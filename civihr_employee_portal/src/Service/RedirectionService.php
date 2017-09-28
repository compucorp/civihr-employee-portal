<?php

namespace Drupal\civihr_employee_portal\Service;

use Drupal\civihr_employee_portal\Helpers\WebformHelper;
use Drupal\civihr_employee_portal\Security\PublicFirewall;

class RedirectionService {

  /**
   * @var PublicFirewall
   */
  protected $firewall;

  /**
   * @var array
   */
  protected $inaccessibleRoutes = [
    '',
    'civicrm',
    'civicrm/dashboard'
  ];

  public function __construct() {
    $this->firewall = new PublicFirewall();
  }

  /**
   * @param $user
   * @param $route
   * @param $requestURI
   *
   * @return string|null
   *   The new route or NULL if no redirect is needed
   */
  public function getRedirectRoute($user, $route, $requestURI) {

    $isAnonymous = is_null($user) || $user->uid == 0;

    if (!$this->firewall->canAccess($user, $route)) {
      $query = $route ? sprintf('?destination=%s', $requestURI) : '';

      return 'welcome-page' . $query;
    }

    if ($this->isAjaxRoute($route)) {
      return NULL;
    }

    if (in_array($route, $this->inaccessibleRoutes)) {
      $tasksDashboard = 'civicrm/tasksassignments/dashboard#/tasks';

      return user_access('access CiviCRM') ? $tasksDashboard : 'dashboard';
    }

    // force all logged in users to complete onboarding
    if (!$isAnonymous
      && !$this->isOnboardingRoute($user, $route)
      && !$this->hasDoneOnboarding($user)
    ) {
      return 'onboarding-form';
    }

    return NULL;
  }

  /**
   * @param \stdClass $user
   * @return bool
   */
  private function hasDoneOnboarding($user) {
    $name = 'Welcome to CiviHR';
    $submissions = WebformHelper::getUserSubmissionsByName($user, $name);

    return !empty($submissions);
  }

  /**
   * @param $user
   * @param $route
   * @return bool
   */
  private function isOnboardingRoute($user, $route) {
    $userEditRoute = sprintf('user/%d/edit', $user->uid);
    $onboardingRoutes = [
      'onboarding-form',
      'features-in-civihr',
      $userEditRoute
    ];

    return in_array($route, $onboardingRoutes);
  }

  /**
   * @param string $route
   * @return bool
   */
  private function isAjaxRoute($route) {
    return strpos($route, 'ajax') !== FALSE;
  }

}
