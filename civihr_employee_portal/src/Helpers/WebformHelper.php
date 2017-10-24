<?php

namespace Drupal\civihr_employee_portal\Helpers;

use CRM_Utils_Array as ArrayHelper;

class WebformHelper {

  /**
   * Finds a single webform by title.
   *
   * @param string $title
   *   The title of the webform
   *
   * @return \stdClass|null
   *   The webform if found, NULL if not found or more than one exist
   */
  public static function findOneByTitle($title) {
    $conditions = ['title' => $title, 'type' => 'webform'];
    $nodes = node_load_multiple(NULL, $conditions);

    if (count($nodes) !== 1) {
      return NULL;
    }

    return current($nodes);
  }

  /**
   * Returns all components of a form that match the provided name
   *
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

  /**
   * Finds all webform submissions by a Drupal user.
   *
   * @param \stdClass $user
   * @param string $title
   *
   * @return array
   */
  public static function getUserSubmissionsByTitle($user, $title) {
    $filters = ['uid' => $user->uid];
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    $allUserSubmissions = webform_get_submissions($filters);
    $targetFormSubmissions = [];
    $webform = self::findOneByTitle($title);
    $webformId = $webform->nid;

    foreach ($allUserSubmissions as $submission) {
      $nodeID = property_exists($submission, 'nid') ? $submission->nid : NULL;
      if ($webformId === $nodeID) {
        $targetFormSubmissions[] = $submission;
      }
    }

    return $targetFormSubmissions;
  }
}
