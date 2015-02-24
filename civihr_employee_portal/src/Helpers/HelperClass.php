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
                $result[] = $contact_array;
            }

        }

        return $result;
    }
    
}