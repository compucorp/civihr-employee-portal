<?php

$view = new view();
$view->name = 'civihr_report_people';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'CiviHR Report - People';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'CiviHR Report - People';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
/* Relationship: CiviCRM Contacts: HRJobContract Details entity */
$handler->display->display_options['relationships']['hrjc_details']['id'] = 'hrjc_details';
$handler->display->display_options['relationships']['hrjc_details']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_details']['field'] = 'hrjc_details';
/* Relationship: HRJobContract Details entity: HRJobContract Health entity */
$handler->display->display_options['relationships']['hrjc_health']['id'] = 'hrjc_health';
$handler->display->display_options['relationships']['hrjc_health']['table'] = 'hrjc_details';
$handler->display->display_options['relationships']['hrjc_health']['field'] = 'hrjc_health';
$handler->display->display_options['relationships']['hrjc_health']['relationship'] = 'hrjc_details';
/* Relationship: HRJobContract Details entity: HRJobContract Hour entity */
$handler->display->display_options['relationships']['hrjc_hour']['id'] = 'hrjc_hour';
$handler->display->display_options['relationships']['hrjc_hour']['table'] = 'hrjc_details';
$handler->display->display_options['relationships']['hrjc_hour']['field'] = 'hrjc_hour';
$handler->display->display_options['relationships']['hrjc_hour']['relationship'] = 'hrjc_details';
/* Relationship: HRJobContract Details entity: HRJobContract Leave entity */
$handler->display->display_options['relationships']['hrjc_leave']['id'] = 'hrjc_leave';
$handler->display->display_options['relationships']['hrjc_leave']['table'] = 'hrjc_details';
$handler->display->display_options['relationships']['hrjc_leave']['field'] = 'hrjc_leave';
$handler->display->display_options['relationships']['hrjc_leave']['relationship'] = 'hrjc_details';
/* Relationship: HRJobContract Details entity: HRJobContract Pay entity */
$handler->display->display_options['relationships']['hrjc_pay']['id'] = 'hrjc_pay';
$handler->display->display_options['relationships']['hrjc_pay']['table'] = 'hrjc_details';
$handler->display->display_options['relationships']['hrjc_pay']['field'] = 'hrjc_pay';
$handler->display->display_options['relationships']['hrjc_pay']['relationship'] = 'hrjc_details';
/* Relationship: HRJobContract Details entity: HRJobContract Pension entity */
$handler->display->display_options['relationships']['hrjc_pension']['id'] = 'hrjc_pension';
$handler->display->display_options['relationships']['hrjc_pension']['table'] = 'hrjc_details';
$handler->display->display_options['relationships']['hrjc_pension']['field'] = 'hrjc_pension';
$handler->display->display_options['relationships']['hrjc_pension']['relationship'] = 'hrjc_details';
/* Relationship: HRJobContract Details entity: HRJobContract Role entity */
$handler->display->display_options['relationships']['hrjc_role']['id'] = 'hrjc_role';
$handler->display->display_options['relationships']['hrjc_role']['table'] = 'hrjc_details';
$handler->display->display_options['relationships']['hrjc_role']['field'] = 'hrjc_role';
$handler->display->display_options['relationships']['hrjc_role']['relationship'] = 'hrjc_details';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
/* Field: CiviCRM Contacts: First Name */
$handler->display->display_options['fields']['first_name']['id'] = 'first_name';
$handler->display->display_options['fields']['first_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['first_name']['field'] = 'first_name';
$handler->display->display_options['fields']['first_name']['label'] = 'First name';
$handler->display->display_options['fields']['first_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Contacts: Last Name */
$handler->display->display_options['fields']['last_name']['id'] = 'last_name';
$handler->display->display_options['fields']['last_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['last_name']['field'] = 'last_name';
$handler->display->display_options['fields']['last_name']['label'] = 'Last name';
$handler->display->display_options['fields']['last_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Contacts: Age Group */
$handler->display->display_options['fields']['age_group']['id'] = 'age_group';
$handler->display->display_options['fields']['age_group']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['age_group']['field'] = 'age_group';
$handler->display->display_options['fields']['age_group']['label'] = 'Age';
/* Field: CiviCRM Contacts: Gender */
$handler->display->display_options['fields']['gender']['id'] = 'gender';
$handler->display->display_options['fields']['gender']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['gender']['field'] = 'gender';
/* Field: HRJobContract Details entity: Contract_type */
$handler->display->display_options['fields']['contract_type']['id'] = 'contract_type';
$handler->display->display_options['fields']['contract_type']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['contract_type']['field'] = 'contract_type';
$handler->display->display_options['fields']['contract_type']['relationship'] = 'hrjc_details';
$handler->display->display_options['fields']['contract_type']['label'] = 'Contract type';
/* Field: HRJobContract Details entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['fields']['location']['relationship'] = 'hrjc_details';
/* Field: HRJobContract Hour entity: Location_standard_hours */
$handler->display->display_options['fields']['location_standard_hours']['id'] = 'location_standard_hours';
$handler->display->display_options['fields']['location_standard_hours']['table'] = 'hrjc_hour';
$handler->display->display_options['fields']['location_standard_hours']['field'] = 'location_standard_hours';
$handler->display->display_options['fields']['location_standard_hours']['relationship'] = 'hrjc_hour';
/* Field: HRJobContract Hour entity: Hours_type */
$handler->display->display_options['fields']['hours_type']['id'] = 'hours_type';
$handler->display->display_options['fields']['hours_type']['table'] = 'hrjc_hour';
$handler->display->display_options['fields']['hours_type']['field'] = 'hours_type';
$handler->display->display_options['fields']['hours_type']['relationship'] = 'hrjc_hour';
$handler->display->display_options['fields']['hours_type']['label'] = 'Hours type';
/* Field: HRJobContract Pay entity: Is_paid */
$handler->display->display_options['fields']['is_paid']['id'] = 'is_paid';
$handler->display->display_options['fields']['is_paid']['table'] = 'hrjc_pay';
$handler->display->display_options['fields']['is_paid']['field'] = 'is_paid';
$handler->display->display_options['fields']['is_paid']['relationship'] = 'hrjc_pay';
$handler->display->display_options['fields']['is_paid']['label'] = 'Is paid';
/* Field: HRJobContract Pay entity: Pay_scale */
$handler->display->display_options['fields']['pay_scale']['id'] = 'pay_scale';
$handler->display->display_options['fields']['pay_scale']['table'] = 'hrjc_pay';
$handler->display->display_options['fields']['pay_scale']['field'] = 'pay_scale';
$handler->display->display_options['fields']['pay_scale']['relationship'] = 'hrjc_pay';
$handler->display->display_options['fields']['pay_scale']['label'] = 'Pay scale';
/* Field: HRJobContract Pension entity: Is_enrolled */
$handler->display->display_options['fields']['is_enrolled']['id'] = 'is_enrolled';
$handler->display->display_options['fields']['is_enrolled']['table'] = 'hrjc_pension';
$handler->display->display_options['fields']['is_enrolled']['field'] = 'is_enrolled';
$handler->display->display_options['fields']['is_enrolled']['relationship'] = 'hrjc_pension';
$handler->display->display_options['fields']['is_enrolled']['label'] = 'Is enrolled';
/* Field: HRJobContract Details entity: Period_start_date */
$handler->display->display_options['fields']['period_start_date']['id'] = 'period_start_date';
$handler->display->display_options['fields']['period_start_date']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['period_start_date']['field'] = 'period_start_date';
$handler->display->display_options['fields']['period_start_date']['relationship'] = 'hrjc_details';
$handler->display->display_options['fields']['period_start_date']['label'] = 'Period start date';
/* Field: HRJobContract Details entity: Period_end_date */
$handler->display->display_options['fields']['period_end_date']['id'] = 'period_end_date';
$handler->display->display_options['fields']['period_end_date']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['period_end_date']['field'] = 'period_end_date';
$handler->display->display_options['fields']['period_end_date']['relationship'] = 'hrjc_details';
$handler->display->display_options['fields']['period_end_date']['label'] = 'Period end date';
/* Field: HRJobContract Role entity: Region */
$handler->display->display_options['fields']['region']['id'] = 'region';
$handler->display->display_options['fields']['region']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['region']['field'] = 'region';
$handler->display->display_options['fields']['region']['relationship'] = 'hrjc_role';
/* Field: HRJobContract Role entity: Department */
$handler->display->display_options['fields']['department']['id'] = 'department';
$handler->display->display_options['fields']['department']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['department']['field'] = 'department';
$handler->display->display_options['fields']['department']['relationship'] = 'hrjc_role';
/* Field: HRJobContract Role entity: Level_type */
$handler->display->display_options['fields']['level_type']['id'] = 'level_type';
$handler->display->display_options['fields']['level_type']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['level_type']['field'] = 'level_type';
$handler->display->display_options['fields']['level_type']['relationship'] = 'hrjc_role';
$handler->display->display_options['fields']['level_type']['label'] = 'Level type';
/* Field: HRJobContract Role entity: Cost_center */
$handler->display->display_options['fields']['cost_center']['id'] = 'cost_center';
$handler->display->display_options['fields']['cost_center']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['cost_center']['field'] = 'cost_center';
$handler->display->display_options['fields']['cost_center']['relationship'] = 'hrjc_role';
$handler->display->display_options['fields']['cost_center']['label'] = 'Cost center';
/* Field: HRJobContract Role entity: Location */
$handler->display->display_options['fields']['location_1']['id'] = 'location_1';
$handler->display->display_options['fields']['location_1']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['location_1']['field'] = 'location';
$handler->display->display_options['fields']['location_1']['relationship'] = 'hrjc_role';
$handler->display->display_options['fields']['location_1']['label'] = 'Role location';
/* Field: HRJobContract Role entity: Start_date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['start_date']['field'] = 'start_date';
$handler->display->display_options['fields']['start_date']['relationship'] = 'hrjc_role';
$handler->display->display_options['fields']['start_date']['label'] = 'Role start date';
/* Field: HRJobContract Role entity: End_date */
$handler->display->display_options['fields']['end_date']['id'] = 'end_date';
$handler->display->display_options['fields']['end_date']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['end_date']['field'] = 'end_date';
$handler->display->display_options['fields']['end_date']['relationship'] = 'hrjc_role';
$handler->display->display_options['fields']['end_date']['label'] = 'Role end date';
/* Sort criterion: HRJobContract Details entity: Jobcontract_id */
$handler->display->display_options['sorts']['jobcontract_id']['id'] = 'jobcontract_id';
$handler->display->display_options['sorts']['jobcontract_id']['table'] = 'hrjc_details';
$handler->display->display_options['sorts']['jobcontract_id']['field'] = 'jobcontract_id';
$handler->display->display_options['sorts']['jobcontract_id']['relationship'] = 'hrjc_details';
$handler->display->display_options['sorts']['jobcontract_id']['order'] = 'DESC';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_json';
$handler->display->display_options['style_options']['root_object'] = '';
$handler->display->display_options['style_options']['top_child_object'] = '';
$handler->display->display_options['style_options']['plaintext_output'] = 1;
$handler->display->display_options['style_options']['remove_newlines'] = 0;
$handler->display->display_options['style_options']['jsonp_prefix'] = '';
$handler->display->display_options['style_options']['using_views_api_mode'] = 0;
$handler->display->display_options['style_options']['object_arrays'] = 0;
$handler->display->display_options['style_options']['numeric_strings'] = 0;
$handler->display->display_options['style_options']['bigint_string'] = 0;
$handler->display->display_options['style_options']['pretty_print'] = 0;
$handler->display->display_options['style_options']['unescaped_slashes'] = 0;
$handler->display->display_options['style_options']['unescaped_unicode'] = 0;
$handler->display->display_options['style_options']['char_encoding'] = array();
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['path'] = 'civihr-report---people';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'civihr_report_people_table');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'age_group' => 'age_group',
  'gender' => 'gender',
  'contract_type' => 'contract_type',
  'location' => 'location',
  'location_standard_hours' => 'location_standard_hours',
  'hours_type' => 'hours_type',
  'is_paid' => 'is_paid',
  'pay_scale' => 'pay_scale',
  'is_enrolled' => 'is_enrolled',
  'period_start_date' => 'period_start_date',
  'period_end_date' => 'period_end_date',
  'region' => 'region',
  'department' => 'department',
  'level_type' => 'level_type',
  'cost_center' => 'cost_center',
  'location_1' => 'location_1',
  'start_date' => 'start_date',
  'end_date' => 'end_date',
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
  'age_group' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'gender' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'contract_type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'location' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'location_standard_hours' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'hours_type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'is_paid' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'pay_scale' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'is_enrolled' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'period_start_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'period_end_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'region' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'department' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'level_type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'cost_center' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'location_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'start_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'end_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$translatables['civihr_report_people'] = array(
  t('Master'),
  t('CiviHR Report - People'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('HRJobContract Details entity'),
  t('HRJobContract Health entity'),
  t('HRJobContract Hour entity'),
  t('HRJobContract Leave entity'),
  t('HRJobContract Pay entity'),
  t('HRJobContract Pension entity'),
  t('HRJobContract Role entity'),
  t('Contact ID'),
  t('.'),
  t(','),
  t('First name'),
  t('Last name'),
  t('Age'),
  t('Gender'),
  t('Contract type'),
  t('Location'),
  t('Location_standard_hours'),
  t('Hours type'),
  t('Is paid'),
  t('Pay scale'),
  t('Is enrolled'),
  t('Period start date'),
  t('Period end date'),
  t('Region'),
  t('Department'),
  t('Level type'),
  t('Cost center'),
  t('Role location'),
  t('Role start date'),
  t('Role end date'),
  t('Page'),
  t('Block'),
);
