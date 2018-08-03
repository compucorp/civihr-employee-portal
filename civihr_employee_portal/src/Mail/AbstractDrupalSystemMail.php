<?php

namespace Drupal\civihr_employee_portal\Mail;

abstract class AbstractDrupalSystemMail {
  /**
   * Returns the name of the template for this mail
   *
   * @return string
   *     the name of the template
   */
  protected abstract function getTemplateName();

  /**
   * Set variables that will be passed to the template
   *
   * @return AbstractDrupalSystemMail
   *     this, an instance of the the same Class
   */
  protected abstract function buildVariables();

  /**
   * Template system to build notifications
   *
   * @var \CRM_Core_Smarty
   */
  static protected $smarty;

  /**
   * Message variable passed by reference that will be used to send the email by Drupal
   * @var array
   */
  protected $message;

  /**
   * Multiple parameters that will be used during the build of a notification
   *
   * @var array
   */
  protected $params;

  /**
   * Structured data that is build to be passed to notification templates
   *
   * @var array
   */
  protected $variables;

  /**
   * Initializes properties
   *
   * @param array $message
   *    the $message variable from a mail function passed by reference
   *
   * @param array $params
   *    initial parameters to build notifications
   */
  public function __construct(&$message = null, $params = []) {
    $this->message = &$message;
    $this->params = $params;

    $message['module'] = 'civihr_employee_portal';
    if (isset($params['key'])) {
      $message['key'] = $params['key'];
    }
    if (isset($params['subject'])) {
      $message['subject'] = $params['subject'];
    }
  }

  public static function init($templatePath) {
    self::$smarty = \CRM_Core_Smarty::singleton();
    self::$smarty->addTemplateDir($templatePath);
  }

  /**
   * Creates headers and body for a notification
   *
   * @return AbstractDrupalSystemMail
   *     this, the same instance
   */
  public function processMessage() {
    $this->buildVariables()->buildHeaders()->buildBody();
    return $this;
  }

  /**
   * Build body for a notification
   *
  * @return AbstractDrupalSystemMail
   *     this, the same instance
   */
  protected function buildBody() {
    $this->message['body'] = [self::$smarty->fetchWith($this->getTemplateName(), $this->variables)];
    return $this;
  }

  /**
   * Build headers for a notification
   *
   * @return AbstractDrupalSystemMail
   *     this, the same instance
   */
  protected function buildHeaders() {
    $headers = [
      'MIME-Version' => '1.0',
      'Content-Type' => 'text/html; charset=UTF-8;'
    ];
    $this->message['headers'] = array_merge($this->message['headers'], $headers);
    return $this;
  }
}

AbstractDrupalSystemMail::init(
  DRUPAL_ROOT . '/' . drupal_get_path('module', 'civihr_employee_portal') . '/templates/smarty'
);
