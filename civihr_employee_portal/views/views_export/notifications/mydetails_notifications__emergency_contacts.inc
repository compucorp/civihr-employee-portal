<?php

$view = new view();
$view->name = 'mydetails_notifications__emergency_contacts';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_value_emergency_contacts_21';
$view->human_name = 'mydetails_notifications__emergency_contacts';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
/* Relationship: CiviCRM Custom: Emergency Contacts: Entity ID */
$handler->display->display_options['relationships']['entity_id']['id'] = 'entity_id';
$handler->display->display_options['relationships']['entity_id']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['relationships']['entity_id']['field'] = 'entity_id';
$handler->display->display_options['relationships']['entity_id']['required'] = TRUE;
/* Field: CiviCRM Custom: Emergency Contacts: Emergency Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['relationship'] = 'entity_id';
/* Field: CiviCRM Custom: Emergency Contacts: Name */
$handler->display->display_options['fields']['name_80']['id'] = 'name_80';
$handler->display->display_options['fields']['name_80']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['name_80']['field'] = 'name_80';
$handler->display->display_options['fields']['name_80']['relationship'] = 'entity_id';
$handler->display->display_options['fields']['name_80']['empty'] = 'Enter the name';
$handler->display->display_options['fields']['name_80']['text_format'] = 'html_without_filters';
/* Field: CiviCRM Custom: Emergency Contacts: Mobile number */
$handler->display->display_options['fields']['mobile_number_91']['id'] = 'mobile_number_91';
$handler->display->display_options['fields']['mobile_number_91']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['mobile_number_91']['field'] = 'mobile_number_91';
$handler->display->display_options['fields']['mobile_number_91']['relationship'] = 'entity_id';
$handler->display->display_options['fields']['mobile_number_91']['text_format'] = 'html_without_filters';
/* Field: CiviCRM Custom: Emergency Contacts: Phone number */
$handler->display->display_options['fields']['phone_number_81']['id'] = 'phone_number_81';
$handler->display->display_options['fields']['phone_number_81']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['phone_number_81']['field'] = 'phone_number_81';
$handler->display->display_options['fields']['phone_number_81']['relationship'] = 'entity_id';
/* Field: CiviCRM Custom: Emergency Contacts: Email */
$handler->display->display_options['fields']['email_82']['id'] = 'email_82';
$handler->display->display_options['fields']['email_82']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['email_82']['field'] = 'email_82';
$handler->display->display_options['fields']['email_82']['relationship'] = 'entity_id';
/* Field: CiviCRM Custom: Emergency Contacts: Street Address Line 2 */
$handler->display->display_options['fields']['street_address_line_2_94']['id'] = 'street_address_line_2_94';
$handler->display->display_options['fields']['street_address_line_2_94']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['street_address_line_2_94']['field'] = 'street_address_line_2_94';
$handler->display->display_options['fields']['street_address_line_2_94']['relationship'] = 'entity_id';
$handler->display->display_options['fields']['street_address_line_2_94']['exclude'] = TRUE;
$handler->display->display_options['fields']['street_address_line_2_94']['empty'] = 'Address line 2';
/* Field: CiviCRM Custom: Emergency Contacts: Street Address */
$handler->display->display_options['fields']['street_address_93']['id'] = 'street_address_93';
$handler->display->display_options['fields']['street_address_93']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['street_address_93']['field'] = 'street_address_93';
$handler->display->display_options['fields']['street_address_93']['relationship'] = 'entity_id';
$handler->display->display_options['fields']['street_address_93']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['street_address_93']['alter']['text'] = '[street_address_93]
[street_address_line_2_94]';
/* Field: CiviCRM Custom: Emergency Contacts: City */
$handler->display->display_options['fields']['city_95']['id'] = 'city_95';
$handler->display->display_options['fields']['city_95']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['city_95']['field'] = 'city_95';
$handler->display->display_options['fields']['city_95']['relationship'] = 'entity_id';
/* Field: CiviCRM Custom: Emergency Contacts: Postal Code */
$handler->display->display_options['fields']['postal_code_96']['id'] = 'postal_code_96';
$handler->display->display_options['fields']['postal_code_96']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['postal_code_96']['field'] = 'postal_code_96';
$handler->display->display_options['fields']['postal_code_96']['relationship'] = 'entity_id';
/* Field: CiviCRM Custom: Emergency Contacts: Country */
$handler->display->display_options['fields']['country_98']['id'] = 'country_98';
$handler->display->display_options['fields']['country_98']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['country_98']['field'] = 'country_98';
$handler->display->display_options['fields']['country_98']['relationship'] = 'entity_id';
/* Field: CiviCRM Custom: Emergency Contacts: State/Province */
$handler->display->display_options['fields']['province_97']['id'] = 'province_97';
$handler->display->display_options['fields']['province_97']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['province_97']['field'] = 'province_97';
$handler->display->display_options['fields']['province_97']['relationship'] = 'entity_id';
/* Field: CiviCRM Custom: Emergency Contacts: Relationship with Employee */
$handler->display->display_options['fields']['relationship_with_employee_83']['id'] = 'relationship_with_employee_83';
$handler->display->display_options['fields']['relationship_with_employee_83']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['relationship_with_employee_83']['field'] = 'relationship_with_employee_83';
$handler->display->display_options['fields']['relationship_with_employee_83']['relationship'] = 'entity_id';
/* Field: CiviCRM Custom: Emergency Contacts: Notes */
$handler->display->display_options['fields']['notes_84_1']['id'] = 'notes_84_1';
$handler->display->display_options['fields']['notes_84_1']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['notes_84_1']['field'] = 'notes_84';
$handler->display->display_options['fields']['notes_84_1']['relationship'] = 'entity_id';
/* Sort criterion: CiviCRM Custom: Emergency Contacts: Emergency Contact ID */
$handler->display->display_options['sorts']['id']['id'] = 'id';
$handler->display->display_options['sorts']['id']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['sorts']['id']['field'] = 'id';
$handler->display->display_options['sorts']['id']['relationship'] = 'entity_id';
$handler->display->display_options['sorts']['id']['order'] = 'DESC';
/* Contextual filter: CiviCRM Custom: Emergency Contacts: Is a Dependant? */
$handler->display->display_options['arguments']['dependant_s__92']['id'] = 'dependant_s__92';
$handler->display->display_options['arguments']['dependant_s__92']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['arguments']['dependant_s__92']['field'] = 'dependant_s__92';
$handler->display->display_options['arguments']['dependant_s__92']['default_action'] = 'not found';
$handler->display->display_options['arguments']['dependant_s__92']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['dependant_s__92']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['dependant_s__92']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['dependant_s__92']['summary_options']['items_per_page'] = '25';
/* Contextual filter: Global: Null */
$handler->display->display_options['arguments']['null']['id'] = 'null';
$handler->display->display_options['arguments']['null']['table'] = 'views';
$handler->display->display_options['arguments']['null']['field'] = 'null';
$handler->display->display_options['arguments']['null']['default_action'] = 'default';
$handler->display->display_options['arguments']['null']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['null']['title'] = '%2';
$handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['null']['default_argument_options']['argument'] = 'Emergency Contacts';
$handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
/* Contextual filter: CiviCRM Drupal match table: Drupal User ID */
$handler->display->display_options['arguments']['uf_id']['id'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['table'] = 'civicrm_uf_match';
$handler->display->display_options['arguments']['uf_id']['field'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['relationship'] = 'entity_id';
$handler->display->display_options['arguments']['uf_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['uf_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uf_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uf_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uf_id']['summary_options']['items_per_page'] = '25';
/* Contextual filter: CiviCRM Custom: Emergency Contacts: Entity ID */
$handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
$handler->display->display_options['arguments']['entity_id']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
$handler->display->display_options['arguments']['entity_id']['relationship'] = 'entity_id';
$handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: CiviCRM Custom: Emergency Contacts: Emergency Contact ID */
$handler->display->display_options['filters']['id']['id'] = 'id';
$handler->display->display_options['filters']['id']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['filters']['id']['field'] = 'id';
$handler->display->display_options['filters']['id']['relationship'] = 'entity_id';
$handler->display->display_options['filters']['id']['operator'] = '>';
$handler->display->display_options['filters']['id']['value']['value'] = '0';
$handler->display->display_options['filters']['id']['exposed'] = TRUE;
$handler->display->display_options['filters']['id']['expose']['operator_id'] = 'id_op';
$handler->display->display_options['filters']['id']['expose']['label'] = 'Emergency Contact ID';
$handler->display->display_options['filters']['id']['expose']['operator'] = 'id_op';
$handler->display->display_options['filters']['id']['expose']['identifier'] = 'emergency_contact_id';
$handler->display->display_options['filters']['id']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  55120974 => 0,
  17087012 => 0,
  57573969 => 0,
  37588037 => 0,
);
$translatables['mydetails_notifications__emergency_contacts'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('CiviCRM Contact ID'),
  t('Emergency Contact ID'),
  t('.'),
  t(','),
  t('Name'),
  t('Enter the name'),
  t('Mobile number'),
  t('Phone number'),
  t('Email'),
  t('Street Address Line 2'),
  t('Address line 2'),
  t('Street Address'),
  t('[street_address_93]
[street_address_line_2_94]'),
  t('City'),
  t('Postal Code'),
  t('Country'),
  t('State/Province'),
  t('Relationship with Employee'),
  t('Notes'),
  t('All'),
  t('%2'),
);
