<?php


use Drupal\civihr_employee_portal\Hook\ModuleImplementsAlter\WebformSubmissionPreSaveReorderer;

class WebformSubmissionPreSaveReordererTest extends \PHPUnit_Framework_TestCase {

  public function testAlterWillPutCiviHREmployeePortalToEnd() {
    $reorderer = new WebformSubmissionPreSaveReorderer();
    $implementations = [
      'yet_another_module' => FALSE,
      'civihr_employee_portal' => FALSE,
      'some_other_module' => FALSE,
      'another_module' => FALSE,
    ];
    $reorderer->alter($implementations);
    $lastEntry = end(array_keys($implementations));
    $this->assertEquals('civihr_employee_portal', $lastEntry);
  }

  public function testAlterWillThrowExceptionIfModuleNotSet() {
    $reorderer = new WebformSubmissionPreSaveReorderer();
    $implementations = [
      'yet_another_module' => FALSE,
    ];
    $this->setExpectedException(
      \RuntimeException::class,
      'Cannot re-order as module "civihr_employee_portal" is not set'
    );
    $reorderer->alter($implementations);
  }

  public function testShouldAlterWillBeTrueForTargetHook() {
    $reorderer = new WebformSubmissionPreSaveReorderer();
    $hook = 'webform_submission_presave';

    $this->assertTrue($reorderer->shouldAlter($hook));
  }

  public function testShouldAlterWillBeFalseForAnotherHook() {
    $reorderer = new WebformSubmissionPreSaveReorderer();
    $hook = 'some_other_hook';

    $this->assertFalse($reorderer->shouldAlter($hook));
  }
}
