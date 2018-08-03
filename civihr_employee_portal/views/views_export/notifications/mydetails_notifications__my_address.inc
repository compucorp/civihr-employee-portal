<?php

$view = new view();
$view->name = 'mydetails_notifications__my_address';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'mydetails_notifications__my_address';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Home Address';
$handler->display->display_options['css_class'] = 'chr_panel--my-details__view__panel';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view my details';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
/* Relationship: CiviCRM Address: Address */
$handler->display->display_options['relationships']['id']['id'] = 'id';
$handler->display->display_options['relationships']['id']['table'] = 'civicrm_address';
$handler->display->display_options['relationships']['id']['field'] = 'id';
$handler->display->display_options['relationships']['id']['relationship'] = 'drupal_id';
$handler->display->display_options['relationships']['id']['label'] = 'Address';
$handler->display->display_options['relationships']['id']['location_type'] = '0';
$handler->display->display_options['relationships']['id']['location_op'] = '0';
$handler->display->display_options['relationships']['id']['is_primary'] = 0;
/* Field: CiviCRM Address: City / Suburb */
$handler->display->display_options['fields']['city']['id'] = 'city';
$handler->display->display_options['fields']['city']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['city']['field'] = 'city';
$handler->display->display_options['fields']['city']['relationship'] = 'id';
$handler->display->display_options['fields']['city']['location_type'] = '0';
$handler->display->display_options['fields']['city']['location_op'] = '0';
$handler->display->display_options['fields']['city']['is_primary'] = 0;
/* Field: CiviCRM Address: Postal Code */
$handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['relationship'] = 'id';
$handler->display->display_options['fields']['postal_code']['location_type'] = '0';
$handler->display->display_options['fields']['postal_code']['location_op'] = '0';
$handler->display->display_options['fields']['postal_code']['is_primary'] = 0;
/* Field: CiviCRM Address: State/Province */
$handler->display->display_options['fields']['state_province']['id'] = 'state_province';
$handler->display->display_options['fields']['state_province']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['state_province']['field'] = 'state_province';
$handler->display->display_options['fields']['state_province']['relationship'] = 'id';
$handler->display->display_options['fields']['state_province']['location_type'] = '0';
$handler->display->display_options['fields']['state_province']['location_op'] = '0';
$handler->display->display_options['fields']['state_province']['is_primary'] = 0;
/* Field: CiviCRM Address: Country */
$handler->display->display_options['fields']['country']['id'] = 'country';
$handler->display->display_options['fields']['country']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['country']['field'] = 'country';
$handler->display->display_options['fields']['country']['relationship'] = 'id';
$handler->display->display_options['fields']['country']['location_type'] = '0';
$handler->display->display_options['fields']['country']['location_op'] = '0';
$handler->display->display_options['fields']['country']['is_primary'] = 0;
/* Contextual filter: CiviCRM Address: Location Type */
$handler->display->display_options['arguments']['location_type']['id'] = 'location_type';
$handler->display->display_options['arguments']['location_type']['table'] = 'civicrm_address';
$handler->display->display_options['arguments']['location_type']['field'] = 'location_type';
$handler->display->display_options['arguments']['location_type']['relationship'] = 'id';
$handler->display->display_options['arguments']['location_type']['default_action'] = 'not found';
$handler->display->display_options['arguments']['location_type']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['location_type']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['location_type']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['location_type']['summary_options']['items_per_page'] = '25';
/* Contextual filter: User: Uid */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'users';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['relationship'] = 'drupal_id';
$handler->display->display_options['arguments']['uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
$translatables['mydetails_notifications__my_address'] = array(
  t('Master'),
  t('Home Address'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Drupal User'),
  t('Address'),
  t('City / Suburb'),
  t('Postal Code'),
  t('State/Province'),
  t('Country'),
  t('All'),
);
