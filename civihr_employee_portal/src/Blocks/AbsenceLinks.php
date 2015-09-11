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
        $links .= '<div class="chr_panel__actions">';
        $links .= '<div class="chr_panel__actions__inline-duo">';
        $links .= civihr_employee_portal_make_link(t('Request TOIL'), 'credit', null, 'chr_panel__actions__action');
        $links .= civihr_employee_portal_make_link(t('Request leave'), 'debit', null, 'chr_panel__actions__action');
        $links .= '</div>';
        $links .= civihr_employee_portal_make_link(t('Use TOIL'), 'credit_use', null, 'chr_panel__actions__action');
        $links .= '</div>';

        return $links;
    }
}
