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
    $titleField = 'hrjc_role_hrjc_revision.role_title';
    $roleEndField = 'hrjc_role_hrjc_revision.role_end_date';
    $roleStartField = 'hrjc_role_hrjc_revision.role_start_date';

    // if department or title is set we must limit to only current roles
    if (!empty($queryParts[$departmentField]) || !empty($queryParts[$titleField])) {
      $roleEndGroup = $query->set_where_group('OR'); // add a new WHERE group
      $query->add_where($roleEndGroup, $roleEndField, date('Y-m-d'), '>=');
      $query->add_where($roleEndGroup, $roleEndField, NULL, 'IS');
      $roleStartGroup = $query->set_where_group();
      $query->add_where($roleStartGroup, $roleStartField, date('Y-m-d'), '<=');
    }
  }
}
