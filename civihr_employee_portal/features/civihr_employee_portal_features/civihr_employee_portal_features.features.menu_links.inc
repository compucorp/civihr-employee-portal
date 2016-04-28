<?php
/**
 * @file
 * civihr_employee_portal_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function civihr_employee_portal_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: hr-reports-settings_age-groups:reports/settings/age_group/
  $menu_links['hr-reports-settings_age-groups:reports/settings/age_group/'] = array(
    'menu_name' => 'hr-reports-settings',
    'link_path' => 'reports/settings/age_group/',
    'router_path' => 'reports/settings/age_group',
    'link_title' => 'Age groups',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'hr-reports-settings_age-groups:reports/settings/age_group/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: hr-reports_report-1-people:reports/people/
  $menu_links['hr-reports_report-1-people:reports/people/'] = array(
    'menu_name' => 'hr-reports',
    'link_path' => 'reports/people/',
    'router_path' => 'reports/%',
    'link_title' => 'Report 1: People',
    'options' => array(
      'attributes' => array(
        'title' => 'CiviHR Report containing Employee, Contract and Role data.',
      ),
      'identifier' => 'hr-reports_report-1-people:reports/people/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: hr-reports_report-2-leave-and-absence:reports/leave_and_absence/
  $menu_links['hr-reports_report-2-leave-and-absence:reports/leave_and_absence/'] = array(
    'menu_name' => 'hr-reports',
    'link_path' => 'reports/leave_and_absence/',
    'router_path' => 'reports/%',
    'link_title' => 'Report 2: Leave and Absence',
    'options' => array(
      'attributes' => array(
        'title' => 'CiviHR Report containing Employee, Contract, Role and Absence Activity data.',
      ),
      'identifier' => 'hr-reports_report-2-leave-and-absence:reports/leave_and_absence/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:dashboard
  $menu_links['main-menu_home:dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_home:dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_reports:reports
  $menu_links['main-menu_reports:reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'reports',
    'router_path' => 'reports',
    'link_title' => 'Reports',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_reports:reports',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Age groups');
  t('Home');
  t('Report 1: People');
  t('Report 2: Leave and Absence');
  t('Reports');


  return $menu_links;
}
