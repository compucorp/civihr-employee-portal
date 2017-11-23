<?php

/**
 * Exported hr_documents view
 */

$view = new view();
$view->name = 'hr_documents';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'HR Documents and Downloads';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'HR Resources';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view hr resources';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'hr-documents-title-block';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_class'] = 'hr-documents-body-block';
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
);
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = 'Read more';
$handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
$handler->display->display_options['fields']['nothing']['alter']['alt'] = 'Read more';
$handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'btn btn-custom';
$handler->display->display_options['fields']['nothing']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'hr_documents' => 'hr_documents',
);

/* Display: HR Documents and Downloads dashboard block */
$handler = $view->new_display('block', 'HR Documents and Downloads dashboard block', 'block');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'jcarousel';
$handler->display->display_options['style_options']['wrap'] = '0';
$handler->display->display_options['style_options']['skin'] = '';
$handler->display->display_options['style_options']['visible'] = '';
$handler->display->display_options['style_options']['responsive'] = 1;
$handler->display->display_options['style_options']['auto'] = '0';
$handler->display->display_options['style_options']['autoPause'] = 1;
$handler->display->display_options['style_options']['easing'] = '';
$handler->display->display_options['style_options']['vertical'] = 0;
$handler->display->display_options['style_options']['ajax'] = 1;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<a href="hr-resources">View all documents</a>';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'hr-documents-title-block';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Short description */
$handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
$handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
$handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
$handler->display->display_options['fields']['field_short_description']['label'] = '';
$handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = 'Read more';
$handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['path'] = 'hr_resources/nojs/resource/[nid]';
$handler->display->display_options['fields']['nothing']['alter']['alt'] = 'Read more';
$handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'btn btn-custom ctools-use-modal ctools-modal-civihr-default-style';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

/* Display: HR Resources page */
$handler = $view->new_display('page', 'HR Resources page', 'hr_resources');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'view-full-hr-documents';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '2, 5, 10, 20, 40, 60';
$handler->display->display_options['pager']['options']['tags']['first'] = 'First';
$handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
$handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
$handler->display->display_options['pager']['options']['tags']['last'] = 'Last';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Result summary */
$handler->display->display_options['header']['result']['id'] = 'result';
$handler->display->display_options['header']['result']['table'] = 'views';
$handler->display->display_options['header']['result']['field'] = 'result';
$handler->display->display_options['header']['result']['content'] = '@total';
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Unfiltered text */
$handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
$handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Resource type */
$handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
$handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
$handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
$handler->display->display_options['fields']['field_resource_type']['label'] = '';
$handler->display->display_options['fields']['field_resource_type']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_resource_type']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_resource_type']['type'] = 'taxonomy_term_reference_plain';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '<strong><h4>[title]</h4></strong>
';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'hr-documents-title-block';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Download */
$handler->display->display_options['fields']['field_download']['id'] = 'field_download';
$handler->display->display_options['fields']['field_download']['table'] = 'field_data_field_download';
$handler->display->display_options['fields']['field_download']['field'] = 'field_download';
$handler->display->display_options['fields']['field_download']['label'] = '';
$handler->display->display_options['fields']['field_download']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_download']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_download']['click_sort_column'] = 'download_fields';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: Content: Short description */
$handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
$handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
$handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
$handler->display->display_options['fields']['field_short_description']['label'] = '';
$handler->display->display_options['fields']['field_short_description']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_short_description']['element_label_colon'] = FALSE;
/* Field: Global: Fieldset */
$handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
$handler->display->display_options['fields']['fieldset']['table'] = 'views';
$handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
$handler->display->display_options['fields']['fieldset']['label'] = 'See Resources';
$handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_attachment',
);
$handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'civihr_form__fieldset--transparent';
$handler->display->display_options['fields']['fieldset']['fieldset']['id'] = '[nid]';
$handler->display->display_options['fields']['fieldset']['fieldset']['collapsible'] = 1;
$handler->display->display_options['fields']['fieldset']['fieldset']['collapsed'] = 1;
/* Field: Content: Attachments */
$handler->display->display_options['fields']['field_attachment']['id'] = 'field_attachment';
$handler->display->display_options['fields']['field_attachment']['table'] = 'field_data_field_attachment';
$handler->display->display_options['fields']['field_attachment']['field'] = 'field_attachment';
$handler->display->display_options['fields']['field_attachment']['label'] = '';
$handler->display->display_options['fields']['field_attachment']['element_label_class'] = 'hr-doc-label';
$handler->display->display_options['fields']['field_attachment']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_attachment']['empty'] = 'No resource file attached!';
$handler->display->display_options['fields']['field_attachment']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_attachment']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_attachment']['multi_type'] = 'ul';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
    'hr_documents' => 'hr_documents',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Global: Combine fields filter */
