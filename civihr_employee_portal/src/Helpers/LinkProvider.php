<?php

namespace Drupal\civihr_employee_portal\Helpers;

/**
 * Provides links to different parts of the site
 */
class LinkProvider {

  const SSP_DASHBOARD = 'dashboard';
  const TASKS_DASHBOARD = 'civicrm/tasksassignments/dashboard#/tasks';

  /**
   * Gets the link where the user should be redirected to after login.
   * Depending on user permissions the landing page will be different.
   *
   * @param array $user
   *   The Drupal user to provide the link for
   *
   * @return string
   *   The link to the landing page
   */
  public static function getLandingPageLink($user) {
    $canAccessCiviCRM = user_access('access CiviCRM', $user);

    return $canAccessCiviCRM ? self::TASKS_DASHBOARD : self::SSP_DASHBOARD;
  }

}
