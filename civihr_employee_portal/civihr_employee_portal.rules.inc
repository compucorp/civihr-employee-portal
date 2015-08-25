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
                'absence_type' => array('type' => 'text', 'label' => t('Absence Debit/Credit main type.')),
                'absence_details' => array('type' => 'text', 'label' => t('Absence details.')),
                'form_values' => array('type' => 'object', 'label' => t('Submitted form values.')),
                'leave_type' => array('type' => 'text', 'label' => t('Leave Type.')),
                'leave_date' => array('type' => 'text', 'label' => t('Leave Date and Duration.')),
                'submitted_attachment' => array('type' => 'object', 'label' => t('Submitted file attachment.')),
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
                'leave_type' => array('type' => 'text', 'label' => t('Leave Type.')),
                'leave_date' => array('type' => 'text', 'label' => t('Leave Date and Duration.')),
            ),
        ),
        'approve_all_post_event' => array(
            'label' => t('Approve All button event - All Absence Approved'),
            'group' => t('Absence entity'),
            'module' => 'civihr_employee_portal',
            'variables' => array(
                'current_user' => array('type' => 'user', 'label' => t('The current logged in user from Absence entity.')),
                'target_user' => array('type' => 'user', 'label' => t('The target User entity.')),
                'manager_notes' => array('type' => 'text', 'label' => t('Manager notes.')),
                'leave_type' => array('type' => 'text', 'label' => t('Leave Type.')),
                'leave_date' => array('type' => 'text', 'label' => t('Leave Date and Duration.')),
            ),
        ),
        'partially_approve_post_event' => array(
            'label' => t('Approve Selected button event - Partial Absence Approval'),
            'group' => t('Absence entity'),
            'module' => 'civihr_employee_portal',
            'variables' => array(
                'current_user' => array('type' => 'user', 'label' => t('The current logged in user from Absence entity.')),
                'target_user' => array('type' => 'user', 'label' => t('The target User entity.')),
                'manager_notes' => array('type' => 'text', 'label' => t('Manager notes.')),
                'leave_type' => array('type' => 'text', 'label' => t('Leave Type.')),
                'leave_date' => array('type' => 'text', 'label' => t('Leave Date and Duration.')),
            ),
        ),
        'user_and_civi_contact_added' => array(
            'label' => t('Employee requests access for the Self Service Portal'),
            'group' => t('Absence entity'),
            'module' => 'civihr_employee_portal',
            'variables' => array(
                'current_user' => array('type' => 'user', 'label' => t('The current logged in user from Absence entity.')),
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
                'submitted_attachment' => array(
                    'type' => 'object',
                    'label' => t('Submitted file attachment'),
                    'description' => t("Submitted file attachment by the employee."),
                ),
            ),
        ),
    );
    
    return $actions;
}

/**
 * New absence request action.
 */
function _new_absence_request_action($roles, $absence_type, $absence_details, $form_values, $submitted_attachment) {

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

    // Check if there is attachment created
    if (count((array) $submitted_attachment) != 0) {

        watchdog('absence attached file', print_r($submitted_attachment, TRUE));

        // @TODO -> check if we have file - if yes load the entity add the file and save
        // Load the main entity
        $main_activity = entity_load_single('civicrm_activity', $result['id']);

        // Attach the file to the entity
        $main_activity->field_attachment[LANGUAGE_NONE][0] = (array) $submitted_attachment;

        // Save the entity
        $main_activity->save();

    }
    else {
        watchdog('no attached file', print_r($submitted_attachment, TRUE));
    }

    // Define Absence Date Durations
    $absentDateDurations = array();
    $date_counter = 0;
    
    foreach ($form_values as $object_property_key => $object_property_value) {
        
        if (strpos($object_property_key, '_requested_day_') !== false) {
            
            if ($date_counter > 0) {
            
                $new_date = strtotime($form_values->absence_request_date_from);
                $new_date = $new_date + (60 * 60 * 24 * $date_counter);
                $new_date = date('Y-m-d', $new_date);
                
                $absentDateDurations[$object_property_key] = array('date' => $new_date . " 00:00:00", 'duration' => $object_property_value, 'approval' => '1');
            
            }
            else {
                
                $absentDateDurations[$object_property_key] = array('date' => $form_values->absence_request_date_from . " 00:00:00", 'duration' => $object_property_value, 'approval' => '1');
                
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
