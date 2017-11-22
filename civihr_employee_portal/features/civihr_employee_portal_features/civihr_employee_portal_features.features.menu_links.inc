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

  // Exported menu link: hr-reports-settings_age-groups:reports/settings/age_group/.
  $menu_links['hr-reports-settings_age-groups:reports/settings/age_group/'] = array(
    'menu_name' => 'hr-reports-settings',
    'link_path' => 'reports/settings/age_group/',
    'router_path' => 'reports/settings/age_group',
    'link_title' => 'Age groups',
    'options' => array(
      'attributes' => array(),
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
  // Exported menu link: hr-reports_report-1-people:reports/people/.
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
  // Exported menu link: hr-reports_report-2-leave-and-absence:reports/leave_and_absence/.
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
  // Exported menu link: main-menu_civihr-admin:civicrm.
  $menu_links['main-menu_civihr-admin:civicrm'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'civicrm',
    'router_path' => 'civicrm',
    'link_title' => 'HR admin',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-tachometer',
        ),
      ),
      'identifier' => 'main-menu_civihr-admin:civicrm',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'customized' => 1,
  );
  // Exported menu link: main-menu_help://civihr-documentation.readthedocs.io/en/latest/self-service-portal/login-screen/.
  $menu_links['main-menu_help://civihr-documentation.readthedocs.io/en/latest/self-service-portal/login-screen/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '//civihr-documentation.readthedocs.io/en/latest/self-service-portal/login-screen/',
    'router_path' => '',
    'link_title' => 'Help',
    'options' => array(
      'identifier' => 'main-menu_help://civihr-documentation.readthedocs.io/en/latest/self-service-portal/login-screen/',
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(
          1 => 1,
        ),
      ),
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-question-circle',
        ),
        'target' => '_blank',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:dashboard.
  $menu_links['main-menu_home:dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-home',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
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
  // Exported menu link: main-menu_hr-resources:hr-resources.
  $menu_links['main-menu_hr-resources:hr-resources'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'hr-resources',
    'router_path' => 'hr-resources',
    'link_title' => 'HR Resources',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-file-text-o',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_hr-resources:hr-resources',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 1,
  );
  // Exported menu link: main-menu_manager-leave:manager-leave.
  $menu_links['main-menu_manager-leave:manager-leave'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'manager-leave',
    'router_path' => 'manager-leave',
    'link_title' => 'Manager Leave',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-suitcase',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_manager-leave:manager-leave',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 1,
  );
  // Exported menu link: main-menu_my-details:hr-details.
  $menu_links['main-menu_my-details:hr-details'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'hr-details',
    'router_path' => 'hr-details',
    'link_title' => 'My Details',
    'options' => array(
      'identifier' => 'main-menu_my-details:hr-details',
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-user',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: main-menu_my-leave:my-leave.
  $menu_links['main-menu_my-leave:my-leave'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'my-leave',
    'router_path' => 'my-leave',
    'link_title' => 'My Leave',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-calendar',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_my-leave:my-leave',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
  );
  // Exported menu link: main-menu_reports:reports.
  $menu_links['main-menu_reports:reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'reports',
    'router_path' => 'reports',
    'link_title' => 'Reports',
    'options' => array(
      'identifier' => 'main-menu_reports:reports',
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-table',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
  );
  // Exported menu link: main-menu_staff-directory:staff-directory.
  $menu_links['main-menu_staff-directory:staff-directory'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'staff-directory',
    'router_path' => 'staff-directory',
    'link_title' => 'Staff Directory',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-search',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_staff-directory:staff-directory',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: main-menu_tasks:tasks-and-documents.
  $menu_links['main-menu_tasks:tasks-and-documents'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'tasks-and-documents',
    'router_path' => 'tasks-and-documents',
    'link_title' => 'Tasks',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-list-ul',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_tasks:tasks-and-documents',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );
  // Exported menu link: main-menu_vacancies:hr-vacancies.
  $menu_links['main-menu_vacancies:hr-vacancies'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'hr-vacancies',
    'router_path' => 'hr-vacancies',
    'link_title' => 'Vacancies',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-user-plus',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_vacancies:hr-vacancies',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Age groups');
  t('HR admin');
  t('HR Resources');
  t('Help');
  t('Home');
  t('Manager Leave');
  t('My Details');
  t('My Leave');
  t('Report 1: People');
  t('Report 2: Leave and Absence');
  t('Reports');
  t('Staff Directory');
  t('Tasks');
  t('Vacancies');

  return $menu_links;
}
