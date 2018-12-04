<?php

/**
 * Refreshes the webform exports which had to be updated to remove the
 * progressbar setting enabled by default by the webform module version 1.18
 */
function civihr_employee_portal_update_7043() {
  civicrm_initialize();
  drush_civihr_employee_portal_refresh_node_export_files();
}
