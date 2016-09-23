<?php

/**
 * Custom views handler field to display name of day of week by its MySQL integer format
 */
class civihr_employee_portal_handler_absence_day_of_week extends views_handler_field {
    private $_daysOfWeek = array(
        0 => '7. Sunday',
        1 => '1. Monday',
        2 => '2. Tuesday',
        3 => '3. Wednesday',
        4 => '4. Thursday',
        5 => '5. Friday',
        6 => '6. Saturday',
    );
    function render($values) {
        $value = $this->get_value($values);
        if ($value) {
            return t($this->_daysOfWeek((int)$value));
        }
        return '';
    }
}
