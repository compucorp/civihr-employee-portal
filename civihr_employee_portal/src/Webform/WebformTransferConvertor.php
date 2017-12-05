<?php

namespace Drupal\civihr_employee_portal\Webform;

/**
 * Defines some methods that should be implemented for the alteration of node
 * data on export, and alteration again when nodes are being imported.
 */
interface WebformTransferConvertor {

  /**
   * Use this method to add or alter data that is being exported, for example to
   * save some metadata about the node that is not included in the export.
   *
   * @param \stdClass $node
   *
   * @return void
   */
  public static function preExport(\stdClass $node);

  /**
   * Use this method to alter data on import, such as by changing some values
   * not handled by the default importing of nodes.
   *
   * @param \stdClass $node
   *
   * @return void
   */
  public static function preImport(\stdClass $node);
  
}
