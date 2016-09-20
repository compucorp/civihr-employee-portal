<?php

/**
 * @file
 * Base field handler for absence_entitlement value.
 */
class civihr_employee_portal_handler_absence_entitlement extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  function render($values) {
    $key = $this->field_alias;

    if (!isset($values->$key)) {
      return '';
    }

    $values = $values->$key;

    // Get the absence types
    $absenceTypes = get_civihr_absence_types();

    foreach ($absenceTypes as $absenceType) {

      if (isset($absenceType['id']) && $absenceType['id'] == $this->options['duration_type']) {

        $value_explode = explode("||", $values);

        $absence_ids = explode("@@", $value_explode[1]);
        $absence_values = explode("@@", $value_explode[0]);

        foreach ($absence_ids as $absence_array_key => $absence_id) {
          if ($absence_id == $absenceType['id']) {

            return '+ ' . $absence_values[$absence_array_key];
          }
        }
      }
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
   * Option definition.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['key'] = array('default' => '');
    $options['duration_type'] = array('default' => '');

    return $options;
  }

  /**
   * Options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['key'] = array(
      '#title' => t('Key Chooser'),
      '#description' => t('choose a key'),
      '#type' => 'textfield',
      '#default_value' => $this->options['key'],
      '#required' => TRUE,
    );

    // Get the absence types
    $absenceTypes = get_civihr_absence_types();

    foreach ($absenceTypes as $absenceType) {

      /**
       * Check if the absence type is active, if active populate in the options list
       */
      if (isset($absenceType['is_active']) && $absenceType['is_active'] == '1') {

        $options[$absenceType['id']] = $absenceType['title'];
      }
    }

    $form['duration_type'] = array(
      '#type' => 'select',
      '#title' => t('Absence type'),
      '#options' => $options,
      '#default_value' => isset($this->options['duration_type']) ? $this->options['duration_type'] : '',
      '#required' => TRUE
    );
  }

  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);

    // Update our custom values
    $this->options['duration_type'] = $form_state['values']['options']['duration_type'];
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    // Add the field.
    $this->table_alias = 'absence_entitlement';

    $this->field_alias = $this->query->add_field(
            $this->table_alias, $this->options['key'], '', $this->options
    );
  }

  /**
   * UI name.
   */
  function ui_name($short = FALSE) {
    if (!empty($this->options['ui_name'])) {
      $title = check_plain($this->options['ui_name']);
      return $title;
    }
    $title = $this->definition['title'];

    if ($short && isset($this->definition['title short'])) {
      $title = $this->definition['title short'];
    }

    return t('!key: !title', array(
      '!key' => $this->options['key'],
      '!title' => $title,
    ));
  }

  /**
   * Called to determine what to tell the clicksorter.
   */
  function click_sort($order) {
    if (isset($this->field_alias)) {
      $this->query->add_orderby(NULL, $this->field_alias, $order);
    }
  }

}
