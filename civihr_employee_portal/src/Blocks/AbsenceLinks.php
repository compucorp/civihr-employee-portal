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

        // Create our own javascript that will be used to theme a modal.
        $civihr_style = array(
            'civihr-default-style' => array(
                'modalOptions' => array(
                    'opacity' => .5,
                    'background-color' => '#000',
                ),
                'animation' => 'fadeIn'
            ),
            'civihr-custom-style' => array(
                'modalOptions' => array(
                    'opacity' => .5,
                    'background-color' => '#000',
                ),
                'modalSize' => array(
                    'height' => 'auto',
                    'width' => 'auto'
                ),
                'animation' => 'fadeIn',
                'modalClass' => 'civihr-custom'
            ),
        );

        drupal_add_js($civihr_style, 'setting');

        $links = '';
        $links .= '<div class="chr_actions-wrapper">';
        $links .= '<div class="chr_actions-wrapper__inline-duo">';
        $links .= civihr_employee_portal_make_link(t('Request TOIL'), 'credit');
        $links .= civihr_employee_portal_make_link(t('Request leave'), 'debit');
        $links .= '</div>';
        $links .= civihr_employee_portal_make_link(t('Use TOIL'), 'credit_use');
        $links .= '</div>';

        return $links;
    }
}
