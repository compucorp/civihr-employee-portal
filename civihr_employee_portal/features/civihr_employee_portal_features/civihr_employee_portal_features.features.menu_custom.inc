<?php
/**
 * @file
 * civihr_employee_portal_features.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function civihr_employee_portal_features_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: hr-reports.
  $menus['hr-reports'] = array(
    'menu_name' => 'hr-reports',
    'title' => 'Reports',
    'description' => 'CiviHR Reports',
  );
  // Exported menu: hr-reports-settings.
  $menus['hr-reports-settings'] = array(
    'menu_name' => 'hr-reports-settings',
    'title' => 'Reports settings',
    'description' => 'CiviHR Reports settings',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CiviHR Reports');
  t('CiviHR Reports settings');
  t('Reports');
  t('Reports settings');


  return $menus;
}
