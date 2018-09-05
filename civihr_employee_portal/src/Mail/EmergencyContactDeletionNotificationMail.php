<?php

namespace Drupal\civihr_employee_portal\Mail;

use Drupal\civihr_employee_portal\Service\ContactService;

class EmergencyContactDeletionNotificationMail extends AbstractDrupalSystemMail {

  /**
   * @inheritdoc
   */
  public function getVariables($message) {
    $contactId = \CRM_Core_Session::singleton()->getLoggedInContactID();
    $contact = civicrm_api3('Contact', 'getsingle', ['id' => $contactId]);
    $contactEmail = ContactService::getContactWorkEmail($contactId);
    $profileLink = ContactService::getLinkToContactProfile($contactId);
    $emergencyContact = $message['params']['emergencyContact'];

    return [
      'workEmail' => $contactEmail,
      'profileLink' => $profileLink,
      'displayName' => $contact['display_name'],
      'submissionDate' => date('Y-m-d H:i'),
      'emergencyContactName' => $emergencyContact['Name']
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
