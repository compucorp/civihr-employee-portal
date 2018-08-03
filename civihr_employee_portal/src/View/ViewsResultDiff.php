<?php

namespace Drupal\civihr_employee_portal\View;

/**
 * ViewsResultDiff captures differences between
 * views in different moments, like when a a form is being
 * submitted: before saving and after saving data. Once the
 * oldData and the newData is obtained it can compute the
 * differences.
 */
class ViewsResultDiff {

  /**
   * An array of relational arrays which will hold the configuration of the views
   * that will be stored and compared.
   * [ setting1, .., settingN ] where settingX is a relational array
   *
   * If "view" key is defined the current array could define the settings for a single view
   *
   * If "group" key is defined its value is another array which can define multiple views
   * using the structure above.
   * The result of the diffs for these views will be joined and appear as one view.
   *
   * In settings array where "view" key is defined:
   * - the value for "view" key must be the view name.
   * - key "displayId": to define a specific display on a view
   * - key "args": (optional) an array of arguments that will be sent to the view
   * - key "exposedFilters": (optional) a relational array to manipulate exposed filters
   * - key "fieldAsKeyForRows": (optional) the id for the field which will serve as id for rows
   *       setting different key using the value of a field which
   *       identifies a row. Helpful when comparing view with multiple
   *       rows to handle deletions and insertions correctly.
   *       This field will be removed from the row by default.
   *
   * In the array where "group" key is defined:
   * - The value will be an array of "views" settings, as defined above
   *
   * @var array
   */
  public $viewsSettings = [];

  /**
   * usually will hold data after a form submission but previous to save or insert
   *
   * @var array
   */
  public $newData = [];

  /**
   * usually will hold data after a form submission but previous to save or insert
   *
   * @var array
   */
  public $oldData = [];

  /**
   * the difference between $newData and $oldData once comparison is made
   *
   * @var array
   */
  public $changes = [];

  /**
   * ViewsResultDiff constructor
   * initialises viewSettings property
   *
   * @param array $viewsSettings
   *     to initialize viewSettings property
   */
  function __construct($viewsSettings = []) {
    // Normalising view settings structure
    foreach ($viewsSettings as $index=>&$value ) {
      if (isset($value['view'])) {
        $value['args'] = !empty($value['args']) ? $value['args'] : [];
        $value['displayId'] = !empty($value['displayId']) ? $value['displayId'] : 'default';
      } else if (isset($value['group'])) {
        foreach ($value['group'] as &$viewSetting) {
          $viewSetting['args'] = !empty($viewSetting['args']) ? $viewSetting['args'] : [];
          $viewSetting['displayId'] = !empty($viewSetting['displayId']) ? $viewSetting['displayId'] : 'default';
        }
      }
    }
    $this->viewsSettings = $viewsSettings;
  }

  /**
   * To compare the results of 2 $rows
   *
   * @param  array $newRow
   *     a row from a recent view result
   * @param  array $oldRow
   *     a row from a previous view result
   *
   * @return array
   *     the difference between both rows
   */
  private function diffViewsRow($newRow, $oldRow) {
    // Normalising new row to get better diffs
    foreach ($oldRow as $key => $value) {
      if (!isset($newRow[$key])) {
        $newRow[$key] = '';
      }
    }
    return array_diff_assoc($newRow, $oldRow);
  }

  /**
   * To compare results of 2 views
   *
   * @param  array $newData
   *     a recent result from view
   * @param  array $oldData
   *     previous result from view
   *
   * @return array
   *     the difference
   */
  private function diffViewsData($newData, $oldData) {
    $dataDiff = [];

    // Normalising new data to get better diffs
    foreach ($oldData as $index => $value) {
      if (!isset($newData[$index])) {
        $newData[$index] = [];
      }
    }
    // Normalising old data to get better diffs
    foreach ($newData as $index => $value) {
      if (!isset($oldData[$index])) {
        $oldData[$index] = [];
      }
    }

    foreach ($oldData as $index => $value) {
      $diff = $this->diffViewsRow($newData[$index], $oldData[$index]);
      if ($diff) {
        $dataDiff[$index] = $diff;
      }
    }
    return $dataDiff;
  }

