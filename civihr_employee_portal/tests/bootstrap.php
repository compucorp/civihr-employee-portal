<?php

if (false === getenv('CIVICRM_SETTINGS')) {
  $errMsg = "Environment variable CIVICRM_SETTINGS must be defined. Use:\n";
  $errMsg .= 'export CIVICRM_SETTINGS="/path/to/civicrm.settings.php"';
  throw new \Exception($errMsg);
}

$civicrmSettings = getenv('CIVICRM_SETTINGS');

if (!file_exists($civicrmSettings)) {
  throw new \Exception(sprintf('Settings file not found at "%s"', $civicrmSettings));
}

require_once $civicrmSettings;

if (!defined('DRUPAL_ROOT')) {
  define('DRUPAL_ROOT', realpath(dirname($civicrmSettings) . '/../../'));
}

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
$_SERVER['REMOTE_ADDR'] = 'localhost';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
