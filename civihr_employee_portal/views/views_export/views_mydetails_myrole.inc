<?php

$view = new view();
$view->name = 'mydetails_myrole';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'MyDetails_MyRole';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Roles';
$handler->display->display_options['css_class'] = 'my-details-view-panel';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view my details';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_tags'] = array(
  0 => 'civihr_employee_portal_alter_date_conditions',
);
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No job role information listed!';
$handler->display->display_options['empty']['area']['format'] = 'full_html';
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
/* Field: HRJobContract Role entity: Role_title */
$handler->display->display_options['fields']['role_title_1']['id'] = 'role_title_1';
$handler->display->display_options['fields']['role_title_1']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_title_1']['field'] = 'role_title';
$handler->display->display_options['fields']['role_title_1']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_title_1']['label'] = '';
$handler->display->display_options['fields']['role_title_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['role_title_1']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['role_title_1']['alter']['text'] = '<div class="views-field views-field-role-title-1">
<span class="views-label">Role Title</span>
<span class="field-content">[role_title_1]</span>
</div>';
$handler->display->display_options['fields']['role_title_1']['element_label_colon'] = FALSE;
/* Field: HRJobContract Role entity: Role_location */
$handler->display->display_options['fields']['role_location_2']['id'] = 'role_location_2';
$handler->display->display_options['fields']['role_location_2']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_location_2']['field'] = 'role_location';
$handler->display->display_options['fields']['role_location_2']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_location_2']['label'] = '';
$handler->display->display_options['fields']['role_location_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['role_location_2']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['role_location_2']['alter']['text'] = '<div class="views-field views-field-role-location-2">
<span class="views-label views-label-role-location-2">Location</span>
<span class="field-content">[role_location_2]</span>
</div>';
$handler->display->display_options['fields']['role_location_2']['element_label_colon'] = FALSE;
/* Field: HRJobContract Role entity: Role_department */
$handler->display->display_options['fields']['role_department']['id'] = 'role_department';
$handler->display->display_options['fields']['role_department']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_department']['field'] = 'role_department';
$handler->display->display_options['fields']['role_department']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_department']['label'] = 'Department';
$handler->display->display_options['fields']['role_department']['exclude'] = TRUE;
$handler->display->display_options['fields']['role_department']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['role_department']['alter']['text'] = '<div class="views-field views-field-role-department">
<span class="views-label views-label-role-department">Department</span>
<span class="field-content">[role_department]</span>
</div>';
$handler->display->display_options['fields']['role_department']['element_label_colon'] = FALSE;
/* Field: HRJobContract Role entity: Role_region */
$handler->display->display_options['fields']['role_region']['id'] = 'role_region';
$handler->display->display_options['fields']['role_region']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_region']['field'] = 'role_region';
$handler->display->display_options['fields']['role_region']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_region']['label'] = 'Region';
$handler->display->display_options['fields']['role_region']['exclude'] = TRUE;
$handler->display->display_options['fields']['role_region']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['role_region']['alter']['text'] = '<div class="views-field views-field-role-region">
<span class="views-label views-label-role-region">Region</span>
<span class="field-content">[role_region]</span>
</div>';
$handler->display->display_options['fields']['role_region']['element_label_colon'] = FALSE;
/* Field: HRJobContract Role entity: Role_level_type */
$handler->display->display_options['fields']['role_level_type']['id'] = 'role_level_type';
$handler->display->display_options['fields']['role_level_type']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_level_type']['field'] = 'role_level_type';
$handler->display->display_options['fields']['role_level_type']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_level_type']['label'] = 'Level';
$handler->display->display_options['fields']['role_level_type']['exclude'] = TRUE;
$handler->display->display_options['fields']['role_level_type']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['role_level_type']['alter']['text'] = '<div class="views-field views-field-role-level-type">
<span class="views-label views-label-role-level-type">Level</span>
<span class="field-content">[role_level_type]</span>
</div>';
$handler->display->display_options['fields']['role_level_type']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="panel-panel">
  <div class="panel-panel-inner">
    <div class="panel-pane pane-block">
      <h2 class="pane-title">
        Job Role
      </h2>
      <div class="pane-content">
    [role_title_1]
    [role_location_2]
    [role_department]
    [role_region]
    [role_level_type]

      </div>
    </div>
  </div>
</div>


';
$handler->display->display_options['fields']['nothing_1']['element_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_label_type'] = '0';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = '0';
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'OR',
  2 => 'OR',
);
/* Filter criterion: HRJobContract Role entity: Role start date */
$handler->display->display_options['filters']['role_start_date_1']['id'] = 'role_start_date_1';
$handler->display->display_options['filters']['role_start_date_1']['table'] = 'hrjc_role';
$handler->display->display_options['filters']['role_start_date_1']['field'] = 'role_start_date';
$handler->display->display_options['filters']['role_start_date_1']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['filters']['role_start_date_1']['operator'] = 'empty';
$handler->display->display_options['filters']['role_start_date_1']['group'] = 1;
/* Filter criterion: HRJobContract Role entity: Role start date */
$handler->display->display_options['filters']['role_start_date']['id'] = 'role_start_date';
$handler->display->display_options['filters']['role_start_date']['table'] = 'hrjc_role';
$handler->display->display_options['filters']['role_start_date']['field'] = 'role_start_date';
$handler->display->display_options['filters']['role_start_date']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['filters']['role_start_date']['operator'] = '<=';
$handler->display->display_options['filters']['role_start_date']['value']['value'] = 'now';
$handler->display->display_options['filters']['role_start_date']['value']['type'] = 'offset';
$handler->display->display_options['filters']['role_start_date']['group'] = 1;
/* Filter criterion: HRJobContract Role entity: Role end date */
$handler->display->display_options['filters']['role_end_date_1']['id'] = 'role_end_date_1';
$handler->display->display_options['filters']['role_end_date_1']['table'] = 'hrjc_role';
$handler->display->display_options['filters']['role_end_date_1']['field'] = 'role_end_date';
$handler->display->display_options['filters']['role_end_date_1']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['filters']['role_end_date_1']['operator'] = 'empty';
$handler->display->display_options['filters']['role_end_date_1']['group'] = 2;
/* Filter criterion: HRJobContract Role entity: Role end date */
$handler->display->display_options['filters']['role_end_date']['id'] = 'role_end_date';
$handler->display->display_options['filters']['role_end_date']['table'] = 'hrjc_role';
$handler->display->display_options['filters']['role_end_date']['field'] = 'role_end_date';
$handler->display->display_options['filters']['role_end_date']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['filters']['role_end_date']['operator'] = '>=';
$handler->display->display_options['filters']['role_end_date']['value']['value'] = 'now';
$handler->display->display_options['filters']['role_end_date']['value']['type'] = 'offset';
$handler->display->display_options['filters']['role_end_date']['group'] = 2;

/* Display: My Roles */
$handler = $view->new_display('block', 'My Roles', 'my_role');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Relationship: CiviCRM Contacts: HRJobContract Revision entity */
$handler->display->display_options['relationships']['hrjc_revision']['id'] = 'hrjc_revision';
$handler->display->display_options['relationships']['hrjc_revision']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_revision']['field'] = 'hrjc_revision';
$handler->display->display_options['relationships']['hrjc_revision']['relationship'] = 'drupal_id';
$handler->display->display_options['relationships']['hrjc_revision']['required'] = TRUE;
/* Relationship: HRJobContract Revision entity: Role_jobcontract_id */
$handler->display->display_options['relationships']['role_jobcontract_id']['id'] = 'role_jobcontract_id';
$handler->display->display_options['relationships']['role_jobcontract_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['role_jobcontract_id']['field'] = 'role_jobcontract_id';
$handler->display->display_options['relationships']['role_jobcontract_id']['relationship'] = 'hrjc_revision';
$handler->display->display_options['relationships']['role_jobcontract_id']['required'] = TRUE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: User: Uid */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'users';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['relationship'] = 'drupal_id';
$handler->display->display_options['arguments']['uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
$translatables['mydetails_myrole'] = array(
  t('Master'),
  t('My Roles'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('No job role information listed!'),
  t('Drupal User'),
  t('HRJobContract Revision entity'),
  t('HRJobContract Details entity'),
  t('<div class="views-field views-field-role-title-1">
<span class="views-label">Role Title</span>
<span class="field-content">[role_title_1]</span>
</div>'),
  t('<div class="views-field views-field-role-location-2">
<span class="views-label views-label-role-location-2">Location</span>
<span class="field-content">[role_location_2]</span>
</div>'),
  t('Department'),
  t('<div class="views-field views-field-role-department">
<span class="views-label views-label-role-department">Department</span>
<span class="field-content">[role_department]</span>
</div>'),
  t('Region'),
  t('<div class="views-field views-field-role-region">
<span class="views-label views-label-role-region">Region</span>
<span class="field-content">[role_region]</span>
</div>'),
  t('Level'),
  t('<div class="views-field views-field-role-level-type">
<span class="views-label views-label-role-level-type">Level</span>
<span class="field-content">[role_level_type]</span>
</div>'),
  t('<div class="panel-panel">
  <div class="panel-panel-inner">
    <div class="panel-pane pane-block">
      <h2 class="pane-title">
        Job Role
      </h2>
      <div class="pane-content">
    [role_title_1]
    [role_location_2]
    [role_department]
    [role_region]
    [role_level_type]

      </div>
    </div>
  </div>
</div>


'),
  t('HRJobContract Role entity'),
  t('All'),
);
