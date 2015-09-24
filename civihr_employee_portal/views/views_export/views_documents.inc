<?php

global $base_url;

$view = new view();
$view->name = 'Documents';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'json';
$view->human_name = 'Documents';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Documents and Downloads';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
    17087012 => '17087012',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/civi_documents/';
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
$handler->display->display_options['fields']['id']['label'] = 'Document ID';
$handler->display->display_options['fields']['id']['key'] = 'id';
/* Field: activity_type_id: value */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'json';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'value';
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Activity Type ID';
$handler->display->display_options['fields']['activity_type_id']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['activity_type_id']['key'] = 'activity_type_id';
/* Field: case_id: value */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'json';
$handler->display->display_options['fields']['case_id']['field'] = 'value';
$handler->display->display_options['fields']['case_id']['label'] = 'Case ID';
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['case_id']['key'] = 'case_id';
/* Field: subject: value */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'json';
$handler->display->display_options['fields']['subject']['field'] = 'value';
$handler->display->display_options['fields']['subject']['label'] = 'Subject';
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['subject']['key'] = 'subject';
/* Field: activity_date_time: value */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'json';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'value';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Activity Date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['activity_date_time']['key'] = 'activity_date_time';
/* Field: expire_date: value */
$handler->display->display_options['fields']['expire_date']['id'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['table'] = 'json';
$handler->display->display_options['fields']['expire_date']['field'] = 'value';
$handler->display->display_options['fields']['expire_date']['label'] = 'Expire Date';
$handler->display->display_options['fields']['expire_date']['element_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['expire_date']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['expire_date']['key'] = 'expire_date';
/* Field: details: value */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'json';
$handler->display->display_options['fields']['details']['field'] = 'value';
$handler->display->display_options['fields']['details']['label'] = 'Details';
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['details']['key'] = 'details';
/* Field: file_count: value */
$handler->display->display_options['fields']['file_count']['id'] = 'file_count';
$handler->display->display_options['fields']['file_count']['table'] = 'json';
$handler->display->display_options['fields']['file_count']['field'] = 'value';
$handler->display->display_options['fields']['file_count']['label'] = 'File Count';
$handler->display->display_options['fields']['file_count']['element_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['file_count']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['file_count']['key'] = 'file_count';
/* Field: status_id: value */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'json';
$handler->display->display_options['fields']['status_id']['field'] = 'value';
$handler->display->display_options['fields']['status_id']['label'] = 'Status ID';
$handler->display->display_options['fields']['status_id']['element_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['status_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['status_id']['key'] = 'status_id';
/* Field: target_contact_id: Document contacts */
$handler->display->display_options['fields']['document_contacts']['id'] = 'document_contacts';
$handler->display->display_options['fields']['document_contacts']['table'] = 'json';
$handler->display->display_options['fields']['document_contacts']['field'] = 'document_contacts';
$handler->display->display_options['fields']['document_contacts']['label'] = 'Document contacts (target)';
$handler->display->display_options['fields']['document_contacts']['key'] = 'target_contact_id';
/* Field: assignee_contact_id: Document contacts */
$handler->display->display_options['fields']['document_contacts_1']['id'] = 'document_contacts_1';
$handler->display->display_options['fields']['document_contacts_1']['table'] = 'json';
$handler->display->display_options['fields']['document_contacts_1']['field'] = 'document_contacts';
$handler->display->display_options['fields']['document_contacts_1']['label'] = 'Document contacts (assignee)';
$handler->display->display_options['fields']['document_contacts_1']['key'] = 'assignee_contact_id';
/* Contextual filter: Json: Document contacts */
$handler->display->display_options['arguments']['document_targets']['id'] = 'document_targets';
$handler->display->display_options['arguments']['document_targets']['table'] = 'json';
$handler->display->display_options['arguments']['document_targets']['field'] = 'document_contacts';
$handler->display->display_options['arguments']['document_targets']['default_action'] = 'default';
$handler->display->display_options['arguments']['document_targets']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['document_targets']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['document_targets']['name'] = 'document_targets';

/* Display: Documents Dashboard block */
$handler = $view->new_display('block', 'Documents Dashboard block', 'block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Documents';
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/civi_documents/';
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
    'document_targets' => 'document_targets',
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
    'document_targets' => array(
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
$handler->display->display_options['fields']['id']['label'] = 'Document ID';
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
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_class'] = 'document-wrapper';
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
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'document-wrapper';
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
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['subject']['key'] = 'subject';
/* Field: activity_date_time: value */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'json';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'value';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due Date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['activity_date_time']['key'] = 'activity_date_time';
/* Field: expire_date: value */
$handler->display->display_options['fields']['expire_date']['id'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['table'] = 'json';
$handler->display->display_options['fields']['expire_date']['field'] = 'value';
$handler->display->display_options['fields']['expire_date']['label'] = 'Expire Date';
$handler->display->display_options['fields']['expire_date']['element_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['expire_date']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['expire_date']['key'] = 'expire_date';
/* Field: details: value */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'json';
$handler->display->display_options['fields']['details']['field'] = 'value';
$handler->display->display_options['fields']['details']['label'] = 'Details';
$handler->display->display_options['fields']['details']['exclude'] = TRUE;
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['details']['key'] = 'details';
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
$handler->display->display_options['fields']['file_count']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['file_count']['key'] = 'file_count';
/* Field: status_id: value */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'json';
$handler->display->display_options['fields']['status_id']['field'] = 'value';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
$handler->display->display_options['fields']['status_id']['element_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['status_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['status_id']['key'] = 'status_id';
/* Field: target_contact_id: Document contacts */
$handler->display->display_options['fields']['document_contacts']['id'] = 'document_contacts';
$handler->display->display_options['fields']['document_contacts']['table'] = 'json';
$handler->display->display_options['fields']['document_contacts']['field'] = 'document_contacts';
$handler->display->display_options['fields']['document_contacts']['label'] = 'Document contacts (target)';
$handler->display->display_options['fields']['document_contacts']['exclude'] = TRUE;
$handler->display->display_options['fields']['document_contacts']['key'] = 'target_contact_id';
/* Field: assignee_contact_id: Document contacts */
$handler->display->display_options['fields']['document_contacts_1']['id'] = 'document_contacts_1';
$handler->display->display_options['fields']['document_contacts_1']['table'] = 'json';
$handler->display->display_options['fields']['document_contacts_1']['field'] = 'document_contacts';
$handler->display->display_options['fields']['document_contacts_1']['label'] = 'Document contacts (assignee)';
$handler->display->display_options['fields']['document_contacts_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['document_contacts_1']['key'] = 'assignee_contact_id';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Json: Document contacts */
$handler->display->display_options['arguments']['document_targets']['id'] = 'document_targets';
$handler->display->display_options['arguments']['document_targets']['table'] = 'json';
$handler->display->display_options['arguments']['document_targets']['field'] = 'document_contacts';
$handler->display->display_options['arguments']['document_targets']['default_action'] = 'default';
$handler->display->display_options['arguments']['document_targets']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['document_targets']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['document_targets']['name'] = 'target_contact_id';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;

/* Display: Documents Dashboard Manager block */
$handler = $view->new_display('block', 'Documents Dashboard Manager block', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'view--w-table';
$handler->display->display_options['title'] = 'Documents Manager';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
    57573969 => '57573969',
);
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/civi_documents/';
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
$handler->display->display_options['fields']['id']['label'] = 'Document ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['key'] = 'id';
/* Field: target_contact_id: Document contacts */
$handler->display->display_options['fields']['document_contacts']['id'] = 'document_contacts';
$handler->display->display_options['fields']['document_contacts']['table'] = 'json';
$handler->display->display_options['fields']['document_contacts']['field'] = 'document_contacts';
$handler->display->display_options['fields']['document_contacts']['label'] = 'Target Contact';
$handler->display->display_options['fields']['document_contacts']['element_type'] = 'div';
$handler->display->display_options['fields']['document_contacts']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['document_contacts']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['document_contacts']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['document_contacts']['key'] = 'target_contact_id';
/* Field: activity_type_id: value */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'json';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'value';
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Activity Type ID';
$handler->display->display_options['fields']['activity_type_id']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['activity_type_id']['key'] = 'activity_type_id';
/* Field: case_id: value */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'json';
$handler->display->display_options['fields']['case_id']['field'] = 'value';
$handler->display->display_options['fields']['case_id']['label'] = 'Assignment';
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'document-wrapper';
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
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['subject']['key'] = 'subject';
/* Field: activity_date_time: value */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'json';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'value';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due Date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['activity_date_time']['key'] = 'activity_date_time';
/* Field: expire_date: value */
$handler->display->display_options['fields']['expire_date']['id'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['table'] = 'json';
$handler->display->display_options['fields']['expire_date']['field'] = 'value';
$handler->display->display_options['fields']['expire_date']['label'] = 'Expire Date';
$handler->display->display_options['fields']['expire_date']['element_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['expire_date']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['expire_date']['key'] = 'expire_date';
/* Field: details: value */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'json';
$handler->display->display_options['fields']['details']['field'] = 'value';
$handler->display->display_options['fields']['details']['label'] = 'Details';
$handler->display->display_options['fields']['details']['exclude'] = TRUE;
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['details']['key'] = 'details';
/* Field: file_count: value */
$handler->display->display_options['fields']['file_count']['id'] = 'file_count';
$handler->display->display_options['fields']['file_count']['table'] = 'json';
$handler->display->display_options['fields']['file_count']['field'] = 'value';
$handler->display->display_options['fields']['file_count']['label'] = 'File Count';
$handler->display->display_options['fields']['file_count']['element_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_class'] = 'hidden';
$handler->display->display_options['fields']['file_count']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['file_count']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['file_count']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['file_count']['key'] = 'file_count';
/* Field: status_id: value */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'json';
$handler->display->display_options['fields']['status_id']['field'] = 'value';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
$handler->display->display_options['fields']['status_id']['element_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['status_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['status_id']['key'] = 'status_id';
/* Field: assignee_contact_id: Document contacts */
$handler->display->display_options['fields']['document_contacts_1']['id'] = 'document_contacts_1';
$handler->display->display_options['fields']['document_contacts_1']['table'] = 'json';
$handler->display->display_options['fields']['document_contacts_1']['field'] = 'document_contacts';
$handler->display->display_options['fields']['document_contacts_1']['label'] = 'Document contacts (assignee)';
$handler->display->display_options['fields']['document_contacts_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['document_contacts_1']['key'] = 'assignee_contact_id';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Json: Document contacts */
$handler->display->display_options['arguments']['document_targets']['id'] = 'document_targets';
$handler->display->display_options['arguments']['document_targets']['table'] = 'json';
$handler->display->display_options['arguments']['document_targets']['field'] = 'document_contacts';
$handler->display->display_options['arguments']['document_targets']['default_action'] = 'default';
$handler->display->display_options['arguments']['document_targets']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['document_targets']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['document_targets']['name'] = 'assignee_contact_id';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
$translatables['Documents'] = array(
    t('Master'),
    t('Documents and Downloads'),
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
    t('Document ID'),
    t('Activity Type ID'),
    t('Case ID'),
    t('Subject'),
    t('Activity Date'),
    t('Expire Date'),
    t('Details'),
    t('File Count'),
    t('Status ID'),
    t('Document contacts (target)'),
    t('Document contacts (assignee)'),
    t('All'),
    t('Documents Dashboard block'),
    t('Documents'),
    t('Type'),
    t('Assignment'),
    t('Due Date'),
    t('Status'),
    t('Documents Dashboard Manager block'),
    t('Documents Manager'),
    t('Target Contact'),
);
