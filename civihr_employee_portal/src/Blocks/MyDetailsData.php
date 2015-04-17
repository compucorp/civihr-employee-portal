<?php

namespace Drupal\civihr_employee_portal\Blocks;

class MyDetailsData {
    
    public function generateBlock() {
        
        $contact_data = '';
        
        // If we have logged in user, get his details
        if (isset($_SESSION['CiviCRM']['userID'])) {
            $contact_data = get_civihr_contact_data($_SESSION['CiviCRM']['userID']);

        }

        // @TODO -> show different view with all the data available
        // If we are on the HR details full list page, show different view with all the data
        if (isset($_GET['q']) && $_GET['q'] == 'hr-details') {

            // Get the contact details view
            $contact_details = views_embed_view('my_details_block', 'default');

        }
        else {

            // Get the contact details view
            $contact_details = views_embed_view('my_details_block', 'default');

        }

        
        // Get the address details view
        $address_data = views_embed_view('my_details_block', 'my_address_block');
        
        // Output the themed details block
        return theme('civihr_employee_portal_my_details_block', 
            array(
                'contact_data' => $contact_data,
                'contact_details' => $contact_details,
                'address_data' => $address_data
            )
        );
                
    }
}
