<?php

/**
 * Exported hr_vacancies view
 */

global $base_url;

$view = new view();
$view->name = 'hr_vacancies';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'json';
$view->human_name = 'HR Vacancies';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'HR Vacancies';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  55120974 => '55120974',
  57573969 => '57573969',
  17087012 => '17087012',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/civihr_vacancies/';
$handler->display->display_options['query']['options']['row_apath'] = 'values';
$handler->display->display_options['query']['options']['show_errors'] = 1;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'row-fluid';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
    'value' => 'value',
    'value_2' => 'value_2',
    'value_1' => 'value_1',
    'nothing' => 'nothing',
);
/* Field: id: value */
$handler->display->display_options['fields']['value_8']['id'] = 'value_8';
$handler->display->display_options['fields']['value_8']['table'] = 'json';
$handler->display->display_options['fields']['value_8']['field'] = 'value';
$handler->display->display_options['fields']['value_8']['label'] = 'Job ID';
$handler->display->display_options['fields']['value_8']['exclude'] = TRUE;
$handler->display->display_options['fields']['value_8']['key'] = 'id';
/* Field: position: value */
$handler->display->display_options['fields']['value']['id'] = 'value';
$handler->display->display_options['fields']['value']['table'] = 'json';
$handler->display->display_options['fields']['value']['field'] = 'value';
$handler->display->display_options['fields']['value']['label'] = 'Job Position';
$handler->display->display_options['fields']['value']['element_type'] = 'div';
$handler->display->display_options['fields']['value']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['value']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['value']['element_wrapper_class'] = 'vacancy-wrapper';
$handler->display->display_options['fields']['value']['key'] = 'position';
/* Field: location: value */
$handler->display->display_options['fields']['value_2']['id'] = 'value_2';
$handler->display->display_options['fields']['value_2']['table'] = 'json';
$handler->display->display_options['fields']['value_2']['field'] = 'value';
$handler->display->display_options['fields']['value_2']['label'] = 'Location';
$handler->display->display_options['fields']['value_2']['element_type'] = 'div';
$handler->display->display_options['fields']['value_2']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['value_2']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['value_2']['element_wrapper_class'] = 'vacancy-wrapper';
$handler->display->display_options['fields']['value_2']['key'] = 'location';
/* Field: salary: value */
$handler->display->display_options['fields']['value_1']['id'] = 'value_1';
$handler->display->display_options['fields']['value_1']['table'] = 'json';
$handler->display->display_options['fields']['value_1']['field'] = 'value';
$handler->display->display_options['fields']['value_1']['label'] = 'Salary';
$handler->display->display_options['fields']['value_1']['element_type'] = 'div';
$handler->display->display_options['fields']['value_1']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['value_1']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['value_1']['element_wrapper_class'] = 'vacancy-wrapper';
$handler->display->display_options['fields']['value_1']['key'] = 'salary';
/* Field: start_date: value */
$handler->display->display_options['fields']['value_3']['id'] = 'value_3';
$handler->display->display_options['fields']['value_3']['table'] = 'json';
$handler->display->display_options['fields']['value_3']['field'] = 'value';
$handler->display->display_options['fields']['value_3']['label'] = 'Start date';
$handler->display->display_options['fields']['value_3']['exclude'] = TRUE;
$handler->display->display_options['fields']['value_3']['key'] = 'start_date';
/* Field: end_date: value */
$handler->display->display_options['fields']['value_4']['id'] = 'value_4';
$handler->display->display_options['fields']['value_4']['table'] = 'json';
$handler->display->display_options['fields']['value_4']['field'] = 'value';
$handler->display->display_options['fields']['value_4']['label'] = 'End date';
$handler->display->display_options['fields']['value_4']['exclude'] = TRUE;
$handler->display->display_options['fields']['value_4']['key'] = 'end_date';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Application Dates';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[value_3] - [value_4]';
$handler->display->display_options['fields']['nothing']['element_type'] = 'div';
$handler->display->display_options['fields']['nothing']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'vacancy-wrapper';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<a href="index.php?q=civicrm/vacancy/apply&reset=1&id=[value_8]" class="btn btn-custom">Apply now</a>';
$handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
$handler->display->display_options['fields']['nothing_1']['element_label_type'] = 'div';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'vacancy-wrapper';
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
$handler->display->display_options['fields']['fieldset']['table'] = 'views';
$handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset']['label'] = 'More details';
$handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'value_5',
    1 => 'value_6',
    2 => 'value_7',
);
$handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'col-md-12 col-sm-12 col-xs-12';
$handler->display->display_options['fields']['fieldset']['fieldset']['id'] = '[value_8]';
$handler->display->display_options['fields']['fieldset']['fieldset']['collapsible'] = 1;
$handler->display->display_options['fields']['fieldset']['fieldset']['collapsed'] = 1;
/* Field: salary: value */
$handler->display->display_options['fields']['value_5']['id'] = 'value_5';
$handler->display->display_options['fields']['value_5']['table'] = 'json';
$handler->display->display_options['fields']['value_5']['field'] = 'value';
$handler->display->display_options['fields']['value_5']['label'] = 'Salary';
$handler->display->display_options['fields']['value_5']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['value_5']['key'] = 'salary';
/* Field: location: value */
$handler->display->display_options['fields']['value_6']['id'] = 'value_6';
$handler->display->display_options['fields']['value_6']['table'] = 'json';
$handler->display->display_options['fields']['value_6']['field'] = 'value';
$handler->display->display_options['fields']['value_6']['label'] = 'Location';
$handler->display->display_options['fields']['value_6']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['value_6']['key'] = 'location';
/* Field: description: value */
$handler->display->display_options['fields']['value_7']['id'] = 'value_7';
$handler->display->display_options['fields']['value_7']['table'] = 'json';
$handler->display->display_options['fields']['value_7']['field'] = 'value';
$handler->display->display_options['fields']['value_7']['label'] = 'Description';
$handler->display->display_options['fields']['value_7']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['value_7']['key'] = 'description';
/* Filter criterion: position: value */
$handler->display->display_options['filters']['value']['id'] = 'value';
$handler->display->display_options['filters']['value']['table'] = 'json';
$handler->display->display_options['filters']['value']['field'] = 'value';
$handler->display->display_options['filters']['value']['operator'] = 'contains';
$handler->display->display_options['filters']['value']['exposed'] = TRUE;
$handler->display->display_options['filters']['value']['expose']['operator_id'] = 'value_op';
$handler->display->display_options['filters']['value']['expose']['label'] = 'Job Position';
$handler->display->display_options['filters']['value']['expose']['operator'] = 'value_op';
$handler->display->display_options['filters']['value']['expose']['identifier'] = 'job_position';
$handler->display->display_options['filters']['value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
);
$handler->display->display_options['filters']['value']['key'] = 'position';
/* Filter criterion: location: value */
$handler->display->display_options['filters']['value_1']['id'] = 'value_1';
$handler->display->display_options['filters']['value_1']['table'] = 'json';
$handler->display->display_options['filters']['value_1']['field'] = 'value';
$handler->display->display_options['filters']['value_1']['operator'] = 'contains';
$handler->display->display_options['filters']['value_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['value_1']['expose']['operator_id'] = 'value_1_op';
$handler->display->display_options['filters']['value_1']['expose']['label'] = 'Location';
$handler->display->display_options['filters']['value_1']['expose']['operator'] = 'value_1_op';
$handler->display->display_options['filters']['value_1']['expose']['identifier'] = 'value_1';
$handler->display->display_options['filters']['value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
);
$handler->display->display_options['filters']['value_1']['key'] = 'location';

/* Display: HR Vacancies Dashboard block */
$handler = $view->new_display('block', 'HR Vacancies Dashboard block', 'hr_vacancies_dashboard_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Current Vacancies';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'jcarousel';
$handler->display->display_options['style_options']['wrap'] = '0';
$handler->display->display_options['style_options']['skin'] = '';
$handler->display->display_options['style_options']['visible'] = '';
$handler->display->display_options['style_options']['responsive'] = 1;
$handler->display->display_options['style_options']['auto'] = '0';
$handler->display->display_options['style_options']['autoPause'] = 1;
$handler->display->display_options['style_options']['easing'] = '';
$handler->display->display_options['style_options']['vertical'] = 0;
$handler->display->display_options['style_options']['ajax'] = 1;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = '<a href="hr-vacancies">View all vacancies</a>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: id: value */
$handler->display->display_options['fields']['value_8']['id'] = 'value_8';
$handler->display->display_options['fields']['value_8']['table'] = 'json';
$handler->display->display_options['fields']['value_8']['field'] = 'value';
$handler->display->display_options['fields']['value_8']['label'] = 'Job ID';
$handler->display->display_options['fields']['value_8']['exclude'] = TRUE;
$handler->display->display_options['fields']['value_8']['key'] = 'id';
/* Field: position: value */
$handler->display->display_options['fields']['value']['id'] = 'value';
$handler->display->display_options['fields']['value']['table'] = 'json';
$handler->display->display_options['fields']['value']['field'] = 'value';
$handler->display->display_options['fields']['value']['label'] = 'Job Position';
$handler->display->display_options['fields']['value']['element_type'] = 'div';
$handler->display->display_options['fields']['value']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['value']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['value']['key'] = 'position';
/* Field: location: value */
$handler->display->display_options['fields']['value_2']['id'] = 'value_2';
$handler->display->display_options['fields']['value_2']['table'] = 'json';
$handler->display->display_options['fields']['value_2']['field'] = 'value';
$handler->display->display_options['fields']['value_2']['label'] = 'Location';
$handler->display->display_options['fields']['value_2']['element_type'] = 'div';
$handler->display->display_options['fields']['value_2']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['value_2']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['value_2']['key'] = 'location';
/* Field: salary: value */
$handler->display->display_options['fields']['value_1']['id'] = 'value_1';
$handler->display->display_options['fields']['value_1']['table'] = 'json';
$handler->display->display_options['fields']['value_1']['field'] = 'value';
$handler->display->display_options['fields']['value_1']['label'] = 'Salary';
$handler->display->display_options['fields']['value_1']['element_type'] = 'div';
$handler->display->display_options['fields']['value_1']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['value_1']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['value_1']['key'] = 'salary';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="index.php?q=civicrm/vacancy/apply&reset=1&id=[value_8]" class="btn btn-custom">Apply now</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;

/* Display: HR Vacancies list */
$handler = $view->new_display('page', 'HR Vacancies list', 'hr_vacancies_list');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['path'] = 'hr-vacancies';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Vacancies';
$handler->display->display_options['menu']['weight'] = '6';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['hr_vacancies'] = array(
    t('Master'),
    t('HR Vacancies'),
    t('more'),
    t('Search'),
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
    t('Job ID'),
    t('Job Position'),
    t('Location'),
    t('Salary'),
    t('Start date'),
    t('End date'),
    t('Application Dates'),
    t('[value_3] - [value_4]'),
    t('<a href="index.php?q=civicrm/vacancy/apply&reset=1&id=[value_8]" class="btn btn-custom">Apply now</a>'),
    t('More details'),
    t('Description'),
    t('HR Vacancies Dashboard block'),
    t('Current Vacancies'),
    t('<a href="hr-vacancies">View all vacancies</a>'),
    t('HR Vacancies list'),
);
