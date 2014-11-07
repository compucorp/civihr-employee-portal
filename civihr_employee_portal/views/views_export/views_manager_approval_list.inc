<?php

/**
 * Exported absence_approval_list view
 */

$view = new view();
$view->name = 'approvals';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'absence_approval_list';
$view->human_name = 'Approvals';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Manager absence approval';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access manager approval screen';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['row_class'] = 'approvals-table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'absence_title' => 'absence_title',
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
  'absence_title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'Nothing to approve yet!';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Field: Absence approval entity: Absence approval entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'ID';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Absence approval entity: Absence_title */
$handler->display->display_options['fields']['absence_title']['id'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['table'] = 'absence_approval_list';
$handler->display->display_options['fields']['absence_title']['field'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['label'] = 'Type';
$handler->display->display_options['fields']['absence_title']['element_class'] = '[absence_title]';
/* Sort criterion: Absence approval entity: Absence_start_date_timestamp */
$handler->display->display_options['sorts']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['sorts']['absence_start_date_timestamp']['table'] = 'absence_approval_list';
$handler->display->display_options['sorts']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
/* Contextual filter: Absence approval entity: Drupal_uid */
$handler->display->display_options['arguments']['drupal_uid']['id'] = 'drupal_uid';
$handler->display->display_options['arguments']['drupal_uid']['table'] = 'absence_approval_list';
$handler->display->display_options['arguments']['drupal_uid']['field'] = 'drupal_uid';
$handler->display->display_options['arguments']['drupal_uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['drupal_uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['drupal_uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['drupal_uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['drupal_uid']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'approvals';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$translatables['approvals'] = array(
  t('Master'),
  t('Manager absence approval'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Nothing to approve yet!'),
  t('ID'),
  t('.'),
  t('Type'),
  t('All'),
  t('Page'),
  t('Block'),
);
