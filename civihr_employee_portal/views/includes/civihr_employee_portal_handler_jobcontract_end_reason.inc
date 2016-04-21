<?php

/**
 * Custom views handler field to display the Job Contract end reason
 */
class civihr_employee_portal_handler_jobcontract_end_reason extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        return get_jobcontract_end_reason($value);
    }
}
