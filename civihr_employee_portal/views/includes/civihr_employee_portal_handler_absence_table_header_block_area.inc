<?php

/**
 * This class contains View Handler for overriding absence_list view.
 * It's used to generate Absence List custom table structure based
 * on Drupal View's fields settings.
 */
class civihr_employee_portal_handler_absence_table_header_block_area extends views_handler_area {

  /**
   * Render the area.
   *
   * @param bool $empty
   *
   * @return string
   */
  public function render($empty = FALSE) {

    $header = $this->getHeaderRow();
    $rows = array();
    $periodId = isset($_REQUEST['absence_start_date_period_filter']) ? $_REQUEST['absence_start_date_period_filter'] : variable_get('default_date_period_id', 1);
    $entitlements = $this->getEntitlementData($periodId);
    $rows[] = $this->getEntitlementRow($entitlements);
    $rows = array_merge($rows, $this->getContentRows($entitlements));

    return theme('table', array('header' => $header, 'rows' => $rows));
  }

  /**
   * Return an array containing header row.
   *
   * @return array
   */
  private function getHeaderRow() {

    $row = array();
    $absenceTypes = $this->getAbsenceTypes();

    $row[] = t('Description');
    $row[] = t('Status');
    foreach ($absenceTypes as $absenceType) {
      $row[] = $absenceType['title'];
    }

    return $row;
  }

  /**
   * Return an array containing entitlements row for given $entitlements array.
   *
   * @param array $entitlements
   *
   * @return array
   */
  private function getEntitlementRow(array $entitlements) {

    $row = array();
    $row[] = '<div class="entitlement-label">' . t('Entitlement') . ':</div>';
    $row[] = '';
    foreach ($entitlements as $key => $value) {
      $row['type_' . $key] = '+ ' . $value;
    }

    return $row;
  }

  /**
   * Return an array containing content rows.
   *
   * @param array $entitlements
   *
   * @return array
   */
  private function getContentRows(array $entitlements) {

    $rows = array();
    $activityAbsenceTypeIds = $this->getActivityAbsenceTypeIds();
    $alterLink = $this->view->display_handler->display->display_options['fields']['nothing']['alter']['text'];
    $dateHandler = new views_handler_field_date();

    foreach ($this->view->result as $absence) {
      $dateHandler->field_alias = 'absence_list_absence_start_date_timestamp';
      $dateHandler->unpack_options($dateHandler->options, $this->view->display_handler->display->display_options['fields']['absence_start_date_timestamp']);
      $startDate = $dateHandler->render($absence);
      $dateHandler->field_alias = 'absence_list_absence_end_date_timestamp';
      $dateHandler->unpack_options($dateHandler->options, $this->view->display_handler->display->display_options['fields']['absence_end_date_timestamp']);
      $endDate = $dateHandler->render($absence);
      $absence->absence_list_absence_start_date_timestamp = $startDate;
      $absence->absence_list_absence_end_date_timestamp = $endDate;
      $title = $this->applyPlaceholders($alterLink, $absence);
      $amount = $absence->absence_list_duration / 480;

      $row = array(
        $title,
        get_civihr_absence_statuses($absence->absence_list_absence_status),
      );
      foreach ($activityAbsenceTypeIds as $typeId) {
        $row['type_' . $typeId] = '';
      }
      $row['type_' . $activityAbsenceTypeIds[$absence->absence_list_activity_type_id]] = ($absence->absence_list_is_credit ? '+ ' : '- ') . $amount;
      $entitlements[$activityAbsenceTypeIds[$absence->absence_list_activity_type_id]] += ($absence->absence_list_is_credit ? $amount : -$amount);
      $rows[] = $row;
    }

    $rows[] = $this->getBalanceRow($activityAbsenceTypeIds, $entitlements);

    return $rows;
  }

  /**
   * Return an array containing balance row.
   *
   * @param array $activityAbsenceTypeIds
   * @param array $balance
   *
   * @return array
   */
  private function getBalanceRow(array $activityAbsenceTypeIds, array $balance) {

    $row = array(
      t('Balance') . ':',
      '',
    );
    foreach ($activityAbsenceTypeIds as $activityId => $typeId) {
      $row['type_' . $typeId] = CRM_Utils_Array::value($typeId, $balance);
    }

    return $row;
  }

  /**
   * Return an array containing Absence types, excluding 'Sick' type.
   *
   * @return array
   */
  private function getAbsenceTypes() {

    $result = array();
    $absenceTypes = get_civihr_absence_types();

    foreach ($absenceTypes as $absenceType) {
      if (civihr_employee_portal_is_sick_absence($absenceType['name'])) {
        continue;
      }
      $result[] = $absenceType;
    }

    return $result;
  }

  /**
   * Return an array containing key / value pairs of activity type id / absence
   * type id. Used for mapping activity types to their absence types equivalents.
   *
   * @return array
   */
  private function getActivityAbsenceTypeIds() {

    $result = array();
    $absenceTypes = $this->getAbsenceTypes();

    foreach ($absenceTypes as $type) {
      if (!empty($type['debit_activity_type_id'])) {
        $result[$type['debit_activity_type_id']] = $type['id'];
      }
      if (!empty($type['credit_activity_type_id'])) {
        $result[$type['credit_activity_type_id']] = $type['id'];
      }
    }

    return $result;
  }

  /**
   * Return an assotiative array containing key / value pairs of
   * absence_type / amount values of currently logged in user for
   * given period (excluding Sick absence type).
   *
   * @param int $periodId
   *
   * @return array
   */
  private function getEntitlementData($periodId) {

    $entitlementData = array();
    $sickTypeId = civihr_employee_portal_get_absence_sick_type_id();

    $absenceEntitlementParams = array(
      'contact_id' => $_SESSION['CiviCRM']['userID'],
      'period_id' => $periodId,
      'return' => array('type_id', 'amount'),
      'options' => array('limit' => 0),
    );
    if ($sickTypeId) {
      $absenceEntitlementParams['type_id'] = array('!=' => $sickTypeId);
    }

    $result = civicrm_api3('HRAbsenceEntitlement', 'get', $absenceEntitlementParams);

    foreach ($result['values'] as $record) {
      $entitlementData[(int)$record['type_id']] = $record['amount'];
    }

    return $entitlementData;
  }

  /**
   * Return string with applied $entity values to specified $pattern placeholders.
   *
   * @param string $pattern
   * @param object $entity
   *
   * @return string
   */
  private function applyPlaceholders($pattern, $entity) {

    $result = $pattern;
    foreach ($entity as $key => $value) {
      $replace = str_replace('absence_list_', '', $key);
      $result = str_replace('[' . $replace . ']', $value, $result);
    }
    return $result;
  }
}
