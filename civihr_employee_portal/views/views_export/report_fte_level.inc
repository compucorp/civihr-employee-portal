<?php

/**
 * Exported view fte_level report
 */

$view = new view();
$view->name = 'fte_level';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'hrjc_role';
$view->human_name = 'FTE / Level';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Headcount / Filter by Level';
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

/* Display: FTE / Level (sum) */
$handler = $view->new_display('page', 'FTE / Level (sum)', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'FTE / Filter by Level';
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
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: HRJobContract Role entity: Level_type */
$handler->display->display_options['fields']['level_type']['id'] = 'level_type';
$handler->display->display_options['fields']['level_type']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['level_type']['field'] = 'level_type';
$handler->display->display_options['fields']['level_type']['label'] = 'department';
/* Field: SUM(HRJobContract Hour entity: Hours_fte) */
$handler->display->display_options['fields']['hours_fte']['id'] = 'hours_fte';
$handler->display->display_options['fields']['hours_fte']['table'] = 'hrjc_hour';
$handler->display->display_options['fields']['hours_fte']['field'] = 'hours_fte';
$handler->display->display_options['fields']['hours_fte']['relationship'] = 'hrjc_hour';
$handler->display->display_options['fields']['hours_fte']['group_type'] = 'sum';
$handler->display->display_options['fields']['hours_fte']['label'] = 'count';
$handler->display->display_options['path'] = 'civihr_reports_fte-level';

/* Display: Filter by Level */
$handler = $view->new_display('block', 'Filter by Level', 'filter_fte_level');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'FTE / Filter by Level';
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
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: HRJobContract Role entity: Contact_id */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'hrjc_role';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: HRJobContract Role entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['location']['field'] = 'location';
/* Field: HRJobContract Role entity: Level_type */
$handler->display->display_options['fields']['level_type']['id'] = 'level_type';
$handler->display->display_options['fields']['level_type']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['level_type']['field'] = 'level_type';
$handler->display->display_options['fields']['level_type']['label'] = 'Level type';
/* Field: Bulk operations: HRJobContract Role entity */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_data_export_action_csv_export' => array(
        'selected' => 1,
        'skip_confirmation' => 1,
        'override_label' => 1,
        'label' => 'CSV',
    ),
);
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: HRJobContract Role entity: Level_type */
$handler->display->display_options['arguments']['level_type']['id'] = 'level_type';
$handler->display->display_options['arguments']['level_type']['table'] = 'hrjc_role';
$handler->display->display_options['arguments']['level_type']['field'] = 'level_type';
$handler->display->display_options['arguments']['level_type']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['level_type']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['level_type']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['level_type']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['level_type']['limit'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;

/* Display: CSV data export */
$handler = $view->new_display('views_data_export', 'CSV data export', 'headcount_level_export');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'FTE / Filter by Level';
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: HRJobContract Role entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['location']['field'] = 'location';
/* Field: HRJobContract Role entity: Level_type */
$handler->display->display_options['fields']['level_type']['id'] = 'level_type';
$handler->display->display_options['fields']['level_type']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['level_type']['field'] = 'level_type';
$handler->display->display_options['fields']['level_type']['label'] = 'Level Type';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: HRJobContract Role entity: Level_type */
$handler->display->display_options['arguments']['level_type']['id'] = 'level_type';
$handler->display->display_options['arguments']['level_type']['table'] = 'hrjc_role';
$handler->display->display_options['arguments']['level_type']['field'] = 'level_type';
$handler->display->display_options['arguments']['level_type']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['level_type']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['level_type']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['level_type']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['level_type']['limit'] = '0';
$handler->display->display_options['path'] = 'fte-level-export';
$handler->display->display_options['displays'] = array(
    'filter_fte_location' => 'filter_fte_location',
    'default' => 0,
    'page' => 0,
);
$handler->display->display_options['sitename_title'] = 0;
$translatables['fte_level'] = array(
    t('Master'),
    t('Headcount / Filter by Level'),
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
    t('FTE / Level (sum)'),
    t('FTE / Filter by Level'),
    t('CiviCRM Contact'),
    t('HRJobContract Hour entity'),
    t('Filter by Level'),
    t('FTE / Filter by Level'),
    t('Display Name'),
    t('Location'),
    t('Level type'),
    t('HRJobContract Role entity'),
    t('- Choose an operation -'),
    t('CSV'),
    t('All'),
    t('CSV data export'),
    t('Level Type'),
);