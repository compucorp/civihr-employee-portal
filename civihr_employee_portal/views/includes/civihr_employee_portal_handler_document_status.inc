
<?php

/**
 * Custom views handler field to display the document status
 */
class civihr_employee_portal_handler_document_status extends views_handler_field {
    
    function render($values) {
        
        // Get the status_id
        $value = $this->get_value($values);
        
        // Find the document status based on status_id
        $document_status_value = get_civihr_document_statuses($value);
        
        return $document_status_value;
    }

}