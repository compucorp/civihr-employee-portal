<?php

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
    global $user;
    
    // Civi init
    civicrm_initialize();
                
    // Create the main activity
    $activityParam = array(
        'sequential' => 1,
        'source_contact_id' => $_SESSION['CiviCRM']['userID'],
        'target_contact_id' => $_SESSION['CiviCRM']['userID'],
        // TODO --> For who to assign this task??
        'assignee_contact_id' => 267,
        'activity_type_id' => $form_values->absence_request_type,
        // TODO --> status ID should be dynamic??
        'status_id' => '2'
    );
    
    $result = civicrm_api3('Activity', 'create', $activityParam);
    
    // Create sub-activities
    $activityLeavesParam = array(
        'sequential' => 1,
        'source_record_id' => $result['id'],
        // TODO --> Get the default absence type ID (not hardcode it!)
        'activity_type_id' => '51',
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
