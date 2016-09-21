<?php

/**
 * Custom views handler field to display the employee name from the employee ID
 */
class civihr_employee_portal_handler_absence_status extends views_handler_field {
    
    function render($values) {
        
        // Get the status_id
        $value = $this->get_value($values);
         
        // Find the absence status based on status_id
        $abence_status_value = get_civihr_absence_statuses($value);
    
        return $abence_status_value;
    }

}