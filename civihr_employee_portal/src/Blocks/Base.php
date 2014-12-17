<?php

namespace Drupal\civihr_employee_portal\Blocks;

class Base {
    
    /**
     * Define block types created by the Drupal civihr_employee_portal_block_info() function
     * @return type
     */
    public static function returnBlockTypes() {
    
        return ['leave' => array('info' => t('CiviHR leave block'),
                                 'class_name' => 'Leave',
                                 'title' => t('My leave')),
                            
                'sick' => array('info' => t('CiviHR sickness report block'),
                                'class_name' => 'Sick',
                                'title' => t('My sickness report')),
            
                'absence_links' => array('info' => t('CiviHR modal absence links block'),
                                'class_name' => 'AbsenceLinks',
                                'title' => '<none>'),
            
                'manager_calendar' => array('info' => t('CiviHR manager calendar block'),
                                'class_name' => 'ManagerCalendar',
                                'title' => '<none>'),
                'my_details' => array('info' => t('CiviHR my details block'),
                                'class_name' => 'MyDetailsData',
                                'title' => '<none>'),
               ];
    }
    
    public function generateBlockInfo() {
        
        foreach ($this->returnBlockTypes() as $block_key => $blocktype) {
            
            $blocks[$block_key] = array(
                'info' => $blocktype['info'],
            );
            
        }
        
        return $blocks;
    }
}

