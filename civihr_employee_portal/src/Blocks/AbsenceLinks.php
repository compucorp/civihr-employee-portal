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

        $links = '';
        $links .= '<div class="chr_panel__footer">';
        $links .= '<div class="chr_actions-wrapper">';
        $links .= civihr_employee_portal_make_link(t('Request TOIL'), 'credit', '', 'pull-left');
        $links .= '<div class="chr_actions-wrapper__inline-duo">';
        $links .= civihr_employee_portal_make_link(t('Request leave'), 'debit');
        $links .= civihr_employee_portal_make_link(t('Use TOIL'), 'credit_use');
        $links .= '</div>';
        $links .= '</div>';
        $links .= '</div>';


        return $links;
    }
}
