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
      $err = sprintf('Webform component title "%s" is not unique', $title);
      throw new \Exception($err);
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

    return self::getValueForComponent($component, $submission);
  }

  /**
   * Fetches the submitted value for a component
   *
   * @param array $component
   * @param \stdClass $submission
   *
   * @return mixed
   */
  public static function getValueForComponent($component, $submission) {
    $cid = \CRM_Utils_Array::value('cid', $component);
    $submission = isset($submission->data) ? $submission->data : [];
    $value = \CRM_Utils_Array::value($cid, $submission, []);

    return array_shift($value);
  }

  /**
   * Gets all the submitted values, replacing options with their labels. The
   * values will be grouped by page and fieldset. If page and fieldset names
   * are available they will be used instead of a numeric index
   *
   * @param \stdClass $node
   * @param \stdClass $submission
   *
   * @return array
   */
  public static function getSubmittedValues($node, $submission) {
    $submittedValues = [];
    $components = $node->webform['components'];
    $typesToSkip = ['markup', 'pagebreak', 'fieldset'];
    $pageTitles = self::getPageTitles($components);
    $fieldsetTitles = self::getFieldsetTitles($components);

    foreach ($components as $component) {
      if (in_array($component['type'], $typesToSkip)) {
        continue;
      }

      $value = self::getValueForComponent($component, $submission);

      // Replace ID with label for select options
      $options = self::getComponentOptions($component);
      if (!empty($options[$value])) {
        $value = $options[$value];
      }

      // Use page title if it exists
      $pageIndex = $component['page_num'];
      if (isset($pageTitles[$pageIndex])) {
        $pageIndex = $pageTitles[$pageIndex];
      }

      // Use fieldset title if it exists, default to parent ID
      $fieldsetIndex = $component['pid'];
      if (isset($fieldsetTitles[$component['pid']])) {
        $fieldsetIndex = $fieldsetTitles[$component['pid']];
      }

      $submittedValues[$pageIndex][$fieldsetIndex][$component['name']] = $value;
    }

    return $submittedValues;
  }

  /**
   * Gets the titles for all markup components assuming they have the h2 tag.
   *
   * @param array $components
   *
   * @return array
   *   The title names stripped of HTML tags and indexed by page number
   */
  private static function getPageTitles($components) {
    $titles = [];

    foreach ($components as $component) {
      if ($component['type'] !== 'markup') {
        continue;
      }

      $doc = new \DOMDocument();
      $doc->loadXML($component['value']);
      $title = $doc->getElementsByTagName('h2')->item(0)->nodeValue;
      $titles[$component['page_num']] = $title;
    }

    return $titles;
  }

  /**
   * Gets the titles for all fieldset components indexed by component ID
   *
   * @param array $components
   *
   * @return array
   */
  private static function getFieldsetTitles($components) {
    $titles = [];

    foreach ($components as $component) {
      if ($component['type'] !== 'fieldset') {
        continue;
      }

      $titles[$component['cid']] = $component['name'];
    }

    return $titles;
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

  /**
   * Returns a list of options from the component indexed by their ID (value
   * for OptionValues)
   *
   * @param array $component
   *
   * @return array
   */
  public static function getComponentOptions($component) {
    $options = [];

    $extra = ArrayHelper::value('extra', $component, []);
    $items = ArrayHelper::value('items', $extra);

    if (!$items) {
      return $options;
    }

    $items = explode("\n", $items);
    foreach ($items as $item) {
      if (strpos($item, '|') !== FALSE) {
        list($id, $label) = explode('|', $item);
        $options[$id] = $label;
      }
    }

    return $options;
  }

}
