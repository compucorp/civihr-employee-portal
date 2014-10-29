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
class views_json_query_handler_argument_query_string extends views_handler_argument {

  /**
   * {@inheritdoc}
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['name'] = array('default' => '');
    $options['use_from_request'] = array('default' => '');
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#default_value' => $this->options['name'],
      '#description' => t('The name of the query string parameter, as used in the JSON file URI.'),
      '#required' => TRUE,
    );
    $form['use_from_request'] = array(
      '#type' => 'select',
      '#title' => t('Use value from dynamic request'),
      '#default_value' => $this->options['use_from_request'],
      '#options' => array('yes' => 'Yes', 'no' => 'No'),
      '#description' => t('Filter by the passed field key (from $_REQUEST).'),
      '#required' => TRUE,
    );
  }
  
  function options_submit(&$form, &$form_state) {
        parent::options_submit($form, $form_state);
        
        // Update our custom values
        $this->options['use_from_request'] = $form_state['values']['options']['use_from_request'];
        
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
    
    // watchdog('this options sub', print_r($this->options, TRUE));
    // watchdog('request test sub', print_r($_REQUEST, TRUE));
    // watchdog('this options 2 sub', print_r($this->argument, TRUE));
    // watchdog('this options3 sub', print_r($this->value, TRUE));
    // watchdog('req test', print_r($_REQUEST, TRUE));
    
    if ($this->options['use_from_request'] == 'yes') {
    
        $request_date = '';
    
        if (isset($_REQUEST['absence_start_date_period_filter'])) {
            $request_date = $_REQUEST['absence_start_date_period_filter'];
        }
        else {
            // Set default period
            $request_date = '1';
        }

        if ($this->options['name'] == 'period_id' && $request_date != '') {

            $operator = '=';
            $key = 'period_id';
            $value = $request_date;

            // Filter by requests
            return array($key, $operator, $value);
        }
    }
    
    $operator = '=';
    $key = $this->options['name'];
    $value = $this->argument;

    return array($key, $operator, $value);
    
    
  }
  
}
