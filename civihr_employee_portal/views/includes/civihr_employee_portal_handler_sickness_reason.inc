<?php

/**
 * Custom views handler field to display the sickness reason label
 * rather than the option value.
 */
class civihr_employee_portal_handler_sickness_reason extends views_handler_field {

    function render($values) {
        $value = $this->get_value($values);
        $sickness_reason_label = get_civihr_absence_sickness_reason_label($value);

        return $sickness_reason_label;
    }
}