  /**
   * Obtain $this->changes comparing $this->oldData with $this->newData
   * @param  array $oldData
   *     previous result from view
   * @param  array $newData
   *     a recent result from view
   * @param  array $changes
   *     the difference between $oldData and $newData
   *
   * @return stdClass $this
   */
  private function compareDataRecursive(&$oldData, &$newData, &$changes) {
    static $i=-1;
    $changes = !$i++ ? [] : $changes;

    foreach ($oldData as $key => $dummyVar) {
      // for groups we apply this function recursively
      if (isset($oldData[$key]['group'])) {
        $changes[] = ['group' => []];
        $lastIndexOfChanges = count($changes) - 1;
        $this->compareDataRecursive(
          $oldData[$key]['group'],
          $newData[$key]['group'],
          $changes[$lastIndexOfChanges]['group']
        );
        // if there are no changes then this group must be deleted
        if (!$changes[$lastIndexOfChanges]['group']) {
          unset($changes[$lastIndexOfChanges]);
        }
      } elseif (isset($oldData[$key]['view'])) {
        $viewName = $oldData[$key]['view'];
        $title = $oldData[$key]['title'];
        // getting the diff of the result of 2 different views
        $diff = $this->diffViewsData(
          $newData[$key]['data'],
          $oldData[$key]['data']
        );
        // store the diff only if something has changed
        if ($diff) {
          $changes[] = ['view' => $viewName, 'diff' => $diff, 'title' => $title ];
        }
      }
    }
    $i--;
  }

  /**
   * To compare data generated between 2 different moments
   *
   * @return ViewsResultDiff
   */
  public function compareData() {
    $this->compareDataRecursive(
      $this->oldData,
      $this->newData,
      $this->changes
    );
    return $this;
  }

  /**
   * To retrieve the current data of the views configured to diff
   * this function will be called by storeNewData or storeOldData
   * to be able to store the data produced by the views for later
   * comparison
   *
   * @return array
   *     The data retrieved from one of more views,
   *     joined on specific fields for later comparison
   */
  private function getCurrentData($settings = null) {
    $data = [];
    $settings = !$settings ? $this->viewsSettings : $settings;

    foreach ($settings as $setting) {
      // if it is a group then apply recursion
      if (isset($setting['group'])) {
        $data[] = ['group' => $this->getCurrentData($setting['group'])];
      } else if (isset($setting['view'])) {
        // if it is a view it must be previewed to get the results
        $view = views_get_view($setting['view']);

        // Setting Exposed Filters
        // backing up $_GET
        $_GETbkp = $_GET;
        // add exposed filter keys to $_GET
        $_GET = isset($setting['exposedFilters']) ? $setting['exposedFilters'] + $_GET : $_GET ;
        $view->preview($setting['displayId'], $setting['args']);
        // reverting $_GET to backed state once the view is executed
        $_GET = $_GETbkp;

        // views which are empty will not have fieldsMarkup
        $view->fieldsMarkup = isset($view->fieldsMarkup) ? $view->fieldsMarkup : [];
        $currentViewData = [];
        $fieldKeyForRows = isset($setting['fieldAsKeyForRows']) ? $setting['fieldAsKeyForRows'] : false;
        // storing the markup for every row
        foreach ($view->fieldsMarkup as $i => $row) {
          // setting different key using the value of a field which identifies
          // a row. Helpful when comparing view with multiple rows to handle
          // deletions and insertions correctly
          $index = $fieldKeyForRows ? $row[$fieldKeyForRows]->content : $i;
          $currentViewData[$index] = [];
          // storing the markup for every field
          foreach ($row as $key => $fieldOutput) {
            if ($key === $fieldKeyForRows) {
              continue;
            }
            $fieldKey = $fieldOutput->label_html;
            $currentViewData[$index][$fieldKey] = $fieldOutput->content;
          }
        }
        $data[] = [
          'view' => $setting['view'],
          'data' => $currentViewData,
          'title' => $view->get_title()
        ];
      }
    }
    return $data;
  }

  /**
   * Stores data on property newData
   *
   * @return ViewsResultDiff
   */
  public function storeNewData() {
    $this->newData = $this->getCurrentData();
    return $this;
  }

  /**
   * Stores data on property oldData
   *
   * @return ViewsResultDiff
   */
  public function storeOldData() {
    $this->oldData = $this->getCurrentData();
    return $this;
  }
}
