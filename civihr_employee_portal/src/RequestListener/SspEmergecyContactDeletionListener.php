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
    $contact = $service->find($params['id']);
    $params['emergencyContactName'] = $contact['Name'];

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

    $entity = \CRM_Utils_Array::value('entity', $_REQUEST);
    $action = \CRM_Utils_Array::value('action', $_REQUEST);

    return $entity === 'contact' && $action === 'deleteemergencycontact';
  }

}
