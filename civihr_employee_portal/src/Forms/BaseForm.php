<?php
/**
 * Created by PhpStorm.
 * User: gergelymeszaros
 * Date: 14/09/15
 * Time: 16:12
 */

namespace Drupal\civihr_employee_portal\Forms;

trait modalCallback {
    public function initModal($ajax, $modalTitle = '', $redirect = '') {
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
                //$output[] = ctools_ajax_command_redirect($redirect);

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

class BaseForm {

    // Use the defined traits
    // This will try to load the form as modal window, if no ajax support it will fallback to default form
    use modalCallback;

    // The constructur will use one string value which will create machine name for this form
    public $formName;

    // This is static, needs to be changed if for some reason the main drupal module is renamed
    public $moduleName = 'civihr_employee_portal';

    /**
     * Constructor
     *
     * @param string form_name
     */
    public function __construct($form_name) {
        $this->formName = $this->moduleName . '_' . $form_name;

        // This will initialise form fields
        $this->setForm();
    }

    public function getFormName() {
        return $this->formName;
    }

}