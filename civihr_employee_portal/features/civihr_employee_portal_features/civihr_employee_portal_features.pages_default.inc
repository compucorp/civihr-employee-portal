<?php
/**
 * @file
 * civihr_employee_portal_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function civihr_employee_portal_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dashboard';
  $page->task = 'page';
  $page->admin_title = 'Dashboard';
  $page->admin_description = '';
  $page->path = 'dashboard';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Dashboard',
    'weight' => '0',
    'name' => 'user-menu',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_sutro_double';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'secondcolumn1' => NULL,
      'secondcolumn2' => NULL,
      'footer' => array(
        'list_type' => 'ul',
      ),
    ),
    'footer' => array(
      'style' => 'list',
    ),
  );
  $display->cache = array();
  $display->title = 'Dashboard';
  $display->uuid = '091af8a4-cb6d-45b4-8946-1016cd5fb4d8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-691f553c-d36d-474b-b89b-c75974eb3eb4';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'views-hr_documents-block ';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'footer-slider-block',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '691f553c-d36d-474b-b89b-c75974eb3eb4';
    $display->content['new-691f553c-d36d-474b-b89b-c75974eb3eb4'] = $pane;
    $display->panels['footer'][0] = 'new-691f553c-d36d-474b-b89b-c75974eb3eb4';
  
    $pane = new stdClass();
    $pane->pid = 'new-b1c02e0a-90d6-490f-8134-69dc9205bc21';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'views-1e6267274b5d19d456da8db2cd22ac5a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'footer-slider-block',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b1c02e0a-90d6-490f-8134-69dc9205bc21';
    $display->content['new-b1c02e0a-90d6-490f-8134-69dc9205bc21'] = $pane;
    $display->panels['footer'][1] = 'new-b1c02e0a-90d6-490f-8134-69dc9205bc21';
    
    $pane = new stdClass();
    $pane->pid = 'new-691f553c-d36d-474b-b89b-c75974eb3eb5';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'views-Documents-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'footer-slider-block',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '691f553c-d36d-474b-b89b-c75974eb3eb5';
    $display->content['new-691f553c-d36d-474b-b89b-c75974eb3eb5'] = $pane;
    $display->panels['footer'][2] = 'new-691f553c-d36d-474b-b89b-c75974eb3eb5';
    
    $pane = new stdClass();
    $pane->pid = 'new-691f553c-d36d-474b-b89b-c75974eb3eb6';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'views-Documents-block_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'footer-slider-block',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '691f553c-d36d-474b-b89b-c75974eb3eb6';
    $display->content['new-691f553c-d36d-474b-b89b-c75974eb3eb6'] = $pane;
    $display->panels['footer'][3] = 'new-691f553c-d36d-474b-b89b-c75974eb3eb6';
    
    $pane = new stdClass();
    $pane->pid = 'new-48897dc2-d49e-4e72-b86a-7ec70b28da04';
    $pane->panel = 'header';
    $pane->type = 'block';
    $pane->subtype = 'civihr_employee_portal-my_details';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
              1 => 4,
              2 => 6,
              3 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'My Details',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '48897dc2-d49e-4e72-b86a-7ec70b28da04';
    $display->content['new-48897dc2-d49e-4e72-b86a-7ec70b28da04'] = $pane;
    $display->panels['header'][0] = 'new-48897dc2-d49e-4e72-b86a-7ec70b28da04';
    $pane = new stdClass();
    $pane->pid = 'new-492d39db-c7b8-4397-92db-ef4745f2ac5d';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'views-approvals-block_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '492d39db-c7b8-4397-92db-ef4745f2ac5d';
    $display->content['new-492d39db-c7b8-4397-92db-ef4745f2ac5d'] = $pane;
    $display->panels['middle'][0] = 'new-492d39db-c7b8-4397-92db-ef4745f2ac5d';
    $pane = new stdClass();
    $pane->pid = 'new-b149e6e0-7df8-46c5-b5b9-085df7ed8a07';
    $pane->panel = 'secondcolumn1';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-absence_list-page';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b149e6e0-7df8-46c5-b5b9-085df7ed8a07';
    $display->content['new-b149e6e0-7df8-46c5-b5b9-085df7ed8a07'] = $pane;
    $display->panels['secondcolumn1'][0] = 'new-b149e6e0-7df8-46c5-b5b9-085df7ed8a07';
    $pane = new stdClass();
    $pane->pid = 'new-ea7ad282-bc5e-4de0-876e-d856b3803460';
    $pane->panel = 'secondcolumn1';
    $pane->type = 'block';
    $pane->subtype = 'civihr_employee_portal-leave';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ea7ad282-bc5e-4de0-876e-d856b3803460';
    $display->content['new-ea7ad282-bc5e-4de0-876e-d856b3803460'] = $pane;
    $display->panels['secondcolumn1'][1] = 'new-ea7ad282-bc5e-4de0-876e-d856b3803460';
    $pane = new stdClass();
    $pane->pid = 'new-90794cd4-53e8-4759-a786-f04977f62c7c';
    $pane->panel = 'secondcolumn2';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-absence_list-page_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '90794cd4-53e8-4759-a786-f04977f62c7c';
    $display->content['new-90794cd4-53e8-4759-a786-f04977f62c7c'] = $pane;
    $display->panels['secondcolumn2'][0] = 'new-90794cd4-53e8-4759-a786-f04977f62c7c';
    $pane = new stdClass();
    $pane->pid = 'new-73347ee0-93bf-40ac-b270-9e9a46792cf0';
    $pane->panel = 'secondcolumn2';
    $pane->type = 'block';
    $pane->subtype = 'civihr_employee_portal-sick';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '73347ee0-93bf-40ac-b270-9e9a46792cf0';
    $display->content['new-73347ee0-93bf-40ac-b270-9e9a46792cf0'] = $pane;
    $display->panels['secondcolumn2'][1] = 'new-73347ee0-93bf-40ac-b270-9e9a46792cf0';
    $pane = new stdClass();
    $pane->pid = 'new-91c23893-858f-4a81-9708-e143fa11724b';
    $pane->panel = 'secondcolumn2';
    $pane->type = 'block';
    $pane->subtype = 'civihr_employee_portal-staff_directory_block';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
              1 => 4,
              2 => 6,
              3 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '91c23893-858f-4a81-9708-e143fa11724b';
    $display->content['new-91c23893-858f-4a81-9708-e143fa11724b'] = $pane;
    $display->panels['secondcolumn2'][2] = 'new-91c23893-858f-4a81-9708-e143fa11724b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ea7ad282-bc5e-4de0-876e-d856b3803460';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dashboard'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'welcome_page';
  $page->task = 'page';
  $page->admin_title = 'Welcome page';
  $page->admin_description = '';
  $page->path = 'welcome-page';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_welcome_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'welcome_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Welcome Page (Anonymous users)',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_sutro_double';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'middle' => NULL,
      'secondcolumn1' => NULL,
      'secondcolumn2' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Welcome';
  $display->uuid = '65fa22bb-05c5-4318-b3eb-20181449dc7a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-dffe613f-1c47-410b-ae4d-3b933e350c82';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'civihr_employee_portal-login_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'dffe613f-1c47-410b-ae4d-3b933e350c82';
    $display->content['new-dffe613f-1c47-410b-ae4d-3b933e350c82'] = $pane;
    $display->panels['footer'][0] = 'new-dffe613f-1c47-410b-ae4d-3b933e350c82';
    $pane = new stdClass();
    $pane->pid = 'new-34a8c3b9-acb5-4419-ba57-7ebfc1f3e8f2';
    $pane->panel = 'middle';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '1',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '34a8c3b9-acb5-4419-ba57-7ebfc1f3e8f2';
    $display->content['new-34a8c3b9-acb5-4419-ba57-7ebfc1f3e8f2'] = $pane;
    $display->panels['middle'][0] = 'new-34a8c3b9-acb5-4419-ba57-7ebfc1f3e8f2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-dffe613f-1c47-410b-ae4d-3b933e350c82';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['welcome_page'] = $page;

  return $pages;

}
