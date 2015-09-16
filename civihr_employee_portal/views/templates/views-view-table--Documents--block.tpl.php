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

$typeResult = civicrm_api3('Activity', 'getoptions', array(
    'field' => "activity_type_id",
));
$types = $typeResult['values'];

/*$statusesResult = civicrm_api3('Document', 'getstatuses', array(
    'sequential' => 1,
));
$statuses = array();
foreach ($statusesResult['values'] as $status):
    $statuses[$status['value']] = $status['label'];
endforeach;*/
$statuses = array(
    0 => 'All',
    1 => 'Awaiting upload',
    2 => 'Awaiting approval',
    3 => 'Approved',
    4 => 'Rejected',
);

$statusesCount = array_combine(array_keys($statuses), array_fill(0, count($statuses), 0));

foreach ($rows as $row):
    $statusesCount[(int)strip_tags($row['status_id'])]++;
    $statusesCount[0]++;
endforeach;

?>
<div class="chr_table-w-filters row">
    <div class="chr_table-w-filters__filters col-md-3">
        <ul id="nav-documents-status" class="nav nav-pills nav-stacked">
<?php $classActive = ' class="active"'; ?>
<?php foreach ($statuses as $key => $value): ?>
            <li<?php print $classActive; ?>><a href data-document-status="<?php print $key; ?>"><?php print $value; ?> <span class="badge pull-right"><?php print $statusesCount[$key]; ?></span></a></li>
<?php $classActive = ''; ?>
<?php endforeach; ?>
        </ul>
    </div>
    <div class="chr_table-w-filters__table-wrapper col-md-9">
        <div class="chr_table-w-filters__table">
            <table id="documents-dashboard-table-staff" <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
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
                                <?php if ($field === 'activity_type_id'):
                                    print $types[strip_tags($content)];
                                    continue;
                                endif;
                                ?>
                                <?php if ($field === 'activity_date_time' && trim(strip_tags($content))):
                                    print date('M d Y', strtotime(strip_tags($content)));
                                    continue;
                                endif; ?>
                                <?php if ($field === 'expire_date' && trim(strip_tags($content))):
                                    print date('M d Y', strtotime(strip_tags($content)));
                                    continue;
                                endif; ?>
                                <?php if ($field === 'status_id'):
                                    print $statuses[strip_tags($content)];
                                    continue;
                                endif; ?>
                                <?php if ($field === 'document_contacts' || $field === 'document_contacts_1'):
                                    print $content;
                                    continue;
                                endif; ?>
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
    (function($){
        var $navDocStatus = $('#nav-documents-status'),
            $tableDocStaff = $('#documents-dashboard-table-staff'),
            $tableDocStaffRows = $tableDocStaff.find('.document-row');

            $navDocStatus.find('a').bind('click', function(e) {
                e.preventDefault();

                var $this = $(this),
                    documentStatus = $this.data('documentStatus');

                $navDocStatus.find('> li').removeClass('active');
                $this.parent().addClass('active');

                if (!documentStatus) {
                    $tableDocStaffRows.show();
                    return
                }

                $tableDocStaffRows.hide();
                $tableDocStaff.find('.status-id-' + documentStatus).show();
        });
    }(CRM.$));
</script>
