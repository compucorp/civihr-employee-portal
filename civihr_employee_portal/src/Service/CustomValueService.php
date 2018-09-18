<?php

namespace Drupal\civihr_employee_portal\Service;

class CustomValueService {

  /**
   * @var array
   *   In-memory cache of custom groups
   */
  private $customGroups = [];

  /**
   * @var array
   *   In-memory cache of custom fields
   */
  private $customFields = [];

  /**
   * @param int $entityId
   * @param string $groupName
   * @param string $fieldName
   *
   * @return mixed
   *   The custom value
   */
  public function getValueForEntity($entityId, $groupName, $fieldName) {
    $customField = $this->getCustomField($groupName, $fieldName);
    $values = \CRM_Core_BAO_CustomValueTable::getEntityValues(
      $entityId,
      NULL,
      [$customField['id']]
    );

    // return array if multi value custom group, otherwise single value
    if ($this->isMultiValueGroup($groupName)) {
      return $values;
    } else {
      return reset($values);
    }
  }

  /**
   * Checks whether a given custom group is a multi-value custom group
   *
   * @param string $groupName
   *
   * @return bool
   */
  private function isMultiValueGroup($groupName) {
    return (bool) $this->getCustomGroup($groupName)['is_multiple'];
  }

  /**
   * Fetches custom field data
   *
   * @param string $groupName
   * @param string $fieldName
   *
   * @return array
   */
  private function getCustomField($groupName, $fieldName) {
    if (!isset($this->customFields[$groupName][$fieldName])) {
      $params = ['name' => $fieldName, 'custom_group_id' => $groupName];
      $field = civicrm_api3('CustomField', 'getsingle', $params);
      $this->customFields[$groupName][$fieldName] = $field;
    }

    return $this->customFields[$groupName][$fieldName];
  }

  /**
   * Fetches custom group data
   *
   * @param string $groupName
   *
   * @return array
   */
  private function getCustomGroup($groupName) {
    if (!isset($this->customGroups[$groupName])) {
      $group = civicrm_api3('CustomGroup', 'getsingle', ['name' => $groupName]);
      $this->customGroups[$groupName] = $group;
    }

    return $this->customGroups[$groupName];
  }

}
