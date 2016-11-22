
<?php

/**
 * Custom views handler to display Task / Document date in specific format.
 */
class civihr_employee_portal_handler_tasks_date extends views_handler_field {
    function render($values) {
        $taskDate = strtotime(strip_tags($this->get_value($values)));
        $dateFilter = _get_task_filter_by_date(date('Y-m-d', $taskDate));
        $result = null;
        if ($dateFilter == 'tomorrow') {
          $result = 'Tomorrow';
        } else if ($dateFilter == 'today') {
          $result = 'Today';
        } else {
          $result = date('m/d/Y', $taskDate);
        }
        return $result;
    }
}
