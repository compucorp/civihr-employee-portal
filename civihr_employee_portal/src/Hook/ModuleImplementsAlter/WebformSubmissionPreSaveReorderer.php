<?php

namespace Drupal\civihr_employee_portal\Hook\ModuleImplementsAlter;

class WebformSubmissionPreSaveReorderer extends ImplementationAlterer {

  /**
   * @inheritdoc
   */
  public function shouldAlter($hookName) {
    return $hookName === 'webform_submission_presave';
  }

  /**
   * @inheritdoc
   */
  public function alter(array &$implementations) {
    $this->moveToEnd($implementations, 'civihr_employee_portal');
  }

}
