<?php

// This file must be at civihr_employee_portal/views directory.
 
/**
 * @file
 * Views definitions for civihr_employee_portal module.
 */
 
/**
 * Implements hook_views_data_alter().
 */
function civihr_employee_portal_views_data_alter(&$data) {


    /**
     * Custom field handler which will create age group based on the contact birth date
     */
    $data['civicrm_contact']['age_group'] = array(
        'title' => t('Age Group'),
        'help' => t('Age group for the contact'),
        'real field' => 'birth_date',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_age_group',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'civihr_employee_portal_argument_age_group',
            'name field' => 'birth_date',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );
        
    $data['json']['absence_entitlement'] = array(
        'title' => t('Absence entitlement value'),
        'help' => t('Absence entitlement'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_entitlement',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['document_contacts'] = array(
        'title' => t('Document contacts'),
        'help' => t('Document contacts'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_document_contacts',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_document_contacts_request_handler',
            'name_field' => 'document_targets',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['document_status'] = array(
        'title' => t('Document status'),
        'help' => t('Document status'),
        'real field' => 'status_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_document_status',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'subject',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );

    $data['json']['task_contacts'] = array(
        'title' => t('Task contacts'),
        'help' => t('Task contacts'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_task_contacts',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_task_contacts_request_handler',
            'name_field' => 'task_targets',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['task_status'] = array(
        'title' => t('Task status'),
        'help' => t('Task status'),
        'real field' => 'status_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_task_status',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'task_status',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['task_type'] = array(
        'title' => t('Task type'),
        'help' => t('Task type'),
        'real field' => 'activity_type_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_task_type',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'task_type',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['period_html'] = array(
        'title' => t('Html field for period date'),
        'help' => t('Displays html field based on period ID'),
        'real field' => 'period_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_period',
            'click sortable' => FALSE,
        ),
        
    );
    
    // Add custom date handler
    $data['absence_list']['absence_start_date_timestamp']['field']['handler'] = 'views_handler_field_date';
    $data['absence_list']['absence_start_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
    $data['absence_list']['absence_start_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
    $data['absence_list']['absence_start_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';
    
    $data['absence_list']['absence_end_date_timestamp']['field']['handler'] = 'views_handler_field_date';
    $data['absence_list']['absence_end_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
    $data['absence_list']['absence_end_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
    $data['absence_list']['absence_end_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';
    
    $data['absence_list']['absence_start_date_period_filter'] = array(
        'title' => t('Absence date filter based on Civi date periods'),
        'help' => t('Absence date filter based on Civi date periods.'),
        'real field' => 'absence_start_date_timestamp',
        'field' => array(
            'handler' => 'views_handler_field_date',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_date',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'civihr_employee_portal_filter_absence_period',
            'help' => t('Filter absence list result based on Civi date periods'),
        ),
        'sort' => array('handler' => 'views_handler_sort_date'),
    );
    
    $data['absence_list']['duration'] = array(
        'title' => t('Absence type row value (Duration)'),
        'help' => t('Row value for each absence type (Duration)'),
        'real field' => 'duration',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_duration',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_numeric',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );
    
    $data['absence_list']['absence_status'] = array(
        'title' => t('Absence status'),
        'help' => t('Absence status field value'),
        'real field' => 'absence_status',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_status',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );
    
    $data['absence_list']['balance_totals'] = array(
        'title' => t('Balance / Totals block area'),
        'help' => t('Balance / Totals block area.'),
        'area' => array(
            'handler' => 'civihr_employee_portal_handler_area_totals',
        ),
    );
    
    $data['absence_approval_list']['civi_target_contact_name'] = array(
        'title' => t('Civi contact name - absence target contact'),
        'help' => t('Civi contact name for the assigned absence/activity target contact'),
        'real field' => 'employee_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_employee_id',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );
    
    $data['absence_approval_list']['duration'] = array(
        'title' => t('Absence type row value (Duration)'),
        'help' => t('Row value for each absence type (Duration)'),
        'real field' => 'duration',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_duration',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_numeric',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );
    
    $data['absence_approval_list']['absence_status'] = array(
        'title' => t('Absence status'),
        'help' => t('Absence status field value'),
        'real field' => 'absence_status',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_status',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );
    
    // Add custom date handler
    $data['absence_approval_list']['absence_start_date_timestamp']['field']['handler'] = 'views_handler_field_date';
    $data['absence_approval_list']['absence_start_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
    $data['absence_approval_list']['absence_start_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
    $data['absence_approval_list']['absence_start_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';
    
    $data['absence_approval_list']['absence_end_date_timestamp']['field']['handler'] = 'views_handler_field_date';
    $data['absence_approval_list']['absence_end_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
    $data['absence_approval_list']['absence_end_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
    $data['absence_approval_list']['absence_end_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';
    
    return $data;
}

/**
 * Implements hook_views_pre_render().
 * Adding required js for the modal window
 */
function civihr_employee_portal_views_pre_render(&$view) {

    if ($view->name == 'hr_documents') {

        if ($view->current_display == 'hr_resources') {

            ctools_include('modal');
            ctools_modal_add_js();

        }
    }
}