$handler->display->display_options['filters']['combine']['id'] = 'combine';
$handler->display->display_options['filters']['combine']['table'] = 'views';
$handler->display->display_options['filters']['combine']['field'] = 'combine';
$handler->display->display_options['filters']['combine']['operator'] = 'word';
$handler->display->display_options['filters']['combine']['group'] = 1;
$handler->display->display_options['filters']['combine']['exposed'] = TRUE;
$handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['label'] = 'Keywords';
$handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
$handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
$handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
);
$handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_short_description' => 'field_short_description',
);
/* Filter criterion: Content: Resource type (field_resource_type) */
$handler->display->display_options['filters']['field_resource_type_tid']['id'] = 'field_resource_type_tid';
$handler->display->display_options['filters']['field_resource_type_tid']['table'] = 'field_data_field_resource_type';
$handler->display->display_options['filters']['field_resource_type_tid']['field'] = 'field_resource_type_tid';
$handler->display->display_options['filters']['field_resource_type_tid']['group'] = 1;
$handler->display->display_options['filters']['field_resource_type_tid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator_id'] = 'field_resource_type_tid_op';
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['label'] = 'Resource type';
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator'] = 'field_resource_type_tid_op';
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['identifier'] = 'field_resource_type_tid';
$handler->display->display_options['filters']['field_resource_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
);
$handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'hr_resource_type';
$handler->display->display_options['path'] = 'hr-resources';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'HR Resources';
$handler->display->display_options['menu']['weight'] = '8';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: HR Resources page modal details */
$handler = $view->new_display('block', 'HR Resources page modal details', 'hr_resources_modal');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'hr-documents-title-block';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Download */
$handler->display->display_options['fields']['field_download']['id'] = 'field_download';
$handler->display->display_options['fields']['field_download']['table'] = 'field_data_field_download';
$handler->display->display_options['fields']['field_download']['field'] = 'field_download';
$handler->display->display_options['fields']['field_download']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_download']['click_sort_column'] = 'download_fields';
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = 'Details:';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['element_wrapper_class'] = 'hr-documents-body-block';
$handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
);
/* Field: Content: Attachments */
$handler->display->display_options['fields']['field_attachment']['id'] = 'field_attachment';
$handler->display->display_options['fields']['field_attachment']['table'] = 'field_data_field_attachment';
$handler->display->display_options['fields']['field_attachment']['field'] = 'field_attachment';
$handler->display->display_options['fields']['field_attachment']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_attachment']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_attachment']['type'] = 'file_table';
$handler->display->display_options['fields']['field_attachment']['delta_offset'] = '0';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="btn">Download</div>';
$handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
$handler->display->display_options['fields']['nothing']['alter']['alt'] = 'Read more';
$handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'btn btn-custom';
$handler->display->display_options['fields']['nothing']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$translatables['hr_documents'] = array(
    t('Master'),
    t('HR Resources'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Read more'),
    t('HR Documents and Downloads dashboard block'),
    t('<a href="hr-resources">View all documents</a>'),
    t('HR Resources page'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('First'),
    t('Previous'),
    t('Next'),
    t('Last'),
    t('@total'),
    t('<strong><h4>[title]</h4></strong>'),
    t('See Resources'),
    t('Attachments'),
    t('No resource file attached!'),
    t('Keywords'),
    t('Resource type'),
    t('HR Resources page modal details'),
    t('Download'),
    t('Details:'),
    t('<div class="btn">Download</div>'),
    t('Post date'),
    t('All'),
);
