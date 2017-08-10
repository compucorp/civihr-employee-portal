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
  0 => t('All'),
  'awaiting-upload' => t('Awaiting upload'),
  'awaiting-approval' => t('Awaiting approval'),
  'approved' => t('Approved'),
  'rejected' => t('Rejected'),
];
$statusesCount = array_combine(array_keys($statuses), array_fill(0, count($statuses), 0));

$targetIds = [];
foreach ($rows as $row):
  if (!isset($row['status_id'])) {
    continue;
  }
  $statusesCount[strtolower(str_replace(' ', '-', $row['status_id']))] ++;
  $statusesCount[0] ++;
  $targetIds[] = CRM_Utils_Array::value('target_contact_id', $row);
endforeach;

$allTargets = civicrm_api3('Contact', 'get', [['id', 'IN', $targetIds]])['values'];
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
              <?php $header = array_merge(['staff' => 'Staff'], $header) ?>
              <?php foreach ($header as $field => $label): ?>
                <th <?php if (!empty($header_classes[$field])) {
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
              $class = 'document-row status-id-' . strtolower(str_replace(' ', '-', $row['status_id'])); ?>
            <tr <?php if ($row_classes[$row_count] || $class) {
                print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';
              } ?>>
                <?php
                $targetID = CRM_Utils_Array::value('target_contact_id', $row);
                $targetDetails = CRM_Utils_Array::value($targetID, $allTargets);
                $targetContactColumn = $targetDetails['display_name'];
                $row = array_merge(['target' => $targetContactColumn], $row);

                // row content
                foreach ($row as $field => $content):
                  $class = '';
                  $attribute = '';
                  $decodeFields = ['document_contacts' || 'document_contacts_1'];
                  if (!empty($field_classes[$field][$row_count])) {
                    $class = sprintf('class = "%s"', $field_classes[$field][$row_count]);
                  }
                  if (!empty($field_attributes[$field][$row_count])) {
                    $attribute = drupal_attributes($field_attributes[$field][$row_count]);
                  }
                  if (in_array($field, $decodeFields)) {
                    $content = strip_tags(html_entity_decode($content));
                  }

                  printf('<td %s %s>%s</td>', $class, $attribute, $content);
                endforeach; ?>
              <td data-ct-spinner data-ct-spinner-id="document-<?php print strip_tags($row['id']); ?>">
                <?php if (strip_tags($row['status_id']) == 3): ?>
                  <button
                    ng-show='!document.loadingModalData'
                    class="btn btn-sm btn-default ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed"
                    disabled>
                    <i class="fa fa-upload"></i> Open
                  </button>
                <?php else: ?>
                  <button
                    ng-show='!document.loadingModalData'
                    ng-click="document.modalDocument(<?php print strip_tags($row['id']); ?> , 'staff')"
                    class="btn btn-sm btn-default">
                    <i class="fa fa-upload"></i> Open
                  </button>
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

    $tableFilters.find('.chr_table-w-filters__filters__nav :first').addClass('active');

    $filtersNav.find('a').bind('click', function (e) {
      e.preventDefault();

      var $this = $(this);

      $filtersNav.find('> li').removeClass('active');
      $this.parent().addClass('active');

      filterTable($this.data('documentStatus'));
    });

    $filtersDropdown.on('change', function (e) {
      filterTable($(this).val());
    });

    // Listen for ready event when T&A finishes loading all modules
    document.addEventListener('taReady', function (e) {
      angular.bootstrap(angular.element("[data-ta-documents]"), ['taDocuments']);
    });



  }(CRM.$));
</script>
