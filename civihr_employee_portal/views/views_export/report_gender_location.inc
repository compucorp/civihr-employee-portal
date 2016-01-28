<?php

/**
 * Exported view gender_location report
 */

$view = new view();
$view->name = 'gender_location';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'hrjc_role';
$view->human_name = 'Gender / Location';
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

/* Display: Gender / Location (count) */
$handler = $view->new_display('page', 'Gender / Location (count)', 'page');
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
/* Field: CiviCRM Contacts: Gender */
$handler->display->display_options['fields']['gender']['id'] = 'gender';
$handler->display->display_options['fields']['gender']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['gender']['field'] = 'gender';
$handler->display->display_options['fields']['gender']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['gender']['label'] = 'gender';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['relationship'] = 'contact_id';
$handler->display->display_options['fields']['id']['label'] = 'contact_id';
$handler->display->display_options['fields']['id']['separator'] = '';
$handler->display->display_options['defaults']['sorts'] = FALSE;
$handler->display->display_options['path'] = 'civihr_reports_gender-location';

/* Display: Filter by Location */
$handler = $view->new_display('block', 'Filter by Location', 'filter_gender_location');
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
$handler->display->display_options['arguments']['location']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['location']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['location']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['location']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['location']['limit'] = '0';
/* Contextual filter: CiviCRM Contacts: Gender */
$handler->display->display_options['arguments']['gender']['id'] = 'gender';
$handler->display->display_options['arguments']['gender']['table'] = 'civicrm_contact';
$handler->display->display_options['arguments']['gender']['field'] = 'gender';
$handler->display->display_options['arguments']['gender']['relationship'] = 'contact_id';
$handler->display->display_options['arguments']['gender']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['gender']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['gender']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['gender']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;

/* Display: CSV data export */
$handler = $view->new_display('views_data_export', 'CSV data export', 'gender_location_export');
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
$handler->display->display_options['arguments']['location']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['location']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['location']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['location']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['location']['limit'] = '0';
$handler->display->display_options['path'] = 'gender-location-export';
$handler->display->display_options['displays'] = array(
  'filter_gender_location' => 'filter_gender_location',
  'default' => 0,
  'page' => 0,
);
$translatables['gender_location'] = array(
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
  t('department'),
  t('count'),
  t('Gender / Location (count)'),
  t('gender'),
  t('contact_id'),
  t('.'),
  t('Filter by Location'),
  t('Contact_id'),
  t('Location'),
  t('All'),
  t('CSV data export'),
);
