
<?php

/**
 * Custom views handler field to display the task type
 */
class civihr_employee_portal_handler_activity_type extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        return get_activity_type_value($value);
    }
}
