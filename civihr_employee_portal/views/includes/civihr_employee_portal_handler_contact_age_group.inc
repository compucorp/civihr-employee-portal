<?php

/**
 * Custom views handler field to display the Age Group label for given age
 */
class civihr_employee_portal_handler_contact_age_group extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        $dateTime = DateTime::createFromFormat('Y-m-d', $value);
        if (!$dateTime) {
            return '';
        }
        $age = $dateTime->diff(new DateTime('now'))->y;
        return get_contact_age_group_label_by_age($age);
    }
}
