<?php

namespace Drupal\civihr_employee_portal\Hook\ModuleImplementsAlter;

abstract class ImplementationAlterer {

  /**
   * Check whether this class should act on the implementation array
   *
   * @param string $hookName
   *
   * @return bool
   */
  abstract public function shouldAlter($hookName);

  /**
   * Make changes to the implementations
   *
   * @param array $implementations
   *
   * @return void
   */
  abstract public function alter(array &$implementations);

  /**
   * @param array $implementations
   * @param string $moduleName
   */
  protected function moveToEnd(array &$implementations, $moduleName) {
    if (!isset($implementations[$moduleName])) {
      $serr = sprintf('Cannot re-order as module "%s" is not set', $moduleName);
      throw new \RuntimeException($serr);
    }

    $tmp = [$moduleName => $implementations[$moduleName]];
    unset($implementations[$moduleName]);
    $implementations += $tmp;
  }
}


