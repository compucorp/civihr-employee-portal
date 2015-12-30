
<?php

/**
 * Custom views handler field to display the Appraisal cycle period
 */
class civihr_employee_portal_handler_appraisal_cycle_period extends views_handler_field {
    function render($values) {
        $cycleStartDate = $values->{"api.AppraisalCycle.getsingle/cycle_start_date"};
        $cycleEndDate = $values->{"api.AppraisalCycle.getsingle/cycle_end_date"};
        
        return get_appraisal_cycle_period($cycleStartDate, $cycleEndDate);
    }
}
