<?php

$view = new view();
$view->name = 'absence_entitlement';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'absence_entitlement';
$view->human_name = 'Absence Entitlement';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Absence Entitlement';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view my leave block';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '0';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'contact_id' => 'contact_id',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'contact_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: Absence Entitlement entity: Absence entitlement entity ID */
$handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['table'] = 'absence_entitlement';
$handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['label'] = 'Contact ID';
$handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['contact_id']['separator'] = '';
/* Field: Absence Entitlement entity: Period_id */
$handler->display->display_options['fields']['period_id']['id'] = 'period_id';
$handler->display->display_options['fields']['period_id']['table'] = 'absence_entitlement';
$handler->display->display_options['fields']['period_id']['field'] = 'period_id';
$handler->display->display_options['fields']['period_id']['label'] = 'Period ID';
$handler->display->display_options['fields']['period_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['period_id']['separator'] = '';
/* Field: Absence Entitlement entity: Html field for period date */
$handler->display->display_options['fields']['period_html']['id'] = 'period_html';
$handler->display->display_options['fields']['period_html']['table'] = 'absence_entitlement';
$handler->display->display_options['fields']['period_html']['field'] = 'period_html';
$handler->display->display_options['fields']['period_html']['label'] = 'Description';
$handler->display->display_options['fields']['period_html']['absence_period_settings'] = 'entitlement_label';
/* Field: Absence Entitlement entity: Html field for period date */
$handler->display->display_options['fields']['period_html_1']['id'] = 'period_html_1';
$handler->display->display_options['fields']['period_html_1']['table'] = 'absence_entitlement';
$handler->display->display_options['fields']['period_html_1']['field'] = 'period_html';
$handler->display->display_options['fields']['period_html_1']['label'] = 'Description';
$handler->display->display_options['fields']['period_html_1']['absence_period_settings'] = 'entitlement_date';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Status';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement']['id'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement']['table'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement']['label'] = 'Vacation';
$handler->display->display_options['fields']['absence_entitlement']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement']['duration_type'] = '2';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement_1']['id'] = 'absence_entitlement_1';
$handler->display->display_options['fields']['absence_entitlement_1']['table'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_1']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_1']['label'] = 'Maternity';
$handler->display->display_options['fields']['absence_entitlement_1']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement_1']['duration_type'] = '3';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement_2']['id'] = 'absence_entitlement_2';
$handler->display->display_options['fields']['absence_entitlement_2']['table'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_2']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_2']['label'] = 'Paternity';
$handler->display->display_options['fields']['absence_entitlement_2']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement_2']['duration_type'] = '4';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement_3']['id'] = 'absence_entitlement_3';
$handler->display->display_options['fields']['absence_entitlement_3']['table'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_3']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_3']['label'] = 'TOIL';
$handler->display->display_options['fields']['absence_entitlement_3']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement_3']['duration_type'] = '5';
/* Field: entitlement_type: Absence entitlement value */
$handler->display->display_options['fields']['absence_entitlement_4']['id'] = 'absence_entitlement_4';
$handler->display->display_options['fields']['absence_entitlement_4']['table'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_4']['field'] = 'absence_entitlement';
$handler->display->display_options['fields']['absence_entitlement_4']['label'] = 'Other';
$handler->display->display_options['fields']['absence_entitlement_4']['key'] = 'entitlement_type';
$handler->display->display_options['fields']['absence_entitlement_4']['duration_type'] = '6';
/* Sort criterion: Absence Entitlement entity: Period_id */
$handler->display->display_options['sorts']['period_id']['id'] = 'period_id';
$handler->display->display_options['sorts']['period_id']['table'] = 'absence_entitlement';
$handler->display->display_options['sorts']['period_id']['field'] = 'period_id';
$handler->display->display_options['sorts']['period_id']['order'] = 'DESC';
/* Contextual filter: Absence Entitlement entity: Uf_id */
$handler->display->display_options['arguments']['uf_id']['id'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['table'] = 'absence_entitlement';
$handler->display->display_options['arguments']['uf_id']['field'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['uf_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uf_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uf_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uf_id']['summary_options']['items_per_page'] = '25';
/* Contextual filter: Absence Entitlement entity: Period_id */
$handler->display->display_options['arguments']['period_id']['id'] = 'period_id';
$handler->display->display_options['arguments']['period_id']['table'] = 'absence_entitlement';
$handler->display->display_options['arguments']['period_id']['field'] = 'period_id';
$handler->display->display_options['arguments']['period_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['period_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['period_id']['default_argument_options']['argument'] = '1';
$handler->display->display_options['arguments']['period_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['period_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['period_id']['summary_options']['items_per_page'] = '25';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'absence-entitlement';
$translatables['absence_entitlement'] = array(
  t('Master'),
  t('Absence Entitlement'),
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
  t('Period ID'),
  t('Description'),
  t('Status'),
  t('Vacation'),
  t('Maternity'),
  t('Paternity'),
  t('TOIL'),
  t('Other'),
  t('All'),
  t('Page'),
);
