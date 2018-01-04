<?php
/**
 * @file
 * civihr_employee_portal_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function civihr_employee_portal_features_default_rules_configuration() {
  $items = array();
  $items['rules_employee_access_request'] = entity_import('rules_config', '{ "rules_employee_access_request" : {
      "LABEL" : "Employee access request",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail", "civihr_employee_portal" ],
      "ON" : { "user_and_civi_contact_added" : [] },
      "DO" : [
        { "mimemail_to_users_of_role" : {
            "key" : "employee-access-request",
            "roles" : { "value" : { "55120974" : "55120974" } },
            "active" : "1",
            "from_mail" : "[site:mail]",
            "subject" : "Employee Access Request",
            "body" : "User [current-user:contact_display_name] with username: [current-user:name] ([current-user:mail]) has requested access to your CiviHR Self Service Portal.\\r\\n\\u003Ca href = \\u0027[site:url]admin\\/people\\u0027\\u003EPlease login to activate this account and assign appropriate access level\\u003C\\/a\\u003E.",
            "plaintext" : "User [current-user:contact_display_name] with username: [current-user:name] ([current-user:mail]) has requested access to your CiviHR Self Service Portal.\\r\\n\\u003Ca href = \\u0027[site:url]admin\\/people\\u0027\\u003EPlease login to activate this account and assign appropriate access level\\u003C\\/a\\u003E.",
            "language_user" : "1",
            "language" : [ "current-user:language" ]
          }
        }
      ]
    }
  }');
  return $items;
}
