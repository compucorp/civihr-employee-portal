<?php

namespace Drupal\civihr_employee_portal\Mail;

class AccountActivatedSystemMail extends AbstractDrupalSystemMail {
  /**
   * Returns the name of the template for this mail
   *
   * @return string
   *     the name of the template
   */
  protected function getTemplateName() {
    return 'user_account_activated.tpl';
  }

  /**
   * Set variables that will be passed to the template
   *
   * @return AccountActivatedSystemMail
   *     this, the instance of the the same Class
   */
  public function buildVariables() {
    $variables = [];
    $recipient = user_load_by_mail($this->message['to']);
    $variables['invitationLink'] = user_pass_reset_url($recipient);
    $variables['currentDateTime'] = new \DateTime();
    $variables['body'] = $this->message['body'][0];
    $this->variables = $variables;
    return $this;
  }
}
