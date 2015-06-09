<?php

namespace Drupal\civihr_employee_portal\Helpers;

class HelperClass {
    
    /**
     * Array merge by array values (matched by ID)
     */
    public static function array_merge_callback($contacts, $job_contracts, $predicate) {
        $result = array();

        foreach ($contacts as $contact_array) {

            // No match found as default
            $result_contact = FALSE;

            foreach ($job_contracts as $job_contract_array) {
                if ($predicate($contact_array, $job_contract_array)) {
                    $result[] = array_merge($contact_array, $job_contract_array);
                    $result_contact = TRUE;
                }
            }

            // This will make sure all the contacts are added to the result set, even if they don't have the job contract defined yet
            // Job contracts without contact records are however not added
            if ($result_contact === FALSE) {
                
                // Put empty job titles to avoid warnings
                $contact_array['title'] = '';
                
                $result[] = $contact_array;
            }

        }

        return $result;
    }

    /**
     * @param $user_id
     * @return mixed
     * Pass the user ID and this function will return array of assigned manager contact IDs
     */
    public static function _get_contact_manager_contact_id($user_id) {

        // Civi init
        civicrm_initialize();

        $params = array(
            'uf_id' => $user_id,
            'version' => 3,
            'sequential' => 1,
        );

        // Get the contact DATA from the passed user ID
        $res = civicrm_api3('UFMatch', 'Get', $params);
        $contact_data = array_shift($res['values']);

        // Get the relationships for the Contact
        $res = civicrm_api3('Relationship', 'get', array('contact_id' => $contact_data['contact_id']));
        $contactRelationships = $res['values'];

        $assigned_manager_contact_ids = [];
        $manager_found = 0;

        // If Leave approver is find, assign him as the manager (add contact ID to $assigned_manager_contact_ids array)
        foreach ($contactRelationships as $key => $relation) {
            if ($relation['relation'] == 'has Leave Approved by') {
                $assigned_manager_contact_ids[] = $relation['contact_id_b'];
                $manager_found++;
            }
        }

        // If no assigned managers found
        if ($manager_found <= 0) {

            // Get the main admin contact (this will be the default approver -> as no other leave approver is found)
            $main_admin_contact = civicrm_api('uf_match', 'get', array(
                'version' => 3,
                'uf_id' => 1,
            ));

            $main_admin_contact = array_shift($main_admin_contact['values']);

            // Set default manager ID
            $assigned_manager_contact_ids[] = $main_admin_contact['contact_id'];

        }

        return $assigned_manager_contact_ids;
    }
    
}