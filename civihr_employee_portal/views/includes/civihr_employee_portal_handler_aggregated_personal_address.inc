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
    $contactID = !$contactID && isset($values->civicrm_address_contact_id) ? $values->civicrm_address_contact_id : $contactID;

    if (!$contactID) {
      return '';
    }

    $address = $this->getAddress($contactID);

    if (!$address) {
      return '';
    }

    return $this->view->name == 'my_details_block' ? $this->formatAddress($address) : $this->formatAddressWithLabels($address);
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

  /**
   * Returns the HTML for the address as it will appear in the view.
   *
   * @param array $address
   *   The address data
   * @return string
   *   The formatted address
   */
  private function formatAddressWithLabels($address) {
    $formatStreetAddress = '
    <div class="views-field views-field-street-address">
      <span class="views-label views-label-street-address">Home Address</span>
      <span class="field-content">
        %s
        %s
        %s
      </span>
    </div>
    ';

    $formatPostcode = '
    <div class="views-field views-field-postal-code">
      <span class="views-label views-label-postal-code">Postcode</span>
      <span class="field-content">%s</span>
    </div>
    ';

    $formatCountry = '
    <div class="views-field views-field-country">
      <span class="views-label views-label-country">Country</span>
      <span class="field-content">%s</span>
    </div>
    ';

    $streetAddress = trim(ArrayHelper::value('street_address', $address));
    $supplementalAddress1 = trim(ArrayHelper::value('supplemental_address_1', $address));

    $streetAddress .= trim( $streetAddress ) ? '<br/>' : '';
    $supplementalAddress1 .= trim($supplementalAddress1) ? '<br/>' : '';
    $city = trim(ArrayHelper::value('city', $address));

    $line1html = $city || $streetAddress || $supplementalAddress1 ?
      sprintf(
        $formatStreetAddress,
        $streetAddress,
        $supplementalAddress1,
        $city
      ) : '';

    $postcode = trim(ArrayHelper::value('postal_code', $address));
    $line2html = $postcode ? sprintf($formatPostcode, $postcode) : '';

    $country = trim(ArrayHelper::value('country_id.name', $address));
    $line3html = $country ? sprintf($formatCountry, $country) : '' ;

    return filter_xss($line1html . $line2html . $line3html,['div','span','br']);
  }
}
