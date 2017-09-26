<?php
/**
 * @file
 * onboarding_slideshow.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function onboarding_slideshow_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_welcome-slideshow:node/add/welcome-slideshow.
  $menu_links['navigation_welcome-slideshow:node/add/welcome-slideshow'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/welcome-slideshow',
    'router_path' => 'node/add/welcome-slideshow',
    'link_title' => 'Welcome Slideshow',
    'options' => array(
      'attributes' => array(
        'title' => 'Slideshow images for the end of the onboarding form.',
      ),
      'identifier' => 'navigation_welcome-slideshow:node/add/welcome-slideshow',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Welcome Slideshow');

  return $menu_links;
}
