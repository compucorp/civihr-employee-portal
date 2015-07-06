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

$fieldsToDisplay = array(
    'activity_type_id' => t('Type'),
    'activity_date_time' => t('Due Date'),
    'expire_date' => t('Expiry Date'),
    'status_id' => t('Status'),
    'nothing' => '',
);

$typeResult = civicrm_api3('Activity', 'getoptions', array(
    'field' => "activity_type_id",
));
$types = $typeResult['values'];

$statusesResult = civicrm_api3('Document', 'getstatuses', array(
    'sequential' => 1,
));
/*$statuses = array();
foreach ($statusesResult['values'] as $status):
    $statuses[$status['value']] = $status['label'];
endforeach;*/
$statuses = array(
    1 => 'Awaiting upload',
    2 => 'Awaiting approval',
    3 => 'Approved',
    4 => 'Rejected',
);

?>
<div id="documents-tabs">
    <div class="documents-tab status-all active" tab-index="0">All</div>
    <div class="documents-tab status-awaiting-upload" tab-index="1">Awaiting Upload</div>
    <div class="documents-tab status-awaiting-approval" tab-index="2">Awaiting Approval</div>
    <div class="documents-tab status-approved" tab-index="3">Approved</div>
    <div class="documents-tab status-rejected" tab-index="4">Rejected</div>
</div>
<table id="documents-dashboard-table-staff" <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <?php
          if (!in_array($field, array_keys($fieldsToDisplay))):
            continue;    
          endif;
          $label = $fieldsToDisplay[$field];
          ?>
            <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
              <?php print $label; ?>
            </th>
        <?php endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <?php $class = 'document-row status-id-' . strip_tags($row['status_id']); ?>
      <tr <?php if ($row_classes[$row_count] || $class) { print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
          <?php
          if (!in_array($field, array_keys($fieldsToDisplay))):
            continue;    
          endif;
          ?>
            <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
              <?php if ($field === 'activity_type_id'):
                print $types[strip_tags($content)];
                continue;
              endif;
              ?>
              <?php if ($field === 'status_id'):
                print $statuses[strip_tags($content)];
                continue;
              endif; ?>
              <?php print $content; ?>
            </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>

<script>
    CRM.$('.documents-tab').bind('click', function() {
        var tabIndex = CRM.$(this).attr('tab-index');
        if (tabIndex != 0) {
            CRM.$('.document-row').hide();
            CRM.$('.status-id-' + tabIndex).show();
        } else {
            CRM.$('.document-row').show();
        }
        CRM.$('.document-row:visible:odd').removeClass('odd').addClass('even');
        CRM.$('.document-row:visible:even').removeClass('even').addClass('odd');
        CRM.$('.documents-tab').removeClass('active');
        CRM.$(this).addClass('active');
    });
</script>
