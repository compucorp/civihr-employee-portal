
<?php

/**
 * Class civihr_employee_portal_argument_date_range
 * Custom argument handler for period date range
 */

class civihr_employee_portal_argument_date_range extends views_handler_argument {

    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);

        $form['civihr_range'] = array(
            '#type' => 'textfield',
            '#title' => t('CiviHR date filter type'),
            '#size' => 20,
            '#default_value' => isset($this->options['civihr_range']) ? $this->options['civihr_range'] : '=',
            '#description' => t('Date argument filter settings'),
        );

    }

    function options_submit(&$form, &$form_state) {
        parent::options_submit($form, $form_state);

        // Update our custom range settings
        $this->options['civihr_range'] = $form_state['values']['options']['civihr_range'];

    }

    /**
     * Set up the query for this argument.
     *
     * The argument sent may be found at $this->argument.
     */
    function query($group_by = FALSE) {
        $this->ensure_my_table();

        // @ we will need to have a validation to allow saving only (<=, >=, =)
        $operator = isset($this->options['civihr_range']) ? $this->options['civihr_range'] : '=';

        watchdog('arg', print_r($this->argument, TRUE));
        watchdog('this options', print_r($operator, TRUE));

        // modified row with optional operator value
        $this->query->add_where(0, "$this->table_alias.$this->real_field", $this->argument, $operator);

    }

}