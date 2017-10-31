<?php

use Drupal\civihr_employee_portal\Helpers\Webform\CustomComponentKeyHelper as KeyHelper;

class CustomComponentKeyHelperTest extends \PHPUnit_Framework_TestCase {

  /**
   * @dataProvider groupIDKeyProvider
   *
   * @param string $key
   * @param int $expectedGroup
   */
  public function testGettingGroupID($key, $expectedGroup) {
    $this->assertEquals($expectedGroup, KeyHelper::getCustomGroupID($key));
  }

  /**
   * @dataProvider groupIDKeyProvider
   *
   * @param string $key
   * @param int $expectedGroup
   * @param int $expectedField
   */
  public function testGettingFieldID($key, $expectedGroup, $expectedField) {
    $this->assertEquals(
      $expectedField,
      KeyHelper::getCustomFieldID($key)
    );
  }

  /**
   * @dataProvider rebuildKeyProvider
   *
   * @param string $original
   * @param int $groupID
   * @param int $fieldID
   * @param string $expected
   */
  public function testRebuildingKey($original, $groupID, $fieldID, $expected) {
    $this->assertEquals(
      $expected,
      KeyHelper::rebuildKey($groupID, $fieldID, $original)
    );
  }

  /**
   * @return array
   */
  public function rebuildKeyProvider() {
    return [
      [
        'civicrm_1_contact_1_cg_5_custom_15',
        1,
        2,
        'civicrm_1_contact_1_cg_1_custom_2'
      ],
      [
        'civicrm_1_contact_1_cg5_custom_15',
        1000,
        999999,
        'civicrm_1_contact_1_cg1000_custom_999999'
      ]
    ];
  }

  /**
   * @return array
   */
  public function groupIDKeyProvider() {
    return [
      [
        'civicrm_firstname',
        '',
        ''
      ],
      [
        // I think the missing underscore is a bug, but I've seen it in an export
        'civicrm_1_contact_1_cg14_custom_100013',
        14,
        100013
      ],
      [
        'civicrm_1_contact_1_cg_5_custom_15',
        5,
        15
      ]
    ];
  }
}
