
<?php

/**
 * Custom views handler field to display the Appraisal cycle type
 */
class civihr_employee_portal_handler_appraisal_cycle_type extends views_handler_field {

  function render($values) {
    $value = $this->get_value($values);
    return get_appraisal_cycle_type($value);
  }
}
