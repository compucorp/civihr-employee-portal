<?php

use Drupal\civihr_employee_portal\Webform\CustomComponentKeyHelper as KeyHelper;

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
      KeyHelper::rebuildCustomFieldKey($groupID, $fieldID, $original)
    );
  }

  /**
   * @dataProvider fieldsetKeyProvider
   *
   * @param string $key
   * @param string $expected
   */
  public function testGettingGroupIdWillReturnExpectedGroup($key, $expected) {
    $this->assertEquals($expected, KeyHelper::getCustomFieldsetGroupId($key));
  }

  /**
   * @dataProvider fieldsetKeyProvider
   *
   * @param string $key
   * @param string $expected
   */
  public function testCustomFieldsetKeysWillBeDetectedCorrectly($key, $expected) {
    $expected = !is_null($expected); // if expected not null it is custom field
    $this->assertEquals($expected, KeyHelper::isCustomFieldsetKey($key));
  }

  /**
   * @dataProvider rebuildCustomFieldsetKeyProvider
   *
   * @param string $original
   * @param string $newGroup
   * @param string $expected
   */
  public function testRebuildingKeyWillReplaceCustomGroupId(
    $original,
    $newGroup,
    $expected
  ) {
    $newKey = KeyHelper::rebuildCustomFieldsetKey($original, $newGroup);

    $this->assertEquals($expected, $newKey);
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

  /**
   * @return array
   */
  public function fieldsetKeyProvider() {
    return [
      [
        'civicrm_',
        NULL
      ],
      [
        'civicrm_1_contact_1_cg9999_fieldset',
        '9999'
      ],
      [
        'civicrm_1_contact_1_cg9999_faldset',
        NULL
      ],
      [
        'civicrm_1_contact_1_cg1_fieldset',
        '1'
      ],
    ];
  }

  /**
   * @return array
   */
  public function rebuildCustomFieldsetKeyProvider() {
    return [
      [
        'civicrm_1_contact_1_cg9999_fieldset',
        '21',
        'civicrm_1_contact_1_cg21_fieldset',
      ],
      [
        'civicrm_1_contact_1_cg9_fieldset',
        '111111111111',
        'civicrm_1_contact_1_cg111111111111_fieldset',
      ],
    ];
  }

}
