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
// loading required resources
civicrm_resources_load('org.civicrm.reqangular', ['reqangular.min.js']);

$statuses = array(
  0 => t('All'),
  'awaiting-upload' => t('Awaiting upload'),
  'awaiting-approval' => t('Awaiting approval'),
  'approved' => t('Approved'),
  'rejected' => t('Rejected'),
);
$statusesCount = array_combine(array_keys($statuses), array_fill(0, count($statuses), 0));

foreach ($rows as $row):
  if (!isset($row['status_id'])) {
    continue;
  }
  $statusesCount[strtolower(str_replace(' ', '-', $row['status_id']))] ++;
  $statusesCount[0] ++;
endforeach;
?>
<div class="chr_table-w-filters chr_table-w-filters--documents row">
  <div class="chr_table-w-filters__filters col-md-3">
    <div class="chr_table-w-filters__filters__dropdown-wrapper">
      <div class="chr_custom-select chr_custom-select--full">
        <select class="chr_table-w-filters__filters__dropdown skip-js-custom-select">
<?php foreach ($statuses as $key => $value): ?>
            <option value="<?php print $key; ?>"><?php print $value; ?> (<?php print $statusesCount[$key]; ?>)</option>
          <?php endforeach; ?>
        </select>
      </div>
    </div>
    <ul class="chr_table-w-filters__filters__nav">
<?php $classActive = ' class="active"'; ?>
<?php foreach ($statuses as $key => $value): ?>
        <li<?php print $classActive; ?>><a href data-document-status="<?php print $key; ?>"><?php print $value; ?> <span class="badge badge-primary pull-right"><?php print $statusesCount[$key]; ?></span></a></li>
        <?php $classActive = ''; ?>
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
              $class = 'document-row status-id-' . strtolower(str_replace(' ', '-', $row['status_id'])); ?>
            <tr <?php if ($row_classes[$row_count] || $class) {
                print 'class="' . implode(' ', $row_classes[$row_count]) . ' ' . $class . '"';
              } ?>>
                <?php foreach ($row as $field => $content): ?>
                <td <?php if ($field_classes[$field][$row_count]) {
                print 'class="' . $field_classes[$field][$row_count] . '" ';
              } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                <?php
                if ($field === 'document_contacts' || $field === 'document_contacts_1'):
                  print strip_tags(html_entity_decode($content));
                  continue;
                endif;
                ?>
    <?php print $content; ?>
                </td>
                <?php endforeach; ?>
              <td>
  <?php if (strip_tags($row['status_id']) == 3): ?>
                  <button
                    class="btn btn-sm btn-default ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed"
                    disabled="disabled">
                    <i class="fa fa-upload"></i> Upload
                  </button>
  <?php else: ?>
                  <a
                    href="/civi_documents/nojs/edit/<?php print strip_tags($row['id']); ?>"
                    class="btn btn-sm btn-default ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">
                    <i class="fa fa-upload"></i> Upload
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

    function filterTable(statusId) {
      if (parseInt(statusId, 10) === 0) {
        $tableDocStaffRows.show();
        return;
      }

      $tableDocStaffRows.hide();
      $tableDocStaff.find('.status-id-' + statusId).show();
    }

    var $tableFilters = $('.chr_table-w-filters--documents'),
            $filtersDropdown = $tableFilters.find('.chr_table-w-filters__filters__dropdown'),
            $filtersNav = $tableFilters.find('.chr_table-w-filters__filters__nav'),
            $tableDocStaff = $tableFilters.find('.chr_table-w-filters__table'),
            $tableDocStaffRows = $tableDocStaff.find('.document-row');

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

    // Trigger event to trigger appDocuments forom T&A
    function taInit() {
      var detail = {
        'app': 'appDocuments',
        'module': 'tnadocuments'
      };

      document.dispatchEvent(typeof window.CustomEvent == "function" ? new CustomEvent('taInit', {
        'detail': detail
      }) : (function(){
        var e = document.createEvent('CustomEvent');
        e.initCustomEvent('taInit', true, true, detail);
        return e;
      })());
    };

    taInit();

    document.addEventListener('taReady', function(){
      taInit();
    });
  }(CRM.$));
</script>

<script src="<?php echo getModuleUrl('uk.co.compucorp.civicrm.tasksassignments').'js/dist/tasks-assignments.min.js';?>"></script>
