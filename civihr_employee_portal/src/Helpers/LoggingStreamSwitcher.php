<?php

namespace Drupal\civihr_employee_portal\Helpers;

/**
 * Handles enabling and disabling of logging streams. The actual logging is
 * handled elsewhere - see the CiviHR hrcore extension.
 */
class LoggingStreamSwitcher {

  /**
   * @param string $streamName
   */
  public static function enableLogging($streamName) {
    global $civihrChangeLogStreams;
    $civihrChangeLogStreams[$streamName] = TRUE;
  }

  /**
   * @param string $streamName
   */
  public static function disableLogging($streamName) {
    global $civihrChangeLogStreams;
    $civihrChangeLogStreams[$streamName] = FALSE;
  }

}
