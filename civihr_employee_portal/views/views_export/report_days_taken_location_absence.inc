<?php

/**
 * Exported view absence_reports_days_taken_location report
 */

$view = new view();
$view->name = 'absence_reports_days_taken_location';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'absence_list';
$view->human_name = 'Absence Reports / Days Taken - Location';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Absence Reports / Days Taken - Location(sum)';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
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
/* Relationship: Absence entity: Contact_id */
$handler->display->display_options['relationships']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['relationships']['contact_id']['table'] = 'absence_list';
$handler->display->display_options['relationships']['contact_id']['field'] = 'contact_id';
/* Relationship: CiviCRM Contacts: HRJobContract Role entity */
$handler->display->display_options['relationships']['hrjc_role']['id'] = 'hrjc_role';
$handler->display->display_options['relationships']['hrjc_role']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_role']['field'] = 'hrjc_role';
$handler->display->display_options['relationships']['hrjc_role']['relationship'] = 'contact_id';
/* Field: Absence entity: Absence entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'absence_list';
$handler->display->display_options['fields']['id']['field'] = 'id';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Absence entity: Absence entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'absence_list';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'absence_entity_id';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Absence entity: Absence_title */
$handler->display->display_options['fields']['absence_title']['id'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_title']['field'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['label'] = 'gender';
/* Field: HRJobContract Role entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['fields']['location']['relationship'] = 'hrjc_role';
$handler->display->display_options['fields']['location']['label'] = 'department';
/* Field: Absence entity: Absence type row value (Duration) */
$handler->display->display_options['fields']['duration']['id'] = 'duration';
$handler->display->display_options['fields']['duration']['table'] = 'absence_list';
$handler->display->display_options['fields']['duration']['field'] = 'duration';
$handler->display->display_options['fields']['duration']['label'] = 'count';
$handler->display->display_options['fields']['duration']['duration_type'] = 'no_format';
/* Field: Absence entity: Absence_start_date */
$handler->display->display_options['fields']['absence_start_date']['id'] = 'absence_start_date';
$handler->display->display_options['fields']['absence_start_date']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_start_date']['field'] = 'absence_start_date';
/* Field: Absence entity: Absence_end_date */
$handler->display->display_options['fields']['absence_end_date']['id'] = 'absence_end_date';
$handler->display->display_options['fields']['absence_end_date']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_end_date']['field'] = 'absence_end_date';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Absence entity: Absence_start_date */
$handler->display->display_options['arguments']['absence_start_date']['id'] = 'absence_start_date';
$handler->display->display_options['arguments']['absence_start_date']['table'] = 'absence_list';
$handler->display->display_options['arguments']['absence_start_date']['field'] = 'absence_start_date';
$handler->display->display_options['arguments']['absence_start_date']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['absence_start_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['absence_start_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['absence_start_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['absence_start_date']['civihr_range'] = '>=';
$handler->display->display_options['arguments']['absence_start_date']['civihr_range_empty'] = '1';
/* Contextual filter: Absence entity: Absence_end_date */
$handler->display->display_options['arguments']['absence_end_date']['id'] = 'absence_end_date';
$handler->display->display_options['arguments']['absence_end_date']['table'] = 'absence_list';
$handler->display->display_options['arguments']['absence_end_date']['field'] = 'absence_end_date';
$handler->display->display_options['arguments']['absence_end_date']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['absence_end_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['absence_end_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['absence_end_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['absence_end_date']['civihr_range'] = '<=';
$handler->display->display_options['arguments']['absence_end_date']['civihr_range_empty'] = '1';
$handler->display->display_options['path'] = 'civihr_reports_absence_days_taken-location';
$translatables['absence_reports_days_taken_location'] = array(
    t('Master'),
    t('Absence Reports / Days Taken - Location(sum)'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('CiviCRM Contact'),
    t('HRJobContract Role entity'),
    t('Absence entity ID'),
    t('.'),
    t(','),
    t('Page'),
    t('absence_entity_id'),
    t('gender'),
    t('department'),
    t('count'),
    t('Absence_start_date'),
    t('Absence_end_date'),
    t('All'),
);