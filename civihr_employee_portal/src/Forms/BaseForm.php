<?php
/**
 * Created by PhpStorm.
 * User: gergelymeszaros
 * Date: 14/09/15
 * Time: 16:12
 */

namespace Drupal\civihr_employee_portal\Forms;

class BaseForm {

    // The constructur will use one string value which will create machine name for this form
    public $formName;

    // This is static, needs to be changed if for some reason the main drupal module is renamed
    public $moduleName = 'civihr_employee_portal';

    // Set our class names what we want use
    public $classRegister = [   'civihr_reports' => 'ReportSettingsForm',
////                                'civihr_reports_monthly' => 'ReportMonthlyForm',
                                'civihr_reports_absence' => 'ReportAbsenceForm',
    ];

    /**
     * Constructor
     *
     * @param string form_name
     */
    public function __construct($form_name, $report_type) {
        $this->formName = $this->moduleName . '_' . $form_name;
        $this->reportType = $report_type;
    }

    public function getFormName() {
        return $this->formName;
    }

    /**
     * @return string
     * Returns the report main type
     * For example civihr_reports or civihr_reports_monthly
     */
    public function getReportType() {
        return $this->reportType;
    }

    public function getClassName($report_type) {
        return $this->classRegister[$report_type];
    }

}