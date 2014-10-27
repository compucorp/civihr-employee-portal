<?php

namespace Drupal\civihr_employee_portal\Blocks;

//require_once('sites/all/modules/civicrm/api/class.api.php');

class Leave {
    
    public function generateBlock() {
        
        return views_embed_view('absence_list', 'page');
                
    }
}
