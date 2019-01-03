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

    $addresses = array_values($result['values']);
    $primaryIndex = array_search('1', array_column($addresses, 'is_primary'));
    if ($primaryIndex === FALSE) {
      $addresses[0]['is_primary'] = 1;
      civicrm_api3('Address', 'create', $addresses[0]);
      $primaryIndex = 0;
    }

    unset($addresses[$primaryIndex]);
    _update_address_to_works($addresses, $locationType['id']);
  }
}

/**
 * Updates addresses to work location type
 *
 * @param array $addresses
 * @param int $locationTypeId
 * @throws CiviCRM_API3_Exception
 */
function _update_address_to_works($addresses, $locationTypeId) {
  foreach ($addresses as $address) {
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
