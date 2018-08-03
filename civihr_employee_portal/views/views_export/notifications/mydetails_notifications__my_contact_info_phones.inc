<?php

$view = new view();
$view->name = 'mydetails_notifications__my_contact_info_phones';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'mydetails_notifications__my_contact_info_phones';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Contact Info - Phones';
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
/* Relationship: CiviCRM Phone Details: Phone */
$handler->display->display_options['relationships']['id']['id'] = 'id';
$handler->display->display_options['relationships']['id']['table'] = 'civicrm_phone';
$handler->display->display_options['relationships']['id']['field'] = 'id';
$handler->display->display_options['relationships']['id']['relationship'] = 'drupal_id';
$handler->display->display_options['relationships']['id']['label'] = 'Phone';
$handler->display->display_options['relationships']['id']['required'] = TRUE;
$handler->display->display_options['relationships']['id']['location_type'] = '0';
$handler->display->display_options['relationships']['id']['location_op'] = '0';
$handler->display->display_options['relationships']['id']['is_primary'] = 0;
$handler->display->display_options['relationships']['id']['phone_type'] = '0';
/* Field: CiviCRM Phone Details: Phone Number Extension */
$handler->display->display_options['fields']['phone_ext']['id'] = 'phone_ext';
$handler->display->display_options['fields']['phone_ext']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone_ext']['field'] = 'phone_ext';
$handler->display->display_options['fields']['phone_ext']['relationship'] = 'id';
$handler->display->display_options['fields']['phone_ext']['label'] = '';
$handler->display->display_options['fields']['phone_ext']['exclude'] = TRUE;
$handler->display->display_options['fields']['phone_ext']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['phone_ext']['alter']['text'] = '(ext. [phone_ext])';
$handler->display->display_options['fields']['phone_ext']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['phone_ext']['location_type'] = '0';
$handler->display->display_options['fields']['phone_ext']['location_op'] = '0';
$handler->display->display_options['fields']['phone_ext']['is_primary'] = 0;
$handler->display->display_options['fields']['phone_ext']['phone_type'] = '0';
/* Field: CiviCRM Phone Details: Location Type */
$handler->display->display_options['fields']['location_type']['id'] = 'location_type';
$handler->display->display_options['fields']['location_type']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['location_type']['field'] = 'location_type';
$handler->display->display_options['fields']['location_type']['relationship'] = 'id';
$handler->display->display_options['fields']['location_type']['label'] = '';
$handler->display->display_options['fields']['location_type']['exclude'] = TRUE;
$handler->display->display_options['fields']['location_type']['element_label_colon'] = FALSE;
/* Field: CiviCRM Phone Details: Phone */
$handler->display->display_options['fields']['phone']['id'] = 'phone';
$handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone']['field'] = 'phone';
$handler->display->display_options['fields']['phone']['relationship'] = 'id';
$handler->display->display_options['fields']['phone']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['phone']['alter']['text'] = '[phone] [phone_ext] - [location_type]';
$handler->display->display_options['fields']['phone']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['phone']['location_type'] = '0';
$handler->display->display_options['fields']['phone']['location_op'] = '0';
$handler->display->display_options['fields']['phone']['is_primary'] = 0;
$handler->display->display_options['fields']['phone']['phone_type'] = '0';
/* Contextual filter: CiviCRM Drupal match table: Drupal User ID */
$handler->display->display_options['arguments']['uf_id']['id'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['table'] = 'civicrm_uf_match';
$handler->display->display_options['arguments']['uf_id']['field'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['uf_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uf_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uf_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uf_id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: CiviCRM Phone Details: Location Type */
$handler->display->display_options['filters']['location_type']['id'] = 'location_type';
$handler->display->display_options['filters']['location_type']['table'] = 'civicrm_phone';
$handler->display->display_options['filters']['location_type']['field'] = 'location_type';
$handler->display->display_options['filters']['location_type']['relationship'] = 'id';
$handler->display->display_options['filters']['location_type']['exposed'] = TRUE;
$handler->display->display_options['filters']['location_type']['expose']['operator_id'] = 'location_type_op';
$handler->display->display_options['filters']['location_type']['expose']['label'] = 'Location Type';
$handler->display->display_options['filters']['location_type']['expose']['operator'] = 'location_type_op';
$handler->display->display_options['filters']['location_type']['expose']['identifier'] = 'location_type';
$handler->display->display_options['filters']['location_type']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  55120974 => 0,
  17087012 => 0,
  57573969 => 0,
  37588037 => 0,
);
/* Filter criterion: CiviCRM Phone Details: Phone Type */
$handler->display->display_options['filters']['phone_type']['id'] = 'phone_type';
$handler->display->display_options['filters']['phone_type']['table'] = 'civicrm_phone';
$handler->display->display_options['filters']['phone_type']['field'] = 'phone_type';
$handler->display->display_options['filters']['phone_type']['relationship'] = 'id';
$handler->display->display_options['filters']['phone_type']['exposed'] = TRUE;
$handler->display->display_options['filters']['phone_type']['expose']['operator_id'] = 'phone_type_op';
$handler->display->display_options['filters']['phone_type']['expose']['label'] = 'Phone Type';
$handler->display->display_options['filters']['phone_type']['expose']['operator'] = 'phone_type_op';
$handler->display->display_options['filters']['phone_type']['expose']['identifier'] = 'phone_type';
$handler->display->display_options['filters']['phone_type']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  55120974 => 0,
  17087012 => 0,
  57573969 => 0,
  37588037 => 0,
);
$translatables['mydetails_notifications__my_contact_info_phones'] = array(
  t('Master'),
  t('Contact Info - Phones'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Drupal User'),
  t('Phone'),
  t('(ext. [phone_ext])'),
  t('[phone] [phone_ext] - [location_type]'),
  t('All'),
  t('Location Type'),
  t('Phone Type'),
);
