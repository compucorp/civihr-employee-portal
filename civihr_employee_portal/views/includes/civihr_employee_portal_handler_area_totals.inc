<?php
/**
 * @file
 */
class civihr_employee_portal_handler_area_totals extends views_handler_area {
  function render($empty = FALSE) {
           
    // Get the absence types
    $absenceTypes = get_civihr_absence_types();
    
    $results = array();
    
    $header = array();
    $rows = array();
    
    /**
     * Date filters
     */
    if (isset($_REQUEST['absence_start_date_period_filter'])) {
        $request_date = $_REQUEST['absence_start_date_period_filter'];
    }
    else {
        // Set default period
        $request_date = '1';
    }
    
    // Build the query
    $query = db_select('civicrm_hrabsence_entitlement', 'che')
        ->fields('che', array('contact_id', 'period_id'))
        ->orderBy('che.contact_id');
    
    // Add the where query
    $query->where('(che.contact_id = :c_id)', array(':c_id' => $_SESSION['CiviCRM']['userID']));
    $query->where('(che.period_id = :period_id)', array(':period_id' => $request_date));
    
    // Add the concat
    $query->addExpression("CONCAT_WS('||', GROUP_CONCAT(amount SEPARATOR '@@'), GROUP_CONCAT(type_id SEPARATOR '@@'))", "entitlement_type");
    
    // Add the group by
    $query->groupBy('che.contact_id, che.period_id');
     
    $result = $query->execute();
    
    $result_output = array();
    
    // Loop and prepare the array
    while($record = $result->fetchAssoc()) {
        $result_output['data'][] = $record;
    }
    
    $header[] = t('Balance: ');
    $rows[0][] = '';
    $header[] = t('');
    $rows[0][] = '';

    if (isset($result_output['data'])) {
        
        // Get the entitlement for the employee, add it to the basic / totals count
        $value_explode = explode("||", $result_output['data'][0]['entitlement_type']);

        $absence_ids = explode("@@", $value_explode[1]);
        $absence_values = explode("@@", $value_explode[0]);



        foreach ($absenceTypes as $absenceType) {

            $results[$absenceType['id']] = 0;

            if (isset($absenceType['is_active']) && $absenceType['is_active'] == '1' && $absenceType['title'] != 'Sick') {

                foreach ($absence_ids as $absence_array_key => $absence_id) {

                    if ($absence_id == $absenceType['id']) {

                        // Set everything to 0
                        $results[$absenceType['id']] = $absence_values[$absence_array_key];

                    }
                }

                foreach ($this->view->result as $row) {


                    if (isset($row->absence_list_is_credit) && $row->absence_list_is_credit == '1' && isset($absenceType['credit_activity_type_id']) && $row->absence_list_activity_type_id == $absenceType['credit_activity_type_id']) {

                        $results[$absenceType['id']] += $row->absence_list_duration / (6 * 80);

                    }
                    else {

                        if ($row->absence_list_activity_type_id == $absenceType['debit_activity_type_id']) {

                            $results[$absenceType['id']] -= $row->absence_list_duration / (6 * 80);

                        }

                    }

                }

                /**
                 * Populate the table
                 */
                $header[] = $absenceType['title'];
                $rows[0][] = $results[$absenceType['id']];
            }
        }
    }
    
    return theme('table', array('header' => $header, 'rows' => $rows));
    
  }
}
