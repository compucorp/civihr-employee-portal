<?php

/**
 * Handles aggregation of emergency contact address fields
 */
class civihr_employee_portal_handler_emergency_contact_aggregated_address extends views_handler_field {

  /**
   * @inheritdoc
   */
  public function render($values) {
    $id = isset($values->id) ? (int) $values->id : NULL;

    if (!$id) {
      return '';
    }

    $addressFields = [
      'Street_Address',
      'Street_Address_Line_2',
      'City',
      'Postal_Code',
      'Province',
      'Country'
    ];

    $fieldMapping = $this->getFieldMapping($addressFields);
    $result = $this->fetchEntityValues($fieldMapping, $id);
    $result = $this->replaceCountryIDWithName($fieldMapping, $result);
    $result = $this->replaceProvinceIDWithName($fieldMapping, $result);

    return implode(', ', $result);
  }

  /**
   * @inheritdoc
   */
  public function query() {
    // override default behaviour as this handler is not tied to a single field
  }

  /**
   * Fetch the custom field column names and sort by original order.
   *
   * @param array $addressFields
   *
   * @return array
   */
  private function getFieldMapping($addressFields) {
    $params = [
      'custom_group_id' => 'Emergency_Contacts',
      'name' => [
        'IN' => $addressFields
      ],
    ];

    $fields = civicrm_api3('CustomField', 'get', $params);
    $fields = array_column($fields['values'], 'column_name', 'name');

    $sortedFields = [];
    foreach ($addressFields as $addressField) {
      $sortedFields[$addressField] = $fields[$addressField];
    }

    return $sortedFields;
  }

  /**
   * Query the database for the custom entity values.
   * This is not suitable for an API call because the CustomValue API is broken
   * and does not respect "ID" in parameters.
   *
   * @param array $fieldMapping
   * @param int $id
   *
   * @return array
   */
  private function fetchEntityValues($fieldMapping, $id) {
    $table = $this->view->base_table;
    $selectFields = implode(', ', $fieldMapping);
    $format = 'SELECT %s FROM `%s` WHERE id = %d';
    $query = sprintf($format, $selectFields, $table, $id);
    $result = CRM_Core_DAO::executeQuery($query);
    $result = current($result->fetchAll());

    return array_filter($result);
  }

  /**
   * Checks for the country ID and replaces it with the country name.
   *
   * @param array $fieldMapping
   * @param array $result
   *
   * @return array
   */
  private function replaceCountryIDWithName($fieldMapping, $result) {
    $countryColumn = $fieldMapping['Country'];

    if (!empty($result[$countryColumn])) {
      $countryName = CRM_Core_BAO_Country::getFieldValue(
        CRM_Core_BAO_Country::class,
        $result[$countryColumn]
      );
      $result[$countryColumn] = $countryName;
    }

    return $result;
  }

  /**
   * Checks for the province ID and replaces it with the country name.
   *
   * @param array $fieldMapping
   * @param array $result
   *
   * @return array
   */
  private function replaceProvinceIDWithName($fieldMapping, $result) {
    $provinceColumn = $fieldMapping['Province'];
    if (!empty($result[$provinceColumn])) {
      $provinceName = CRM_Core_DAO_StateProvince::getFieldValue(
        CRM_Core_DAO_StateProvince::class,
        $result[$provinceColumn]
      );
      $result[$provinceColumn] = $provinceName;
    }

    return $result;
  }

}
