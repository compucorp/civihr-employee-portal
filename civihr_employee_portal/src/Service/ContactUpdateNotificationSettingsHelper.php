<?php

namespace Drupal\civihr_employee_portal\Service;

use Drupal\civihr_employee_portal\Forms\OnboardingWizardCustomizationForm;

class ContactUpdateNotificationSettingsHelper {

  /**
   * Checks settings to determine whether emails should be sent
   *
   * @return bool
   */
  public static function shouldSendMail() {
    $targetEmail = self::getTargetEmail();
    $shouldSendKey = OnboardingWizardCustomizationForm::SEND_UPDATES_KEY;
    $shouldSend = variable_get($shouldSendKey);

    return $shouldSend && !empty($targetEmail);
  }

  /**
   * Gets the email that notifications should be sent to
   *
   * @return string
   */
  public static function getTargetEmail() {
    return variable_get(
      OnboardingWizardCustomizationForm::EMAIL_TO_SEND_UPDATES_KEY
    );
  }

}
