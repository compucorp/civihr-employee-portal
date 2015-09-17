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

    public function setForm() {
        $this->form_data['main_filter'] = array(
            '#type' => 'textfield',
            '#title' => 'sss Filters for Y axis?' . $this->getFormName(),
            '#size' => 10,
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
    public function validateForm($form, &$form_state) {


        form_set_error('main_filter', t('New error from class'));

        // No errors found
        return TRUE;

    }


}