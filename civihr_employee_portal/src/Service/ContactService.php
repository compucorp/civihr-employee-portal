<?php

namespace Drupal\civihr_employee_portal\Service;

class ContactService {

  /**
   * @param string $role
   *   The name of the target role
   *
   * @return array
   *   An array of contact IDs with that role
   */
  public static function getContactIDsWithRole($role) {
    $role = user_role_load_by_name($role);

    if (!$role) {
      return [];
    }

    $rid = $role->rid;

    $uids = db_select('users_roles', 'ur')
      ->fields('ur', ['uid'])
      ->condition('ur.rid', $rid)
      ->execute()->fetchCol();

    if (empty($uids)) {
      return [];
    }

    $result = civicrm_api3('UFMatch', 'get', ['uf_id' => ['IN' => $uids]]);

    if ($result['count'] < 1) {
      return [];
    }

    return array_column($result['values'], 'contact_id');
  }

  /**
   * Gets all line managers for the provided contact ID.
   *
   * @param int $contactID
   *
   * @return array
   */
  public static function getLineManagerIDs($contactID) {
    $managerRelationshipName = 'Line manager is';

    $lineManagerType = civicrm_api3('RelationshipType', 'get', [
      'name_a_b' => $managerRelationshipName,
    ]);

    if ($lineManagerType['count'] != 1) {
      return [];
    }
    $lineManagerTypeId = array_shift($lineManagerType['values'])['id'];

    $relationships = civicrm_api3('Relationship', 'get', [
      'relationship_type_id' => $lineManagerTypeId,
      'contact_id_a' => $contactID,
      'is_active' => 1,
    ]);

    return array_column($relationships['values'], 'contact_id_b');
  }

  /**
   * Fetch the provided contact's work email
   *
   * @param int $contactId
   *
   * @return string
   */
  public static function getContactWorkEmail($contactId) {
    $contactEmailRes = civicrm_api3('Email', 'get', [
      'contact_id' => $contactId,
      'location_type_id' => 'Work',
      'options' => ['limit' => 1],
      'sequential' => 1,
    ]);

    if ($contactEmailRes['count'] == 1) {
      return $contactEmailRes['values'][0]['email'];
    }

    return '';
  }

  /**
   * Fetch an absolute link to the contact's profile page
   *
   * @param int $contactId
   *
   * @return string
   */
  public static function getLinkToContactProfile($contactId) {
    $profilePath = 'civicrm/contact/view';
    $queryParams = ['cid' => $contactId];
    $profileLink = \CRM_Utils_System::url($profilePath, $queryParams, TRUE);

    return $profileLink;
  }

}
