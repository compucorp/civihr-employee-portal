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
 * -@var object $view: The view object
 * -@var object $field: The field handler object that can process the input
 * -@var object $row: The raw SQL result that can be used
 * -@var string $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 *
 *
 * Prints SSN aplication or SSN aplication status
 * if application status is "not applying" it does not print anything if the
 * SSN number is empty
 * if application status is currently appliying it prints "application in progress"
 */
?>

<?php if (!$row->civicrm_value_inline_custom_data_14_ni_ssn_application_in_pr): ?>
  <?php if ($row->civicrm_value_inline_custom_data_14_ni_ssn_70): ?>
    <?php print $output; ?>
  <?php endif; ?>
<?php else: ?>
  <div class="chr_panel--my-details__personal__application_status--in-progress">
    <span class="views-label">NI/SSN </span>
    <span class="value">Application in progress</span>
  </div>
<?php endif ?>
