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
$statuses = array();
foreach ($statusesResult['values'] as $status):
    $statuses[$status['value']] = $status['label'];
endforeach;

?>
<div class="row">
    <div class="col-xs-12 col-sm-12 col-lg-12">
        <table id="tasks-dashboard-table-staff" <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
            <?php if (!empty($title) || !empty($caption)) : ?>
                <caption><?php print $caption . $title; ?></caption>
            <?php endif; ?>
            <?php if (!empty($header)) : ?>
                <thead>
                    <tr>
                    <?php foreach ($header as $field => $label): ?>
                        <?php if ($field == 'task_contacts' || $field == 'task_contacts_1' || $field == 'activity_date_time'):
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
                <?php $rowType = 'task-my'; ?>
                <?php if (strip_tags($row['task_contacts_1']) == $civiUser['contact_id']):
                    $rowType = 'task-delegated';
                endif; ?>
                <?php $class = 'task-row status-id-' . strip_tags($row['status_id']) . ' ' . $rowType; ?>
                <tr <?php if ($row_classes[$row_count] || $class) { print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';  } ?>>
                    <?php foreach ($row as $field => $content): ?>
                        <?php if ($field == 'task_contacts' || $field == 'task_contacts_1' ||  $field == 'activity_date_time'):
                            continue;
                        endif; ?>
                        <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                            <?php print strip_tags(html_entity_decode($content)); ?>
                        </td>
                    <?php endforeach; ?>
                        <td>
                            <?php
                            $checked = '';
                            if (strip_tags($row['status_id']) == 2):
                                $checked = ' checked="checked" ';
                            endif;
                            ?>
                            <input type="checkbox" class="checkbox-task-completed"<?php print $checked; ?> disabled="disabled" />
                        </td>
                </tr>
            <?php endforeach; ?>
            </tbody>
        </table>
    </div>
</div>
