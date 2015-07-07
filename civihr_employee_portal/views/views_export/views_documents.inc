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
  6 => '6',
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
/* Field: source_contact_id: value */
$handler->display->display_options['fields']['source_contact_id']['id'] = 'source_contact_id';
$handler->display->display_options['fields']['source_contact_id']['table'] = 'json';
$handler->display->display_options['fields']['source_contact_id']['field'] = 'value';
$handler->display->display_options['fields']['source_contact_id']['label'] = 'Source Contact ID';
$handler->display->display_options['fields']['source_contact_id']['element_type'] = 'div';
$handler->display->display_options['fields']['source_contact_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['source_contact_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['source_contact_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['source_contact_id']['key'] = 'source_contact_id';
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
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/civi_documents/nojs/edit/[id]" class="btn btn-custom ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">Upload</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

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
  'file_count' => 'file_count',
  'status_id' => 'status_id',
  'nothing' => 'nothing',
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
  'nothing' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;

/* Display: Documents Dashboard Manager block */
$handler = $view->new_display('block', 'Documents Dashboard Manager block', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Documents Manager';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  5 => '5',
);
$handler->display->display_options['defaults']['query'] = FALSE;
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = $base_url . '/civi_documents_manager/';
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
  'file_count' => 'file_count',
  'status_id' => 'status_id',
  'nothing' => 'nothing',
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
  'nothing' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
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
  t('Source Contact ID'),
  t('File Count'),
  t('Status ID'),
  t('<a href="/civi_documents/nojs/edit/[id]" class="btn btn-custom ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed">Upload</a>'),
  t('Documents Dashboard block'),
  t('Documents'),
  t('Documents Dashboard Manager block'),
  t('Documents Manager'),
);
