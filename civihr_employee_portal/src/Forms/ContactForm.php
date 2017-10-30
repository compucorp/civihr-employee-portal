<?php

namespace Drupal\civihr_employee_portal\Forms;

use CRM_Contact_Form_Contact;
use Drupal\civihr_employee_portal\Helpers\ContactImagePathfinder;
use Drupal\civihr_employee_portal\Helpers\ImageResizer;

class ContactForm {

  /**
   * @param CRM_Contact_Form_Contact $form
   */
  public static function postProcess($form) {
    self::resizeImage($form);
    // If details are updated clear contact cache
    _civihr_employee_portal_clear_contact_cache($form->getContactID());
  }

  /**
   * Resize the contact's current image to fit profile pictures.
   *
   * @param CRM_Contact_Form_Contact $form
   */
  private static function resizeImage($form) {
    $contactID = $form->getContactID();
    $imageChanged = !empty($form->_submitFiles['image_URL']['name']);

    if (!$imageChanged) {
      return;
    }

    $imagePath = ContactImagePathfinder::getPath($contactID);
    ImageResizer::resizeForProfile($imagePath);
  }
}
