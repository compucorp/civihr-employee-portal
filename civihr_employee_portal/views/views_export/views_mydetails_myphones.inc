<?php

$view = new view();
$view->name = 'mydetails_myphones';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'MyDetails_MyPhones';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view my details';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'phone_ext' => 'phone_ext',
  'phone' => 'phone',
);
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
/* Relationship: CiviCRM Phone Details: Phone */
$handler->display->display_options['relationships']['id']['id'] = 'id';
$handler->display->display_options['relationships']['id']['table'] = 'civicrm_phone';
$handler->display->display_options['relationships']['id']['field'] = 'id';
$handler->display->display_options['relationships']['id']['label'] = 'Phone';
$handler->display->display_options['relationships']['id']['required'] = TRUE;
$handler->display->display_options['relationships']['id']['location_type'] = '0';
$handler->display->display_options['relationships']['id']['location_op'] = '0';
$handler->display->display_options['relationships']['id']['is_primary'] = 0;
$handler->display->display_options['relationships']['id']['phone_type'] = '0';
/* Field: CiviCRM Phone Details: Location Type */
$handler->display->display_options['fields']['location_type']['id'] = 'location_type';
$handler->display->display_options['fields']['location_type']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['location_type']['field'] = 'location_type';
$handler->display->display_options['fields']['location_type']['relationship'] = 'id';
$handler->display->display_options['fields']['location_type']['label'] = '';
$handler->display->display_options['fields']['location_type']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['location_type']['alter']['text'] = '[location_type] phone number';
$handler->display->display_options['fields']['location_type']['element_label_colon'] = FALSE;
/* Field: CiviCRM Phone Details: Phone Number Extension */
$handler->display->display_options['fields']['phone_ext']['id'] = 'phone_ext';
$handler->display->display_options['fields']['phone_ext']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone_ext']['field'] = 'phone_ext';
$handler->display->display_options['fields']['phone_ext']['relationship'] = 'id';
$handler->display->display_options['fields']['phone_ext']['label'] = '';
$handler->display->display_options['fields']['phone_ext']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['phone_ext']['location_type'] = '0';
$handler->display->display_options['fields']['phone_ext']['location_op'] = '0';
$handler->display->display_options['fields']['phone_ext']['is_primary'] = 0;
$handler->display->display_options['fields']['phone_ext']['phone_type'] = '0';
/* Field: CiviCRM Phone Details: Phone */
$handler->display->display_options['fields']['phone']['id'] = 'phone';
$handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone']['field'] = 'phone';
$handler->display->display_options['fields']['phone']['relationship'] = 'id';
$handler->display->display_options['fields']['phone']['label'] = '';
$handler->display->display_options['fields']['phone']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['phone']['location_type'] = '0';
$handler->display->display_options['fields']['phone']['location_op'] = '0';
$handler->display->display_options['fields']['phone']['is_primary'] = 0;
$handler->display->display_options['fields']['phone']['phone_type'] = '0';
/* Sort criterion: CiviCRM Phone Details: Phone Location Type */
$handler->display->display_options['sorts']['location_type_id']['id'] = 'location_type_id';
$handler->display->display_options['sorts']['location_type_id']['table'] = 'civicrm_phone';
$handler->display->display_options['sorts']['location_type_id']['field'] = 'location_type_id';
$handler->display->display_options['sorts']['location_type_id']['relationship'] = 'id';
/* Contextual filter: CiviCRM Contacts: Contact ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'default';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['id']['default_argument_options']['code'] = 'return CRM_Core_Session::singleton()->getLoggedInContactID();';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
$translatables['mydetails_myphones'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Phone'),
  t('[location_type] phone number'),
  t('All'),
);
