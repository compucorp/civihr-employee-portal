<?php

/**
 * Exported view fte_all report
 */

$view = new view();
$view->name = 'fte_all';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'hrjc_role';
$view->human_name = 'FTE / All';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Headcount / Filter by Location';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'views_json';
$handler->display->display_options['style_options']['root_object'] = 'results';
$handler->display->display_options['style_options']['top_child_object'] = 'data';
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
/* Field: HRJobContract Role entity: Department */
$handler->display->display_options['fields']['department_1']['id'] = 'department_1';
$handler->display->display_options['fields']['department_1']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['department_1']['field'] = 'department';
$handler->display->display_options['fields']['department_1']['label'] = 'department';
/* Field: COUNT(HRJobContract Role entity: Department) */
$handler->display->display_options['fields']['department']['id'] = 'department';
$handler->display->display_options['fields']['department']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['department']['field'] = 'department';
$handler->display->display_options['fields']['department']['group_type'] = 'count';
$handler->display->display_options['fields']['department']['label'] = 'count';
$handler->display->display_options['fields']['department']['separator'] = '';
/* Contextual filter: HRJobContract Details entity: Period_start_date */
$handler->display->display_options['arguments']['period_start_date']['id'] = 'period_start_date';
$handler->display->display_options['arguments']['period_start_date']['table'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_start_date']['field'] = 'period_start_date';
$handler->display->display_options['arguments']['period_start_date']['relationship'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_start_date']['exception']['value'] = 'All';
$handler->display->display_options['arguments']['period_start_date']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['period_start_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['period_start_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['period_start_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['period_start_date']['civihr_range'] = '=';

/* Display: FTE / All (sum) */
$handler = $view->new_display('page', 'FTE / All (sum)', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'FTE / Filter by All';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: HRJobContract Role entity: Contact_id */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'hrjc_role';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
/* Relationship: CiviCRM Contacts: HRJobContract Hour entity */
$handler->display->display_options['relationships']['hrjc_hour']['id'] = 'hrjc_hour';
$handler->display->display_options['relationships']['hrjc_hour']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_hour']['field'] = 'hrjc_hour';
$handler->display->display_options['relationships']['hrjc_hour']['relationship'] = 'contact_id';
/* Relationship: CiviCRM Contacts: HRJobContract Details entity */
$handler->display->display_options['relationships']['hrjc_details']['id'] = 'hrjc_details';
$handler->display->display_options['relationships']['hrjc_details']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_details']['field'] = 'hrjc_details';
$handler->display->display_options['relationships']['hrjc_details']['relationship'] = 'contact_id';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'department';
$handler->display->display_options['fields']['nothing']['alter']['text'] = 'All';
/* Field: SUM(HRJobContract Hour entity: Hours_fte) */
$handler->display->display_options['fields']['hours_fte']['id'] = 'hours_fte';
$handler->display->display_options['fields']['hours_fte']['table'] = 'hrjc_hour';
$handler->display->display_options['fields']['hours_fte']['field'] = 'hours_fte';
$handler->display->display_options['fields']['hours_fte']['relationship'] = 'hrjc_hour';
$handler->display->display_options['fields']['hours_fte']['group_type'] = 'sum';
$handler->display->display_options['fields']['hours_fte']['label'] = 'count';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: HRJobContract Details entity: Period_start_date */
$handler->display->display_options['arguments']['period_start_date']['id'] = 'period_start_date';
$handler->display->display_options['arguments']['period_start_date']['table'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_start_date']['field'] = 'period_start_date';
$handler->display->display_options['arguments']['period_start_date']['relationship'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_start_date']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['period_start_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['period_start_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['period_start_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['period_start_date']['civihr_range'] = '<=';
$handler->display->display_options['arguments']['period_start_date']['civihr_range_empty'] = '0';
/* Contextual filter: HRJobContract Details entity: Period_end_date */
$handler->display->display_options['arguments']['period_end_date']['id'] = 'period_end_date';
$handler->display->display_options['arguments']['period_end_date']['table'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_end_date']['field'] = 'period_end_date';
$handler->display->display_options['arguments']['period_end_date']['relationship'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_end_date']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['period_end_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['period_end_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['period_end_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['period_end_date']['civihr_range'] = '>=';
$handler->display->display_options['arguments']['period_end_date']['civihr_range_empty'] = '1';
$handler->display->display_options['path'] = 'fte-all';

/* Display: Filter by All */
$handler = $view->new_display('block', 'Filter by All', 'filter_fte_all');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'FTE / Filter by All';
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '2';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
    'department_1' => 'department_1',
    'contact_id' => 'contact_id',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
    'department_1' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
    ),
    'contact_id' => array(
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
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: HRJobContract Role entity: Department */
$handler->display->display_options['fields']['department_1']['id'] = 'department_1';
$handler->display->display_options['fields']['department_1']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['department_1']['field'] = 'department';
$handler->display->display_options['fields']['department_1']['label'] = 'department';
/* Field: HRJobContract Role entity: Contact_id */
$handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['separator'] = '';
/* Field: HRJobContract Role entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: HRJobContract Role entity: Location */
$handler->display->display_options['arguments']['location']['id'] = 'location';
$handler->display->display_options['arguments']['location']['table'] = 'hrjc_role';
$handler->display->display_options['arguments']['location']['field'] = 'location';
$handler->display->display_options['arguments']['location']['exception']['value'] = 'All';
$handler->display->display_options['arguments']['location']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['location']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['location']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['location']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['location']['limit'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;

/* Display: CSV data export */
$handler = $view->new_display('views_data_export', 'CSV data export', 'headcount_all_export');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'FTE / Filter by All';
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: HRJobContract Role entity: Department */
$handler->display->display_options['fields']['department_1']['id'] = 'department_1';
$handler->display->display_options['fields']['department_1']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['department_1']['field'] = 'department';
$handler->display->display_options['fields']['department_1']['label'] = 'department';
/* Field: HRJobContract Role entity: Contact_id */
$handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['separator'] = '';
/* Field: HRJobContract Role entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: HRJobContract Role entity: Location */
$handler->display->display_options['arguments']['location']['id'] = 'location';
$handler->display->display_options['arguments']['location']['table'] = 'hrjc_role';
$handler->display->display_options['arguments']['location']['field'] = 'location';
$handler->display->display_options['arguments']['location']['exception']['value'] = 'All';
$handler->display->display_options['arguments']['location']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['location']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['location']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['location']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['location']['limit'] = '0';
$handler->display->display_options['path'] = 'fte-all-export';
$handler->display->display_options['displays'] = array(
    'filter_fte_all' => 'filter_fte_all',
    'default' => 0,
    'page' => 0,
);
$handler->display->display_options['sitename_title'] = 0;
$translatables['fte_all'] = array(
    t('Master'),
    t('Headcount / Filter by Location'),
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
    t('department'),
    t('count'),
    t('All'),
    t('FTE / All (sum)'),
    t('FTE / Filter by All'),
    t('CiviCRM Contact'),
    t('HRJobContract Hour entity'),
    t('HRJobContract Details entity'),
    t('Filter by All'),
    t('Contact_id'),
    t('.'),
    t('Location'),
    t('CSV data export'),
);