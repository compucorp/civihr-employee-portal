<?php

namespace Drupal\civihr_employee_portal\View;

class MyDetails_MyRoleView extends AbstractView {

  /**
   * @var string
   */
  protected static $name = 'MyDetails_MyRole';

  /**
   * @inheritdoc
   * To alter specific fields which store dates in format Y-m-d
   * The dates are converted to Unix Timestamp so they can be used
   * from the views interface as filters
   */
  public function alter($view, $query) {
    $dateFieldsToTimestamp = [
      'hrjc_role_hrjc_revision.role_start_date',
      'hrjc_role_hrjc_revision.role_end_date'
    ];
    civihr_employee_portal_views_date_fields_to_timestamp($view, $query, $dateFieldsToTimestamp);
  }
}
