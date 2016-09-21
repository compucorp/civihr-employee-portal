<?php

/**
 * Argument handler for matching CiviCRM user ID by provided Drupal UID value.
 *
 * @ingroup views_argument_handlers
 */
class civihr_employee_portal_argument_contact_id extends views_handler_argument {

  function query($group_by = FALSE) {
    $this->ensure_my_table();
    $contact_match = get_civihr_uf_match_data($this->argument);
    $this->query->add_where(0, "{$this->table_alias}.{$this->real_field}", $contact_match['contact_id'], "=");
  } 
}
