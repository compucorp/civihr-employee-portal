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
            <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
              <?php print $label; ?>
            </th>
        <?php endforeach; ?>
            <th></th>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <?php $class = 'document-row status-id-' . strip_tags($row['status_id']); ?>
      <tr <?php if ($row_classes[$row_count] || $class) { print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
            <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
              <?php if ($field === 'status_id'): ?>
                    <select class="document-status" name="document-<?php print strip_tags($row['id']); ?>-select-status" data-id="<?php print strip_tags($row['id']); ?>" data-original-value="<?php print (int)strip_tags($content); ?>">
                <?php foreach ($statuses as $statusKey => $statusValue): ?>
                    <?php
                        $selected = '';
                        if ($statusKey == (int)strip_tags($content)):
                            $selected = ' selected="selected"';
                        endif;
                    ?>
                    <option value="<?php print $statusKey; ?>"<?php print $selected; ?>><?php print $statusValue; ?></option>
                <?php endforeach; ?>
                </select>
              <?php continue; ?>
              <?php endif; ?>
              <?php if ($field === 'case_id'): ?>
              <?php
                $caseId = (int)strip_tags($content);
                if ($caseId):
                    $case = civicrm_api3('Case', 'get', array(
                      'sequential' => 1,
                      'id' => $caseId,
                    ));
                    $caseType = civicrm_api3('CaseType', 'get', array(
                      'sequential' => 1,
                      'id' => $case['values'][0]['case_type_id'],
                    ));
                    print $caseType['values'][0]['title'];
                endif;
              ?>
              <?php continue; ?>
              <?php endif; ?>
              <?php print strip_tags(html_entity_decode($content)); ?>
            </td>
        <?php endforeach; ?>
          <td>
              <div class="btn-group">
                  <a href class="dropdown-toggle context-menu-toggle" data-toggle="dropdown"><i class="fa fa-ellipsis-v"></i></a>
                  <ul class="dropdown-menu pull-right">
                      <?php if ((int)strip_tags($row['file_count'])): ?><li><a href="/civicrm/tasksassignments/file/zip?entityID=<?php print $row['id']; ?>&entityTable=civicrm_activity" target="_blank"><i class="fa fa-download"></i> Download</a></li><?php endif; ?>
                      <li><a href="/civi_documents/nojs/edit/<?php print $row['id']; ?>" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed"><i class="fa fa-pencil"></i> Edit</a></li>
                      <li><a href="/civi_documents/nojs/reminder/<?php print $row['id']; ?>" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed"><i class="fa fa-envelope-o"></i> Send reminder</a></li>
                      <li><a href="/civi_documents/nojs/delete/<?php print $row['id']; ?>" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed"><i class="fa fa-trash-o"></i> Delete</a></li>
                  </ul>
              </div>
            </td>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>

<script>
    (function($, CRM){
        var $tableDocManager = $('#documents-dashboard-table-manager');

        $tableDocManager.find('.document-status').change(function(e){
            var selectEl = e.delegateTarget,
                $select = $(selectEl);

            $select.attr('disabled', 'disabled');

            $.ajax({
                url: '/civi_documents/ajax/change_document_status/' + $select.data('id') + '/' + selectEl.value,
                success: function(result) {
                    $select.removeAttr('disabled');

                    if (!result.success) {
                        CRM.alert(result.message, 'Error', 'error');
                        $select.val($select.data('originalValue'));
                        return
                    }

                    $select.data('originalValue',selectEl.value);

                }
            });
        });
    }(CRM.$, CRM));
</script>
