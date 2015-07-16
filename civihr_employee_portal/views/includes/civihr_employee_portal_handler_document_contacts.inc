<?php
/**
 * @file
 * Base field handler for views_json_query.
 */

class civihr_employee_portal_handler_document_contacts extends views_json_query_handler_field {
  /**
   * Render.
   */
  function render($values) {

      $key = $this->field_alias;

      // Get the contact ID from array
      $id = array_shift($values->$key);

      // Get the contact data based on the contact ID
      $contact_data = get_civihr_contact_data($id);

      // Pass the display name to the render_field
      return $this->render_field($contact_data['display_name']);

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
