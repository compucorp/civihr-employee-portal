<?php

namespace Drupal\civihr_employee_portal\Webform;

interface WebformTransferConvertor {

  /**
   * @param \stdClass $node
   * @return void
   */
  public static function preExport(\stdClass $node);

  /**
   * @param \stdClass $node
   * @return void
   */
  public static function preImport(\stdClass $node);
  
}
