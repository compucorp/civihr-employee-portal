<?php

/**
 * Implements hook_drush_help().
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
    }
}

/**
 * Implements hook_drush_command().
 */
function civihr_employee_portal_drush_command() {
    $items = array();

    $items['refresh-node-export-files'] = array(
        'description' => dt('Refresh Webform node export files.'),
        'arguments'   => array(),
        'examples' => array(
            'Standard example' => 'drush refresh-node-export-files',
        ),
        'aliases' => array('rnef'),
    );

    $items['civihr-blocks-cleanup'] = array(
        'description' => dt('Hides the blocks not used for CiviHR employee portal.'),
        'arguments'   => array(),
        'examples' => array(
            'Standard example' => 'drush civihr-blocks-cleanup',
        ),
        'aliases' => array('civihrbc'),
    );

    $items['update-external-ids'] = array(
        'description' => dt('Sets usernames into external IDs'),
        'arguments'   => array(),
        'examples' => array(
            'Standard example' => 'drush update-external-ids',
        ),
        'aliases' => array('drush-ueids'),
    );
    
     $items['update-email-type'] = array(
        'description' => dt('Sets primary email type to "Work" for existing users'),
        'arguments'   => array(),
        'examples' => array(
            'Standard example' => 'drush update-email-type',
        ),
        'aliases' => array('drush-uetype'),
    );
    return $items;
}

/**
 * Callback function for drush refresh-node-export-files.
 * Callback is called by using drush_hook_command() where
 * the Drush command with all "-" characters converted to "_" characters (refresh-node-export-files)
 *
 */
function drush_civihr_employee_portal_refresh_node_export_files() {

    // Check for all node export files
    $files = file_scan_directory(drupal_get_path('module', 'civihr_employee_portal') . '/features/node_export_files', '/.*\.export$/');

    // Loop the export files and import them
    foreach ($files as $filepath => $file) {

        $info = node_export_import(file_get_contents($filepath));
        drush_log(print_r($info), 'ok');

    }

    // Log to the command line with an OK status
    drush_log('Node Webform refresh finished', 'ok');
}

/**
 * Callback function for drush civihr-blocks-cleanup.
 * Callback is called by using drush_hook_command() where
 * the Drush command with all "-" characters converted to "_" characters (civihr-blocks-cleanup)
 *
 */
function drush_civihr_employee_portal_civihr_blocks_cleanup() {

    // Disable not needed blocks
    db_update('block')
        ->fields(array('region' => -1))
        ->condition('theme', 'civihr_default_theme')
        ->condition('region', 'content')
        ->condition('delta', 'main', '!=')
        ->execute();

    // Log to the command line with an OK status
    drush_log('CiviHR not used blocks were hidden', 'ok');
}

/**
 * Callback function for drush update-external-ids.
 * Callback is called by using drush_hook_command() where
 * the Drush command with all "-" characters converted to "_" characters (update-external-ids)
 *
 */
function drush_civihr_employee_portal_update_external_ids() {
    try {
        $uf_data = civicrm_api3('UFMatch', 'get', array(
            'sequential' => 1,
            'return' => "contact_id,uf_id,contact_type",
        ));

        foreach ($uf_data['values'] as $uf_item) {
            $user = user_load($uf_item['uf_id']);

            $result = civicrm_api3('Contact', 'create', array(
                'sequential' => 1,
                'contact_type' => $uf_item['contact_type'],
                'id' => $uf_item['contact_id'],
                'external_identifier' => $user->name,
            ));
        }
    }
    catch (CiviCRM_API3_Exception $e) {
        $error = $e->getMessage();
        drush_log(dt('Error communicating with CiVi API: @err', array('@err' => $error)), 'error');
        drush_user_abort();
        return;
    }

    // Log to the command line with an OK status
    drush_log('External ID parameters were updated', 'ok');
}

/**
 * Callback function for drush update-email-type.
 * Callback is called by using drush_hook_command() where
 * the Drush command with all "-" characters converted to "_" characters (update-email-type)
 *
 */
function drush_civihr_employee_portal_update_email_type() {
    try {
        $work_type_id = _get_work_location_type_id();

        $uf_data = civicrm_api3('UFMatch', 'get', array(
            'sequential' => 1,
            'return' => "contact_id",
        ));

        //update primary email to "Work" location type for each user
        foreach ($uf_data['values'] as $uf_item) {

            $email_data = civicrm_api3('Email', 'get', array(
                'sequential' => 1,
                'contact_id' => $uf_item['contact_id'],
                'is_primary' => 1,
                'return' => "id,email,contact_id,is_primary,location_type_id",
            ));

            $email_values = reset($email_data['values']);
            
            if ($email_values['location_type_id'] !== $work_type_id) {
                $result = civicrm_api3('Email', 'create', array(
                    'sequential' => 1,
                    'id' => $email_values['id'],
                    'email' => $email_values['email'],
                    'contact_id' => $email_values['contact_id'],
                    'is_primary' => $email_values['is_primary'],
                    'location_type_id' => $work_type_id,
                ));
            }
        }
    }
    catch (CiviCRM_API3_Exception $e) {
        $error = $e->getMessage();
        drush_log(dt('Error communicating with CiVi API: @err', array('@err' => $error)), 'error');
        drush_user_abort();
        return;
    }

    // Log to the command line with an OK status
    drush_log('Primary email types were changed to "Work"', 'ok');
}

/**
 * Helper function for retrieving particular "Work" location type id
 */
function _get_work_location_type_id() {
    $type_data = civicrm_api3('LocationType', 'get', array(
        'sequential' => 1,
        'display_name' => "Work",
    ));

    $type_values = reset($type_data['values']);

    return $type_values['id'];
}
