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
    $total_count = t('No attachments');

    // Get the total count of all attachments
    if (isset($row->field_field_attachment) && !empty($row->field_field_attachment[0]['rendered']['#items'])) {
        $total_count = count($row->field_field_attachment[0]['rendered']['#items']);
    }

    // Get the download link if we have anything to download
    $download_link = isset($row->field_field_download[0])? l(' ' . $row->field_field_download[0]['rendered']['#text'] . ' (' . $total_count . ')', $row->field_field_download[0]['rendered']['#path'], array('attributes' => array('class' => 'chr_action--icon--download', 'aria-hidden' => 'true'))) : '';
    $custom_output = '<div class="row"><div class="col-xs-6 resource-uploaded-date text-left">' . t('Uploaded on: ') . format_date($row->node_created, 'custom', t('d/m/Y', array(), array('context' => 'php date format'))) . '</div><div class="col-xs-6 resource-download-all text-right">' . $download_link . '</div></div>';
?>

<?php print $custom_output; ?>
