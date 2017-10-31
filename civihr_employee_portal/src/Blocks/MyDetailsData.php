<?php

namespace Drupal\civihr_employee_portal\Blocks;

class MyDetailsData {
    
    public function generateBlock() {
        
        $contact_data = '';
        
        // If we have logged in user, get his details
        if (isset($_SESSION['CiviCRM']['userID'])) {
            $contact_data = get_civihr_contact_data($_SESSION['CiviCRM']['userID']);

        }

        // Get the contact details view
        $contact_details = views_embed_view('my_details_block', 'my_details_block');

        // Get the address details view
        $address_data = views_embed_view('my_details_block', 'my_address_block');
        $address_data_title = t('Contact Information');

        // Output the themed details block
        return theme('civihr_employee_portal_my_details_block', 
            array(
                'contact_data' => $contact_data,
                'contact_details' => $contact_details,
                'address_data' => $address_data,
                'address_data_title' => $address_data_title
            )
        );
                
    }
}
