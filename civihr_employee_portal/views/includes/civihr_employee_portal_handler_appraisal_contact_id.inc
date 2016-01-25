<?php
/**
 * @file
 * Base field handler for views_json_query.
 */

class civihr_employee_portal_handler_appraisal_contact_id extends views_json_query_handler_field {
  /**
   * Render.
   */
  function render($values) {

      $key = $this->field_alias;

      // Get the contact ID from array
      $id = array_shift($values->$key);
      
      return $id;
  }

  /**
   * Renders field.
   */
  function render_field($value) {

    return check_plain($value);
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    // Add the field.
    $this->table_alias = 'json';

    $this->field_alias = $this->query->add_field(
      $this->table_alias,
      $this->options['key'],
      '',
      $this->options
    );
  }
}
