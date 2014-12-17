<?php
/**
 * @file
 * civihr_employee_portal_features.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function civihr_employee_portal_features_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'det_tab';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Details tab';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'webform_delta_client-block-2',
      'hide_title' => 1,
      'title' => 'My details',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'webform_delta_client-block-3',
      'hide_title' => 1,
      'title' => 'Emergency contact',
      'weight' => '-99',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Excel';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Details tab');
  t('Emergency contact');
  t('My details');

  $export['det_tab'] = $quicktabs;

  return $export;
}
