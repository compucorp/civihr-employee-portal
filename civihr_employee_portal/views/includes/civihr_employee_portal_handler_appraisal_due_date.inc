
<?php

/**
 * Custom views handler field to display the Appraisal due date
 */
class civihr_employee_portal_handler_appraisal_due_date extends views_handler_field {

  function render($values) {
    $selfAppraisalDue = $values->appraisal_self_appraisal_due;
    $managerAppraisalDue = $values->appraisal_manager_appraisal_due;
    $gradeDue = $values->appraisal_grade_due;

    return get_appraisal_due_date($selfAppraisalDue, $managerAppraisalDue, $gradeDue);
  }

  function query() {
  }

}
