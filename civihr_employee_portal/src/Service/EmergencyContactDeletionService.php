<?php

namespace Drupal\civihr_employee_portal\Service;

use CRM_Hremergency_Service_EmergencyContactService as EmergencyContactService;

class EmergencyContactDeletionService {

  /**
   * Deletes an emergency contact and sends a notification mail about it
   *
   * @param int $id
   *   The ID of the emergency contact
   */
  public function delete($id) {
    $service = new EmergencyContactService();
    $emergencyContact = $service->find($id);

    if (!$emergencyContact) {
      $err = sprintf('Emergency contact with ID "%d" was not found', $id);
      throw new \Exception($err);
    }

    if (!$this->canDelete($emergencyContact)) {
      $err = 'You do not have permission to delete that emergency contact';
      throw new \Exception($err);
    }

    $service->delete($id);
    $this->sendNotification($emergencyContact);
  }

  /**
   * Sends the notification mail about emergency contact deletion
   *
   * @param array $emergencyContact
   */
  protected function sendNotification($emergencyContact) {
    if (!WebformSubmissionSettingsService::shouldSendMail()) {
      return;
    }

    $params = ['emergencyContact' => $emergencyContact];
    $mail = WebformSubmissionSettingsService::getTargetEmail();
    $module = 'civihr_employee_portal';
    $lang = language_default();
    drupal_mail($module, 'emergency_contact_deletion', $mail, $lang, $params);
  }

  /**
   * Decide whether a user can delete the emergency contact or not
   *
   * @param array $emergencyContact
   *
   * @return bool
   */
  private function canDelete($emergencyContact) {
    // Allow for self-made changes
    $currentContactId = \CRM_Core_Session::getLoggedInContactID();
    if ($currentContactId == $emergencyContact['entity_id']) {
      return TRUE;
    }

    // Or allow for admins
    return user_access('administer CiviCRM');
  }

}
