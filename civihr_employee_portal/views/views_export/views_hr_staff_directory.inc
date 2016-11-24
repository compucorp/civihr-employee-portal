<?php

/**
 * Exported hr_staff_directory view
 */

$view = new view();
$view->name = 'civihr_staff_directory';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'CiviHR - Staff Directory';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Staff Directory';
$handler->display->display_options['css_class'] = 'view-hr-staff-directory';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view staff directory';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '2, 5, 10, 20, 40, 60';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'image_URL' => 'image_URL',
  'first_name' => 'first_name',
  'last_name' => 'last_name',
  'display_name' => 'display_name',
  'phone' => 'phone',
  'phone_ext' => 'phone_ext',
  'title' => 'title',
  'email' => 'email',
  'location' => 'location',
  'contract_type' => 'contract_type',
  'department' => 'department',
  'end_date' => 'end_date',
  'is_active' => 'is_active',
  'start_date' => 'start_date',
  'end_date_1' => 'end_date_1',
  'start_date_1' => 'start_date_1',
  'display_name_1' => 'display_name_1',
  'is_primary' => 'is_primary',
  'email_1' => 'email_1',
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
  'image_URL' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'first_name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'last_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'display_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'phone' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'phone_ext' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'email' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'location' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'contract_type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'department' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'end_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'is_active' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'start_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'end_date_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'start_date_1' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'display_name_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'is_primary' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'email_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Header: Global: Result summary */
