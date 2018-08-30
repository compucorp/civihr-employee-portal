<?php

namespace Drupal\civihr_employee_portal\Hook\ModuleImplementsAlter;

interface ImplementationAlterer {

  /**
   * Check whether this class should act on the implementation array
   *
   * @param string $hookName
   *
   * @return bool
   */
  public function shouldAlter($hookName);

  /**
   * Make changes to the implementations
   *
   * @param array $implementations
   *
   * @return void
   */
  public function alter(array &$implementations);

}
