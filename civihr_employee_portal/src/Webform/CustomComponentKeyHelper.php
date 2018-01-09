<?php

namespace Drupal\civihr_employee_portal\Webform;

use CRM_Utils_Array as ArrayHelper;

/**
 * Helper class to deal with manipulation and parsing of the 'form_key' field
 * of custom field webform components.
 */
class CustomComponentKeyHelper {

  /**
   * @var string
   *   Matches the format of a custom field key e.g.
   *   civicrm_1_contact_1_cg_5_custom_15
   */
  private static $pattern = '/(.*cg_?)(\d+)_custom_(\d+)/';

  /**
   * Gets the custom group ID from the form key.
   *
   * @param string $formKey
   *
   * @return int
   */
  public static function getCustomGroupID($formKey) {
    preg_match(self::$pattern, $formKey, $matches);
    $groupIDIndex = 2;

    return ArrayHelper::value($groupIDIndex, $matches);
  }

  /**
   * Gets the custom field ID from the form key.
   *
   * @param string $formKey
   *
   * @return int
   */
  public static function getCustomFieldID($formKey) {
    preg_match(self::$pattern, $formKey, $matches);
    $fieldIDIndex = 3;

    return ArrayHelper::value($fieldIDIndex, $matches);
  }

  /**
   * Replaces existing custom group ID and custom field ID with new ones.
   *
   * @param int $groupID
   * @param int $fieldID
   * @param string $formKey
   *
   * @return string
   */
  public static function rebuildKey($groupID, $fieldID, $formKey) {
    $replacement = sprintf('${1}%d_custom_%d', $groupID, $fieldID);

    return preg_replace(self::$pattern, $replacement, $formKey);
  }
}
