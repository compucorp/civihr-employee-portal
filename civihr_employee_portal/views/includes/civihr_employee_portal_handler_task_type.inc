
<?php

/**
 * Custom views handler field to display the task type
 */
class civihr_employee_portal_handler_task_type extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        return get_task_type($value);
    }
}
