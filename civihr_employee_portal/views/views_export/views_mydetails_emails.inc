<?php

$view = new view();
$view->name = 'mydetails_emails';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'MyDetails_Emails';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: CiviCRM Email: Email Address */
$handler->display->display_options['relationships']['id']['id'] = 'id';
$handler->display->display_options['relationships']['id']['table'] = 'civicrm_email';
$handler->display->display_options['relationships']['id']['field'] = 'id';
$handler->display->display_options['relationships']['id']['label'] = 'Email Address';
$handler->display->display_options['relationships']['id']['required'] = TRUE;
$handler->display->display_options['relationships']['id']['location_type'] = '0';
$handler->display->display_options['relationships']['id']['location_op'] = '0';
$handler->display->display_options['relationships']['id']['is_primary'] = 0;
/* Field: CiviCRM Email: Location Type */
$handler->display->display_options['fields']['location_type']['id'] = 'location_type';
$handler->display->display_options['fields']['location_type']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['location_type']['field'] = 'location_type';
$handler->display->display_options['fields']['location_type']['relationship'] = 'id';
$handler->display->display_options['fields']['location_type']['label'] = '';
$handler->display->display_options['fields']['location_type']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['location_type']['alter']['text'] = '[location_type] Email';
$handler->display->display_options['fields']['location_type']['element_label_colon'] = FALSE;
/* Field: CiviCRM Email: Email Address */
$handler->display->display_options['fields']['email']['id'] = 'email';
$handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['email']['field'] = 'email';
$handler->display->display_options['fields']['email']['relationship'] = 'id';
$handler->display->display_options['fields']['email']['label'] = '';
$handler->display->display_options['fields']['email']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['email']['alter']['text'] = '<a href="mailto:[email] ">[email] </a>';
$handler->display->display_options['fields']['email']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['email']['location_type'] = '0';
$handler->display->display_options['fields']['email']['location_op'] = '0';
$handler->display->display_options['fields']['email']['is_primary'] = 0;
$handler->display->display_options['fields']['email']['link_to_user'] = '0';
/* Sort criterion: CiviCRM Email: Email Location Type */
$handler->display->display_options['sorts']['location_type_id']['id'] = 'location_type_id';
$handler->display->display_options['sorts']['location_type_id']['table'] = 'civicrm_email';
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
$translatables['mydetails_emails'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Email Address'),
  t('[location_type] Email'),
  t('<a href="mailto:[email] ">[email] </a>'),
  t('All'),
);
