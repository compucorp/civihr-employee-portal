<?php

// We assume that this script is being executed from the root of the Drupal
// installation. e.g. -- > phpunit StaffDirectoryResultTest sites/all/modules/civihr-custom/civihr_employee_portal/tdd/StaffDirectoryResultTest.php
// These constants and variables are needed for the bootstrap process.
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';

// Bootstrap Drupal.
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Load our custom classes
use Drupal\civihr_employee_portal\Helpers\HelperClass;
use Drupal\civihr_employee_portal\Helpers\Test\TestUser;

// Our test class.
class UsernameToExternalIdTest extends PHPUnit_Framework_TestCase {

    private $testUser = NULL;

    protected function setUp() {
        
    }

    //check whether module username_to_external_id is enabled
    public function testModuleState() {
        print " Test if module is enabled \r\n";
        $this->assertEquals(TRUE, module_exists("username_to_external_id"));
    }

    /**
     * test if all users have primary email set to type "Work"
     * @depends testModuleState
     */
    public function testPrimaryEmailType() {
        try {
            $resultUserIDs = array();
            $workTypeID = HelperClass::_get_work_location_type_id();

            $ufData = civicrm_api3('UFMatch', 'get', array(
                'sequential' => 1,
                'return' => "contact_id",
            ));

            foreach ($ufData['values'] as $ufItem) {

                $emailData = civicrm_api3('Email', 'get', array(
                    'sequential' => 1,
                    'contact_id' => $ufItem['contact_id'],
                    'is_primary' => 1,
                    'return' => "id,email,contact_id,is_primary,location_type_id",
                ));

                $emailValues = reset($emailData['values']);

                if ($emailValues['location_type_id'] !== $workTypeID) {
                    $resultUserIDs[] = $ufItem['contact_id'];
                }
            }

            print " Test Primary Email Type \r\n";
            print_r($resultUserIDs);

            $this->assertEquals(array(), $resultUserIDs);
        }
        catch (CiviCRM_API3_Exception $e) {
            print " Exception raised in method " . __FUNCTION__ . " : " . $e->getMessage() . "\r\n";
            $this->fail('Exception occured by civi API call.');
        }
    }

    /**
     *  tries to create a new drupal user and civi contact 
     *  and tests if the external ID is set properly
     * @depends testModuleState
     */
    public function testExternalID() {
        try {
            print " Test External ID \r\n";

            $this->testUser = new TestUser(NULL, true);
            $values = $this->testUser->getCiviContactValues("external_identifier");

            $this->assertEquals($this->testUser->name, $values['external_identifier']);
            $this->testUser->delete();
        }
        catch (\Exception $e) {
            print " Exception raised in method " . __FUNCTION__ . " : " . $e->getMessage() . "\r\n";
            $this->fail('Exception occured');
        }
    }

    /**
     * updates the contact and tests the external ID again
     * @depends testModuleState
     */
    public function testContactUpdate() {
        try {
            print " Test External ID after contact update \r\n";
            $this->testUser = new TestUser(NULL, true);
            // update civi contact 
            $this->testUser->setCiviContactValues(array(
                'first_name' => "Foo",
                'last_name' => "Bar",
            ));

            // update drupal user account
            $this->testUser->name = $this->testUser->name . "_2";
            $this->testUser->save();

            $values = $this->testUser->getCiviContactValues("external_identifier");

            $this->assertEquals($this->testUser->name, $values['external_identifier']);
            $this->testUser->delete();
        }
        catch (\Exception $e) {
            print " Exception raised in method " . __FUNCTION__ . " : " . $e->getMessage() . "\r\n";
            $this->fail('Exception occured');
        }
    }

    /**
     * sets the personal phone, personal email for the contact -> and checks 
     * if the correct values are returned with the API
     * @depends testModuleState
     */
    public function testPersonalDetails() {
        try {
            print " Test correct setup of personal email and phone \r\n";
            $this->testUser = new TestUser(NULL, true);

            $contactID = $this->testUser->getCiviUserId();
            $personalTypeID = HelperClass::_get_location_type_id("Home");
            $inputDetails = array('email' => "test_foo_bar.home@compucorp.co.uk", 'phone' => "22222222");

            $emailResult = civicrm_api3('Email', 'create', array(
                'sequential' => 1,
                'contact_id' => $contactID,
                'location_type_id' => $personalTypeID,
                'email' => $inputDetails['email'],
            ));

            $phoneResult = civicrm_api3('Phone', 'create', array(
                'sequential' => 1,
                'contact_id' => $contactID,
                'location_type_id' => $personalTypeID,
                'phone' => $inputDetails['phone'],
            ));

            $emailData = civicrm_api3('Email', 'getsingle', array(
                'sequential' => 1,
                'contact_id' => $contactID,
                'location_type_id' => $personalTypeID,
            ));

            $phoneData = civicrm_api3('Phone', 'getsingle', array(
                'sequential' => 1,
                'contact_id' => $contactID,
                'location_type_id' => $personalTypeID,
            ));

            $this->assertEquals($inputDetails, array('email' => $emailData['email'], 'phone' => $phoneData['phone']));
            $this->testUser->delete();
        }
        catch (\Exception $e) {
            print " Exception raised in method " . __FUNCTION__ . " : " . $e->getMessage() . "\r\n";
            $this->fail('Exception occured');
        }
    }

    /**
     * checks if the work email from the API is set as primary and is the 
     * same as the email used when creating the contact
     * @depends testModuleState
     */
    public function testWorkEmail() {
        try {
            print " Test work email type \r\n";
            $this->testUser = new TestUser(NULL, true);

            $contactID = $this->testUser->getCiviUserId();
            $workTypeID = HelperClass::_get_work_location_type_id();

            $emailData = civicrm_api3('Email', 'getsingle', array(
                'sequential' => 1,
                'contact_id' => $contactID,
                'is_primary' => 1,
                'location_type_id' => $workTypeID,
                'return' => "id,email,contact_id,is_primary,location_type_id",
            ));

            $this->assertEquals($this->testUser->mail, $emailData['email']);
            $this->testUser->delete();
        }
        catch (\Exception $e) {
            print " Exception raised in method " . __FUNCTION__ . " : " . $e->getMessage() . "\r\n";
            $this->fail('Exception occured');
        }
    }

    protected function tearDown() {
        
    }

}
