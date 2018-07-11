<?php

$view = new view();
$view->name = 'mydetails_contactdetails';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'MyDetails_ContactDetails';
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
$handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = '<div class="contact-details-label">Contact Details</div>';
$handler->display->display_options['header']['area']['format'] = 'html_without_filters';
/* Footer: Global: View area */
$handler->display->display_options['footer']['view_1']['id'] = 'view_1';
$handler->display->display_options['footer']['view_1']['table'] = 'views';
$handler->display->display_options['footer']['view_1']['field'] = 'view';
$handler->display->display_options['footer']['view_1']['view_to_insert'] = 'mydetails_emails:default';
/* Footer: Global: View area */
$handler->display->display_options['footer']['view']['id'] = 'view';
$handler->display->display_options['footer']['view']['table'] = 'views';
$handler->display->display_options['footer']['view']['field'] = 'view';
$handler->display->display_options['footer']['view']['empty'] = TRUE;
$handler->display->display_options['footer']['view']['view_to_insert'] = 'mydetails_myphones:default';
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
/* Field: CiviCRM Contacts: Preferred Name */
$handler->display->display_options['fields']['nick_name']['id'] = 'nick_name';
$handler->display->display_options['fields']['nick_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['nick_name']['field'] = 'nick_name';
$handler->display->display_options['fields']['nick_name']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['nick_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nick_name']['element_wrapper_class'] = 'chr_panel--my-details__view__panel';
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
/* Filter criterion: CiviCRM Contacts: Contact ID */
$handler->display->display_options['filters']['id']['id'] = 'id';
$handler->display->display_options['filters']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['filters']['id']['field'] = 'id';
$handler->display->display_options['filters']['id']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['id']['operator'] = 'not empty';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'my_details');
$translatables['mydetails_contactdetails'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('<div class="contact-details-label">Contact Details</div>'),
  t('Drupal User'),
  t('Preferred Name'),
  t('All'),
  t('Block'),
);
