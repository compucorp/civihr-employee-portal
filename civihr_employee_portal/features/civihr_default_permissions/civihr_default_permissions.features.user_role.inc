<?php
/**
 * @file
 * civihr_default_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function civihr_default_permissions_user_default_roles() {
  $roles = array();

  // Exported role: civihr_admin.
  $roles['civihr_admin'] = array(
    'name' => 'civihr_admin',
    'weight' => 3,
    'machine_name' => 'civihr_admin',
  );

  // Exported role: civihr_manager.
  $roles['civihr_manager'] = array(
    'name' => 'civihr_manager',
    'weight' => 5,
    'machine_name' => 'civihr_manager',
  );

  // Exported role: civihr_staff.
  $roles['civihr_staff'] = array(
    'name' => 'civihr_staff',
    'weight' => 4,
    'machine_name' => 'civihr_staff',
  );

  return $roles;
}
