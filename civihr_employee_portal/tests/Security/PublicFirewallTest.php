<?php

use Drupal\civihr_employee_portal\Security\PublicFirewall;

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
      ['something/yoti'],
      ['something/yoti_connect'],
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
      ['yoti'],
      ['yoti/anything'],
      ['yoti-connect'],
      ['yoti-connect/lorem-ipsum'],
      ['civicrm/calendar-feed']
    ];
  }

}
