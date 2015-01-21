<?php

/**
 * Exported absence_approval_list view
 */

$view = new view();
$view->name = 'approvals';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'absence_approval_list';
$view->human_name = 'Approvals';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Manager absence approval';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access manager approval screen';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['row_class'] = 'approvals-table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'absence_title' => 'absence_title',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'absence_title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<a href="manager_approval/nojs/calendar/show" class="ctools-use-modal ctools-modal-civihr-default-style">Open manager calendar</a>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'Nothing to approve yet!';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Field: Absence approval entity: Employee_id */
$handler->display->display_options['fields']['employee_id']['id'] = 'employee_id';
$handler->display->display_options['fields']['employee_id']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['employee_id']['field'] = 'employee_id';
$handler->display->display_options['fields']['employee_id']['label'] = 'Employee CiviCRM Contact ID';
$handler->display->display_options['fields']['employee_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['employee_id']['element_label_class'] = 'employee-id';
$handler->display->display_options['fields']['employee_id']['separator'] = '';
/* Field: Absence approval entity: Absence approval entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Main Absence ID';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Absence approval entity: Activity_type_id */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Activity type ID';
$handler->display->display_options['fields']['activity_type_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['activity_type_id']['separator'] = '';
/* Field: Absence approval entity: Civi contact name - absence target contact */
$handler->display->display_options['fields']['civi_target_contact_name']['id'] = 'civi_target_contact_name';
$handler->display->display_options['fields']['civi_target_contact_name']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['civi_target_contact_name']['field'] = 'civi_target_contact_name';
$handler->display->display_options['fields']['civi_target_contact_name']['label'] = 'Employee name';
/* Field: Absence approval entity: Absence_title */
$handler->display->display_options['fields']['absence_title']['id'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['absence_title']['field'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['label'] = 'Type';
$handler->display->display_options['fields']['absence_title']['element_class'] = '[absence_title]';
/* Field: Absence approval entity: Absence type row value (Duration) */
$handler->display->display_options['fields']['duration']['id'] = 'duration';
$handler->display->display_options['fields']['duration']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['duration']['field'] = 'duration';
$handler->display->display_options['fields']['duration']['label'] = 'Duration';
$handler->display->display_options['fields']['duration']['exclude'] = TRUE;
$handler->display->display_options['fields']['duration']['duration_type'] = '2_53';
/* Field: Absence approval entity: Absence_start_date_timestamp */
$handler->display->display_options['fields']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['label'] = '';
$handler->display->display_options['fields']['absence_start_date_timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_start_date_timestamp']['custom_date_format'] = 'd M, Y';
$handler->display->display_options['fields']['absence_start_date_timestamp']['timezone'] = 'Europe/London';
/* Field: Absence approval entity: Absence_end_date_timestamp */
$handler->display->display_options['fields']['absence_end_date_timestamp']['id'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['absence_end_date_timestamp']['field'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['label'] = '';
$handler->display->display_options['fields']['absence_end_date_timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['absence_end_date_timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['absence_end_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_end_date_timestamp']['custom_date_format'] = 'd M, Y';
$handler->display->display_options['fields']['absence_end_date_timestamp']['timezone'] = 'Europe/London';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Dates';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[absence_start_date_timestamp] - [absence_end_date_timestamp] ([duration])';
/* Field: Absence approval entity: Absence status */
$handler->display->display_options['fields']['absence_status']['id'] = 'absence_status';
$handler->display->display_options['fields']['absence_status']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['absence_status']['field'] = 'absence_status';
$handler->display->display_options['fields']['absence_status']['label'] = 'Status';
$handler->display->display_options['fields']['absence_status']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['absence_status']['alter']['text'] = '<div id="act-id-[id]">[absence_status]</div>';
/* Field: Global: Tooltip field */
$handler->display->display_options['fields']['tooltip']['id'] = 'tooltip';
$handler->display->display_options['fields']['tooltip']['table'] = 'views';
$handler->display->display_options['fields']['tooltip']['field'] = 'tooltip';
$handler->display->display_options['fields']['tooltip']['label'] = 'Pick days';
$handler->display->display_options['fields']['tooltip']['exclude'] = TRUE;
$handler->display->display_options['fields']['tooltip']['alter']['text'] = '<a href="manager_approval/nojs/pick_days/[employee_id]/[id]/[activity_type_id]" class="ctools-use-modal ctools-modal-civihr-default-style">Pick days</a>';
$handler->display->display_options['fields']['tooltip']['tooltip_text'] = 'Choose days';
$handler->display->display_options['fields']['tooltip']['tooltip_hide_if_equal'] = 1;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = 'Action';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div id="quick-approve"><span id="[id]" class="glyphicon glyphicon-ok-sign" aria-hidden="true"></span><span  id="[id]" class="glyphicon glyphicon-remove-sign" aria-hidden="true"></span></div>
[tooltip]';
/* Sort criterion: Absence approval entity: Absence_start_date_timestamp */
$handler->display->display_options['sorts']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['sorts']['absence_start_date_timestamp']['table'] = 'absence_approval_list';
$handler->display->display_options['sorts']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
/* Contextual filter: Absence approval entity: Drupal_uid */
$handler->display->display_options['arguments']['drupal_uid']['id'] = 'drupal_uid';
$handler->display->display_options['arguments']['drupal_uid']['table'] = 'absence_approval_list';
$handler->display->display_options['arguments']['drupal_uid']['field'] = 'drupal_uid';
$handler->display->display_options['arguments']['drupal_uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['drupal_uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['drupal_uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['drupal_uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['drupal_uid']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'approvals';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$translatables['approvals'] = array(
  t('Master'),
  t('Manager absence approval'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('<a href="manager_approval/nojs/calendar/show" class="ctools-use-modal ctools-modal-civihr-default-style">Open manager calendar</a>'),
  t('Nothing to approve yet!'),
  t('Employee CiviCRM Contact ID'),
  t('.'),
  t('Main Absence ID'),
  t('Activity type ID'),
  t('Employee name'),
  t('Type'),
  t('Duration'),
  t('Dates'),
  t('[absence_start_date_timestamp] - [absence_end_date_timestamp] ([duration])'),
  t('Status'),
  t('<div id="act-id-[id]">[absence_status]</div>'),
  t('Pick days'),
  t('<a href="manager_approval/nojs/pick_days/[employee_id]/[id]/[activity_type_id]" class="ctools-use-modal ctools-modal-civihr-default-style">Pick days</a>'),
  t('Choose days'),
  t('1'),
  t('Action'),
  t('<div id="quick-approve"><span id="[id]" class="glyphicon glyphicon-ok-sign" aria-hidden="true"></span><span  id="[id]" class="glyphicon glyphicon-remove-sign" aria-hidden="true"></span></div>
[tooltip]'),
  t('All'),
  t('Page'),
  t('Block'),
);