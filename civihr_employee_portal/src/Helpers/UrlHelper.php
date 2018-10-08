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

  /**
   * Removes the provided key from the URL query parameters
   *
   * @param string $url
   *   The URL to edit, e.g. http://example.com?foo=bar&bar=zoo
   * @param string $targetKey
   *   The key you want to remove e.g. bar
   *
   * @return string
   *   Original URL without the target query, e.g. http://example.com?foo=bar
   */
  public static function removeQueryValueFromUrl($url, $targetKey) {
    $origQueryString = parse_url($url, PHP_URL_QUERY);
    $queryParts = explode('&', $origQueryString);

    $newQueryParts = [];
    foreach ($queryParts as $index => $queryPart) {
      list($key) = explode('=', $queryPart);

      $keyToCompare = $targetKey;
      if (substr($key, -2) === '[]') {
        $keyToCompare = $targetKey . '[]';
      }

      if ($key !== $keyToCompare) {
        $newQueryParts[$key] = $queryPart;
      }
    }

    $newQueryString = implode('&', $newQueryParts);
    $newUrl = str_replace($origQueryString, $newQueryString, $url);

    if (!$newQueryString) {
      // remove ? if no query string remains
      $newUrl = str_replace('?', '', $newUrl);
    }

    return $newUrl;
  }

}
