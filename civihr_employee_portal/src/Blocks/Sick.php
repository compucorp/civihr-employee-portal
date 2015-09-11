<?php

namespace Drupal\civihr_employee_portal\Blocks;

class Sick {

    public function generateBlock() {

        $name = 'absence_list';
        $display = 'page_1';
        $alter = array('exposed' => array('absence_start_date_period_filter' => variable_get('default_date_period_id', '1')));

        $view = views_get_view($name);

        $view->init_display($display);

        $view->preview = TRUE;
        $view->is_cacheable = TRUE;

        if(isset($alter['exposed'])){
            foreach($alter['exposed'] as $key => $valor) {
                $view->exposed_input[$key] = $valor;
            }
        }

        // Display the view with default filter
        $view->set_display($display);

        // Get the default filters
        $filters = $view->display_handler->get_option('filters');

        // Get civi defined date periods
        $civi_date_periods = get_civihr_date_periods();
        $filter_values = array();

        foreach ($civi_date_periods as $civi_date_period) {
            $filter_values[$civi_date_period['id']] = array('title' => $civi_date_period['title'], 'operator' => 'between', 'value' => array('type' => 'date', 'value' => '', 'min' => $civi_date_period['start_date'], 'max' => $civi_date_period['end_date']));
        }

        // Assign the new values to the filter
        $filters['absence_start_date_period_filter']['group_info']['group_items'] = $filter_values;

        // Update default view filters
        $view->display_handler->set_option('filters', $filters);
        $view->pre_execute();

        // Render sickness links block
        $sickness_links = render(module_invoke('civihr_employee_portal', 'block_view', 'sickness_links')['content']);

        return $view->render($display) . $sickness_links;

    }
}
