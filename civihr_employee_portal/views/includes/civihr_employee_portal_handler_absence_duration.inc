<?php

/** @file
 *  Handles filtering by networks
 */
class civihr_employee_portal_handler_absence_duration extends views_handler_field {
    
    function render($values) {
        
        $absence_type_values = explode('_', $this->options['duration_type']);
        $absence_type_ids = array();
        
        if (isset($absence_type_values[1]) && $absence_type_values[1] != '') {
            $absence_type_ids[] = $absence_type_values[1];
        }
        
        if (isset($absence_type_values[2]) && $absence_type_values[2] != '') {
            $absence_type_ids[] = $absence_type_values[2];
        }
        
        /**
         * Special case for handling duration for absence_list block (Leave and Sickness block)
         */
        if (isset($values->absence_list_activity_type_id)) {
            
            if (in_array($values->absence_list_activity_type_id, $absence_type_ids)) {

                if (isset($values->absence_list_is_credit) && $values->absence_list_is_credit == '1') {
                    return '+' . ' ' . $values->absence_list_duration / (6 * 80);
                }

                return '-' . ' ' . $values->absence_list_duration / (6 * 80);
            }
        }
        
        else {
            $value = $this->get_value($values);
            
            return $value <= 480 ? $value / (6 * 80) . ' day' : $value / (6 * 80) . ' days';
        }
        
        // No match leave the field empty (empty columns will be hidden by views)
        return '';

    }

    function option_definition() {
        $options = parent::option_definition();
        
        // Define our custom settings fields
        $options['duration_type'] = array();
        
        return $options;
     }

    function options_form(&$form, &$form_state) {    
        
        $options = array();
        
        // Get the absence types
        $absenceTypes = get_civihr_absence_types();
        
        foreach ($absenceTypes as $absenceType) {
            
            // Store the debit / credit activity type IDs as well
            $suffix = '';
            
            if (isset($absenceType['allow_debits']) && $absenceType['allow_debits'] == '1') {
                $suffix .= '_' . $absenceType['debit_activity_type_id'];
            }
            
            if (isset($absenceType['allow_credits']) && $absenceType['allow_credits'] == '1') {
                $suffix .= '_' . $absenceType['credit_activity_type_id'];
            }
            
            /**
             * Check if the absence type is active, if active populate in the options list
             */
            if (isset($absenceType['is_active']) && $absenceType['is_active'] == '1') {
            
                if (isset($suffix) && $suffix != '') {
                    $options[$absenceType['id'] . $suffix] = $absenceType['title'];
                }
                
            }
        }

        $form['duration_type'] = array(
            '#type' => 'select',
            '#title' => t('Absence type'),
            '#options' => $options,
            '#default_value' => isset($this->options['duration_type']) ? $this->options['duration_type'] : '',
            '#required' => TRUE
        );

        parent::options_form($form, $form_state);

    }     

    function options_submit(&$form, &$form_state) {
        parent::options_submit($form, $form_state);
        
        // Update our custom values
        $this->options['duration_type'] = $form_state['values']['options']['duration_type'];
        
    }

}