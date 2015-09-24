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
$civiUser = get_civihr_uf_match_data($user->uid);

$typeResult = civicrm_api3('Activity', 'getoptions', array(
    'field' => "activity_type_id",
));
$types = $typeResult['values'];

$statusesResult = civicrm_api3('Task', 'getstatuses', array(
    'sequential' => 1,
));
$statuses = array(0 => 'All');
foreach ($statusesResult['values'] as $status):
    $statuses[$status['value']] = $status['label'];
endforeach;

$taskFilters = array(
    0 => 'All',
    1 => 'Overdue',
    2 => 'Due Today',
    3 => 'Due This Week',
    4 => 'Later',
);
$taskFiltersCount = array_combine(array_keys($taskFilters), array_fill(0, count($taskFilters), 0));

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
    $taskFiltersCount[_get_task_filter_by_date($row['activity_date_time'])]++;
    $taskFiltersCount[0]++;
endforeach;

function _get_task_filter_by_date($date) {
    $today = date('Y-m-d');
    $nbDay = date('N', strtotime($today));
    $sunday = new DateTime($today);
    $sunday->modify('+' . (7 - $nbDay) . ' days');
    $weekEnd = $sunday->format('Y-m-d');
    $taskDate = date('Y-m-d', strtotime(strip_tags($date)));
    
    if ($taskDate < $today) {
        return 1;
    }
    if ($taskDate == $today) {
        return 2;
    }
    if ($taskDate > $weekEnd) {
        return 4;
    }
    return 3;
}

?>
<div class="row">
    <div class="col-xs-12 col-sm-4 col-lg-3">
        <ul id="nav-tasks-filter" class="nav nav-pills nav-stacked">
<?php $classActive = ' class="active"'; ?>
<?php foreach ($taskFilters as $key => $value): ?>
            <li<?php print $classActive; ?>><a href data-task-filter="<?php print $key; ?>"><?php print $value; ?> <span class="badge pull-right task-counter-filter-<?php print $key; ?>"><?php print $taskFiltersCount[$key]; ?></span></a></li>
<?php $classActive = ''; ?>
<?php endforeach; ?>
        </ul>
    </div>
    <div class="col-xs-12 col-sm-8 col-lg-9">
        <table id="tasks-dashboard-table-staff" <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
            <?php if (!empty($title) || !empty($caption)) : ?>
                <caption><?php print $caption . $title; ?></caption>
            <?php endif; ?>
            <?php if (!empty($header)) : ?>
                <thead>
                    <tr>
                    <?php foreach ($header as $field => $label): ?>
                        <?php if ($field == 'task_contacts' || $field == 'task_contacts_1' || $field == 'task_contacts_2'):
                            continue;
                        endif; ?>
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
                ?>
                <?php $class = 'task-row task-filter-id-' . _get_task_filter_by_date($row['activity_date_time']) . ' ' . $rowType; ?>
                <tr id="row-task-id-<?php print strip_tags($row['id']); ?>" <?php if ($row_classes[$row_count] || $class) { print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';  } ?>>
                    <?php foreach ($row as $field => $content): ?>
                        <?php if ($field == 'task_contacts' || $field == 'task_contacts_1' || $field == 'task_contacts_2'):
                            continue;
                        endif; ?>
                        <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                            <a
                                href="/civi_tasks/nojs/edit/<?php print strip_tags($row['id']); ?>"
                                class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">
                            <?php if ($field === 'activity_type_id'):
                                print $types[strip_tags($content)];
                                continue;
                            endif;
                            ?>
                            <?php if ($field === 'activity_date_time' && trim(strip_tags($content))):
                                print date('M d Y', strtotime(strip_tags($content)));
                                continue;
                            endif; ?>
                            <?php if ($field === 'status_id'):
                                print $statuses[strip_tags($content)];
                                continue;
                            endif; ?>
                            <?php print strip_tags(html_entity_decode($content)); ?>
                            </a>
                        </td>
                    <?php endforeach; ?>
                        <td>
                            <?php
                            $checked = '';
                            $disabled = '';
                            if (strip_tags($row['status_id']) == 2):
                                $checked = ' checked="checked" ';
                                $disabled = ' disabled="disabled" ';
                            endif;
                            if (!user_access('can create and edit tasks')):
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
    <?php if (user_access('can create and edit tasks')): ?>
    <a href="/civi_tasks/nojs/create" class="btn btn-sm btn-custom ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">Create new task</a>
    <?php endif; ?>
</div>

<script>
    (function($){
        var $navDocFilter = $('#nav-tasks-filter'),
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
        
        var $navDocTypes = $('#nav-tasks-types');
        
        $navDocTypes.find('a').bind('click', function(e) {
            e.preventDefault();

            var $this = $(this),
                taskType = $this.data('taskType');

            $navDocTypes.find('> li').removeClass('active');
            $this.parent().addClass('active');
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
            var checkedTaskId = CRM.$(this).val();
            CRM.api3('Task', 'create', {
                "sequential": 1,
                "id": checkedTaskId,
                "status_id": 1
            }).done(function(result) {
                if (!result.is_error) {
                    CRM.$('#row-task-id-' + checkedTaskId).fadeOut(500, function() {
                        CRM.$(this).remove();
                        refreshTasksCounter(currentTaskTypeClass);
                    })
                }
            });
        });
        
        function showFilteredTaskRows() {
            $tableDocStaffRows.hide();
            $tableDocStaffRows.removeClass('selected-by-type').removeClass('selected-by-filter');
            $selectedRowType.addClass('selected-by-type');
            $selectedRowFilter.addClass('selected-by-filter');
            $('.selected-by-type.selected-by-filter', $tableDocStaff).show();
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
    }(CRM.$));
</script>
