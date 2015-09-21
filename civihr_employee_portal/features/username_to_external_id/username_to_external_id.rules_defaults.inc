<?php
/**
 * @file
 * username_to_external_id.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function username_to_external_id_default_rules_configuration() {
  $items = array();
  $items['rules_user_reflect_external_id'] = entity_import('rules_config', '{ "rules_user_reflect_external_id" : {
      "LABEL" : "User create - reflect External ID",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "external ID", "user created" ],
      "REQUIRES" : [ "civicrm", "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "civicrm_entity_user_exists" : { "civicrm_contact" : [ "account:civicrm-contact" ] } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "account:civicrm-contact:external-identifier" ],
            "value" : "[account:name]"
          }
        }
      ]
    }
  }');
  $items['rules_user_update_reflect_external_id'] = entity_import('rules_config', '{ "rules_user_update_reflect_external_id" : {
      "LABEL" : "User update - reflect External ID",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "external ID", "user updated" ],
      "REQUIRES" : [ "civicrm", "rules" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "civicrm_entity_user_exists" : { "civicrm_contact" : [ "account:civicrm-contact" ] } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "account:civicrm-contact:external-identifier" ],
            "value" : "[account:name]"
          }
        }
      ]
    }
  }');
  return $items;
}
