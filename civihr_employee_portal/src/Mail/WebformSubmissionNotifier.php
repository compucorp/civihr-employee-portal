<?php

namespace Drupal\civihr_employee_portal\Mail;

use Drupal\civihr_employee_portal\Forms\OnboardingWebForm;

class WebformSubmissionNotifier {

  /**
   * @var array
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
   * @param \stdClass $node
   * @param \stdClass $submission
   */
  public function sendNotification($node, $submission) {
    if (!in_array($node->title, $this->webformsToNotifyAbout)) {
      return;
    }

    $this->sendMail($node, $submission);
  }

  /**
   * @param \stdClass $node
   * @param \stdClass $submission
   */
  private function sendMail($node, $submission) {
    $params['node'] = $node;
    $params['submission'] = $submission;

    // todo fetch email from settings
    $email = 'tmp@compucorp.co.uk';

    $key = 'civihr_webform_submission';
    if ($node->title === OnboardingWebForm::NAME) {
      // Use a different key for onboarding form handling
      $key = 'civihr_onboarding_form_submission';
    }

    $module = 'civihr_employee_portal';
    drupal_mail($module, $key, $email, language_default(), $params);
  }
}
