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
    'case_id' => t('Assignment'),
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
<table id="documents-dashboard-table-manager" <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
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
              <?php if ($field === 'status_id'): ?>
                <select class="document-status" onchange="changeDocumentStatus(<?php print strip_tags($row['id']); ?>, this.value)">
                <?php foreach ($statuses as $statusKey => $statusValue): ?>
                    <?php
                        $selected = '';
                        if ($statusKey == strip_tags($content)):
                            $selected = ' selected="selected"';
                        endif;
                    ?>
                    <option value="<?php print $statusKey; ?>"<?php print $selected; ?>><?php print $statusValue; ?></option>
                <?php endforeach; ?>
                </select>
              <?php continue; ?>
              <?php endif; ?>
              <?php if ($field === 'nothing'): ?>
                <div class="more">
                    <span>More...</span>
                    <?php if ((int)strip_tags($row['file_count'])): ?><a href="/civicrm/tasksassignments/file/zip?entityID=<?php print $row['id']; ?>&entityTable=civicrm_activity" target="_blank">View</a><?php endif; ?>
                    <a href="/civi_documents/nojs/edit/<?php print $row['id']; ?>" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">Edit</a>
                    <a href="/civi_documents/nojs/reminder/<?php print $row['id']; ?>" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">Send reminder</a>
                    <a href="/civi_documents/nojs/delete/<?php print $row['id']; ?>" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">Delete</a>
                </div>
              <?php else: ?>
                <?php print strip_tags($content); ?>
              <?php endif; ?>
            </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>

<script>
    function changeDocumentStatus(id, value) {
        console.info('TODO: change Document status on the fly');
        console.info('id: ' + id);
        console.info('value: ' + value);
    }
</script>
