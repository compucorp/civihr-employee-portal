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

  // Exported role: HR Admin.
  $roles['HR Admin'] = array(
    'name' => 'HR Admin',
    'weight' => 3,
    'machine_name' => 'civihr_admin',
  );

  // Exported role: Manager.
  $roles['Manager'] = array(
    'name' => 'Manager',
    'weight' => 5,
    'machine_name' => 'civihr_manager',
  );

  // Exported role: Regional HR Admin.
  $roles['Regional HR Admin'] = array(
    'name' => 'Regional HR Admin',
    'weight' => 6,
    'machine_name' => 'civihr_admin_local',
  );

  // Exported role: Staff.
  $roles['Staff'] = array(
    'name' => 'Staff',
    'weight' => 4,
    'machine_name' => 'civihr_staff',
  );

  return $roles;
}
