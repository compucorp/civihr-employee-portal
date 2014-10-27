<?php
/**
 * @file
 * civihr_employee_portal_features.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function civihr_employee_portal_features_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'calendar_legend_view_calendar_legend';
  $strongarm->value = 'calendar_absence_list:page_1';
  $export['calendar_legend_view_calendar_legend'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_version';
  $strongarm->value = '1.8';
  $export['jquery_update_jquery_version'] = $strongarm;

  return $export;
}
