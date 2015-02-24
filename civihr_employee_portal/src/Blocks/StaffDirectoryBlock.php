<?php

namespace Drupal\civihr_employee_portal\Blocks;

class StaffDirectoryBlock {
    
    public function generateBlock() {
        
        // Output the block as form
        return drupal_get_form('civihr_employee_portal_directory_block_form');
                
    }
}