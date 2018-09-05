<?php

namespace Drupal\civihr_employee_portal\Mail;

use Drupal\civihr_employee_portal\Forms\OnboardingWebForm;
use Drupal\civihr_employee_portal\Forms\OnboardingWizardCustomizationForm;

class WebformSubmissionNotifier {

  /**
   * @var array
   *   A list of webform titles to send notifications for
   */
  private $webformsToNotifyAbout = [
    'My Personal Details',
    'My Contact Details',
    'My Home Address',
    'My Payroll',
    'Create Emergency Contact',
    'Create Dependant',
    OnboardingWebForm::NAME,
  ];

  /**
   * Sends notifications about the submission of a webform
   *
   * @param \stdClass $node
   * @param \stdClass $submission
   */
  public function sendNotification($node, $submission) {
    if ($this->shouldSendMail($node)) {
      $this->sendMail($node, $submission);
    }
  }

  /**
   * Sends an email notification about the webform submission
   *
   * @param \stdClass $node
   * @param \stdClass $submission
   */
  private function sendMail($node, $submission) {
    $params['node'] = $node;
    $params['submission'] = $submission;
    $key = $this->getMailKey($node);
    $module = 'civihr_employee_portal';
    $email = $this->getTargetEmail();

    drupal_mail($module, $key, $email, language_default(), $params);
  }

  /**
   * Checks settings and node title to determine whether emails should be sent
   *
   * @param \stdClass $node
   *
   * @return bool
   */
  private function shouldSendMail($node) {
    if (!in_array($node->title, $this->webformsToNotifyAbout)) {
      return FALSE;
    }

    $targetEmail = $this->getTargetEmail();
    $shouldSendKey = OnboardingWizardCustomizationForm::SEND_UPDATES_KEY;
    $shouldSend = variable_get($shouldSendKey);

    return $shouldSend && !empty($targetEmail);
  }

  /**
   * Gets the email that notifications should be sent to
   *
   * @return string
   */
  private function getTargetEmail() {
    return variable_get(
      OnboardingWizardCustomizationForm::EMAIL_TO_SEND_UPDATES_KEY
    );
  }

  /**
   * Gets the key to be used when mailing. This key will affect which mail
   * class is used when sending the mail
   *
   * @see civihr_employee_portal_mail()
   *
   * @param \stdClass $node
   *
   * @return string
   */
  private function getMailKey($node) {
    switch ($node->title) {
      case OnboardingWebForm::NAME:
        return 'civihr_onboarding_form_submission';
      default:
        return 'civihr_webform_submission';
    }
  }

}
