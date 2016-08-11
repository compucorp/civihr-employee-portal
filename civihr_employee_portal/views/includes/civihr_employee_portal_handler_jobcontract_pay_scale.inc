<?php

/**
 * Custom views handler field to display the Job Contract pay scale
 */
class civihr_employee_portal_handler_jobcontract_pay_scale extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        return get_jobcontract_pay_scale($value);
    }
}
