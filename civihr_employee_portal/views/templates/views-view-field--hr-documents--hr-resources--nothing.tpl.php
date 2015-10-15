<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>

<?php
    $total_count = isset($row->field_field_attachment) ? count($row->field_field_attachment) : t('No attachments');;
    $resource_type = isset($row->field_field_resource_type[0]) ? $row->field_field_resource_type[0]['rendered']['#markup'] : NULL;

    // Get the download link if we have anything to download
    if (isset($row->field_field_download[0])) {
        $download_link = l(
            $row->field_field_download[0]['rendered']['#text'] . " ($total_count)",
            $row->field_field_download[0]['rendered']['#path'],
            array('attributes' => array('class' => 'chr_action--transparent chr_action--icon--download', 'aria-hidden' => 'true'))
        );
    }

    $custom_output = '
        <div class="chr_hr-resource__header col-xs-6 col-sm-3 col-md-2">
            <h3 class="chr_hr-resource__name" id="resource-modal">'
                . civihr_employee_portal_make_link($row->node_title, 'hr-resource', $row->nid) .
            '</h3>
            <span class="chr_hr-resource__type">' . ( $resource_type ? $resource_type : '' ) . '</span>
        </div>
        <div class="clearfix visible-xs-block"></div>
        <div class="chr_hr-resource__description col-sm-6 col-md-7">'
            . ( isset($row->field_field_short_description[0]) ? $row->field_field_short_description[0]['rendered']['#markup'] : '' ) .
        '</div>
    ';

    if (isset($download_link)) {
        $custom_output .= '
            <div class="chr_hr-resource__download col-sm-3">'
                . $download_link .
            '</div>
        ';
    }
?>

<?php print $custom_output; ?>
