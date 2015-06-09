<?php

use Drupal\civihr_employee_portal\Helpers\HelperClass;

/**
 * Implementation of hook_rules_event_info().
 * @ingroup Absence entity
 */
function civihr_employee_portal_rules_event_info() {
    return array(
        'absence_request_add' => array(
            'label' => t('Employee submits absence request'),
            'group' => t('Absence entity'),
            'module' => 'civihr_employee_portal',
            'variables' => array(
                'current_user' => array('type' => 'user', 'label' => t('The current logged in user from Absence entity.')),
                'absence_type' => array('type' => 'text', 'label' => t('Absence type.')),
                'absence_details' => array('type' => 'text', 'label' => t('Absence details.')),
                'form_values' => array('type' => 'object', 'label' => t('Submitted form values.')),
            ),
        ),
        'reject_all_post_event' => array(
            'label' => t('Reject All button event - All Absence Rejected'),
            'group' => t('Absence entity'),
            'module' => 'civihr_employee_portal',
            'variables' => array(
                'current_user' => array('type' => 'user', 'label' => t('The current logged in user from Absence entity.')),
                'target_user' => array('type' => 'user', 'label' => t('The target User entity.')),
                'manager_notes' => array('type' => 'text', 'label' => t('Manager notes.')),
                'form_values' => array('type' => 'object', 'label' => t('Submitted form values.')),
            ),
        ),
    );
}

/**
 * Implements hook_rules_action_info().
 */
function civihr_employee_portal_rules_action_info() {
    $actions = array(
        '_new_absence_request_action' => array(
            'label' => t('Create new absence request based on passed absence type'),
            'group' => t('Absence entity actions'),
            'parameter' => array(
                // To select a user role.
                'roles' => array(
                    'type' => 'list<integer>',
                    'label' => t('Roles'),
                    'options list' => 'entity_metadata_user_roles',
                    'description' => t('Select the roles whose users can view your message.'),
                ),
                // Absence type (debit or credit)
                'absence_type' => array(
                    'type' => 'text',
                    'label' => t('Absence type'),
                    'description' => t("Absence type passed from the event definition."),
                ),
                // Message inserted by the employee
                'absence_details' => array(
                    'type' => 'text',
                    'label' => t('Absence details'),
                    'description' => t("Absence details submitted by the employee."),
                ),
                'form_values' => array(
                    'type' => 'object',
                    'label' => t('Submitted form values'),
                    'description' => t("Submitted form values by the employee."),
                ),
            ),
        ),
    );
    
    return $actions;
}

/**
 * New absence request action.
 */
function _new_absence_request_action($roles, $absence_type, $absence_details, $form_values) {

    // @TODO --> Change this to the passed USER object (source or target)
    global $user;

    // Get the assigned manager contact IDs array
    $managers = HelperClass::_get_contact_manager_contact_id($user->uid);

    // Create the main activity
    $activityParam = array(
        'sequential' => 1,
        'source_contact_id' => $_SESSION['CiviCRM']['userID'],
        'target_contact_id' => $_SESSION['CiviCRM']['userID'],
        'details' => $form_values->details,
        'assignee_contact_id' => $managers[0],
        'activity_type_id' => $form_values->absence_request_type,
        // TODO --> status ID should be dynamic??
        'status_id' => '1'
    );
    
    $result = civicrm_api3('Activity', 'create', $activityParam);
        
    // Get the main "absence" activity ID
    $activityTypes = CRM_Core_OptionGroup::values('activity_type', FALSE, FALSE, FALSE, NULL, 'name');
    $activityTypeId = CRM_Utils_Array::key('Absence', $activityTypes);
    
    // Create sub-activities
    $activityLeavesParam = array(
        'sequential' => 1,
        'source_record_id' => $result['id'],
        'activity_type_id' => $activityTypeId,
    );
    
    $absentDateDurations = array();
    
    $date_counter = 0;
    
    foreach ($form_values as $object_property_key => $object_property_value) {
        
        if (strpos($object_property_key, '_requested_day_') !== false) {
            
            if ($date_counter > 0) {
            
                $new_date = strtotime($form_values->absence_request_date_from);
                $new_date = $new_date + (60 * 60 * 24 * $date_counter);
                $new_date = date('Y-m-d', $new_date);
                
                $absentDateDurations[$object_property_key] = array('date' => $new_date . " 00:00:00", 'duration' => $object_property_value, 'approval' => '2');
            
            }
            else {
                
                $absentDateDurations[$object_property_key] = array('date' => $form_values->absence_request_date_from . " 00:00:00", 'duration' => $object_property_value, 'approval' => '2');
                
            }
            
            $date_counter++;
        }
        
    }
    
    foreach ($absentDateDurations as $object_key => $duration) {
        $activityLeavesParam['activity_date_time'] = $duration['date'];
        $activityLeavesParam['duration'] = $duration['duration'];
        $activityLeavesParam['status_id'] = $duration['approval'];
        
        civicrm_api3('Activity', 'create', $activityLeavesParam);

    }
    
    // @TODO -> This should provide success / failure value (email message should be based on this success or failure) -> If failure don't create activity
        
}
