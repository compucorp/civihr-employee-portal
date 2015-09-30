<?php

/**
 * @file
 * Definition of views_handler_argument_null.
 */

/**
 * Argument handler for query string parameter in a JSON file URL.
 *
 * @ingroup views_argument_handlers
 */
class views_json_query_argument_task_contacts_request_handler extends views_handler_argument {

  /**
   * {@inheritdoc}
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['name'] = array('default' => '');
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

      $form['name'] = array(
          '#type' => 'textfield',
          '#title' => t('JSON key'),
          '#default_value' => $this->options['name'],
          '#description' => t('The key in the JSON file to use for the filter.'),
          '#required' => TRUE,
      );
  }
  
  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
   }

  /**
   * {@inheritdoc}
   */
  function default_actions($which = NULL) {
    $keys = array('ignore', 'not found', 'default', 'access denied');
    if ($which) {
      if (in_array($which, $keys)) {
        return parent::default_actions($which);
      }
      return;
    }
    $actions = parent::default_actions();
    foreach (array_keys($actions) as $key) {
      if (!in_array($key, $keys)) {
        unset($actions[$key]);
      }
    }
    return $actions;
  }

  function validate_argument_basic($arg) {
    return parent::validate_argument_basic($arg);
  }

  /**
   * {@inheritdoc}
   
  function query($group_by = FALSE) {
    $this->query->add_filter($this);
  }
   * 
   */
  
  /**
   * Generate a query from all of the information supplied to the object.
   *
   * @param $get_count
   *   Provide a countquery if this is true, otherwise provide a normal query.
   */
  function query($get_count = FALSE) {
    
    // Add the filters
    $this->query->add_filter($this);
  }
  
  /**
   * Generate.
   */
  function generate() {

    // Use the array_contains new filter type
    $operator = 'array_contains';

    // Get the column key which we want to filter
    $key = $this->options['name'];

    // Get the contact match data from UID
    $contact_match = get_civihr_uf_match_data($this->argument);

    // $key -> the key(column) in json which we will filter
    // $operator -> used for filter
    // $contact_match['contact_id'] -> data what we are looking for
    return array($key, $operator, $contact_match['contact_id']);
  }
  
}
