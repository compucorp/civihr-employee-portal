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
  // Exported menu link: hr-reports_leave-reports:reports/leave_and_absence/.
  $menu_links['hr-reports_leave-reports:reports/leave_and_absence/'] = array(
    'menu_name' => 'hr-reports',
    'link_path' => 'reports/leave_and_absence/',
    'router_path' => 'reports/%',
    'link_title' => 'Leave Reports',
    'options' => array(
      'identifier' => 'hr-reports_leave-reports:reports/leave_and_absence/',
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'attributes' => array(
        'title' => 'Create reports showing the analysis of Leave taken for Holiday/Vacation, Sickness, TOIL and other leave types.',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: hr-reports_people-reports:reports/people/.
  $menu_links['hr-reports_people-reports:reports/people/'] = array(
    'menu_name' => 'hr-reports',
    'link_path' => 'reports/people/',
    'router_path' => 'reports/%',
    'link_title' => 'People Reports',
    'options' => array(
      'identifier' => 'hr-reports_people-reports:reports/people/',
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'attributes' => array(
        'title' => 'Create reports showing analysis of Headcount and FTE by Department, Role, Contract Type and other staff data.',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_help://userguide.civihr.org/.
  $menu_links['main-menu_help://userguide.civihr.org/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '//userguide.civihr.org/',
    'router_path' => '',
    'link_title' => 'Help',
    'options' => array(
      'identifier' => 'main-menu_help://userguide.civihr.org/',
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
  // Exported menu link: main-menu_hr-admin:civicrm.
  $menu_links['main-menu_hr-admin:civicrm'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'civicrm',
    'router_path' => 'civicrm',
    'link_title' => 'HR Admin',
    'options' => array(
      'identifier' => 'main-menu_hr-admin:civicrm',
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'attributes' => array(
        'class' => array(
          0 => 'fa',
          1 => 'fa-tachometer',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Age groups');
  t('HR Admin');
  t('HR Resources');
  t('Help');
  t('Home');
  t('Leave Reports');
  t('Manager Leave');
  t('My Details');
  t('My Leave');
  t('People Reports');
  t('Staff Directory');
  t('Tasks');
  t('Vacancies');

  return $menu_links;
}
