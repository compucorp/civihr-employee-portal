<?php

use Drupal\civihr_employee_portal\Service\CustomValueService;

/**
 * Handles displaying the NI/SSN number for a contact, or "pending" if
 * application is in progress
 */
class civihr_employee_portal_handler_ni_ssn_or_status extends views_handler_field {

  /**
   * @inheritdoc
   */
  public function render($values) {
    $contactID = isset($values->id) ? $values->id : NULL;

    if (!$contactID) {
      return '';
    }

    $ssnField = 'NI_SSN';
    $statusField = 'has_applied_for_identification';
    $group = 'Inline_Custom_Data';
    $service = new CustomValueService();
    $isApplying = $service->getValueForEntity($contactID, $group, $statusField);

    if ($isApplying) {
      return '<em>Pending</em>';
    }

    return $service->getValueForEntity($contactID, $group, $ssnField);
  }

  /**
   * @inheritdoc
   */
  public function query() {
    // override default behaviour as this handler is not tied to a single field
  }

}
