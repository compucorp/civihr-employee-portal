<?php

namespace Drupal\civihr_employee_portal\Forms;

class OnboardingWizardCustomizationForm {

  const LOGO_KEY = 'civihr_onboarding_organization_logo_fid';
  const WELCOME_TEXT_KEY = 'civihr_onboarding_welcome_text';
  const INTRODUCTION_TEXT_KEY = 'civihr_onboarding_intro_text';
  const CAROUSEL_OPTIONS_KEY = 'civihr_onboarding_carousel_options';
  const TEST_BUTTON_VALUE = 'Save and test onboarding wizard';

  /**
   * Builds an array representation of the onboarding customization settings
   * form which can be rendered.
   *
   * @return array
   */
  public function build() {
    $form = [];
    $form[self::LOGO_KEY] = $this->getLogoElement();
    $form[self::WELCOME_TEXT_KEY] = $this->getWelcomeTextElement();
    $form[self::INTRODUCTION_TEXT_KEY] = $this->getIntroElement();
    $form[self::CAROUSEL_OPTIONS_KEY] = $this->getCarouselElement();
    $form['civihr_onboarding_updates_group'] = $this->getUpdatesGroupElement();
    $form['actions']['cancel'] = $this->getCancelButton();
    $form['actions']['save-and-test'] = $this->getSaveAndTestButton();
    $form['#submit'][] = [$this, 'onSubmit'];

    $form = system_settings_form($form);

    $form = $this->adjustSaveButton($form);

    return $form;
  }

  /**
   * Handles some post-processing of the form such as saving images and
   * (un)publishing content.
   *
   * @param array $form
   * @param array $formState
   */
  public function onSubmit($form, &$formState) {
    if ($this->clickedCancel($formState)) {
      drupal_goto('/dashboard');
    }

    $this->saveLogo($formState);
    $this->updateCarouselContent($formState);

    // sends user to the first step of the onboarding wizard
    // which is just node edit page with custom theming
    if ($this->clickedSaveAndTest($formState)) {
      $userEditPath = '/user/' . user_uid_optional_load()->uid . '/edit';
      $queryParams = ['query' => [ 'testing' => 1 ]];
      drupal_goto($userEditPath, $queryParams);
    }
  }

  /**
   * @return array
   */
  private function getLogoElement() {
    return [
      '#type' => 'managed_file',
      '#title' => t('Upload organization logo for welcome screen'),
      '#weight' => 1,
      '#description' => '',
      '#default_value' => variable_get(self::LOGO_KEY),
      '#upload_location' => 'public://',
      '#upload_validators' => ['file_validate_extensions' => ['gif png jpg jpeg']]
    ];
  }

  /**
   * @return array
   */
  private function getWelcomeTextElement() {
    $welcomeText = variable_get(self::WELCOME_TEXT_KEY);

    return [
      '#type' => 'textarea',
      '#title' => t('Personalize your welcome text'),
      '#weight' => 2,
      '#description' => '',
      '#default_value' => $welcomeText,
    ];
  }

  /**
   * @return array
   */
  private function getIntroElement() {
    $introDescription = 'Customize the welcome introduction when a user lands '
      . 'on tasks and documents page at end of wizard.';

    return [
      '#type' => 'textarea',
      '#title' => t($introDescription),
      '#weight' => 4,
      '#description' => '',
      '#default_value' => variable_get(self::INTRODUCTION_TEXT_KEY),
    ];
  }

  /**
   * @return array
   */
  private function getCarouselElement() {
    /** @var \DatabaseStatementBase $query */
    $query = db_select('node', 'n')
      ->fields('n', ['nid', 'title', 'status'])
      ->condition('type', 'welcome_slideshow')
      ->execute();
    $carouselNodes = $query->fetchAll(\PDO::FETCH_ASSOC);
    $carouselOptions = array_column($carouselNodes, 'title', 'nid');
    // defaults is simple array of node IDs that are enabled
    $carouselDefaults = array_column($carouselNodes, 'status', 'nid');
    $carouselDefaults = array_keys(array_filter($carouselDefaults));

    return [
      '#type' => 'checkboxes',
      '#options' => $carouselOptions,
      '#weight' => 3,
      '#title' => t('Select which features are shown on the welcome carousel'),
      '#default_value' => $carouselDefaults,
    ];
  }

  /**
   * @return array
   */
  private function getCancelButton() {
    return [
      '#type' => 'submit',
      '#value' => t('Cancel'),
      '#weight' => 1,
    ];
  }

  /**
   * This is required as Drupal does not handle saving of files from a
   * system form
   * @see https://drupal.stackexchange.com/a/187043/75186
   *
   * @param array $formState
   */
  private function saveLogo(&$formState) {
    global $user;
    $file = file_load($formState['values'][self::LOGO_KEY]);
    if (!$file) {
      return;
    }

    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    variable_set(self::LOGO_KEY, $file->fid);
    file_usage_add($file, 'user', 'user', $user->uid);
  }

