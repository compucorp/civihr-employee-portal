
<?php

/**
 * Custom views handler field to display the employee name from the employee ID
 */
class civihr_employee_portal_handler_absence_status extends views_handler_field {
    
    function render($values) {
        
        // Debug function elapsed time
        $starttime = round(microtime(true) * 1000);
    
        // Get the contact_id
        $value = $this->get_value($values);
        
        // Find the contact_name based on contact_id
        $abence_status_value = get_civihr_absence_statuses($value);
    
        // Debug function elapsed time end
        $endtime = round(microtime(true) * 1000);
        
        $timediff = $endtime - $starttime;
        
        watchdog('contact absence status: ' . $value . ' - time elapsed', $timediff);
        
        // How we want to display the approved absences?
        if ($abence_status_value == 'Completed') {
            $abence_status_value = 'Approved';
        }
        if ($abence_status_value == 'Scheduled') {
            $abence_status_value = 'Awaiting approval';
        }
        
        return $abence_status_value;
    }

}