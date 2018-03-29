<?php

namespace Drupal\civihr_employee_portal\Webform;

use CRM_Utils_Array as ArrayHelper;
use Drupal\civihr_employee_portal\Webform\CustomComponentKeyHelper as KeyHelper;

/**
 * Responsible for adding metadata on custom fields when exporting webforms and
 * using that metadata to correct cross-system changes in custom field IDs when
 * importing webforms.
 */
class WebformExportCustomFieldConvertor implements WebformTransferConvertor {

  /**
   * Supplements the node data with a snapshot of a mapping of custom group and
   * field IDs to their machine name for use when re-importing.
   *
   * @param \stdClass $node
   */
  public static function preExport(\stdClass $node) {
    if ($node->type !== 'webform') {
      return;
    }

    $components = ArrayHelper::value('components', $node->webform, []);
    $customGroupIDs = [];
    $customFieldIDs = [];

    foreach ($components as $key => $component) {
      $formKey = ArrayHelper::value('form_key', $component);

      if (!KeyHelper::isCustomFieldKey($formKey)) {
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
   * Replaces form keys with the correct custom group and field ID for this
   * CiviCRM instance if metadata exists in the import node.
   *
   * @param \stdClass $node
   */
  public static function preImport(\stdClass $node) {
    if ($node->type !== 'webform') {
      return;
    }

    // Node was not exported since this change was applied
    if (empty($node->customMapping['customGroups'])) {
      return;
    }

    $groupNameMapping = $node->customMapping['customGroups'];
    $groupMapping = self::reverseNameMapping('CustomGroup', $groupNameMapping);
    $fieldNameMapping = $node->customMapping['customFields'];
    $fieldMapping = self::reverseNameMapping('CustomField', $fieldNameMapping);
    $components = ArrayHelper::value('components', $node->webform, []);

    foreach ($components as $index => $component) {
      $formKey = ArrayHelper::value('form_key', $component);
      $newKey = NULL;

      if (KeyHelper::isCustomFieldKey($formKey)) {
        $newKey = self::getUpdatedCustomFieldKey(
          $formKey,
          $groupMapping,
          $fieldMapping
        );
      }
      elseif (KeyHelper::isCustomFieldsetKey($formKey)) {
        $newKey = self::getUpdatedCustomFieldsetKey($formKey, $groupMapping);
      }

      if ($newKey) {
        $node->webform['components'][$index]['form_key'] = $newKey;
      }
    }

    self::replaceWebformCiviCRMCounts($node, $groupMapping);
    self::replaceConfigCreateModeIds($node, $groupMapping);
  }

  /**
   * The webform node also keeps a count of how many custom groups values are
   * in use when exporting. However it uses the format "number_of_cg_<groupID>"
   * and if the group ID changes it disables this custom group in the webform.
   *
   * @param \stdClass $node
   * @param array $groupMapping
   */
  private static function replaceWebformCiviCRMCounts(\stdClass $node, $groupMapping) {
    $civiWebform = isset($node->webform_civicrm) ? $node->webform_civicrm : [];
    $civiGroups = ArrayHelper::value('data', $civiWebform, []);
    $prefix = 'number_of_cg';

    foreach ($civiGroups as $entity => $groups) {
      foreach ($groups as $index => $values) {

        if (!is_array($values)) {
          continue;
        }

        foreach ($values as $key => $value) {

          if (substr($key, 0, strlen($prefix)) === $prefix) {
            $oldGroupID = str_replace($prefix, '', $key);
            $newGroupID = ArrayHelper::value($oldGroupID, $groupMapping);

            if (is_null($newGroupID)) {
              continue;
            }

            $newKey = sprintf('%s%d', $prefix, $newGroupID);

            unset($node->webform_civicrm['data'][$entity][$index][$key]);
            $node->webform_civicrm['data'][$entity][$index][$newKey] = $value;
          }
        }
      }
    }
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

    if (empty($ids)) {
      return [];
    }

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
      $originalID = ArrayHelper::key($result['name'], $originalMapping);
      $oldToNewMapping[$originalID] = $result['id'];
    }

    return $oldToNewMapping;
  }

  /**
   * Fixes the create mode for webform configuration. The creation mode key
   * references custom group ID, which can change on each system.
   *
   * @param \stdClass $node
   * @param array $groupMapping
   */
  private static function replaceConfigCreateModeIds($node, $groupMapping) {
    $civiWebform = isset($node->webform_civicrm) ? $node->webform_civicrm : [];
    $data = ArrayHelper::value('data', $civiWebform, []);
    $config = ArrayHelper::value('config', $data, []);
    $createModes = ArrayHelper::value('create_mode', $config);
    $fixedModes = [];
    $groupPrefix = 'cg';

    foreach ($createModes as $key => $mode) {
      $parts = explode('_', $key);
      $originalGroupId = ArrayHelper::value(4, $parts);
      $originalGroupId = str_replace($groupPrefix, '', $originalGroupId);
      if (!isset($groupMapping[$originalGroupId])) {
        continue;
      }
      $newGroupId = $groupMapping[$originalGroupId];
      $parts[4] = $groupPrefix . $newGroupId;
      $fixedKey = implode('_', $parts);
      $fixedModes[$fixedKey] = $mode;
    }

    $node->webform_civicrm['data']['config']['create_mode'] = $fixedModes;
  }

  /**
   * Uses old-to-new mapping to replace custom group and field IDs in a
   * provided form key
   *
   * @param string $formKey
   *   The original form key
   * @param array $groupMapping
   *   Mapping of original custom group IDs to current ones on system
   * @param $fieldMapping
   *   Mapping of original custom field IDs to current ones on system
   *
   * @return string|null
   *   The updated field key, or null if the custom group/field is unrecognized
   */
  private static function getUpdatedCustomFieldKey(
    $formKey,
    $groupMapping,
    $fieldMapping
  ) {
    $oldGroupID = KeyHelper::getCustomGroupID($formKey);
    $newGroupID = ArrayHelper::value($oldGroupID, $groupMapping);
    $oldFieldID = KeyHelper::getCustomFieldID($formKey);
    $newFieldID = ArrayHelper::value($oldFieldID, $fieldMapping);

    if ($newGroupID && $newFieldID) {
      return KeyHelper::rebuildCustomFieldKey($newGroupID, $newFieldID, $formKey);
    }

    return NULL;
  }

  /**
   * Uses old-to-new custom group mapping to replace custom group ID in a
   * provided form key
   *
   * @param string $formKey
   *   The original form key
   * @param array $groupMapping
   *   Mapping of original custom group IDs to current ones on system
   *
   * @return string|null
   *   The updated field key, or null if the custom group is unrecognized
   */
  private static function getUpdatedCustomFieldsetKey($formKey, $groupMapping) {
    $oldGroupId = KeyHelper::getCustomFieldsetGroupId($formKey);
    $newGroupId = ArrayHelper::value($oldGroupId, $groupMapping);

    if ($newGroupId) {
      return KeyHelper::rebuildCustomFieldsetKey($formKey, $newGroupId);
    }

    return NULL;
  }

}
