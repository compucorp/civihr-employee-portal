<?php

$view = new view();
$view->name = 'hr_vacancies';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'hrvacancy';
$view->human_name = 'HR Vacancies';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Current Vacancies';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view vacancies';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
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
$handler->display->display_options['row_plugin'] = 'fields';
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = '<a href="hr-vacancies">View all vacancies</a>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
/* Field: HRVacancy entity: Hrvacancy entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Job ID';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: HRVacancy entity: Position */
$handler->display->display_options['fields']['position']['id'] = 'position';
$handler->display->display_options['fields']['position']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['position']['field'] = 'position';
$handler->display->display_options['fields']['position']['label'] = 'Job Position';
$handler->display->display_options['fields']['position']['element_type'] = 'div';
$handler->display->display_options['fields']['position']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['position']['element_wrapper_type'] = 'div';
/* Field: HRVacancy entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['fields']['location']['element_type'] = 'div';
$handler->display->display_options['fields']['location']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['location']['element_wrapper_type'] = 'div';
/* Field: HRVacancy entity: Salary */
$handler->display->display_options['fields']['salary']['id'] = 'salary';
$handler->display->display_options['fields']['salary']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['salary']['field'] = 'salary';
$handler->display->display_options['fields']['salary']['element_type'] = 'div';
$handler->display->display_options['fields']['salary']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['salary']['element_wrapper_type'] = 'div';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="index.php?q=civicrm/vacancy/apply&reset=1&id=[value_8]" class="btn btn-custom">Apply now</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: HRVacancy entity: Start_date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['start_date']['field'] = 'start_date';

/* Display: HR Vacancies Dashboard block */
$handler = $view->new_display('block', 'HR Vacancies Dashboard block', 'hr_vacancies_dashboard_block');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: HRVacancy entity: Hrvacancy entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Job ID';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: HRVacancy entity: Position */
$handler->display->display_options['fields']['position']['id'] = 'position';
$handler->display->display_options['fields']['position']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['position']['field'] = 'position';
$handler->display->display_options['fields']['position']['label'] = 'Job Position';
$handler->display->display_options['fields']['position']['element_type'] = 'div';
$handler->display->display_options['fields']['position']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['position']['element_wrapper_type'] = 'div';
/* Field: HRVacancy entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['fields']['location']['element_type'] = 'div';
$handler->display->display_options['fields']['location']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['location']['element_wrapper_type'] = 'div';
/* Field: HRVacancy entity: Salary */
$handler->display->display_options['fields']['salary']['id'] = 'salary';
$handler->display->display_options['fields']['salary']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['salary']['field'] = 'salary';
$handler->display->display_options['fields']['salary']['element_type'] = 'div';
$handler->display->display_options['fields']['salary']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['salary']['element_wrapper_type'] = 'div';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="index.php?q=civicrm/vacancy/apply&reset=1&id=[value_8]" class="btn btn-custom">Apply now</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

/* Display: HR Vacancies list */
$handler = $view->new_display('page', 'HR Vacancies list', 'hr_vacancies_list');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'HR Vacancies';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'row-fluid';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'position' => 'position',
  'location' => 'location',
  'salary' => 'salary',
  'nothing_1' => 'nothing_1',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: HRVacancy entity: Hrvacancy entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Job ID';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: HRVacancy entity: Position */
