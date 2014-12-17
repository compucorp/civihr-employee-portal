<?php

namespace Drupal\civihr_employee_portal\Blocks;

class MyDetailsData {
    
    public function generateBlock() {
        
        // Get the contact details view
        $contact_details = views_embed_view('my_details_block', 'default');
        
        // Get the address details view
        $address_data = views_embed_view('my_details_block', 'my_address_block');
        
        // Output the themed details block
        return theme('civihr_employee_portal_my_details_block', 
            array(
                'profile_image' => '',
                'contact_details' => $contact_details,
                'address_data' => $address_data
            )
        );
                
    }
}
