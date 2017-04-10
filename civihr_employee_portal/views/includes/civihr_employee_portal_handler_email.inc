
<?php

/**
 * Custom field handler for emails, including multiple emails since
 * @see civicrm_handler_field_email only works with single mails
 */
class civihr_employee_portal_handler_email extends views_handler_field {
  /**
   * @param array $values
   *  All the values to be rendered by the view
   *
   * @return string
   *  The rendered emails separated by spaces
   */
  public function render($values) {
    $emails = $this->get_value($values);

    if (!$emails) {
      return '';
    }

    $this->sanitize_value($emails);
    $emails = array_filter(explode(' ', $emails));
    array_walk($emails, function (&$email) {
      $email = $this->linkify($email);
    });

    return implode(' ', $emails);
  }

  /**
   * @param string $email
   *  The email to be put in a link
   *
   * @return string
   *  The linked email
   */
  private function linkify($email) {
    return sprintf('<a href="mailto:%s">%s</a>', $email, $email);
  }
}
