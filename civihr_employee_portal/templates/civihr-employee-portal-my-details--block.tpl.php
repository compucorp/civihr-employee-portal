<?php

/**
 * @var string $address_data
 *   The content of the "Contact Information" block
 * @var string $address_data_title
 *   The title of the "Contact Information" block
 * @var string $contact_details
 *   The content of the "My Details" block
 * @var string $emergencyContactsBlock
 *   The rendered content of the emergency contact block
 * @var string $emergencyContactsTitle
 *   The title for the emergency contact block
 * @var string $dependantsBlock
 *   The rendered content of the dependants block
 * @var string $dependantsTitle
 *   The title for the dependants block
 * @var array $title_prefix
 *   An array containing additional output populated by modules, intended to be
 *   displayed in front of the main title tag that appears in the template.
 * @var array $title_suffix
 *   An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * @var string $attributes
 *   Attributes for the block
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 */

global $user; // Show only if we have the logged in user
$actionsClasses = 'ctools-use-modal ctools-modal-civihr-custom-style chr_action--icon--edit';

if (!$user->uid) {
  return '';
}
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="row relative">
    <div class="col-md-2">
      <div class="chr_profile-card hidden-xs hidden-sm">
        <div class="chr_profile-card__picture">
          <?php if (isset($contact_data['image_URL']) && !empty($contact_data['image_URL'])) { ?>
            <img src="<?php print $contact_data['image_URL']; ?>"/>
          <?php } else { ?>
            <img
              src="<?php print drupal_get_path('module', 'civihr_employee_portal') . '/images/profile-default.png' ?>"/>
          <?php } ?>
        </div>
      </div>
    </div>
    <div class="col-md-5 chr_panel--my-details__data-group">
      <h5
        class="chr_panel--my-details__data-group__title"><?php print t('My Details'); ?></h5>
      <div class="chr_panel--my-details__data-group__content">
        <?php print $contact_details; ?>
      </div>
    </div>
    <div class="col-md-offset-7 vertical-splitter hidden-xs hidden-sm"></div>
    <div class="col-md-5 chr_panel--my-details__data-group">
      <h5
        class="chr_panel--my-details__data-group__title"><?php print $address_data_title ?></h5>
      <div class="chr_panel--my-details__data-group__content">
        <?php print $address_data; ?>
      </div>
    </div>
  </div>
  <div class="chr_panel__footer">
    <div class="chr_actions-wrapper">
      <?php print l(t('Edit my details'), 'my_details/nojs/view', array('attributes' => array('class' => $actionsClasses))); ?>
    </div>
  </div>
</div>
