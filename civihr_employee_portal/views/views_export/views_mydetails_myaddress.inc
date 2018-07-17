<?php

$view = new view();
$view->name = 'mydetails_myaddress';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'MyDetails_MyAddress';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Home Address';
$handler->display->display_options['css_class'] = 'chr_panel--my-details__view__panel';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view my details';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
/* Footer: Global: Text area */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['content'] = '<a href="/edit-my-home-address/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
  <i class="fa fa-pencil" aria-hidden="true"></i>
    Edit my address
</a>
';
$handler->display->display_options['footer']['area']['format'] = 'html_without_filters';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '<p class="view-empty-message">No home address listed!</p>

<div class="chr_panel__footer">
    <div class="chr_actions-wrapper">

<a href="/edit-my-home-address/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
                        <i class="fa fa-plus" aria-hidden="true"></i>
                        Add home address
                      </a>

  </div>
</div>

';
$handler->display->display_options['empty']['area']['format'] = 'html_without_filters';
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
/* Field: CiviCRM Address: Contact ID */
$handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
$handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
/* Field: CiviCRM Contacts: Aggregated Contact Home Address */
$handler->display->display_options['fields']['aggregated_personal_address']['id'] = 'aggregated_personal_address';
$handler->display->display_options['fields']['aggregated_personal_address']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['aggregated_personal_address']['field'] = 'aggregated_personal_address';
$handler->display->display_options['fields']['aggregated_personal_address']['label'] = '';
$handler->display->display_options['fields']['aggregated_personal_address']['element_type'] = '0';
$handler->display->display_options['fields']['aggregated_personal_address']['element_label_type'] = '0';
$handler->display->display_options['fields']['aggregated_personal_address']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['aggregated_personal_address']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['aggregated_personal_address']['element_default_classes'] = FALSE;
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['uid_current']['value'] = '1';

/* Display: Home Address */
$handler = $view->new_display('block', 'Home Address', 'my_address');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['defaults']['arguments'] = FALSE;
$translatables['mydetails_myaddress'] = array(
  t('Master'),
  t('Home Address'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('<a href="/edit-my-home-address/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
  <i class="fa fa-pencil" aria-hidden="true"></i>
    Edit my address
</a>
'),
  t('<p class="view-empty-message">No home address listed!</p>

<div class="chr_panel__footer">
    <div class="chr_actions-wrapper">

<a href="/edit-my-home-address/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
                        <i class="fa fa-plus" aria-hidden="true"></i>
                        Add home address
                      </a>

  </div>
</div>

'),
  t('Drupal User'),
  t('Contact ID'),
  t('.'),
  t(','),
);
