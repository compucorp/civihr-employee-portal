<?php

namespace Drupal\civihr_employee_portal\View;

class StaffDirectoryView extends AbstractView {

  /**
   * @var string
   */
  protected static $name = 'civihr_staff_directory';

  /**
   * @inheritdoc
   */
  public function alter($view, $query) {
    $queryParts = [];
    $this->getWhereFields($query->where, $queryParts);
    $departmentField = 'hrjc_role_hrjc_revision.role_department';
    $roleEndField = 'hrjc_role_hrjc_revision.role_end_date';

    // if department is set we must limit to only current roles
    if (!empty($queryParts[$departmentField])) {
      $group = $query->set_where_group('OR'); // add a new WHERE group
      $query->add_where($group, $roleEndField, date('Y-m-d'), '>=');
      $query->add_where($group, $roleEndField, NULL, 'IS');
    }
  }
}
