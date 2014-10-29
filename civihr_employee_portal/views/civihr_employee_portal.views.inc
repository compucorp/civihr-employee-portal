<?php

// This file must be at civihr_employee_portal/views directory.
 
/**
 * @file
 * Views definitions for civihr_employee_portal module.
 */
 
/**
 * Implements hook_views_data_alter().
 */
function civihr_employee_portal_views_data_alter(&$data) {
        
    $data['json']['absence_entitlement'] = array(
        'title' => t('Absence entitlement value'),
        'help' => t('Absence entitlement'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_entitlement',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_handler_argument_query_string',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['period_html'] = array(
        'title' => t('Html field for period date'),
        'help' => t('Displays html field based on period ID'),
        'real field' => 'period_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_period',
            'click sortable' => FALSE,
        ),
        
    );
    
    // Add custom date handler
    $data['absence_list']['absence_start_date_timestamp']['field']['handler'] = 'views_handler_field_date';
    $data['absence_list']['absence_start_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
    $data['absence_list']['absence_start_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
    $data['absence_list']['absence_start_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';
    
    $data['absence_list']['absence_end_date_timestamp']['field']['handler'] = 'views_handler_field_date';
    $data['absence_list']['absence_end_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
    $data['absence_list']['absence_end_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
    $data['absence_list']['absence_end_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';
    
    $data['absence_list']['absence_start_date_period_filter'] = array(
        'title' => t('Absence date filter based on Civi date periods'),
        'help' => t('Absence date filter based on Civi date periods.'),
        'real field' => 'absence_start_date_timestamp',
        'field' => array(
            'handler' => 'views_handler_field_date',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_date',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'civihr_employee_portal_filter_absence_period',
            'help' => t('Filter absence list result based on Civi date periods'),
        ),
        'sort' => array('handler' => 'views_handler_sort_date'),
    );
    
    $data['absence_list']['duration'] = array(
        'title' => t('Absence type row value (Duration)'),
        'help' => t('Row value for each absence type (Duration)'),
        'real field' => 'duration',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_duration',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_numeric',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );
    
    $data['absence_list']['balance_totals'] = array(
        'title' => t('Balance / Totals block area'),
        'help' => t('Balance / Totals block area.'),
        'area' => array(
            'handler' => 'civihr_employee_portal_handler_area_totals',
        ),
    );
    
    return $data;
}