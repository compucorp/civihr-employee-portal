<?php

$view = new view();
$view->name = 'appraisals';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'appraisal';
$view->human_name = 'Appraisals';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Appraisals';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view appraisals';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
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
);
/* Field: Appraisal entity: Appraisal Employee */
$handler->display->display_options['fields']['appraisal_employee']['id'] = 'appraisal_employee';
$handler->display->display_options['fields']['appraisal_employee']['table'] = 'appraisal';
$handler->display->display_options['fields']['appraisal_employee']['field'] = 'appraisal_employee';
$handler->display->display_options['fields']['appraisal_employee']['label'] = 'Employee';
$handler->display->display_options['fields']['appraisal_employee']['exclude'] = TRUE;
/* Field: Appraisal entity: Appraisal Cycle Type */
$handler->display->display_options['fields']['appraisal_cycle_type']['id'] = 'appraisal_cycle_type';
$handler->display->display_options['fields']['appraisal_cycle_type']['table'] = 'appraisal';
$handler->display->display_options['fields']['appraisal_cycle_type']['field'] = 'appraisal_cycle_type';
$handler->display->display_options['fields']['appraisal_cycle_type']['label'] = 'Cycle Type';
/* Field: Appraisal entity: Appraisal Cycle Period */
$handler->display->display_options['fields']['appraisal_cycle_period']['id'] = 'appraisal_cycle_period';
$handler->display->display_options['fields']['appraisal_cycle_period']['table'] = 'appraisal';
$handler->display->display_options['fields']['appraisal_cycle_period']['field'] = 'appraisal_cycle_period';
$handler->display->display_options['fields']['appraisal_cycle_period']['label'] = 'Cycle Period';
/* Field: Appraisal entity: Appraisal Status */
$handler->display->display_options['fields']['appraisal_status']['id'] = 'appraisal_status';
$handler->display->display_options['fields']['appraisal_status']['table'] = 'appraisal';
$handler->display->display_options['fields']['appraisal_status']['field'] = 'appraisal_status';
$handler->display->display_options['fields']['appraisal_status']['label'] = 'Status';
/* Field: Appraisal entity: Appraisal Line Manager */
$handler->display->display_options['fields']['appraisal_line_manager']['id'] = 'appraisal_line_manager';
$handler->display->display_options['fields']['appraisal_line_manager']['table'] = 'appraisal';
$handler->display->display_options['fields']['appraisal_line_manager']['field'] = 'appraisal_line_manager';
$handler->display->display_options['fields']['appraisal_line_manager']['label'] = 'Line Manager';
/* Field: Appraisal entity: Appraisal Due Date */
$handler->display->display_options['fields']['appraisal_due_date']['id'] = 'appraisal_due_date';
$handler->display->display_options['fields']['appraisal_due_date']['table'] = 'appraisal';
$handler->display->display_options['fields']['appraisal_due_date']['field'] = 'appraisal_due_date';
$handler->display->display_options['fields']['appraisal_due_date']['label'] = 'Due Date';
/* Field: Appraisal entity: Grade */
$handler->display->display_options['fields']['grade']['id'] = 'grade';
$handler->display->display_options['fields']['grade']['table'] = 'appraisal';
$handler->display->display_options['fields']['grade']['field'] = 'grade';
$handler->display->display_options['fields']['grade']['separator'] = '';
/* Field: Appraisal entity: Status_id */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'appraisal';
$handler->display->display_options['fields']['status_id']['field'] = 'status_id';
$handler->display->display_options['fields']['status_id']['label'] = 'Status ID';
$handler->display->display_options['fields']['status_id']['separator'] = '';
/* Field: Appraisal entity: Self_appraisal_due */
$handler->display->display_options['fields']['self_appraisal_due']['id'] = 'self_appraisal_due';
$handler->display->display_options['fields']['self_appraisal_due']['table'] = 'appraisal';
$handler->display->display_options['fields']['self_appraisal_due']['field'] = 'self_appraisal_due';
$handler->display->display_options['fields']['self_appraisal_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['self_appraisal_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['self_appraisal_due']['element_wrapper_class'] = 'hidden';
/* Field: Appraisal entity: Manager_appraisal_due */
$handler->display->display_options['fields']['manager_appraisal_due']['id'] = 'manager_appraisal_due';
$handler->display->display_options['fields']['manager_appraisal_due']['table'] = 'appraisal';
$handler->display->display_options['fields']['manager_appraisal_due']['field'] = 'manager_appraisal_due';
$handler->display->display_options['fields']['manager_appraisal_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['manager_appraisal_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['manager_appraisal_due']['element_wrapper_class'] = 'hidden';
/* Field: Appraisal entity: Grade_due */
$handler->display->display_options['fields']['grade_due']['id'] = 'grade_due';
$handler->display->display_options['fields']['grade_due']['table'] = 'appraisal';
$handler->display->display_options['fields']['grade_due']['field'] = 'grade_due';
$handler->display->display_options['fields']['grade_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['grade_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['grade_due']['element_wrapper_class'] = 'hidden';
/* Field: Appraisal entity: Appraisal entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'appraisal';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_wrapper_class'] = 'hidden';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Appraisal entity: Cycle_start_date */
$handler->display->display_options['fields']['cycle_start_date']['id'] = 'cycle_start_date';
$handler->display->display_options['fields']['cycle_start_date']['table'] = 'appraisal';
$handler->display->display_options['fields']['cycle_start_date']['field'] = 'cycle_start_date';
$handler->display->display_options['fields']['cycle_start_date']['label'] = '';
$handler->display->display_options['fields']['cycle_start_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['cycle_start_date']['element_label_colon'] = FALSE;
/* Field: Appraisal entity: Cycle_end_date */
$handler->display->display_options['fields']['cycle_end_date']['id'] = 'cycle_end_date';
$handler->display->display_options['fields']['cycle_end_date']['table'] = 'appraisal';
$handler->display->display_options['fields']['cycle_end_date']['field'] = 'cycle_end_date';
$handler->display->display_options['fields']['cycle_end_date']['label'] = '';
$handler->display->display_options['fields']['cycle_end_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['cycle_end_date']['element_label_colon'] = FALSE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'appraisals_manager');
$handler->display->display_options['enabled'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Appraisal entity: Appraisal Manager ID */
$handler->display->display_options['arguments']['manager_id']['id'] = 'manager_id';
$handler->display->display_options['arguments']['manager_id']['table'] = 'appraisal';
$handler->display->display_options['arguments']['manager_id']['field'] = 'manager_id';
$handler->display->display_options['arguments']['manager_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['manager_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['manager_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['manager_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['manager_id']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['path'] = 'hr-appraisals-manager';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Appraisals';
$handler->display->display_options['menu']['weight'] = '22';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'appraisals_employee');
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Appraisal entity: Appraisal Contact ID */
$handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['arguments']['contact_id']['table'] = 'appraisal';
$handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['arguments']['contact_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['contact_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['contact_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['contact_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['contact_id']['summary_options']['items_per_page'] = '25';
$translatables['appraisals'] = array(
  t('Master'),
  t('Appraisals'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Employee'),
  t('Cycle Type'),
  t('Cycle Period'),
  t('Status'),
  t('Line Manager'),
  t('Due Date'),
  t('Grade'),
  t('.'),
  t('Status ID'),
  t('Self_appraisal_due'),
  t('Manager_appraisal_due'),
  t('Grade_due'),
  t('Appraisal entity ID'),
  t('Page'),
  t('All'),
  t('Block'),
);

