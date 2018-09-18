<?php

namespace Drupal\civihr_employee_portal\Mail;

abstract class AbstractDrupalSystemMail {

  /**
   * @return string
   */
  abstract public function getTemplateName();

  /**
   * @param array $message
   *
   * @return array
   */
  public function getVariables($message) {
    return [];
  }

  /**
   * @param array $message
   *
   * @return string
   */
  public function getSubject($message) {
    return $message['subject'];
  }

  /**
   * @return array
   */
  public function getHeaders() {
    return $headers = [
      'MIME-Version' => '1.0',
      'Content-Type' => 'text/html; charset=UTF-8;'
    ];
  }

}
