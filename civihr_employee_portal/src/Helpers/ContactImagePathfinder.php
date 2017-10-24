<?php

namespace Drupal\civihr_employee_portal\Helpers;

class ContactImagePathfinder {
  /**
   * @param $contactID
   *   The ID of the target contact
   *
   * @return string|NULL
   *   The image path if it exists, or NULL if not set or doesn't exist.
   */
  public static function getPathToContactImage($contactID) {
    $targetContact = civicrm_api3('Contact', 'getsingle', ['id' => $contactID]);
    // Since this is postProcess image_URL is already pointing to new image
    $imageUrl = $targetContact['image_URL'];

    // Get the full path to the image
    $queryString = parse_url($imageUrl, PHP_URL_QUERY);
    parse_str($queryString, $queryParts);
    $imageName = \CRM_Utils_Array::value('photo', $queryParts);
    $path = \Civi::settings()->get('customFileUploadDir');
    $path = \Civi::paths()->getPath($path);
    $imagePath = $path . $imageName;

    return file_exists($imagePath) ? $imagePath : NULL;
  }
}
