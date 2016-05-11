<?php
/**
 * @file
 * A filter similar to separate filters for start and end date, but exposed in
 * a single field.
 */

class views_between_dates_filter_handler extends date_views_filter_handler_simple {
  function init(&$view, &$options) {

    parent::init($view, $options);
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['start_date_field'] = array('default' => NULL);
    $options['end_date_field'] = array('default' => NULL);
    return $options;
  }

  function operators() {
    $operators = array(
      // Re-using = and != operators to pass date_views_filter_handler_simple::value_validate tests
      // No reason to write new functions at this time.
      '=' => array(
        'title' => t('Is between date fields'),
        'method' => 'op_between_dates',
        'short' => t('between_dates'),
        'values' => 1,
      ),
      '!=' => array(
        'title' => t('Is NOT between date fields'),
        'method' => 'op_between_dates',
        'short' => t('not_between_dates'),
        'values' => 1,
      ),
    );
    return $operators;
  }

  function op_between_dates($field) {
    $this->get_query_fields();
    if (empty($this->query_fields)) {
      return;
    }
    $field_names = array();
    foreach ((array) $this->query_fields as $query_field) {
      $field = $query_field['field'];
      $this->date_handler = $query_field['date_handler'];
      // Respect relationships when determining the table alias.
      if ($field['table_name'] != $this->table || !empty($this->relationship)) {
        $this->related_table_alias = $this->query->ensure_table($field['table_name'], $this->relationship);
      }
      $table_alias = !empty($this->related_table_alias) ? $this->related_table_alias : $field['table_name'];

      // TODO: Research adding delta field code from parent:op_simple here.
      $field_name = $table_alias . '.' . $field['field_name'];
      $field_names[] = $field_name;
    }
    // SQL: start date <= value AND end date >= value.
    // If data is correct.
    if (count($field_names) == 2) {
      $value = $this->get_filter_value('value', $this->value['value']);
      $comp_date = new DateObject($value, date_default_timezone(), $this->format);

      $start_field = $this->date_handler->sql_field($field_names[0], NULL, $comp_date);
      $start_field = $this->date_handler->sql_format($this->format, $start_field);
      $end_field = $this->date_handler->sql_field($field_names[1], NULL, $comp_date);
      $end_field = $this->date_handler->sql_format($this->format, $end_field);
      $placeholder = $this->placeholder();
      $group = !empty($this->options['date_group']) ? $this->options['date_group'] : $this->options['group'];
      if ($this->operator == '=') {
        $this->query->add_where_expression($group, "$start_field <= $placeholder AND $end_field >= $placeholder", array($placeholder => $value));
      }
      // Else not between
      else {
        $this->query->add_where_expression($group, "$start_field > $placeholder OR $end_field < $placeholder", array($placeholder => $value));
      }
   }

  }

  function extra_options_form(&$form, &$form_state) {
    parent::extra_options_form($form, $form_state);

    $fields = date_views_fields($this->base_table);
    $options = array();
    foreach ($fields['name'] as $name => $field) {
      $options[$name] = $field['label'];
    }

    $form['start_date_field'] = array(
      '#title' => t('Start date field'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $this->options['start_date_field'],
      '#description' => t('Select start date field.'),
      '#required' => TRUE,
    );
    $form['end_date_field'] = array(
      '#title' => t('End date field'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $this->options['end_date_field'],
      '#description' => t('Select end date field.'),
      '#required' => TRUE,
    );
  }

  function extra_options_validate($form, &$form_state) {
    if (empty($form_state['values']['options']['start_date_field'])) {
      form_error($form['start_date_field'], t('You must select a start date field for this filter.'));
    }
    if (empty($form_state['values']['options']['end_date_field'])) {
      form_error($form['end_date_field'], t('You must select an end date field for this filter.'));
    }
  }

  // Update the summary values to provide
  // meaningful information for each option.
  function admin_summary() {
    if (empty($this->options['start_date_field']) || empty($this->options['end_date_field'])) {
      return t('Missing date fields!');
    }
    $handler = $this->date_handler;

    $fields = date_views_fields($this->view->base_table);

    $start_field = $this->options['start_date_field'];
    $end_field = $this->options['end_date_field'];
    if (array_key_exists($start_field, $fields['name']) && array_key_exists($end_field, $fields['name'])) {
      $start = $fields['name'][$start_field]['label'];
      $end = $fields['name'][$end_field]['label'];

      $widget_options = $this->widget_options();
      // If the filter is exposed, display the granularity.
      if ($this->options['exposed']) {
        return t('(@start - @end) <strong>Exposed</strong> @format',
          array('@start' => $start, '@end' => $end, '@format' => $handler->granularity));
      }
      // If not exposed, display the value.
      $value = check_plain(!empty($this->options['default_date']) ? $this->options['default_date'] : $this->options['value']['value']);
      if ($this->operator == '=') {
        return t('(@start <= @value >= @end)', array('@start' => $start, '@value' => $value, '@end' => $end));
      }
      else {
        return t('(@start > @value < @end)', array('@start' => $start, '@value' => $value, '@end' => $end));
      }
    }
    return;
  }

  function get_query_fields() {
    $fields = date_views_fields($this->base_table);
    $fields = $fields['name'];
    $this->query_fields = array();
    $date_fields = array($this->options['start_date_field'], $this->options['end_date_field']);

    foreach ($date_fields as $delta => $name) {
      if (array_key_exists($name, $fields) && $field = $fields[$name]) {
        $date_handler = new date_sql_handler($field['sql_type'], date_default_timezone());
        $date_handler->granularity = $this->options['granularity'];
        $date_handler->db_timezone = date_get_timezone_db($field['tz_handling']);
        $date_handler->local_timezone = date_get_timezone($field['tz_handling']);
        $operator = ($delta == 0) ? '<=' : '>=';
        $this->query_fields[] = array(
          'field' => $field,
          'date_handler' => $date_handler,
        );
      }
    }
  }
}
