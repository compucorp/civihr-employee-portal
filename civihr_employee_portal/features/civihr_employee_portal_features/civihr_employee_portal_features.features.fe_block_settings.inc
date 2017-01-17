<?php
/**
 * @file
 * civihr_employee_portal_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function civihr_employee_portal_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-hr-reports-settings'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'hr-reports-settings',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => 'reports',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 1,
      ),
      'civihr_default_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 1,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 1,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
