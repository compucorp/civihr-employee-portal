<?php

namespace Drupal\civihr_employee_portal\Mail;

class AccountActivatedSystemMail extends AbstractDrupalSystemMail {
  /**
   * @return string
   */
  public function getTemplateName() {
    return 'user_account_activated.tpl';
  }

  /**
   * @param array $message
   *
   * @return array
   */
  public function getVariables($message) {
    $recipient = user_load_by_mail($message['to']);

    return [
      'invitationLink' => user_pass_reset_url($recipient),
      'currentDateTime' => new \DateTime(),
    ];
  }

}
