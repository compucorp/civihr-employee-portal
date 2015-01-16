<?php
/**
 * @file
 * civihr_employee_portal_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function civihr_employee_portal_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
