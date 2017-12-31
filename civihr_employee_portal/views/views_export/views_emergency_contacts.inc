<?php

$view = new view();
$view->name = 'emergency_contacts';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_value_emergency_contacts_21';
$view->human_name = 'Emergency Contacts';
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
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name_80' => 'name_80',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'name_80' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
/* Field: CiviCRM Custom: Emergency Contacts: Emergency Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
/* Field: CiviCRM Custom: Emergency Contacts: Entity ID */
$handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
$handler->display->display_options['fields']['entity_id']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
$handler->display->display_options['fields']['entity_id']['label'] = '';
$handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
/* Field: CiviCRM Custom: Emergency Contacts: Name */
$handler->display->display_options['fields']['name_80']['id'] = 'name_80';
$handler->display->display_options['fields']['name_80']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['name_80']['field'] = 'name_80';
/* Field: CiviCRM Custom: Emergency Contacts: Mobile number */
$handler->display->display_options['fields']['mobile_number_91']['id'] = 'mobile_number_91';
$handler->display->display_options['fields']['mobile_number_91']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['mobile_number_91']['field'] = 'mobile_number_91';
$handler->display->display_options['fields']['mobile_number_91']['label'] = 'Mobile Number';
/* Field: CiviCRM Custom: Emergency Contacts: Phone number */
$handler->display->display_options['fields']['phone_number_81']['id'] = 'phone_number_81';
$handler->display->display_options['fields']['phone_number_81']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['phone_number_81']['field'] = 'phone_number_81';
$handler->display->display_options['fields']['phone_number_81']['label'] = 'Phone Number';
/* Field: CiviCRM Custom: Emergency Contacts: Email */
$handler->display->display_options['fields']['email_82']['id'] = 'email_82';
$handler->display->display_options['fields']['email_82']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['email_82']['field'] = 'email_82';
$handler->display->display_options['fields']['email_82']['label'] = 'Primary Email';
/* Field: CiviCRM Custom: Emergency Contacts: Aggregated Emergency Contact Address */
$handler->display->display_options['fields']['emergency_contact_aggregated_address']['id'] = 'emergency_contact_aggregated_address';
$handler->display->display_options['fields']['emergency_contact_aggregated_address']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['emergency_contact_aggregated_address']['field'] = 'emergency_contact_aggregated_address';
$handler->display->display_options['fields']['emergency_contact_aggregated_address']['label'] = 'Address';
/* Field: CiviCRM Custom: Emergency Contacts: Relationship with Employee */
$handler->display->display_options['fields']['relationship_with_employee_83']['id'] = 'relationship_with_employee_83';
$handler->display->display_options['fields']['relationship_with_employee_83']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['relationship_with_employee_83']['field'] = 'relationship_with_employee_83';
/* Field: CiviCRM Custom: Emergency Contacts: Notes */
$handler->display->display_options['fields']['notes_84']['id'] = 'notes_84';
$handler->display->display_options['fields']['notes_84']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['notes_84']['field'] = 'notes_84';
/* Field: CiviCRM Custom: Emergency Contacts: Is a Dependant? */
$handler->display->display_options['fields']['dependant_s__92']['id'] = 'dependant_s__92';
$handler->display->display_options['fields']['dependant_s__92']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['fields']['dependant_s__92']['field'] = 'dependant_s__92';
$handler->display->display_options['fields']['dependant_s__92']['label'] = '';
$handler->display->display_options['fields']['dependant_s__92']['exclude'] = TRUE;
$handler->display->display_options['fields']['dependant_s__92']['element_label_colon'] = FALSE;
/* Field: Placeholder for Deletion Button (Button markup is provided by template) */
$handler->display->display_options['fields']['emergency_contact_deletion']['id'] = 'emergency_contact_deletion';
$handler->display->display_options['fields']['emergency_contact_deletion']['table'] = 'views';
$handler->display->display_options['fields']['emergency_contact_deletion']['field'] = 'nothing';
$handler->display->display_options['fields']['emergency_contact_deletion']['ui_name'] = 'Placeholder for Deletion Button (Button markup is provided by template)';
$handler->display->display_options['fields']['emergency_contact_deletion']['label'] = '';
$handler->display->display_options['fields']['emergency_contact_deletion']['alter']['text'] = '<!-- This field is totally empty, but uses markup from civihr-employee-portal-theme to display the button. See civihr_default_theme/templates/view/views-view-field--emergency-contacts--non-dependant-emergency-contact--emergency_contact_deletion.tpl.php -->';
$handler->display->display_options['fields']['emergency_contact_deletion']['element_label_colon'] = FALSE;
/* Contextual filter: CiviCRM Custom: Emergency Contacts: Entity ID */
$handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
$handler->display->display_options['arguments']['entity_id']['table'] = 'civicrm_value_emergency_contacts_21';
$handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
$handler->display->display_options['arguments']['entity_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['entity_id']['default_argument_options']['code'] = 'return \\CRM_Core_Session::getLoggedInContactID();';
$handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['value'] = 'No';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['fields'] = array(
  'dependant_s__92' => 'dependant_s__92',
);

/* Display: Non Dependant Emergency Contacts */
$handler = $view->new_display('block', 'Non Dependant Emergency Contacts', 'non_dependant_emergency_contact');
$handler->display->display_options['display_description'] = 'A list of emergency contacts where the "dependant" flag is false';

/* Display: Dependant Emergency Contacts */
$handler = $view->new_display('block', 'Dependant Emergency Contacts', 'dependant_emergency_contact');
$handler->display->display_options['display_description'] = 'A list of emergency contacts where the "dependant" flag is true';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['value'] = 'Yes';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['fields'] = array(
  'dependant_s__92' => 'dependant_s__92',
);
$handler->display->display_options['block_description'] = 'dependant_emergency_contact';
$translatables['emergency_contacts'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('No results'),
  t('.'),
  t(','),
  t('Name'),
  t('Mobile Number'),
  t('Phone Number'),
  t('Primary Email'),
  t('Address'),
  t('Relationship with Employee'),
  t('Notes'),
  t('<!-- This field is totally empty, but uses markup from civihr-employee-portal-theme to display the button. See civihr_default_theme/templates/view/views-view-field--emergency-contacts--non-dependant-emergency-contact--emergency_contact_deletion.tpl.php -->'),
  t('All'),
  t('Non Dependant Emergency Contacts'),
  t('A list of emergency contacts where the "dependant" flag is false'),
  t('Dependant Emergency Contacts'),
  t('A list of emergency contacts where the "dependant" flag is true'),
  t('dependant_emergency_contact'),
);