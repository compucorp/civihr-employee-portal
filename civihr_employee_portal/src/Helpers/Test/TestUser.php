<?php

namespace Drupal\civihr_employee_portal\Helpers\Test;

class TestUser {

    private $user;
    private $civiUserID = NULL;
    const DEFAULT_TEST_USERNAME = "test_foo_bar";

    public function __construct($input = NULL, $deleteIfUsernameExists = FALSE) {
        //check mandatory fields presence if array input given for non-existing user
        if (is_array($input) && !isset($input['uid'])) {
            $mandatoryKeys = array('name', 'status', 'key');

            foreach ($mandatoryKeys as $key) {
                if (!array_key_exists($key, $input)) {
                    throw new Exception("Mandatory key '" . $key . "' not present in user definition array");
                }
            }
        }

        //load existing user by uid
        if (is_int($input)) {
            $input = array('uid' => $input);
        }

        //fill in default test data, if no input array or uid was set
        if ($input === NULL) {
            $input = array(
                'name' => self::DEFAULT_TEST_USERNAME,
                'status' => 1,
                'mail' => "test_foo_bar.work@compucorp.co.uk",
            );
        }

        //delete existing user with same username if flagged
        if ($deleteIfUsernameExists && !isset($input['uid'])) {
            $duplicateUser = user_load_by_name($input['name']);
            
            if(isset($duplicateUser->uid)){
                $this->deleteAsAdmin($duplicateUser->uid);
            }
        }

        //create test user account according to setup
        $this->user = user_save(drupal_anonymous_user(), $input);
    }

    public function __get($name) {
        return $this->user->$name;
    }

    public function __set($name, $value) {
        $this->user->$name = $value;
    }

    public function save() {
        $this->user = user_save($this->user);
    }

    /**
     * permanently deletes user from both - drupal and civi
     */
    public function delete() {
        $this->deleteAsAdmin($this->user->uid);
    }
    
    private function deleteAsAdmin($uid) {
        $this->runAsAdmin(array($this, "deleteUser"), array($uid));
    }

    private function deleteUser($uid) {
        $uf = get_civihr_uf_match_data($uid);

        user_delete($uid);

        if (!empty($uf['contact_id'])) {
            try {
                $result = civicrm_api3('Contact', 'delete', array(
                    'sequential' => 1,
                    'id' => $uf['contact_id'],
                    'skip_undelete' => 1,
                ));
            }
            catch (CiviCRM_API3_Exception $e) {
                $error = $e->getMessage();
                watchdog("test error: testExternalID", $error);
            }
        }
    }
    
    private function runAsAdmin($callback, $params) {
        // Prevent session information from being saved while doing funky stuff.
        $original_session_state = drupal_save_session();
        drupal_save_session(FALSE);

        // Force the current user to anonymous to ensure consistent permissions on
        // funky stuff runs.
        $original_user = $GLOBALS['user'];
        $GLOBALS['user'] = user_load_by_name('civihr_admin');

        call_user_func_array($callback, $params);

        // Restore the user.
        $GLOBALS['user'] = $original_user;
        drupal_save_session($original_session_state);
    }
    
    //retrieve info from civi contact
    public function getCiviValues($requestedFields) {
        if(!is_array($requestedFields)){
            $requestedFields = array($requestedFields);
        }
        
        try {
            $result = civicrm_api3('Contact', 'getsingle', array(
                'sequential' => 1,
                'id' => $this->getCiviUserId(),
                'return' => join(",", $requestedFields),
            ));
        }
        catch (CiviCRM_API3_Exception $e) {
            $error = $e->getMessage();
            watchdog("test user: error retrieving values from API", $error);
        }        
        
        return $result;
    }
    
    private function getCiviUserId() {
        if($this->civiUserID === NULL){
            $uf = get_civihr_uf_match_data($this->user->uid);
            if (!empty($uf['contact_id'])) {
                $this->civiUserID = $uf['contact_id'];
            }
            else{
                throw new Exception("Test user has no civi Contact assigned.");
            }
        }
        
        return $this->civiUserID;
    }

}
