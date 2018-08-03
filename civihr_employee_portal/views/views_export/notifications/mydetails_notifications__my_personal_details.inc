<?php

$view = new view();
$view->name = 'mydetails_notifications__my_personal_details';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'mydetails_notifications__my_personal_details';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Personal Details';
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
/* Field: CiviCRM Contacts: Birth Date */
$handler->display->display_options['fields']['birth_date']['id'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['birth_date']['field'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['birth_date']['custom_date_format'] = 'Y-m-d';
$handler->display->display_options['fields']['birth_date']['second_date_format'] = 'long';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Contacts: Gender */
$handler->display->display_options['fields']['gender']['id'] = 'gender';
$handler->display->display_options['fields']['gender']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['gender']['field'] = 'gender';
/* Field: CiviCRM Custom: Extended Demographics: Marital Status */
$handler->display->display_options['fields']['marital_status_58']['id'] = 'marital_status_58';
$handler->display->display_options['fields']['marital_status_58']['table'] = 'civicrm_value_extended_demographics_8';
$handler->display->display_options['fields']['marital_status_58']['field'] = 'marital_status_58';
/* Field: CiviCRM Custom: Extended Demographics: Nationality */
$handler->display->display_options['fields']['nationality_44']['id'] = 'nationality_44';
$handler->display->display_options['fields']['nationality_44']['table'] = 'civicrm_value_extended_demographics_8';
$handler->display->display_options['fields']['nationality_44']['field'] = 'nationality_44';
/* Field: CiviCRM Custom: NI/SSN Number: NI / SSN */
$handler->display->display_options['fields']['ni_ssn_70']['id'] = 'ni_ssn_70';
$handler->display->display_options['fields']['ni_ssn_70']['table'] = 'civicrm_value_inline_custom_data_14';
$handler->display->display_options['fields']['ni_ssn_70']['field'] = 'ni_ssn_70';
/* Field: CiviCRM Custom: NI/SSN Number: NI/SSN application in progress */
$handler->display->display_options['fields']['ni_ssn_application_in_progress_71']['id'] = 'ni_ssn_application_in_progress_71';
$handler->display->display_options['fields']['ni_ssn_application_in_progress_71']['table'] = 'civicrm_value_inline_custom_data_14';
$handler->display->display_options['fields']['ni_ssn_application_in_progress_71']['field'] = 'ni_ssn_application_in_progress_71';
/* Contextual filter: CiviCRM Drupal match table: Drupal User ID */
$handler->display->display_options['arguments']['uf_id']['id'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['table'] = 'civicrm_uf_match';
$handler->display->display_options['arguments']['uf_id']['field'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['uf_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uf_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uf_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uf_id']['summary_options']['items_per_page'] = '25';
$translatables['mydetails_notifications__my_personal_details'] = array(
  t('Master'),
  t('My Personal Details'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Birth Date'),
  t('Display Name'),
  t('Gender'),
  t('Marital Status'),
  t('Nationality'),
  t('NI / SSN'),
  t('NI/SSN application in progress'),
  t('All'),
);
