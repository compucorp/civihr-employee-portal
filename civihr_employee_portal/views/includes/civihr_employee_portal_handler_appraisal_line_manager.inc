
<?php

/**
 * Custom views handler field to display the Appraisal line manager
 */
class civihr_employee_portal_handler_appraisal_line_manager extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        $contact_data = get_civihr_contact_data($value);
        
        return $contact_data['display_name'];
    }
}
