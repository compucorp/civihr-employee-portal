<?php
/**
 * @file
 * civihr_employee_portal_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function civihr_employee_portal_features_default_page_manager_pages() {
  $pages['dashboard'] = _employee_portal_features_build_default_dashboard_page();
  $pages['manager_absence_approval'] = _employee_portal_features_build_default_absence_approval_page();
  $pages['welcome_page'] = _employee_portal_features_build_default_welcome_page();
  $pages['tasks_and_documents'] = _employee_portal_features_build_default_tasks_and_documents_page();

  return $pages;
}

function _employee_portal_features_build_default_tasks_and_documents_page() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'tasks_and_documents';
  $page->task = 'page';
  $page->admin_title = 'Tasks and Documents';
  $page->admin_description = '';
  $page->path = 'tasks-and-documents';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Tasks and Documents',
    'name' => 'main-menu',
    'weight' => '10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_tasks_and_documents__panel_context_eb7dd441-1a8d-414e-96d8-77255ce14124';
  $handler->task = 'page';
  $handler->subtask = 'tasks_and_documents';
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
    'name' => '',
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
  $display->title = 'Tasks and Documents';
  $display->uuid = '091af8a4-cb6d-45b4-8946-1016cd5fb4d8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0f962e7d-947f-4064-b545-efdf7262a50f';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'views-Tasks-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'chr_panel chr_panel--no-padding chr_panel--tasks',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0f962e7d-947f-4064-b545-efdf7262a50f';
  $display->content['new-0f962e7d-947f-4064-b545-efdf7262a50f'] = $pane;
  $display->panels['header'][0] = 'new-0f962e7d-947f-4064-b545-efdf7262a50f';
  $pane = new stdClass();
  $pane->pid = 'new-7bc09b07-84d8-44a5-9f7b-1ac1e4cfcd0a';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-hr_documents-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7bc09b07-84d8-44a5-9f7b-1ac1e4cfcd0a';
  $display->content['new-7bc09b07-84d8-44a5-9f7b-1ac1e4cfcd0a'] = $pane;
  $display->panels['middle'][0] = 'new-7bc09b07-84d8-44a5-9f7b-1ac1e4cfcd0a';
  $pane = new stdClass();
  $pane->pid = 'new-691f553c-d36d-474b-b89b-c75974eb3eb4';
  $pane->panel = 'middle';
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
    'css_class' => 'chr_panel chr_panel--no-padding',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '691f553c-d36d-474b-b89b-c75974eb3eb4';
  $display->content['new-691f553c-d36d-474b-b89b-c75974eb3eb4'] = $pane;
  $display->panels['middle'][1] = 'new-691f553c-d36d-474b-b89b-c75974eb3eb4';
  $pane = new stdClass();
  $pane->pid = 'new-691f553c-d36d-474b-b89b-c75974eb3eb5';
  $pane->panel = 'middle';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '691f553c-d36d-474b-b89b-c75974eb3eb5';
  $display->content['new-691f553c-d36d-474b-b89b-c75974eb3eb5'] = $pane;
  $display->panels['middle'][2] = 'new-691f553c-d36d-474b-b89b-c75974eb3eb5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  return $page;
}

function _employee_portal_features_build_default_dashboard_page() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dashboard';
  $page->task = 'page';
  $page->admin_title = 'Dashboard';
  $page->admin_description = '';
  $page->path = 'dashboard';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7bc09b07-84d8-44a5-9f7b-1ac1e4cfcd0a';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'views-hr_documents-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7bc09b07-84d8-44a5-9f7b-1ac1e4cfcd0a';
  $display->content['new-7bc09b07-84d8-44a5-9f7b-1ac1e4cfcd0a'] = $pane;
  $display->panels['footer'][0] = 'new-7bc09b07-84d8-44a5-9f7b-1ac1e4cfcd0a';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b1c02e0a-90d6-490f-8134-69dc9205bc21';
  $display->content['new-b1c02e0a-90d6-490f-8134-69dc9205bc21'] = $pane;
  $display->panels['footer'][1] = 'new-b1c02e0a-90d6-490f-8134-69dc9205bc21';
  $pane = new stdClass();
  $pane->pid = 'new-48897dc2-d49e-4e72-b86a-7ec70b28da04';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'civihr_employee_portal-my_details';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view my details',
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'chr_panel chr_panel--my-details',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '48897dc2-d49e-4e72-b86a-7ec70b28da04';
  $display->content['new-48897dc2-d49e-4e72-b86a-7ec70b28da04'] = $pane;
  $display->panels['header'][0] = 'new-48897dc2-d49e-4e72-b86a-7ec70b28da04';
  $pane = new stdClass();
  $pane->pid = 'new-80f12630-09c3-4ce3-8d65-f766db9a08a9';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'views-appraisals-appraisals_employee';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '80f12630-09c3-4ce3-8d65-f766db9a08a9';
  $display->content['new-80f12630-09c3-4ce3-8d65-f766db9a08a9'] = $pane;
  $display->panels['header'][1] = 'new-80f12630-09c3-4ce3-8d65-f766db9a08a9';
  $pane = new stdClass();
  $pane->pid = 'new-b149e6e0-7df8-46c5-b5b9-085df7ed8a07';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-absence_list-page';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'My Leave',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'chr_panel chr_panel__header--w-actions',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b149e6e0-7df8-46c5-b5b9-085df7ed8a07';
  $display->content['new-b149e6e0-7df8-46c5-b5b9-085df7ed8a07'] = $pane;
  $display->panels['middle'][0] = 'new-b149e6e0-7df8-46c5-b5b9-085df7ed8a07';
  $pane = new stdClass();
  $pane->pid = 'new-ea7ad282-bc5e-4de0-876e-d856b3803460';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'civihr_employee_portal-leave';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view my leave block',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
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
  $display->panels['middle'][1] = 'new-ea7ad282-bc5e-4de0-876e-d856b3803460';
  $pane = new stdClass();
  $pane->pid = 'new-90794cd4-53e8-4759-a786-f04977f62c7c';
  $pane->panel = 'secondcolumn1';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-absence_list-page_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'My Sickness Report',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'chr_panel chr_panel__header--w-actions',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '90794cd4-53e8-4759-a786-f04977f62c7c';
  $display->content['new-90794cd4-53e8-4759-a786-f04977f62c7c'] = $pane;
  $display->panels['secondcolumn1'][0] = 'new-90794cd4-53e8-4759-a786-f04977f62c7c';
  $pane = new stdClass();
  $pane->pid = 'new-73347ee0-93bf-40ac-b270-9e9a46792cf0';
  $pane->panel = 'secondcolumn1';
  $pane->type = 'block';
  $pane->subtype = 'civihr_employee_portal-sick';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view my sickness report block',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
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
  $display->panels['secondcolumn1'][1] = 'new-73347ee0-93bf-40ac-b270-9e9a46792cf0';
  $pane = new stdClass();
  $pane->pid = 'new-91c23893-858f-4a81-9708-e143fa11724b';
  $pane->panel = 'secondcolumn2';
  $pane->type = 'block';
  $pane->subtype = 'civihr_employee_portal-staff_directory_block';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view staff directory',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '91c23893-858f-4a81-9708-e143fa11724b';
  $display->content['new-91c23893-858f-4a81-9708-e143fa11724b'] = $pane;
  $display->panels['secondcolumn2'][0] = 'new-91c23893-858f-4a81-9708-e143fa11724b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ea7ad282-bc5e-4de0-876e-d856b3803460';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  return $page;
}

function _employee_portal_features_build_default_absence_approval_page() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'manager_absence_approval';
  $page->task = 'page';
  $page->admin_title = 'Manager Absence Approval';
  $page->admin_description = '';
  $page->path = 'manager-absence-approval';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access manager approval screen',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Manager Absence Approval',
    'name' => 'main-menu',
    'weight' => '21',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_manager_absence_approval__panel_context_20fb9bcb-9a86-41c8-ba3b-ffe986c811cc';
  $handler->task = 'page';
  $handler->subtask = 'manager_absence_approval';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Manager Absence Approval',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'manager-absence-approval-page',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1d65d481-33ec-46fe-9f4c-a2dd99e7b2eb';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1647dd09-dad7-4648-b088-0c4ef71c085e';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'views-approvals-block_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1647dd09-dad7-4648-b088-0c4ef71c085e';
  $display->content['new-1647dd09-dad7-4648-b088-0c4ef71c085e'] = $pane;
  $display->panels['contentmain'][0] = 'new-1647dd09-dad7-4648-b088-0c4ef71c085e';
  $pane = new stdClass();
  $pane->pid = 'new-83f8a7cb-999a-4903-aacc-9127245f3eeb';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'civihr_employee_portal-manager_calendar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '83f8a7cb-999a-4903-aacc-9127245f3eeb';
  $display->content['new-83f8a7cb-999a-4903-aacc-9127245f3eeb'] = $pane;
  $display->panels['contentmain'][1] = 'new-83f8a7cb-999a-4903-aacc-9127245f3eeb';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-1647dd09-dad7-4648-b088-0c4ef71c085e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  return $page;
}

function _employee_portal_features_build_default_welcome_page() {
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'radix_geary';
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
      'column3' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = '65fa22bb-05c5-4318-b3eb-20181449dc7a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_welcome_page_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-889a60ef-1b56-4330-85cf-d3c0f25fcc01';
  $pane->panel = 'column2';
  $pane->type = 'page_logo';
  $pane->subtype = 'page_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'block-welcome-logo',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '889a60ef-1b56-4330-85cf-d3c0f25fcc01';
  $display->content['new-889a60ef-1b56-4330-85cf-d3c0f25fcc01'] = $pane;
  $display->panels['column2'][0] = 'new-889a60ef-1b56-4330-85cf-d3c0f25fcc01';
  $pane = new stdClass();
  $pane->pid = 'new-3b43f2a1-c244-4018-adcc-ee092c4fa9d8';
  $pane->panel = 'column2';
  $pane->type = 'page_site_name';
  $pane->subtype = 'page_site_name';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'linked' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'block-welcome-sitename',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3b43f2a1-c244-4018-adcc-ee092c4fa9d8';
  $display->content['new-3b43f2a1-c244-4018-adcc-ee092c4fa9d8'] = $pane;
  $display->panels['column2'][1] = 'new-3b43f2a1-c244-4018-adcc-ee092c4fa9d8';
  $pane = new stdClass();
  $pane->pid = 'new-6f7f063d-ef96-4a44-8e20-921039687b30';
  $pane->panel = 'column2';
  $pane->type = 'page_slogan';
  $pane->subtype = 'page_slogan';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'block-welcome-slogan',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6f7f063d-ef96-4a44-8e20-921039687b30';
  $display->content['new-6f7f063d-ef96-4a44-8e20-921039687b30'] = $pane;
  $display->panels['column2'][2] = 'new-6f7f063d-ef96-4a44-8e20-921039687b30';
  $pane = new stdClass();
  $pane->pid = 'new-f122256d-6524-48e1-a630-60a24dfb412e';
  $pane->panel = 'column2';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Login:',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f122256d-6524-48e1-a630-60a24dfb412e';
  $display->content['new-f122256d-6524-48e1-a630-60a24dfb412e'] = $pane;
  $display->panels['column2'][3] = 'new-f122256d-6524-48e1-a630-60a24dfb412e';
  $pane = new stdClass();
  $pane->pid = 'new-c1e74a5e-1513-4ae2-bd55-e097b00d3575';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p class="text-center">Don\'t have a login?
          <a href="/request_new_account/nojs" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed" title="Request new account">Click here to request one from your HR administrator</a></p>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'c1e74a5e-1513-4ae2-bd55-e097b00d3575';
  $display->content['new-c1e74a5e-1513-4ae2-bd55-e097b00d3575'] = $pane;
  $display->panels['column2'][4] = 'new-c1e74a5e-1513-4ae2-bd55-e097b00d3575';
  $pane = new stdClass();
  $pane->pid = 'new-34a8c3b9-acb5-4419-ba57-7ebfc1f3e8f2';
  $pane->panel = 'header';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 30037204,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
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
  $display->panels['header'][0] = 'new-34a8c3b9-acb5-4419-ba57-7ebfc1f3e8f2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  return $page;
}
