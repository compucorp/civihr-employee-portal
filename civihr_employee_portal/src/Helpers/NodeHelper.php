<?php

namespace Drupal\civihr_employee_portal\Helpers;

class NodeHelper {

  /**
   * Finds a single node
   *
   * @param array $criteria
   *   The criteria for searching for the node
   *
   * @return \stdClass|null
   *   The first node matching the criteria, if found. NULL if not found.
   */
  public static function findOneBy($criteria = []) {
    $nodes = node_load_multiple(NULL, $criteria);

    if (!$nodes) {
      return NULL;
    }

    return current($nodes);
  }

  /**
   * Refreshes all the exported node files bundled with this module.
   *
   * @return int
   *   The number of nodes refreshed
   *
   * @throws \Exception
   */
  public static function refreshExportFiles() {
    $moduleRoot = drupal_get_path('module', 'civihr_employee_portal');
    $exportFilesDir = $moduleRoot . '/features/node_export_files';
    $files = file_scan_directory($exportFilesDir, '/.*\.export$/');
    $count = 0;

    foreach ($files as $filepath => $file) {
      $contents = file_get_contents($filepath);
      $importData = node_export_import($contents, 't', FALSE);
      $importNodes = empty($importData['nodes']) ? [] : $importData['nodes'];

      foreach ($importNodes as $importNode) {
        $existingNode = self::findOneBy([
          'title' => $importNode->title,
          'type' => $importNode->type,
        ]);

        // Set these to update existing instead of creating new node
        if ($existingNode) {
          $importNode->nid = $existingNode->nid;
          $importNode->vid = $existingNode->vid;
          $importNode->is_new = FALSE;
        }

        node_export_save($importNode);

        // Need to manually update webform_civicrm_form record
        if ($importNode->type === 'webform' && !$importNode->is_new) {
          $civicrmWebform = $importNode->webform_civicrm;
          $civicrmWebform['nid'] = $existingNode->nid;
          drupal_write_record('webform_civicrm_forms', $civicrmWebform, ['nid']);
        }

        variable_set($file->name . '_webform_nid', $importNode->nid);
        $count++;
      }
    }

    return $count;
  }
}