$handler->display->display_options['header']['result']['id'] = 'result';
$handler->display->display_options['header']['result']['table'] = 'views';
$handler->display->display_options['header']['result']['field'] = 'result';
$handler->display->display_options['header']['result']['content'] = '@total';
/* Footer: Global: Unfiltered text */
$handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
$handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
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
/* Relationship: CiviCRM Email: Email Address */
$handler->display->display_options['relationships']['id']['id'] = 'id';
$handler->display->display_options['relationships']['id']['table'] = 'civicrm_email';
$handler->display->display_options['relationships']['id']['field'] = 'id';
$handler->display->display_options['relationships']['id']['label'] = 'Email Address';
$handler->display->display_options['relationships']['id']['location_type'] = '0';
$handler->display->display_options['relationships']['id']['location_op'] = '0';
$handler->display->display_options['relationships']['id']['is_primary'] = 1;
/* Relationship: CiviCRM Contacts: CiviCRM Relationship (starting from contact A) */
$handler->display->display_options['relationships']['relationship_id_a']['id'] = 'relationship_id_a';
$handler->display->display_options['relationships']['relationship_id_a']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['relationship_id_a']['field'] = 'relationship_id_a';
$handler->display->display_options['relationships']['relationship_id_a']['relationship_type'] = array();
/* Relationship: CiviCRM Relationships: Contact ID B */
$handler->display->display_options['relationships']['contact_id_b_']['id'] = 'contact_id_b_';
$handler->display->display_options['relationships']['contact_id_b_']['table'] = 'civicrm_relationship';
$handler->display->display_options['relationships']['contact_id_b_']['field'] = 'contact_id_b_';
$handler->display->display_options['relationships']['contact_id_b_']['relationship'] = 'relationship_id_a';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Contacts: Contact Image */
$handler->display->display_options['fields']['image_URL']['id'] = 'image_URL';
$handler->display->display_options['fields']['image_URL']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['image_URL']['field'] = 'image_URL';
$handler->display->display_options['fields']['image_URL']['label'] = '';
$handler->display->display_options['fields']['image_URL']['exclude'] = TRUE;
$handler->display->display_options['fields']['image_URL']['element_label_colon'] = FALSE;
/* Field: CiviCRM Contacts: First Name */
$handler->display->display_options['fields']['first_name']['id'] = 'first_name';
$handler->display->display_options['fields']['first_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['first_name']['field'] = 'first_name';
$handler->display->display_options['fields']['first_name']['label'] = 'Name';
$handler->display->display_options['fields']['first_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['first_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Contacts: Last Name */
$handler->display->display_options['fields']['last_name']['id'] = 'last_name';
$handler->display->display_options['fields']['last_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['last_name']['field'] = 'last_name';
$handler->display->display_options['fields']['last_name']['label'] = 'Name';
$handler->display->display_options['fields']['last_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['label'] = 'Name';
$handler->display->display_options['fields']['display_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['display_name']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['display_name']['alter']['text'] = '[first_name] [last_name]';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Phone Details: Phone */
$handler->display->display_options['fields']['phone']['id'] = 'phone';
$handler->display->display_options['fields']['phone']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone']['field'] = 'phone';
$handler->display->display_options['fields']['phone']['label'] = 'Work Phone';
$handler->display->display_options['fields']['phone']['location_type'] = '2';
$handler->display->display_options['fields']['phone']['location_op'] = '0';
$handler->display->display_options['fields']['phone']['is_primary'] = 0;
$handler->display->display_options['fields']['phone']['phone_type'] = '0';
/* Field: CiviCRM Phone Details: Phone Number Extension */
$handler->display->display_options['fields']['phone_ext']['id'] = 'phone_ext';
$handler->display->display_options['fields']['phone_ext']['table'] = 'civicrm_phone';
$handler->display->display_options['fields']['phone_ext']['field'] = 'phone_ext';
$handler->display->display_options['fields']['phone_ext']['label'] = 'Work Phone Extension';
$handler->display->display_options['fields']['phone_ext']['location_type'] = '2';
$handler->display->display_options['fields']['phone_ext']['location_op'] = '0';
$handler->display->display_options['fields']['phone_ext']['is_primary'] = 0;
$handler->display->display_options['fields']['phone_ext']['phone_type'] = '0';
/* Field: HRJobContract Details entity: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['title']['label'] = 'Job Title';
/* Field: CiviCRM Email: Email Address */
$handler->display->display_options['fields']['email_1']['id'] = 'email_1';
$handler->display->display_options['fields']['email_1']['table'] = 'civicrm_email';
$handler->display->display_options['fields']['email_1']['field'] = 'email';
$handler->display->display_options['fields']['email_1']['relationship'] = 'id';
$handler->display->display_options['fields']['email_1']['location_type'] = '0';
$handler->display->display_options['fields']['email_1']['location_op'] = '0';
$handler->display->display_options['fields']['email_1']['is_primary'] = 0;
/* Field: HRJobContract Details entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['fields']['location']['relationship'] = 'details_revision_id';
/* Field: HRJobContract Details entity: Contract_type */
$handler->display->display_options['fields']['contract_type']['id'] = 'contract_type';
$handler->display->display_options['fields']['contract_type']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['contract_type']['field'] = 'contract_type';
$handler->display->display_options['fields']['contract_type']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['contract_type']['label'] = ' Contract Type ';
/* Field: HRJobContract Role entity: Role_department */
$handler->display->display_options['fields']['department']['id'] = 'department';
$handler->display->display_options['fields']['department']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['department']['field'] = 'role_department';
$handler->display->display_options['fields']['department']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['department']['label'] = 'Department';
/* Field: CiviCRM Relationships: End Date */
$handler->display->display_options['fields']['end_date']['id'] = 'end_date';
$handler->display->display_options['fields']['end_date']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['end_date']['field'] = 'end_date';
$handler->display->display_options['fields']['end_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['end_date']['date_format'] = 'long';
$handler->display->display_options['fields']['end_date']['second_date_format'] = 'long';
/* Field: CiviCRM Relationships: Is Relationship Active */
$handler->display->display_options['fields']['is_active']['id'] = 'is_active';
$handler->display->display_options['fields']['is_active']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['is_active']['field'] = 'is_active';
$handler->display->display_options['fields']['is_active']['exclude'] = TRUE;
$handler->display->display_options['fields']['is_active']['not'] = 0;
/* Field: CiviCRM Relationships: Start Date */
$handler->display->display_options['fields']['start_date']['id'] = 'start_date';
$handler->display->display_options['fields']['start_date']['table'] = 'civicrm_relationship';
$handler->display->display_options['fields']['start_date']['field'] = 'start_date';
$handler->display->display_options['fields']['start_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['start_date']['date_format'] = 'long';
$handler->display->display_options['fields']['start_date']['second_date_format'] = 'long';
/* Field: HRJobContract Role entity: Role end date */
$handler->display->display_options['fields']['end_date_1']['id'] = 'end_date_1';
$handler->display->display_options['fields']['end_date_1']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['end_date_1']['field'] = 'role_end_date';
$handler->display->display_options['fields']['end_date_1']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['end_date_1']['exclude'] = TRUE;
/* Field: Broken/missing handler */
$handler->display->display_options['fields']['start_date_1']['id'] = 'start_date_1';
$handler->display->display_options['fields']['start_date_1']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['start_date_1']['field'] = 'role_star_date';
$handler->display->display_options['fields']['start_date_1']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['start_date_1']['exclude'] = TRUE;
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name_1']['id'] = 'display_name_1';
$handler->display->display_options['fields']['display_name_1']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name_1']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name_1']['relationship'] = 'contact_id_b_';
$handler->display->display_options['fields']['display_name_1']['label'] = 'Manager';
$handler->display->display_options['fields']['display_name_1']['link_to_civicrm_contact'] = 0;
/* Sort criterion: CiviCRM Contacts: Contact ID */
$handler->display->display_options['sorts']['id']['id'] = 'id';
$handler->display->display_options['sorts']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['sorts']['id']['field'] = 'id';
/* Filter criterion: CiviCRM Contacts: Contact Type */
$handler->display->display_options['filters']['contact_type']['id'] = 'contact_type';
$handler->display->display_options['filters']['contact_type']['table'] = 'civicrm_contact';
$handler->display->display_options['filters']['contact_type']['field'] = 'contact_type';
$handler->display->display_options['filters']['contact_type']['value'] = array(
  'Individual' => 'Individual',
);
$handler->display->display_options['filters']['contact_type']['group'] = 1;
/* Filter criterion: CiviCRM Contacts: Display Name */
$handler->display->display_options['filters']['display_name']['id'] = 'display_name';
$handler->display->display_options['filters']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['filters']['display_name']['field'] = 'display_name';
$handler->display->display_options['filters']['display_name']['operator'] = 'contains';
$handler->display->display_options['filters']['display_name']['group'] = 1;
$handler->display->display_options['filters']['display_name']['exposed'] = TRUE;
$handler->display->display_options['filters']['display_name']['expose']['operator_id'] = 'display_name_op';
$handler->display->display_options['filters']['display_name']['expose']['label'] = 'Name';
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
$handler->display->display_options['filters']['display_name']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['display_name']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['display_name']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['display_name']['expose']['autocomplete_field'] = 'display_name';
$handler->display->display_options['filters']['display_name']['expose']['autocomplete_raw_suggestion'] = 0;
$handler->display->display_options['filters']['display_name']['expose']['autocomplete_raw_dropdown'] = 0;
$handler->display->display_options['filters']['display_name']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: HRJobContract Details entity: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'hrjc_details';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['relationship'] = 'details_revision_id';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['group'] = 1;
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Job Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: CiviCRM Phone Details: Phone */
$handler->display->display_options['filters']['phone']['id'] = 'phone';
$handler->display->display_options['filters']['phone']['table'] = 'civicrm_phone';
$handler->display->display_options['filters']['phone']['field'] = 'phone';
$handler->display->display_options['filters']['phone']['operator'] = 'contains';
$handler->display->display_options['filters']['phone']['group'] = 1;
$handler->display->display_options['filters']['phone']['exposed'] = TRUE;
$handler->display->display_options['filters']['phone']['expose']['operator_id'] = 'phone_op';
$handler->display->display_options['filters']['phone']['expose']['label'] = 'Phone';
$handler->display->display_options['filters']['phone']['expose']['operator'] = 'phone_op';
$handler->display->display_options['filters']['phone']['expose']['identifier'] = 'phone';
$handler->display->display_options['filters']['phone']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['phone']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['phone']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['phone']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['phone']['expose']['autocomplete_field'] = 'phone';
$handler->display->display_options['filters']['phone']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['phone']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['phone']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: CiviCRM Email: Email Address */
$handler->display->display_options['filters']['email']['id'] = 'email';
$handler->display->display_options['filters']['email']['table'] = 'civicrm_email';
$handler->display->display_options['filters']['email']['field'] = 'email';
$handler->display->display_options['filters']['email']['relationship'] = 'id';
$handler->display->display_options['filters']['email']['operator'] = 'contains';
$handler->display->display_options['filters']['email']['group'] = 1;
$handler->display->display_options['filters']['email']['exposed'] = TRUE;
$handler->display->display_options['filters']['email']['expose']['operator_id'] = 'email_op';
$handler->display->display_options['filters']['email']['expose']['label'] = 'Email';
$handler->display->display_options['filters']['email']['expose']['operator'] = 'email_op';
$handler->display->display_options['filters']['email']['expose']['identifier'] = 'email';
$handler->display->display_options['filters']['email']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  55120974 => 0,
  17087012 => 0,
  57573969 => 0,
);
$handler->display->display_options['filters']['email']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['email']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['email']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['email']['expose']['autocomplete_field'] = 'email_1';
$handler->display->display_options['filters']['email']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['email']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['email']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: HRJobContract Role entity: Role_department */
$handler->display->display_options['filters']['department']['id'] = 'department';
$handler->display->display_options['filters']['department']['table'] = 'hrjc_role';
$handler->display->display_options['filters']['department']['field'] = 'role_department';
$handler->display->display_options['filters']['department']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['filters']['department']['operator'] = 'contains';
$handler->display->display_options['filters']['department']['group'] = 1;
$handler->display->display_options['filters']['department']['exposed'] = TRUE;
$handler->display->display_options['filters']['department']['expose']['operator_id'] = 'department_op';
$handler->display->display_options['filters']['department']['expose']['label'] = 'Department';
$handler->display->display_options['filters']['department']['expose']['operator'] = 'department_op';
$handler->display->display_options['filters']['department']['expose']['identifier'] = 'department';
$handler->display->display_options['filters']['department']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['department']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['department']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['department']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['department']['expose']['autocomplete_field'] = 'department';
$handler->display->display_options['filters']['department']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['department']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['department']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: HRJobContract Details entity: Location */
$handler->display->display_options['filters']['location']['id'] = 'location';
$handler->display->display_options['filters']['location']['table'] = 'hrjc_details';
$handler->display->display_options['filters']['location']['field'] = 'location';
$handler->display->display_options['filters']['location']['relationship'] = 'details_revision_id';
$handler->display->display_options['filters']['location']['operator'] = 'contains';
$handler->display->display_options['filters']['location']['group'] = 1;
$handler->display->display_options['filters']['location']['exposed'] = TRUE;
$handler->display->display_options['filters']['location']['expose']['operator_id'] = 'location_op';
$handler->display->display_options['filters']['location']['expose']['label'] = 'Location';
$handler->display->display_options['filters']['location']['expose']['operator'] = 'location_op';
$handler->display->display_options['filters']['location']['expose']['identifier'] = 'location';
$handler->display->display_options['filters']['location']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  6 => 0,
  5 => 0,
);
$handler->display->display_options['filters']['location']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['location']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['location']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['location']['expose']['autocomplete_field'] = 'location';
$handler->display->display_options['filters']['location']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['location']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['location']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: CiviCRM Contacts: Display Name */
$handler->display->display_options['filters']['display_name_1']['id'] = 'display_name_1';
$handler->display->display_options['filters']['display_name_1']['table'] = 'civicrm_contact';
$handler->display->display_options['filters']['display_name_1']['field'] = 'display_name';
$handler->display->display_options['filters']['display_name_1']['relationship'] = 'contact_id_b_';
$handler->display->display_options['filters']['display_name_1']['operator'] = 'contains';
$handler->display->display_options['filters']['display_name_1']['group'] = 1;
$handler->display->display_options['filters']['display_name_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['display_name_1']['expose']['operator_id'] = 'display_name_1_op';
$handler->display->display_options['filters']['display_name_1']['expose']['label'] = 'Manager';
$handler->display->display_options['filters']['display_name_1']['expose']['operator'] = 'display_name_1_op';
$handler->display->display_options['filters']['display_name_1']['expose']['identifier'] = 'display_name_1';
$handler->display->display_options['filters']['display_name_1']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  55120974 => 0,
  17087012 => 0,
  57573969 => 0,
);
$handler->display->display_options['filters']['display_name_1']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['display_name_1']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['display_name_1']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['display_name_1']['expose']['autocomplete_field'] = 'display_name_1';
$handler->display->display_options['filters']['display_name_1']['expose']['autocomplete_raw_suggestion'] = 0;
$handler->display->display_options['filters']['display_name_1']['expose']['autocomplete_raw_dropdown'] = 0;
$handler->display->display_options['filters']['display_name_1']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: HRJobContract Details entity: Is_primary */
$handler->display->display_options['filters']['is_primary']['id'] = 'is_primary';
$handler->display->display_options['filters']['is_primary']['table'] = 'hrjc_details';
$handler->display->display_options['filters']['is_primary']['field'] = 'is_primary';
$handler->display->display_options['filters']['is_primary']['relationship'] = 'details_revision_id';
$handler->display->display_options['filters']['is_primary']['value']['value'] = '1';
$handler->display->display_options['filters']['is_primary']['group'] = 1;
/* Filter criterion: CiviCRM Contacts: Is Deleted */
$handler->display->display_options['filters']['is_deleted']['id'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['table'] = 'civicrm_contact';
$handler->display->display_options['filters']['is_deleted']['field'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['value'] = '0';

/* Display: Staff directory list page */
$handler = $view->new_display('page', 'Staff directory list page', 'page');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '2, 5, 10, 20, 40, 60';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
$handler->display->display_options['pager']['options']['tags']['first'] = 'First';
$handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
$handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
$handler->display->display_options['pager']['options']['tags']['last'] = 'Last';
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
$handler->display->display_options['arguments']['period_start_date']['civihr_range_empty'] = '0';
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
$handler->display->display_options['merge_rows'] = TRUE;
$handler->display->display_options['field_config'] = array(
  'id' => array(
    'merge_option' => 'filter',
    'separator' => ', ',
  ),
  'image_URL' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'nothing' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'display_name' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'phone' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'title' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'email' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'location' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'contract_type' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'department' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'display_name_1' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
);
$handler->display->display_options['path'] = 'staff-directory';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Staff Directory';
$handler->display->display_options['menu']['weight'] = '20';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['civihr_staff_directory'] = array(
  t('Master'),
  t('Staff Directory'),
  t('more'),
  t('Search'),
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
  t('@total'),
  t('HRJobContract Revision entity'),
  t('HRJobContract Details entity'),
  t('HRJobContract Role entity'),
  t('Email Address'),
  t('CiviCRM Relationship (starting from contact A)'),
  t('CiviCRM Contact B'),
  t('Contact ID'),
  t('.'),
  t('Name'),
  t('[first_name] [last_name]'),
  t('Work Phone'),
  t('Work Phone Extension'),
  t('Job Title'),
  t('Location'),
  t(' Contract Type '),
  t('Department'),
  t('End Date'),
  t('Is Relationship Active'),
  t('Start Date'),
  t('Role end date'),
  t('Broken handler hrjc_role.role_star_date'),
  t('Manager'),
  t('Phone'),
  t('Email'),
  t('Staff directory list page'),
  t('First'),
  t('Previous'),
  t('Next'),
  t('Last'),
  t('All'),
);
