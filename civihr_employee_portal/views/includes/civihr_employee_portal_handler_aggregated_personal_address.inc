<?php

use CRM_Utils_Array as ArrayHelper;

/**
 * Handles aggregation of a contacts different home address fields
 */
class civihr_employee_portal_handler_aggregated_personal_address extends views_handler_field {

  /**
   * @inheritdoc
   */
  public function render($values) {
    $contactID = isset($values->id) ? $values->id : NULL;

    if (!$contactID) {
      return '';
    }

    $address = $this->getAddress($contactID);

    if (!$address) {
      return '';
    }

    return $this->formatAddress($address);
  }

  /**
   * @inheritdoc
   */
  public function query() {
    // override default behaviour as this handler is not tied to a single field
  }

  /**
   * Gets the primary address for a contact ID
   *
   * @param int $contactID
   * @return array|null
   */
  private function getAddress($contactID) {
    $return = [
      'street_address',
      'supplemental_address_1',
      'city',
      'state_province_id.name',
      'postal_code',
      'country_id.name',
    ];

    $address = civicrm_api3('Address', 'get', [
      'location_type_id' => 'Personal',
      'contact_id' => $contactID,
      'return' => $return,
      'options' => ['limit' => 1]
    ]);

    if ($address['count'] != 1) {
      return NULL;
    }

    return array_shift($address['values']);
  }

  /**
   * Returns the HTML for the address as it will appear in the view.
   *
   * @param array $address
   *   The address data
   * @return string
   *   The formatted address
   */
  private function formatAddress($address) {
    $format = '%s<br/>%s<br/>%s %s<br/>%s<br/>%s';

    return sprintf(
      $format,
      filter_xss(ArrayHelper::value('street_address', $address)),
      filter_xss(ArrayHelper::value('supplemental_address_1', $address)),
      filter_xss(ArrayHelper::value('city', $address)),
      filter_xss(ArrayHelper::value('state_province_id.name', $address)),
      filter_xss(ArrayHelper::value('postal_code', $address)),
      filter_xss(ArrayHelper::value('country_id.name', $address))
    );
  }
}
