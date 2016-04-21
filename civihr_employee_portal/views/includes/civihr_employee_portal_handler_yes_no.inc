<?php

/**
 * Custom views handler field to boolean value converted to 'Yes' / 'No' string
 */
class civihr_employee_portal_handler_yes_no extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        if ($value === null || $value === '') {
            return '';
        }
        return (int)$value ? t('Yes') : t('No');
    }
}
