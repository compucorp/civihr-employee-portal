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
   *   The first node matching the criteria, if found. NULL if not found.
   */
  public static function findOneBy($criteria = []) {
    $nodes = node_load_multiple(NULL, $criteria);

    if (!$nodes) {
      return NULL;
    }

    return current($nodes);
  }
}
