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
 * -@var object $view
 *        The view object
 * -@var object $field
 *        The field handler object that can process the input
 * -@var object $row
 *        The raw SQL result that can be used
 * -@var string $output
 *        The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

 /**
 * This template file prints the image of the user in "My Details" page
 * using the HTML structures implemented in the dashboard
 */
?>

<div class="chr_profile-card">
  <div class="chr_profile-card__picture">
    <?php if ($output != 'no image') { ?>
      <?php print $output ?>
    <?php } else { ?>
      <img
        src="<?php print drupal_get_path('module', 'civihr_employee_portal') . '/images/profile-default.png' ?>"/>
    <?php } ?>
  </div>
</div>
