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
   * Returns a single component of a form that matches the provided title
   *
   * @param \stdClass $node
   * @param string $title
   *
   * @return array
   */
  public static function getComponentByTitle($node, $title) {
    if (!property_exists($node, 'webform')) {
      return [];
    }

    $components = ArrayHelper::value('components', $node->webform, []);

    $components = array_filter($components, function($component) use ($title) {
      return ArrayHelper::value('name', $component) === $title;
    });

    if (count($components) !== 1) {
      throw new \Exception('Webform component title is not unique');
    }

    return array_shift($components);
  }

  /**
   * Gets the submitted value for a webform by the title of the field.
   *
   * @param \stdClass $node
   *   The webform node
   * @param \stdClass $submission
   *   The submitted values
   * @param string $title
   *   The title of the field to lookup
   *
   * @return mixed
   */
  public static function getValueByTitle($node, $submission, $title) {
    $component = WebformHelper::getComponentByTitle($node, $title);
    $cid = \CRM_Utils_Array::value('cid', $component);
    $submission = isset($submission->data) ? $submission->data : [];
    $value = \CRM_Utils_Array::value($cid, $submission, []);

    return array_shift($value);
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
