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

/**
* Implements hook_views_pre_view().
*/
function civihr_employee_portal_views_pre_view(&$view, &$display_id, &$args){

    if($view->name == 'absence_list') {
         
        // Get civi defined date periods
        $civi_date_periods = get_civihr_date_periods();
        
        $filter_values = array();
        
        foreach ($civi_date_periods as $civi_date_period) {
            
            $filter_values[$civi_date_period['id']] = array('title' => $civi_date_period['title'], 'operator' => 'between', 'value' => array('type' => 'date', 'value' => '', 'min' => $civi_date_period['start_date'], 'max' => $civi_date_period['end_date']));
            
        }
        
        // Get the period date filters and modify them
        $filters = $view->display_handler->get_option('filters');

        // Overwrite default filter values
        $filters['absence_start_date_timestamp']['group_info']['group_items'] = $filter_values;
        
        // Set the values
        $view->display_handler->set_option('filters', $filters);
               
    }

}