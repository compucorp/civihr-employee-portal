<?php
/**
 * @file
 * civihr_employee_portal_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function civihr_employee_portal_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_home:dashboard
  $menu_links['main-menu_home:dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_home:dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Home');


  return $menu_links;
}
