<?php
/**
 * @file
 * Base field handler for views_json_query.
 */

class civihr_employee_portal_handler_document_contacts extends views_handler_field {
  /**
   * Render.
   */
  function render($values) {
      
    $key = $this->field_alias;

    if (isset($key) && !empty($key)) {
        return ',' . implode(',', $values->$key) . ',';
    }

    return '';
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
