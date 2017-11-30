<?php

namespace Drupal\civihr_employee_portal\Webform;

/**
 * Responsible for ensuring reliable transfer of webforms between systems.
 *
 * Handles adding metadata for fields that rely on the database IDs and then
 * using the metadata to use the correct IDs on whichever system the webform is
 * exported to.
 */
class WebformTransferService {

  /**
   * @param \stdClass $node
   */
  public static function preExport(\stdClass $node) {
    WebformExportCustomFieldConvertor::preExport($node);
    LocationTypeIDConvertor::preExport($node);
  }

  /**
   * @param \stdClass $node
   */
  public static function preImport(\stdClass $node) {
    WebformExportCustomFieldConvertor::preExport($node);
    LocationTypeIDConvertor::preImport($node);
  }
}
