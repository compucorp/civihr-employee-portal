<?php

/**
 * Custom views handler field to display date in Y-m-d format
 */
class civihr_employee_portal_handler_date_yyyy_mm_dd extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        $timestamp = strtotime($value);
        if (!$timestamp || $timestamp < 0) {
            return '';
        }
        return date('Y-m-d', $timestamp);
    }
}
