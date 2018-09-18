<?php

namespace Drupal\civihr_employee_portal\Service;

class EmergencyContactDeletionNotifier {

  /**
   * Sends the notification mail about emergency contact deletion
   *
   * @param array $emergencyContact
   */
  public function notifyDeletion($emergencyContact) {
    if (!ContactUpdateNotificationSettingsHelper::shouldSendMail()) {
      return;
    }

    $params = ['emergencyContact' => $emergencyContact];
    $mail = ContactUpdateNotificationSettingsHelper::getTargetEmail();
    $module = 'civihr_employee_portal';
    $lang = language_default();
    drupal_mail($module, 'emergency_contact_deletion', $mail, $lang, $params);
  }

}
