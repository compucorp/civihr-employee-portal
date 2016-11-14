
<?php

/**
 * Custom views handler to display Task / Document date in specific format.
 */
class civihr_employee_portal_handler_documents_date extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        return date('M d Y', strtotime(strip_tags($value)));
    }
}
