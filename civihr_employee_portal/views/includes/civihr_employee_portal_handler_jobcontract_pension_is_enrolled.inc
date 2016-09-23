<?php

/**
 * Custom views handler field to display the Job Contract pension 'is enrolled' label
 */
class civihr_employee_portal_handler_jobcontract_pension_is_enrolled extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        return get_jobcontract_pension_is_enrolled($value);
    }
}
