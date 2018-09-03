<?php

namespace Drupal\civihr_employee_portal\Helpers;

/**
 * Handles enabling and disabling of logging streams. The actual logging is
 * handled elsewhere - see the CiviHR hrcore extension.
 */
class LoggingStreamSwitcher {

  /**
   * Sets a logging stream status to enabled
   *
   * @param string $streamName
   */
  public static function enableLogging($streamName) {
    global $civihrChangeLogStreams;
    $civihrChangeLogStreams[$streamName] = TRUE;
  }

  /**
   * Sets a logging stream status to disabled
   *
   * @param string $streamName
   */
  public static function disableLogging($streamName) {
    global $civihrChangeLogStreams;
    $civihrChangeLogStreams[$streamName] = FALSE;
  }

  /**
   * Checks whether a given logging stream is enabled
   *
   * @param string $streamName
   *
   * @return bool
   */
  public static function isEnabled($streamName) {
    global $civihrChangeLogStreams;

    return \CRM_Utils_Array::value($streamName, $civihrChangeLogStreams, FALSE);
  }

}
