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
    
    public $value1;
    public $value2;

    protected function setUp() {
        $this->value1 = 4;
        $this->value2 = 5;
    }
    
    // Compare values and assert PASS or FAILURE
    public function testCompareValues() {
        
        print " Match \r\n";
        return $this->assertEquals($this->value1 + 1, $this->value2);
           
    }
    
    // Compare values and assert PASS or FAILURE
    public function testCompareValues2() {
        
        
        $arr1 = Array();
        $arr1[0]['id'] = 1;
        $arr1[0]['name'] = 'NAME 1 for ID 1';
        $arr1[1]['id'] = 4;
        $arr1[1]['name'] = 'NAME2 for ID 4';
        $arr1[2]['id'] = 2;
        $arr1[2]['name'] = 'NAME 3 for ID 2';

        $arr2 = Array();
        $arr2[0]['id'] = 1;
        $arr2[0]['status'] = 'STATUS FOR ID 1';
        $arr2[2]['id'] = 2;
        $arr2[2]['status'] = 'STATUS FOR ID 2';
        $arr2[5]['id'] = 4;
        $arr2[5]['status'] = 'STATUS FOR ID 4';

        $merged_output = HelperClass::array_merge_callback($arr1, $arr2, function ($contact_array, $job_contract_array) {
            return $contact_array['id'] == $job_contract_array['id'];
        });

        print_r($merged_output);
        
        print " Match values2 \r\n";
        return $this->assertEquals($this->value1, $this->value2);
           
    }

}