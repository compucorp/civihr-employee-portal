<?php

/**
 * Exported calendar_absence_list view
 */

$view = new view();
$view->name = 'calendar_absence_list';
$view->description = '';
$view->tag = 'Calendar';
$view->base_table = 'absence_list';
$view->human_name = 'Calendar absence list';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['link_display'] = 'page_1';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'month';
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['name_size'] = '3';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['row_plugin'] = 'calendar_entity';
/* Field: Absence entity: Absence entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'absence_list';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Absence entity: Absence_title */
$handler->display->display_options['fields']['absence_title']['id'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_title']['field'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['label'] = '';
$handler->display->display_options['fields']['absence_title']['element_label_colon'] = FALSE;
/* Field: Absence entity: Absence_start_date_timestamp */
$handler->display->display_options['fields']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['label'] = '';
$handler->display->display_options['fields']['absence_start_date_timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_start_date_timestamp']['custom_date_format'] = 'd M, Y';
/* Field: Absence entity: Absence_end_date_timestamp */
$handler->display->display_options['fields']['absence_end_date_timestamp']['id'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_end_date_timestamp']['field'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['label'] = '';
$handler->display->display_options['fields']['absence_end_date_timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['absence_end_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_end_date_timestamp']['custom_date_format'] = 'd M, Y';
/* Sort criterion: Absence entity: Absence_start_date_timestamp */
$handler->display->display_options['sorts']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['sorts']['absence_start_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['sorts']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
$handler->display->display_options['sorts']['absence_start_date_timestamp']['granularity'] = 'day';

/* Display: Month */
$handler = $view->new_display('page', 'Month', 'page_1');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'month';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['name_size'] = '3';
$handler->display->display_options['style_options']['mini'] = '0';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['style_options']['multiday_hidden'] = array(
  'activity_type_id' => 'activity_type_id',
  'absence_title' => 'absence_title',
  'absence_start_date_timestamp' => 'absence_start_date_timestamp',
  'absence_end_date_timestamp' => 'absence_end_date_timestamp',
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['row_options']['inline'] = array(
  'tooltip' => 'tooltip',
);
$handler->display->display_options['row_options']['colors']['legend'] = 'absence_type';
$handler->display->display_options['row_options']['colors']['calendar_colors_absence_type'] = array(
  52 => '#E48282',
  53 => '#4D6C81',
  54 => '#EBA782',
  55 => '#91C68E',
  57 => '#1606c3',
  56 => '#977CA9',
  58 => '#C198AC',
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: Block area */
$handler->display->display_options['footer']['block']['id'] = 'block';
$handler->display->display_options['footer']['block']['table'] = 'views';
$handler->display->display_options['footer']['block']['field'] = 'block';
$handler->display->display_options['footer']['block']['block_to_insert'] = 'calendar:calendar_legend';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Absence entity: Absence entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'absence_list';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Absence entity: Activity_type_id */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'absence_list';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['activity_type_id']['separator'] = '';
/* Field: Absence entity: Absence_title */
$handler->display->display_options['fields']['absence_title']['id'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_title']['field'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['label'] = '';
$handler->display->display_options['fields']['absence_title']['element_label_colon'] = FALSE;
/* Field: Absence entity: Absence_start_date_timestamp */
$handler->display->display_options['fields']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['label'] = '';
$handler->display->display_options['fields']['absence_start_date_timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_start_date_timestamp']['custom_date_format'] = 'd M, Y';
/* Field: Absence entity: Absence_end_date_timestamp */
$handler->display->display_options['fields']['absence_end_date_timestamp']['id'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_end_date_timestamp']['field'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['label'] = '';
$handler->display->display_options['fields']['absence_end_date_timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['absence_end_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_end_date_timestamp']['custom_date_format'] = 'd M, Y';
/* Field: Global: Tooltip field */
$handler->display->display_options['fields']['tooltip']['id'] = 'tooltip';
$handler->display->display_options['fields']['tooltip']['table'] = 'views';
$handler->display->display_options['fields']['tooltip']['field'] = 'tooltip';
$handler->display->display_options['fields']['tooltip']['alter']['text'] = '[absence_title]';
$handler->display->display_options['fields']['tooltip']['tooltip_text'] = 'From: [absence_start_date_timestamp]
To: [absence_end_date_timestamp]
Type ID: [activity_type_id] ';
$handler->display->display_options['fields']['tooltip']['tooltip_hide_if_equal'] = 0;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Date: Date (absence_list) */
$handler->display->display_options['arguments']['date_argument_1']['id'] = 'date_argument_1';
$handler->display->display_options['arguments']['date_argument_1']['table'] = 'absence_list';
$handler->display->display_options['arguments']['date_argument_1']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument_1']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument_1']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument_1']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument_1']['add_delta'] = 'yes';
$handler->display->display_options['arguments']['date_argument_1']['use_fromto'] = 'no';
$handler->display->display_options['arguments']['date_argument_1']['date_fields'] = array(
  'absence_list.absence_start_date_timestamp' => 'absence_list.absence_start_date_timestamp',
);
/* Contextual filter: Absence entity: Drupal_uid */
$handler->display->display_options['arguments']['drupal_uid']['id'] = 'drupal_uid';
$handler->display->display_options['arguments']['drupal_uid']['table'] = 'absence_list';
$handler->display->display_options['arguments']['drupal_uid']['field'] = 'drupal_uid';
$handler->display->display_options['arguments']['drupal_uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['drupal_uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['drupal_uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['drupal_uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['drupal_uid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Absence entity: Absence status */
$handler->display->display_options['filters']['absence_status']['id'] = 'absence_status';
$handler->display->display_options['filters']['absence_status']['table'] = 'absence_list';
$handler->display->display_options['filters']['absence_status']['field'] = 'absence_status';
$handler->display->display_options['filters']['absence_status']['operator'] = '!=';
$handler->display->display_options['filters']['absence_status']['value'] = '3';
$handler->display->display_options['path'] = 'calendar-absence-list';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Month';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Calendar';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Week */
$handler = $view->new_display('page', 'Week', 'page_2');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'week';
$handler->display->display_options['pager']['options']['link_format'] = 'clean';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['calendar_type'] = 'week';
$handler->display->display_options['style_options']['name_size'] = '3';
$handler->display->display_options['style_options']['mini'] = '0';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Date: Date (absence_list) */
$handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['table'] = 'absence_list';
$handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
$handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
$handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
  'absence_list.absence_start_date_timestamp' => 'absence_list.absence_start_date_timestamp',
);
$handler->display->display_options['path'] = 'calendar-absence-start-date-timestamp/week';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Week';
$handler->display->display_options['menu']['weight'] = '2';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Day */
$handler = $view->new_display('page', 'Day', 'page_3');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'day';
$handler->display->display_options['pager']['options']['link_format'] = 'clean';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['calendar_type'] = 'day';
$handler->display->display_options['style_options']['name_size'] = '3';
$handler->display->display_options['style_options']['mini'] = '0';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Date: Date (absence_list) */
$handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['table'] = 'absence_list';
$handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
$handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
  'absence_list.absence_start_date_timestamp' => 'absence_list.absence_start_date_timestamp',
);
$handler->display->display_options['path'] = 'calendar-absence-start-date-timestamp/day';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Day';
$handler->display->display_options['menu']['weight'] = '3';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Year */
$handler = $view->new_display('page', 'Year', 'page');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'year';
$handler->display->display_options['pager']['options']['link_format'] = 'clean';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['calendar_type'] = 'year';
$handler->display->display_options['style_options']['name_size'] = '1';
$handler->display->display_options['style_options']['mini'] = '0';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Absence entity: Absence_start_date_timestamp */
$handler->display->display_options['fields']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['label'] = '';
$handler->display->display_options['fields']['absence_start_date_timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['hide_alter_empty'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Date: Date (absence_list) */
$handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['table'] = 'absence_list';
$handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
$handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
$handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
  'absence_list.absence_start_date_timestamp' => 'absence_list.absence_start_date_timestamp',
);
$handler->display->display_options['path'] = 'calendar-absence-start-date-timestamp/year';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Year';
$handler->display->display_options['menu']['weight'] = '4';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->display->display_options['defaults']['use_ajax'] = FALSE;
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'date_views_pager';
$handler->display->display_options['pager']['options']['date_id'] = 'mini';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'calendar_style';
$handler->display->display_options['style_options']['name_size'] = '1';
$handler->display->display_options['style_options']['mini'] = '1';
$handler->display->display_options['style_options']['with_weekno'] = '0';
$handler->display->display_options['style_options']['multiday_theme'] = '1';
$handler->display->display_options['style_options']['theme_style'] = '1';
$handler->display->display_options['style_options']['max_items'] = '0';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'calendar_entity';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Date: Date (absence_list) */
$handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['table'] = 'absence_list';
$handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
$handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
$handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
$handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
$handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
  'absence_list.absence_start_date_timestamp' => 'absence_list.absence_start_date_timestamp',
);

/* Display: Upcoming */
$handler = $view->new_display('block', 'Upcoming', 'block_2');
$handler->display->display_options['display_description'] = 'Upcoming events block';
$handler->display->display_options['defaults']['use_more'] = FALSE;
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Date: Date (absence_list) */
$handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['table'] = 'absence_list';
$handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
$handler->display->display_options['filters']['date_filter']['operator'] = '>=';
$handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
$handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
$handler->display->display_options['filters']['date_filter']['date_fields'] = array(
  'absence_list.absence_start_date_timestamp' => 'absence_list.absence_start_date_timestamp',
);
$translatables['calendar_absence_list'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Absence entity ID'),
  t('.'),
  t('Month'),
  t('Activity_type_id'),
  t('Tooltip field'),
  t('[absence_title]'),
  t('From: [absence_start_date_timestamp]
To: [absence_end_date_timestamp]
Type ID: [activity_type_id] '),
  t('All'),
  t('Week'),
  t('Day'),
  t('Year'),
  t('Block'),
  t('Upcoming'),
  t('Upcoming events block'),
);
