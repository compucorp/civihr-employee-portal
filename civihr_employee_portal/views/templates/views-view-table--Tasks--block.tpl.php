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

define('PAST_DAY', 1);
define('TODAY', 2);
define('DAY_AFTER_WEEKEND', 4);
define('TOMORROW', 5);
define('ANY_OTHER_DAY', 3);

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
$contactsFilterValues = array();

foreach ($rows as $row):
    $rowType = null;
    if (strip_tags($row['task_contacts_1']) == $civiUser['contact_id']):
        $rowType = 'task-my';
    endif;
    if (strip_tags($row['task_contacts_2']) == $civiUser['contact_id'] && strip_tags($row['task_contacts_1']) != $civiUser['contact_id']):
        $rowType = 'task-delegated';
    endif;
    if (!$rowType):
        continue;
    endif;
    $contactsIds[strip_tags($row['task_contacts'])] = 1;
    $taskFiltersCount[_get_task_filter_by_date($row['activity_date_time'])]++;
    $taskFiltersCount[0]++;
endforeach;

$contactsResult = civicrm_api3('Contact', 'get', array(
  'id' => array('IN' => array_keys($contactsIds)),
  'return' => "sort_name",
));
foreach ($contactsResult['values'] as $key => $value) {
    $contactsFilterValues[$key] = $value['sort_name'];
}

function _get_task_filter_by_date($date) {
    $today = date('Y-m-d');
    $tomorrow = new DateTime('tomorrow');
    $nbDay = date('N', strtotime($today));
    $sunday = new DateTime($today);
    $sunday->modify('+' . (7 - $nbDay) . ' days');
    $weekEnd = $sunday->format('Y-m-d');
    $taskDate = date('Y-m-d', strtotime(strip_tags($date)));

    if ($taskDate < $today) {
        return PAST_DAY;
    }
    if ($taskDate == $today) {
        return TODAY;
    }
    if ($taskDate > $weekEnd) {
        return DAY_AFTER_WEEKEND;
    }
    if ($taskDate == $tomorrow->format('Y-m-d')){
        return TOMORROW;
    }
    return ANY_OTHER_DAY;
}

