<?php

namespace Drupal\civihr_employee_portal\Security;

/**
 * This class is responsible for checking if anonymous users can access
 * certain routes
 */
class PublicFirewall {

  /**
   * Anonymous users can access these paths
   *
   * @var array
   */
  public static $publicRoutes = [
    '/^welcome-page$/',
    '/^sites\/default\/files\/logo.jpg$/', // if logo is missing
    '/^request_new_account\/ajax$/', // from login page
    '/^user((?!\/register).)*$/', // user* except user/register
    '/^yoti-connect*/' // yoti login plugin
  ];

  /**
   * @param \stdClass $user the user to check access for
   * @param string $route the route to check
   *
   * @return bool
   */
  public function canAccess($user, $route) {
    $isAnonymous = is_null($user) || $user->uid == 0;

    if (!$isAnonymous) {
      return TRUE;
    }

    return $this->allowAnonymousAccess($route);
  }

  /**
   * Check if route matches against all public routes
   *
   * @param string $route
   * @return bool
   */
  private function allowAnonymousAccess($route) {
    foreach (self::$publicRoutes as $pattern) {
      if (preg_match($pattern, $route)) {
        return TRUE;
      }
    }

    return FALSE;
  }

}
