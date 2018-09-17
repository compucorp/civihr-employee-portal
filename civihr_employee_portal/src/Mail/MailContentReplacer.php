<?php

namespace Drupal\civihr_employee_portal\Mail;

class MailContentReplacer {

  /**
   * @var \CRM_Core_Smarty
   */
  private $smarty;

  /**
   * @param \CRM_Core_Smarty $smarty
   */
  public function __construct(\CRM_Core_Smarty $smarty) {
    $moduleRoot = drupal_get_path('module', 'civihr_employee_portal');
    $smarty->addTemplateDir($moduleRoot . '/templates/smarty');

    $this->smarty = $smarty;
  }

  /**
   * @param $message
   * @param AbstractDrupalSystemMail $replacement
   */
  public function replaceContent(
    &$message,
    AbstractDrupalSystemMail $replacement
  ) {
    $variables = $replacement->getVariables($message);
    $headers = $replacement->getHeaders();
    $templateName = $replacement->getTemplateName();

    // allow use of original content inside smarty template
    if (isset($message['body'][0])) {
      $variables['body'] = $message['body'][0];
    }

    $body = $this->smarty->fetchWith($templateName, $variables);

    $message['subject'] = $replacement->getSubject($message);
    $message['headers'] = array_merge($message['headers'], $headers);
    $message['body'] = [$body];
  }

}
