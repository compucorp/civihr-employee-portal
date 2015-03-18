<?php
/**
 * @file
 * civihr_contact_summary_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function civihr_contact_summary_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contact_summary_civicrm_tab';
  $page->task = 'page';
  $page->admin_title = 'Contact Summary CiviCRM tab';
  $page->admin_description = '';
  $page->path = 'contact-summary';
  $page->access = array(
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
  $handler->name = 'page_contact_summary_civicrm_tab__panel_context_c7fe58bd-dda7-481e-8b0f-0894ef2b14de';
  $handler->task = 'page';
  $handler->subtask = 'contact_summary_civicrm_tab';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
  $display->layout = 'radix_bryant';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '72210891-806a-43c5-88e2-1cff4d398271';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1164b384-5cf3-4b0c-9a32-76d90dfadea6';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'views-c93388d640fa5c274c1264d994f7e882';
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
    $pane->uuid = '1164b384-5cf3-4b0c-9a32-76d90dfadea6';
    $display->content['new-1164b384-5cf3-4b0c-9a32-76d90dfadea6'] = $pane;
    $display->panels['sidebar'][0] = 'new-1164b384-5cf3-4b0c-9a32-76d90dfadea6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contact_summary_civicrm_tab'] = $page;

  return $pages;

}
