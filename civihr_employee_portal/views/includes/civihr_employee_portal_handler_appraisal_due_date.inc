
<?php

/**
 * Custom views handler field to display the Appraisal due date
 */
class civihr_employee_portal_handler_appraisal_due_date extends views_handler_field {
    function render($values) {
        $selfAppraisalDue = $values->self_appraisal_due;
        $managerAppraisalDue = $values->manager_appraisal_due;
        $gradeDue = $values->grade_due;
        
        return get_appraisal_due_date($selfAppraisalDue, $managerAppraisalDue, $gradeDue);
    }
}
