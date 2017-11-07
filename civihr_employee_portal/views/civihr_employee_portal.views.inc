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
      'handler' => 'views_handler_field', // 'views_handler_field_date',
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

  // Appraisals handlers
  $data['appraisal']['appraisal_cycle_type'] = array(
    'title' => t('Appraisal Cycle Type'),
    'help' => t('Appraisal Cycle Type'),
    'real field' => 'cycle_type_id',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_appraisal_cycle_type',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_cycle_type',
      'string' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );

  $data['appraisal']['appraisal_cycle_period'] = array(
    'title' => t('Appraisal Cycle Period'),
    'help' => t('Appraisal Cycle Period'),
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_appraisal_cycle_period',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_cycle_period',
      'string' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );

  $data['appraisal']['appraisal_status'] = array(
    'title' => t('Appraisal Status'),
    'help' => t('Appraisal Status'),
    'real field' => 'status_id',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_appraisal_status',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_status',
      'string' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );

  $data['appraisal']['appraisal_employee'] = array(
    'title' => t('Appraisal Employee'),
    'help' => t('Appraisal Employee'),
    'real field' => 'contact_id',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_appraisal_employee',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_employee',
      'string' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );

  $data['appraisal']['appraisal_line_manager'] = array(
    'title' => t('Appraisal Line Manager'),
    'help' => t('Appraisal Line Manager'),
    'real field' => 'manager_id',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_appraisal_line_manager',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_line_manager',
      'string' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );

  $data['appraisal']['appraisal_due_date'] = array(
    'title' => t('Appraisal Due Date'),
    'help' => t('Appraisal Due Date'),
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_appraisal_due_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_due_date',
      'string' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );

  $data['appraisal']['contact_id'] = array(
    'title' => t('Appraisal Contact ID'),
    'help' => t('Appraisal Contact ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'contact_id',
      'string' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );

  $data['appraisal']['manager_id'] = array(
    'title' => t('Appraisal Manager ID'),
    'help' => t('Appraisal Manager ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'manager_id',
      'string' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );

  // Task handlers
  $data['tasks']['assignee_contact_id'] = array(
    'title' => t('Assignee contact'),
    'help' => t('Assignee contact'),
    'real field' => 'assignee_contact_id',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'assignee_contact',
      'string' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );
  $data['tasks']['target_contact_id'] = array(
    'title' => t('Target contact'),
    'help' => t('Target contact'),
    'real field' => 'target_contact_id',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'target_contact',
      'string' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );
  $data['tasks']['status_id'] = array(
    'title' => t('Task status'),
    'help' => t('Task status'),
    'real field' => 'status_id',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_task_status',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'task_status',
      'string' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_json_query_handler_sort'),
  );
  $data['tasks']['activity_type_id'] = array(
    'title' => t('Task type'),
    'help' => t('Task type'),
    'real field' => 'activity_type_id',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_activity_type',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'task_type',
      'string' => TRUE
    ),
  );
  $data['tasks']['activity_date_time'] = array(
    'title' => t('Task due date'),
    'help' => t('Task due date'),
    'real field' => 'activity_date_time',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_tasks_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'task_due_date',
      'string' => TRUE
    ),
  );

  // Document handlers
  $data['documents']['assignee_contact_id'] = array(
    'title' => t('Assignee contact'),
    'help' => t('Assignee contact'),
    'real field' => 'assignee_contact_id',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'assignee_contact',
      'string' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );
  $data['documents']['target_contact_id'] = array(
    'title' => t('Target contact'),
    'help' => t('Target contact'),
    'real field' => 'target_contact_id',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'target_contact',
      'string' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_handler_sort'),
  );
  $data['documents']['status_id'] = array(
    'title' => t('Document status'),
    'help' => t('Document status'),
    'real field' => 'status_id',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_document_status',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'status',
      'string' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_json_query_handler_sort'),
  );
  $data['documents']['activity_type_id'] = array(
    'title' => t('Document type'),
    'help' => t('Document type'),
    'real field' => 'activity_type_id',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_activity_type',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'document_type',
      'string' => TRUE
    ),
  );
  $data['documents']['activity_date_time'] = array(
    'title' => t('Document due date'),
    'help' => t('Document due date'),
    'real field' => 'activity_date_time',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_documents_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'document_due_date',
      'string' => TRUE
    ),
  );
  $data['documents']['expire_date'] = array(
    'title' => t('Document expire date'),
    'help' => t('Document expire date'),
    'real field' => 'expire_date',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_documents_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name_field' => 'document_expire_date',
      'string' => TRUE
    ),
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

  $data['absence_activity']['absence_duration_days'] = array(
    'title' => t('Absence duration in days'),
    'real field' => 'absence_duration_days',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'absence_duration_days',
      'string' => TRUE
    ),
    'filter' => array(
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ),
    'sort' => array('handler' => 'views_json_query_handler_sort'),
  );

  $data['absence_activity']['absence_duration_hours'] = array(
    'title' => t('Absence duration in hours'),
    'real field' => 'absence_duration_hours',
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'absence_duration_hours',
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

  $data['absence_activity']['absence_status'] = array(
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

  $data['absence_activity']['sickness_reason'] = array(
    'title' => t('Sickness reason'),
    'help' => t('Sickness reason field value'),
    'real field' => 'sickness_reason',
    'field' => array(
      'handler' => 'civihr_employee_portal_handler_sickness_reason',
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

  $data['hrjc_contact_details']['work_email']['field']['handler'] = 'civihr_employee_portal_handler_email';

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
  if (in_array($view->name, ['appraisals', 'Tasks', 'my_details_block'])) {
    ctools_include('modal');
    ctools_modal_add_js();
  }

  if ($view->name == "civihr_staff_directory") {
    $view->result = removeInactiveManagers($view->result);
    $view->result = removeInactiveRoleDetails($view->result);
  }

  if ($view->name == "civihr_report_people" || $view->name == "civihr_report_leave_and_absence") {
    formatLengthsOfService($view->result);
  }
}

/**
 * Processes results in people report view to format length of service for each
 * contact in a human readable form.
 *
 * @param array $results
 *   Array of objects (stdClass) that hold data for each contact in people report.
 */
function formatLengthsOfService($results) {
  foreach ($results as $key => $currentRecord) {
    if (!empty($currentRecord->civicrm_value_length_of_service_11_length_of_service)) {
      $length = [];
      $today = new DateTime();
      $past = (new DateTime())->sub(new DateInterval('P' . $currentRecord->civicrm_value_length_of_service_11_length_of_service . 'D'));
      $interval = $today->diff($past);

      $years = intval($interval->format('%y'));
      $months = intval($interval->format('%m'));
      $days = intval($interval->format('%d'));

      if ($years > 0) {
        $length[] = $years > 1 ? "$years years" : "$years year";
      }
      if ($months > 0) {
        $length[] = $months > 1 ? "$months months" : "$months month";
      }
      if ($days > 0) {
        $length[] = $days > 1 ? "$days days" : "$days day";
      }

      $currentRecord->civicrm_value_length_of_service_11_length_of_service = implode(' ', $length);
    }
  }
}

/**
 * Implements hook_views_post_render().
 *
 */
function civihr_employee_portal_views_post_render(&$view, &$output, &$cache) {
  if ($view->name == "civihr_staff_directory") {
    $fieldsToClean = removeAdditionalCommas($view);
    if (!empty($fieldsToClean)) {
      $output = strtr($output, $fieldsToClean);
    }
  }

  if ($view->name == 'hr_vacancies') {
    _civihr_employee_portal_decode_vacancy_description_html($view, $output);
  }
}

/**
 * Decodes html entities in description for each vacancy so HTML tags are sent
 * to the browser.
 *
 * @param object $view
 * @param string $output
 */
function _civihr_employee_portal_decode_vacancy_description_html(&$view, &$output) {
  $replacements = [];
  $renderedFields = [];

  if (isset($view->style_plugin->rendered_fields)) {
    $renderedFields = $view->style_plugin->rendered_fields;
  }
  foreach ($renderedFields as $vacancy) {
    $replacements[$vacancy['description']] = html_entity_decode($vacancy['description']);
  }

  $output = strtr($output, $replacements);
}

function removeAdditionalCommas($view) {
  $fieldsToClean = array();

  foreach ($view->style_plugin->rendered_fields as $renderedField) {
    $managerFieldValues = !empty($renderedField['last_name_1']) ? $renderedField['last_name_1'] : NULL;
    $departmentFieldValues = !empty($renderedField['department']) ? $renderedField['department'] : NULL;

    if ($managerFieldValues != NULL && trim($managerFieldValues) != "") {
      $cleanedValue = preg_replace('/,( *,)+/', ',', trim($managerFieldValues, ', '));
      $fieldsToClean[$managerFieldValues] = $cleanedValue;
    }

    if ($departmentFieldValues != NULL) {
      $cleanedValue = preg_replace('/,( *,)+/', ',', trim($departmentFieldValues, ', '));
      $fieldsToClean[$departmentFieldValues] = $cleanedValue;
    }
  }

  return $fieldsToClean;
}

/**
 * Sets the manager display name to NULL for contacts with manager relationships
 * starting in the future or ending in the past to hide them from the view
 *
 * @param \stdClass[] $results
 *
 * @return array
 */
function removeInactiveManagers($results = []) {
  $endField = 'civicrm_relationship_civicrm_contact_1_end_date';
  $startField = 'civicrm_relationship_civicrm_contact_1_start_date';
  $managerField = 'civicrm_contact_civicrm_relationship_1_display_name';
  $startOfToday = new \DateTime('today 00:00:00');
  $endOfToday = new \DateTime('today 23:59:59');

  $startDates = [];

  foreach ($results as $key => $value) {
    $end = $value->$endField ? new \DateTime($value->$endField) : NULL;
    $start = $value->$startField ? new \DateTime($value->$startField) : NULL;
    $startDates[] = $start;
    $isActive = $value->civicrm_relationship_is_active == 1;
    $isPast = $end && $end < $startOfToday;
    $isFuture = $start > $endOfToday;

    if (!$isActive || $isPast || $isFuture) {
      $value->$managerField = NULL;
    }
  }

  return $results;
}

/**
 * Removes titles and locations from inactive roles for the result
 *
 * @param \stdClass[] $results
 *
 * @return array
 */
function removeInactiveRoleDetails($results = []) {
  $endField = 'hrjc_role_hrjc_revision_role_end_date';
  $startField = 'hrjc_role_hrjc_revision_role_start_date';
  $titleField = 'hrjc_role_hrjc_revision_role_title';
  $locationField = 'hrjc_role_hrjc_revision_role_location';
  $startOfToday = new \DateTime('today 00:00:00');
  $endOfToday = new \DateTime('today 23:59:59');

  foreach ($results as $key => $row) {
    $roleEnd = $row->$endField ? new \DateTime($row->$endField) : NULL;
    $roleStart = $row->$startField ? new \DateTime($row->$startField) : NULL;
    $isPastRole = $roleEnd && $roleEnd < $startOfToday;
    $isFutureRole = $roleStart && $roleStart > $endOfToday;

    if ($isPastRole || $isFutureRole) {
      $row->$titleField = NULL;
      $row->$locationField = NULL;
    }
  }

  return $results;
}

/**
 * Implements hook_views_query_alter().
 *
 * @param view $view
 * @param views_plugin_query_default $query
 */
function civihr_employee_portal_views_query_alter(&$view, &$query) {
  if ($view->name !== 'civihr_staff_directory') {
    return;
  }

  $queryParts = [];
  getWhereFields($query->where, $queryParts);
  $departmentField = 'hrjc_role_hrjc_revision.role_department';
  $roleEndField = 'hrjc_role_hrjc_revision.role_end_date';

  // if department is set we must limit to only current roles
  if (!empty($queryParts[$departmentField])) {
    $group = $query->set_where_group('OR'); // add a new WHERE group
    $query->add_where($group, $roleEndField, date('Y-m-d'), '>=');
    $query->add_where($group, $roleEndField, NULL, 'IS');
  }
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

    // Set the custom header
    $view->set_item_option(
            $display_id, 'header', 'result', 'content', '<div class="chr_search-result__total">'
            . t('Results') .
            '<span class="chr_search-result__total__count">'
            . $view->get_item($display_id, 'header', 'result')['content'] .
            '</span>
            </div>'
    );
  }
}

/**
 * Takes the where part of a query and returns an array of fields => values
 *
 * @param mixed $part
 *  The $query->where part
 * @param array $fields
 *  An array to store the fields
 */
function getWhereFields($part, &$fields) {
  if (isset($part['conditions'])) {
    $part = $part['conditions'];
  }
  if (isset($part['field']) && $part['field'] instanceof DatabaseCondition) {
    $part = $part['field']->conditions();
  }

  if (isset($part['field'])) {
    $fields[$part['field']] = $part['value'];
  }
  elseif (is_array($part)) {
    foreach ($part as $item) {
      getWhereFields($item, $fields);
    }
  }
};
