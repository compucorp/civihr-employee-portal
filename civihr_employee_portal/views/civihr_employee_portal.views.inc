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

    /**
     * Custom field handler which will create age group based on the contact birth date
     */
    $data['civicrm_contact']['age_group'] = array(
        'title' => t('Age Group'),
        'help' => t('Age group for the contact'),
        'real field' => 'birth_date',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_age_group',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'civihr_employee_portal_argument_age_group',
            'name field' => 'birth_date',
            'numeric' => FALSE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );

    // Add custom date handler for job contract start/end dates
    $data['hrjc_details']['period_start_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
    $data['hrjc_details']['period_end_date']['argument']['handler'] = 'civihr_employee_portal_argument_date_range';
        
    $data['json']['absence_entitlement'] = array(
        'title' => t('Absence entitlement value'),
        'help' => t('Absence entitlement'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_entitlement',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['document_contacts'] = array(
        'title' => t('Document contacts'),
        'help' => t('Document contacts'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_document_contacts',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_document_contacts_request_handler',
            'name_field' => 'document_targets',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['document_status'] = array(
        'title' => t('Document status'),
        'help' => t('Document status'),
        'real field' => 'status_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_document_status',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'subject',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );

    $data['json']['task_contacts'] = array(
        'title' => t('Task contacts'),
        'help' => t('Task contacts'),
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_task_contacts',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_task_contacts_request_handler',
            'name_field' => 'task_targets',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['task_status'] = array(
        'title' => t('Task status'),
        'help' => t('Task status'),
        'real field' => 'status_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_task_status',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'task_status',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_json_query_handler_filter',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_json_query_handler_sort'),
    );
    
    $data['json']['task_type'] = array(
        'title' => t('Task type'),
        'help' => t('Task type'),
        'real field' => 'activity_type_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_task_type',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_json_query_argument_request_handler',
            'name_field' => 'task_type',
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
    
    $data['absence_list']['absence_status'] = array(
        'title' => t('Absence status'),
        'help' => t('Absence status field value'),
        'real field' => 'absence_status',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_status',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
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
    
    $data['absence_approval_list']['civi_target_contact_name'] = array(
        'title' => t('Civi contact name - absence target contact'),
        'help' => t('Civi contact name for the assigned absence/activity target contact'),
        'real field' => 'employee_id',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_employee_id',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );
    
    $data['absence_approval_list']['duration'] = array(
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
    
    $data['absence_approval_list']['absence_status'] = array(
        'title' => t('Absence status'),
        'help' => t('Absence status field value'),
        'real field' => 'absence_status',
        'field' => array(
            'handler' => 'civihr_employee_portal_handler_absence_status',
            'click sortable' => TRUE,
        ),
        'argument' => array(
            'handler' => 'views_handler_argument_string',
            'name_field' => 'title',
            'string' => TRUE
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
            'help' => t('Filter results to a particular result set'),
        ),
        'sort' => array('handler' => 'views_handler_sort'),
    );
    
    // Add custom date handler
    $data['absence_approval_list']['absence_start_date_timestamp']['field']['handler'] = 'views_handler_field_date';
    $data['absence_approval_list']['absence_start_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
    $data['absence_approval_list']['absence_start_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
    $data['absence_approval_list']['absence_start_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';
    
    $data['absence_approval_list']['absence_end_date_timestamp']['field']['handler'] = 'views_handler_field_date';
    $data['absence_approval_list']['absence_end_date_timestamp']['sort']['handler'] = 'views_handler_sort_date';
    $data['absence_approval_list']['absence_end_date_timestamp']['filter']['handler'] = 'views_handler_filter_date';
    $data['absence_approval_list']['absence_end_date_timestamp']['argument']['handler'] = 'views_handler_argument_date';
    
    return $data;
}

/**
 * Implements hook_views_pre_render().
 * Adding required js for the modal window
 */
function civihr_employee_portal_views_pre_render(&$view) {

    if ($view->name == 'hr_documents') {

        if ($view->current_display == 'hr_resources') {

            ctools_include('modal');
            ctools_modal_add_js();

        }
    }
    
    if($view->name == "civihr_staff_directory"){
      $view->result = removeInactiveManagers($view->result);
    }
}

/**
 * Implements hook_views_post_render().
 * Remove additional commas
 */
function civihr_employee_portal_views_post_render(&$view, &$output, &$cache) {
  foreach($view->style_plugin->rendered_fields as $renderedField){
    $fieldsToClean[$renderedField['display_name_1']] = trim($renderedField['display_name_1'], ', ');
    $fieldsToClean[$renderedField['department']] = trim($renderedField['department'], ', ');
  }
  $output = strtr($output, $fieldsToClean);
}

function removeInactiveManagers($results = array()) {
  foreach ($results as $key => $value) {
    if ($value->civicrm_relationship_is_active == 0 ||
       ($value->civicrm_relationship_end_date < date('Y-m-d') && $value->civicrm_relationship_end_date != NULL))
        {
          $value->civicrm_contact_civicrm_relationship_display_name = NULL;
        }
    }
  return $results;
}

/**
 * Implements hook_views_pre_view().
 * @param $view
 * @param $display_id
 * @param $args
 */
function civihr_employee_portal_views_pre_view(&$view, &$display_id, &$args) {

    // Custom configuration start for items per page
    if (($view->name == 'civihr_staff_directory' && $display_id == 'page') ||
        ($view->name == 'hr_documents' && $display_id == 'hr_resources')) {

        // Default value for items per page
        $default_count = $view->display_handler->display->display_options['pager']['options']['items_per_page'];

        // Set number of items to show
        $numbers_to_show = explode(',', $view->display_handler->display->display_options['pager']['options']['expose']['items_per_page_options']);

        // Generate page path
        $view_url_path = $view->display[$display_id]->display_options['path'];
        $vupc = strlen($view_url_path);
        $page_path = substr($_GET['q'], 0, $vupc);

        // Set items to show per page
        $selected_count = isset($_GET['items_per_page']) ? $_GET['items_per_page'] : $default_count;

        // Create links
        // Not using the l function as it can't handle the "active" class correctly (https://www.drupal.org/node/1410574)
        $items_per_page = array_map(
            function ($item) use ($page_path, $selected_count) {
                $item = trim($item);
                $href = $page_path . '?items_per_page=' . $item;
                $class = 'chr_search-result__items-per-page__list__item btn btn-default';

                if ($selected_count == $item) {
                    $class .= ' active';
                }

                return sprintf('<a href="%s" class="%s">%s</a>', $href, $class, $item);
            },
            $numbers_to_show
        );

        $item_per_page_nav = '<nav class="chr_search-result__items-per-page">
            <span>' . t('View:') . '</span>
            <div class="chr_search-result__items-per-page__list btn-group btn-group-sm">'
                . implode('', $items_per_page ) .
            '</div>
        </nav>';

        // Set the custom footer
        $view->set_item_option(
            $display_id,
            'footer',
            'area_text_custom',
            'content',
            $item_per_page_nav
        );

        // Set the custom header
        $view->set_item_option(
            $display_id,
            'header',
            'result',
            'content',
            '<div class="chr_search-result__total">'
                . t('Results') .
                '<span class="chr_search-result__total__count">'
                    . $view->get_item($display_id, 'header', 'result')['content'] .
                '</span>
            </div>' . $item_per_page_nav
        );

        // Set items per page to the view
        $view->set_items_per_page($selected_count);
    }
}
