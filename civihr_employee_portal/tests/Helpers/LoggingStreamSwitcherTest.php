<?php

use Drupal\civihr_employee_portal\Helpers\LoggingStreamSwitcher;

class LoggingStreamSwitcherTest extends \PHPUnit_Framework_TestCase {

  public function testEnabling() {
    LoggingStreamSwitcher::enableLogging('foo');

    $this->assertTrue(LoggingStreamSwitcher::isEnabled('foo'));
  }

  public function testDisabling() {
    LoggingStreamSwitcher::disableLogging('foo');

    $this->assertFalse(LoggingStreamSwitcher::isEnabled('foo'));
  }

  public function testSwitching() {
    LoggingStreamSwitcher::enableLogging('foo');
    LoggingStreamSwitcher::disableLogging('foo');

    $this->assertFalse(LoggingStreamSwitcher::isEnabled('foo'));
  }
}
