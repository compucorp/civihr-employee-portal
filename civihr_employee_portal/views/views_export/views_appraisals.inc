<?php

global $base_url;

$view = new view();
$view->name = 'appraisals';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'json';
$view->human_name = 'Appraisals';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Appraisals Manager';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/appraisals_list/';
$handler->display->display_options['query']['options']['row_apath'] = 'values';
$handler->display->display_options['query']['options']['show_errors'] = 1;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['style_plugin'] = 'table';
/* Field: Json: Appraisal Employee */
$handler->display->display_options['fields']['appraisal_employee']['id'] = 'appraisal_employee';
$handler->display->display_options['fields']['appraisal_employee']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_employee']['field'] = 'appraisal_employee';
/* Field: Json: Appraisal Cycle Type */
$handler->display->display_options['fields']['appraisal_cycle_type']['id'] = 'appraisal_cycle_type';
$handler->display->display_options['fields']['appraisal_cycle_type']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_cycle_type']['field'] = 'appraisal_cycle_type';
$handler->display->display_options['fields']['appraisal_cycle_type']['label'] = 'Appraisal cycle type';
/* Field: Json: Appraisal Cycle Period */
$handler->display->display_options['fields']['appraisal_cycle_period']['id'] = 'appraisal_cycle_period';
$handler->display->display_options['fields']['appraisal_cycle_period']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_cycle_period']['field'] = 'appraisal_cycle_period';
$handler->display->display_options['fields']['appraisal_cycle_period']['label'] = 'Appraisal cycle period';
/* Field: Json: Appraisal Status */
$handler->display->display_options['fields']['appraisal_status']['id'] = 'appraisal_status';
$handler->display->display_options['fields']['appraisal_status']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_status']['field'] = 'appraisal_status';
$handler->display->display_options['fields']['appraisal_status']['label'] = 'Appraisal status';
/* Field: Json: Appraisal Line Manager */
$handler->display->display_options['fields']['appraisal_line_manager']['id'] = 'appraisal_line_manager';
$handler->display->display_options['fields']['appraisal_line_manager']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_line_manager']['field'] = 'appraisal_line_manager';
$handler->display->display_options['fields']['appraisal_line_manager']['label'] = 'Line Manager';
/* Field: Json: Appraisal Due Date */
$handler->display->display_options['fields']['appraisal_due_date']['id'] = 'appraisal_due_date';
$handler->display->display_options['fields']['appraisal_due_date']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_due_date']['field'] = 'appraisal_due_date';
/* Field: grade: value */
$handler->display->display_options['fields']['grade']['id'] = 'grade';
$handler->display->display_options['fields']['grade']['table'] = 'json';
$handler->display->display_options['fields']['grade']['field'] = 'value';
$handler->display->display_options['fields']['grade']['label'] = 'Grade';
$handler->display->display_options['fields']['grade']['empty'] = 'Pending';
$handler->display->display_options['fields']['grade']['key'] = 'grade';
/* Field: status_id: value */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'json';
$handler->display->display_options['fields']['status_id']['field'] = 'value';
$handler->display->display_options['fields']['status_id']['label'] = 'Status ID';
$handler->display->display_options['fields']['status_id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['status_id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['status_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status_id']['key'] = 'status_id';
/* Field: self_appraisal_due: value */
$handler->display->display_options['fields']['self_appraisal_due']['id'] = 'self_appraisal_due';
$handler->display->display_options['fields']['self_appraisal_due']['table'] = 'json';
$handler->display->display_options['fields']['self_appraisal_due']['field'] = 'value';
$handler->display->display_options['fields']['self_appraisal_due']['label'] = 'Self Appraisal Due';
$handler->display->display_options['fields']['self_appraisal_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['self_appraisal_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['self_appraisal_due']['key'] = 'self_appraisal_due';
/* Field: manager_appraisal_due: value */
$handler->display->display_options['fields']['manager_appraisal_due']['id'] = 'manager_appraisal_due';
$handler->display->display_options['fields']['manager_appraisal_due']['table'] = 'json';
$handler->display->display_options['fields']['manager_appraisal_due']['field'] = 'value';
$handler->display->display_options['fields']['manager_appraisal_due']['label'] = 'Manager Appraisal Due';
$handler->display->display_options['fields']['manager_appraisal_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['manager_appraisal_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['manager_appraisal_due']['key'] = 'manager_appraisal_due';
/* Field: grade_due: value */
$handler->display->display_options['fields']['grade_due']['id'] = 'grade_due';
$handler->display->display_options['fields']['grade_due']['table'] = 'json';
$handler->display->display_options['fields']['grade_due']['field'] = 'value';
$handler->display->display_options['fields']['grade_due']['label'] = 'Grade Due';
$handler->display->display_options['fields']['grade_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['grade_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['grade_due']['key'] = 'grade_due';
/* Field: id: value */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'json';
$handler->display->display_options['fields']['id']['field'] = 'value';
$handler->display->display_options['fields']['id']['label'] = 'Appraisal ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['key'] = 'id';
/* Contextual filter: Json: Appraisal Contact ID */
$handler->display->display_options['arguments']['appraisal_contact_id']['id'] = 'appraisal_contact_id';
$handler->display->display_options['arguments']['appraisal_contact_id']['table'] = 'json';
$handler->display->display_options['arguments']['appraisal_contact_id']['field'] = 'appraisal_contact_id';
$handler->display->display_options['arguments']['appraisal_contact_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['appraisal_contact_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['appraisal_contact_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['appraisal_contact_id']['name'] = 'manager_id';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'appraisals_manager');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Appraisals';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view appraisals';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Json: Appraisal Employee */
$handler->display->display_options['fields']['appraisal_employee']['id'] = 'appraisal_employee';
$handler->display->display_options['fields']['appraisal_employee']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_employee']['field'] = 'appraisal_employee';
$handler->display->display_options['fields']['appraisal_employee']['label'] = 'Employee';
/* Field: Json: Appraisal Cycle Type */
$handler->display->display_options['fields']['appraisal_cycle_type']['id'] = 'appraisal_cycle_type';
$handler->display->display_options['fields']['appraisal_cycle_type']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_cycle_type']['field'] = 'appraisal_cycle_type';
$handler->display->display_options['fields']['appraisal_cycle_type']['label'] = 'Appraisal cycle type';
/* Field: Json: Appraisal Cycle Period */
$handler->display->display_options['fields']['appraisal_cycle_period']['id'] = 'appraisal_cycle_period';
$handler->display->display_options['fields']['appraisal_cycle_period']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_cycle_period']['field'] = 'appraisal_cycle_period';
$handler->display->display_options['fields']['appraisal_cycle_period']['label'] = 'Cycle Period';
/* Field: Json: Appraisal Status */
$handler->display->display_options['fields']['appraisal_status']['id'] = 'appraisal_status';
$handler->display->display_options['fields']['appraisal_status']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_status']['field'] = 'appraisal_status';
$handler->display->display_options['fields']['appraisal_status']['label'] = 'Status';
/* Field: Json: Appraisal Line Manager */
$handler->display->display_options['fields']['appraisal_line_manager']['id'] = 'appraisal_line_manager';
$handler->display->display_options['fields']['appraisal_line_manager']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_line_manager']['field'] = 'appraisal_line_manager';
$handler->display->display_options['fields']['appraisal_line_manager']['label'] = 'Line Manager';
$handler->display->display_options['fields']['appraisal_line_manager']['element_class'] = 'hidden';
$handler->display->display_options['fields']['appraisal_line_manager']['element_label_class'] = 'hidden';
/* Field: Json: Appraisal Due Date */
$handler->display->display_options['fields']['appraisal_due_date']['id'] = 'appraisal_due_date';
$handler->display->display_options['fields']['appraisal_due_date']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_due_date']['field'] = 'appraisal_due_date';
$handler->display->display_options['fields']['appraisal_due_date']['label'] = 'Due Date';
/* Field: grade: value */
$handler->display->display_options['fields']['grade']['id'] = 'grade';
$handler->display->display_options['fields']['grade']['table'] = 'json';
$handler->display->display_options['fields']['grade']['field'] = 'value';
$handler->display->display_options['fields']['grade']['label'] = 'Grade';
$handler->display->display_options['fields']['grade']['empty'] = 'Pending';
$handler->display->display_options['fields']['grade']['key'] = 'grade';
/* Field: status_id: value */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'json';
$handler->display->display_options['fields']['status_id']['field'] = 'value';
$handler->display->display_options['fields']['status_id']['label'] = 'Status ID';
$handler->display->display_options['fields']['status_id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['status_id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['status_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status_id']['key'] = 'status_id';
/* Field: self_appraisal_due: value */
$handler->display->display_options['fields']['self_appraisal_due']['id'] = 'self_appraisal_due';
$handler->display->display_options['fields']['self_appraisal_due']['table'] = 'json';
$handler->display->display_options['fields']['self_appraisal_due']['field'] = 'value';
$handler->display->display_options['fields']['self_appraisal_due']['label'] = 'Self Appraisal Due';
$handler->display->display_options['fields']['self_appraisal_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['self_appraisal_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['self_appraisal_due']['key'] = 'self_appraisal_due';
/* Field: manager_appraisal_due: value */
$handler->display->display_options['fields']['manager_appraisal_due']['id'] = 'manager_appraisal_due';
$handler->display->display_options['fields']['manager_appraisal_due']['table'] = 'json';
$handler->display->display_options['fields']['manager_appraisal_due']['field'] = 'value';
$handler->display->display_options['fields']['manager_appraisal_due']['label'] = 'Manager Appraisal Due';
$handler->display->display_options['fields']['manager_appraisal_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['manager_appraisal_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['manager_appraisal_due']['key'] = 'manager_appraisal_due';
/* Field: grade_due: value */
$handler->display->display_options['fields']['grade_due']['id'] = 'grade_due';
$handler->display->display_options['fields']['grade_due']['table'] = 'json';
$handler->display->display_options['fields']['grade_due']['field'] = 'value';
$handler->display->display_options['fields']['grade_due']['label'] = 'Grade Due';
$handler->display->display_options['fields']['grade_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['grade_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['grade_due']['key'] = 'grade_due';
/* Field: id: value */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'json';
$handler->display->display_options['fields']['id']['field'] = 'value';
$handler->display->display_options['fields']['id']['label'] = 'Appraisal ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['key'] = 'id';
$handler->display->display_options['path'] = 'hr-appraisals-manager';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Appraisals';
$handler->display->display_options['menu']['weight'] = '22';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'appraisals_employee');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Appraisals';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Json: Appraisal Cycle Type */
$handler->display->display_options['fields']['appraisal_cycle_type']['id'] = 'appraisal_cycle_type';
$handler->display->display_options['fields']['appraisal_cycle_type']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_cycle_type']['field'] = 'appraisal_cycle_type';
/* Field: Json: Appraisal Cycle Period */
$handler->display->display_options['fields']['appraisal_cycle_period']['id'] = 'appraisal_cycle_period';
$handler->display->display_options['fields']['appraisal_cycle_period']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_cycle_period']['field'] = 'appraisal_cycle_period';
$handler->display->display_options['fields']['appraisal_cycle_period']['label'] = 'Appraisal Period';
/* Field: Json: Appraisal Status */
$handler->display->display_options['fields']['appraisal_status']['id'] = 'appraisal_status';
$handler->display->display_options['fields']['appraisal_status']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_status']['field'] = 'appraisal_status';
$handler->display->display_options['fields']['appraisal_status']['label'] = 'Status';
/* Field: Json: Appraisal Line Manager */
$handler->display->display_options['fields']['appraisal_line_manager']['id'] = 'appraisal_line_manager';
$handler->display->display_options['fields']['appraisal_line_manager']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_line_manager']['field'] = 'appraisal_line_manager';
$handler->display->display_options['fields']['appraisal_line_manager']['label'] = 'Line Manager';
/* Field: Json: Appraisal Due Date */
$handler->display->display_options['fields']['appraisal_due_date']['id'] = 'appraisal_due_date';
$handler->display->display_options['fields']['appraisal_due_date']['table'] = 'json';
$handler->display->display_options['fields']['appraisal_due_date']['field'] = 'appraisal_due_date';
$handler->display->display_options['fields']['appraisal_due_date']['label'] = 'Due Date';
/* Field: grade: value */
$handler->display->display_options['fields']['grade']['id'] = 'grade';
$handler->display->display_options['fields']['grade']['table'] = 'json';
$handler->display->display_options['fields']['grade']['field'] = 'value';
$handler->display->display_options['fields']['grade']['label'] = 'Grade';
$handler->display->display_options['fields']['grade']['empty'] = 'Pending';
$handler->display->display_options['fields']['grade']['key'] = 'grade';
/* Field: status_id: value */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'json';
$handler->display->display_options['fields']['status_id']['field'] = 'value';
$handler->display->display_options['fields']['status_id']['label'] = 'Status ID';
$handler->display->display_options['fields']['status_id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['status_id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['status_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['status_id']['key'] = 'status_id';
/* Field: self_appraisal_due: value */
$handler->display->display_options['fields']['self_appraisal_due']['id'] = 'self_appraisal_due';
$handler->display->display_options['fields']['self_appraisal_due']['table'] = 'json';
$handler->display->display_options['fields']['self_appraisal_due']['field'] = 'value';
$handler->display->display_options['fields']['self_appraisal_due']['label'] = 'Self Appraisal Due';
$handler->display->display_options['fields']['self_appraisal_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['self_appraisal_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['self_appraisal_due']['key'] = 'self_appraisal_due';
/* Field: manager_appraisal_due: value */
$handler->display->display_options['fields']['manager_appraisal_due']['id'] = 'manager_appraisal_due';
$handler->display->display_options['fields']['manager_appraisal_due']['table'] = 'json';
$handler->display->display_options['fields']['manager_appraisal_due']['field'] = 'value';
$handler->display->display_options['fields']['manager_appraisal_due']['label'] = 'Manager Appraisal Due';
$handler->display->display_options['fields']['manager_appraisal_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['manager_appraisal_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['manager_appraisal_due']['key'] = 'manager_appraisal_due';
/* Field: grade_due: value */
$handler->display->display_options['fields']['grade_due']['id'] = 'grade_due';
$handler->display->display_options['fields']['grade_due']['table'] = 'json';
$handler->display->display_options['fields']['grade_due']['field'] = 'value';
$handler->display->display_options['fields']['grade_due']['label'] = 'Grade Due';
$handler->display->display_options['fields']['grade_due']['element_class'] = 'hidden';
$handler->display->display_options['fields']['grade_due']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['grade_due']['key'] = 'grade_due';
/* Field: id: value */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'json';
$handler->display->display_options['fields']['id']['field'] = 'value';
$handler->display->display_options['fields']['id']['label'] = 'Appraisal ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['key'] = 'id';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Json: Appraisal Contact ID */
$handler->display->display_options['arguments']['appraisal_contact_id']['id'] = 'appraisal_contact_id';
$handler->display->display_options['arguments']['appraisal_contact_id']['table'] = 'json';
$handler->display->display_options['arguments']['appraisal_contact_id']['field'] = 'appraisal_contact_id';
$handler->display->display_options['arguments']['appraisal_contact_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['appraisal_contact_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['appraisal_contact_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['appraisal_contact_id']['name'] = 'contact_id';
$translatables['appraisals'] = array(
  t('Master'),
  t('Appraisals Manager'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Appraisal Employee'),
  t('Appraisal cycle type'),
  t('Appraisal cycle period'),
  t('Appraisal status'),
  t('Line Manager'),
  t('Appraisal Due Date'),
  t('Grade'),
  t('Pending'),
  t('Status ID'),
  t('Self Appraisal Due'),
  t('Manager Appraisal Due'),
  t('Grade Due'),
  t('Appraisal ID'),
  t('All'),
  t('Page'),
  t('Appraisals'),
  t('Employee'),
  t('Cycle Period'),
  t('Status'),
  t('Due Date'),
  t('Block'),
  t('Appraisal Cycle Type'),
  t('Appraisal Period'),
);
