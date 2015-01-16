<?php

namespace Drupal\civihr_employee_portal\Blocks;

class LoginBlock {
    
    public function generateBlock() {
        
        // Output the themed login details block
        return theme('civihr_employee_portal_login_block', 
            array(
                'custom_data' => ''
            )
        );
                
    }
}
