<?php

/**
 * Implementation of hook_rules_event_info().
 * 
 */
function civihr_hrjobcontract_entities_rules_event_info() {
    return array(
        'hrjobcontract_after_create' => array(
            'label' => t('Job Contract has been created'),
            'group' => t('HRJobContract'),
            'module' => 'civihr_hrjobcontract_entities',
            'variables' => array(
                'instance' => array('type' => 'object', 'label' => 'Job Contract instance'),
            ),
        ),
        'hrjobcontract_after_delete' => array(
            'label' => t('Job Contract has been deleted'),
            'group' => t('HRJobContract'),
            'module' => 'civihr_hrjobcontract_entities',
            'variables' => array(
                'instance' => array('type' => 'text', 'label' => 'Deleted Job Contract ID'),
            ),
        ),
    );
}
