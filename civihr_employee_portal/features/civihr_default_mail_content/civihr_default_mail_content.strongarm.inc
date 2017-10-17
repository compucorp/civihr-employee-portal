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
  $strongarm->value = '<h2>Follow these instructions to reset your password</h2>
      <p>
        A request has been made to reset your CiviHR password. To reset your password, please click the button below. The link will take you to the system’s user page where you can enter a new password into the password fields. Once saved, this will be your new password to login to the site.
      </p>
      <p>
        After setting your password, you will be able to login to CiviHR  by using the following credentials:
      </p>
      <p>
        Username: [user:name]
        <br/>
        Password: (the password you have just created)
      </p>
      <p>
        Please note: The button below can only be used once to login. It expires after one day. Nothing will happen if it\'s not used - your password will not change if you do not reset it.
      </p>
      <p>
        Best wishes,
        <br/>
        The CiviHR Team
      </p>';
  $export['user_mail_password_reset_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_body';
  $strongarm->value = '<h2>Please create a password</h2>
  <p>
    Hello, and welcome to CiviHR, the open-source HR solution for non-profit organisations.
  </p>
  <p>
    You are receiving this email because a site administrator has setup a user account in your name. You will need to change the designated password to something private and secure before you begin using the system.
  </p>
  <p>
    Please login by clicking the button below. This will take you to your user page where you can enter a new password. Once saved, this will be your password to login to the site.  If you forget your password, you can reset it at any time using the password reset link, available on the CiviHR login page.
  </p>
  <p>
    After setting your password, you will be able to login to CiviHR  by using the following credentials:
  </p>
  <p>
    Username: [user:name]
    <br/>
    Password: (the password you have just created)
  </p>
  <p>
    You system can be accessed through this address:[site:url]. Please bookmark this page.
    We hope you enjoy using CiviHR. For instructions on how to use the system, please read the online user guide.
  </p>
  <p>
    Best wishes,
    <br/>
    The CiviHR Team
  </p>';
  $export['user_mail_register_admin_created_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_body';
  $strongarm->value = '<h2>Please create a password</h2>
  <p>
    Hello, and welcome to CiviHR, the open-source HR solution for non-profit organisations.
  </p>
  <p>
    You are receiving this email because a site administrator has setup a user account in your name. You will need to change the designated password to something private and secure before you begin using the system.
  </p>
  <p>
    Please login by clicking the button below. This will take you to your user page where you can enter a new password. Once saved, this will be your password to login to the site.  If you forget your password, you can reset it at any time using the password reset link, available on the CiviHR login page.
  </p>
  <p>
    After setting your password, you will be able to login to CiviHR  by using the following credentials:
  </p>
  <p>
    Username: [user:name]
    <br/>
    Password: (the password you have just created)
  </p>
  <p>
    You system can be accessed through this address:[site:url]. Please bookmark this page.
    We hope you enjoy using CiviHR. For instructions on how to use the system, please read the online user guide.
  </p>
  <p>
    Best wishes,
    <br/>
    The CiviHR Team
  </p>';
  $export['user_mail_status_activated_body'] = $strongarm;

  return $export;
}