$handler->display->display_options['fields']['position']['id'] = 'position';
$handler->display->display_options['fields']['position']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['position']['field'] = 'position';
$handler->display->display_options['fields']['position']['label'] = 'Job Position';
$handler->display->display_options['fields']['position']['element_type'] = 'div';
$handler->display->display_options['fields']['position']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['position']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['position']['element_wrapper_class'] = 'vacancy-wrapper';
/* Field: HRVacancy entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['fields']['location']['element_type'] = 'div';
$handler->display->display_options['fields']['location']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['location']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['location']['element_wrapper_class'] = 'vacancy-wrapper';
/* Field: HRVacancy entity: Salary */
$handler->display->display_options['fields']['salary']['id'] = 'salary';
$handler->display->display_options['fields']['salary']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['salary']['field'] = 'salary';
$handler->display->display_options['fields']['salary']['element_type'] = 'div';
$handler->display->display_options['fields']['salary']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['salary']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['salary']['element_wrapper_class'] = 'vacancy-wrapper';
/* Field: HRVacancy entity: Start_date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['start_date']['field'] = 'start_date';
$handler->display->display_options['fields']['start_date']['label'] = 'Start date';
$handler->display->display_options['fields']['start_date']['exclude'] = TRUE;
/* Field: HRVacancy entity: End_date */
$handler->display->display_options['fields']['end_date']['id'] = 'end_date';
$handler->display->display_options['fields']['end_date']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['end_date']['field'] = 'end_date';
$handler->display->display_options['fields']['end_date']['label'] = 'End date';
$handler->display->display_options['fields']['end_date']['exclude'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = 'Application Dates';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[start_date] - [end_date]';
$handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
$handler->display->display_options['fields']['nothing_1']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'vacancy-wrapper';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
$handler->display->display_options['fields']['nothing_2']['table'] = 'views';
$handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_2']['label'] = '';
$handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<a href="index.php?q=civicrm/vacancy/apply&reset=1&id=[id]" class="btn btn-custom">Apply now</a>';
$handler->display->display_options['fields']['nothing_2']['element_type'] = 'div';
$handler->display->display_options['fields']['nothing_2']['element_label_type'] = 'div';
$handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing_2']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['nothing_2']['element_wrapper_class'] = 'vacancy-wrapper';
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
$handler->display->display_options['fields']['fieldset']['table'] = 'views';
$handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset']['label'] = 'More details';
$handler->display->display_options['fields']['fieldset']['children'] = array(
  0 => 'salary_1',
  1 => 'location_1',
  2 => 'description',
);
$handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'col-md-12 col-sm-12 col-xs-12';
$handler->display->display_options['fields']['fieldset']['fieldset']['id'] = '[id]';
$handler->display->display_options['fields']['fieldset']['fieldset']['collapsible'] = 1;
$handler->display->display_options['fields']['fieldset']['fieldset']['collapsed'] = 1;
/* Field: HRVacancy entity: Salary */
$handler->display->display_options['fields']['salary_1']['id'] = 'salary_1';
$handler->display->display_options['fields']['salary_1']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['salary_1']['field'] = 'salary';
$handler->display->display_options['fields']['salary_1']['element_label_type'] = 'strong';
/* Field: HRVacancy entity: Location */
$handler->display->display_options['fields']['location_1']['id'] = 'location_1';
$handler->display->display_options['fields']['location_1']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['location_1']['field'] = 'location';
$handler->display->display_options['fields']['location_1']['element_label_type'] = 'strong';
/* Field: HRVacancy entity: Description */
$handler->display->display_options['fields']['description']['id'] = 'description';
$handler->display->display_options['fields']['description']['table'] = 'hrvacancy';
$handler->display->display_options['fields']['description']['field'] = 'description';
$handler->display->display_options['fields']['description']['element_label_type'] = 'strong';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: HRVacancy entity: Position */
$handler->display->display_options['filters']['position']['id'] = 'position';
$handler->display->display_options['filters']['position']['table'] = 'hrvacancy';
$handler->display->display_options['filters']['position']['field'] = 'position';
$handler->display->display_options['filters']['position']['operator'] = 'contains';
$handler->display->display_options['filters']['position']['exposed'] = TRUE;
$handler->display->display_options['filters']['position']['expose']['operator_id'] = 'position_op';
$handler->display->display_options['filters']['position']['expose']['label'] = 'Job Position';
$handler->display->display_options['filters']['position']['expose']['operator'] = 'position_op';
$handler->display->display_options['filters']['position']['expose']['identifier'] = 'job_position';
$handler->display->display_options['filters']['position']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  55120974 => 0,
  17087012 => 0,
  57573969 => 0,
);
$handler->display->display_options['filters']['position']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['position']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['position']['expose']['autocomplete_field'] = 'position';
$handler->display->display_options['filters']['position']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['position']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['position']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: HRVacancy entity: Location */
$handler->display->display_options['filters']['location']['id'] = 'location';
$handler->display->display_options['filters']['location']['table'] = 'hrvacancy';
$handler->display->display_options['filters']['location']['field'] = 'location';
$handler->display->display_options['filters']['location']['operator'] = 'contains';
$handler->display->display_options['filters']['location']['exposed'] = TRUE;
$handler->display->display_options['filters']['location']['expose']['operator_id'] = 'location_op';
$handler->display->display_options['filters']['location']['expose']['label'] = 'Location';
$handler->display->display_options['filters']['location']['expose']['operator'] = 'location_op';
$handler->display->display_options['filters']['location']['expose']['identifier'] = 'location';
$handler->display->display_options['filters']['location']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  55120974 => 0,
  17087012 => 0,
  57573969 => 0,
);
$handler->display->display_options['filters']['location']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['location']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['location']['expose']['autocomplete_field'] = 'location';
$handler->display->display_options['filters']['location']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['location']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['location']['expose']['autocomplete_dependent'] = 0;
$handler->display->display_options['path'] = 'hr-vacancies';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Vacancies';
$handler->display->display_options['menu']['weight'] = '6';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['hr_vacancies'] = array(
  t('Master'),
  t('Current Vacancies'),
  t('more'),
  t('Search'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('<a href="hr-vacancies">View all vacancies</a>'),
  t('Job ID'),
  t('.'),
  t('Job Position'),
  t('Location'),
  t('Salary'),
  t('<a href="index.php?q=civicrm/vacancy/apply&reset=1&id=[value_8]" class="btn btn-custom">Apply now</a>'),
  t('Start_date'),
  t('HR Vacancies Dashboard block'),
  t('HR Vacancies list'),
  t('HR Vacancies'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Start date'),
  t('End date'),
  t('Application Dates'),
  t('[start_date] - [end_date]'),
  t('<a href="index.php?q=civicrm/vacancy/apply&reset=1&id=[id]" class="btn btn-custom">Apply now</a>'),
  t('More details'),
  t('Description'),
);
