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
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['label'] = 'Name';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Phone Details: Phone */
$handler->display->display_options['fields']['phone']['id'] = 'phone';
$handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone']['field'] = 'phone';
$handler->display->display_options['fields']['phone']['label'] = 'Work Phone';
$handler->display->display_options['fields']['phone']['exclude'] = TRUE;
$handler->display->display_options['fields']['phone']['location_type'] = '2';
$handler->display->display_options['fields']['phone']['location_op'] = '0';
$handler->display->display_options['fields']['phone']['is_primary'] = 0;
$handler->display->display_options['fields']['phone']['phone_type'] = '1';
/* Field: CiviCRM Phone Details: Phone Number Extension */
$handler->display->display_options['fields']['phone_ext']['id'] = 'phone_ext';
$handler->display->display_options['fields']['phone_ext']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone_ext']['field'] = 'phone_ext';
$handler->display->display_options['fields']['phone_ext']['label'] = 'Work Phone Extension';
$handler->display->display_options['fields']['phone_ext']['exclude'] = TRUE;
$handler->display->display_options['fields']['phone_ext']['location_type'] = '2';
$handler->display->display_options['fields']['phone_ext']['location_op'] = '0';
$handler->display->display_options['fields']['phone_ext']['is_primary'] = 0;
$handler->display->display_options['fields']['phone_ext']['phone_type'] = '1';
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Work_phone */
$handler->display->display_options['fields']['work_phone']['id'] = 'work_phone';
$handler->display->display_options['fields']['work_phone']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone']['field'] = 'work_phone';
$handler->display->display_options['fields']['work_phone']['relationship'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone']['exclude'] = TRUE;
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Work_phone_ext */
$handler->display->display_options['fields']['work_phone_ext']['id'] = 'work_phone_ext';
$handler->display->display_options['fields']['work_phone_ext']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone_ext']['field'] = 'work_phone_ext';
$handler->display->display_options['fields']['work_phone_ext']['relationship'] = 'hrjc_contact_details';
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
/* Field: HRJobContract Details entity: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['title']['label'] = 'Designation';
/* Field: HRJobContract Details entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['fields']['location']['relationship'] = 'details_revision_id';
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
/* Field: CiviCRM Custom: Emergency Contacts: Name */
$handler->display->display_options['fields']['name_80']['id'] = 'name_80';
$handler->display->display_options['fields']['name_80']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['name_80']['field'] = 'name_80';
$handler->display->display_options['fields']['name_80']['label'] = 'Emergency Contact';
$handler->display->display_options['fields']['name_80']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: HRJobContract Details entity: Period start date */
$handler->display->display_options['arguments']['period_start_date']['id'] = 'period_start_date';
$handler->display->display_options['arguments']['period_start_date']['table'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_start_date']['field'] = 'period_start_date';
$handler->display->display_options['arguments']['period_start_date']['relationship'] = 'details_revision_id';
$handler->display->display_options['arguments']['period_start_date']['default_action'] = 'default';
$handler->display->display_options['arguments']['period_start_date']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['period_start_date']['default_argument_options']['code'] = 'return date(\'Y-m-d\');';
$handler->display->display_options['arguments']['period_start_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['period_start_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['period_start_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['period_start_date']['civihr_range'] = '<=';
$handler->display->display_options['arguments']['period_start_date']['civihr_range_empty'] = '1';
/* Contextual filter: HRJobContract Details entity: Period end date */
$handler->display->display_options['arguments']['period_end_date']['id'] = 'period_end_date';
$handler->display->display_options['arguments']['period_end_date']['table'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_end_date']['field'] = 'period_end_date';
$handler->display->display_options['arguments']['period_end_date']['relationship'] = 'details_revision_id';
$handler->display->display_options['arguments']['period_end_date']['default_action'] = 'default';
$handler->display->display_options['arguments']['period_end_date']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['period_end_date']['default_argument_options']['code'] = 'return date(\'Y-m-d\');';
$handler->display->display_options['arguments']['period_end_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['period_end_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['period_end_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['period_end_date']['civihr_range'] = '>=';
$handler->display->display_options['arguments']['period_end_date']['civihr_range_empty'] = '1';
/* Contextual filter: HRJobContract Revision entity: Effective_end_date */
$handler->display->display_options['arguments']['effective_end_date']['id'] = 'effective_end_date';
$handler->display->display_options['arguments']['effective_end_date']['table'] = 'hrjc_revision';
$handler->display->display_options['arguments']['effective_end_date']['field'] = 'effective_end_date';
$handler->display->display_options['arguments']['effective_end_date']['relationship'] = 'hrjc_revision';
$handler->display->display_options['arguments']['effective_end_date']['default_action'] = 'default';
$handler->display->display_options['arguments']['effective_end_date']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['effective_end_date']['default_argument_options']['code'] = 'return date(\'Y-m-d\');';
$handler->display->display_options['arguments']['effective_end_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['effective_end_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['effective_end_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['effective_end_date']['civihr_range'] = '>=';
$handler->display->display_options['arguments']['effective_end_date']['civihr_range_empty'] = '1';

/* Display: My address */
$handler = $view->new_display('block', 'My address', 'my_address_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'My Address Block';
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
/* Field: CiviCRM Address: Full Street Address */
$handler->display->display_options['fields']['street_address']['id'] = 'street_address';
$handler->display->display_options['fields']['street_address']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['street_address']['field'] = 'street_address';
$handler->display->display_options['fields']['street_address']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['street_address']['label'] = 'Address';
$handler->display->display_options['fields']['street_address']['location_type'] = '1';
$handler->display->display_options['fields']['street_address']['location_op'] = '0';
$handler->display->display_options['fields']['street_address']['is_primary'] = 1;
$handler->display->display_options['fields']['street_address']['is_billing'] = 0;
/* Field: CiviCRM Address: Supplemental Street Address */
$handler->display->display_options['fields']['supplemental_address_1']['id'] = 'supplemental_address_1';
$handler->display->display_options['fields']['supplemental_address_1']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['supplemental_address_1']['field'] = 'supplemental_address_1';
$handler->display->display_options['fields']['supplemental_address_1']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['supplemental_address_1']['label'] = 'Address Line 2';
$handler->display->display_options['fields']['supplemental_address_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['supplemental_address_1']['location_type'] = '1';
$handler->display->display_options['fields']['supplemental_address_1']['location_op'] = '0';
$handler->display->display_options['fields']['supplemental_address_1']['is_primary'] = 1;
$handler->display->display_options['fields']['supplemental_address_1']['is_billing'] = 0;
/* Field: CiviCRM Address: City / Suburb */
$handler->display->display_options['fields']['city']['id'] = 'city';
$handler->display->display_options['fields']['city']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['city']['field'] = 'city';
$handler->display->display_options['fields']['city']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['city']['location_type'] = '1';
$handler->display->display_options['fields']['city']['location_op'] = '0';
$handler->display->display_options['fields']['city']['is_primary'] = 1;
$handler->display->display_options['fields']['city']['is_billing'] = 0;
/* Field: CiviCRM Address: Postal Code */
$handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['postal_code']['location_type'] = '1';
$handler->display->display_options['fields']['postal_code']['location_op'] = '0';
$handler->display->display_options['fields']['postal_code']['is_primary'] = 1;
$handler->display->display_options['fields']['postal_code']['is_billing'] = 0;
/* Field: CiviCRM Address: State/Province */
$handler->display->display_options['fields']['state_province']['id'] = 'state_province';
$handler->display->display_options['fields']['state_province']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['state_province']['field'] = 'state_province';
$handler->display->display_options['fields']['state_province']['location_type'] = '1';
$handler->display->display_options['fields']['state_province']['location_op'] = '0';
$handler->display->display_options['fields']['state_province']['is_primary'] = 1;
$handler->display->display_options['fields']['state_province']['is_billing'] = 0;
/* Field: CiviCRM Address: Country */
$handler->display->display_options['fields']['country']['id'] = 'country';
$handler->display->display_options['fields']['country']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['country']['field'] = 'country';
$handler->display->display_options['fields']['country']['location_type'] = '1';
$handler->display->display_options['fields']['country']['location_op'] = '0';
$handler->display->display_options['fields']['country']['is_primary'] = 1;
$handler->display->display_options['fields']['country']['is_billing'] = 0;

/* Display: My details (full) */
$handler = $view->new_display('block', 'My details (full)', 'my_details_block_full');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'My Details';
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
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['label'] = 'Display name';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Work_phone */
$handler->display->display_options['fields']['work_phone']['id'] = 'work_phone';
$handler->display->display_options['fields']['work_phone']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone']['field'] = 'work_phone';
$handler->display->display_options['fields']['work_phone']['relationship'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone']['exclude'] = TRUE;
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Work_phone_ext */
$handler->display->display_options['fields']['work_phone_ext']['id'] = 'work_phone_ext';
$handler->display->display_options['fields']['work_phone_ext']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone_ext']['field'] = 'work_phone_ext';
$handler->display->display_options['fields']['work_phone_ext']['relationship'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_phone_ext']['exclude'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = 'Work Phone';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[work_phone] ext. [work_phone_ext]';
/* Field: HRJobContract Contact Work/Home Phone and E-mail Entity: Work_email */
$handler->display->display_options['fields']['work_email']['id'] = 'work_email';
$handler->display->display_options['fields']['work_email']['table'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_email']['field'] = 'work_email';
$handler->display->display_options['fields']['work_email']['relationship'] = 'hrjc_contact_details';
$handler->display->display_options['fields']['work_email']['label'] = 'Work Email';
/* Field: CiviCRM Contacts: Birth Date */
$handler->display->display_options['fields']['birth_date']['id'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['birth_date']['field'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['label'] = 'Date of birth';
$handler->display->display_options['fields']['birth_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['birth_date']['custom_date_format'] = 'd.m.Y';
$handler->display->display_options['fields']['birth_date']['second_date_format'] = 'long';
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
$handler->display->display_options['fields']['home_email']['label'] = 'Personal Email';
/* Field: CiviCRM Address: Full Street Address */
$handler->display->display_options['fields']['street_address']['id'] = 'street_address';
$handler->display->display_options['fields']['street_address']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['street_address']['field'] = 'street_address';
$handler->display->display_options['fields']['street_address']['exclude'] = TRUE;
$handler->display->display_options['fields']['street_address']['location_type'] = '1';
$handler->display->display_options['fields']['street_address']['location_op'] = '0';
$handler->display->display_options['fields']['street_address']['is_primary'] = 1;
$handler->display->display_options['fields']['street_address']['is_billing'] = 0;
/* Field: CiviCRM Address: Supplemental Street Address */
$handler->display->display_options['fields']['supplemental_address_1']['id'] = 'supplemental_address_1';
$handler->display->display_options['fields']['supplemental_address_1']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['supplemental_address_1']['field'] = 'supplemental_address_1';
$handler->display->display_options['fields']['supplemental_address_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['supplemental_address_1']['location_type'] = '1';
$handler->display->display_options['fields']['supplemental_address_1']['location_op'] = '0';
$handler->display->display_options['fields']['supplemental_address_1']['is_primary'] = 1;
$handler->display->display_options['fields']['supplemental_address_1']['is_billing'] = 0;
/* Field: CiviCRM Address: City / Suburb */
$handler->display->display_options['fields']['city']['id'] = 'city';
$handler->display->display_options['fields']['city']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['city']['field'] = 'city';
$handler->display->display_options['fields']['city']['exclude'] = TRUE;
$handler->display->display_options['fields']['city']['location_type'] = '1';
$handler->display->display_options['fields']['city']['location_op'] = '0';
$handler->display->display_options['fields']['city']['is_primary'] = 1;
$handler->display->display_options['fields']['city']['is_billing'] = 0;
/* Field: CiviCRM Address: Postal Code */
$handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['exclude'] = TRUE;
$handler->display->display_options['fields']['postal_code']['location_type'] = '1';
$handler->display->display_options['fields']['postal_code']['location_op'] = '0';
$handler->display->display_options['fields']['postal_code']['is_primary'] = 1;
$handler->display->display_options['fields']['postal_code']['is_billing'] = 0;
/* Field: CiviCRM Address: Country */
$handler->display->display_options['fields']['country']['id'] = 'country';
$handler->display->display_options['fields']['country']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['country']['field'] = 'country';
$handler->display->display_options['fields']['country']['exclude'] = TRUE;
$handler->display->display_options['fields']['country']['location_type'] = '1';
$handler->display->display_options['fields']['country']['location_op'] = '0';
$handler->display->display_options['fields']['country']['is_primary'] = 1;
$handler->display->display_options['fields']['country']['is_billing'] = 0;
$handler->display->display_options['fields']['country']['country_display'] = '2';
/* Field: CiviCRM Address: State/Province */
$handler->display->display_options['fields']['state_province']['id'] = 'state_province';
$handler->display->display_options['fields']['state_province']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['state_province']['field'] = 'state_province';
$handler->display->display_options['fields']['state_province']['location_type'] = '1';
$handler->display->display_options['fields']['state_province']['location_op'] = '0';
$handler->display->display_options['fields']['state_province']['is_primary'] = 1;
$handler->display->display_options['fields']['state_province']['is_billing'] = 0;
$handler->display->display_options['fields']['state_province']['prov_display'] = '2';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Address';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[street_address] <br />
[supplemental_address_1] <br />
[city] [postal_code] <br />
[state_province] <br />
[country]';

/* Display: Emergency Contact (full) */
$handler = $view->new_display('block', 'Emergency Contact (full)', 'my_details_emergency_contact');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Emergency Contact';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: CiviCRM Custom: Emergency Contacts: Name */
$handler->display->display_options['fields']['name_80']['id'] = 'name_80';
$handler->display->display_options['fields']['name_80']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['name_80']['field'] = 'name_80';
$handler->display->display_options['fields']['name_80']['label'] = 'Contact name';
$handler->display->display_options['fields']['name_80']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Mobile number */
$handler->display->display_options['fields']['mobile_number_91']['id'] = 'mobile_number_91';
$handler->display->display_options['fields']['mobile_number_91']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['mobile_number_91']['field'] = 'mobile_number_91';
$handler->display->display_options['fields']['mobile_number_91']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Phone number */
$handler->display->display_options['fields']['phone_number_81']['id'] = 'phone_number_81';
$handler->display->display_options['fields']['phone_number_81']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['phone_number_81']['field'] = 'phone_number_81';
$handler->display->display_options['fields']['phone_number_81']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Email */
$handler->display->display_options['fields']['email_82']['id'] = 'email_82';
$handler->display->display_options['fields']['email_82']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['email_82']['field'] = 'email_82';
$handler->display->display_options['fields']['email_82']['label'] = 'Primary email';
$handler->display->display_options['fields']['email_82']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Street Address */
$handler->display->display_options['fields']['street_address_93']['id'] = 'street_address_93';
$handler->display->display_options['fields']['street_address_93']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['street_address_93']['field'] = 'street_address_93';
$handler->display->display_options['fields']['street_address_93']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Street Address Line 2 */
$handler->display->display_options['fields']['street_address_line_2_94']['id'] = 'street_address_line_2_94';
$handler->display->display_options['fields']['street_address_line_2_94']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['street_address_line_2_94']['field'] = 'street_address_line_2_94';
$handler->display->display_options['fields']['street_address_line_2_94']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: City */
$handler->display->display_options['fields']['city_95']['id'] = 'city_95';
$handler->display->display_options['fields']['city_95']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['city_95']['field'] = 'city_95';
$handler->display->display_options['fields']['city_95']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Postal Code */
$handler->display->display_options['fields']['postal_code_96']['id'] = 'postal_code_96';
$handler->display->display_options['fields']['postal_code_96']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['postal_code_96']['field'] = 'postal_code_96';
$handler->display->display_options['fields']['postal_code_96']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Country */
$handler->display->display_options['fields']['country_98']['id'] = 'country_98';
$handler->display->display_options['fields']['country_98']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['country_98']['field'] = 'country_98';
$handler->display->display_options['fields']['country_98']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: State/Province */
$handler->display->display_options['fields']['province_97']['id'] = 'province_97';
$handler->display->display_options['fields']['province_97']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['province_97']['field'] = 'province_97';
$handler->display->display_options['fields']['province_97']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Relationship with Employee */
$handler->display->display_options['fields']['relationship_with_employee_83']['id'] = 'relationship_with_employee_83';
$handler->display->display_options['fields']['relationship_with_employee_83']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['relationship_with_employee_83']['field'] = 'relationship_with_employee_83';
$handler->display->display_options['fields']['relationship_with_employee_83']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Notes */
$handler->display->display_options['fields']['notes_84']['id'] = 'notes_84';
$handler->display->display_options['fields']['notes_84']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['notes_84']['field'] = 'notes_84';
$handler->display->display_options['fields']['notes_84']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Dependant(s) */
$handler->display->display_options['fields']['dependant_s__92']['id'] = 'dependant_s__92';
$handler->display->display_options['fields']['dependant_s__92']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['dependant_s__92']['field'] = 'dependant_s__92';
$handler->display->display_options['fields']['dependant_s__92']['alter']['strip_tags'] = TRUE;
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
  t('Work_phone'),
  t('Work_phone_ext'),
  t('[work_phone] ext. [work_phone_ext]'),
  t('Work E-mail'),
  t('Designation'),
  t('Location'),
  t('Role title'),
  t('Role Department'),
  t('All'),
  t('My address'),
  t('My Address Block'),
  t('Personal Phone'),
  t('Personal E-mail'),
  t('Address'),
  t('Address Line 2'),
  t('City / Suburb'),
  t('Postal Code'),
  t('State/Province'),
  t('Country'),
  t('My details (full)'),
  t('My Details'),
  t('Display name'),
  t('Work Email'),
  t('Date of birth'),
  t('Personal Email'),
  t('Full Street Address'),
  t('Supplemental Street Address'),
  t('[street_address] <br />
[supplemental_address_1] <br />
[city] [postal_code] <br />
[state_province] <br />
[country]'),
  t('Emergency Contact (full)'),
  t('Contact name'),
  t('Mobile number'),
  t('Phone number'),
  t('Primary email'),
  t('Street Address'),
  t('Street Address Line 2'),
  t('City'),
  t('Relationship with Employee'),
  t('Notes'),
  t('Dependant(s)'),
);
