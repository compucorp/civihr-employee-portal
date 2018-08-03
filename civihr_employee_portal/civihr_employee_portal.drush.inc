<?php

use Drupal\civihr_employee_portal\Helpers\HelperClass;
use Drupal\civihr_employee_portal\Helpers\NodeHelper;

/**
 * Implements hook_drush_help().
 *
 * @param string $command
 *
 * @return string
 */
function civihr_employee_portal_drush_help($command) {
  switch ($command) {
    case 'drush:refresh-node-export-files':
      return dt('Refreshes the node webform files');
    case 'drush:civihr-blocks-cleanup':
      return dt('Hides the blocks not used for CiviHR employee portal');
    case 'drush:update-external-ids':
      return dt('Sets usernames into external IDs');
    case 'drush:update-email-type':
      return dt('Sets primary email type to "Work" for existing users');
    default:
      return '';
  }
}

/**
 * Implements hook_drush_command().
 */
function civihr_employee_portal_drush_command() {
  $items = [];

  $items['refresh-node-export-files'] = [
    'description' => dt('Refresh Webform node export files.'),
    'arguments' => [],
    'examples' => [
      'Standard example' => 'drush refresh-node-export-files',
    ],
    'aliases' => ['rnef'],
  ];

  $items['civihr-blocks-cleanup'] = [
    'description' => dt('Hides the blocks not used for CiviHR employee portal.'),
    'arguments' => [],
    'examples' => [
      'Standard example' => 'drush civihr-blocks-cleanup',
    ],
    'aliases' => ['civihrbc'],
  ];

  $items['update-external-ids'] = [
    'description' => dt('Sets usernames into external IDs'),
    'arguments' => [],
    'examples' => [
      'Standard example' => 'drush update-external-ids',
    ],
    'aliases' => ['drush-ueids'],
  ];

  $items['update-email-type'] = [
    'description' => dt('Sets primary email type to "Work" for existing users'),
    'arguments' => [],
    'examples' => [
      'Standard example' => 'drush update-email-type',
    ],
    'aliases' => ['drush-uetype'],
  ];

  return $items;
}

/**
 * Callback function for 'drush refresh-node-export-files'
 *
 * Takes all files in the features/node_export_files and refreshes them.
 */
function drush_civihr_employee_portal_refresh_node_export_files() {
  $count = NodeHelper::refreshExportFiles();
  drush_log(sprintf('%d nodes were updated', $count), 'ok');
}

/**
 * Callback function for drush civihr-blocks-cleanup.
 * Callback is called by using drush_hook_command() where the Drush command with
 * all "-" characters converted to "_" characters (civihr-blocks-cleanup)
 */
function drush_civihr_employee_portal_civihr_blocks_cleanup() {

  // Disable not needed blocks
  db_update('block')
    ->fields(['region' => -1])
    ->condition('theme', 'civihr_default_theme')
    ->condition('region', 'content')
    ->condition('delta', 'main', '!=')
    ->execute();

  // Log to the command line with an OK status
  drush_log('CiviHR not used blocks were hidden', 'ok');
}

/**
 * Callback function for drush update-external-ids.
 * Callback is called by using drush_hook_command() where the Drush command with
 * all "-" characters converted to "_" characters (update-external-ids)
 */
function drush_civihr_employee_portal_update_external_ids() {
  try {
    $uf_data = civicrm_api3('UFMatch', 'get', [
      'sequential' => 1,
      'return' => "contact_id,uf_id,contact_type",
    ]);

    foreach ($uf_data['values'] as $uf_item) {
      $user = user_load($uf_item['uf_id']);

      civicrm_api3('Contact', 'create', [
        'sequential' => 1,
        'contact_type' => $uf_item['contact_type'],
        'id' => $uf_item['contact_id'],
        'external_identifier' => $user->name,
      ]);
    }
  } catch (CiviCRM_API3_Exception $e) {
    $error = $e->getMessage();
    $msg = dt('Error communicating with Civi API: @err', ['@err' => $error]);
    drush_log($msg, 'error');
    drush_user_abort();
    return;
  }

  // Log to the command line with an OK status
  drush_log('External ID parameters were updated', 'ok');
}

/**
 * Callback function for drush update-email-type.
 * Callback is called by using drush_hook_command() where the Drush command with
 * all "-" characters converted to "_" characters (update-email-type)
 *
 */
function drush_civihr_employee_portal_update_email_type() {
  try {
    $work_type_id = HelperClass::_get_work_location_type_id();

    $uf_data = civicrm_api3('UFMatch', 'get', [
      'sequential' => 1,
      'return' => "contact_id",
    ]);

    //update primary email to "Work" location type for each user
    foreach ($uf_data['values'] as $uf_item) {

      $email_data = civicrm_api3('Email', 'get', [
        'sequential' => 1,
        'contact_id' => $uf_item['contact_id'],
        'is_primary' => 1,
        'return' => "id,email,contact_id,is_primary,location_type_id",
      ]);

      $email_values = reset($email_data['values']);

      if ((isset($email_values['id']) && isset($email_values['email']))
        && $email_values['location_type_id'] !== $work_type_id) {
        civicrm_api3('Email', 'create', [
          'sequential' => 1,
          'id' => $email_values['id'],
          'email' => $email_values['email'],
          'contact_id' => $email_values['contact_id'],
          'is_primary' => $email_values['is_primary'],
          'location_type_id' => $work_type_id,
        ]);
      }
    }
  } catch (CiviCRM_API3_Exception $e) {
    $error = $e->getMessage();
    $msg = dt('Error communicating with CiVi API: @err', ['@err' => $error]);
    drush_log($msg, 'error');
    drush_user_abort();
    return;
  }

  // Log to the command line with an OK status
  drush_log('Primary email types were changed to "Work"', 'ok');
}
