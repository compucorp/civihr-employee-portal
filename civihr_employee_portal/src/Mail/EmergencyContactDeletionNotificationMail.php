<?php

namespace Drupal\civihr_employee_portal\Mail;

class EmergencyContactDeletionNotificationMail extends WebformSubmissionNotificationMail {

  /**
   * @inheritdoc
   */
  public function getVariables($message) {
    $contactId = \CRM_Core_Session::singleton()->getLoggedInContactID();
    $contact = civicrm_api3('Contact', 'getsingle', ['id' => $contactId]);
    $contactEmail = $this->getContactWorkEmail($contactId);
    $profileLink = $this->getLinkToContractProfile($contactId);

    return [
      'workEmail' => $contactEmail,
      'profileLink' => $profileLink,
      'displayName' => $contact['display_name'],
      'submissionDate' => date('Y-m-d H:i'),
      'emergencyContactName' => $message['params']['emergencyContactName']
    ];
  }

  /**
   * @inheritdoc
   */
  public function getTemplateName() {
    return 'emergency_contact_deletion.tpl';
  }

  /**
   * @inheritdoc
   */
  public function getSubject($message) {
    return 'CiviHR Self Service Data Submission - Emergency Contact Deleted';
  }

}
