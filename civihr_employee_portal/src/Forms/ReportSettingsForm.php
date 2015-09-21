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
            '#suffix' => '<div class="container">

  <div id="table">
    <span class="table-add glyphicon glyphicon-plus"></span>
    <table class="table-editable">
      <tr>
        <th>Description</th>
        <th>Start Age</th>
        <th>End Age</th>
        <th></th>
        <th></th>
      </tr>
      <tr>
        <td class="changeable" contenteditable="true">desc</td>
        <td class="changeable" contenteditable="true">start</td>
        <td class="changeable" contenteditable="true">end</td>
        <td>
          <span class="table-remove glyphicon glyphicon-remove"></span>
        </td>
        <td>
          <span class="table-up glyphicon glyphicon-arrow-up"></span>
          <span class="table-down glyphicon glyphicon-arrow-down"></span>
        </td>
      </tr>
      <!-- This is our clonable table line -->
      <tr class="hide">
        <td class="changeable" contenteditable="true">Untitled</td>
        <td class="changeable" contenteditable="true">undefined</td>
        <td class="changeable" contenteditable="true">undefined</td>
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
    public function validateForm($form, &$form_state) {


        watchdog('values passed', print_r($form_state, TRUE));

        form_set_error('main_filter', t('New error from class'));

        // No errors found
        return TRUE;

    }


}