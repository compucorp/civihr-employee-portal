<?php

namespace Drupal\civihr_employee_portal\Blocks;

class SicknessLinks {

    /**
     * Absence request html modal links
     * @return string
     */
    public function generateBlock() {

        $links = '';
        $links .= '<div id="absence-links" class="list-group" style="height: 50px;">';
        $links .= civihr_employee_portal_make_link(t('Report new sickness'), 'sick');


        $links .= '</div>';

        return $links;
    }
}