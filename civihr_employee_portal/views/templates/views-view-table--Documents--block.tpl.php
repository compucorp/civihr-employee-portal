<?php
/**
 * @file
 * Template to display a view as a table.
 *
 * @var string $title
 *   The title of this group of rows.  May be empty.
 * @var array $header
 *   An array of header labels keyed by field id.
 * @var string $caption
 *   The caption for this table. May be empty.
 * @var array $header_classes
 *   An array of header classes keyed by field id.
 * @var array $fields
 *   An array of CSS IDs to use for each field id.
 * @var string $classes
 *   A class or classes to apply to the table, based on settings.
 * @var array $row_classes
 *   An array of classes to apply to each row, indexed by row number.
 * @var array $rows
 *   An array of row items. Each row is an array of content. $rows are keyed by
 *   row number, fields within rows are keyed by field ID.
 * @var array $field_classes
 *   An array of classes to apply to each field, indexed by field id, then row.
 * @var array $field_attributes
 *   Array of arrays of attributes indexed by field id and then row.
 * @var string $attributes
 *   Empty
 *
 * @ingroup views_templates
 */
$statuses = [
  'awaiting-upload' => t('Awaiting upload'),
  'awaiting-approval' => t('Awaiting approval'),
  'approved' => t('Approved'),
  'rejected' => t('Rejected'),
  0 => t('All'),
];
$statusesCount = array_combine(array_keys($statuses), array_fill(0, count($statuses), 0));

$documentIds = [];
foreach ($rows as $row):
  if (!isset($row['status_id'])) {
    continue;
  }
  $statusesCount[strtolower(str_replace(' ', '-', $row['status_id']))] ++;
  $statusesCount[0] ++;
  $documentIds[] = $row['id'];
endforeach;

// used to decide whether to show download button
$documentFileCount = [];
if (!empty($documentIds)) {
  $documentFileCount = civicrm_api3('Document', 'get', ['id' => ['IN' => $documentIds]]);
  $documentFileCount = array_column($documentFileCount['values'], 'file_count', 'id');
}
?>

