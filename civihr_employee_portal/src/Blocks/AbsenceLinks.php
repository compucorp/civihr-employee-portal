<?php

namespace Drupal\civihr_employee_portal\Blocks;

class AbsenceLinks {
    
    /**
     * Absence request html modal links
     * @return string
     */
    public function generateBlock() {
        
        ctools_include('modal');
        ctools_modal_add_js();
        
        // Set the modal size (width) based on the available screen size of the user (passed from the jQuery on each page load)
        $width = isset($_COOKIE['browser_width']) ? $_COOKIE['browser_width'] * 0.75 : 550;
        
        // Create our own javascript that will be used to theme a modal.
        $civihr_style = array(
            'civihr-default-style' => array(
                'modalOptions' => array(
                    'opacity' => .5,
                    'background-color' => '#000',
                ),
                'animation' => 'fadeIn',
            ),
        );
        
        drupal_add_js($civihr_style, 'setting');

        $links = '';
        $links .= '<div id="absence-links" class="list-group" style="height: 50px;">';
        $links .= civihr_employee_portal_make_link('Request leave', 'debit');
        $links .= civihr_employee_portal_make_link('Apply for credits', 'credit');
        $links .= civihr_employee_portal_make_link('Open calendar', 'calendar');
        
        $links .= '</div>';
        
        return $links;
    }
}