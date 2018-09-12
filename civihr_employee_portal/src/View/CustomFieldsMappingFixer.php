<?php

namespace Drupal\civihr_employee_portal\View;

/**
 * To match unknown table names and field names when importing views
 * with custom fields and custom groups from CiviCRM.
 * Replaces unknown fields names and unknown tables like:
 * - exported [name_of_the_field]_[ID1] with existing [name_of_the_field]_[ID2]
 * - exported [name_of_the_table]_[ID3] with existing [name_of_the_table]_[ID4]
 * ... where ID1, ID2, ID3 & ID4 are different numbers created by different
 * mechanisms thus producing different IDs.
 */
class CustomFieldsMappingFixer {

  /**
   * To fix mapping on Views import of CiviCRM custom fields
   *
   * @param \view $view
   *     the view that is being imported / recreated
   */
  public static function fixMapping($view) {
    foreach ($view->display as $display) {
      foreach ($display->display_options as &$displayOption) {
        if (!is_array($displayOption)) {
          continue;
        }

        self::processDisplayOptions($displayOption);
      }
    }
  }

  /**
   * Process all display options for an exported view only when it is related
   * to a field and the field has a number at the end of its name, which is
   * the pattern for custom fields from CiviCRM
   *
   * @var array
   *     Display option a exported view structure
   */
  private static function processDisplayOptions(&$displayOption) {
    foreach ($displayOption as &$option) {
      // only continue if this option is about a field
      if (!isset($option['field'])) {
        continue;
      }

      $optionIdParts = explode('_', $option['field']);
      $finalIdPart = array_pop($optionIdParts);
      if (count($optionIdParts) === 0 || !intval($finalIdPart)) {
        continue;
      }

      self::processOption($option);
    }
  }

  /**
   * To process a display option for a field in view
   *
   * @var array $option
   *     structure that contains an option for a field in view
   */
  private static function processOption(&$option) {
    // checking if this table is part of the civicrm views integration
    $tableName = self::getCiviCRMtableName($option['table']);
    $prefix = $tableName ? self::getPrefix($tableName) : FALSE;
    if ($prefix) {
      $option['table'] = $tableName;
      $columns = self::getColumnsFromTable($prefix . $tableName);
      // if the table where the current field belongs exists does not have it
      // then we can search for similar fields in the same table and make replacements
      if (!isset($columns[$option['field']])) {
        $fieldNameBase = self::removeLastNumberOfString($option['field']);
        $pos = array_search($fieldNameBase, $columns);
        if ($pos !== FALSE) {
          $option['field'] = array_search($columns[$pos], $columns);
        }
      }
    }
  }

  /**
   * Return an existing CiviCRM table based on the base name of the table,
   * where "base name of the table" is the name of the table without the number
   * at the end
   *
   * @param string $tableName
   *     this is the table name exported by views
   *
   * @return string
   *     the name of the existing table if found or an empty string
   */
  private static function getCiviCRMtableName($tableName) {
    global $databases;
    static $tableNamesMap = [];
    // creates a map with table names without IDs to existing table names with IDs
    if (!$tableNamesMap) {
      $tablesWithIds = array_keys($databases['default']['default']['prefix']);
      foreach ($tablesWithIds as $tableWithId) {
        $tableNamesMap[self::removeLastNumberOfString($tableWithId)] = $tableWithId;
      }
    }

    $exportedTableBaseName = self::removeLastNumberOfString($tableName);
    $tableFound = isset($tableNamesMap[$exportedTableBaseName]);

    return $tableFound ? $tableNamesMap[$exportedTableBaseName] : '';
  }

  /**
   * Removes the number in end of a string
   * In this context that number is always separated by an underscore
   *
   * @param  string $string
   *     the string which could have underscores or not
   *
   * @return string
   *     the string without the number at the end,
   *     if no number found at the end returns the same string
   */
  private static function removeLastNumberOfString($string) {
    $pieces = explode('_', $string);
    $lastIndex = count($pieces) - 1;

    return $lastIndex > 0 && intval(array_pop($pieces)) ? implode('_', $pieces) : $string;
  }

  /**
   * To obtain the prefix for a table in the current installation
   *
   * @param string $tableName
   *     the name of the table
   *
   * @return string
   *     the prefix for the table
   */
  private static function getPrefix($tableName) {
    global $databases;

    return $databases['default']['default']['prefix'][$tableName];
  }

  /**
   * Gets the columns from a table keyed by the name of the column without
   * the sequential at the end
   *
   * @param string $table
   *     the name of the table
   *
   * @return array
   *     the names of the columns of the table
   */
  private static function getColumnsFromTable($table) {
    static $columns = [];
    if (!isset($columns[$table])) {
      $columns[$table] = [];
      $res = db_query('SHOW COLUMNS FROM ' . $table)->fetchAll();
      foreach ($res as $field) {
        $columns[$table][$field->Field] = self::removeLastNumberOfString($field->Field);
      }
    }

    return $columns[$table];
  }

}
