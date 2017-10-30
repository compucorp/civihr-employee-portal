<?php

use Drupal\civihr_employee_portal\Helpers\Webform\CustomComponentKeyHelper;

class CustomComponentKeyHelperTest extends \PHPUnit_Framework_TestCase {

  /**
   * @dataProvider groupIDKeyProvider
   *
   * @param string $key
   * @param int $expectedGroup
   * @param int $expectedField
   */
  public function testGettingParts($key, $expectedGroup, $expectedField) {
    $groupID = CustomComponentKeyHelper::getCustomGroupID($key);
    $fieldID = CustomComponentKeyHelper::getCustomFieldID($key);

    $this->assertEquals($expectedGroup, $groupID);
    $this->assertEquals($expectedField, $fieldID);
  }

  public function testRebuildingKey() {
    $groupID = 1;
    $fieldID = 2;
    $original = 'civicrm_1_contact_1_cg_5_custom_15';
    $expected = 'civicrm_1_contact_1_cg_1_custom_2';
    $new = CustomComponentKeyHelper::rebuildKey($groupID, $fieldID, $original);

    $this->assertEquals($expected, $new);
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
