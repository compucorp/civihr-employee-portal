<?php

/**
 * Updates contact address, enforcing only one personal address type
 */
function civihr_employee_portal_update_7044() {
  civicrm_initialize();
  $locationType = civicrm_api3('LocationType', 'get', ['name' => 'Work']);
  if (!$locationType['count']) {
    return;
  }

  $addresses = _get_personal_address_count();
  foreach ($addresses as $address) {
    if ($address['total'] < 2) {
      continue;
    }

    $result = civicrm_api3('Address', 'get', [
      'location_type_id' => 'Personal',
      'contact_id' => $address['contact_id']
    ]);

    $contactAddresses = array_values($result['values']);
    $primaryIndex = array_search('1', array_column($contactAddresses, 'is_primary'));
    if ($primaryIndex === FALSE) {
      $isWorkPrimary = _check_contact_work_address_is_primary($address['contact_id']);
      if (!$isWorkPrimary) {
        $contactAddresses[0]['is_primary'] = 1;
        civicrm_api3('Address', 'create', $contactAddresses[0]);
      }

      $primaryIndex = 0;
    }

    unset($contactAddresses[$primaryIndex]);
    _update_address_to_works($contactAddresses, $locationType['id']);
  }
}

/**
 * Updates addresses to work location type
 *
 * @param array $contactAddresses
 * @param int $locationTypeId
 * @throws CiviCRM_API3_Exception
 */
function _update_address_to_works($contactAddresses, $locationTypeId) {
  foreach ($contactAddresses as $address) {
    $address['location_type_id'] = $locationTypeId;
    $address['is_primary'] = 0;
    civicrm_api3('Address', 'create', $address);
  }
}

/**
 * Fetches personal addresses grouped by their contact_id
 *
 * @return array
 */
function _get_personal_address_count() {
  $query = "
    SELECT a.contact_id, COUNT(a.location_type_id) AS total, SUM(a.is_primary) AS primary_count
    FROM civicrm_address a
    INNER JOIN civicrm_location_type lt ON (a.location_type_id = lt.id)
    WHERE lt.name = 'Personal'
    GROUP BY a.contact_id
  ";

  $result = CRM_Core_DAO::executeQuery($query);

  return $result->fetchAll();
}

/**
 * Checks if contact has a primary work address type
 *
 * @param int $contactId
 * @return bool
 * @throws CiviCRM_API3_Exception
 */
function _check_contact_work_address_is_primary($contactId) {
  $result = civicrm_api3('Address', 'get', [
    'location_type_id' => 'Work',
    'is_primary' => 1,
    'contact_id' => $contactId
  ]);

  if ($result['count']) {
    return TRUE;
  }

  return FALSE;
}
