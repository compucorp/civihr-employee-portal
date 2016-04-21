<?php

/**
 * Custom views handler field to display Absence Duration in days
 */
class civihr_employee_portal_handler_absence_duration_in_days extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        if ($value === null || $value === '') {
            return '';
        }
        return number_format((int)$value / (60 * 8), 2, '.', '');
    }
}
