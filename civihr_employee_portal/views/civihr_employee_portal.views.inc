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

  $data['absence_list']['absence_start_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
  $data['absence_list']['absence_end_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';

  $data['absence_approval_list']['absence_start_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
  $data['absence_approval_list']['absence_end_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';

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

  $data['absence_list']['absence_table_header'] = array(
    'title' => t('Absence table header block area'),
    'help' => t('Absence table header block area.'),
    'area' => array(
      'handler' => 'civihr_employee_portal_handler_absence_table_header_block_area',
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
  if (in_array($view->name, array('appraisals', 'approvals'))) {
    ctools_include('modal');
    ctools_modal_add_js();
  }
  if ($view->name == "civihr_staff_directory") {
    $view->result = removeInactiveManagers($view->result);
    $view->result = removeInactiveDepartments($view->result);
  }
  if ($view->name == "approvals") {
    $view->result = removeAbsencesForOtherManagers($view->result);
  }
  
  if ($view->name == "civihr_report_people" && $view->current_display == 'civihr_report_table_people' ) {
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
 * Remove absences of contacts that belong to managers other than the currently logged in manager
 *
 */
function removeAbsencesForOtherManagers($results) {
  global $user;
  $managerData = get_civihr_uf_match_data($user->uid);
  $managerId = $managerData['contact_id'];

  foreach ($results as $key => $value) {
    $managers = _getManagerContacts($value->absence_approval_list_employee_id);
    if (!in_array($managerId, $managers)) {
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
  if ($view->name == "civihr_staff_directory") {
    $fieldsToClean = removeAdditionalCommas($view);
    if (!empty($fieldsToClean)) {
      $output = strtr($output, $fieldsToClean);
    }
  }
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

function removeInactiveDepartments($results = array()) {
  foreach ($results as $key => $value) {
    $startDate = !empty($value->hrjc_role_civicrm_contact_start_date) ? $value->hrjc_role_civicrm_contact_start_date : NULL;
    $endDate = !empty($value->hrjc_role_civicrm_contact_end_date) ? $value->hrjc_role_civicrm_contact_end_date : NULL;

    if (($endDate && $endDate < date('Y-m-d h:i:s') && $endDate != "0000-00-00 00:00:00") ||
            ($startDate && $startDate > date('Y-m-d h:i:s'))
    ) {
      $value->hrjc_role_civicrm_contact_department = NULL;
    }
  }
  return $results;
}

function removeInactiveManagers($results = array()) {
  foreach ($results as $key => $value) {
    if ($value->civicrm_relationship_is_active == 0 ||
            ($value->civicrm_relationship_end_date < date('Y-m-d') && $value->civicrm_relationship_end_date != NULL) ||
            $value->civicrm_relationship_start_date > date('Y-m-d')) {
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
