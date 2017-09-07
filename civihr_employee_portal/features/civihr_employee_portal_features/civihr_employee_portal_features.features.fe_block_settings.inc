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

  $export['block-signup'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'signup',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['calendar-calendar_legend'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'calendar_legend',
    'module' => 'calendar',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['civicrm-2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 2,
    'module' => 'civicrm',
    'node_types' => array(),
    'pages' => 'civicrm
civicrm/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -99,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -99,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['civicrm-3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 3,
    'module' => 'civicrm',
    'node_types' => array(),
    'pages' => 'civicrm
civicrm/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -98,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -98,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['civicrm-5'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 5,
    'module' => 'civicrm',
    'node_types' => array(),
    'pages' => 'civicrm
civicrm/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -96,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -96,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['civicrm-7'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 7,
    'module' => 'civicrm',
    'node_types' => array(),
    'pages' => 'civicrm
civicrm/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => -94,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -94,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['civihr_employee_portal-absence_links'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'absence_links',
    'module' => 'civihr_employee_portal',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['civihr_employee_portal-leave'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'leave',
    'module' => 'civihr_employee_portal',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['civihr_employee_portal-login_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'login_block',
    'module' => 'civihr_employee_portal',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['civihr_employee_portal-manager_calendar'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'manager_calendar',
    'module' => 'civihr_employee_portal',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['civihr_employee_portal-my_details'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'my_details',
    'module' => 'civihr_employee_portal',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['civihr_employee_portal-sick'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'sick',
    'module' => 'civihr_employee_portal',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['civihr_employee_portal-sickness_links'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'sickness_links',
    'module' => 'civihr_employee_portal',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['civihr_employee_portal-staff_directory_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'staff_directory_block',
    'module' => 'civihr_employee_portal',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['comment-recent'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'recent',
    'module' => 'comment',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['fancy_login-fancy_login_login_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'fancy_login_login_block',
    'module' => 'fancy_login',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['locale-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'module' => 'locale',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['logintoboggan-logintoboggan_logged_in'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'logintoboggan_logged_in',
    'module' => 'logintoboggan',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['masquerade-masquerade'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'masquerade',
    'module' => 'masquerade',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-features'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'features',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-hr-reports'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'hr-reports',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

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

  $export['node-recent'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'recent',
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['node-syndicate'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'syndicate',
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -1,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'help',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'management',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 10,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-new'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'new',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-online'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'online',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views--exp-absence_list-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-absence_list-page',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views--exp-absence_list-page_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-absence_list-page_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-08b3e99980d17d44b1eb73de5c9bd2a7'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '08b3e99980d17d44b1eb73de5c9bd2a7',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-1e6267274b5d19d456da8db2cd22ac5a'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '1e6267274b5d19d456da8db2cd22ac5a',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-3539fdc55d599d00af13d22a80d803ad'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '3539fdc55d599d00af13d22a80d803ad',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-39882a91299a3f1f20f6e438a830f610'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '39882a91299a3f1f20f6e438a830f610',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-7b29f543a637570f0924516a4fa19465'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '7b29f543a637570f0924516a4fa19465',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-9814635ddcc509717746723efa8d6ca1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '9814635ddcc509717746723efa8d6ca1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-Documents-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'Documents-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-Documents-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'Documents-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-Tasks-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'Tasks-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-Tasks-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'Tasks-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-appraisals-appraisals_employee'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'appraisals-appraisals_employee',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-approvals-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'approvals-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-b4e2186316536d3e43a9ca587b7a97e2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'b4e2186316536d3e43a9ca587b7a97e2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-calendar_absence_list-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calendar_absence_list-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-calendar_absence_list-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calendar_absence_list-block_2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-civicrm_my_activities-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'civicrm_my_activities-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-civicrm_my_activities-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'civicrm_my_activities-block_2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-d9463282626b997876303509331c22e0'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'd9463282626b997876303509331c22e0',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-hr_documents-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'hr_documents-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-hr_documents-hr_resources_modal'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'hr_documents-hr_resources_modal',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-hr_resource_types_list-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'hr_resource_types_list-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['webform-client-block-2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'client-block-2',
    'module' => 'webform',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['webform-client-block-3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'client-block-3',
    'module' => 'webform',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'civihr_default_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'civihr_default_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
