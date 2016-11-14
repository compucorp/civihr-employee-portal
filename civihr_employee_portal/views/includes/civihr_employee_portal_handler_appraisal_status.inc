
<?php

/**
 * Custom views handler field to display the Appraisal status
 */
class civihr_employee_portal_handler_appraisal_status extends views_handler_field {

  function render($values) {
    $value = $this->get_value($values);
    return get_appraisal_status($value);
  }
}
