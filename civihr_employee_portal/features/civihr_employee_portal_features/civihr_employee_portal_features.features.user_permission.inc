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

  // Exported permission: 'access manager approval screen'.
  $permissions['access manager approval screen'] = array(
    'name' => 'access manager approval screen',
    'roles' => array(
      'civihr_manager' => 'civihr_manager',
    ),
    'module' => 'civihr_employee_portal',
  );

  return $permissions;
}
