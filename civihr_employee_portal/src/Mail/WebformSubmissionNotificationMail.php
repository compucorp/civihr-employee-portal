<?php

namespace Drupal\civihr_employee_portal\Mail;

use Drupal\civihr_employee_portal\Helpers\WebformHelper;
use Drupal\civihr_employee_portal\Service\ContactService;

class WebformSubmissionNotificationMail extends AbstractDrupalSystemMail {

  /**
   * @inheritdoc
   */
  public function getVariables($message) {
    $node = $message['params']['node'];
    $submission = $message['params']['submission'];

    $contactId = WebformHelper::getValueByTitle($node, $submission, 'Existing Contact');
    $contact = civicrm_api3('Contact', 'getsingle', ['id' => $contactId]);

    $contactEmail = ContactService::getContactWorkEmail($contactId);
    $profileLink = ContactService::getLinkToContactProfile($contactId);
    $submittedValues = $this->formatSubmittedValues($node, $submission);

    return [
      'submittedValues' => $submittedValues,
      'workEmail' => $contactEmail,
      'profileLink' => $profileLink,
      'displayName' => $contact['display_name'],
      'submissionDate' => date('Y-m-d H:i', $submission->submitted),
      'webformTitle' => $node->title,
    ];
  }

  /**
   * @inheritdoc
   */
  public function getTemplateName() {
    return 'dashboard_edit_details.tpl';
  }

  /**
   * @inheritdoc
   */
  public function getSubject($message) {
    return 'CiviHR Self Service Data Submission';
  }

  /**
   * Prepare submitted values for display in the email
   *
   * @param \stdClass $node
   * @param \stdClass $submission
   *
   * @return array
   */
  protected function formatSubmittedValues($node, $submission) {
    $submittedValues = WebformHelper::getSubmittedValues($node, $submission);

    // We don't want these fields as they are not user-submitted values
    $fieldsToRemove = [
      'Existing Contact',
      'Emergency Contacts',
    ];

    foreach ($submittedValues as $pageIndex => $pageValues) {
      foreach ($pageValues as $fieldSetIndex => $fieldSetValues) {
        foreach ($fieldsToRemove as $fieldToRemove) {
          unset($submittedValues[$pageIndex][$fieldSetIndex][$fieldToRemove]);
        }
      }
    }

    return $submittedValues;
  }

}
