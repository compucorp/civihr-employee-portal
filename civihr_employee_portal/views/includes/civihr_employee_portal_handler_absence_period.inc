<?php

/** @file
 *  HTML field handler for absence_period
 */
class civihr_employee_portal_handler_absence_period extends views_handler_field {
    
    function render($values) {
        
        $civi_date_periods = get_civihr_date_periods();
        
        $filter_values = array();
        
        foreach ($civi_date_periods as $civi_date_period) {
            
            if ($civi_date_period['id'] == $values->period_id) {
                return '<div>' . t('Absence entitlement from') . '</div><div>' . $civi_date_period['title'] . '</div>';
            }
            
        }
        
        // No match leave the field empty (empty columns will be hidden by views)
        return '';

    }

    function option_definition() {
        $options = parent::option_definition();
        
        // Define our custom settings fields
        $options['absence_period_settings'] = array();
        
        return $options;
     }

    function options_form(&$form, &$form_state) {    
        
        $options = array();
        $options['1'] = 'test1';
        $options['2'] = 'test2';

        $form['absence_period_settings'] = array(
            '#type' => 'select',
            '#title' => t('Absence period settings'),
            '#options' => $options,
            '#default_value' => isset($this->options['absence_period_settings']) ? $this->options['absence_period_settings'] : '',
            '#required' => TRUE
        );

        parent::options_form($form, $form_state);

    }     

    function options_submit(&$form, &$form_state) {
        parent::options_submit($form, $form_state);
        
        // Update our custom values
        $this->options['absence_period_settings'] = $form_state['values']['options']['absence_period_settings'];
        
    }

}