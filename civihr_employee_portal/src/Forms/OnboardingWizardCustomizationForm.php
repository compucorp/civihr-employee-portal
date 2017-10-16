<?php

namespace Drupal\civihr_employee_portal\Forms;

class OnboardingWizardCustomizationForm {

  const LOGO_KEY = 'civihr_onboarding_organization_logo_fid';
  const WELCOME_TEXT_KEY = 'civihr_onboarding_welcome_text';
  const INTRODUCTION_TEXT_KEY = 'civihr_onboarding_intro_text';
  const CAROUSEL_OPTIONS_KEY = 'civihr_onboarding_carousel_options';

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
    $form['#submit'][] = [$this, 'onSubmit'];

    return system_settings_form($form);
  }

  /**
   * Handles some post-processing of the form such as saving images and
   * (un)publishing content.
   *
   * @param array $form
   * @param array $formState
   */
  public function onSubmit($form, &$formState) {
    $this->saveLogo($formState);
    $this->updateCarouselContent($formState);
  }

  /**
   * @return array
   */
  private function getLogoElement() {
    return [
      '#type' => 'managed_file',
      '#title' => t('Organization Logo'),
      '#weight' => 1,
      '#description' => t('Upload organization logo for welcome screen'),
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
      '#title' => t('Welcome Text'),
      '#weight' => 2,
      '#description' => t('Personalize your welcome text'),
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
      '#title' => t('Introduction'),
      '#weight' => 4,
      '#description' => t($introDescription),
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
}
