<?php

$view = new view();
$view->name = 'mydetails_notifications__my_contact_info_other';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'mydetails_notifications__my_contact_info_other';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Contact Details';
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
/* Field: CiviCRM Contacts: Preferred Name */
$handler->display->display_options['fields']['nick_name']['id'] = 'nick_name';
$handler->display->display_options['fields']['nick_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['nick_name']['field'] = 'nick_name';
/* Contextual filter: CiviCRM Drupal match table: Drupal User ID */
$handler->display->display_options['arguments']['uf_id']['id'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['table'] = 'civicrm_uf_match';
$handler->display->display_options['arguments']['uf_id']['field'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['uf_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uf_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uf_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uf_id']['summary_options']['items_per_page'] = '25';
$translatables['mydetails_notifications__my_contact_info_other'] = array(
  t('Master'),
  t('Contact Details'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Preferred Name'),
  t('All'),
);
