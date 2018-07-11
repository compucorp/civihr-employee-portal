<?php
/**
 * @file
 * civihr_employee_portal_features.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function civihr_employee_portal_features_filter_default_formats() {
  $formats = array();

  // Exported format: HTML without filters.
  $formats['html_without_filters'] = array(
    'format' => 'html_without_filters',
    'name' => 'HTML without filters',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
