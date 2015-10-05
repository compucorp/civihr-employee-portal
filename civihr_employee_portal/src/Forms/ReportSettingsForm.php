<?php
/**
 * Created by PhpStorm.
 * User: gergelymeszaros
 * Date: 14/09/15
 * Time: 16:23
 */

namespace Drupal\civihr_employee_portal\Forms;

class ReportSettingsForm extends BaseForm {

    // This will hold the form data
    private $form_data = array();
    private $y_axis_filter_types = array();

    /**
     * Sets default Y axis filter types
     */
    public function setYAxisFilterTypes($additional_filters = array()) {

        $filters = array(
            'headcount' => t('Headcount'),
            'gender' => t('Gender'),
            'age' => t('Age')
        );

        // This function allows to add any new Y Axis types if needed and passed to the function properly
        $this->y_axis_filter_types = array_merge($filters, $additional_filters);
    }

    /**
     * Returns the Y Axis filter types
     * @return array
     */
    public function getYAxisFilterTypes() {
        return $this->y_axis_filter_types;
    }

    /**
     * Returns defined age groups (json stringified values)
     * @return null
     */
    public function getRawAgeGroups() {
        return variable_get('age_group_vals', []);
    }

    /**
     * Returns the defined age groups (if any)
     */
    public function getAgeGroupsHTML() {

        $html = '';

        // Decode string as associative array
        foreach (json_decode($this->getRawAgeGroups(), TRUE) as $age_group) {
            $html .= '<tr>';
            $html .= '<td class="changeable" contenteditable="true">' . $age_group['description'] . '</td>';
            $html .= '<td class="changeable" contenteditable="true">' . $age_group['start_period'] . '</td>';
            $html .= '<td class="changeable" contenteditable="true">' . $age_group['end_period'] . '</td>';
            $html .= '<td><span class="table-remove glyphicon glyphicon-remove"></span></td>';
            $html .= '<td><span class="table-up glyphicon glyphicon-arrow-up"></span><span class="table-down glyphicon glyphicon-arrow-down"></span></td>';
            $html .= '</tr>';
        }

        return $html;

    }

    public function setForm() {

        // Sets the Y Axis filter types
        // Optionally can pass new Y Axis filter type for example: $this->setYAxisFilterTypes(array('headcount2' => 'new headcount filter type'));
        $this->setYAxisFilterTypes();

        $this->form_data['enabled_y_axis_filters'] = array(
            '#type' => 'checkboxes',
            '#title' => t('Y Axis Filters'),
            '#description' => t('Select Y Axis Group By options'),
            '#options' => $this->getYAxisFilterTypes(),
            '#default_value' => array_keys(variable_get('enabled_y_axis_filters', array()))
        );

        $this->form_data['age_group_vals'] = array(
            '#type' => 'hidden',
            '#title' => $this->getFormName(),
            '#default_value' => $this->getRawAgeGroups(),
            '#maxlength' => 1024,
            '#suffix' => '<div class="container">

                              <div id="table">
                                <span class="table-add glyphicon glyphicon-plus"></span>
                                <table class="table-editable">
                                  <tr>
                                    <th id="description">Description</th>
                                    <th id="start_period">Start Age</th>
                                    <th id="end_period">End Age</th>
                                    <th></th>
                                    <th></th>
                                  </tr>

                                    ' . $this->getAgeGroupsHTML() . '

                                  <!-- This is our clonable table line -->
                                  <tr class="hide">
                                    <td class="changeable" contenteditable="true">0 - 99</td>
                                    <td class="changeable" contenteditable="true">0</td>
                                    <td class="changeable" contenteditable="true">99</td>
                                    <td>
                                      <span class="table-remove glyphicon glyphicon-remove"></span>
                                    </td>
                                    <td>
                                      <span class="table-up glyphicon glyphicon-arrow-up"></span>
                                      <span class="table-down glyphicon glyphicon-arrow-down"></span>
                                    </td>
                                  </tr>
                                </table>
                              </div>
                        </div>'
        );

        $this->form_data['submit'] = array(
            '#type' => 'submit',
            '#value' => t('Save settings!'),
        );

        $this->form_data['#validate'][] = 'civihr_employee_portal_report_settings_form_validate';
        $this->form_data['#submit'][] = "civihr_employee_portal_report_settings_form_submit";
    }

    /**
     * Function to return the whole initialised form
     * @return array
     */
    public function getForm() {
        return $this->form_data;
    }

    /**
     *
     * Function to validate our form data
     * @param $form
     * @param $form_state
     * @return bool
     */
    public function validateForm($form, &$form_state, $object) {

        watchdog('form state', print_r($form_state['values'], TRUE));

        // Pass the custom form object data (if it's not passed we can't see our object in the submit phase)
        $form_state['build_info']['args'] = array(array('form_object' => $object));

        if (isset($form_state['values']['age_group_vals'])) {

            if (empty($form_state['values']['age_group_vals']) || $form_state['values']['age_group_vals'] == '[]') {
                form_set_error('main_filter', t('Age Groups cannot be empty!'));
            }

            // All validation passed
            return TRUE;
        }

        // Error found
        return FALSE;

    }

    /**
     * Function to save our form data
     * @param $form
     * @param $form_state
     */
    public function submitForm($form, &$form_state) {

        watchdog('new submit', print_r($form_state['values'], TRUE));

        if (isset($form_state['values']['enabled_y_axis_filters'])) {
            // Saves the enabled Y Axis filters
            variable_set('enabled_y_axis_filters', $form_state['values']['enabled_y_axis_filters']);
        }

        if (isset($form_state['values']['age_group_vals'])) {
            // Saves the age group settings
            variable_set('age_group_vals', $form_state['values']['age_group_vals']);
        }

        drupal_set_message(t('Settings Saved!'), 'success');

        // If no ajax trigger redirect (otherwise the form will redirect after ajax finished
        if (!isset($form_state['ajax'])) {
            drupal_goto('civihr_reports');
        }

    }

}