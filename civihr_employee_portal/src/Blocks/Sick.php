<?php

namespace Drupal\civihr_employee_portal\Blocks;

class Sick {
    
    public function generateBlock() {
    
        return views_embed_view('absence_list', 'page_1');
    }
}
