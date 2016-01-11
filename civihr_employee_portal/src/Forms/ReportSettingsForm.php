<?php
/**
 * Created by PhpStorm.
 * User: gergelymeszaros
 * Date: 14/09/15
 * Time: 16:23
 */

namespace Drupal\civihr_employee_portal\Forms;

trait modalCallback {
    public function initModal($ajax, $modalTitle = '') {
        if ($ajax) {
            ctools_include('ajax');
            ctools_include('modal');

            //$title = t('CiviHR Report settings form');

            $form_state = array(
                'ajax' => TRUE,
                'is_ajax_update' => TRUE,
                'title' => $modalTitle,
            );

            // Pass the custom form object data
            $form_state['build_info']['args'] = array(array('form_object' => $this));

            // Use ctools to generate ajax instructions for the browser to create a form in a modal popup.
            $output = ctools_modal_form_wrapper($this->getFormName(), $form_state);

            // If the form has been submitted, there may be additional instructions such as dismissing the modal popup.
            if (!empty($form_state['executed'])) {

                // Add the responder javascript, required by ctools
                ctools_add_js('ajax-responder');

                $output[] = ctools_modal_command_dismiss();
                $output[] = ajax_command_remove('#messages');
                $output[] = ajax_command_after('#breadcrumb', '<div id="messages">' . theme('status_messages') . '</div>');

                // If we need to redirect
                $output[] = ctools_ajax_command_redirect($this->getReportType());

            }

            // Return the ajax instructions to the browser via ajax_render().
            print ajax_render($output);
            drupal_exit();

        }
        else {

            // Returns default form (no AJAX support OR mobile view)
            return drupal_get_form($this->getFormName(), array('form_object' => $this));
        }
    }
}

class ReportSettingsForm extends BaseForm {

    // Use the defined traits
    // This will try to load the form as modal window, if no ajax support it will fallback to default form
    use modalCallback;

    // This will hold the form data
    public $form_data = array();
    public $y_axis_filter_types = array();

    /**
     * Constructor
     *
     * @param string form_name
     */
    public function __construct($form_name, $report_type) {
        BaseForm::__construct($form_name, $report_type);

        // This will initialise form fields
        // Created in child classes which should extend the base class
        $this->setForm();
    }

    /**
     * Sets default Y axis filter types
     */
    public function setYAxisFilterTypes($additional_filters = array()) {

        $filters = array(
            'fte' => t('FTE'),
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
     * Returns the Y Axis filter types default values or empty array
     */
    public function getYAxisFilterTypesDefaults() {
        return variable_get($this->getReportType() . '_enabled_y_axis_filters', array());
    }

    /**
     * Sets default X axis filter types
     */
    public function setXAxisFilterTypes($additional_filters = array()) {

        $filters = array(
            'all' => t('All'),
            'location' => t('Location'),
            'department' => t('Department'),
            'level' => t('Level')
        );

        // This function allows to add any new X Axis types if needed and passed to the function properly
        $this->x_axis_filter_types = array_merge($filters, $additional_filters);
    }

    /**
     * Returns the X Axis filter types
     * @return array
     */
    public function getXAxisFilterTypes() {
        return $this->x_axis_filter_types;
    }

    /**
     * Returns the X Axis filter types default values or empty array
     */
    public function getXAxisFilterTypesDefaults($type = 'all') {
        return variable_get($this->getReportType() . '_enabled_x_axis_filters_' . $type, array());
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

        // Sets the Y Axis group types
        // Optionally can pass new Y Axis filter type for example: $this->setYAxisFilterTypes(array('headcount2' => 'new headcount filter type'));
        $this->setYAxisFilterTypes();

        // Sets the X Axis group types
        // Optionally can pass new X Axis type same as for Y Axis groupings
        $this->setXAxisFilterTypes();

        $this->form_data['modal_body_open'] = array(
            '#markup' => '<div class="modal-body">'
        );

        $this->form_data['enabled_y_axis_filters'] = array(
            '#type' => 'checkboxes',
            '#title' => t('Y Axis Group By options'),
            '#description' => t('Select Y Axis Group By options'),
            '#options' => $this->getYAxisFilterTypes(),
            '#default_value' => $this->getYAxisFilterTypesDefaults(),
        );

        foreach ($this->getYAxisFilterTypes() as $key => $value) {
            $this->form_data['enabled_x_axis_filters_' . $key] = array(
                '#type' => 'checkboxes',
                '#options' => $this->getXAxisFilterTypes(),
                '#default_value' => $this->getXAxisFilterTypesDefaults($key),
                '#title' => t('X Axis Group By settings for ' . $key . '!'),
                '#states' => array(
                    'visible' => array(
                        ':input[name="enabled_y_axis_filters[' . $key . ']"]' => array('checked' => TRUE),
                    ),
                ),
            );
        }

        $this->form_data['age_group_vals'] = array(
            '#type' => 'hidden',
            '#title' => $this->getFormName(),
            '#default_value' => $this->getRawAgeGroups(),
            '#maxlength' => 1024,
            '#suffix' => '<div id="table">
                <span class="table-add glyphicon glyphicon-plus"></span>
                <table class="table table-striped table-editable">
                    <thead>
                        <tr>
                          <th id="description">Description</th>
                          <th id="start_period">Start Age</th>
                          <th id="end_period">End Age</th>
                          <th></th>
                          <th></th>
                        </tr>
                    </thead>
                    <tbody>'
                        . $this->getAgeGroupsHTML() .
                        '<!-- This is our clonable table line -->
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
                    </tbody>
              </table>
            </div>'
        );

        $this->form_data['modal_body_close'] = array(
            '#markup' => '</div>'
        );

        $this->form_data['submit'] = array(
            '#type' => 'submit',
            '#value' => t('Save settings!'),
            '#prefix' => '<div class="modal-footer">',
            '#suffix' => '</div>',
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

            // Saves the enabled Y Axis group by settings
            variable_set($this->getReportType() . '_enabled_y_axis_filters', $form_state['values']['enabled_y_axis_filters']);

            // Saves the X Axis group by settings
            foreach ($this->getYAxisFilterTypes() as $key => $value) {
                variable_set($this->getReportType() . '_enabled_x_axis_filters_' . $key, $form_state['values']['enabled_x_axis_filters_' . $key]);
            }

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
