<?php

use Drupal\civihr_employee_portal\Helpers\UrlHelper;

/**
 * Remove photo=0 from all contact image URLs
 *
 * It was added to fix a warning in CiviCRM, but this warning is no longer
 * generated and the addition of photo=0 causes problems for image display
 */
function civihr_employee_portal_update_7042() {
  civicrm_initialize();
  $contacts = civicrm_api3('Contact', 'get');
  $contacts = CRM_Utils_Array::value('values', $contacts, []);

  foreach ($contacts as $contact) {
    $imageUrl = CRM_Utils_Array::value('image_URL', $contact);

    if (!$imageUrl) {
      continue;
    }

    if (strpos($imageUrl, 'photo=0') === FALSE) {
      continue;
    }

    $newImageUrl = UrlHelper::removeQueryValueFromUrl($imageUrl, 'photo');

    civicrm_api3('Contact', 'create', [
      'id' => $contact['id'],
      'image_URL' => $newImageUrl,
    ]);
  }
}
