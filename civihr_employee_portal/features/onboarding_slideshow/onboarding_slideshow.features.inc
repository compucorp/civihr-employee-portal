<?php
/**
 * @file
 * onboarding_slideshow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function onboarding_slideshow_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function onboarding_slideshow_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function onboarding_slideshow_node_info() {
  $items = array(
    'welcome_slideshow' => array(
      'name' => t('Welcome Slideshow'),
      'base' => 'node_content',
      'description' => t('Slideshow images for the end of the onboarding form.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
