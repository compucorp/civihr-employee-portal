<?php

/** @file
 *  HTML field handler for absence_period label and date values.
 */
class civihr_employee_portal_handler_absence_period extends views_handler_field {

  function render($values) {
    $civi_date_periods = get_civihr_date_periods();
    $filter_values = array();

    foreach ($civi_date_periods as $civi_date_period) {
      if ($civi_date_period['id'] == $values->absence_entitlement_period_id) {
        if (isset($this->options['absence_period_settings'])) {
          if ($this->options['absence_period_settings'] == 'entitlement_label') {
            return '<div class="entitlement-label">' . t('Entitlement:') . '</div>';
          }
          if ($this->options['absence_period_settings'] == 'entitlement_date') {
            return '<div class="entitlement-date">' . $civi_date_period['title'] . '</div>';
          }
        } else {
          return '';
        }
      }
    }

    // No match leave the field empty (empty columns will be hidden by views)
    return '';
  }

  function option_definition() {
    $options = parent::option_definition();

    // Define our custom settings fields
    $options['absence_period_settings'] = array();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $options = array();
    $options['entitlement_label'] = t('Show Entitlement Label');
    $options['entitlement_date'] = t('Show Entitlement Date');

    $form['absence_period_settings'] = array(
      '#type' => 'select',
      '#title' => t('Absence period settings'),
      '#options' => $options,
      '#default_value' => isset($this->options['absence_period_settings']) ? $this->options['absence_period_settings'] : '',
      '#required' => TRUE
    );

    parent::options_form($form, $form_state);
  }

  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);

    // Update our custom values
    $this->options['absence_period_settings'] = $form_state['values']['options']['absence_period_settings'];
  }
}
