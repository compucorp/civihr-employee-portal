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

// Our test class.
class StaffDirectoryResultTest extends PHPUnit_Framework_TestCase {

    protected function setUp() {
    }
    
    //check whether module username_to_external_id is enabled
    public function testModuleState() {
        $this->assertEquals(TRUE, module_exists("username_to_external_id"));
    }

    /**
     * test if all users have primary email set to type "Work"
     * @depends testModuleState
     */
    public function testPrimaryEmailType() {
        try {
            $res_user_ids = array();
            $work_type_id = HelperClass::_get_work_location_type_id();

            $uf_data = civicrm_api3('UFMatch', 'get', array(
                'sequential' => 1,
                'return' => "contact_id",
            ));

            foreach ($uf_data['values'] as $uf_item) {

                $email_data = civicrm_api3('Email', 'get', array(
                    'sequential' => 1,
                    'contact_id' => $uf_item['contact_id'],
                    'is_primary' => 1,
                    'return' => "id,email,contact_id,is_primary,location_type_id",
                ));

                $email_values = reset($email_data['values']);

                if ($email_values['location_type_id'] !== $work_type_id) {
                    $res_user_ids[] = $uf_item['contact_id'];
                }
            }

            print " Test Primary Email Type \r\n";
            print_r($res_user_ids);

            $this->assertEquals(array(), $res_user_ids);
        }
        catch (CiviCRM_API3_Exception $e) {
            $error = $e->getMessage();
            watchdog("test error: testPrimaryEmailType", $error);

            $this->fail('Exception occured by civi API call.');
        }
    }

}