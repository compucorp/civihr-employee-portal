<?php

use Drupal\civihr_employee_portal\Security\PublicFirewall;

// required as we have no autoloader inside this extension
require_once __DIR__ . '/../src/Security/PublicFirewall.php';

class PublicFirewallTest extends \PHPUnit_Framework_TestCase {

  public function testAuthenticatedUserIsAllowed() {
    $user = new \stdClass();
    $user->uid = 132;

    $firewall = new PublicFirewall();
    $this->assertTrue($firewall->canAccess($user, '/foo'));
  }

  /**
   * @dataProvider protectedRouteProvider
   * @param $route
   */
  public function testAnonymousUserDeniedAsExpected($route) {
    $user = new \stdClass();
    $user->uid = 0;
    $firewall = new PublicFirewall();
    $this->assertFalse($firewall->canAccess($user, $route));
  }

  /**
   * @test
   * @dataProvider publicRouteProvider
   * @param $route
   */
  public function testAnonymousUserAllowedAsExpected($route) {
    $user = new \stdClass();
    $user->uid = 0;
    $firewall = new PublicFirewall();
    $this->assertTrue($firewall->canAccess($user, $route));
  }

  /**
   * @return array
   */
  public function protectedRouteProvider() {
    return [
      ['user/register'],
      ['welcome-page/protected'],
      ['request_new_accountajax'],
      ['home/user'],
      ['yoti_connect'],
      ['something/yoti-connect'],
      [''],
    ];
  }

  /**
   * @return array
   */
  public function publicRouteProvider() {
    return [
      ['user'],
      ['sites/default/files/logo.jpg'],
      ['request_new_account/ajax'],
      ['user/some/other/path'],
      ['yoti-connect'],
      ['yoti-connect/anything'],
    ];
  }

}