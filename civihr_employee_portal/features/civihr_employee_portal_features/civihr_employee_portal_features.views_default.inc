<?php
/**
 * @file
 * civihr_employee_portal_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function civihr_employee_portal_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'civihr_report_custom_contacts_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'civicrm_contact';
  $view->human_name = 'CiviHR Report - Custom Contacts Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CiviHR Report - Custom Contacts Report';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'addressee_display' => 'addressee_display',
    'age' => 'age',
    'age_group' => 'age_group',
    'display_name' => 'display_name',
    'email_greeting_display' => 'email_greeting_display',
    'gender' => 'gender',
    'prefix_id' => 'prefix_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'addressee_display' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'age' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'age_group' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'display_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'email_greeting_display' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'gender' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'prefix_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: CiviCRM Contacts: Contact ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: CiviCRM Contacts: Addressee */
  $handler->display->display_options['fields']['addressee_display']['id'] = 'addressee_display';
  $handler->display->display_options['fields']['addressee_display']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['addressee_display']['field'] = 'addressee_display';
  /* Field: CiviCRM Contacts: Age */
  $handler->display->display_options['fields']['age']['id'] = 'age';
  $handler->display->display_options['fields']['age']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['age']['field'] = 'age';
  /* Field: CiviCRM Contacts: Age Group */
  $handler->display->display_options['fields']['age_group']['id'] = 'age_group';
  $handler->display->display_options['fields']['age_group']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['age_group']['field'] = 'age_group';
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
  /* Field: CiviCRM Contacts: Email Greeting */
  $handler->display->display_options['fields']['email_greeting_display']['id'] = 'email_greeting_display';
  $handler->display->display_options['fields']['email_greeting_display']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['email_greeting_display']['field'] = 'email_greeting_display';
  /* Field: CiviCRM Contacts: Gender */
  $handler->display->display_options['fields']['gender']['id'] = 'gender';
  $handler->display->display_options['fields']['gender']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['gender']['field'] = 'gender';
  /* Field: CiviCRM Contacts: Prefix */
  $handler->display->display_options['fields']['prefix_id']['id'] = 'prefix_id';
  $handler->display->display_options['fields']['prefix_id']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['prefix_id']['field'] = 'prefix_id';
  /* Filter criterion: CiviCRM Contacts: Contact ID */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'civicrm_contact';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['id']['expose']['operator_id'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['label'] = 'Contact ID';
  $handler->display->display_options['filters']['id']['expose']['operator'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['identifier'] = 'myfilter1';
  $handler->display->display_options['filters']['id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    55120974 => 0,
    17087012 => 0,
    57573969 => 0,
  );
  /* Filter criterion: CiviCRM Contacts: Display Name */
  $handler->display->display_options['filters']['display_name']['id'] = 'display_name';
  $handler->display->display_options['filters']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['filters']['display_name']['field'] = 'display_name';
  $handler->display->display_options['filters']['display_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['display_name']['expose']['operator_id'] = 'display_name_op';
  $handler->display->display_options['filters']['display_name']['expose']['label'] = 'Display Name';
  $handler->display->display_options['filters']['display_name']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['display_name']['expose']['operator'] = 'display_name_op';
  $handler->display->display_options['filters']['display_name']['expose']['identifier'] = 'display_name';
  $handler->display->display_options['filters']['display_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    55120974 => 0,
    17087012 => 0,
    57573969 => 0,
  );
  $handler->display->display_options['filters']['display_name']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['display_name']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['display_name']['expose']['autocomplete_field'] = 'display_name';
  $handler->display->display_options['filters']['display_name']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['display_name']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['display_name']['expose']['autocomplete_dependent'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = '';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'civihr_report_json_custom_contacts_report';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'civihr_report_table_custom_contacts_report');

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'civihr_report_export_custom_contacts_report';
  $translatables['civihr_report_custom_contacts_report'] = array(
    t('Master'),
    t('CiviHR Report - Custom Contacts Report'),
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
    t('Contact ID'),
    t('.'),
    t(','),
    t('Addressee'),
    t('Age'),
    t('Age Group'),
    t('Display Name'),
    t('Email Greeting'),
    t('Gender'),
    t('Prefix'),
    t('Page'),
    t('Block'),
    t('Data export'),
  );
  $export['civihr_report_custom_contacts_report'] = $view;

  $view = new view();
  $view->name = 'civihr_report_leave';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'civicrm_contact';
  $view->human_name = 'CiviHR Report - Leave';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CiviHR Report - Leave';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = '';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Relationship: CiviCRM Contacts: Absence approval entity */
  $handler->display->display_options['relationships']['absence_approval_list']['id'] = 'absence_approval_list';
  $handler->display->display_options['relationships']['absence_approval_list']['table'] = 'civicrm_contact';
  $handler->display->display_options['relationships']['absence_approval_list']['field'] = 'absence_approval_list';
  /* Field: CiviCRM Contacts: Contact ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: CiviCRM Contacts: Display Name */
  $handler->display->display_options['fields']['display_name']['id'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['display_name']['field'] = 'display_name';
  $handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
  /* Field: CiviCRM Contacts: Age Group */
  $handler->display->display_options['fields']['age_group']['id'] = 'age_group';
  $handler->display->display_options['fields']['age_group']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['age_group']['field'] = 'age_group';
  $handler->display->display_options['fields']['age_group']['label'] = 'Age';
  /* Field: CiviCRM Contacts: Gender */
  $handler->display->display_options['fields']['gender']['id'] = 'gender';
  $handler->display->display_options['fields']['gender']['table'] = 'civicrm_contact';
  $handler->display->display_options['fields']['gender']['field'] = 'gender';
  /* Field: Absence approval entity: Absence_title */
  $handler->display->display_options['fields']['absence_title']['id'] = 'absence_title';
  $handler->display->display_options['fields']['absence_title']['table'] = 'absence_approval_list';
  $handler->display->display_options['fields']['absence_title']['field'] = 'absence_title';
  $handler->display->display_options['fields']['absence_title']['relationship'] = 'absence_approval_list';
  $handler->display->display_options['fields']['absence_title']['label'] = 'Type';
  /* Field: Absence approval entity: Absence_start_date */
  $handler->display->display_options['fields']['absence_start_date']['id'] = 'absence_start_date';
  $handler->display->display_options['fields']['absence_start_date']['table'] = 'absence_approval_list';
  $handler->display->display_options['fields']['absence_start_date']['field'] = 'absence_start_date';
  $handler->display->display_options['fields']['absence_start_date']['relationship'] = 'absence_approval_list';
  $handler->display->display_options['fields']['absence_start_date']['label'] = 'Absence start date';
  /* Field: Absence approval entity: Absence_end_date */
  $handler->display->display_options['fields']['absence_end_date']['id'] = 'absence_end_date';
  $handler->display->display_options['fields']['absence_end_date']['table'] = 'absence_approval_list';
  $handler->display->display_options['fields']['absence_end_date']['field'] = 'absence_end_date';
  $handler->display->display_options['fields']['absence_end_date']['relationship'] = 'absence_approval_list';
  $handler->display->display_options['fields']['absence_end_date']['label'] = 'Absence end date';
  /* Field: Absence approval entity: Absence status */
  $handler->display->display_options['fields']['absence_status']['id'] = 'absence_status';
  $handler->display->display_options['fields']['absence_status']['table'] = 'absence_approval_list';
  $handler->display->display_options['fields']['absence_status']['field'] = 'absence_status';
  $handler->display->display_options['fields']['absence_status']['relationship'] = 'absence_approval_list';
  /* Field: Absence approval entity: Absence type row value (Duration) */
  $handler->display->display_options['fields']['duration']['id'] = 'duration';
  $handler->display->display_options['fields']['duration']['table'] = 'absence_approval_list';
  $handler->display->display_options['fields']['duration']['field'] = 'duration';
  $handler->display->display_options['fields']['duration']['relationship'] = 'absence_approval_list';
  $handler->display->display_options['fields']['duration']['label'] = 'Duration';
  $handler->display->display_options['fields']['duration']['duration_type'] = 'no_format';
  /* Field: Absence approval entity: Is_credit */
  $handler->display->display_options['fields']['is_credit']['id'] = 'is_credit';
  $handler->display->display_options['fields']['is_credit']['table'] = 'absence_approval_list';
  $handler->display->display_options['fields']['is_credit']['field'] = 'is_credit';
  $handler->display->display_options['fields']['is_credit']['relationship'] = 'absence_approval_list';
  $handler->display->display_options['fields']['is_credit']['label'] = 'Is credit';
  /* Contextual filter: Absence approval entity: Absence_start_date */
  $handler->display->display_options['arguments']['absence_start_date']['id'] = 'absence_start_date';
  $handler->display->display_options['arguments']['absence_start_date']['table'] = 'absence_approval_list';
  $handler->display->display_options['arguments']['absence_start_date']['field'] = 'absence_start_date';
  $handler->display->display_options['arguments']['absence_start_date']['relationship'] = 'absence_approval_list';
  $handler->display->display_options['arguments']['absence_start_date']['exception']['value'] = 'any';
  $handler->display->display_options['arguments']['absence_start_date']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['absence_start_date']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['absence_start_date']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['absence_start_date']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['absence_start_date']['civihr_range'] = '>=';
  $handler->display->display_options['arguments']['absence_start_date']['civihr_range_empty'] = '0';
  /* Contextual filter: Absence approval entity: Absence_end_date */
  $handler->display->display_options['arguments']['absence_end_date']['id'] = 'absence_end_date';
  $handler->display->display_options['arguments']['absence_end_date']['table'] = 'absence_approval_list';
  $handler->display->display_options['arguments']['absence_end_date']['field'] = 'absence_end_date';
  $handler->display->display_options['arguments']['absence_end_date']['relationship'] = 'absence_approval_list';
  $handler->display->display_options['arguments']['absence_end_date']['exception']['value'] = 'any';
  $handler->display->display_options['arguments']['absence_end_date']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['absence_end_date']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['absence_end_date']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['absence_end_date']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['absence_end_date']['civihr_range'] = '<=';
  $handler->display->display_options['arguments']['absence_end_date']['civihr_range_empty'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'civihr-report---leave';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'civihr-report---leave-csv';
  $translatables['civihr_report_leave'] = array(
    t('Master'),
    t('CiviHR Report - Leave'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Absence approval entity'),
    t('Contact ID'),
    t('.'),
    t(','),
    t('Display Name'),
    t('Age'),
    t('Gender'),
    t('Type'),
    t('Absence start date'),
    t('Absence end date'),
    t('Absence status'),
    t('Duration'),
    t('Is credit'),
    t('All'),
    t('Page'),
    t('Data export'),
  );
  $export['civihr_report_leave'] = $view;

  return $export;
}
