<?php

/**
 * Exported absence_entitlement view
 */

$view = new view();
$view->name = 'absence_entitlement';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'json';
$view->human_name = 'Absence entitlement';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Absence entitlement';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['json_file'] = 'http://178.79.132.53:8001/absence_entitlement_json/';
$handler->display->display_options['query']['options']['row_apath'] = 'data';
$handler->display->display_options['query']['options']['show_errors'] = 1;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'value' => 'value',
  'value_1' => 'value_1',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'value' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'value_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: contact_id: value */
$handler->display->display_options['fields']['value']['id'] = 'value';
$handler->display->display_options['fields']['value']['table'] = 'json';
$handler->display->display_options['fields']['value']['field'] = 'value';
$handler->display->display_options['fields']['value']['label'] = 'Contact ID';
$handler->display->display_options['fields']['value']['exclude'] = TRUE;
$handler->display->display_options['fields']['value']['key'] = 'contact_id';
/* Field: period_id: value */
$handler->display->display_options['fields']['value_1']['id'] = 'value_1';
$handler->display->display_options['fields']['value_1']['table'] = 'json';
$handler->display->display_options['fields']['value_1']['field'] = 'value';
$handler->display->display_options['fields']['value_1']['label'] = 'Period ID';
$handler->display->display_options['fields']['value_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['value_1']['key'] = 'period_id';
/* Field: Json: Html field for period date */
$handler->display->display_options['fields']['period_html']['id'] = 'period_html';
$handler->display->display_options['fields']['period_html']['table'] = 'json';
$handler->display->display_options['fields']['period_html']['field'] = 'period_html';
$handler->display->display_options['fields']['period_html']['label'] = 'Description';
$handler->display->display_options['fields']['period_html']['absence_period_settings'] = '2';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement_1']['id'] = 'absence_entitlement_1';
$handler->display->display_options['fields']['absence_entitlement_1']['table'] = 'json';
$handler->display->display_options['fields']['absence_entitlement_1']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_1']['label'] = 'Vacation';
$handler->display->display_options['fields']['absence_entitlement_1']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement_1']['duration_type'] = '2';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement_4']['id'] = 'absence_entitlement_4';
$handler->display->display_options['fields']['absence_entitlement_4']['table'] = 'json';
$handler->display->display_options['fields']['absence_entitlement_4']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_4']['label'] = 'MATERNITY';
$handler->display->display_options['fields']['absence_entitlement_4']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement_4']['duration_type'] = '3';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement_2']['id'] = 'absence_entitlement_2';
$handler->display->display_options['fields']['absence_entitlement_2']['table'] = 'json';
$handler->display->display_options['fields']['absence_entitlement_2']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_2']['label'] = 'Paternity';
$handler->display->display_options['fields']['absence_entitlement_2']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement_2']['duration_type'] = '4';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement']['id'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement']['table'] = 'json';
$handler->display->display_options['fields']['absence_entitlement']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement']['label'] = 'TOIL';
$handler->display->display_options['fields']['absence_entitlement']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement']['duration_type'] = '5';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement_5']['id'] = 'absence_entitlement_5';
$handler->display->display_options['fields']['absence_entitlement_5']['table'] = 'json';
$handler->display->display_options['fields']['absence_entitlement_5']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_5']['label'] = 'OTHER';
$handler->display->display_options['fields']['absence_entitlement_5']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement_5']['duration_type'] = '6';
/* Sort criterion: period_id: value */
$handler->display->display_options['sorts']['value']['id'] = 'value';
$handler->display->display_options['sorts']['value']['table'] = 'json';
$handler->display->display_options['sorts']['value']['field'] = 'value';
$handler->display->display_options['sorts']['value']['order'] = 'DESC';
$handler->display->display_options['sorts']['value']['key'] = 'period_id';
/* Contextual filter: Json: Absence entitlement value */
$handler->display->display_options['arguments']['absence_entitlement_1']['id'] = 'absence_entitlement_1';
$handler->display->display_options['arguments']['absence_entitlement_1']['table'] = 'json';
$handler->display->display_options['arguments']['absence_entitlement_1']['field'] = 'absence_entitlement';
$handler->display->display_options['arguments']['absence_entitlement_1']['default_argument_type'] = 'raw';
$handler->display->display_options['arguments']['absence_entitlement_1']['default_argument_options']['index'] = '0';
$handler->display->display_options['arguments']['absence_entitlement_1']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['absence_entitlement_1']['name'] = 'period_id';
$handler->display->display_options['arguments']['absence_entitlement_1']['use_from_request'] = 'yes';
/* Contextual filter: Json: Absence entitlement value */
$handler->display->display_options['arguments']['absence_entitlement']['id'] = 'absence_entitlement';
$handler->display->display_options['arguments']['absence_entitlement']['table'] = 'json';
$handler->display->display_options['arguments']['absence_entitlement']['field'] = 'absence_entitlement';
$handler->display->display_options['arguments']['absence_entitlement']['default_action'] = 'default';
$handler->display->display_options['arguments']['absence_entitlement']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['absence_entitlement']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['absence_entitlement']['name'] = 'uf_id';
$handler->display->display_options['arguments']['absence_entitlement']['use_from_request'] = 'no';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'absence-entitlement';
$translatables['absence_entitlement'] = array(
  t('Master'),
  t('Absence entitlement'),
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
  t('Period ID'),
  t('Description'),
  t('Vacation'),
  t('MATERNITY'),
  t('Paternity'),
  t('TOIL'),
  t('OTHER'),
  t('All'),
  t('Page'),
);