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
<div data-ta-documents-manager ng-controller="ModalController as document">
  <div> <!-- This div is mandatory, to append Modal -->
    <table id="documents-dashboard-table-manager" <?php if ($classes) {
      print 'class="' . $classes . '" ';
    } ?><?php print $attributes; ?>>
      <?php if (!empty($title) || !empty($caption)) : ?>
        <caption><?php print $caption . $title; ?></caption>
      <?php endif; ?>
      <?php if (!empty($header)) : ?>
        <thead>
          <tr>
            <?php foreach ($header as $field => $label): ?>
              <th <?php if ($header_classes[$field]) {
                print 'class="' . $header_classes[$field] . '" ';
              } ?>>
              <?php print $label; ?>
              </th>
            <?php endforeach; ?>
            <th></th>
          </tr>
        </thead>
        <?php endif; ?>
      <tbody>
        <?php foreach ($rows as $row_count => $row):
          if (!isset($row['id'])) {
            printf('<tr class = "document-row no-results"><td colspan="4">%s</td></tr>', $row[0]);
            continue;
          }
          $class = 'document-row status-id-' . strip_tags($row['status_id']); ?>
          <tr <?php if ($row_classes[$row_count] || $class) {
              print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';
            } ?>>
            <?php foreach ($row as $field => $content): ?>
              <td <?php if ($field_classes[$field][$row_count]) {
                  print 'class="' . $field_classes[$field][$row_count] . '" ';
                } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                <?php if ($field === 'status_id'): ?>
                  <select class="document-status" name="document-<?php print strip_tags($row['id']); ?>-select-status" data-id="<?php print strip_tags($row['id']); ?>" data-original-value="<?php print (int) strip_tags($content); ?>">
                    <?php foreach ($statuses as $statusKey => $statusValue): ?>
                      <?php
                        $selected = '';
                        if ($statusKey == (int) strip_tags($content)):
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
                    $caseId = (int) strip_tags($content);
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
              <button
              ng-click="document.modalDocument(<?php print strip_tags($row['id']); ?>, 'manager')"
              class="btn btn-sm btn-default">
                <i class="fa fa-upload"></i> Open
              </button>
            </td>
          </tr>
        <?php endforeach; ?>
      </tbody>
    </table>
  </div>
</div>

<script>
  (function ($, CRM) {
    var $tableDocManager = $('#documents-dashboard-table-manager');

    $tableDocManager.find('.document-status').change(function (e) {
      var selectEl = e.delegateTarget;
      var $select = $(selectEl);

      $select.attr('disabled', 'disabled');

      $.ajax({
        url: '/civi_documents/ajax/change_document_status/' + $select.data('id') + '/' + selectEl.value,
        success: function (result) {
          $select.removeAttr('disabled');

          if (!result.success) {
            CRM.alert(result.message, 'Error', 'error');
            $select.val($select.data('originalValue'));
            return
          }

          $select.data('originalValue', selectEl.value);
        }
      });
    });

    // Listen for ready event when T&A finishes loading all modules
    document.addEventListener('taReady', function (e) {
      angular.bootstrap(angular.element("[data-ta-documents-manager]"), ['taDocuments']);
    });
  }(CRM.$, CRM));
</script>
