<?php

$view = new view();
$view->name = 'mydetails_notifications__my_contact_info_emails';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'mydetails_notifications__my_contact_info_emails';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Contact Info - Emails';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Field: CiviCRM Email: Email Address */
$handler->display->display_options['fields']['email']['id'] = 'email';
$handler->display->display_options['fields']['email']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['email']['field'] = 'email';
$handler->display->display_options['fields']['email']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['email']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['email']['alter']['text'] = '[email] - !2';
$handler->display->display_options['fields']['email']['location_type'] = '0';
$handler->display->display_options['fields']['email']['location_op'] = '1';
$handler->display->display_options['fields']['email']['is_primary'] = 0;
/* Contextual filter: CiviCRM Email: Email Location Type */
$handler->display->display_options['arguments']['location_type_id']['id'] = 'location_type_id';
$handler->display->display_options['arguments']['location_type_id']['table'] = 'civicrm_email';
$handler->display->display_options['arguments']['location_type_id']['field'] = 'location_type_id';
$handler->display->display_options['arguments']['location_type_id']['relationship'] = 'drupal_id';
$handler->display->display_options['arguments']['location_type_id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['location_type_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['location_type_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['location_type_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['location_type_id']['summary_options']['items_per_page'] = '25';
/* Contextual filter: Global: Null */
$handler->display->display_options['arguments']['null']['id'] = 'null';
$handler->display->display_options['arguments']['null']['table'] = 'views';
$handler->display->display_options['arguments']['null']['field'] = 'null';
$handler->display->display_options['arguments']['null']['default_action'] = 'not found';
$handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
/* Contextual filter: CiviCRM Drupal match table: Drupal User ID */
$handler->display->display_options['arguments']['uf_id']['id'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['table'] = 'civicrm_uf_match';
$handler->display->display_options['arguments']['uf_id']['field'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['uf_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uf_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uf_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uf_id']['summary_options']['items_per_page'] = '25';
$translatables['mydetails_notifications__my_contact_info_emails'] = array(
  t('Master'),
  t('Contact Info - Emails'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Drupal User'),
  t('Email Address'),
  t('[email] - !2'),
  t('All'),
);
