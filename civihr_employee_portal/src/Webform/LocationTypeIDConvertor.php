<?php

namespace Drupal\civihr_employee_portal\Webform;

class LocationTypeIDConvertor implements WebformTransferConvertor {

  const MAPPING_KEY = 'locationTypes';

  /**
   * @inheritdoc
   */
  public static function preExport(\stdClass $node) {
    $locationTypeIDs = self::getLocationTypeIDsByRef($node);
    $params = ['id' => ['IN' => $locationTypeIDs]];
    $locationTypes = civicrm_api3('LocationType', 'get', $params)['values'];
    $locationTypes = array_column($locationTypes, 'name', 'id');
    $node->customMapping[self::MAPPING_KEY] = $locationTypes;
  }

  /**
   * @inheritdoc
   */
  public static function preImport(\stdClass $node) {
    $oldMapping = $node->customMapping[self::MAPPING_KEY];
    $oldToNewMapping = self::reverseMapping($oldMapping);

    foreach (self::getLocationTypeIDsByRef($node) as &$locationTypeID) {
      if (isset($oldToNewMapping[$locationTypeID])) {
        $locationTypeID = $oldToNewMapping[$locationTypeID];
      }
    }
  }

  /**
   * Gets all location type IDs for a webform.
   * Results are returned by reference to allow easier modification.
   *
   * @param \stdClass $node
   * @return array
   */
  private static function getLocationTypeIDsByRef(\stdClass $node) {
    $locationTypeIDs = [];

    $civicrmData = &$node->webform_civicrm;
    foreach ($civicrmData['data'] as &$entities) {
      foreach ($entities as &$entity) {
        if (!is_array($entity)) {
          continue;
        }
        foreach ($entity as &$subEntities) {
          if (!is_array($subEntities)) {
            continue;
          }
          foreach ($subEntities as &$subEntity) {
            foreach ($subEntity as $key => &$value) {
              if ($key === 'location_type_id') {
                $locationTypeIDs[] = &$value;
              }
            }
          }
        }
      }
    }

    return $locationTypeIDs;
  }

  /**
   * Gets a mapping of old location type IDs to their new ID.
   *
   * @param $oldMapping
   * @return array
   */
  private static function reverseMapping($oldMapping) {
    $params = ['name' => ['IN' => $oldMapping]];
    $newLocationTypes = civicrm_api3('LocationType', 'get', $params)['values'];
    $newLocationTypes = array_column($newLocationTypes, 'name', 'id');
    $oldToNewMapping = [];

    foreach ($oldMapping as $oldID => $name) {
      if (in_array($name, $newLocationTypes)) {
        $oldToNewMapping[$oldID] = array_search($name, $newLocationTypes);
      }
    }
    return $oldToNewMapping;
  }

}
