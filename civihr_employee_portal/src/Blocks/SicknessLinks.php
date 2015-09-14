<?php

namespace Drupal\civihr_employee_portal\Blocks;

class SicknessLinks {

    /**
     * Sickness request html modal links
     * @return string
     */
    public function generateBlock() {

        $links = '';
        $links .= '<div class="chr_panel__actions">';
        $links .= civihr_employee_portal_make_link(t('Report new sickness'), 'sick');
        $links .= '</div>';

        return $links;
    }
}
