<?php

require_once './includes/bootstrap.inc';
define('DRUPAL_ROOT', getcwd());
$_SERVER['REMOTE_ADDR'] = '127.0.0.1';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

class CiviHRJobContractEntitiesTest extends PHPUnit_Framework_TestCase
{
  protected $_testContactId = array();
  protected $_testJobContractId = array();
  protected $_date = array();

  public function __construct($name = NULL, array $data = array(), $dataName = '') {
    parent::__construct($name, $data, $dataName);
  }

  public function testDrupalView()
  {
    $this->_setUp();
    $this->assertEquals($this->_getExpectedViewData(), $this->_getActualViewData(), "Actual View data is different than expected.");
    $this->_clearTestData();
  }

  protected function _setUp() {
    $todayTime = time();
    $yesterdayTime = $todayTime - 3600 * 24;
    $tomorrowTime = $todayTime + 3600 * 24;
    $this->_date = array(
      'yesterday' => date('Y-m-d', $yesterdayTime),
      'today' => date('Y-m-d', $todayTime),
      'tomorrow' => date('Y-m-d', $tomorrowTime),
    );

    $this->_createTestData();
  }

  protected function _createTestData() {
    $createTestDataResult = true;
    try {
        // Create test Contact.
        $result = civicrm_api3('Contact', 'create', array(
          'sequential' => 1,
          'contact_type' => "Individual",
          'first_name' => "CiviHRJobContractEntitiesTest",
        ));
        $this->_testContactId = $result['id'];

        // Create test Job Contract for test Contact.
        $result = civicrm_api3('HRJobContract', 'create', array(
          'sequential' => 1,
          'contact_id' => $this->_testContactId,
        ));
        $this->_testJobContractId = $result['id'];

        // Create base (current) revision of some Job Contract entities.
        // Job Contract Details entity.
        $result = civicrm_api3('HRJobDetails', 'create', array(
          'sequential' => 1,
          'position' => "Test Position",
          'title' => "Test Title (today)",
          'period_start_date' => "2015-01-01",
          'jobcontract_id' => $this->_testJobContractId,
        ));
        // $result['values'][0] contains id, jobcontract_revision_id
        $revisionId = $result['values'][0]['jobcontract_revision_id'];
        // Job Contract Health entity.
        /*$result = civicrm_api3('HRJobHealth', 'create', array(
          'sequential' => 1,
          'plan_type' => "Family",
          'jobcontract_id' => $this->_testJobContractId,
          'jobcontract_revision_id' => $result['jobcontract_revision_id'],
        ));*/

        // Set Revision's effective date to today.
        $result = civicrm_api3('HRJobContractRevision', 'create', array(
          'sequential' => 1,
          'id' => $revisionId,
          'effective_date' => $this->_date['today'],
        ));

        // Create second revision of Details entity with yesterday effective date.
        $result = civicrm_api3('HRJobDetails', 'create', array(
          'sequential' => 1,
          'title' => "Test Title (yesterday)",
          'jobcontract_id' => $this->_testJobContractId,
        ));
        $revisionId = $result['values'][0]['jobcontract_revision_id'];
        $result = civicrm_api3('HRJobContractRevision', 'create', array(
          'sequential' => 1,
          'id' => $revisionId,
          'effective_date' => $this->_date['yesterday'],
        ));

        // Create third revision of Details entity with tomorrow effective date.
        $result = civicrm_api3('HRJobDetails', 'create', array(
          'sequential' => 1,
          'title' => "Test Title (tomorrow)",
          'jobcontract_id' => $this->_testJobContractId,
        ));
        $revisionId = $result['values'][0]['jobcontract_revision_id'];
        $result = civicrm_api3('HRJobContractRevision', 'create', array(
          'sequential' => 1,
          'id' => $revisionId,
          'effective_date' => $this->_date['tomorrow'],
        ));
    } catch (Exception $e) {
      $createTestDataResult = false;
    }
    $this->assertEquals(true, $createTestDataResult, "Cannot create test data.");
  }

  protected function _clearTestData() {
    // Delete test Job Contract and its entities.
    civicrm_api3('HRJobContract', 'deletecontractpermanently', array(
      'sequential' => 1,
      'id' => $this->_testJobContractId,
    ));
    // Delete test Contact.
    $result = civicrm_api3('Contact', 'get', array(
      'sequential' => 1,
      'first_name' => "CiviHRJobContractEntitiesTest",
    ));
    if (!empty($result['values'])) {
      foreach ($result['values'] as $contact) {
        civicrm_api3('Contact', 'delete', array('id' => $contact['contact_id']));
      }
    }
  }

  protected function _getActualViewData() {
    $json = file_get_contents(CIVICRM_UF_BASEURL . '/civihrjobcontractentitiestest');
    return json_decode($json, true);
  }

  protected function _getExpectedViewData() {
    return array(
      0 => array(
        "Contact ID" => "" . $this->_testContactId,
        "First Name" => "CiviHRJobContractEntitiesTest",
        "JobContract ID" => "" . $this->_testJobContractId,
        "Title" => "Test Title (today)",
      ),
    );
  }
}