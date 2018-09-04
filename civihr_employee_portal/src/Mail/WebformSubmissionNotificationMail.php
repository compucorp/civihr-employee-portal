<?php

namespace Drupal\civihr_employee_portal\Mail;

use Drupal\civihr_employee_portal\Helpers\WebformHelper;

class WebformSubmissionNotificationMail extends AbstractDrupalSystemMail {

  /**
   * @inheritdoc
   */
  public function getVariables($message) {
    $node = $message['params']['node'];
    $submission = $message['params']['submission'];

    $contactId = WebformHelper::getValueByTitle($node, $submission, 'Existing Contact');
    $contact = civicrm_api3('Contact', 'getsingle', ['id' => $contactId]);

    $contactEmail = $this->getContactWorkEmail($contactId);
    $profileLink = $this->getLinkToContractProfile($contactId);
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
   * Fetch the provided contact's work email
   *
   * @param int $contactId
   *
   * @return string
   */
  protected function getContactWorkEmail($contactId) {
    $contactEmailRes = civicrm_api3('Email', 'get', [
      'contact_id' => $contactId,
      'location_type_id' => 'Work',
      'options' => ['limit' => 1],
      'sequential' => 1,
    ]);

    if ($contactEmailRes['count'] == 1) {
      return $contactEmailRes['values'][0]['email'];
    }

    return '';
  }

  /**
   * Fetch an absolute link to the contact's profile page
   *
   * @param int $contactId
   *
   * @return string
   */
  protected function getLinkToContractProfile($contactId) {
    $profilePath = 'civicrm/contact/view';
    $queryParams = ['cid' => $contactId];
    $profileLink = \CRM_Utils_System::url($profilePath, $queryParams, TRUE);

    return $profileLink;
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
