<?php

namespace Drupal\civihr_employee_portal\Forms;

use Drupal\civihr_employee_portal\Helpers\WebformHelper;
use Drupal\civihr_employee_portal\Service\ContactService;
use Drupal\civihr_employee_portal\Service\TaskCreationService;
use Drupal\civihr_employee_portal\Helpers\LinkProvider;

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
    $this->hackyFixForImageURL($contactID);
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
   * Remove empty components keys from $form['submitted'] as they break markup.
   * @see https://www.drupal.org/node/2916491
   *
   * @param array $form
   */
  private function removeEmptyKeys(&$form) {
    $original = \CRM_Utils_Array::value('submitted', $form);

    if (!$original) {
      return;
    }

    $form['submitted'] = array_filter($original);
  }

  /**
   * Adds help text to inform existing users of the system why they're being
   * asked to complete the onboarding form.
   *
   * @param array $form
   */
  private function addHelpText(&$form) {

    if (!isset($form['progressbar']['#page_num'])) {
      return;
    }

    $currentPage = $form['progressbar']['#page_num'];
    $isFirstPage = $currentPage === 1;

    if (!$isFirstPage) {
      return;
    }

    $helpText = $this->getHelpText();
    $skipButtonMarkup = $this->getSkipButtonMarkup();

    // create a 'markup' element to show message
    $progressBarWeight = $form['progressbar']['#weight'];
    $classes = 'alert alert-success';
    $style = 'display: inline-block';
    $format = '<div class="%s" style="%s"><p>%s</p>%s</div>';
    $markup = sprintf($format, $classes, $style, $helpText, $skipButtonMarkup);

    $form['submitted']['onboarding_explanation'] = [
      '#weight' => $progressBarWeight + 1,
      '#type' => 'markup',
      '#markup' => $markup,
      '#prefix' => '<div style="text-align: center;">',
      '#suffix' => '</div>'
    ];
  }

  /**
   * Unfortunately for us the contact profile page will expect an image URL
   * using the civicrm/file?photo=foo.jpg style. Since our contact images are
   * created using webform they won't match this so to avoid the warnings about
   * 'Undefined index: photo' we append photo=0 here.
   *
   * @see CRM_Utils_File::getImageURL
   *
   * @param int $contactID
   */
  private function hackyFixForImageURL($contactID) {
    $params = ['return' => 'image_URL', 'id' => $contactID];
    /** @var string $current */
    $current = civicrm_api3('Contact', 'getvalue', $params);

    if (empty($current)) {
      return;
    }

    // don't append to url if photo is already set
    parse_str(parse_url($current, PHP_URL_QUERY), $queryParts);
    if (isset($queryParts['photo'])) {
      return;
    }

    $operator = FALSE === strpos($current, '?') ? '?' : '&';
    $current .= $operator . 'photo=0';

    unset($params['return']);
    $params['image_URL']  = $current;
    civicrm_api3('Contact', 'create', $params);
  }

  /**
   * Gets the help text to show the user at the beginning of the onboarding form.
   *
   * @return string
   */
  private function getHelpText() {
    return 'Please start by entering your details below.'
      . '<br/><br/> You can always update these details later.';
  }

  /**
   * Gets the markup for the button to skip the onboarding form. The button
   * itself is wrapped in a link to the landing page for the user.
   *
   * @return string
   */
  private function getSkipButtonMarkup() {
    $classes = 'btn btn-default chr_onboarding-wizard_remind-me-later';
    $format = '<button type="button" class="%s">%s</button>';
    $buttonText = ts('Skip and Remind Me Later');
    $buttonMarkup = sprintf($format, $classes, $buttonText);

    global $user;
    $link = LinkProvider::getLandingPageLink($user);

    return sprintf('<a href="%s">%s</a>', $link, $buttonMarkup);
  }

}
