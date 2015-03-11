<?php

/**
 * Exported hr_staff_directory view
 */

global $base_url;

$view = new view();
$view->name = 'hr_staff_directory';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'json';
$view->human_name = 'HR Staff directory';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'HR Staff Directory';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/civihr_contacts/';
$handler->display->display_options['query']['options']['row_apath'] = 'values';
$handler->display->display_options['query']['options']['show_errors'] = 1;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'value' => 'value',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'value' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: display_name: value */
$handler->display->display_options['fields']['value']['id'] = 'value';
$handler->display->display_options['fields']['value']['table'] = 'json';
$handler->display->display_options['fields']['value']['field'] = 'value';
$handler->display->display_options['fields']['value']['label'] = 'Name';
$handler->display->display_options['fields']['value']['key'] = 'display_name';
/* Field: phone: value */
$handler->display->display_options['fields']['value_3']['id'] = 'value_3';
$handler->display->display_options['fields']['value_3']['table'] = 'json';
$handler->display->display_options['fields']['value_3']['field'] = 'value';
$handler->display->display_options['fields']['value_3']['label'] = 'Work Phone';
$handler->display->display_options['fields']['value_3']['key'] = 'phone';
/* Field: title: value */
$handler->display->display_options['fields']['value_2']['id'] = 'value_2';
$handler->display->display_options['fields']['value_2']['table'] = 'json';
$handler->display->display_options['fields']['value_2']['field'] = 'value';
$handler->display->display_options['fields']['value_2']['label'] = 'Job title';
$handler->display->display_options['fields']['value_2']['key'] = 'title';
/* Field: email: value */
$handler->display->display_options['fields']['value_1']['id'] = 'value_1';
$handler->display->display_options['fields']['value_1']['table'] = 'json';
$handler->display->display_options['fields']['value_1']['field'] = 'value';
$handler->display->display_options['fields']['value_1']['label'] = 'Email';
$handler->display->display_options['fields']['value_1']['key'] = 'email';
/* Field: location: value */
$handler->display->display_options['fields']['value_4']['id'] = 'value_4';
$handler->display->display_options['fields']['value_4']['table'] = 'json';
$handler->display->display_options['fields']['value_4']['field'] = 'value';
$handler->display->display_options['fields']['value_4']['label'] = 'Location / Place of Work';
$handler->display->display_options['fields']['value_4']['key'] = 'location';
/* Field: contract_type: value */
$handler->display->display_options['fields']['value_5']['id'] = 'value_5';
$handler->display->display_options['fields']['value_5']['table'] = 'json';
$handler->display->display_options['fields']['value_5']['field'] = 'value';
$handler->display->display_options['fields']['value_5']['label'] = 'Contract Type';
$handler->display->display_options['fields']['value_5']['key'] = 'contract_type';
/* Filter criterion: display_name: value */
$handler->display->display_options['filters']['value_1']['id'] = 'value_1';
$handler->display->display_options['filters']['value_1']['table'] = 'json';
$handler->display->display_options['filters']['value_1']['field'] = 'value';
$handler->display->display_options['filters']['value_1']['operator'] = 'contains';
$handler->display->display_options['filters']['value_1']['group'] = 1;
$handler->display->display_options['filters']['value_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['value_1']['expose']['operator_id'] = 'value_1_op';
$handler->display->display_options['filters']['value_1']['expose']['label'] = 'Name';
$handler->display->display_options['filters']['value_1']['expose']['operator'] = 'value_1_op';
$handler->display->display_options['filters']['value_1']['expose']['identifier'] = 'display_name';
$handler->display->display_options['filters']['value_1']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['value_1']['key'] = 'display_name';
/* Filter criterion: title: value */
$handler->display->display_options['filters']['value_2']['id'] = 'value_2';
$handler->display->display_options['filters']['value_2']['table'] = 'json';
$handler->display->display_options['filters']['value_2']['field'] = 'value';
$handler->display->display_options['filters']['value_2']['operator'] = 'contains';
$handler->display->display_options['filters']['value_2']['group'] = 1;
$handler->display->display_options['filters']['value_2']['exposed'] = TRUE;
$handler->display->display_options['filters']['value_2']['expose']['operator_id'] = 'value_2_op';
$handler->display->display_options['filters']['value_2']['expose']['label'] = 'Job title';
$handler->display->display_options['filters']['value_2']['expose']['operator'] = 'value_2_op';
$handler->display->display_options['filters']['value_2']['expose']['identifier'] = 'job_title';
$handler->display->display_options['filters']['value_2']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['value_2']['key'] = 'title';
/* Filter criterion: phone: value */
$handler->display->display_options['filters']['value_3']['id'] = 'value_3';
$handler->display->display_options['filters']['value_3']['table'] = 'json';
$handler->display->display_options['filters']['value_3']['field'] = 'value';
$handler->display->display_options['filters']['value_3']['operator'] = 'contains';
$handler->display->display_options['filters']['value_3']['group'] = 1;
$handler->display->display_options['filters']['value_3']['exposed'] = TRUE;
$handler->display->display_options['filters']['value_3']['expose']['operator_id'] = 'value_3_op';
$handler->display->display_options['filters']['value_3']['expose']['label'] = 'Phone';
$handler->display->display_options['filters']['value_3']['expose']['operator'] = 'value_3_op';
$handler->display->display_options['filters']['value_3']['expose']['identifier'] = 'phone';
$handler->display->display_options['filters']['value_3']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['value_3']['key'] = 'phone';
/* Filter criterion: email: value */
$handler->display->display_options['filters']['value']['id'] = 'value';
$handler->display->display_options['filters']['value']['table'] = 'json';
$handler->display->display_options['filters']['value']['field'] = 'value';
$handler->display->display_options['filters']['value']['operator'] = 'contains';
$handler->display->display_options['filters']['value']['group'] = 1;
$handler->display->display_options['filters']['value']['exposed'] = TRUE;
$handler->display->display_options['filters']['value']['expose']['operator_id'] = 'value_op';
$handler->display->display_options['filters']['value']['expose']['label'] = 'Email';
$handler->display->display_options['filters']['value']['expose']['operator'] = 'value_op';
$handler->display->display_options['filters']['value']['expose']['identifier'] = 'email_value';
$handler->display->display_options['filters']['value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['value']['key'] = 'email';

/* Display: HR Staff Directory list */
$handler = $view->new_display('page', 'HR Staff Directory list', 'hr_vacancies_list');
$handler->display->display_options['path'] = 'hr-staff-directory';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Staff Directory';
$handler->display->display_options['menu']['weight'] = '7';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['hr_staff_directory'] = array(
  t('Master'),
  t('HR Staff Directory'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Name'),
  t('Work Phone'),
  t('Job title'),
  t('Email'),
  t('Location / Place of Work'),
  t('Contract Type'),
  t('Phone'),
  t('HR Staff Directory list'),
);