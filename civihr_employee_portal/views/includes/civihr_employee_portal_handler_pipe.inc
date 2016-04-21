<?php

/**
 * Custom views handler field to replace '|' character with ', '
 */
class civihr_employee_portal_handler_pipe extends views_handler_field {
    function render($values) {
        $value = $this->get_value($values);
        $expl = explode('|', $value);
        $items = array();
        foreach ($expl as $item) {
            if ($item !== '') {
                $items[] = $item;
            }
        }
        return implode(', ', $items);
    }
}
