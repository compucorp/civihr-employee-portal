<?php

/**
 * Implementation of hook_rules_event_info().
 * @ingroup Absence entity
 */
function civihr_employee_portal_rules_event_info() {
    return array(
        'user_and_civi_contact_added' => array(
            'label' => t('Employee requests access for the Self Service Portal'),
            'group' => t('Absence entity'),
            'module' => 'civihr_employee_portal',
            'variables' => array(
                'current_user' => array('type' => 'user', 'label' => t('The current logged in user from Absence entity.')),
            ),
        ),
    );
}
