<?php

/**
 * @file
 * Definition of civihr_employee_portal_filter_absence_period.
 */

/**
 * Extends views_handler_filter_date and sets the default group option values based on CiviCRM date periods
 *
 * @ingroup views_filter_handlers
 */
class civihr_employee_portal_filter_absence_period extends views_handler_filter_date {
    
  /**
   * Build a form containing a group of operator | values to apply as a
   * single filter.
   */
  function group_form(&$form, &$form_state) {
    if (!empty($this->options['group_info']['optional']) && !$this->multiple_exposed_input()) {

      $old_any = $this->options['group_info']['widget'] == 'select' ? '<Any>' : '&lt;Any&gt;';
      $any_label = variable_get('views_exposed_filter_any_label', 'new_any') == 'old_any' ? $old_any : t('- Any -');
      $groups = array('All' => $any_label);
    }
    
    // Get civi defined date periods
    $civi_date_periods = get_civihr_date_periods();
        
    $filter_values = array();
        
    foreach ($civi_date_periods as $civi_date_period) {
            
        $filter_values[$civi_date_period['id']] = array('title' => $civi_date_period['title'], 'operator' => 'between', 'value' => array('type' => 'date', 'value' => '', 'min' => $civi_date_period['start_date'], 'max' => $civi_date_period['end_date']));
            
    }
    
    // Force rewrite default values (from CIVIcrm)
    $this->options['group_info']['group_items'] = $filter_values;
    
    foreach ($this->options['group_info']['group_items'] as $id => $group) {
      if (!empty($group['title'])) {
        $groups[$id] = $id != 'All' ? t($group['title']) : $group['title'];
      }
    }

    if (count($groups)) {
      $value = $this->options['group_info']['identifier'];

      $form[$value] = array(
        '#type' => $this->options['group_info']['widget'],
        '#default_value' => $this->group_info,
        '#options' => $groups,
      );
      if (!empty($this->options['group_info']['multiple'])) {
        if (count($groups) < 5) {
          $form[$value]['#type'] = 'checkboxes';
        }
        else {
          $form[$value]['#type'] = 'select';
          $form[$value]['#size'] = 5;
          $form[$value]['#multiple'] = TRUE;
        }
        unset($form[$value]['#default_value']);
        if (empty($form_state['input'])) {
          $form_state['input'][$value] = $this->group_info;
        }
      }

      $this->options['expose']['label'] = '';
    }
  }
    
}