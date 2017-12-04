<?php

namespace Drupal\civihr_employee_portal\Helpers;

class NodeHelper {

  /**
   * Finds a single node
   *
   * @param array $criteria
   *   The criteria for searching for the node
   *
   * @return \stdClass|null
   *   The node, if found. NULL if not found or more than one exist.
   */
  public static function findOneBy($criteria = []) {
    $nodes = node_load_multiple(NULL, $criteria);

    if (count($nodes) !== 1) {
      return NULL;
    }

    return current($nodes);
  }
}
