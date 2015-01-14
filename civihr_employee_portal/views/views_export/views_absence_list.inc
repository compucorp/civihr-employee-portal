<?php

/**
 * Exported absence_list view
 */

$view = new view();
$view->name = 'absence_list';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'absence_list';
$view->human_name = 'Absence list';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Absence list';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  4 => '4',
  6 => '6',
  5 => '5',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'absence_title' => 'absence_title',
  'drupal_uid' => 'drupal_uid',
  'absence_start_date' => 'absence_start_date',
);
$handler->display->display_options['style_options']['default'] = 'absence_start_date';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'absence_title' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'drupal_uid' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'absence_start_date' => array(
    'sortable' => 1,
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
$handler->display->display_options['empty']['area']['content'] = 'No results for the selected period!';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
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
$handler->display->display_options['fields']['absence_title']['label'] = 'Absence title';
$handler->display->display_options['fields']['absence_title']['exclude'] = TRUE;
/* Field: Absence entity: Drupal_uid */
$handler->display->display_options['fields']['drupal_uid']['id'] = 'drupal_uid';
$handler->display->display_options['fields']['drupal_uid']['table'] = 'absence_list';
$handler->display->display_options['fields']['drupal_uid']['field'] = 'drupal_uid';
$handler->display->display_options['fields']['drupal_uid']['label'] = 'Drupal UID';
$handler->display->display_options['fields']['drupal_uid']['exclude'] = TRUE;
$handler->display->display_options['fields']['drupal_uid']['separator'] = '';
/* Field: Absence entity: Absence_start_date_timestamp */
$handler->display->display_options['fields']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['label'] = 'Absence start date';
$handler->display->display_options['fields']['absence_start_date_timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_start_date_timestamp']['custom_date_format'] = 'd M, Y';
$handler->display->display_options['fields']['absence_start_date_timestamp']['timezone'] = 'Europe/London';
/* Field: Absence entity: Absence_end_date_timestamp */
$handler->display->display_options['fields']['absence_end_date_timestamp']['id'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_end_date_timestamp']['field'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['label'] = 'Absence end date';
$handler->display->display_options['fields']['absence_end_date_timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['absence_end_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_end_date_timestamp']['custom_date_format'] = 'd M, Y';
$handler->display->display_options['fields']['absence_end_date_timestamp']['timezone'] = 'Europe/London';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Absences';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[absence_title] ([absence_start_date_timestamp] - [absence_end_date_timestamp])';
/* Sort criterion: Absence entity: Absence_start_date_timestamp */
$handler->display->display_options['sorts']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['sorts']['absence_start_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['sorts']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
/* Contextual filter: Absence entity: Drupal_uid */
$handler->display->display_options['arguments']['drupal_uid']['id'] = 'drupal_uid';
$handler->display->display_options['arguments']['drupal_uid']['table'] = 'absence_list';
$handler->display->display_options['arguments']['drupal_uid']['field'] = 'drupal_uid';
$handler->display->display_options['arguments']['drupal_uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['drupal_uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['drupal_uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['drupal_uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['drupal_uid']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Absence entity: Absence_start_date_timestamp */
$handler->display->display_options['filters']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['filters']['absence_start_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['filters']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
$handler->display->display_options['filters']['absence_start_date_timestamp']['exposed'] = TRUE;
$handler->display->display_options['filters']['absence_start_date_timestamp']['expose']['operator_id'] = 'absence_start_date_timestamp_op';
$handler->display->display_options['filters']['absence_start_date_timestamp']['expose']['label'] = 'Absence_start_date_timestamp';
$handler->display->display_options['filters']['absence_start_date_timestamp']['expose']['operator'] = 'absence_start_date_timestamp_op';
$handler->display->display_options['filters']['absence_start_date_timestamp']['expose']['identifier'] = 'absence_start_date_timestamp';
$handler->display->display_options['filters']['absence_start_date_timestamp']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['absence_start_date_timestamp']['group_info']['label'] = 'Period';
$handler->display->display_options['filters']['absence_start_date_timestamp']['group_info']['identifier'] = 'absence_start_date_timestamp';
$handler->display->display_options['filters']['absence_start_date_timestamp']['group_info']['optional'] = FALSE;
$handler->display->display_options['filters']['absence_start_date_timestamp']['group_info']['default_group'] = '1';
$handler->display->display_options['filters']['absence_start_date_timestamp']['group_info']['group_items'] = array(
  1 => array(
    'title' => '2014',
    'operator' => 'between',
    'value' => array(
      'type' => 'date',
      'value' => '',
      'min' => '2014-01-01 00:00:00',
      'max' => '2014-12-31 00:00:00',
    ),
  ),
  2 => array(
    'title' => '2015',
    'operator' => 'between',
    'value' => array(
      'type' => 'date',
      'value' => '',
      'min' => '2015-01-01 00:00:00',
      'max' => '2015-12-01 00:00:00',
    ),
  ),
  3 => array(
    'title' => '',
    'operator' => '=',
    'value' => array(
      'type' => 'date',
      'value' => '',
      'min' => '',
      'max' => '',
    ),
  ),
);

/* Display: Leave report */
$handler = $view->new_display('page', 'Leave report', 'page');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'activity_type_id' => 'activity_type_id',
  'is_credit' => 'is_credit',
  'absence_title' => 'absence_title',
  'drupal_uid' => 'drupal_uid',
  'absence_start_date_timestamp' => 'absence_start_date_timestamp',
  'absence_end_date_timestamp' => 'absence_end_date_timestamp',
  'nothing' => 'nothing'
);

/**
 * Dynamic field creation start - CiviHR
**/

foreach ($absenceTypes as $absenceType) {

    if (isset($absenceType['id']) && $absenceType['is_active'] == 1) {
        
        // Should have a settings somewhere that the Sick type is our special case, which we need to display in different block
        if ($absenceType['name'] != 'Sick') {
            $handler->display->display_options['style_options']['columns']['duration_' . $absenceType['id']] = 'duration_' . $absenceType['id'];
        }
    }
    
}

/**
 * Dynamic field creation end - CiviHR
**/

$handler->display->display_options['style_options']['default'] = 'absence_start_date_timestamp';
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
  'is_credit' => array(
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
  'drupal_uid' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'absence_start_date_timestamp' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'absence_end_date_timestamp' => array(
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
  ) 
);


/**
 * Dynamic field creation start - CiviHR
**/

foreach ($absenceTypes as $absenceType) {

    if (isset($absenceType['id']) && $absenceType['is_active'] == 1) {
        
        // Should have a settings somewhere that the Sick type is our special case, which we need to display in different block
        if ($absenceType['name'] != 'Sick') {
            $handler->display->display_options['style_options']['info']['duration_' . $absenceType['id']] = array(
                'sortable' => 0,
                'default_sort_order' => 'asc',
                'align' => '',
                'separator' => '',
                'empty_column' => 0,
            );
        }
    }
    
}

/**
 * Dynamic field creation end - CiviHR
**/

$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: View area */
$handler->display->display_options['header']['view']['id'] = 'view';
$handler->display->display_options['header']['view']['table'] = 'views';
$handler->display->display_options['header']['view']['field'] = 'view';
$handler->display->display_options['header']['view']['view_to_insert'] = 'absence_entitlement:page';
$handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Absence entity: Balance / Totals block area */
$handler->display->display_options['footer']['balance_totals']['id'] = 'balance_totals';
$handler->display->display_options['footer']['balance_totals']['table'] = 'absence_list';
$handler->display->display_options['footer']['balance_totals']['field'] = 'balance_totals';
/* Footer: Global: Block area */
$handler->display->display_options['footer']['block']['id'] = 'block';
$handler->display->display_options['footer']['block']['table'] = 'views';
$handler->display->display_options['footer']['block']['field'] = 'block';
$handler->display->display_options['footer']['block']['empty'] = TRUE;
$handler->display->display_options['footer']['block']['block_to_insert'] = 'civihr_employee_portal:absence_links';
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
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Activity type ID';
$handler->display->display_options['fields']['activity_type_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['activity_type_id']['separator'] = '';
/* Field: Absence entity: Is_credit */
$handler->display->display_options['fields']['is_credit']['id'] = 'is_credit';
$handler->display->display_options['fields']['is_credit']['table'] = 'absence_list';
$handler->display->display_options['fields']['is_credit']['field'] = 'is_credit';
$handler->display->display_options['fields']['is_credit']['exclude'] = TRUE;
$handler->display->display_options['fields']['is_credit']['separator'] = '';
/* Field: Absence entity: Absence_title */
$handler->display->display_options['fields']['absence_title']['id'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_title']['field'] = 'absence_title';
$handler->display->display_options['fields']['absence_title']['label'] = 'Absence title';
$handler->display->display_options['fields']['absence_title']['exclude'] = TRUE;
/* Field: Absence entity: Drupal_uid */
$handler->display->display_options['fields']['drupal_uid']['id'] = 'drupal_uid';
$handler->display->display_options['fields']['drupal_uid']['table'] = 'absence_list';
$handler->display->display_options['fields']['drupal_uid']['field'] = 'drupal_uid';
$handler->display->display_options['fields']['drupal_uid']['label'] = 'Drupal UID';
$handler->display->display_options['fields']['drupal_uid']['exclude'] = TRUE;
$handler->display->display_options['fields']['drupal_uid']['separator'] = '';
/* Field: Absence entity: Absence_start_date_timestamp */
$handler->display->display_options['fields']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['label'] = 'Absence start date';
$handler->display->display_options['fields']['absence_start_date_timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_start_date_timestamp']['custom_date_format'] = 'd M, Y';
$handler->display->display_options['fields']['absence_start_date_timestamp']['timezone'] = 'Europe/London';
/* Field: Absence entity: Absence_end_date_timestamp */
$handler->display->display_options['fields']['absence_end_date_timestamp']['id'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_end_date_timestamp']['field'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['label'] = 'Absence end date';
$handler->display->display_options['fields']['absence_end_date_timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['absence_end_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_end_date_timestamp']['custom_date_format'] = 'd M, Y';
$handler->display->display_options['fields']['absence_end_date_timestamp']['timezone'] = 'Europe/London';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[absence_title] ([absence_start_date_timestamp] - [absence_end_date_timestamp])';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: Absence entity: Absence status */
$handler->display->display_options['fields']['absence_status']['id'] = 'absence_status';
$handler->display->display_options['fields']['absence_status']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_status']['field'] = 'absence_status';
$handler->display->display_options['fields']['absence_status']['label'] = '';
$handler->display->display_options['fields']['absence_status']['element_label_colon'] = FALSE;

/**
 * Dynamic field creation start - CiviHR
**/

foreach ($absenceTypes as $absenceType) {

    if (isset($absenceType['id']) && $absenceType['is_active'] == 1) {
        
        
        // Store the debit / credit activity type IDs as well
        $suffix = '';

        if (isset($absenceType['allow_debits']) && $absenceType['allow_debits'] == '1') {
            $suffix .= '_' . $absenceType['debit_activity_type_id'];
        }

        if (isset($absenceType['allow_credits']) && $absenceType['allow_credits'] == '1') {
            $suffix .= '_' . $absenceType['credit_activity_type_id'];
        }
            

        // Should have a settings somewhere that the Sick type is our special case, which we need to display in different block
        if ($absenceType['name'] != 'Sick') {
            /* Field: Absence entity: Absence type row value (Duration) */
            $handler->display->display_options['fields']['duration_' . $absenceType['id']]['id'] = 'duration_' . $absenceType['id'];
            $handler->display->display_options['fields']['duration_' . $absenceType['id']]['table'] = 'absence_list';
            $handler->display->display_options['fields']['duration_' . $absenceType['id']]['field'] = 'duration';
            $handler->display->display_options['fields']['duration_' . $absenceType['id']]['label'] = '';
            $handler->display->display_options['fields']['duration_' . $absenceType['id']]['element_label_colon'] = FALSE;
            $handler->display->display_options['fields']['duration_' . $absenceType['id']]['duration_type'] = $absenceType['id'] . $suffix;
        }

    }

}

/**
 * Dynamic field creation end - CiviHR
**/

$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Absence entity: Absence date filter based on Civi date periods */
$handler->display->display_options['filters']['absence_start_date_period_filter']['id'] = 'absence_start_date_period_filter';
$handler->display->display_options['filters']['absence_start_date_period_filter']['table'] = 'absence_list';
$handler->display->display_options['filters']['absence_start_date_period_filter']['field'] = 'absence_start_date_period_filter';
$handler->display->display_options['filters']['absence_start_date_period_filter']['group'] = 1;
$handler->display->display_options['filters']['absence_start_date_period_filter']['exposed'] = TRUE;
$handler->display->display_options['filters']['absence_start_date_period_filter']['expose']['operator_id'] = 'absence_start_date_period_filter_op';
$handler->display->display_options['filters']['absence_start_date_period_filter']['expose']['label'] = 'Absence date filter based on Civi date periods';
$handler->display->display_options['filters']['absence_start_date_period_filter']['expose']['operator'] = 'absence_start_date_period_filter_op';
$handler->display->display_options['filters']['absence_start_date_period_filter']['expose']['identifier'] = 'absence_start_date_period_filter';
$handler->display->display_options['filters']['absence_start_date_period_filter']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['label'] = 'My leave';
$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['identifier'] = 'absence_start_date_period_filter';
$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['optional'] = FALSE;
$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['default_group'] = '1';

/**
 * Dynamic field creation start - CiviHR
**/

$current_year = date("Y");

$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['group_items'] = array(
  1 => array(
    'title' => 'Generated from code (Do not overwrite)',
    'operator' => 'between',
    'value' => array(
      'type' => 'date',
      'value' => '',
      'min' => $current_year . '-01-01 00:00:00',
      'max' => $current_year . '-12-31 23:59:59',
    ),
  )   
    
);

/**
 * Dynamic field creation end - CiviHR
**/


/* Filter criterion: Absence entity: Absence_title */
$handler->display->display_options['filters']['absence_title']['id'] = 'absence_title';
$handler->display->display_options['filters']['absence_title']['table'] = 'absence_list';
$handler->display->display_options['filters']['absence_title']['field'] = 'absence_title';
$handler->display->display_options['filters']['absence_title']['operator'] = '!=';
$handler->display->display_options['filters']['absence_title']['value'] = 'Sick';
$handler->display->display_options['filters']['absence_title']['group'] = 1;
$handler->display->display_options['path'] = 'absence-list';

/* Display: Sickness report */
$handler = $view->new_display('page', 'Sickness report', 'page_1');
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
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
$handler->display->display_options['fields']['absence_title']['label'] = 'Absence title';
$handler->display->display_options['fields']['absence_title']['exclude'] = TRUE;
/* Field: Absence entity: Drupal_uid */
$handler->display->display_options['fields']['drupal_uid']['id'] = 'drupal_uid';
$handler->display->display_options['fields']['drupal_uid']['table'] = 'absence_list';
$handler->display->display_options['fields']['drupal_uid']['field'] = 'drupal_uid';
$handler->display->display_options['fields']['drupal_uid']['label'] = 'Drupal UID';
$handler->display->display_options['fields']['drupal_uid']['exclude'] = TRUE;
$handler->display->display_options['fields']['drupal_uid']['separator'] = '';
/* Field: Absence entity: Absence_start_date_timestamp */
$handler->display->display_options['fields']['absence_start_date_timestamp']['id'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_start_date_timestamp']['field'] = 'absence_start_date_timestamp';
$handler->display->display_options['fields']['absence_start_date_timestamp']['label'] = 'Absence start date';
$handler->display->display_options['fields']['absence_start_date_timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['absence_start_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_start_date_timestamp']['custom_date_format'] = 'd M, Y';
$handler->display->display_options['fields']['absence_start_date_timestamp']['timezone'] = 'Europe/London';
/* Field: Absence entity: Absence_end_date_timestamp */
$handler->display->display_options['fields']['absence_end_date_timestamp']['id'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_end_date_timestamp']['field'] = 'absence_end_date_timestamp';
$handler->display->display_options['fields']['absence_end_date_timestamp']['label'] = 'Absence end date';
$handler->display->display_options['fields']['absence_end_date_timestamp']['exclude'] = TRUE;
$handler->display->display_options['fields']['absence_end_date_timestamp']['date_format'] = 'custom';
$handler->display->display_options['fields']['absence_end_date_timestamp']['custom_date_format'] = 'd M, Y';
$handler->display->display_options['fields']['absence_end_date_timestamp']['timezone'] = 'Europe/London';
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = 'Description';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[absence_title] ([absence_start_date_timestamp] - [absence_end_date_timestamp])';
/* Field: Absence entity: Absence status */
$handler->display->display_options['fields']['absence_status']['id'] = 'absence_status';
$handler->display->display_options['fields']['absence_status']['table'] = 'absence_list';
$handler->display->display_options['fields']['absence_status']['field'] = 'absence_status';
$handler->display->display_options['fields']['absence_status']['label'] = 'Status';
/* Field: Absence entity: Absence type row value (Duration) */
$handler->display->display_options['fields']['duration']['id'] = 'duration';
$handler->display->display_options['fields']['duration']['table'] = 'absence_list';
$handler->display->display_options['fields']['duration']['field'] = 'duration';
$handler->display->display_options['fields']['duration']['label'] = 'Number of days';
$handler->display->display_options['fields']['duration']['duration_type'] = '1_52';
/* Field: Absence entity: Details */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'absence_list';
$handler->display->display_options['fields']['details']['field'] = 'details';
$handler->display->display_options['fields']['details']['label'] = 'Comments';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Absence entity: Absence date filter based on Civi date periods */
$handler->display->display_options['filters']['absence_start_date_period_filter']['id'] = 'absence_start_date_period_filter';
$handler->display->display_options['filters']['absence_start_date_period_filter']['table'] = 'absence_list';
$handler->display->display_options['filters']['absence_start_date_period_filter']['field'] = 'absence_start_date_period_filter';
$handler->display->display_options['filters']['absence_start_date_period_filter']['group'] = 1;
$handler->display->display_options['filters']['absence_start_date_period_filter']['exposed'] = TRUE;
$handler->display->display_options['filters']['absence_start_date_period_filter']['expose']['operator_id'] = 'absence_start_date_period_filter_op';
$handler->display->display_options['filters']['absence_start_date_period_filter']['expose']['label'] = 'Absence date filter based on Civi date periods';
$handler->display->display_options['filters']['absence_start_date_period_filter']['expose']['operator'] = 'absence_start_date_period_filter_op';
$handler->display->display_options['filters']['absence_start_date_period_filter']['expose']['identifier'] = 'absence_start_date_period_filter';
$handler->display->display_options['filters']['absence_start_date_period_filter']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['label'] = 'My sickness report';
$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['identifier'] = 'absence_start_date_period_filter';
$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['optional'] = FALSE;
$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['default_group'] = '1';

/**
 * Dynamic field creation start - CiviHR
**/

$current_year = date("Y");

$handler->display->display_options['filters']['absence_start_date_period_filter']['group_info']['group_items'] = array(
  1 => array(
    'title' => 'Generated from code (Do not overwrite)',
    'operator' => 'between',
    'value' => array(
      'type' => 'date',
      'value' => '',
      'min' => $current_year . '-01-01 00:00:00',
      'max' => $current_year . '-12-31 23:59:59',
    ),
  )   
    
);

/**
 * Dynamic field creation end - CiviHR
**/

/* Filter criterion: Absence entity: Absence_title */
$handler->display->display_options['filters']['absence_title']['id'] = 'absence_title';
$handler->display->display_options['filters']['absence_title']['table'] = 'absence_list';
$handler->display->display_options['filters']['absence_title']['field'] = 'absence_title';
$handler->display->display_options['filters']['absence_title']['value'] = 'Sick';
$handler->display->display_options['filters']['absence_title']['group'] = 1;
$handler->display->display_options['path'] = 'sickness-report';
$translatables['absence_list'] = array(
  t('Master'),
  t('Absence list'),
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
  t('No results for the selected period!'),
  t('Absence entity ID'),
  t('.'),
  t('Absence title'),
  t('Drupal UID'),
  t('Absence start date'),
  t('Absence end date'),
  t('Absences'),
  t('[absence_title] ([absence_start_date_timestamp] - [absence_end_date_timestamp])'),
  t('All'),
  t('Absence_start_date_timestamp'),
  t('Period'),
  t('Leave report'),
  t('Activity type ID'),
  t('Is_credit'),
  t('Absence date filter based on Civi date periods'),
  t('My leave'),
  t('Sickness report'),
  t('Description'),
  t('Status'),
  t('Number of days'),
  t('Comments'),
  t('My sickness report'),
);