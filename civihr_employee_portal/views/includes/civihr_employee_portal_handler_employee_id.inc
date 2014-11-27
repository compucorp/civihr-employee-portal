
<?php

/**
 * Custom views handler field to display the employee name from the employee ID
 */
class civihr_employee_portal_handler_employee_id extends views_handler_field {
    
    function render($values) {
            
        // Get the contact_id
        $value = $this->get_value($values);
        
        // Find the contact_name based on contact_id
        $data = get_civihr_contact_data($value);
    
        return $data['display_name'];
    }

}