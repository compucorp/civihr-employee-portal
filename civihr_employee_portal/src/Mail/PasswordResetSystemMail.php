<?php

namespace Drupal\civihr_employee_portal\Mail;

class PasswordResetSystemMail extends AbstractDrupalSystemMail {
  /**
   * @return string
   */
  public function getTemplateName() {
    return 'user_password_reset.tpl';
  }

  /**
   * @param array $message
   *
   * @return array
   */
  public function getVariables($message) {
    $recipient = user_load_by_mail($message['to']);

    return [
      'resetLink' => user_pass_reset_url($recipient),
      'currentDateTime' => new \DateTime(),
      'username' => $recipient->name,
    ];
  }

}
