
<?php

/**
 * Custom views handler field to display the task status
 */
class civihr_employee_portal_handler_task_status extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        return get_task_statuses($value);
    }
}
