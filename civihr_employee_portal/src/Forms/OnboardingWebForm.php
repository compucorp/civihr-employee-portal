<?php

namespace Drupal\civihr_employee_portal\Forms;

use Drupal\civihr_employee_portal\Helpers\WebformHelper;
use Drupal\civihr_employee_portal\Service\ContactService;
use Drupal\civihr_employee_portal\Service\TaskCreationService;

class OnboardingWebForm {

  const STATUS_APPLYING = 1;
  const NAME = 'Welcome to CiviHR';

  /**
   * Some required processing such as clearing caches and creating tasks.
   *
   * @param \stdClass $node
   *   The webform node
   * @param \stdClass $values
   *   The submitted values
   */
  public function onSubmit($node, $values) {
    $contactID = \CRM_Core_Session::singleton()->getLoggedInContactID();

    // clear contact data cache used in get_civihr_contact_data()
    cache_clear_all('civihr_contact_data_' . $contactID, 'cache');

    if ($this->isApplyingForSSN($node, $values)) {
      $this->createReminderTask($contactID);
    }

    $this->setWorkEmailAsPrimary($node, $values, $contactID);
  }

  /**
   * Checks the application status for the "Is applying for NI/SSN" field
   *
   * @param \stdClass $node
   * @param \stdClass $values
   *
   * @return bool
   */
  private function isApplyingForSSN($node, $values) {
    $title = 'I am currently applying for a NI/ SSN';
    $status = WebformHelper::getValueByTitle($node, $values, $title);
    $uid = property_exists($values, 'uid') ? $values->uid : NULL;

    if (NULL === $uid) {
      return FALSE;
    }

    return $status == self::STATUS_APPLYING;
  }

  /**
   * Creates a reminder task for the line manager to check if NI/SSN application
   * is still in progress 1 month later.
   *
   * @param int $contactID
   *   The logged in contact ID
   */
  private function createReminderTask($contactID) {
    $taskTypeName = 'Check on contact for NI/SSN';
    $date = new \DateTime('+1 months');

    $assigneeIDs = ContactService::getLineManagerIDs($contactID);
    if (empty($assigneeIDs)) {
      $assigneeIDs = ContactService::getContactIDsWithRole('CIVIHR_ADMIN');
    }

    $assigneeIDs = array_diff($assigneeIDs, [$contactID]); // remove self
    $assigneeID = current($assigneeIDs); // only one assignee, first in line

    if ($assigneeID) {
      TaskCreationService::create($contactID, [$assigneeID], $taskTypeName, $date);
    }
  }

  /**
   * If work email is set in the webform it will have already been created  at
   * this point, but we need to make it primary.
   *
   * @param \stdClass $node
   * @param \stdClass $values
   * @param int $contactID
   */
  private function setWorkEmailAsPrimary($node, $values, $contactID) {
    $workEmail = WebformHelper::getValueByTitle($node, $values, 'Work Email');

    // it wasn't set in form
    if (!$workEmail) {
      return;
    }

    $params = [
      'contact_id' => $contactID,
      'email' => $workEmail,
      'location_type_id' => 'Work'
    ];

    $mail = civicrm_api3('Email', 'get', $params);

    if ($mail['count'] != 1) {
      return;
    }

    $mail = array_shift($mail['values']);
    $params['is_primary'] = 1;
    $params['id'] = $mail['id'];

    civicrm_api3('Email', 'create', $params);
  }

  /**
   * Handles all alterations from hook_form_alter().
   *
   * @param array $form
   */
  public function alter(&$form) {
    $this->removeEmptyKeys($form);
    $this->addHelpText($form);
  }

  /**
   * Remove empty components keys from $form['submitted'] as they break markup.
   * @see https://www.drupal.org/node/2916491
   *
   * @param array $form
   */
  private function removeEmptyKeys(&$form) {
    $form['submitted'] = array_filter(\CRM_Utils_Array::value('submitted', $form));
  }

  /**
   * Adds help text to inform existing users of the system why they're being
   * asked to complete the onboarding form.
   *
   * @param array $form
   */
  private function addHelpText(&$form) {
    $helpText = 'CiviHR users can now complete a quick and easy'
      . ' wizard to enter their details into the system.<br/>Any information '
      . 'that you have already provided to the system will be shown in the '
      . 'wizard and can be updated.';

    $currentPage = $form['progressbar']['#page_num'];
    $isFirstPage = $currentPage === 1;

    if (!$isFirstPage || $this->userCreatedAfterOnboardingReleased()) {
      return;
    }

    // create a 'markup' element to show message
    $progressBarWeight = $form['progressbar']['#weight'];
    $classes = 'alert alert-success';
    $style = 'display: inline-block';
    $format = '<p class="%s" style="%s">%s</p>';
    $markup = sprintf($format, $classes, $style, $helpText);

    $form['submitted']['onboarding_explanation'] = [
      '#weight' => $progressBarWeight + 1,
      '#type' => 'markup',
      '#markup' => $markup,
      '#prefix' => '<div style="text-align: center;">',
      '#suffix' => '</div>'
    ];
  }

  /**
   * Checks if the current logged in user was created after the onboarding
   * feature was released.
   *
   * @return bool
   */
  private function userCreatedAfterOnboardingReleased() {
    global $user;
    $onboardingForm = WebformHelper::findOneByTitle(self::NAME);
    $onboardingRelease = $onboardingForm->created;

    return $user->created > $onboardingRelease;
  }

}
