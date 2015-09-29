<?php

/**
 * Exported view age_location report
 */

$view = new view();
$view->name = 'age_location';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'hrjc_role';
$view->human_name = 'Age / Location';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Gender / Filter by Location';
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
/* Relationship: HRJobContract Role entity: Contact_id */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'hrjc_role';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
/* Relationship: CiviCRM Contacts: HRJobContract Role entity */
$handler->display->display_options['relationships']['hrjc_role']['id'] = 'hrjc_role';
$handler->display->display_options['relationships']['hrjc_role']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_role']['field'] = 'hrjc_role';
$handler->display->display_options['relationships']['hrjc_role']['relationship'] = 'contact_id';
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

/* Display: Age / Location (count) */
$handler = $view->new_display('page', 'Age / Location (count)', 'page');
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: HRJobContract Role entity: Contact_id */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'hrjc_role';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: HRJobContract Role entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['fields']['location']['label'] = 'department';
/* Field: CiviCRM Contacts: Birth Date */
$handler->display->display_options['fields']['birth_date']['id'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['birth_date']['field'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['birth_date']['label'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['birth_date']['custom_date_format'] = 'Y-m-d';
$handler->display->display_options['fields']['birth_date']['second_date_format'] = 'long';
/* Field: CiviCRM Contacts: Age Group */
$handler->display->display_options['fields']['age_group']['id'] = 'age_group';
$handler->display->display_options['fields']['age_group']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['age_group']['field'] = 'age_group';
$handler->display->display_options['fields']['age_group']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['age_group']['label'] = 'gender';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['id']['label'] = 'contact_id';
$handler->display->display_options['fields']['id']['separator'] = '';
$handler->display->display_options['defaults']['sorts'] = FALSE;
$handler->display->display_options['path'] = 'age-location';

/* Display: Filter by Age */
$handler = $view->new_display('block', 'Filter by Age', 'filter_age_location');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Gender / Filter by Location';
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
'location' => 'location',
'views_bulk_operations' => 'views_bulk_operations',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
'department_1' => array(
'sortable' => 0,
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
'location' => array(
'sortable' => 0,
'default_sort_order' => 'asc',
'align' => '',
'separator' => '',
'empty_column' => 0,
),
'views_bulk_operations' => array(
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
/* Field: CiviCRM Contacts: Birth Date */
$handler->display->display_options['fields']['birth_date']['id'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['birth_date']['field'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['birth_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['birth_date']['custom_date_format'] = 'Y-m-d';
$handler->display->display_options['fields']['birth_date']['second_date_format'] = 'long';
/* Field: CiviCRM Contacts: Age Group */
$handler->display->display_options['fields']['age_group']['id'] = 'age_group';
$handler->display->display_options['fields']['age_group']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['age_group']['field'] = 'age_group';
$handler->display->display_options['fields']['age_group']['relationship'] = 'contact_id';
/* Field: HRJobContract Role entity: Department */
$handler->display->display_options['fields']['department_1']['id'] = 'department_1';
$handler->display->display_options['fields']['department_1']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['department_1']['field'] = 'department';
$handler->display->display_options['fields']['department_1']['label'] = 'department';
/* Field: HRJobContract Role entity: Contact_id */
$handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['label'] = 'Contact ID';
$handler->display->display_options['fields']['contact_id']['separator'] = '';
/* Field: HRJobContract Role entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['location']['field'] = 'location';
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
/* Contextual filter: HRJobContract Role entity: Location */
$handler->display->display_options['arguments']['location']['id'] = 'location';
$handler->display->display_options['arguments']['location']['table'] = 'hrjc_role';
$handler->display->display_options['arguments']['location']['field'] = 'location';
$handler->display->display_options['arguments']['location']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['location']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['location']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['location']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['location']['limit'] = '0';
/* Contextual filter: CiviCRM Contacts: Age Group */
$handler->display->display_options['arguments']['age_group']['id'] = 'age_group';
$handler->display->display_options['arguments']['age_group']['table'] = 'civicrm_contact';
$handler->display->display_options['arguments']['age_group']['field'] = 'age_group';
$handler->display->display_options['arguments']['age_group']['relationship'] = 'contact_id';
$handler->display->display_options['arguments']['age_group']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['age_group']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['age_group']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['age_group']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
$handler->display->display_options['merge_rows'] = TRUE;
$handler->display->display_options['field_config'] = array(
'birth_date' => array(
'merge_option' => 'merge_unique',
'separator' => ', ',
),
'age_group' => array(
'merge_option' => 'merge_unique',
'separator' => ', ',
),
'department_1' => array(
'merge_option' => 'merge_unique',
'separator' => ', ',
),
'contact_id' => array(
'merge_option' => 'filter',
'separator' => ', ',
),
'location' => array(
'merge_option' => 'merge_unique',
'separator' => ', ',
),
'views_bulk_operations' => array(
'merge_option' => 'merge_unique',
'separator' => '',
),
);

/* Display: CSV data export */
$handler = $view->new_display('views_data_export', 'CSV data export', 'age_location_export');
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: HRJobContract Role entity: Contact_id */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'hrjc_role';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
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
/* Field: CiviCRM Address: Country */
$handler->display->display_options['fields']['country']['id'] = 'country';
$handler->display->display_options['fields']['country']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['country']['field'] = 'country';
$handler->display->display_options['fields']['country']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['country']['location_type'] = '0';
$handler->display->display_options['fields']['country']['location_op'] = '0';
$handler->display->display_options['fields']['country']['is_primary'] = 0;
$handler->display->display_options['fields']['country']['is_billing'] = 0;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: HRJobContract Role entity: Location */
$handler->display->display_options['arguments']['location']['id'] = 'location';
$handler->display->display_options['arguments']['location']['table'] = 'hrjc_role';
$handler->display->display_options['arguments']['location']['field'] = 'location';
$handler->display->display_options['arguments']['location']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['location']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['location']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['location']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['location']['limit'] = '0';
$handler->display->display_options['path'] = 'age-location-export';
$handler->display->display_options['displays'] = array(
'filter_age_location' => 'filter_age_location',
'default' => 0,
'page' => 0,
);
$translatables['age_location'] = array(
t('Master'),
t('Gender / Filter by Location'),
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
t('CiviCRM Contact'),
t('HRJobContract Role entity'),
t('department'),
t('count'),
t('Age / Location (count)'),
t('birth_date'),
t('gender'),
t('contact_id'),
t('.'),
t('Filter by Age'),
t('Birth Date'),
t('Age Group'),
t('Contact ID'),
t('Location'),
t('- Choose an operation -'),
t('CSV'),
t('All'),
t('CSV data export'),
t('Contact_id'),
t('Country'),
);