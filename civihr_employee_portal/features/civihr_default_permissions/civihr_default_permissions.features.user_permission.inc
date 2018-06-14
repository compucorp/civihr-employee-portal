<?php
/**
 * @file
 * civihr_default_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function civihr_default_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Administer fancy login'.
  $permissions['Administer fancy login'] = array(
    'name' => 'Administer fancy login',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fancy_login',
  );

  // Exported permission: 'access AJAX API'.
  $permissions['access AJAX API'] = array(
    'name' => 'access AJAX API',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviCRM'.
  $permissions['access CiviCRM'] = array(
    'name' => 'access CiviCRM',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviCRM developer menu and tools'.
  $permissions['access CiviCRM developer menu and tools'] = array(
    'name' => 'access CiviCRM developer menu and tools',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviReport'.
  $permissions['access CiviReport'] = array(
    'name' => 'access CiviReport',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Contact Dashboard'.
  $permissions['access Contact Dashboard'] = array(
    'name' => 'access Contact Dashboard',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'access HRJobs'.
  $permissions['access HRJobs'] = array(
    'name' => 'access HRJobs',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access HRReport'.
  $permissions['access HRReport'] = array(
    'name' => 'access HRReport',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Report Criteria'.
  $permissions['access Report Criteria'] = array(
    'name' => 'access Report Criteria',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Tasks and Assignments'.
  $permissions['access Tasks and Assignments'] = array(
    'name' => 'access Tasks and Assignments',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Tasks and Assignments Files'.
  $permissions['access Tasks and Assignments Files'] = array(
    'name' => 'access Tasks and Assignments Files',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Vacancy'.
  $permissions['access Vacancy'] = array(
    'name' => 'access Vacancy',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all cases and activities'.
  $permissions['access all cases and activities'] = array(
    'name' => 'access all cases and activities',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access all custom data'.
  $permissions['access all custom data'] = array(
    'name' => 'access all custom data',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access contact reference fields'.
  $permissions['access contact reference fields'] = array(
    'name' => 'access contact reference fields',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access deleted contacts'.
  $permissions['access deleted contacts'] = array(
    'name' => 'access deleted contacts',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access hrreports'.
  $permissions['access hrreports'] = array(
    'name' => 'access hrreports',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'access leave and absences'.
  $permissions['access leave and absences'] = array(
    'name' => 'access leave and absences',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access leave and absences in ssp'.
  $permissions['access leave and absences in ssp'] = array(
    'name' => 'access leave and absences in ssp',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access my cases and activities'.
  $permissions['access my cases and activities'] = array(
    'name' => 'access my cases and activities',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access own HRJobs'.
  $permissions['access own HRJobs'] = array(
    'name' => 'access own HRJobs',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access root menu items and configurations'.
  $permissions['access root menu items and configurations'] = array(
    'name' => 'access root menu items and configurations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access subpermission form'.
  $permissions['access subpermission form'] = array(
    'name' => 'access subpermission form',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'subpermissions',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access uploaded files'.
  $permissions['access uploaded files'] = array(
    'name' => 'access uploaded files',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access users overview'.
  $permissions['access users overview'] = array(
    'name' => 'access users overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'add cases'.
  $permissions['add cases'] = array(
    'name' => 'add cases',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'add contacts'.
  $permissions['add contacts'] = array(
    'name' => 'add contacts',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer CiviCRM'.
  $permissions['administer CiviCRM'] = array(
    'name' => 'administer CiviCRM',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer CiviCRM Entity'.
  $permissions['administer CiviCRM Entity'] = array(
    'name' => 'administer CiviCRM Entity',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm_entity',
  );

  // Exported permission: 'administer CiviCase'.
  $permissions['administer CiviCase'] = array(
    'name' => 'administer CiviCase',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer Reports'.
  $permissions['administer Reports'] = array(
    'name' => 'administer Reports',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer Tagsets'.
  $permissions['administer Tagsets'] = array(
    'name' => 'administer Tagsets',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer Vacancy'.
  $permissions['administer Vacancy'] = array(
    'name' => 'administer Vacancy',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer browser class'.
  $permissions['administer browser class'] = array(
    'name' => 'administer browser class',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'browserclass',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer dedupe rules'.
  $permissions['administer dedupe rules'] = array(
    'name' => 'administer dedupe rules',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer leave and absences'.
  $permissions['administer leave and absences'] = array(
    'name' => 'administer leave and absences',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer payment processors'.
  $permissions['administer payment processors'] = array(
    'name' => 'administer payment processors',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer private reports'.
  $permissions['administer private reports'] = array(
    'name' => 'administer private reports',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer reserved groups'.
  $permissions['administer reserved groups'] = array(
    'name' => 'administer reserved groups',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer reserved reports'.
  $permissions['administer reserved reports'] = array(
    'name' => 'administer reserved reports',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer reserved tags'.
  $permissions['administer reserved tags'] = array(
    'name' => 'administer reserved tags',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer roles and teams'.
  $permissions['administer roles and teams'] = array(
    'name' => 'administer roles and teams',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer staff accounts'.
  $permissions['administer staff accounts'] = array(
    'name' => 'administer staff accounts',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer subpermission'.
  $permissions['administer subpermission'] = array(
    'name' => 'administer subpermission',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'subpermissions',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer tipsy'.
  $permissions['administer tipsy'] = array(
    'name' => 'administer tipsy',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'tipsy',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer userprotect'.
  $permissions['administer userprotect'] = array(
    'name' => 'administer userprotect',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'assign HR Admin role'.
  $permissions['assign HR Admin role'] = array(
    'name' => 'assign HR Admin role',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Manager role'.
  $permissions['assign Manager role'] = array(
    'name' => 'assign Manager role',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Staff role'.
  $permissions['assign Staff role'] = array(
    'name' => 'assign Staff role',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'can administer calendar feeds'.
  $permissions['can administer calendar feeds'] = array(
    'name' => 'can administer calendar feeds',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'can create and edit tasks'.
  $permissions['can create and edit tasks'] = array(
    'name' => 'can create and edit tasks',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel users with role 17087012'.
  $permissions['cancel users with role 17087012'] = array(
    'name' => 'cancel users with role 17087012',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 2'.
  $permissions['cancel users with role 2'] = array(
    'name' => 'cancel users with role 2',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 55120974'.
  $permissions['cancel users with role 55120974'] = array(
    'name' => 'cancel users with role 55120974',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 57573969'.
  $permissions['cancel users with role 57573969'] = array(
    'name' => 'cancel users with role 57573969',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'change document status'.
  $permissions['change document status'] = array(
    'name' => 'change document status',
    'roles' => array(
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own e-mail'.
  $permissions['change own e-mail'] = array(
    'name' => 'change own e-mail',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'change own openid'.
  $permissions['change own openid'] = array(
    'name' => 'change own openid',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'change own password'.
  $permissions['change own password'] = array(
    'name' => 'change own password',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'civicrm_entity.rules.administer'.
  $permissions['civicrm_entity.rules.administer'] = array(
    'name' => 'civicrm_entity.rules.administer',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm_entity',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create hr_documents content'.
  $permissions['create hr_documents content'] = array(
    'name' => 'create hr_documents content',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create manual batch'.
  $permissions['create manual batch'] = array(
    'name' => 'create manual batch',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create users'.
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'customize welcome wizard'.
  $permissions['customize welcome wizard'] = array(
    'name' => 'customize welcome wizard',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'delete HRJobs'.
  $permissions['delete HRJobs'] = array(
    'name' => 'delete HRJobs',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete Tasks and Documents'.
  $permissions['delete Tasks and Documents'] = array(
    'name' => 'delete Tasks and Documents',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete activities'.
  $permissions['delete activities'] = array(
    'name' => 'delete activities',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete all manual batches'.
  $permissions['delete all manual batches'] = array(
    'name' => 'delete all manual batches',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any hr_documents content'.
  $permissions['delete any hr_documents content'] = array(
    'name' => 'delete any hr_documents content',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete contacts'.
  $permissions['delete contacts'] = array(
    'name' => 'delete contacts',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete in CiviCase'.
  $permissions['delete in CiviCase'] = array(
    'name' => 'delete in CiviCase',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own hr_documents content'.
  $permissions['delete own hr_documents content'] = array(
    'name' => 'delete own hr_documents content',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own manual batches'.
  $permissions['delete own manual batches'] = array(
    'name' => 'delete own manual batches',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in hr_resource_type'.
  $permissions['delete terms in hr_resource_type'] = array(
    'name' => 'delete terms in hr_resource_type',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit HRJobs'.
  $permissions['edit HRJobs'] = array(
    'name' => 'edit HRJobs',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit all contacts'.
  $permissions['edit all contacts'] = array(
    'name' => 'edit all contacts',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit all manual batches'.
  $permissions['edit all manual batches'] = array(
    'name' => 'edit all manual batches',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any hr_documents content'.
  $permissions['edit any hr_documents content'] = array(
    'name' => 'edit any hr_documents content',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit api keys'.
  $permissions['edit api keys'] = array(
    'name' => 'edit api keys',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit groups'.
  $permissions['edit groups'] = array(
    'name' => 'edit groups',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit message templates'.
  $permissions['edit message templates'] = array(
    'name' => 'edit message templates',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit mimemail user settings'.
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'edit my contact'.
  $permissions['edit my contact'] = array(
    'name' => 'edit my contact',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit own account'.
  $permissions['edit own account'] = array(
    'name' => 'edit own account',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'edit own api keys'.
  $permissions['edit own api keys'] = array(
    'name' => 'edit own api keys',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own hr_documents content'.
  $permissions['edit own hr_documents content'] = array(
    'name' => 'edit own hr_documents content',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own manual batches'.
  $permissions['edit own manual batches'] = array(
    'name' => 'edit own manual batches',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in hr_resource_type'.
  $permissions['edit terms in hr_resource_type'] = array(
    'name' => 'edit terms in hr_resource_type',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit users with role 17087012'.
  $permissions['edit users with role 17087012'] = array(
    'name' => 'edit users with role 17087012',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 2'.
  $permissions['edit users with role 2'] = array(
    'name' => 'edit users with role 2',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 55120974'.
  $permissions['edit users with role 55120974'] = array(
    'name' => 'edit users with role 55120974',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 57573969'.
  $permissions['edit users with role 57573969'] = array(
    'name' => 'edit users with role 57573969',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'evaluate Applicants'.
  $permissions['evaluate Applicants'] = array(
    'name' => 'evaluate Applicants',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'export all manual batches'.
  $permissions['export all manual batches'] = array(
    'name' => 'export all manual batches',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'export nodes'.
  $permissions['export nodes'] = array(
    'name' => 'export nodes',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'export own manual batches'.
  $permissions['export own manual batches'] = array(
    'name' => 'export own manual batches',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'export own nodes'.
  $permissions['export own nodes'] = array(
    'name' => 'export own nodes',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'force merge duplicate contacts'.
  $permissions['force merge duplicate contacts'] = array(
    'name' => 'force merge duplicate contacts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import contacts'.
  $permissions['import contacts'] = array(
    'name' => 'import contacts',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'manage Applicants'.
  $permissions['manage Applicants'] = array(
    'name' => 'manage Applicants',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage hrreports configuration'.
  $permissions['manage hrreports configuration'] = array(
    'name' => 'manage hrreports configuration',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'manage hrreports settings'.
  $permissions['manage hrreports settings'] = array(
    'name' => 'manage hrreports settings',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'manage leave and absences in ssp'.
  $permissions['manage leave and absences in ssp'] = array(
    'name' => 'manage leave and absences in ssp',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'merge duplicate contacts'.
  $permissions['merge duplicate contacts'] = array(
    'name' => 'merge duplicate contacts',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'profile create'.
  $permissions['profile create'] = array(
    'name' => 'profile create',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile edit'.
  $permissions['profile edit'] = array(
    'name' => 'profile edit',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile listings'.
  $permissions['profile listings'] = array(
    'name' => 'profile listings',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile listings and forms'.
  $permissions['profile listings and forms'] = array(
    'name' => 'profile listings and forms',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile view'.
  $permissions['profile view'] = array(
    'name' => 'profile view',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'see download link'.
  $permissions['see download link'] = array(
    'name' => 'see download link',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'download',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'send arbitrary files'.
  $permissions['send arbitrary files'] = array(
    'name' => 'send arbitrary files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'skip IDS check'.
  $permissions['skip IDS check'] = array(
    'name' => 'skip IDS check',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'translate CiviCRM'.
  $permissions['translate CiviCRM'] = array(
    'name' => 'translate CiviCRM',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'use PHP to import nodes'.
  $permissions['use PHP to import nodes'] = array(
    'name' => 'use PHP to import nodes',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node_export',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view Applicants'.
  $permissions['view Applicants'] = array(
    'name' => 'view Applicants',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all activities'.
  $permissions['view all activities'] = array(
    'name' => 'view all activities',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all contacts'.
  $permissions['view all contacts'] = array(
    'name' => 'view all contacts',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all manual batches'.
  $permissions['view all manual batches'] = array(
    'name' => 'view all manual batches',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all notes'.
  $permissions['view all notes'] = array(
    'name' => 'view all notes',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view appraisals'.
  $permissions['view appraisals'] = array(
    'name' => 'view appraisals',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view debug output'.
  $permissions['view debug output'] = array(
    'name' => 'view debug output',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view hr resources'.
  $permissions['view hr resources'] = array(
    'name' => 'view hr resources',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view my contact'.
  $permissions['view my contact'] = array(
    'name' => 'view my contact',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view my details'.
  $permissions['view my details'] = array(
    'name' => 'view my details',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view my invoices'.
  $permissions['view my invoices'] = array(
    'name' => 'view my invoices',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'view my tasks and documents blocks'.
  $permissions['view my tasks and documents blocks'] = array(
    'name' => 'view my tasks and documents blocks',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view own manual batches'.
  $permissions['view own manual batches'] = array(
    'name' => 'view own manual batches',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view report sql'.
  $permissions['view report sql'] = array(
    'name' => 'view report sql',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view staff directory'.
  $permissions['view staff directory'] = array(
    'name' => 'view staff directory',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view system status on footer'.
  $permissions['view system status on footer'] = array(
    'name' => 'view system status on footer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Regional HR Admin' => 'Regional HR Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view vacancies'.
  $permissions['view vacancies'] = array(
    'name' => 'view vacancies',
    'roles' => array(
      'HR Admin' => 'HR Admin',
      'Manager' => 'Manager',
      'Regional HR Admin' => 'Regional HR Admin',
      'Staff' => 'Staff',
      'administrator' => 'administrator',
    ),
    'module' => 'civihr_employee_portal',
  );

  return $permissions;
}
