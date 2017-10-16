<?php

namespace Drupal\civihr_employee_portal\Service;

class TaskCreationService {
  /**
   * @param int $contactID
   * @param array $assigneeIDs
   * @param string $taskType
   * @param \DateTime $date
   */
  public static function create($contactID, $assigneeIDs, $taskType, $date) {
    $taskTypeId = static::getTaskTypeID($taskType);

    if (NULL === $taskTypeId) {
      return;
    }

    civicrm_api3('Task', 'create', [
      'assignee_contact_id' => $assigneeIDs,
      'activity_type_id' => $taskTypeId,
      'activity_date_time' => $date->format('d-m-Y'),
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
}
