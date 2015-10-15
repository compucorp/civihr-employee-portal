<?php

namespace Drupal\civihr_employee_portal\Helpers\Test;

class TestUserException extends \Exception {}

class TestUser {

    private $user;
    private $civiUserID = NULL;

    const DEFAULT_TEST_USERNAME = "test_foo_bar";
    const CIVIHR_ADMIN_USERNAME = "civihr_admin";

    public function __construct($input = NULL, $deleteIfUsernameExists = FALSE) {
        // check mandatory fields presence if array input given for non-existing user
        if (is_array($input) && !isset($input['uid'])) {
            $mandatoryKeys = array('name', 'status', 'key');

            foreach ($mandatoryKeys as $key) {
                if (!array_key_exists($key, $input)) {
                    throw new TestUserException("Mandatory key '" . $key .
                    "' not present in user definition array");
                }
            }
        }

        // load existing user by uid
        if (is_int($input)) {
            $input = array('uid' => $input);
        }

        // fill in default test data, if no input array or uid was set
        if ($input === NULL) {
            $input = array(
                'name' => self::DEFAULT_TEST_USERNAME,
                'status' => 1,
                'mail' => "test_foo_bar.work@compucorp.co.uk",
            );
        }

        // delete existing user with same username if flagged
        if ($deleteIfUsernameExists && !isset($input['uid'])) {
            $duplicateUser = user_load_by_name($input['name']);

            if (isset($duplicateUser->uid)) {
                $this->deleteAsAdmin($duplicateUser->uid);
            }
        }

        // create test user account according to setup
        $this->user = user_save(NULL, $input);
        // civi autmatically considers as logged in the new created contact
        // we avoid this behavior and synchronize it with currently logged 
        // drupal user(anonymous if no other was logged)
        $this->logInAsCiviContact($GLOBALS['user']);
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

    protected function deleteAsAdmin($uid) {
        $adminUser = user_load_by_name(self::CIVIHR_ADMIN_USERNAME);
        $this->runAsUser(array($this, "deleteUser"), $adminUser, array($uid));
    }

    protected function deleteUser($uid) {
        $uf = get_civihr_uf_match_data($uid);
        user_delete($uid);

        if (!empty($uf['contact_id'])) {
            $result = civicrm_api3('Contact', 'delete', array(
                'sequential' => 1,
                'id' => $uf['contact_id'],
                'skip_undelete' => 1,
            ));
        }
    }

    /**
     * runs callback function as given user
     * @param type $callback function to be called
     * @param type $user user account under which the callback will be executed
     * @param type $params array parameters handed to callback function
     */
    protected function runAsUser($callback, $user, $params) {
        // Prevent session information from being saved while doing funky stuff.
        $original_session_state = drupal_save_session();
        drupal_save_session(FALSE);

        $original_user = $GLOBALS['user'];
        $GLOBALS['user'] = $user;
        $this->logInAsCiviContact($user);

        try {
            call_user_func_array($callback, $params);
        }
        catch (Exception $e) {
            // we switch back to original user first correctly before throwing exception
            $this->switchToOriginalUser($original_user, $original_session_state);
            throw $e;
        }
        
        $this->switchToOriginalUser($original_user, $original_session_state);
    }
    
    /**
     * Restore the original user no matter if execution crushed.
     */
    protected function switchToOriginalUser($original_user, $original_session_state) {
        $GLOBALS['user'] = $original_user;
        $this->logInAsCiviContact($original_user);
        drupal_save_session($original_session_state);
    }

    /**
     * sets contact associated with given user as logged in civi user
     * @param int $user user object from Drupal
     */
    protected function logInAsCiviContact($user) {
        \CRM_Core_BAO_UFMatch::synchronize($user, FALSE, 'Drupal', civicrm_get_ctype('Individual')
        );
    }

    /**
     * retrieve info for this user from civi contact
     * @param $requestedFields array fields to retrieve from 
     * contact record via civi API
     */
    public function getCiviContactValues($requestedFields) {
        if (!is_array($requestedFields)) {
            $requestedFields = array($requestedFields);
        }

        $result = civicrm_api3('Contact', 'getsingle', array(
            'sequential' => 1,
            'id' => $this->getCiviUserId(),
            'return' => join(",", $requestedFields),
        ));

        return $result;
    }

    /**
     * set civi contact values for contact associated with this user
     * @param $values array key => value pairs to set to 
     * contact record via civi API 
     */
    public function setCiviContactValues($values) {
        $base = array(
            'sequential' => 1,
            'id' => $this->getCiviUserId(),
        );

        $result = civicrm_api3('Contact', 'create', array_merge($values, $base));

        return $result;
    }

    public function getCiviUserId() {
        if ($this->civiUserID === NULL) {
            $uf = get_civihr_uf_match_data($this->user->uid);
            if (!empty($uf['contact_id'])) {
                $this->civiUserID = $uf['contact_id'];
            }
            else {
                throw new TestUserException("Test user has no civi Contact assigned.");
            }
        }

        return $this->civiUserID;
    }

}
