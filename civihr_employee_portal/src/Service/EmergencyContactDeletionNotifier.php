<?php

namespace Drupal\civihr_employee_portal\Service;

use CRM_Hremergency_Service_EmergencyContactService as EmergencyContactService;

class EmergencyContactDeletionNotifier {

  /**
   * Sends the notification mail about emergency contact deletion
   *
   * @param int $emergencyContactId
   */
  public function notifyDeletion($emergencyContactId) {
    if (!ContactUpdateNotificationSettingsHelper::shouldSendMail()) {
      return;
    }

    $service = new EmergencyContactService();
    $emergencyContact = $service->find($emergencyContactId);

    $params = ['emergencyContact' => $emergencyContact];
    $mail = ContactUpdateNotificationSettingsHelper::getTargetEmail();
    $module = 'civihr_employee_portal';
    $lang = language_default();
    drupal_mail($module, 'emergency_contact_deletion', $mail, $lang, $params);
  }

}
