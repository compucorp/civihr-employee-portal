<?php

namespace Drupal\civihr_employee_portal\Helpers;

use CRM_Utils_Array as ArrayHelper;

class NodeHelper {

  /**
   * @param \stdClass $node
   * @param string $name
   *
   * @return array
   */
  public static function getWebformComponentsByName($node, $name) {
    if (!property_exists($node, 'webform')) {
      return [];
    }

    $components = ArrayHelper::value('components', $node->webform, []);

    return array_filter($components, function($component) use ($name) {
      return ArrayHelper::value('name', $component) === $name;
    });
  }
}
