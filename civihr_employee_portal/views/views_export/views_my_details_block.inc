<?php

/**
 * Exported my_details_block view
 */

$view = new view();
$view->name = 'my_details_block';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'My details block';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Details Block';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view my details';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
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
/* Relationship: CiviCRM Contacts: HRJobContract Revision entity */
$handler->display->display_options['relationships']['hrjc_revision']['id'] = 'hrjc_revision';
$handler->display->display_options['relationships']['hrjc_revision']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_revision']['field'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Details_revision_id */
$handler->display->display_options['relationships']['details_revision_id']['id'] = 'details_revision_id';
$handler->display->display_options['relationships']['details_revision_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['details_revision_id']['field'] = 'details_revision_id';
$handler->display->display_options['relationships']['details_revision_id']['relationship'] = 'hrjc_revision';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Custom: Emergency Contacts: Name */
$handler->display->display_options['fields']['name_80']['id'] = 'name_80';
$handler->display->display_options['fields']['name_80']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['name_80']['field'] = 'name_80';
$handler->display->display_options['fields']['name_80']['label'] = 'Emergency Contact';
$handler->display->display_options['fields']['name_80']['alter']['strip_tags'] = TRUE;
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current']['value'] = '1';

/* Display: My details */
$handler = $view->new_display('block', 'My details', 'my_details_block');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
/* Relationship: CiviCRM Contacts: HRJobContract Revision entity */
$handler->display->display_options['relationships']['hrjc_revision']['id'] = 'hrjc_revision';
$handler->display->display_options['relationships']['hrjc_revision']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_revision']['field'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Details_revision_id */
$handler->display->display_options['relationships']['details_revision_id']['id'] = 'details_revision_id';
$handler->display->display_options['relationships']['details_revision_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['details_revision_id']['field'] = 'details_revision_id';
$handler->display->display_options['relationships']['details_revision_id']['relationship'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Role_jobcontract_id */
$handler->display->display_options['relationships']['role_jobcontract_id']['id'] = 'role_jobcontract_id';
$handler->display->display_options['relationships']['role_jobcontract_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['role_jobcontract_id']['field'] = 'role_jobcontract_id';
$handler->display->display_options['relationships']['role_jobcontract_id']['relationship'] = 'hrjc_revision';
/* Relationship: CiviCRM Contacts: HRJobContract Contact Work/Home Phone and E-mail Entity */
$handler->display->display_options['relationships']['hrjc_contact_details']['id'] = 'hrjc_contact_details';
$handler->display->display_options['relationships']['hrjc_contact_details']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_contact_details']['field'] = 'hrjc_contact_details';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['label'] = 'Name';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Work_phone */
$handler->display->display_options['fields']['work_phone']['id'] = 'work_phone';
$handler->display->display_options['fields']['work_phone']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone']['field'] = 'work_phone';
$handler->display->display_options['fields']['work_phone']['relationship'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone']['label'] = 'Work Phone';
$handler->display->display_options['fields']['work_phone']['exclude'] = TRUE;
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Work_phone_ext */
$handler->display->display_options['fields']['work_phone_ext']['id'] = 'work_phone_ext';
$handler->display->display_options['fields']['work_phone_ext']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone_ext']['field'] = 'work_phone_ext';
$handler->display->display_options['fields']['work_phone_ext']['relationship'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone_ext']['label'] = 'Work Phone Extension';
$handler->display->display_options['fields']['work_phone_ext']['exclude'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Work Phone';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[work_phone] ext. [work_phone_ext]';
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Work_email */
$handler->display->display_options['fields']['work_email']['id'] = 'work_email';
$handler->display->display_options['fields']['work_email']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_email']['field'] = 'work_email';
$handler->display->display_options['fields']['work_email']['relationship'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_email']['label'] = 'Work E-mail';
/* Field: CiviCRM Contacts: Birth Date */
$handler->display->display_options['fields']['birth_date']['id'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['birth_date']['field'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['label'] = 'Date of Birth';
$handler->display->display_options['fields']['birth_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['birth_date']['custom_date_format'] = 'd.m.Y';
$handler->display->display_options['fields']['birth_date']['second_date_format'] = 'long';
/* Field: HRJobContract Details entity: Location_label */
$handler->display->display_options['fields']['location_label']['id'] = 'location_label';
$handler->display->display_options['fields']['location_label']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['location_label']['field'] = 'location_label';
$handler->display->display_options['fields']['location_label']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['location_label']['label'] = 'Location';
/* Field: HRJobContract Details entity: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['title']['label'] = 'Designation';
/* Field: HRJobContract Role entity: Role_title */
$handler->display->display_options['fields']['role_title']['id'] = 'role_title';
$handler->display->display_options['fields']['role_title']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_title']['field'] = 'role_title';
$handler->display->display_options['fields']['role_title']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_title']['label'] = 'Role title';
/* Field: HRJobContract Role entity: Role_department */
$handler->display->display_options['fields']['role_department']['id'] = 'role_department';
$handler->display->display_options['fields']['role_department']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_department']['field'] = 'role_department';
$handler->display->display_options['fields']['role_department']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_department']['label'] = 'Role Department';
/* Field: CiviCRM Custom: NI/SSN Number: NI / SSN */
$handler->display->display_options['fields']['ni_ssn_60']['id'] = 'ni_ssn_60';
$handler->display->display_options['fields']['ni_ssn_60']['table'] = 'civicrm_value_inline_custom_10';
$handler->display->display_options['fields']['ni_ssn_60']['field'] = 'ni_ssn_60';
$handler->display->display_options['fields']['ni_ssn_60']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['ni_ssn_60']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: NI/SSN Number: NI/SSN application in progress */
$handler->display->display_options['fields']['ni_ssn_application_in_progress_61']['id'] = 'ni_ssn_application_in_progress_61';
$handler->display->display_options['fields']['ni_ssn_application_in_progress_61']['table'] = 'civicrm_value_inline_custom_10';
$handler->display->display_options['fields']['ni_ssn_application_in_progress_61']['field'] = 'ni_ssn_application_in_progress_61';
$handler->display->display_options['fields']['ni_ssn_application_in_progress_61']['empty'] = 'No';
$handler->display->display_options['defaults']['arguments'] = FALSE;

/* Display: Contact Information */
$handler = $view->new_display('block', 'Contact Information', 'my_address_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Contact Information Block';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['footer'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
/* Relationship: CiviCRM Contacts: HRJobContract Contact Work/Home Phone and E-mail Entity */
$handler->display->display_options['relationships']['hrjc_contact_details']['id'] = 'hrjc_contact_details';
$handler->display->display_options['relationships']['hrjc_contact_details']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_contact_details']['field'] = 'hrjc_contact_details';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: CiviCRM Address: Contact ID */
$handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Home_phone */
$handler->display->display_options['fields']['home_phone']['id'] = 'home_phone';
$handler->display->display_options['fields']['home_phone']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['home_phone']['field'] = 'home_phone';
$handler->display->display_options['fields']['home_phone']['relationship'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['home_phone']['label'] = 'Personal Phone';
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Home_email */
$handler->display->display_options['fields']['home_email']['id'] = 'home_email';
$handler->display->display_options['fields']['home_email']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['home_email']['field'] = 'home_email';
$handler->display->display_options['fields']['home_email']['relationship'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['home_email']['label'] = 'Personal E-mail';
/* Field: CiviCRM Contacts: Aggregated Contact Home Address */
$handler->display->display_options['fields']['aggregated_personal_address']['id'] = 'aggregated_personal_address';
$handler->display->display_options['fields']['aggregated_personal_address']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['aggregated_personal_address']['field'] = 'aggregated_personal_address';
$handler->display->display_options['fields']['aggregated_personal_address']['label'] = 'Home Address';
$translatables['my_details_block'] = array(
  t('Master'),
  t('My Details Block'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Drupal User'),
  t('HRJobContract Revision entity'),
  t('HRJobContract Details entity'),
  t('Contact ID'),
  t('.'),
  t(','),
  t('Display Name'),
  t('Emergency Contact'),
  t('My details'),
  t('HRJobContract Role entity'),
  t('HRJobContract Contact Work/Home Phone and E-mail Entity'),
  t('Name'),
  t('Work Phone'),
  t('Work Phone Extension'),
  t('[work_phone] ext. [work_phone_ext]'),
  t('Work E-mail'),
  t('Date of Birth'),
  t('Location'),
  t('Designation'),
  t('Role title'),
  t('Role Department'),
  t('NI / SSN'),
  t('NI/SSN application in progress'),
  t('No'),
  t('Contact Information'),
  t('Contact Information Block'),
  t('Personal Phone'),
  t('Personal E-mail'),
  t('Home Address'),
);
