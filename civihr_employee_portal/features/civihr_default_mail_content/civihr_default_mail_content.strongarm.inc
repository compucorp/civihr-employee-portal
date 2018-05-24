<?php
/**
 * @file
 * civihr_default_mail_content.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function civihr_default_mail_content_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_body';
  $strongarm->value = '<p>
        A request has been made to reset your CiviHR password. To reset your password, please click the button below. The link will take you to your CiviHR user account page where you can enter a new password.
      </p>
      <p>
        Please note: the button below expires after one day and can only be used once. Nothing will happen if it\'s not used - your password will remain unchanged.
      </p>';
  $export['user_mail_password_reset_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_subject';
  $strongarm->value = 'Reset your CiviHR password';
  $export['user_mail_password_reset_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_body';
  $strongarm->value = '<p>
    A CiviHR user account has been created for you. Please set your password by clicking on the link below and following the instructions on the page.
  </p>
  <p>
    Once you have set your password, you can access CiviHR via the logon page at <a href="[site:url]">[site:url]</a> - your username is [user:name]</p>
  </p>
  <p>
    For instructions on how to use the system, please read the online <a href="https://civihr-documentation.readthedocs.io/en/latest/initial-setup-and-configuration/staff-managers-quickstart/">user guide</a>.
  </p>';
  $export['user_mail_register_admin_created_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_subject';
  $strongarm->value = 'Welcome to CiviHR';
  $export['user_mail_register_admin_created_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_body';
  $strongarm->value = '<p>
    A CiviHR user account has been created for you. Please set your password by clicking on the link below and following the instructions on the page.
  </p>
  <p>
    Once you have set your password, you can access CiviHR via the logon page at <a href="[site:url]">[site:url]</a> - your username is [user:name]</p>
  </p>
  <p>
    For instructions on how to use the system, please read the online <a href="https://civihr-documentation.readthedocs.io/en/latest/initial-setup-and-configuration/staff-managers-quickstart/">user guide</a>.
  </p>';
  $export['user_mail_status_activated_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_subject';
  $strongarm->value = 'Welcome to CiviHR';
  $export['user_mail_status_activated_subject'] = $strongarm;

  return $export;
}
