<?php

use Drupal\civihr_employee_portal\Webform\LocationTypeIDConvertor;

class LocationTypeIDConvertorTest extends PHPUnit_Framework_TestCase {

  /**
   * @var array
   */
  protected $locationType;

  protected function setUp() {
    $result = civicrm_api3('LocationType', 'create', ['name' => 'Test']);
    $this->locationType = array_shift($result['values']);
  }

  protected function tearDown() {
    civicrm_api3('LocationType', 'delete', ['id' => $this->locationType['id']]);
  }

  public function testEmptyMapping() {
    $node = new \stdClass();
    LocationTypeIDConvertor::preExport($node);

    $key = LocationTypeIDConvertor::MAPPING_KEY;
    $this->assertArrayHasKey($key, $node->customMapping);
  }

  public function testExportAndReImport() {
    $node = new \stdClass();
    $sampleLocationType = $this->locationType;
    $correctID = $sampleLocationType['id'];
    $wrongID = $correctID + 500;

    $node->webform_civicrm = $this->getSampleCiviCRMWebform($correctID);

    // Check that export will add the correct mapping
    LocationTypeIDConvertor::preExport($node);
    $mapping = &$node->customMapping[LocationTypeIDConvertor::MAPPING_KEY];
    $this->assertEquals([$correctID => $sampleLocationType['name']], $mapping);

    // Break the mapping to point to wrong ID
    $mapping[$wrongID] = $sampleLocationType['name'];
    unset($mapping[$correctID]);
    $phoneData = &$node->webform_civicrm['data']['Contact'][0]['phone'][0];
    $phoneData['location_type_id'] = $wrongID;
    $this->assertEquals($wrongID, $phoneData['location_type_id']);

    // Check that importing will correct the ID
    LocationTypeIDConvertor::preImport($node);
    $this->assertEquals($correctID, $phoneData['location_type_id']);
  }

  /**
   * @param $correctID
   * @return array
   */
  private function getSampleCiviCRMWebform($correctID) {
    return [
      'data' => [
        'Contact' => [
          [
            'phone' => [
              [
                'location_type_id' => $correctID
              ],
            ]
          ]
        ]
      ]
    ];
  }
}
