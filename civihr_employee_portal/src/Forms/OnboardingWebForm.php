<?php

namespace Drupal\civihr_employee_portal\Forms;

use Drupal\civihr_employee_portal\Helpers\WebformHelper;
use Drupal\civihr_employee_portal\Service\ContactService;
use Drupal\civihr_employee_portal\Service\TaskCreationService;

class OnboardingWebForm {

  const STATUS_APPLYING = 1;
  const NAME = 'Welcome to CiviHR';

  /**
   * @param \stdClass $node
   * @param array $submission
   */
  public function onSubmit($node, $submission) {
    $contactID = \CRM_Core_Session::singleton()->getLoggedInContactID();

    // clear contact data cache used in get_civihr_contact_data()
    cache_clear_all('civihr_contact_data_' . $contactID, 'cache');

    if ($this->isApplyingForSSN($node, $submission)) {
      $this->createReminderTask($contactID);
    }
  }

  /**
   * @param $node
   * @param $submission
   *
   * @return bool
   */
  private function isApplyingForSSN($node, $submission) {
    $fieldName = 'I am currently applying for a NI/ SSN';
    $statusField = WebformHelper::getWebformComponentsByName($node, $fieldName);
    $uid = property_exists($submission, 'uid') ? $submission->uid : NULL;

    if (count($statusField) !== 1 || NULL === $uid) {
      return FALSE; // field doesn't exist
    }

    $statusField = array_shift($statusField);
    $cid = \CRM_Utils_Array::value('cid', $statusField);
    $values = property_exists($submission, 'data') ? $submission->data : NULL;
    $applicationStatus = \CRM_Utils_Array::value($cid, $values, []);
    $applicationStatus = array_shift($applicationStatus);

    return $applicationStatus == self::STATUS_APPLYING;
  }

  /**
   * @param int $contactID
   *   The logged in contact ID
   */
  private function createReminderTask($contactID) {
    $taskTypeName = 'Check on contact for NI/SSN';
    $date = date('d-m-Y', strtotime('+1 months'));

    $assigneeIDs = ContactService::getLineManagerIDs($contactID);
    if (empty($assigneeIDs)) {
      $assigneeIDs = ContactService::getContactIDsWithRole('CIVIHR_ADMIN');
    }
    $assigneeID = current($assigneeIDs); // only one assignee, first in line

    if ($assigneeID && $assigneeID != $contactID) {
      TaskCreationService::create($contactID, [$assigneeID], $taskTypeName, $date);
    }
  }

}
