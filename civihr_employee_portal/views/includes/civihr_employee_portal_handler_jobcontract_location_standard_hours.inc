<?php

/**
 * Custom views handler field to display the Job Contract location standard hours
 */
class civihr_employee_portal_handler_jobcontract_location_standard_hours extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        return get_jobcontract_location_standard_hours($value);
    }
}
