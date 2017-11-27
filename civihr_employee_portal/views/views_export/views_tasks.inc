<?php

$view = new view();
$view->name = 'Tasks';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'tasks';
$view->human_name = 'Tasks';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Tasks';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view my tasks and documents blocks';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
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
);
/* Field: Task entity: Task entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'tasks';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Task ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Task entity: Task type */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'tasks';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'activity_type_id';
/* Field: Task entity: Case_id */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'tasks';
$handler->display->display_options['fields']['case_id']['field'] = 'case_id';
$handler->display->display_options['fields']['case_id']['label'] = 'Workflow';
$handler->display->display_options['fields']['case_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['case_id']['separator'] = '';
/* Field: Task entity: Subject */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'tasks';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
$handler->display->display_options['fields']['subject']['exclude'] = TRUE;
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'task-wrapper';
/* Field: Task entity: Task due date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'tasks';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'task-wrapper';
/* Field: Task entity: Task status */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'tasks';
$handler->display->display_options['fields']['status_id']['field'] = 'status_id';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
/* Field: Task entity: Details */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'tasks';
$handler->display->display_options['fields']['details']['field'] = 'details';
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'task-wrapper';
/* Field: Task entity: Target contact */
$handler->display->display_options['fields']['target_contact_id']['id'] = 'target_contact_id';
$handler->display->display_options['fields']['target_contact_id']['table'] = 'tasks';
$handler->display->display_options['fields']['target_contact_id']['field'] = 'target_contact_id';
/* Field: Task entity: Assignee contact */
$handler->display->display_options['fields']['assignee_contact_id']['id'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['table'] = 'tasks';
$handler->display->display_options['fields']['assignee_contact_id']['field'] = 'assignee_contact_id';
/* Field: Task entity: Source_contact_id */
$handler->display->display_options['fields']['source_contact_id']['id'] = 'source_contact_id';
$handler->display->display_options['fields']['source_contact_id']['table'] = 'tasks';
$handler->display->display_options['fields']['source_contact_id']['field'] = 'source_contact_id';
$handler->display->display_options['fields']['source_contact_id']['label'] = 'Source contact';
$handler->display->display_options['fields']['source_contact_id']['separator'] = '';
/* Field: Task entity: Target_contact_name */
$handler->display->display_options['fields']['target_contact_name']['id'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['table'] = 'tasks';
$handler->display->display_options['fields']['target_contact_name']['field'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['label'] = '';
$handler->display->display_options['fields']['target_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['target_contact_name']['element_wrapper_class'] = 'hidden';
/* Field: Task entity: Source_contact_name */
$handler->display->display_options['fields']['source_contact_name']['id'] = 'source_contact_name';
$handler->display->display_options['fields']['source_contact_name']['table'] = 'tasks';
$handler->display->display_options['fields']['source_contact_name']['field'] = 'source_contact_name';
$handler->display->display_options['fields']['source_contact_name']['label'] = '';
$handler->display->display_options['fields']['source_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['source_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['source_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['source_contact_name']['element_wrapper_class'] = 'hidden';
/* Field: Task entity: Assignee_contact_name */
$handler->display->display_options['fields']['assignee_contact_name']['id'] = 'assignee_contact_name';
$handler->display->display_options['fields']['assignee_contact_name']['table'] = 'tasks';
$handler->display->display_options['fields']['assignee_contact_name']['field'] = 'assignee_contact_name';
$handler->display->display_options['fields']['assignee_contact_name']['label'] = '';
$handler->display->display_options['fields']['assignee_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['assignee_contact_name']['element_wrapper_class'] = 'hidden';
/* Contextual filter: Task entity: Assignee contact */
$handler->display->display_options['arguments']['assignee_contact_id']['id'] = 'assignee_contact_id';
$handler->display->display_options['arguments']['assignee_contact_id']['table'] = 'tasks';
$handler->display->display_options['arguments']['assignee_contact_id']['field'] = 'assignee_contact_id';
$handler->display->display_options['arguments']['assignee_contact_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['assignee_contact_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['assignee_contact_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['assignee_contact_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['assignee_contact_id']['summary_options']['items_per_page'] = '25';

/* Display: My Tasks Dashboard block */
$handler = $view->new_display('block', 'My Tasks Dashboard block', 'block');
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<a href="/civi_tasks/nojs/view_completed" class="ctools-use-modal ctools-modal-civihr-custom-large-style ctools-use-modal-processed chr_action--transparent chr_action--icon--list chr_action--icon--responsive show-complete-tasks"><span>Show completed tasks</span></a>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Task entity: Task entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'tasks';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Task ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Task entity: Task type */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'tasks';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'activity_type_id';
/* Field: Task entity: Case_id */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'tasks';
$handler->display->display_options['fields']['case_id']['field'] = 'case_id';
$handler->display->display_options['fields']['case_id']['label'] = 'Workflow';
$handler->display->display_options['fields']['case_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['case_id']['separator'] = '';
/* Field: Task entity: Subject */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'tasks';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
$handler->display->display_options['fields']['subject']['exclude'] = TRUE;
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'task-wrapper';
/* Field: Task entity: Task due date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'tasks';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'task-wrapper';
/* Field: Task entity: Task status */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'tasks';
$handler->display->display_options['fields']['status_id']['field'] = 'status_id';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
/* Field: Task entity: Details */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'tasks';
$handler->display->display_options['fields']['details']['field'] = 'details';
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'task-wrapper';
/* Field: Task entity: Target contact */
$handler->display->display_options['fields']['target_contact_id']['id'] = 'target_contact_id';
$handler->display->display_options['fields']['target_contact_id']['table'] = 'tasks';
$handler->display->display_options['fields']['target_contact_id']['field'] = 'target_contact_id';
$handler->display->display_options['fields']['target_contact_id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_id']['element_wrapper_class'] = 'hidden';
/* Field: Task entity: Assignee contact */
$handler->display->display_options['fields']['assignee_contact_id']['id'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['table'] = 'tasks';
$handler->display->display_options['fields']['assignee_contact_id']['field'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_id']['element_wrapper_class'] = 'hidden';
/* Field: Task entity: Source_contact_id */
$handler->display->display_options['fields']['source_contact_id']['id'] = 'source_contact_id';
$handler->display->display_options['fields']['source_contact_id']['table'] = 'tasks';
$handler->display->display_options['fields']['source_contact_id']['field'] = 'source_contact_id';
$handler->display->display_options['fields']['source_contact_id']['label'] = 'Source contact';
$handler->display->display_options['fields']['source_contact_id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['source_contact_id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['source_contact_id']['element_wrapper_class'] = 'hidden';
$handler->display->display_options['fields']['source_contact_id']['separator'] = '';
/* Field: Task entity: Target_contact_name */
$handler->display->display_options['fields']['target_contact_name']['id'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['table'] = 'tasks';
$handler->display->display_options['fields']['target_contact_name']['field'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['label'] = '';
$handler->display->display_options['fields']['target_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['target_contact_name']['element_wrapper_class'] = 'hidden';
/* Field: Task entity: Source_contact_name */
$handler->display->display_options['fields']['source_contact_name']['id'] = 'source_contact_name';
$handler->display->display_options['fields']['source_contact_name']['table'] = 'tasks';
$handler->display->display_options['fields']['source_contact_name']['field'] = 'source_contact_name';
$handler->display->display_options['fields']['source_contact_name']['label'] = '';
$handler->display->display_options['fields']['source_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['source_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['source_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['source_contact_name']['element_wrapper_class'] = 'hidden';
/* Field: Task entity: Assignee_contact_name */
$handler->display->display_options['fields']['assignee_contact_name']['id'] = 'assignee_contact_name';
$handler->display->display_options['fields']['assignee_contact_name']['table'] = 'tasks';
$handler->display->display_options['fields']['assignee_contact_name']['field'] = 'assignee_contact_name';
$handler->display->display_options['fields']['assignee_contact_name']['label'] = '';
$handler->display->display_options['fields']['assignee_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['assignee_contact_name']['element_wrapper_class'] = 'hidden';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Task entity: Task status */
$handler->display->display_options['filters']['status_id']['id'] = 'status_id';
$handler->display->display_options['filters']['status_id']['table'] = 'tasks';
$handler->display->display_options['filters']['status_id']['field'] = 'status_id';
$handler->display->display_options['filters']['status_id']['operator'] = '!=';
$handler->display->display_options['filters']['status_id']['value'] = '2';

/* Display: Completed Tasks block */
$handler = $view->new_display('block', 'Completed Tasks block', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Completed Tasks';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Task entity: Task entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'tasks';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Task ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Task entity: Task type */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'tasks';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'activity_type_id';
/* Field: Task entity: Case_id */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'tasks';
$handler->display->display_options['fields']['case_id']['field'] = 'case_id';
$handler->display->display_options['fields']['case_id']['label'] = 'Workflow';
$handler->display->display_options['fields']['case_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'task-wrapper';
$handler->display->display_options['fields']['case_id']['separator'] = '';
/* Field: Task entity: Subject */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'tasks';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
$handler->display->display_options['fields']['subject']['exclude'] = TRUE;
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'task-wrapper';
/* Field: Task entity: Task due date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'tasks';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_class'] = 'hidden';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'hidden';
/* Field: Task entity: Task status */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'tasks';
$handler->display->display_options['fields']['status_id']['field'] = 'status_id';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
/* Field: Task entity: Details */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'tasks';
$handler->display->display_options['fields']['details']['field'] = 'details';
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'task-wrapper';
/* Field: Task entity: Target contact */
$handler->display->display_options['fields']['target_contact_id']['id'] = 'target_contact_id';
$handler->display->display_options['fields']['target_contact_id']['table'] = 'tasks';
$handler->display->display_options['fields']['target_contact_id']['field'] = 'target_contact_id';
$handler->display->display_options['fields']['target_contact_id']['exclude'] = TRUE;
/* Field: Task entity: Assignee contact */
$handler->display->display_options['fields']['assignee_contact_id']['id'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['table'] = 'tasks';
$handler->display->display_options['fields']['assignee_contact_id']['field'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['exclude'] = TRUE;
/* Field: Task entity: Source_contact_id */
$handler->display->display_options['fields']['source_contact_id']['id'] = 'source_contact_id';
$handler->display->display_options['fields']['source_contact_id']['table'] = 'tasks';
$handler->display->display_options['fields']['source_contact_id']['field'] = 'source_contact_id';
$handler->display->display_options['fields']['source_contact_id']['label'] = 'Source contact';
$handler->display->display_options['fields']['source_contact_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['source_contact_id']['separator'] = '';
/* Field: Task entity: Target_contact_name */
$handler->display->display_options['fields']['target_contact_name']['id'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['table'] = 'tasks';
$handler->display->display_options['fields']['target_contact_name']['field'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['label'] = '';
$handler->display->display_options['fields']['target_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['target_contact_name']['element_wrapper_class'] = 'hidden';
/* Field: Task entity: Source_contact_name */
$handler->display->display_options['fields']['source_contact_name']['id'] = 'source_contact_name';
$handler->display->display_options['fields']['source_contact_name']['table'] = 'tasks';
$handler->display->display_options['fields']['source_contact_name']['field'] = 'source_contact_name';
$handler->display->display_options['fields']['source_contact_name']['label'] = '';
$handler->display->display_options['fields']['source_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['source_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['source_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['source_contact_name']['element_wrapper_class'] = 'hidden';
/* Field: Task entity: Assignee_contact_name */
$handler->display->display_options['fields']['assignee_contact_name']['id'] = 'assignee_contact_name';
$handler->display->display_options['fields']['assignee_contact_name']['table'] = 'tasks';
$handler->display->display_options['fields']['assignee_contact_name']['field'] = 'assignee_contact_name';
$handler->display->display_options['fields']['assignee_contact_name']['label'] = '';
$handler->display->display_options['fields']['assignee_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['assignee_contact_name']['element_wrapper_class'] = 'hidden';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Task entity: Task status */
$handler->display->display_options['filters']['status_id']['id'] = 'status_id';
$handler->display->display_options['filters']['status_id']['table'] = 'tasks';
$handler->display->display_options['filters']['status_id']['field'] = 'status_id';
$handler->display->display_options['filters']['status_id']['value'] = '2';
$translatables['tasks'] = array(
  t('Master'),
  t('My Tasks'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Task ID'),
  t('.'),
  t('Task type'),
  t('Workflow'),
  t('Subject'),
  t('Due date'),
  t('Status'),
  t('Details'),
  t('Target contact'),
  t('Assignee contact'),
  t('Source contact'),
  t('All'),
  t('My Tasks Dashboard block'),
  t('<a href="/civi_tasks/nojs/view_completed" class="ctools-use-modal ctools-modal-civihr-custom-large-style ctools-use-modal-processed chr_action--transparent chr_action--icon--list chr_action--icon--responsive show-complete-tasks"><span>Show completed tasks</span></a>'),
  t('Completed Tasks block'),
  t('Completed Tasks'),
);
