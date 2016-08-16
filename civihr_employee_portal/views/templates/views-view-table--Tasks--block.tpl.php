<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */

global $user;

/**
 * Checks if a task is assigned to the given user
 * @param  object $task
 * @param  int $user_id
 * @return boolean
 */
function taskAssignedToUser($task, $user_id) {
  return strip_tags($task['task_contacts_1']) != $user_id;
}

$civiUser = get_civihr_uf_match_data($user->uid);

$typeResult = civicrm_api3('Activity', 'getoptions', array(
    'field' => "activity_type_id",
));
$types = $typeResult['values'];

$taskFilters = array(
    0 => 'All',
    1 => 'Overdue',
    2 => 'Due Today',
    3 => 'Due This Week',
    4 => 'Later',
);
$taskFiltersCount = array_combine(array_keys($taskFilters), array_fill(0, count($taskFilters), 0));
$contactsIds = array();
$contacts = array();

foreach ($rows as $row):
  if (taskAssignedToUser($row, $civiUser['contact_id'])) {
    continue;
  }

  $contactsIds[strip_tags($row['task_contacts'])] = 1;
  $taskFiltersCount[_get_task_filter_by_date($row['activity_date_time'])]++;
  $taskFiltersCount[0]++;
endforeach;

$contactsFilterValues = _get_contacts_filter_values($contactsIds);

?>

<div class="chr_table-w-filters row">
    <div class="chr_table-w-filters__filters col-md-3">
        <div class="chr_table-w-filters__filters__dropdown-wrapper">
            <div class="chr_custom-select chr_custom-select--full">
                <select id="select-tasks-filter" class="chr_table-w-filters__filters__dropdown skip-js-custom-select">
                    <?php foreach ($taskFilters as $key => $value): ?>
                        <option value="<?php print $key; ?>"><?php print $value; ?> (<?php print $taskFiltersCount[$key]; ?>)</option>
                    <?php endforeach; ?>
                </select>
            </div>
        </div>
        <ul id="nav-tasks-filter" class="chr_table-w-filters__filters__nav">
            <?php $classActive = ' class="active"'; ?>
            <?php foreach ($taskFilters as $key => $value): ?>
                <?php $badgeType = $key == 1 ? 'danger' : 'primary'; ?>
                <li<?php print $classActive; ?>>
                    <a href data-task-filter="<?php print $key; ?>">
                        <?php print $value; ?>
                        <span class="badge badge-<?php print $badgeType; ?> pull-right task-counter-filter-<?php print $key; ?>">
                            <?php print $taskFiltersCount[$key]; ?>
                        </span>
                    </a>
                </li>
                <?php $classActive = ''; ?>
            <?php endforeach; ?>
        </ul>
    </div>
    <div class="chr_table-w-filters__table-wrapper col-md-9">
        <div class="chr_table-w-filters__table">
            <table id="tasks-dashboard-table-staff" <?php if ($classes) { print 'class="'. $classes . ' tasks-dashboard-table" '; } ?><?php print $attributes; ?>>
                <?php if (!empty($title) || !empty($caption)) : ?>
                    <caption><?php print $caption . $title; ?></caption>
                <?php endif; ?>
                <?php if (!empty($header)) : ?>
                    <thead>
                        <tr>
                        <?php
                          foreach ($header as $field => $label):
                            if (_is_field_task_contact($field)) {
                              continue;
                            }
                        ?>
                            <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
                                <?php print $label; ?>
                            </th>
                        <?php endforeach; ?>
                            <th><?php print t('Mark Complete'); ?></th>
                        </tr>
                    </thead>
                <?php endif; ?>
                <tbody>
                <?php foreach ($rows as $row_count => $row): ?>
                    <?php
                    if (taskAssignedToUser($row, $civiUser['contact_id'])) {
                      continue;
                    }

                    $class = 'task-row task-filter-id-' . _get_task_filter_by_date($row['activity_date_time']);
                    $targetKey = strip_tags($row['task_contacts']);
                    $contactsFilterValue = !empty($contactsFilterValues[$targetKey]) ? $contactsFilterValues[$targetKey] : '';
                    ?>
                    <tr id="row-task-id-<?php print strip_tags($row['id']); ?>" <?php if ($row_classes[$row_count] || $class) { print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';  } ?> data-row-contacts="<?php print $contactsFilterValue; ?>">
                        <?php
                          foreach ($row as $field => $content):
                            if (_is_field_task_contact($field)) {
                              continue;
                            }

                            if($field == 'activity_date_time') {
                              $taskDate = strtotime(strip_tags($content));
                              $dateFilter = _get_task_filter_by_date(date('Y-m-d', $taskDate));

                              if ($dateFilter == TASK_TOMORROW) {
                                $content = 'Tomorrow';
                              } else if ($dateFilter == TASK_TODAY) {
                                $content = 'Today';
                              } else {
                                $content = date('m/d/Y', $taskDate);
                              }
                            }
                        ?>
                          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                            <a
                              href="/civi_tasks/nojs/edit/<?php print strip_tags($row['id']); ?>"
                              class="ctools-use-modal ctools-modal-civihr-custom-style ctools-use-modal-processed">
                              <?php print strip_tags(html_entity_decode($content)); ?>
                            </a>
                          </td>
                        <?php endforeach; ?>
                            <td>
                                <?php
                                $checked = '';
                                $disabled = '';
                                if (!_task_can_be_marked_as_complete($row['id'])):
                                    $disabled = ' disabled="disabled" ';
                                endif;
                                ?>
                                <input type="checkbox" id="task-completed[<?php print strip_tags($row['id']); ?>" class="checkbox-task-completed" value="<?php print strip_tags($row['id']); ?>"<?php print $checked . $disabled; ?> />
                            </td>
                    </tr>
                <?php endforeach; ?>
                </tbody>
            </table>
        </div>
    </div>
</div>
<?php if (user_access('can create and edit tasks')): ?>
    <div class="chr_panel__footer">
        <div class="chr_actions-wrapper">
            <a href="/civi_tasks/nojs/create" class="chr_action ctools-use-modal ctools-modal-civihr-custom-style ctools-use-modal-processed">Create new task</a>
        </div>
    </div>
<?php endif; ?>
<script>
  (function ($) {
    Drupal.behaviors.civihr_employee_portal_tasks.initTasksFilters();
  }(CRM.$));
</script>
