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
    // To convert start_date and end_date to timestamp
    // to correct filtering in views
    $dateFieldsToTimestamp = [
      'hrjc_role_hrjc_revision.role_start_date',
      'hrjc_role_hrjc_revision.role_end_date'
    ];
    civihr_employee_portal_views_date_fields_to_timestamp($view, $query, $dateFieldsToTimestamp);
  }
}