function isFieldName($field){
   return $field == 'task_contacts' || $field == 'task_contacts_1' || $field == 'task_contacts_2';
}

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
                            if (isFieldName($field)) {
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
                    <?php $rowType = null;
                    if (strip_tags($row['task_contacts_1']) == $civiUser['contact_id']):
                        $rowType = 'task-my';
                    endif;
                    if (strip_tags($row['task_contacts_2']) == $civiUser['contact_id'] && strip_tags($row['task_contacts_1']) != $civiUser['contact_id']):
                        $rowType = 'task-delegated';
                    endif;
                    if (!$rowType):
                        continue;
                    endif;
                    $rowContacts = strip_tags($row['task_contacts']) . ',' . strip_tags($row['task_contacts_1']) . ',' . strip_tags($row['task_contacts_2']);
                    ?>
                    <?php $class = 'task-row task-filter-id-' . _get_task_filter_by_date($row['activity_date_time']) . ' ' . $rowType; ?>
                    <tr id="row-task-id-<?php print strip_tags($row['id']); ?>" <?php if ($row_classes[$row_count] || $class) { print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';  } ?> data-row-contacts="<?php print $contactsFilterValues[strip_tags($row['task_contacts'])]; ?>">
                        <?php
                          foreach ($row as $field => $content):
                            if (isFieldName($field)) {
                              continue;
                            }

                            if($field == 'activity_date_time') {
                              $taskDate = strtotime(strip_tags($content));
                              $dateFilter = _get_task_filter_by_date(date('Y-m-d', $taskDate));

                              if($dateFilter == TOMORROW){
                                $content = 'Tomorrow';
                              }else if($dateFilter == TODAY){
                                $content = 'Today';
                              }else{
                                $content = date('m/d/Y', $taskDate);
                              }
                            }
                        ?>
                            <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
								<?php //if (_task_can_be_edited($row['id'])): ?>
                                <a
                                    href="/civi_tasks/nojs/edit/<?php print strip_tags($row['id']); ?>"
                                    class="ctools-use-modal ctools-modal-civihr-custom-style ctools-use-modal-processed">
								<?php //endif; ?>
                                    <?php print strip_tags(html_entity_decode($content)); ?>
								<?php //if (_task_can_be_edited($row['id'])): ?>
                                </a>
								<?php //endif; ?>
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
    (function($){
        var $navDocFilter = $('#nav-tasks-filter'),
            $dropdownFilter = $('#select-tasks-filter'),
            $navDocTypes = $('#nav-tasks-types'),
            $dropdownTypes = $('#select-tasks-types'),
            $tableDocStaff = $('#tasks-dashboard-table-staff'),
            $tableDocStaffRows = $tableDocStaff.find('.task-row');

        var $selectedRowFilter =  $tableDocStaff.find('.task-row'),
            $selectedRowType = $tableDocStaff.find('.task-row'),
            selectedRowFilterSelector = null;

        var currentTaskTypeClass = '';

        $navDocFilter.find('a').bind('click', function(e) {
            e.preventDefault();

            var $this = $(this),
                taskFilter = $this.data('taskFilter');

            $navDocFilter.find('> li').removeClass('active');
            $this.parent().addClass('active');

            if (!taskFilter) {
                $selectedRowFilter = $tableDocStaff.find('.task-row');
                selectedRowFilterSelector = '.task-row';
            } else {
                $selectedRowFilter = $tableDocStaff.find('.task-filter-id-' + taskFilter);
                selectedRowFilterSelector = '.task-filter-id-' + taskFilter;
            }

            showFilteredTaskRows();
        });

        $dropdownFilter.on('change', function (e) {
            var taskFilter = $(this).val();

            if (parseInt(taskFilter, 10) === 0) {
                $selectedRowFilter = $tableDocStaff.find('.task-row');
                selectedRowFilterSelector = '.task-row';
            } else {
                $selectedRowFilter = $tableDocStaff.find('.task-filter-id-' + taskFilter);
                selectedRowFilterSelector = '.task-filter-id-' + taskFilter;
            }

            showFilteredTaskRows();
        });

        $navDocTypes.find('button').bind('click', function(e) {
            e.preventDefault();

            var $this = $(this),
                taskType = $this.data('taskType');

            $navDocTypes.children().removeClass('active');
            $this.addClass('active');
            if (taskType === 'all') {
                $selectedRowType = $tableDocStaff.find('.task-row');
                currentTaskTypeClass = '';
                refreshTasksCounter(currentTaskTypeClass);
            } else {
                currentTaskTypeClass = '.task-' + taskType;
                $selectedRowType = $tableDocStaff.find(currentTaskTypeClass);
                refreshTasksCounter(currentTaskTypeClass);
            }

            showFilteredTaskRows();
        });

        $dropdownTypes.on('change', function (e) {
            var taskType = $(this).val();

            if (taskType === 'all') {
                $selectedRowType = $tableDocStaff.find('.task-row');
                currentTaskTypeClass = '';
                refreshTasksCounter(currentTaskTypeClass);
            } else {
                currentTaskTypeClass = '.task-' + taskType;
                $selectedRowType = $tableDocStaff.find(currentTaskTypeClass);
                refreshTasksCounter(currentTaskTypeClass);
            }

            showFilteredTaskRows();
        });

        var chk = CRM.$('.checkbox-task-completed');
        chk.unbind('change').bind('change', function(e) {
            var checkedTaskId = $(this).val();
            $.ajax({
                url: '/civi_tasks/ajax/complete/' + checkedTaskId,
                success: function(result) {
                    if (!result.success) {
                        CRM.alert(result.message, 'Error', 'error');
                        return;
                    }
                    $('#row-task-id-' + checkedTaskId).fadeOut(500, function() {
                        $(this).remove();
                        refreshTasksCounter(currentTaskTypeClass);
                    });
                }
            });
        });

        buildTaskContactFilter();

        function showFilteredTaskRows() {
            $tableDocStaffRows
              .hide()
              .removeClass('selected-by-type')
              .removeClass('selected-by-filter');
            $selectedRowType.addClass('selected-by-type');
            $selectedRowFilter.addClass('selected-by-filter');
            $('.selected-by-type.selected-by-filter.selected-by-contact', $tableDocStaff).show();
        }

        function refreshTasksCounter(taskTypeClass) {
            var sum = 0;
            for (var i = 1; i < <?php print count($taskFilters); ?>; i++) {
                var counter = $(taskTypeClass + '.task-filter-id-' + i, $tableDocStaff).length;
                sum += counter;
                $('#nav-tasks-filter .task-counter-filter-' + i).text(counter);
            }
            $('#nav-tasks-filter .task-counter-filter-0').text(sum);
        }

        function buildTaskContactFilter() {
            $tableDocStaffRows.addClass('selected-by-contact');
            $('#task-filter-contact').on("keyup", function() {
                var value = $(this).val().toLowerCase();
                $tableDocStaffRows.removeClass('selected-by-contact');
                $("#tasks-dashboard-table-staff > tbody > tr.task-row").each(function(index) {
                    var $row = $(this);
                    var text = $row.data('rowContacts') || '';
                    var matchedIndex = text.toLowerCase().indexOf(value);
                    if (value.length === 0 || matchedIndex !== -1) {
                      $row.addClass('selected-by-contact');
                    } else {
                      $row.removeClass('selected-by-contact');
                    }
                });
                showFilteredTaskRows();
            });
        }
    }(CRM.$));
</script>
