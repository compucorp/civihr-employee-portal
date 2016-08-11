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
    $data['civicrm_contact']['age'] = array(
        'title' => t('Age'),
        'help' => t('Contact age'),
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

    /**
     * Custom field handler which will create age group based on the contact birth date
     */
    $data['civicrm_contact']['age_group'] = array(
        'title' => t('Age Group'),
        'help' => t('Age group for the contact'),
        'real field' => 'birth_date',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_contact_age_group',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name field' => 'birth_date',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );

    // Add custom date handler for job contract start/end dates
    $data['hrjc_revision']['effective_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
    $data['hrjc_revision']['effective_end_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';

    $data['hrjc_details']['period_start_date'] = array(
        'title' => t('Period start date'),
        'real field' => 'period_start_date',
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'civihr_employee_portal_argument_date_range',
            'name field' => 'period_start_date',
            'numeric' => FALSE,
        ),
        'sort' => array(
           'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );

    $data['hrjc_details']['period_end_date'] = array(
        'title' => t('Period end date'),
        'real field' => 'period_end_date',
        'field' => array(
            'handler' => 'views_handler_field',// 'views_handler_field_date',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'civihr_employee_portal_argument_date_range',
            'name field' => 'period_end_date',
            'numeric' => FALSE,
        ),
        'sort' => array(
           'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );

    $data['hrjc_role']['role_start_date'] = array(
        'title' => t('Role start date'),
        'real field' => 'role_start_date',
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'civihr_employee_portal_argument_date_range',
            'name field' => 'role_start_date',
            'numeric' => FALSE,
        ),
        'sort' => array(
           'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );

    $data['hrjc_role']['role_end_date'] = array(
        'title' => t('Role end date'),
        'real field' => 'role_end_date',
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'civihr_employee_portal_argument_date_range',
            'name field' => 'role_end_date',
            'numeric' => FALSE,
        ),
        'sort' => array(
           'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );

    $data['hrjc_details_hrjc_revision']['period_start_date'] = array(
        'title' => t('Period start date'),
        'real field' => 'period_start_date',
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'civihr_employee_portal_argument_date_range',
            'name field' => 'period_start_date',
            'numeric' => FALSE,
        ),
        'sort' => array(
           'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );

    $data['hrjc_details_hrjc_revision']['period_end_date'] = array(
        'title' => t('Period end date'),
        'real field' => 'period_end_date',
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'civihr_employee_portal_argument_date_range',
            'name field' => 'period_end_date',
            'numeric' => FALSE,
        ),
        'sort' => array(
           'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );

    $data['absence_list']['absence_start_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
    $data['absence_list']['absence_end_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';

    $data['absence_approval_list']['absence_start_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
    $data['absence_approval_list']['absence_end_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';

//    $data['absence_activity']['absence_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
        $data['absence_activity']['absence_date'] = array(
        'title' => t('Absence date'),
        'real field' => 'absence_date',
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'civihr_employee_portal_argument_date_range',
            'name field' => 'absence_date',
            'numeric' => FALSE,
        ),
        'sort' => array(
           'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
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
    
    // Appraisals handlers
    $data['json']['appraisal_cycle_type'] = array(
        'title' => t('Appraisal Cycle Type'),
        'help' => t('Appraisal Cycle Type'),
        'real field' => 'api.AppraisalCycle.getsingle/cycle_type_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_appraisal_cycle_type',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'appraisal_cycle_type',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['appraisal_cycle_period'] = array(
        'title' => t('Appraisal Cycle Period'),
        'help' => t('Appraisal Cycle Period'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_appraisal_cycle_period',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'appraisal_cycle_period',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['appraisal_status'] = array(
        'title' => t('Appraisal Status'),
        'help' => t('Appraisal Status'),
        'real field' => 'status_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_appraisal_status',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'appraisal_status',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['appraisal_employee'] = array(
        'title' => t('Appraisal Employee'),
        'help' => t('Appraisal Employee'),
        'real field' => 'contact_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_appraisal_employee',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'appraisal_employee',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['appraisal_line_manager'] = array(
        'title' => t('Appraisal Line Manager'),
        'help' => t('Appraisal Line Manager'),
        'real field' => 'manager_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_appraisal_line_manager',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'appraisal_line_manager',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['appraisal_due_date'] = array(
        'title' => t('Appraisal Due Date'),
        'help' => t('Appraisal Due Date'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_appraisal_due_date',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'appraisal_due_date',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['appraisal_contact_id'] = array(
        'title' => t('Appraisal Contact ID'),
        'help' => t('Appraisal Contact ID'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_appraisal_contact_id',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_appraisal_contact_id_request_handler',
            'name_field' => 'appraisal_contact_id',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );

    // Reports handlers
    $data['hrjc_details']['end_reason'] = array(
        'title' => t('Contract end reason'),
        'real field' => 'end_reason',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_jobcontract_end_reason',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'end_reason',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['hrjc_hour']['location_standard_hours'] = array(
        'title' => t('Contract location standard hours'),
        'real field' => 'location_standard_hours',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_jobcontract_location_standard_hours',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'location_standard_hours',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['hrjc_pay']['pay_scale'] = array(
        'title' => t('Contract pay scale'),
        'real field' => 'pay_scale',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_jobcontract_pay_scale',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'pay_scale',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['hrjc_pension']['is_enrolled'] = array(
        'title' => t('Contract pension is enrolled'),
        'real field' => 'is_enrolled',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_jobcontract_pension_is_enrolled',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'is_enrolled',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['hrjc_role']['role_funder'] = array(
        'title' => t('Role funder'),
        'real field' => 'role_funder',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_pipe',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'role_funder',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['hrjc_role']['role_percent_pay_funder'] = array(
        'title' => t('Role percent pay funder'),
        'real field' => 'role_percent_pay_funder',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_pipe',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'role_percent_pay_funder',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['hrjc_role']['role_cost_center'] = array(
        'title' => t('Role cost center'),
        'real field' => 'role_cost_center',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_pipe',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'role_cost_center',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['hrjc_role']['role_percent_pay_cost_center'] = array(
        'title' => t('Role percent pay cost center'),
        'real field' => 'role_percent_pay_cost_center',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_pipe',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'role_percent_pay_cost_center',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
/*    $data['absence_activity']['absence_day_of_week'] = array(
        'title' => t('Absence day of week'),
        'real field' => 'absence_day_of_week',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_day_of_week',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',//'views_json_query_argument_request_handler',
            'name_field' => 'absence_day_of_week',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',//'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );*/
    $data['absence_activity']['absence_duration'] = array(
        'title' => t('Absence duration in days'),
        'real field' => 'absence_duration',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_duration_in_days',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'absence_duration',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['absence_activity']['absence_amount_taken'] = array(
        'title' => t('Absence amount taken'),
        'real field' => 'absence_amount_taken',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_duration_in_days',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'absence_amount_taken',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['absence_activity']['absence_amount_accrued'] = array(
        'title' => t('Absence amount accrued'),
        'real field' => 'absence_amount_accrued',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_duration_in_days',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'absence_amount_accrued',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['absence_activity']['absence_absolute_amount'] = array(
        'title' => t('Absence absolute duration'),
        'real field' => 'absence_absolute_amount',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_duration_in_days',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'absence_absolute_amount',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    $data['absence_activity']['absence_is_credit'] = array(
        'title' => t('Absence is credit'),
        'real field' => 'absence_is_credit',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_yes_no',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'absence_is_credit',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['civicrm_value_emergency_contacts_21']['id'] = array(
        'title' => t('Emergency Contact ID'),
        'help' => t('Emergency Contact ID field value'),
        'real field' => 'id',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort'
        ),
    );

    // Add custom date handler
//    $data['absence_activity']['absence_date']['field']['handler'] = 'views_handler_field_date';
//    $data['absence_activity']['absence_date']['sort']['handler'] = 'views_handler_sort_date';
//    $data['absence_activity']['absence_date']['filter']['handler'] = 'views_handler_filter_date';
//    $data['absence_activity']['absence_date']['argument']['handler'] = 'views_handler_argument_date';

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
    
    $data['absence_approval_list']['manager_id'] = array(
        'title' => t('Manager ID'),
        'help' => t('Manager ID field value'),
        'real field' => 'manager_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_manager_id',
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
    
    if ($view->name == 'appraisals') {

        ctools_include('modal');
        ctools_modal_add_js();

    }
    
    if($view->name == "civihr_staff_directory"){
      $view->result = removeInactiveManagers($view->result);
      $view->result = removeInactiveDepartments($view->result);
    }

    if($view->name == "approvals"){
      $view->result = removeAbsencesForOtherManagers($view->result);
    }
}

/**
 * Remove absences of contacts that belong to managers other than the currently logged in manager
 *
 */
function removeAbsencesForOtherManagers($results){
  global $user;
  $managerData = get_civihr_uf_match_data($user->uid);
  $managerId = $managerData['contact_id'];

  foreach($results as $key => $value){
    $managers = _getManagerContacts($value->absence_approval_list_employee_id);
    if(!in_array($managerId, $managers)){
      unset($results[$key]);
    }
  }
  return $results;
}

/**
 * Implements hook_views_post_render().
 *
 */
function civihr_employee_portal_views_post_render(&$view, &$output, &$cache) {
  if($view->name == "civihr_staff_directory"){
    $fieldsToClean = removeAdditionalCommas($view);
    if(!empty($fieldsToClean)){
      $output = strtr($output, $fieldsToClean);
    }
  }
}

function removeAdditionalCommas($view){
  $fieldsToClean = array();

  foreach($view->style_plugin->rendered_fields as $renderedField){
    $managerFieldValues = $renderedField['last_name_1'];
    $departmentFieldValues = $renderedField['department'];

    if($managerFieldValues != NULL && trim($managerFieldValues) != "")
    {
      $cleanedValue = preg_replace('/,( *,)+/', ',', trim($managerFieldValues, ', '));
      $fieldsToClean[$managerFieldValues] = $cleanedValue;
    }

    if($departmentFieldValues != NULL)
    {
      $cleanedValue = preg_replace('/,( *,)+/', ',', trim($departmentFieldValues, ', '));
      $fieldsToClean[$departmentFieldValues] = $cleanedValue;
    }
  }

  return $fieldsToClean;
}


function removeInactiveDepartments($results = array()){
  foreach($results as $key => $value){
    $startDate = $value->hrjc_role_civicrm_contact_start_date;
    $endDate = $value->hrjc_role_civicrm_contact_end_date;

    if(($endDate < date('Y-m-d h:i:s') && $endDate != "0000-00-00 00:00:00")
       ||
       ($startDate > date('Y-m-d h:i:s'))
      )
    {
      $value->hrjc_role_civicrm_contact_department = NULL;
    }
  }
  return $results;
}

function removeInactiveManagers($results = array()) {
  foreach ($results as $key => $value) {
    if ($value->civicrm_relationship_is_active == 0 ||
       ($value->civicrm_relationship_end_date < date('Y-m-d') && $value->civicrm_relationship_end_date != NULL) ||
        $value->civicrm_relationship_start_date > date('Y-m-d'))
        {
          $value->civicrm_contact_civicrm_relationship_first_name = NULL;
          $value->civicrm_contact_civicrm_relationship_last_name = NULL;
        }
    }
  return $results;
}

/**
 * Implements hook_views_pre_view().
 * @param $view
 * @param $display_id
 * @param $args
 */
function civihr_employee_portal_views_pre_view(&$view, &$display_id, &$args) {

    // Custom configuration start for items per page
    if (($view->name == 'civihr_staff_directory' && $display_id == 'page') ||
        ($view->name == 'hr_documents' && $display_id == 'hr_resources')) {

        // Default value for items per page
        $default_count = $view->display_handler->display->display_options['pager']['options']['items_per_page'];

        // Set number of items to show
        $numbers_to_show = explode(',', $view->display_handler->display->display_options['pager']['options']['expose']['items_per_page_options']);

        // Generate page path
        $view_url_path = $view->display[$display_id]->display_options['path'];
        $vupc = strlen($view_url_path);
        $page_path = substr($_GET['q'], 0, $vupc);

        // Set items to show per page
        $selected_count = isset($_GET['items_per_page']) ? $_GET['items_per_page'] : $default_count;

        // Create links
        // Not using the l function as it can't handle the "active" class correctly (https://www.drupal.org/node/1410574)
        $items_per_page = array_map(
            function ($item) use ($page_path, $selected_count) {
                $item = trim($item);
                $href = $page_path . '?items_per_page=' . $item;
                $class = 'chr_search-result__items-per-page__list__item btn btn-default';

                if ($selected_count == $item) {
                    $class .= ' active';
                }

                return sprintf('<a href="%s" class="%s">%s</a>', $href, $class, $item);
            },
            $numbers_to_show
        );

        $item_per_page_nav = '<nav class="chr_search-result__items-per-page">
            <span>' . t('View:') . '</span>
            <div class="chr_search-result__items-per-page__list btn-group btn-group-sm">'
                . implode('', $items_per_page ) .
            '</div>
        </nav>';

        // Set the custom footer
        $view->set_item_option(
            $display_id,
            'footer',
            'area_text_custom',
            'content',
            $item_per_page_nav
        );

        // Set the custom header
        $view->set_item_option(
            $display_id,
            'header',
            'result',
            'content',
            '<div class="chr_search-result__total">'
                . t('Results') .
                '<span class="chr_search-result__total__count">'
                    . $view->get_item($display_id, 'header', 'result')['content'] .
                '</span>
            </div>' . $item_per_page_nav
        );

        // Set items per page to the view
        $view->set_items_per_page($selected_count);
    }
}
