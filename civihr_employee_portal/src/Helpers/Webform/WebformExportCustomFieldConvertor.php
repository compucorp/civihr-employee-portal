<?php

namespace Drupal\civihr_employee_portal\Helpers\Webform;

use CRM_Utils_Array as ArrayHelper;
use Drupal\civihr_employee_portal\Helpers\Webform\CustomComponentKeyHelper as KeyHelper;

/**
 * Responsible for adding metadata on custom fields when exporting webforms and
 * using that metadata to correct cross-system changes in custom field IDs when
 * importing webforms.
 */
class WebformExportCustomFieldConvertor {

  const KEY_GROUP = 'custom_group_name';
  const KEY_FIELD = 'custom_field_name';

  /**
   * Supplements the node data with a snapshot of a mapping of custom group and
   * field IDs to their machine name for use when re-importing.
   *
   * @param \stdClass $node
   */
  public static function addCustomMappingForExport(\stdClass $node) {
    if ($node->type !== 'webform') {
      return;
    }

    $components = ArrayHelper::value('components', $node->webform, []);
    $customGroupIDs = [];
    $customFieldIDs = [];

    foreach ($components as $key => $component) {
      $formKey = ArrayHelper::value('form_key', $component);

      if (!self::isCustomFieldKey($formKey)) {
        continue;
      }

      $groupID = KeyHelper::getCustomGroupID($formKey);
      $fieldID = KeyHelper::getCustomFieldID($formKey);

      if ($groupID && !in_array($groupID, $customGroupIDs)) {
        $customGroupIDs[] = $groupID;
      }

      if ($fieldID && !in_array($fieldID, $customFieldIDs)) {
        $customFieldIDs[] = $fieldID;
      }
    }

    $groups = self::getNameMapping('CustomGroup', $customGroupIDs);
    $fields = self::getNameMapping('CustomField', $customFieldIDs);

    $node->customMapping['customFields'] = $fields;
    $node->customMapping['customGroups'] = $groups;
  }

  /**
   * Gets a mapping of entity IDs to names for custom fields or groups
   *
   * @param string $entity
   * @param array $ids
   *
   * @return array
   */
  private static function getNameMapping($entity, $ids) {
    $params['id'] = ['IN' => $ids];
    $params['return'] = ['name'];
    $results = civicrm_api3($entity, 'get', $params);
    $results = ArrayHelper::value('values', $results, []);

    return array_column($results, 'name', 'id');
  }

  /**
   * Reverse the process of original mapping by looking up the new ID of the
   * custom group/field entity based on the name from the mapping.
   *
   * @param string $entity
   * @param array $originalMapping
   *
   * @return array
   *   With values of old ID => new ID
   */
  private static function reverseNameMapping($entity, $originalMapping) {
    $names = array_values($originalMapping);

    $params['name'] = ['IN' => $names];
    $params['return'] = ['id', 'name'];
    $results = civicrm_api3($entity, 'get', $params);
    $results = ArrayHelper::value('values', $results, []);

    $oldToNewMapping = [];

    foreach ($results as $result) {
      $orignalID = ArrayHelper::key($result['name'], $originalMapping);
      $oldToNewMapping[$orignalID] = $result['id'];
    }

    return $oldToNewMapping;
  }

  /**
   * Replaces form keys with the correct custom group and field ID for this
   * CiviCRM instance if metadata exists in the import node.
   *
   * @param \stdClass $node
   */
  public static function replaceCustomDataForImport(\stdClass $node) {
    if ($node->type !== 'webform') {
      return;
    }

    // Node was not exported since this change was applied
    if (!isset($node->customMapping)) {
      return;
    }

    $groupNameMapping = $node->customMapping['customGroups'];
    $groupMapping = self::reverseNameMapping('CustomGroup', $groupNameMapping);
    $fieldNameMapping = $node->customMapping['customFields'];
    $fieldMapping = self::reverseNameMapping('CustomField', $fieldNameMapping);
    $components = ArrayHelper::value('components', $node->webform, []);

    foreach ($components as $key => $component) {
      $formKey = ArrayHelper::value('form_key', $component);

      if (!self::isCustomFieldKey($formKey)) {
        continue;
      }

      $oldGroupID = KeyHelper::getCustomGroupID($formKey);
      $newGroupID = ArrayHelper::value($oldGroupID, $groupMapping);

      $oldFieldID = KeyHelper::getCustomFieldID($formKey);
      $newFieldID = ArrayHelper::value($oldFieldID, $fieldMapping);

      $newKey = KeyHelper::rebuildKey($newGroupID, $newFieldID, $formKey);

      $node->webform['components'][$key]['form_key'] = $newKey;
    }

    $civiWebform = isset($node->webform_civicrm) ? $node->webform_civicrm : [];
    $civiGroups = ArrayHelper::value('data', $civiWebform, []);
    $customGroupCountPrefix = 'number_of_cg';

    foreach ($civiGroups as $entity => $groups) {
      foreach ($groups as $index => $values) {

        if (!is_array($values)) {
          continue;
        }

        foreach ($values as $key => $value) {

          if (substr($key, 0, 12) === $customGroupCountPrefix) {
            $oldGroupID = str_replace($customGroupCountPrefix, '', $key);
            $newGroupID = ArrayHelper::value($oldGroupID, $groupMapping);

            if (!$newGroupID) {
              continue;
            }

            $newKey = sprintf('%s%d', $customGroupCountPrefix, $newGroupID);
            unset($node->webform_civicrm['data'][$entity][$index][$key]);
            $node->webform_civicrm['data'][$entity][$index][$newKey] = $value;
          }
        }
      }
    }
  }

  /**
   * Returns true if key matches the format cg<groupID>_custom_<fieldID>
   *
   * @param string $formKey
   *
   * @return bool
   */
  private static function isCustomFieldKey($formKey) {
    return !empty(KeyHelper::getCustomGroupID($formKey));
  }
}
