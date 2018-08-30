<?php

use Drupal\civihr_employee_portal\Helpers\LoggingStreamSwitcher;

class LoggingStreamSwitcherTest extends \PHPUnit_Framework_TestCase {

  public function testSwitchingOnWillChangeGlobalVariable() {
    LoggingStreamSwitcher::enableLogging('foo');
    global $civihrChangeLogStreams;

    $this->assertTrue($civihrChangeLogStreams['foo']);
  }

  public function testDisablingWillSetGlobalVariableToFalse() {
    LoggingStreamSwitcher::disableLogging('foo');
    global $civihrChangeLogStreams;

    $this->assertFalse($civihrChangeLogStreams['foo']);
  }

  public function testSwitchingWillChangeGlobalVariable() {
    LoggingStreamSwitcher::enableLogging('foo');
    LoggingStreamSwitcher::disableLogging('foo');
    global $civihrChangeLogStreams;

    $this->assertFalse($civihrChangeLogStreams['foo']);
  }
}
