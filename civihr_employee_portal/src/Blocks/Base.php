<?php

namespace Drupal\civihr_employee_portal\Blocks;

class Base {
    
    /**
     * Define block types created by the Drupal civihr_employee_portal_block_info() function
     * @return type
     */
    public static function returnBlockTypes() {

      return [
        'my_details' => [
          'info' => t('CiviHR my details block'),
          'class_name' => 'MyDetailsData',
          'title' => '<none>'
        ],
        'login_block' => [
          'info' => t('CiviHR custom login block'),
          'class_name' => 'LoginBlock',
          'title' => '<none>'
        ],
        'staff_directory_block' => [
          'info' => t('CiviHR Staff Directory dashboard block'),
          'class_name' => 'StaffDirectoryBlock',
          'title' => 'Staff Directory'
        ],
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

