<?php
/**
 * Created by PhpStorm.
 * User: gergelymeszaros
 * Date: 17/12/2015
 * Time: 18:20
 */

namespace Drupal\civihr_employee_portal\Forms;

class ReportAbsenceForm extends ReportSettingsForm {

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
            'days_taken' => t('Days Taken'),
            'no_employees' => t('NO. Employees'),
            'avg_duration' => t('AVG. Duration')
        );

        // This function allows to add any new Y Axis types if needed and passed to the function properly
        $this->y_axis_filter_types = array_merge($filters, $additional_filters);
    }

}