  /**
   * Publishes / unpublishes onboarding slideshow content based on their status.
   *
   * @param array $formState
   */
  private function updateCarouselContent($formState) {
    $nodeIDs = $formState['values'][self::CAROUSEL_OPTIONS_KEY];
    foreach ($nodeIDs as $nid => $value) {
      // if $value is not zero node should be published
      $isPublished = (int) ($value != 0);
      $node = node_load($nid);
      $node->status = $isPublished;
      node_save($node);
    }
  }

  /**
   * On form submission checks if the button pressed was "cancel"
   *
   * @param array $formState
   *
   * @return bool
   */
  private function clickedCancel($formState) {
    $clickedButton = \CRM_Utils_Array::value('clicked_button', $formState);

    return \CRM_Utils_Array::value('#value', $clickedButton) === t('Cancel');
  }

  /**
   * On form submission checks if the button pressed was "SaveAndTest"
   *
   * @param array $formState
   *
   * @return bool
   */
  private function clickedSaveAndTest($formState) {
    $clickedButton = \CRM_Utils_Array::value('clicked_button', $formState);

    return \CRM_Utils_Array::value('#value', $clickedButton) === t(self::TEST_BUTTON_VALUE);
  }

  /**
   * Sets the title and weight for the save button
   *
   * @param array $form
   *
   * @return array
   */
  private function adjustSaveButton($form) {
    $form['actions']['submit']['#value'] = ts('Save');
    $form['actions']['submit']['#weight'] = 0;

    return $form;
  }

  /**
   * Returns the structure for the button which saves and go to test
   *
   * @return array
   */
  private function getSaveAndTestButton() {
    return [
      '#type' => 'submit',
      '#value' => t(self::TEST_BUTTON_VALUE),
      '#weight' => -10,
    ];
  }

  /**
   * To validate the email which will receive the updates
   *
   * @param array $element
   *    The email input field
   * @param array $form_state
   *    the state of the onboarding form
   */
  public function validateEmail($element, &$form_state) {
    $value = $element['#value'];
    $send_updates = $form_state['input']['civihr_onboarding_send_updates'];
    // only validate if admin has chosen to send updates
    if ($send_updates) {
      // no empty value
      if ($value == '') {
        form_error($element, t('If you choose to receive updates then email field is mandatory'));
        // checking email address is valid
      } else if (!valid_email_address($value)) {
        form_error($element, t('The entered email address which will receive the updates is not valid'));
      }
    }
  }

  /**
   * Returns the elements for setting notifications on Onboarding Wizard Form
   *
   * @return array
   */
  private function getUpdatesGroupElement() {

    // Variable names
    $sendUpdatesKey = 'civihr_onboarding_send_updates';
    $emailToSendUpdatesKey = 'civihr_onboarding_email_to_send_updates';

    // Classes
    $bemBlock = 'civihr_onboarding_form';
    $toggleClass = $bemBlock.'--toggle';
    $updatesGroupClass = $bemBlock.'--container';
    $updatesGroupClassNoUpdates = $updatesGroupClass . '--no-updates';

    $element = [
      '#type' => 'container',
      '#weight' => 5,
      '#attributes' => [
        'class' => [
          $updatesGroupClass,
          // set this class as initial state to avoid unnecessary animation
          // when javascript runs and makes the email visible or not
          variable_get($sendUpdatesKey) ? '' : $updatesGroupClassNoUpdates,
        ]
      ],
      '#suffix' => '<hr/>',
    ];

    // snippet to add markup suport to style a toggle button
    $addToggleButton = '$("[name=\'' . $sendUpdatesKey . '\']").after("<span class=\'' . $toggleClass . '\'>toggle</span>");';

    // snippet to remove the initial state. At this point the email is already
    // visible or hidden, and the initial state must be removed to allow
    // styling changes on user interaction
    $removeInitialState = 'setTimeout(function() { $(".' . $updatesGroupClass . '").removeClass("' . $updatesGroupClassNoUpdates . '") }, 0);';

    $element['#attached']['js'][] = [
      'data' => 'jQuery(document).ready(function($) { ' . $addToggleButton . $removeInitialState . ' });',
      'type' => 'inline',
    ];

    $element[$sendUpdatesKey] = [
      '#type' => 'checkbox',
      '#title' => 'Send an email when someone updates their details',
      '#default_value' => variable_get($sendUpdatesKey),
    ];

    $element[$emailToSendUpdatesKey] = [
      '#type' => 'textfield',
      '#description' => 'The email which will receive the updates',
      '#default_value' => variable_get($emailToSendUpdatesKey),
      '#element_validate' => [[$this, 'validateEmail']],
      '#size' => 50,
      '#maxlength' => 128,
      '#attributes' => ['placeholder' => t('Please enter an email address')],
      '#states' => [
        'enabled' =>
          ['input[name="civihr_onboarding_send_updates"]' => ['checked' => TRUE]
        ],
      ],
    ];

    return $element;
  }
}
