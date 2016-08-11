<?php
/**
 * @file
 * civihr_employee_portal_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function civihr_employee_portal_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access AJAX API'.
  $permissions['access AJAX API'] = array(
    'name' => 'access AJAX API',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviCRM'.
  $permissions['access CiviCRM'] = array(
    'name' => 'access CiviCRM',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access CiviReport'.
  $permissions['access CiviReport'] = array(
    'name' => 'access CiviReport',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Contact Dashboard'.
  $permissions['access Contact Dashboard'] = array(
    'name' => 'access Contact Dashboard',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access HRJobs'.
  $permissions['access HRJobs'] = array(
    'name' => 'access HRJobs',
    'roles' => array(
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access HRReport'.
  $permissions['access HRReport'] = array(
    'name' => 'access HRReport',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Report Criteria'.
  $permissions['access Report Criteria'] = array(
    'name' => 'access Report Criteria',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access Vacancy'.
  $permissions['access Vacancy'] = array(
    'name' => 'access Vacancy',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'access all cases and activities'.
  $permissions['access all cases and activities'] = array(
    'name' => 'access all cases and activities',
    'roles' => array(
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access all custom data'.
  $permissions['access all custom data'] = array(
    'name' => 'access all custom data',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access contact reference fields'.
  $permissions['access contact reference fields'] = array(
    'name' => 'access contact reference fields',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access deleted contacts'.
  $permissions['access deleted contacts'] = array(
    'name' => 'access deleted contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access hrreports'.
  $permissions['access hrreports'] = array(
    'name' => 'access hrreports',
    'roles' => array(),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'access manager approval screen'.
  $permissions['access manager approval screen'] = array(
    'name' => 'access manager approval screen',
    'roles' => array(
      'civihr_manager' => 'civihr_manager',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'access my cases and activities'.
  $permissions['access my cases and activities'] = array(
    'name' => 'access my cases and activities',
    'roles' => array(
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'access own HRJobs'.
  $permissions['access own HRJobs'] = array(
    'name' => 'access own HRJobs',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'access private file download'.
  $permissions['access private file download'] = array(
    'name' => 'access private file download',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'access uploaded files'.
  $permissions['access uploaded files'] = array(
    'name' => 'access uploaded files',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'add cases'.
  $permissions['add cases'] = array(
    'name' => 'add cases',
    'roles' => array(
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'add contacts'.
  $permissions['add contacts'] = array(
    'name' => 'add contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer CiviCRM'.
  $permissions['administer CiviCRM'] = array(
    'name' => 'administer CiviCRM',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer CiviCase'.
  $permissions['administer CiviCase'] = array(
    'name' => 'administer CiviCase',
    'roles' => array(
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer Reports'.
  $permissions['administer Reports'] = array(
    'name' => 'administer Reports',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer Tagsets'.
  $permissions['administer Tagsets'] = array(
    'name' => 'administer Tagsets',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer Vacancy'.
  $permissions['administer Vacancy'] = array(
    'name' => 'administer Vacancy',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer dedupe rules'.
  $permissions['administer dedupe rules'] = array(
    'name' => 'administer dedupe rules',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer payment processors'.
  $permissions['administer payment processors'] = array(
    'name' => 'administer payment processors',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer reserved groups'.
  $permissions['administer reserved groups'] = array(
    'name' => 'administer reserved groups',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer reserved reports'.
  $permissions['administer reserved reports'] = array(
    'name' => 'administer reserved reports',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer reserved tags'.
  $permissions['administer reserved tags'] = array(
    'name' => 'administer reserved tags',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'create manual batch'.
  $permissions['create manual batch'] = array(
    'name' => 'create manual batch',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete HRJobs'.
  $permissions['delete HRJobs'] = array(
    'name' => 'delete HRJobs',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete activities'.
  $permissions['delete activities'] = array(
    'name' => 'delete activities',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete all manual batches'.
  $permissions['delete all manual batches'] = array(
    'name' => 'delete all manual batches',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete contacts'.
  $permissions['delete contacts'] = array(
    'name' => 'delete contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete in CiviCase'.
  $permissions['delete in CiviCase'] = array(
    'name' => 'delete in CiviCase',
    'roles' => array(
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'delete own manual batches'.
  $permissions['delete own manual batches'] = array(
    'name' => 'delete own manual batches',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit HRAbsences'.
  $permissions['edit HRAbsences'] = array(
    'name' => 'edit HRAbsences',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit HRJobs'.
  $permissions['edit HRJobs'] = array(
    'name' => 'edit HRJobs',
    'roles' => array(
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit all contacts'.
  $permissions['edit all contacts'] = array(
    'name' => 'edit all contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit all manual batches'.
  $permissions['edit all manual batches'] = array(
    'name' => 'edit all manual batches',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit groups'.
  $permissions['edit groups'] = array(
    'name' => 'edit groups',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit my contact'.
  $permissions['edit my contact'] = array(
    'name' => 'edit my contact',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'edit own manual batches'.
  $permissions['edit own manual batches'] = array(
    'name' => 'edit own manual batches',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'evaluate Applicants'.
  $permissions['evaluate Applicants'] = array(
    'name' => 'evaluate Applicants',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'export all manual batches'.
  $permissions['export all manual batches'] = array(
    'name' => 'export all manual batches',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'export own manual batches'.
  $permissions['export own manual batches'] = array(
    'name' => 'export own manual batches',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'import contacts'.
  $permissions['import contacts'] = array(
    'name' => 'import contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'manage Applicants'.
  $permissions['manage Applicants'] = array(
    'name' => 'manage Applicants',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'manage hrreports settings'.
  $permissions['manage hrreports settings'] = array(
    'name' => 'manage hrreports settings',
    'roles' => array(),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'manage own HRAbsences'.
  $permissions['manage own HRAbsences'] = array(
    'name' => 'manage own HRAbsences',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'merge duplicate contacts'.
  $permissions['merge duplicate contacts'] = array(
    'name' => 'merge duplicate contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile create'.
  $permissions['profile create'] = array(
    'name' => 'profile create',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile edit'.
  $permissions['profile edit'] = array(
    'name' => 'profile edit',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile listings'.
  $permissions['profile listings'] = array(
    'name' => 'profile listings',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile listings and forms'.
  $permissions['profile listings and forms'] = array(
    'name' => 'profile listings and forms',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'profile view'.
  $permissions['profile view'] = array(
    'name' => 'profile view',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'see download link'.
  $permissions['see download link'] = array(
    'name' => 'see download link',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'download',
  );

  // Exported permission: 'translate CiviCRM'.
  $permissions['translate CiviCRM'] = array(
    'name' => 'translate CiviCRM',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view Applicants'.
  $permissions['view Applicants'] = array(
    'name' => 'view Applicants',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'view HRAbsences'.
  $permissions['view HRAbsences'] = array(
    'name' => 'view HRAbsences',
    'roles' => array(),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all activities'.
  $permissions['view all activities'] = array(
    'name' => 'view all activities',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all contacts'.
  $permissions['view all contacts'] = array(
    'name' => 'view all contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all manual batches'.
  $permissions['view all manual batches'] = array(
    'name' => 'view all manual batches',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view all notes'.
  $permissions['view all notes'] = array(
    'name' => 'view all notes',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view my contact'.
  $permissions['view my contact'] = array(
    'name' => 'view my contact',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view own manual batches'.
  $permissions['view own manual batches'] = array(
    'name' => 'view own manual batches',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'administer roles and teams'.
  $permissions['administer roles and teams'] = array(
    'name' => 'administer roles and teams',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
    ),
    'module' => 'civicrm',
  );

  // Exported permission: 'view my details'.
  $permissions['view my details'] = array(
    'name' => 'view my details',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view my tasks block'.
  $permissions['view my tasks block'] = array(
    'name' => 'view my tasks block',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view appraisals'.
  $permissions['view appraisals'] = array(
    'name' => 'view appraisals',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view my leave block'.
  $permissions['view my leave block'] = array(
    'name' => 'view my leave block',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view my sickness report block'.
  $permissions['view my sickness report block'] = array(
    'name' => 'view my sickness report block',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view staff directory'.
  $permissions['view staff directory'] = array(
    'name' => 'view staff directory',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view hr resources'.
  $permissions['view hr resources'] = array(
    'name' => 'view hr resources',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civihr_employee_portal',
  );

  // Exported permission: 'view vacancies'.
  $permissions['view vacancies'] = array(
    'name' => 'view vacancies',
    'roles' => array(
      'administrator' => 'administrator',
      'civihr_admin' => 'civihr_admin',
      'civihr_manager' => 'civihr_manager',
      'civihr_staff' => 'civihr_staff',
    ),
    'module' => 'civihr_employee_portal',
  );

  return $permissions;
}
