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
  $items['rules_absent_request_submit'] = entity_import('rules_config', '{ "rules_absent_request_submit" : {
      "LABEL" : "Absent request submit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "civihr_employee_portal" ],
      "ON" : { "absence_request_add" : [] },
      "DO" : [
        { "_new_absence_request_action" : {
            "roles" : { "value" : { "3" : "3" } },
            "absence_type" : [ "absence-type" ],
            "absence_details" : "Thanks [current-user:name] Test message from rules\\r\\nYou have applied for -\\u003E [absence-type:value]\\r\\nMessage you inserted is -\\u003E [absence-details:value]",
            "form_values" : [ "form-values" ]
          }
        },
        { "mail" : {
            "to" : "meszaros275@gmail.com",
            "subject" : "[absence-type:value] type",
            "message" : "Employee submitted data: [absence-details:value]",
            "from" : "greg@compucorp.co.uk",
            "language" : [ "current-user:language" ]
          }
        },
        { "drupal_message" : {
            "message" : "Absence request of type: [absence-type:value] submitted for approval\\r\\nDetails: [absence-details:value]",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
