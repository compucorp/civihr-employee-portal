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
    $pane->pid = 'new-691f553c-d36d-474b-b89b-c75974eb3eb4';
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
      'css_class' => 'chr_panel chr_panel--no-padding',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '691f553c-d36d-474b-b89b-c75974eb3eb4';
    $display->content['new-691f553c-d36d-474b-b89b-c75974eb3eb4'] = $pane;
    $display->panels['footer'][2] = 'new-691f553c-d36d-474b-b89b-c75974eb3eb4';
    $pane = new stdClass();
    $pane->pid = 'new-691f553c-d36d-474b-b89b-c75974eb3eb5';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '691f553c-d36d-474b-b89b-c75974eb3eb5';
    $display->content['new-691f553c-d36d-474b-b89b-c75974eb3eb5'] = $pane;
    $display->panels['footer'][3] = 'new-691f553c-d36d-474b-b89b-c75974eb3eb5';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0f962e7d-947f-4064-b545-efdf7262a50f';
    $display->content['new-0f962e7d-947f-4064-b545-efdf7262a50f'] = $pane;
    $display->panels['header'][1] = 'new-0f962e7d-947f-4064-b545-efdf7262a50f';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '80f12630-09c3-4ce3-8d65-f766db9a08a9';
    $display->content['new-80f12630-09c3-4ce3-8d65-f766db9a08a9'] = $pane;
    $display->panels['header'][2] = 'new-80f12630-09c3-4ce3-8d65-f766db9a08a9';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'chr_panel chr_panel--no-padding',
    );
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
    $display->panels['secondcolumn1'][0] = 'new-b149e6e0-7df8-46c5-b5b9-085df7ed8a07';
    $pane = new stdClass();
    $pane->pid = 'new-ea7ad282-bc5e-4de0-876e-d856b3803460';
    $pane->panel = 'secondcolumn1';
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
    $display->panels['secondcolumn1'][1] = 'new-ea7ad282-bc5e-4de0-876e-d856b3803460';
    $pane = new stdClass();
    $pane->pid = 'new-90794cd4-53e8-4759-a786-f04977f62c7c';
    $pane->panel = 'secondcolumn2';
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
    $display->panels['secondcolumn2'][0] = 'new-90794cd4-53e8-4759-a786-f04977f62c7c';
    $pane = new stdClass();
    $pane->pid = 'new-73347ee0-93bf-40ac-b270-9e9a46792cf0';
    $pane->panel = 'secondcolumn2';
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

  return $pages;

}
