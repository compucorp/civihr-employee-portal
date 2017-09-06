<?php

namespace Drupal\civihr_employee_portal\Service;

class TaskCreationService {
  /**
   * @param int $contactID
   * @param string $taskTypeName
   * @param string $date
   */
  public static function createForAllManagers($contactID, $taskTypeName, $date) {
    $taskTypeId = static::getTaskTypeID($taskTypeName);
    $managerIds = static::getManagerIDs($contactID);

    if (NULL === $taskTypeId || empty($managerIds)) {
      return;
    }

    civicrm_api3('Task', 'create', [
      'assignee_contact_id' => $managerIds,
      'activity_type_id' => $taskTypeId,
      'activity_date_time' => $date,
      'target_id' => $contactID,
    ]);
  }

  /**
   * @param $taskTypeName
   *
   * @return null|int
   */
  private static function getTaskTypeID($taskTypeName) {
    $taskType = civicrm_api3('OptionValue', 'get', [
      'option_group_id' => 'activity_type',
      'component_id' => 'CiviTask',
      'name' => $taskTypeName
    ]);

    if ($taskType['count'] != 1) {
      return NULL;
    }

    $taskType = $taskType['values'];
    $taskType = array_shift($taskType);

    return $taskType['value'];
  }

  /**
   * @param $contactID
   *
   * @return array
   */
  private static function getManagerIDs($contactID) {
    $managerRelationshipName = 'Line manager is';

    $lineManagerType = civicrm_api3('RelationshipType', 'get', [
      'name_a_b' => $managerRelationshipName,
    ]);

    if ($lineManagerType['count'] != 1) {
      return [];
    }
    $lineManagerTypeId = array_shift($lineManagerType['values'])['id'];

    $relationships = civicrm_api3('Relationship', 'get', [
      'relationship_type_id' => $lineManagerTypeId,
      'contact_id_a' => $contactID,
      'is_active' => 1,
    ]);

    return array_column($relationships['values'], 'contact_id_b');
  }
}
