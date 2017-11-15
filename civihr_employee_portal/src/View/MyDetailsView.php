<?php

namespace Drupal\civihr_employee_portal\View;

class MyDetailsView extends AbstractView {

  /**
   * @var string
   */
  protected static $name = 'my_details_block';

  /**
   * This is responsible for altering the query for the my details block to
   * use data from only active job contracts. It does this by adding an extra
   * join condition on the job contract revision table.
   *
   * @inheritdoc
   */
  public function alter(&$view, &$query) {
    // Only applies to my_details_block display
    if ($view->current_display !== self::$name) {
      return;
    }

    $currentContactID = \CRM_Core_Session::getLoggedInContactID();
    $contractID = $this->getCurrentContractID($currentContactID);

    // If no current contract then add an impossible join condition
    $filterID = $contractID ? $contractID : 0;

    $revisionTable = 'hrjc_revision';
    $contactTable = 'civicrm_contact';
    $joinAlias = sprintf('%s_%s', $revisionTable, $contactTable);
    $joinCondition = sprintf('%s.jobcontract_id = %d', $joinAlias, $filterID);

    // Set the condition in the query
    $join = &$query->table_queue[$joinAlias]['join'];
    $join->extra = $joinCondition;
  }

  /**
   * Gets the current contract ID for the given contact ID
   *
   * @param int $contactID
   *
   * @return int|null
   */
  private function getCurrentContractID($contactID) {
    $result = civicrm_api3('HRJobContract', 'getcurrentcontract', [
      'contact_id' => $contactID,
    ]);

    // God knows why but this result is a stdClass and count is always "1"
    if (isset($result['values']->contract_id)) {
      return $result['values']->contract_id;
    }

    return NULL;
  }
}
