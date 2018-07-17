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
?>

<div class="container">
  <div class="row">
    <div class="col-md-6" >
      <?php print $field->last_tokens['[name_80]'] ?>
      <?php print $field->last_tokens['[mobile_number_91]'] ?>
      <?php print $field->last_tokens['[phone_number_81]'] ?>
    </div>
    <div class="col-md-6 emergency-address" >
      <div class="views-field">
      <div class="views-label">Address</div>
      <div class="field-content">
        <?php print $field->last_tokens['[street_address_93]'] ?>
        <?php print $field->last_tokens['[street_address_line_2_94]'] ?>
        <?php print $field->last_tokens['[province_97]'] ?>
        <p><?php print $field->last_tokens['[country_98]'] ?></p>
        <?php print $field->last_tokens['[postal_code_96]'] ?>
      </div>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="col-md-6" >
      <div class="views-field">
        <div class="views-label">Relationship</div>
        <div class="field-content"><?php print $field->last_tokens['[relationship_with_employee_83]'] ?></div>
      </div>
    </div>
    <div class="col-md-6" >
      <div class="views-field">
        <div class="views-label">Primary email</div>
        <div class="field-content"><?php print $field->last_tokens['[email_82]'] ?></div>
      </div>
    </div>
  </div>
</div>
