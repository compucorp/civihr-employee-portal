<?php

global $base_url;

$view = new view();
$view->name = 'Tasks';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'json';
$view->human_name = 'Tasks';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Tasks';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  3 => '3',
  55120974 => '55120974',
  57573969 => '57573969',
  17087012 => '17087012',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/civi_tasks/';
$handler->display->display_options['query']['options']['row_apath'] = 'values';
$handler->display->display_options['query']['options']['show_errors'] = 1;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['row_class'] = 'row-fluid';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'id' => 'id',
  'subject' => 'subject',
  'details' => 'details',
);
/* Field: id: value */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'json';
$handler->display->display_options['fields']['id']['field'] = 'value';
$handler->display->display_options['fields']['id']['label'] = 'Task ID';
$handler->display->display_options['fields']['id']['key'] = 'id';
/* Field: activity_type_id: value */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'json';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'value';
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Activity Type ID';
$handler->display->display_options['fields']['activity_type_id']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['activity_type_id']['key'] = 'activity_type_id';
/* Field: case_id: value */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'json';
$handler->display->display_options['fields']['case_id']['field'] = 'value';
$handler->display->display_options['fields']['case_id']['label'] = 'Case ID';
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['case_id']['key'] = 'case_id';
/* Field: subject: value */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'json';
$handler->display->display_options['fields']['subject']['field'] = 'value';
$handler->display->display_options['fields']['subject']['label'] = 'Subject';
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['subject']['key'] = 'subject';
/* Field: activity_date_time: value */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'json';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'value';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Activity Date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['activity_date_time']['key'] = 'activity_date_time';
/* Field: expire_date: value */
$handler->display->display_options['fields']['expire_date']['id'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['table'] = 'json';
$handler->display->display_options['fields']['expire_date']['field'] = 'value';
$handler->display->display_options['fields']['expire_date']['label'] = 'Expire Date';
$handler->display->display_options['fields']['expire_date']['element_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['expire_date']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['expire_date']['key'] = 'expire_date';
/* Field: details: value */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'json';
$handler->display->display_options['fields']['details']['field'] = 'value';
$handler->display->display_options['fields']['details']['label'] = 'Details';
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['details']['key'] = 'details';
/* Field: file_count: value */
$handler->display->display_options['fields']['file_count']['id'] = 'file_count';
$handler->display->display_options['fields']['file_count']['table'] = 'json';
$handler->display->display_options['fields']['file_count']['field'] = 'value';
$handler->display->display_options['fields']['file_count']['label'] = 'File Count';
$handler->display->display_options['fields']['file_count']['element_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['file_count']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['file_count']['key'] = 'file_count';
/* Field: status_id: value */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'json';
$handler->display->display_options['fields']['status_id']['field'] = 'value';
$handler->display->display_options['fields']['status_id']['label'] = 'Status ID';
$handler->display->display_options['fields']['status_id']['element_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['status_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['status_id']['key'] = 'status_id';
/* Field: target_contact_id: Task contacts */
$handler->display->display_options['fields']['task_contacts']['id'] = 'task_contacts';
$handler->display->display_options['fields']['task_contacts']['table'] = 'json';
$handler->display->display_options['fields']['task_contacts']['field'] = 'task_contacts';
$handler->display->display_options['fields']['task_contacts']['label'] = 'Task contacts (target)';
$handler->display->display_options['fields']['task_contacts']['key'] = 'target_contact_id';
/* Field: assignee_contact_id: Task contacts */
$handler->display->display_options['fields']['task_contacts_1']['id'] = 'task_contacts_1';
$handler->display->display_options['fields']['task_contacts_1']['table'] = 'json';
$handler->display->display_options['fields']['task_contacts_1']['field'] = 'task_contacts';
$handler->display->display_options['fields']['task_contacts_1']['label'] = 'Task contacts (assignee)';
$handler->display->display_options['fields']['task_contacts_1']['key'] = 'assignee_contact_id';
/* Contextual filter: Json: Task contacts */
$handler->display->display_options['arguments']['task_targets']['id'] = 'task_targets';
$handler->display->display_options['arguments']['task_targets']['table'] = 'json';
$handler->display->display_options['arguments']['task_targets']['field'] = 'task_contacts';
$handler->display->display_options['arguments']['task_targets']['default_action'] = 'default';
$handler->display->display_options['arguments']['task_targets']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['task_targets']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['task_targets']['name'] = 'task_targets';

/* Display: Tasks Dashboard block */
$handler = $view->new_display('block', 'Tasks Dashboard block', 'block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Tasks';
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/civi_tasks/';
$handler->display->display_options['query']['options']['row_apath'] = 'values';
$handler->display->display_options['query']['options']['show_errors'] = 1;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'activity_type_id' => 'activity_type_id',
  'case_id' => 'case_id',
  'subject' => 'subject',
  'activity_date_time' => 'activity_date_time',
  'expire_date' => 'expire_date',
  'details' => 'details',
  'source_contact_id' => 'source_contact_id',
  'target_contact_id' => 'target_contact_id',
  'assignee_contact_id' => 'assignee_contact_id',
  'file_count' => 'file_count',
  'status_id' => 'status_id',
  'task_targets' => 'task_targets',
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
  'activity_type_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'case_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'subject' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'activity_date_time' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'expire_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'details' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'source_contact_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'target_contact_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'assignee_contact_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'file_count' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'task_targets' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<div class="tasks-list-actions"><div id="nav-tasks-types" class="btn-group btn-group-sm"><a href class="btn btn-gray" data-task-type="my">My Tasks</a><a href class="btn btn-gray" data-task-type="delegated">Delegated Tasks</a><a href class="btn btn-gray active" data-task-type="all">All</a></div><div id="tasks-list-header-additional"><a href="/civi_tasks/nojs/view_completed" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">Show completed tasks</a><input type="text" name="task-filter-name" value="" placeholder="Enter name" /></div></div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: id: value */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'json';
$handler->display->display_options['fields']['id']['field'] = 'value';
$handler->display->display_options['fields']['id']['label'] = 'Task ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['key'] = 'id';
/* Field: activity_type_id: value */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'json';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'value';
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Type';
$handler->display->display_options['fields']['activity_type_id']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['activity_type_id']['key'] = 'activity_type_id';
/* Field: case_id: value */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'json';
$handler->display->display_options['fields']['case_id']['field'] = 'value';
$handler->display->display_options['fields']['case_id']['label'] = 'Assignment';
$handler->display->display_options['fields']['case_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['case_id']['key'] = 'case_id';
/* Field: subject: value */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'json';
$handler->display->display_options['fields']['subject']['field'] = 'value';
$handler->display->display_options['fields']['subject']['label'] = 'Subject';
$handler->display->display_options['fields']['subject']['exclude'] = TRUE;
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['subject']['key'] = 'subject';
/* Field: activity_date_time: value */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'json';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'value';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due Date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['activity_date_time']['key'] = 'activity_date_time';
/* Field: expire_date: value */
$handler->display->display_options['fields']['expire_date']['id'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['table'] = 'json';
$handler->display->display_options['fields']['expire_date']['field'] = 'value';
$handler->display->display_options['fields']['expire_date']['label'] = 'Expire Date';
$handler->display->display_options['fields']['expire_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['expire_date']['element_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['expire_date']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['expire_date']['key'] = 'expire_date';
/* Field: file_count: value */
$handler->display->display_options['fields']['file_count']['id'] = 'file_count';
$handler->display->display_options['fields']['file_count']['table'] = 'json';
$handler->display->display_options['fields']['file_count']['field'] = 'value';
$handler->display->display_options['fields']['file_count']['label'] = 'File Count';
$handler->display->display_options['fields']['file_count']['exclude'] = TRUE;
$handler->display->display_options['fields']['file_count']['element_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_class'] = 'hidden';
$handler->display->display_options['fields']['file_count']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['file_count']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['file_count']['key'] = 'file_count';
/* Field: status_id: value */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'json';
$handler->display->display_options['fields']['status_id']['field'] = 'value';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
$handler->display->display_options['fields']['status_id']['element_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['status_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['status_id']['key'] = 'status_id';
/* Field: details: value */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'json';
$handler->display->display_options['fields']['details']['field'] = 'value';
$handler->display->display_options['fields']['details']['label'] = 'Details';
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['details']['key'] = 'details';
/* Field: target_contact_id: Task contacts */
$handler->display->display_options['fields']['task_contacts']['id'] = 'task_contacts';
$handler->display->display_options['fields']['task_contacts']['table'] = 'json';
$handler->display->display_options['fields']['task_contacts']['field'] = 'task_contacts';
$handler->display->display_options['fields']['task_contacts']['label'] = 'Task contacts (target)';
$handler->display->display_options['fields']['task_contacts']['key'] = 'target_contact_id';
/* Field: assignee_contact_id: Task contacts */
$handler->display->display_options['fields']['task_contacts_1']['id'] = 'task_contacts_1';
$handler->display->display_options['fields']['task_contacts_1']['table'] = 'json';
$handler->display->display_options['fields']['task_contacts_1']['field'] = 'task_contacts';
$handler->display->display_options['fields']['task_contacts_1']['label'] = 'Task contacts (assignee)';
$handler->display->display_options['fields']['task_contacts_1']['key'] = 'assignee_contact_id';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: status_id: value */
$handler->display->display_options['filters']['value']['id'] = 'value';
$handler->display->display_options['filters']['value']['table'] = 'json';
$handler->display->display_options['filters']['value']['field'] = 'value';
$handler->display->display_options['filters']['value']['operator'] = '!=';
$handler->display->display_options['filters']['value']['value'] = '2';
$handler->display->display_options['filters']['value']['key'] = 'status_id';
/* Filter criterion: status_id: value */
$handler->display->display_options['filters']['value_1']['id'] = 'value_1';
$handler->display->display_options['filters']['value_1']['table'] = 'json';
$handler->display->display_options['filters']['value_1']['field'] = 'value';
$handler->display->display_options['filters']['value_1']['operator'] = '!=';
$handler->display->display_options['filters']['value_1']['value'] = '3';
$handler->display->display_options['filters']['value_1']['key'] = 'status_id';
/* Filter criterion: status_id: value */
$handler->display->display_options['filters']['value_2']['id'] = 'value_2';
$handler->display->display_options['filters']['value_2']['table'] = 'json';
$handler->display->display_options['filters']['value_2']['field'] = 'value';
$handler->display->display_options['filters']['value_2']['operator'] = '!=';
$handler->display->display_options['filters']['value_2']['value'] = '6';
$handler->display->display_options['filters']['value_2']['key'] = 'status_id';
/* Filter criterion: status_id: value */
$handler->display->display_options['filters']['value_3']['id'] = 'value_3';
$handler->display->display_options['filters']['value_3']['table'] = 'json';
$handler->display->display_options['filters']['value_3']['field'] = 'value';
$handler->display->display_options['filters']['value_3']['operator'] = '!=';
$handler->display->display_options['filters']['value_3']['value'] = '8';
$handler->display->display_options['filters']['value_3']['key'] = 'status_id';

/* Display: Completed Tasks block */
$handler = $view->new_display('block', 'Completed Tasks block', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Tasks';
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/civi_tasks/';
$handler->display->display_options['query']['options']['row_apath'] = 'values';
$handler->display->display_options['query']['options']['show_errors'] = 1;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'activity_type_id' => 'activity_type_id',
  'case_id' => 'case_id',
  'subject' => 'subject',
  'activity_date_time' => 'activity_date_time',
  'expire_date' => 'expire_date',
  'details' => 'details',
  'source_contact_id' => 'source_contact_id',
  'target_contact_id' => 'target_contact_id',
  'assignee_contact_id' => 'assignee_contact_id',
  'file_count' => 'file_count',
  'status_id' => 'status_id',
  'task_targets' => 'task_targets',
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
  'activity_type_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'case_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'subject' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'activity_date_time' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'expire_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'details' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'source_contact_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'target_contact_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'assignee_contact_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'file_count' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'task_targets' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: id: value */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'json';
$handler->display->display_options['fields']['id']['field'] = 'value';
$handler->display->display_options['fields']['id']['label'] = 'Task ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['key'] = 'id';
/* Field: activity_type_id: value */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'json';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'value';
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Type';
$handler->display->display_options['fields']['activity_type_id']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['activity_type_id']['key'] = 'activity_type_id';
/* Field: case_id: value */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'json';
$handler->display->display_options['fields']['case_id']['field'] = 'value';
$handler->display->display_options['fields']['case_id']['label'] = 'Assignment';
$handler->display->display_options['fields']['case_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['case_id']['key'] = 'case_id';
/* Field: subject: value */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'json';
$handler->display->display_options['fields']['subject']['field'] = 'value';
$handler->display->display_options['fields']['subject']['label'] = 'Subject';
$handler->display->display_options['fields']['subject']['exclude'] = TRUE;
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['subject']['key'] = 'subject';
/* Field: activity_date_time: value */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'json';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'value';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due Date';
$handler->display->display_options['fields']['activity_date_time']['exclude'] = TRUE;
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['activity_date_time']['key'] = 'activity_date_time';
/* Field: expire_date: value */
$handler->display->display_options['fields']['expire_date']['id'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['table'] = 'json';
$handler->display->display_options['fields']['expire_date']['field'] = 'value';
$handler->display->display_options['fields']['expire_date']['label'] = 'Expire Date';
$handler->display->display_options['fields']['expire_date']['exclude'] = TRUE;
$handler->display->display_options['fields']['expire_date']['element_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['expire_date']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['expire_date']['key'] = 'expire_date';
/* Field: status_id: value */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'json';
$handler->display->display_options['fields']['status_id']['field'] = 'value';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
$handler->display->display_options['fields']['status_id']['element_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['status_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['status_id']['key'] = 'status_id';
/* Field: details: value */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'json';
$handler->display->display_options['fields']['details']['field'] = 'value';
$handler->display->display_options['fields']['details']['label'] = 'Details';
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['details']['key'] = 'details';
/* Field: target_contact_id: Task contacts */
$handler->display->display_options['fields']['task_contacts']['id'] = 'task_contacts';
$handler->display->display_options['fields']['task_contacts']['table'] = 'json';
$handler->display->display_options['fields']['task_contacts']['field'] = 'task_contacts';
$handler->display->display_options['fields']['task_contacts']['label'] = 'Task contacts (target)';
$handler->display->display_options['fields']['task_contacts']['key'] = 'target_contact_id';
/* Field: assignee_contact_id: Task contacts */
$handler->display->display_options['fields']['task_contacts_1']['id'] = 'task_contacts_1';
$handler->display->display_options['fields']['task_contacts_1']['table'] = 'json';
$handler->display->display_options['fields']['task_contacts_1']['field'] = 'task_contacts';
$handler->display->display_options['fields']['task_contacts_1']['label'] = 'Task contacts (assignee)';
$handler->display->display_options['fields']['task_contacts_1']['key'] = 'assignee_contact_id';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'OR',
);
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: status_id: value */
$handler->display->display_options['filters']['value']['id'] = 'value';
$handler->display->display_options['filters']['value']['table'] = 'json';
$handler->display->display_options['filters']['value']['field'] = 'value';
$handler->display->display_options['filters']['value']['value'] = '2';
$handler->display->display_options['filters']['value']['group'] = 1;
$handler->display->display_options['filters']['value']['key'] = 'status_id';
$translatables['Tasks'] = array(
  t('Master'),
  t('Tasks'),
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
  t('Task ID'),
  t('Activity Type ID'),
  t('Case ID'),
  t('Subject'),
  t('Activity Date'),
  t('Expire Date'),
  t('Details'),
  t('File Count'),
  t('Status ID'),
  t('Task contacts (target)'),
  t('Task contacts (assignee)'),
  t('All'),
  t('Tasks Dashboard block'),
  t('<div class="tasks-list-actions"><div id="nav-tasks-types" class="btn-group btn-group-sm"><a href class="btn btn-gray" data-task-type="my">My Tasks</a><a href class="btn btn-gray" data-task-type="delegated">Delegated Tasks</a><a href class="btn btn-gray active" data-task-type="all">All</a></div><div id="tasks-list-header-additional"><a href="/civi_tasks/nojs/view_completed" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">Show completed tasks</a><input type="text" name="task-filter-name" value="" placeholder="Enter name" /></div></div>'),
  t('Type'),
  t('Assignment'),
  t('Due Date'),
  t('Status'),
  t('Completed Tasks block'),
);
