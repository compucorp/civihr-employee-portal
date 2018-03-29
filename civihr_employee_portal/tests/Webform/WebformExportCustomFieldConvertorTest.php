<?php

use Drupal\civihr_employee_portal\Webform\WebformExportCustomFieldConvertor as Convertor;
use Drupal\civihr_employee_portal\Webform\CustomComponentKeyHelper as KeyHelper;

class WebformExportCustomFieldConvertorTest extends PHPUnit_Framework_TestCase {

  /**
   * Basic test to check that an empty node will still have empty mapping
   */
  public function testEmptyMapping() {
    $node = new \stdClass();
    $node->type = 'webform';
    Convertor::preExport($node);

    $this->assertObjectHasAttribute('customMapping', $node);
  }

  /**
   * This tests that the correct custom group/field IDs and names will be added
   */
  public function testMappingAddsCorrectNames() {
    $node = $this->getNodeWithMapping(2);
    Convertor::preExport($node);

    $mapping = $node->customMapping;
    $groupID = key($mapping['customGroups']);
    $groupName = current($mapping['customGroups']);
    $fieldID = key($mapping['customFields']);
    $fieldName = current($mapping['customFields']);

    $params = ['return' => "name", 'id' => $groupID];
    $expectedGroupName = civicrm_api3('CustomGroup', 'getvalue', $params);
    $params['id'] = $fieldID;
    $expectedFieldName = civicrm_api3('CustomField', 'getvalue', $params);

    $this->assertEquals($expectedFieldName, $fieldName);
    $this->assertEquals($expectedGroupName, $groupName);
  }

  /**
   * This creates a node with some components and adds the mapping to it.
   * Then it changes some IDs on the node data and checks that the function
   * replaceCustomDataForImport will update the node to use the correct IDs.
   */
  public function testConversionWhenIDsHaveChanged() {
    // get a node and add mapping before corrupting it
    $node = $this->getNodeWithMapping(2);
    Convertor::preExport($node);
    $webformCount = &$node->webform_civicrm['data']['contact'][0];

    $sampleComponent = &$node->webform['components'][0];
    $correctKey = $sampleComponent['form_key'];

    $correctGroupID = KeyHelper::getCustomGroupID($correctKey);
    $correctFieldID = KeyHelper::getCustomFieldID($correctKey);
    $wrongGroupID = $correctGroupID + 200;
    $wrongFieldID = $correctFieldID + 200;

    // Replace the form key with key using wrong group and field ID
    $badKey = KeyHelper::rebuildCustomFieldKey($wrongGroupID, $wrongFieldID, $correctKey);
    $sampleComponent['form_key'] = $badKey;

    // Replace CiviCRM webform count with keys using wrong group ID
    $correctCountKey = 'number_of_cg' . $correctGroupID;
    $wrongCountKey = 'number_of_cg' . $wrongGroupID;
    $webformCount[$wrongCountKey] = $webformCount[$correctCountKey];
    unset($webformCount[$correctCountKey]);

    // Replace group mapping
    $groupMapping = &$node->customMapping['customGroups'];
    $groupMapping[$wrongGroupID] = $groupMapping[$correctGroupID];
    unset($groupMapping[$correctGroupID]);

    // Replace field mapping
    $fieldMapping = &$node->customMapping['customFields'];
    $fieldMapping[$wrongFieldID] = $fieldMapping[$correctFieldID];
    unset($fieldMapping[$correctFieldID]);

    Convertor::preImport($node);

    $this->assertEquals($correctKey, $sampleComponent['form_key']);
    $this->assertArrayHasKey($correctCountKey, $webformCount);
  }

  /**
   * @param $componentLimit
   * @return stdClass
   */
  private function getNodeWithMapping($componentLimit) {
    $node = new \stdClass();
    $node->type = 'webform';
    $customGroupIDs = $this->getRandomEntityIDs('CustomGroup', $componentLimit);
    $customFieldIDs = $this->getRandomEntityIDs('CustomField', $componentLimit);

    if (empty($customFieldIDs) || empty($customGroupIDs)) {
      $this->markTestSkipped('Could not load custom fields / groups');
    }

    $format = 'civicrm_1_contact_1_cg_%d_custom_%d';
    foreach ($customGroupIDs as $index => $customGroupID) {
      $key = sprintf($format, $customGroupIDs[$index], $customFieldIDs[$index]);
      $node->webform['components'][] = ['form_key' => $key];

      // add CiviCRM webform mapping
      $node->webform_civicrm['data']['contact'][0]['number_of_cg' . $customGroupID] = 1;
    }

    return $node;
  }

  /**
   * @param string $entity
   * @param int $limit
   * @return array
   */
  private function getRandomEntityIDs($entity, $limit = 5) {
    $results = civicrm_api3($entity, 'get', ['options' => ['limit' => $limit]]);

    return array_column($results['values'], 'id');
  }

}
