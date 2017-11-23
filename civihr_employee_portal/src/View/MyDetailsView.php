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
  public function alter($view, $query) {
    // Only applies to my_details_block display
    if ($view->current_display !== self::$name) {
      return;
    }

    $currentContactID = \CRM_Core_Session::getLoggedInContactID();
    $revision = $this->getCurrentRevision($currentContactID);

    // If no current contract then add an impossible join condition
    $contractID = $revision ? $revision['jobcontract_id'] : 0;
    $roleRevisionID = $revision ? $revision['role_revision_id'] : 0;
    $detailsRevisionID = $revision ? $revision['details_revision_id'] : 0;

    $revisionAlias = 'hrjc_revision_civicrm_contact';

    // Single condition for revision ID would be better, but revision ID does
    // not exist in hrjc_details
    $this->addJoinCondition($query, $revisionAlias, 'jobcontract_id', $contractID);
    $this->addJoinCondition($query, $revisionAlias, 'role_revision_id', $roleRevisionID);
    $this->addJoinCondition($query, $revisionAlias, 'details_revision_id', $detailsRevisionID);
  }

  /**
   * Gets the current contract ID for the given contact ID
   *
   * @param int $contactID
   *
   * @return int|null
   */
  private function getCurrentRevision($contactID) {
    $contract = civicrm_api3('HRJobContract', 'getcurrentcontract', [
      'contact_id' => $contactID,
    ]);

    // God knows why but this result is a stdClass
    if (!isset($contract['values']->contract_id)) {
      return NULL;
    }

    $contractID = $contract['values']->contract_id;

    return civicrm_api3('HRJobContractRevision', 'getcurrentrevision', [
      'jobcontract_id' => $contractID,
    ])['values'];
  }

  /**
   * Adds an extra join condition for a certain table alias.
   *
   * @param \views_plugin_query_default $query
   * @param string $joinAlias
   * @param string $field
   * @param int $id
   */
  private function addJoinCondition($query, $joinAlias, $field, $id) {
    $joinCondition = sprintf('%s.%s = %d', $joinAlias, $field, $id);
    $join = $query->table_queue[$joinAlias]['join'];

    if (empty($join->extra)) {
      $join->extra = $joinCondition;
    } else {
      $join->extra = $join->extra . ' AND ' . $joinCondition;
    }
  }
}
