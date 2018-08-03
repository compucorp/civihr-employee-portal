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

        // Get the contact ID based on the USER ID
        $contact_id = get_civihr_uf_match_data($user_id)['contact_id'];

        return _getManagerContacts($contact_id);
    }
    
    /**
     * Helper method for retrieving particular "Work" location type id
     */
    public static function _get_work_location_type_id() {
        return self::_get_location_type_id("Work");
    }
    
    public static function _get_location_type_id($name) {
        $type_data = civicrm_api3('LocationType', 'getsingle', array(
            'sequential' => 1,
            'display_name' => $name,
        ));

        return $type_data['id'];
    }

  /**
   * Takes the first element of an array of stdClass instances,
   * then convert this element to array only with its values
   * and then returns the first element on the array of values.
   *
   * @param array $a
   *     an array of stdClass instances
   *
   * @return string|integer|stdClass
   *     the first value found in the first stdClass element
   */
  public static function getFirstValueFromFirstObjectInArray($a) {
    return is_array($a) && $a ? array_values(get_object_vars($a[0]))[0] : FALSE;
  }

  /**
   * Gets location by display name. This is used to avoid using IDs which
   * could be different depending on how this values are generated
   *
   * @param string $display_name
   *     the name of the location
   *
   * @return int
   *     the ID of the location
   */
  public static function getLocationTypeIdByName($display_name) {
    return civicrm_api3('LocationType', 'get', [
      'sequential' => 1,
      'return' => ['id'],
      'display_name' => $display_name,
    ])['values'][0]['id'];
  }

  /**
   * Gets phone type by name. This is used to avoid using IDs which could
   * be different depending on how this values are generated
   *
   * @param string $name
   *     the name of the phone type
   *
   * @return int
   *     the ID of the phone type
   */
  public static function getPhoneTypeByName($name) {
    return civicrm_api3('OptionValue', 'get', [
      'sequential' => 1,
      'return' => ['value'],
      'option_group_id' => 'phone_type',
      'name' => $name,
    ])['values'][0]['value'];
  }
}
