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

$profile_image = $row->civicrm_contact_image_url ? $row->civicrm_contact_image_url : drupal_get_path('module', 'civihr_employee_portal') . '/images/profile-default.png';
?>
<div class="chr_profile-card">
    <div class="chr_profile-card__picture chr_profile-card__picture--small">
        <img src="<?php print $profile_image; ?>" />
    </div>
    <div class="chr_profile-card__name">
        <?php
            $fullName = $row->civicrm_contact_first_name . " " . $row->civicrm_contact_last_name;
            print $fullName;
        ?>
    </div>
</div>