<base href="/"> <!-- This is required to remove # for the URL-->
<div data-ta-documents ng-controller="ModalController as document" class="chr_table-w-filters chr_table-w-filters--documents row">
  <div class="chr_table-w-filters__filters col-md-3">
    <ul class="chr_table-w-filters__filters__nav">
      <?php foreach ($statuses as $key => $value): ?>
        <li>
          <a href data-document-status="<?php print $key; ?>">
            <?php print $value; ?>
            <span class="badge badge-primary pull-right">
              <?php print $statusesCount[$key]; ?>
            </span>
          </a>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>

  <div class="chr_table-w-filters__table-wrapper col-md-9">
    <div class="chr_table-w-filters__table">
      <table id="documents-dashboard-table-staff" <?php if ($classes) {
        print 'class="' . $classes . '" ';
      } ?><?php print $attributes; ?>>
        <?php if (!empty($title) || !empty($caption)) : ?>
          <caption><?php print $caption . $title; ?></caption>
        <?php endif; ?>
        <?php if (!empty($header)) : ?>
          <thead>
            <tr>
              <?php foreach ($header as $field => $label): ?>
                <th <?php if (!empty($header_classes[$field])) {
                  print 'class="' . $header_classes[$field] . '" ';
                } ?>>
                <?php
                // This is in angular scope and html5 mode is enabled, so
                // need to set target or sort links will not work
                if (strpos($label, '<a href') !== FALSE) {
                  $label = str_replace('<a href', '<a target="_self" href', $label);
                }
                print $label;
                ?>
                </th>
                <?php endforeach; ?>
              <th></th>
            </tr>
          </thead>
          <?php endif; ?>
        <tbody>
          <?php foreach ($rows as $row_count => $row):
            $rowID = strip_tags(CRM_Utils_Array::value('id', $row));
            if (!$rowID) {
              printf('<tr class = "document-row no-results"><td colspan="4">%s</td></tr>', $row[0]);
              continue;
            }
            $class = 'document-row status-id-' . strtolower(str_replace(' ', '-', $row['status_id'])); ?>
            <tr <?php if ($row_classes[$row_count] || $class) {
                print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';
              } ?>>
                <?php
                foreach ($row as $field => $content):
                  $class = '';
                  $attribute = '';
                  if (!empty($field_classes[$field][$row_count])) {
                    $class = sprintf('class = "%s"', $field_classes[$field][$row_count]);
                  }
                  if (!empty($field_attributes[$field][$row_count])) {
                    $attribute = drupal_attributes($field_attributes[$field][$row_count]);
                  }

                  printf('<td %s %s>%s</td>', $class, $attribute, $content);
                endforeach; ?>
              <td data-ct-spinner data-ct-spinner-id="document-<?php print $rowID; ?>">
                <?php if ($row['status_id'] === 'awaiting upload'): ?>
                  <button
                    ng-show='!document.loadingModalData'
                    <?php printf('ng-click="document.modalDocument(%s , \'staff\')"', $rowID); ?>
                    class="btn btn-sm btn-default">
                    <i class="fa fa-upload"></i>
                    Upload
                  </button>
                <?php else: ?>
                  <button
                    ng-show='!document.loadingModalData'
                    <?php printf('ng-click="document.modalDocument(%d , \'staff\')"', $rowID); ?>
                    class="btn btn-sm btn-default">
                    <i class="fa fa-eye"></i>
                    View
                  </button>
                  <?php $showDownload = CRM_Utils_Array::value($rowID, $documentFileCount, 0) > 0 ? 'true' : 'false'; ?>
                  <a class="btn btn-sm btn-default"
                    <?php printf("ng-show='!document.loadingModalData && %s'", $showDownload); ?>
                    target="_blank"
                    ng-href="/civicrm/tasksassignments/file/zip?entityID=<?php print $rowID; ?>&entityTable=civicrm_activity"
                  >
                    <i class="fa fa-download"></i>
                    Download
                  </a>
                <?php endif; ?>
              </td>
            </tr>
          <?php endforeach; ?>
        </tbody>
      </table>
    </div>
  </div>
</div>

<script>
  (function ($) {
    'use strict';

    CRM.contactId = Drupal.settings.contactId;
    CRM.adminId = Drupal.settings.adminId;
    CRM.tasksAssignments = Drupal.settings.tasksAssignments;
    CRM.debug = Drupal.settings.tasksAssignments.debug;

    function filterTable(statusId) {
      if (parseInt(statusId, 10) === 0) {
        $tableDocStaffRows.show();
        return;
      }

      $tableDocStaffRows.hide();
      $tableDocStaff.find('.status-id-' + statusId).show();
    }

    var $tableFilters = $('.chr_table-w-filters--documents');
    var $filtersDropdown = $tableFilters.find('.chr_table-w-filters__filters__dropdown');
    var $filtersNav = $tableFilters.find('.chr_table-w-filters__filters__nav');
    var $tableDocStaff = $tableFilters.find('.chr_table-w-filters__table');
    var $tableDocStaffRows = $tableDocStaff.find('.document-row');


    $filtersNav.find('a').bind('click', function (e) {
      e.preventDefault();

      var $this = $(this);

      $filtersNav.find('> li').removeClass('active');
      $this.parent().addClass('active');

      filterTable($this.data('documentStatus'));
    });

    $filtersDropdown.on('change', function () {
      filterTable($(this).val());
    });

    // Listen for ready event when T&A finishes loading all modules
    document.addEventListener('taReady', function () {
      angular.bootstrap(angular.element("[data-ta-documents]"), ['taDocuments']);
      // select first filter as default
      $tableFilters.find('.chr_table-w-filters__filters__nav :first a').click();
    });

  }(CRM.$));
</script>

<script src="<?php echo getModuleUrl('uk.co.compucorp.civicrm.tasksassignments').'js/dist/tasks-assignments.min.js';?>"></script>
