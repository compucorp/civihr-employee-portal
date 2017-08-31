<?php

namespace Drupal\civihr_employee_portal\Helpers;

use CRM_Utils_Array as ArrayHelper;

class WebformHelper {

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

  /**
   * @param $user
   * @param $name
   *
   * @return array
   */
  public static function getUserSubmissionsByName($user, $name) {
    $filters = ['uid' => $user->uid];
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    $submissions = webform_get_submissions($filters);

    foreach ($submissions as $submission) {
      $title = property_exists($submission, 'title') ? $submission->title : NULL;
      if ($title === $name) {
        $submissions[] = $submission;
      }
    }

    return $submissions;
  }
}
