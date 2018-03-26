<?php

namespace Drupal\civihr_employee_portal\Helpers;

/**
 * Helper class for operations on URLs
 */
class UrlHelper {

  /**
   * Removes duplicate query parts from a url. Accepts the value for the first
   * part.
   *
   * @param string $url
   *
   * @return string
   */
  public static function dedupeUrlQueryParams($url) {
    $origQueryString = parse_url($url, PHP_URL_QUERY);
    $queryParts = explode('&', $origQueryString);

    $queryPartsUnique = [];
    foreach ($queryParts as $index => $queryPart) {
      list($key) = explode('=', $queryPart);

      // give unique key to query params like foo[]=bar
      if (substr($key, -2) === '[]') {
        $key = $key . $index;
      }

      if (!isset($queryPartsUnique[$key])) {
        $queryPartsUnique[$key] = $queryPart;
      }
    }

    $newQueryString = implode('&', $queryPartsUnique);

    return str_replace($origQueryString, $newQueryString, $url);
  }

}