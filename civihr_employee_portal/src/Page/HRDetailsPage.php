<?php

namespace Drupal\civihr_employee_portal\Page;

use Drupal\civihr_employee_portal\Helpers\CustomData\CustomEntityLinkHelper;

class HRDetailsPage {

  /**
   * Get variables for use in the hr-details page
   *
   * @return array
   */
  public function getVariables() {
    $dependantsView = views_embed_view(
      'emergency_contacts',
      'dependant_emergency_contact'
    );
    $emergencyContactsView = views_embed_view(
      'emergency_contacts',
      'non_dependant_emergency_contact'
    );

    return [
      'contactID' => $this->getCurrentContactID(),
      'emergencyContactsView' => $emergencyContactsView,
      'dependantsView' => $dependantsView,
    ];
  }

  /**
   * @return int|NULL
   */
  private function getCurrentContactID() {
    return \CRM_Core_Session::getLoggedInContactID();
  }

  /**
   * Gets the path this page uses.
   *
   * @return string
   */
  public static function getPath() {
    return 'hr-details';
  }
}
