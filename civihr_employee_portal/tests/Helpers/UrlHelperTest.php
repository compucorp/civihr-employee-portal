<?php

use Drupal\civihr_employee_portal\Helpers\UrlHelper;

class UrlHelperTest extends \PHPUnit_Framework_TestCase {

  /**
   * @dataProvider duplicateQueryUrlProvider
   *
   * @param string $url
   * @param string $expected
   */
  public function testDedupeWillReturnExpectedResults($url, $expected) {
    $this->assertEquals($expected, UrlHelper::dedupeUrlQueryParams($url));
  }

  /**
   * @return array
   */
  public function duplicateQueryUrlProvider() {
    return [
      [
        '',
        '',
      ],
      [
        'http://www.civihr.net',
        'http://www.civihr.net',
      ],
      [
        'http://civihr.net/sites/default/files/webform/500_3.jpg?photo=0&photo=0&photo=0&photo=0&photo=0&photo=0',
        'http://civihr.net/sites/default/files/webform/500_3.jpg?photo=0',
      ],
      [
        'http://civihr.local/civicrm/contact/imagefile?photo=pp_2e6adadea8d41b0ac065e888f2e61dc5.jpeg',
        'http://civihr.local/civicrm/contact/imagefile?photo=pp_2e6adadea8d41b0ac065e888f2e61dc5.jpeg',
      ],
      [
        'http://civihr.local/civicrm/contact/imagefile?photo=pp_2e6adadea8d41b0ac065e888f2e61dc5.jpeg&photo=0',
        'http://civihr.local/civicrm/contact/imagefile?photo=pp_2e6adadea8d41b0ac065e888f2e61dc5.jpeg',
      ],
      [
        'http://www.civihr.net?foo=bar&bar=car&foo=bar2&bar=car2#someanchor',
        'http://www.civihr.net?foo=bar&bar=car#someanchor',
      ],
      [
        'http://www.civihr.net?foo[]=1&foo[]=2&bar[a]=3',
        'http://www.civihr.net?foo[]=1&foo[]=2&bar[a]=3',
      ],
      [
        'http://www.civihr.net?foo[]=1&foo[]=2&1=a',
        'http://www.civihr.net?foo[]=1&foo[]=2&1=a',
      ],
      [
        'http://www.civihr.net?foo[]=1&foo[]=2&foo[a]=1&foo[a]=2',
        'http://www.civihr.net?foo[]=1&foo[]=2&foo[a]=1',
      ],
      [
        'http://www.civihr.net?foo[a][]=1&foo[a][]=2',
        'http://www.civihr.net?foo[a][]=1&foo[a][]=2',
      ],
      [
        'http://www.civihr.net?foo[a][b]=1&foo[a][b]=2',
        'http://www.civihr.net?foo[a][b]=1',
      ],
    ];
  }

}
