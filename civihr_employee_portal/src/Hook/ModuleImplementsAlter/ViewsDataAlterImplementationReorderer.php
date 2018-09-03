<?php

namespace Drupal\civihr_employee_portal\Hook\ModuleImplementsAlter;

class ViewsDataAlterImplementationReorderer extends ImplementationAlterer {

  /**
   * @inheritdoc
   */
  public function alter(array &$implementations) {
    $group = [];

    // Check if the module exists and it's installed
    if (module_exists('views_autocomplete_filters')) {
      // Put the views autocomplete filters after civicrm
      $module = 'views_autocomplete_filters';
      $group += [$module => $implementations[$module]];
      unset($implementations[$module]);
    }

    /**
     * Put the civihr employee portal module after civicrm module . The civicrm
     * module will ruthlessly replace all changes from views_data_alter hook
     * @see civicrm_views_data_alter
     */
    $module = 'civihr_employee_portal';
    $group += [$module => $implementations[$module]];
    unset($implementations[$module]);

    // Make sure some modules are after civicrm to avoid error with autocomplete search or drush cc all
    $implementations = $implementations + $group;
  }

  /**
   * @inheritdoc
   */
  public function shouldAlter($hookName) {
    return $hookName === 'views_data_alter';
  }

}
