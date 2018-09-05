<?php

namespace Drupal\civihr_employee_portal\RequestListener;

use Drupal\civihr_employee_portal\Service\WebformSubmissionSettingsService;
use CRM_Hremergency_Service_EmergencyContactService as EmergencyContactService;

class SspEmergecyContactDeletionListener {

  public function apply() {
    if (!WebformSubmissionSettingsService::shouldSendMail()) {
      return;
    }

    $json = \CRM_Utils_Array::value('json', $_REQUEST, '');
    $params = json_decode($json, TRUE);

    $service = new EmergencyContactService();
    $emergencyContact = $service->find($params['id']);

    if (!$emergencyContact) {
      return;
    }

    // Only send the mail for self-made changes
    $currentContactId = \CRM_Core_Session::getLoggedInContactID();
    if ($currentContactId != $emergencyContact['entity_id']) {
      return;
    }

    $params = ['emergencyContact' => $emergencyContact];
    $mail = WebformSubmissionSettingsService::getTargetEmail();
    $module = 'civihr_employee_portal';
    $lang = language_default();
    drupal_mail($module, 'emergency_contact_deletion', $mail, $lang, $params);
  }

  /**
   * @return bool
   */
  public function applies() {
    $isCiviAjaxRequest = current_path() === 'civicrm/ajax/rest';

    if (!$isCiviAjaxRequest) {
      return FALSE;
    }

    $entity = strtolower(\CRM_Utils_Array::value('entity', $_REQUEST, ''));
    if ($entity !== 'contact') {
      return FALSE;
    }

    $action = \CRM_Utils_Array::value('action', $_REQUEST);
    $referer = \CRM_Utils_Array::value('HTTP_REFERER', $_SERVER, '');
    $refererPath = parse_url($referer, PHP_URL_PATH);
    $isFromDashboard = $refererPath === '/hr-details';

    return $action === 'deleteemergencycontact' && $isFromDashboard;
  }

}
