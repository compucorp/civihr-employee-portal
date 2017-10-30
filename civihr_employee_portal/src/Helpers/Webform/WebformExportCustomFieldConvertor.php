<?php

namespace Drupal\civihr_employee_portal\Helpers\Webform;

use CRM_Utils_Array as ArrayHelper;
use Drupal\civihr_employee_portal\Helpers\Webform\CustomComponentKeyHelper as KeyHelper;

class WebformExportCustomFieldConvertor {

  const KEY_GROUP = 'custom_group_name';
  const KEY_FIELD = 'custom_field_name';

  /**
   * Supplements the node data with custom field metadata such as custom group
   * name and custom field name for use when re-importing.
   *
   * @param \stdClass $node
   */
  public static function addCustomDataForExport(\stdClass $node) {
    if (!self::isWebform($node)) {
      return;
    }

    $components = ArrayHelper::value('components', $node->webform, []);

    foreach ($components as $key => $component) {
      $formKey = ArrayHelper::value('form_key', $component);

      if (!self::isCustomFieldKey($formKey)) {
        continue;
      }

      $groupName = self::getCustomGroupNameFromKey($formKey);
      $fieldName = self::getCustomFieldNameFromKey($formKey);

      if (!$groupName || !$fieldName) {
        continue;
      }

      $node->webform['components'][$key][self::KEY_GROUP] = $groupName;
      $node->webform['components'][$key][self::KEY_FIELD] = $fieldName;
    }
  }

  /**
   * Replaces form keys with the correct custom group and field ID for this
   * CiviCRM instance if metadata exists in the import node.
   *
   * @param \stdClass $node
   */
  public static function replaceCustomDataForImport(\stdClass $node) {
    if (!self::isWebform($node)) {
      return;
    }

    $components = ArrayHelper::value('components', $node->webform, []);

    foreach ($components as $key => $component) {
      $formKey = ArrayHelper::value('form_key', $component);

      if (!self::isCustomFieldKey($formKey)) {
        continue;
      }

      $groupID = self::getCustomGroupIDFromComponent($component);
      $fieldID = self::getCustomFieldIDFromComponent($component);

      if (!$groupID || !$fieldID) {
        continue;
      }

      $newKey = KeyHelper::rebuildKey($groupID, $fieldID, $formKey);

      $node->webform['components'][$key]['form_key'] = $newKey;
    }
  }

  /**
   * Checks if the node is of type webform
   *
   * @param \stdClass $node
   * @return bool
   */
  private static function isWebform(\stdClass $node) {
    if (isset($node->type) && $node->type === 'webform') {
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Returns true if key matches the format cg<groupID>_custom_<fieldID>
   *
   * @param string $formKey
   * @return bool
   */
  private static function isCustomFieldKey($formKey) {
    return !empty(KeyHelper::getCustomGroupID($formKey));
  }

  /**
   * Finds the custom group ID from a form key
   *
   * @param string $formKey
   *
   * @return int|NULL
   */
  private static function getCustomGroupNameFromKey($formKey) {
    $groupID = KeyHelper::getCustomGroupID($formKey);

    if (!$groupID) {
      return NULL;
    }

    $result = self::getSingleOrNullEntity('CustomGroup', ['id' => $groupID]);

    return ArrayHelper::value('name', $result);
  }

  /**
   * Finds the custom field ID from a form key
   *
   * @param string $formKey
   *
   * @return int|NULL
   */
  private static function getCustomFieldNameFromKey($formKey) {
    $fieldID = KeyHelper::getCustomFieldID($formKey);

    if (!$fieldID) {
      return NULL;
    }

    $result = self::getSingleOrNullEntity('CustomField', ['id' => $fieldID]);

    return ArrayHelper::value('name', $result);
  }

  /**
   * Gets the custom group ID based on group name, if it is set in the component
   * and the group exists.
   *
   * @param array $component
   *
   * @return int|NULL
   */
  private static function getCustomGroupIDFromComponent($component) {
    $groupName = ArrayHelper::value(self::KEY_GROUP, $component);

    if (!$groupName) {
      return NULL;
    }

    $result = self::getSingleOrNullEntity('CustomGroup', ['name' => $groupName]);

    return ArrayHelper::value('id', $result);
  }

  /**
   * Gets the custom group ID based on group name, if it is set in the component
   * and the group exists.
   *
   * @param array $component
   *
   * @return int|NULL
   */
  private static function getCustomFieldIDFromComponent($component) {
    $fieldName = ArrayHelper::value(self::KEY_FIELD, $component);

    if (!$fieldName) {
      return NULL;
    }

    $result = self::getSingleOrNullEntity('CustomField', ['name' => $fieldName]);

    return ArrayHelper::value('id', $result);
  }


  /**
   * Does an API call to get a single entity without throwing an exception like
   * get_single does.
   *
   * @param string $entity
   * @param array $params
   * @return array|NULL
   */
  private static function getSingleOrNullEntity($entity, $params) {
    $result = civicrm_api3($entity, 'get', $params);

    if ($result['count'] != 1) {
      return NULL;
    }

    return array_shift($result['values']);
  }

}
