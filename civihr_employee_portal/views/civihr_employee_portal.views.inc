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
  $data['civicrm_contact']['age'] = [
    'title' => t('Age'),
    'help' => t('Contact age'),
    'real field' => 'birth_date',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_age_group',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_age_group',
      'name field' => 'birth_date',
      'numeric' => FALSE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  /**
   * Custom field handler which will create age group based on the contact birth date
   */
  $data['civicrm_contact']['age_group'] = [
    'title' => t('Age Group'),
    'help' => t('Age group for the contact'),
    'real field' => 'birth_date',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_contact_age_group',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name field' => 'birth_date',
      'numeric' => FALSE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  // Add custom date handler for job contract start/end dates
  $data['hrjc_revision']['effective_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
  $data['hrjc_revision']['effective_end_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';

  $data['hrjc_details']['period_start_date'] = [
    'title' => t('Period start date'),
    'real field' => 'period_start_date',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_date_range',
      'name field' => 'period_start_date',
      'numeric' => FALSE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort_date',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_date',
    ],
  ];

  $data['hrjc_details']['period_end_date'] = [
    'title' => t('Period end date'),
    'real field' => 'period_end_date',
    'field' => [
      'handler' => 'views_handler_field', // 'views_handler_field_date',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_date_range',
      'name field' => 'period_end_date',
      'numeric' => FALSE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort_date',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_date',
    ],
  ];

  $data['hrjc_role']['role_start_date'] = [
    'title' => t('Role start date'),
    'real field' => 'role_start_date',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_date_range',
      'name field' => 'role_start_date',
      'numeric' => FALSE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort_date',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_date',
    ],
  ];

  $data['hrjc_role']['role_end_date'] = [
    'title' => t('Role end date'),
    'real field' => 'role_end_date',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_date_range',
      'name field' => 'role_end_date',
      'numeric' => FALSE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort_date',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_date',
    ],
  ];

  $data['hrjc_details_hrjc_revision']['period_start_date'] = [
    'title' => t('Period start date'),
    'real field' => 'period_start_date',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_date_range',
      'name field' => 'period_start_date',
      'numeric' => FALSE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort_date',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_date',
    ],
  ];

  $data['hrjc_details_hrjc_revision']['period_end_date'] = [
    'title' => t('Period end date'),
    'real field' => 'period_end_date',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_date_range',
      'name field' => 'period_end_date',
      'numeric' => FALSE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort_date',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_date',
    ],
  ];

  $data['absence_list']['absence_start_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
  $data['absence_list']['absence_end_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';

  $data['absence_approval_list']['absence_start_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
  $data['absence_approval_list']['absence_end_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';

  $data['absence_activity']['absence_date'] = [
    'title' => t('Absence date'),
    'real field' => 'absence_date',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_date_range',
      'name field' => 'absence_date',
      'numeric' => FALSE,
    ],
    'sort' => [
      'handler' => 'views_handler_sort_date',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_date',
    ],
  ];

  // Appraisals handlers
  $data['appraisal']['appraisal_cycle_type'] = [
    'title' => t('Appraisal Cycle Type'),
    'help' => t('Appraisal Cycle Type'),
    'real field' => 'cycle_type_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_appraisal_cycle_type',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_cycle_type',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['appraisal']['appraisal_cycle_period'] = [
    'title' => t('Appraisal Cycle Period'),
    'help' => t('Appraisal Cycle Period'),
    'field' => [
      'handler' => 'civihr_employee_portal_handler_appraisal_cycle_period',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_cycle_period',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['appraisal']['appraisal_status'] = [
    'title' => t('Appraisal Status'),
    'help' => t('Appraisal Status'),
    'real field' => 'status_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_appraisal_status',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_status',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['appraisal']['appraisal_employee'] = [
    'title' => t('Appraisal Employee'),
    'help' => t('Appraisal Employee'),
    'real field' => 'contact_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_appraisal_employee',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_employee',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['appraisal']['appraisal_line_manager'] = [
    'title' => t('Appraisal Line Manager'),
    'help' => t('Appraisal Line Manager'),
    'real field' => 'manager_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_appraisal_line_manager',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_line_manager',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['appraisal']['appraisal_due_date'] = [
    'title' => t('Appraisal Due Date'),
    'help' => t('Appraisal Due Date'),
    'field' => [
      'handler' => 'civihr_employee_portal_handler_appraisal_due_date',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'appraisal_due_date',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['appraisal']['contact_id'] = [
    'title' => t('Appraisal Contact ID'),
    'help' => t('Appraisal Contact ID'),
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'contact_id',
      'string' => TRUE,
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['appraisal']['manager_id'] = [
    'title' => t('Appraisal Manager ID'),
    'help' => t('Appraisal Manager ID'),
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'manager_id',
      'string' => TRUE,
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  // Task handlers
  $data['tasks']['assignee_contact_id'] = [
    'title' => t('Assignee contact'),
    'help' => t('Assignee contact'),
    'real field' => 'assignee_contact_id',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'assignee_contact',
      'string' => TRUE,
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];
  $data['tasks']['target_contact_id'] = [
    'title' => t('Target contact'),
    'help' => t('Target contact'),
    'real field' => 'target_contact_id',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'target_contact',
      'string' => TRUE,
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];
  $data['tasks']['status_id'] = [
    'title' => t('Task status'),
    'help' => t('Task status'),
    'real field' => 'status_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_task_status',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'task_status',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['tasks']['activity_type_id'] = [
    'title' => t('Task type'),
    'help' => t('Task type'),
    'real field' => 'activity_type_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_activity_type',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'task_type',
      'string' => TRUE
    ],
  ];
  $data['tasks']['activity_date_time'] = [
    'title' => t('Task due date'),
    'help' => t('Task due date'),
    'real field' => 'activity_date_time',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_tasks_date',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'task_due_date',
      'string' => TRUE
    ],
  ];

  // Document handlers
  $data['documents']['assignee_contact_id'] = [
    'title' => t('Assignee contact'),
    'help' => t('Assignee contact'),
    'real field' => 'assignee_contact_id',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'assignee_contact',
      'string' => TRUE,
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];
  $data['documents']['target_contact_id'] = [
    'title' => t('Target contact'),
    'help' => t('Target contact'),
    'real field' => 'target_contact_id',
    'field' => [
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'civihr_employee_portal_argument_contact_id',
      'name_field' => 'target_contact',
      'string' => TRUE,
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];
  $data['documents']['status_id'] = [
    'title' => t('Document status'),
    'help' => t('Document status'),
    'real field' => 'status_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_document_status',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'status',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['documents']['activity_type_id'] = [
    'title' => t('Document type'),
    'help' => t('Document type'),
    'real field' => 'activity_type_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_activity_type',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'document_type',
      'string' => TRUE
    ],
  ];
  $data['documents']['activity_date_time'] = [
    'title' => t('Document due date'),
    'help' => t('Document due date'),
    'real field' => 'activity_date_time',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_documents_date',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'document_due_date',
      'string' => TRUE
    ],
  ];
  $data['documents']['expire_date'] = [
    'title' => t('Document expire date'),
    'help' => t('Document expire date'),
    'real field' => 'expire_date',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_documents_date',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument',
      'name_field' => 'document_expire_date',
      'string' => TRUE
    ],
  ];

  // Reports handlers
  $data['hrjc_details']['end_reason'] = [
    'title' => t('Contract end reason'),
    'real field' => 'end_reason',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_jobcontract_end_reason',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'end_reason',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['hrjc_hour']['location_standard_hours'] = [
    'title' => t('Contract location standard hours'),
    'real field' => 'location_standard_hours',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_jobcontract_location_standard_hours',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'location_standard_hours',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['hrjc_pay']['pay_scale'] = [
    'title' => t('Contract pay scale'),
    'real field' => 'pay_scale',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_jobcontract_pay_scale',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'pay_scale',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['hrjc_pension']['is_enrolled'] = [
    'title' => t('Contract pension is enrolled'),
    'real field' => 'is_enrolled',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_jobcontract_pension_is_enrolled',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'is_enrolled',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['hrjc_role']['role_funder'] = [
    'title' => t('Role funder'),
    'real field' => 'role_funder',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_pipe',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'role_funder',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['hrjc_role']['role_percent_pay_funder'] = [
    'title' => t('Role percent pay funder'),
    'real field' => 'role_percent_pay_funder',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_pipe',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'role_percent_pay_funder',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['hrjc_role']['role_cost_center'] = [
    'title' => t('Role cost center'),
    'real field' => 'role_cost_center',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_pipe',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'role_cost_center',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['hrjc_role']['role_percent_pay_cost_center'] = [
    'title' => t('Role percent pay cost center'),
    'real field' => 'role_percent_pay_cost_center',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_pipe',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'role_percent_pay_cost_center',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];

  $data['absence_activity']['absence_duration'] = [
    'title' => t('Absence duration in days'),
    'real field' => 'absence_duration',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_absence_duration_in_days',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'absence_duration',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['absence_activity']['absence_amount_taken'] = [
    'title' => t('Absence amount taken'),
    'real field' => 'absence_amount_taken',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_absence_duration_in_days',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'absence_amount_taken',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['absence_activity']['absence_amount_accrued'] = [
    'title' => t('Absence amount accrued'),
    'real field' => 'absence_amount_accrued',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_absence_duration_in_days',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'absence_amount_accrued',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['absence_activity']['absence_absolute_amount'] = [
    'title' => t('Absence absolute duration'),
    'real field' => 'absence_absolute_amount',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_absence_duration_in_days',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'absence_absolute_amount',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];
  $data['absence_activity']['absence_is_credit'] = [
    'title' => t('Absence is credit'),
    'real field' => 'absence_is_credit',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_yes_no',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_json_query_argument_request_handler',
      'name_field' => 'absence_is_credit',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_json_query_handler_filter',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_json_query_handler_sort'],
  ];

  $data['absence_activity']['absence_status'] = [
    'title' => t('Absence status'),
    'help' => t('Absence status field value'),
    'real field' => 'absence_status',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_absence_status',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument_string',
      'name_field' => 'title',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['civicrm_value_emergency_contacts_21']['id'] = [
    'title' => t('Emergency Contact ID'),
    'help' => t('Emergency Contact ID field value'),
    'real field' => 'id',
    'field' => [
      'handler' => 'views_handler_field_numeric',
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
    ],
    'sort' => [
      'handler' => 'views_handler_sort'
    ],
  ];

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

  $data['absence_list']['absence_start_date_period_filter'] = [
    'title' => t('Absence date filter based on Civi date periods'),
    'help' => t('Absence date filter based on Civi date periods.'),
    'real field' => 'absence_start_date_timestamp',
    'field' => [
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument_date',
      'name_field' => 'title',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'civihr_employee_portal_filter_absence_period',
      'help' => t('Filter absence list result based on Civi date periods'),
    ],
    'sort' => ['handler' => 'views_handler_sort_date'],
  ];

  $data['absence_list']['duration'] = [
    'title' => t('Absence type row value (Duration)'),
    'help' => t('Row value for each absence type (Duration)'),
    'real field' => 'duration',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_absence_duration',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument_numeric',
      'name_field' => 'title',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['absence_list']['absence_status'] = [
    'title' => t('Absence status'),
    'help' => t('Absence status field value'),
    'real field' => 'absence_status',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_absence_status',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument_string',
      'name_field' => 'title',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['absence_list']['absence_table_header'] = [
    'title' => t('Absence table header block area'),
    'help' => t('Absence table header block area.'),
    'area' => [
      'handler' => 'civihr_employee_portal_handler_absence_table_header_block_area',
    ],
  ];

  $data['absence_approval_list']['civi_target_contact_name'] = [
    'title' => t('Civi contact name - absence target contact'),
    'help' => t('Civi contact name for the assigned absence/activity target contact'),
    'real field' => 'employee_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_employee_id',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument_string',
      'name_field' => 'title',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['absence_approval_list']['duration'] = [
    'title' => t('Absence type row value (Duration)'),
    'help' => t('Row value for each absence type (Duration)'),
    'real field' => 'duration',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_absence_duration',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument_numeric',
      'name_field' => 'title',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_numeric',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['absence_approval_list']['absence_status'] = [
    'title' => t('Absence status'),
    'help' => t('Absence status field value'),
    'real field' => 'absence_status',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_absence_status',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument_string',
      'name_field' => 'title',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  $data['absence_approval_list']['manager_id'] = [
    'title' => t('Manager ID'),
    'help' => t('Manager ID field value'),
    'real field' => 'manager_id',
    'field' => [
      'handler' => 'civihr_employee_portal_handler_manager_id',
      'click sortable' => TRUE,
    ],
    'argument' => [
      'handler' => 'views_handler_argument_string',
      'name_field' => 'title',
      'string' => TRUE
    ],
    'filter' => [
      'handler' => 'views_handler_filter_string',
      'help' => t('Filter results to a particular result set'),
    ],
    'sort' => ['handler' => 'views_handler_sort'],
  ];

  // Add custom date handler
  $data['absence_approval_list']['absence_start_date_timestamp']['field']['handler'] = 'views_handler_field_date';
  $data['absence_approval_list']['absence_start_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
  $data['absence_approval_list']['absence_start_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
  $data['absence_approval_list']['absence_start_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';

  $data['absence_approval_list']['absence_end_date_timestamp']['field']['handler'] = 'views_handler_field_date';
  $data['absence_approval_list']['absence_end_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
  $data['absence_approval_list']['absence_end_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
  $data['absence_approval_list']['absence_end_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';

  // custom handler to add links to emails
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
  if (in_array($view->name, ['appraisals', 'approvals', 'Tasks'])) {
    ctools_include('modal');
    ctools_modal_add_js();
  }
  if ($view->name == "civihr_staff_directory") {
    $view->result = removeInactiveManagers($view->result);
    $view->result = removeInactiveRoleDetails($view->result);
  }
  if ($view->name == "approvals") {
    $view->result = removeAbsencesForOtherManagers($view->result);
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
  $fieldsToClean = [];

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
 * @param view $view
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
