<?php

$view = new view();
$view->name = 'mydetails_personal';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'MyDetails_Personal';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['css_class'] = 'chr_panel--my-details__view__panel';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view my details';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
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
$handler->display->display_options['footer']['area']['empty'] = TRUE;
$handler->display->display_options['footer']['area']['content'] = '                <a href="/user/!2/edit" class="ctools-modal-civihr-custom-style  btn btn-primary">
                  <i class="fa fa-user" aria-hidden="true"></i> Edit account
                </a>
                <a href="/edit-my-personal-details/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
                  <i class="fa fa-pencil" aria-hidden="true"></i> Edit Personal Details
                </a>

';
$handler->display->display_options['footer']['area']['format'] = 'html_without_filters';
$handler->display->display_options['footer']['area']['tokenize'] = TRUE;
/* Field: CiviCRM Contacts: Contact Image */
$handler->display->display_options['fields']['image_URL']['id'] = 'image_URL';
$handler->display->display_options['fields']['image_URL']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['image_URL']['field'] = 'image_URL';
$handler->display->display_options['fields']['image_URL']['label'] = '';
$handler->display->display_options['fields']['image_URL']['element_type'] = '0';
$handler->display->display_options['fields']['image_URL']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['image_URL']['empty'] = 'no image';
$handler->display->display_options['fields']['image_URL']['empty_zero'] = TRUE;
$handler->display->display_options['fields']['image_URL']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['image_URL']['url_only'] = 0;
$handler->display->display_options['fields']['image_URL']['image_style'] = 'thumbnail';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = '';
$handler->display->display_options['fields']['id']['exclude'] = TRUE;
$handler->display->display_options['fields']['id']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['id']['alter']['text'] = '<div class="chr_panel--my-details__personal__contact_id"><span>ID</span> [id]</div>';
$handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['label'] = 'Name';
$handler->display->display_options['fields']['display_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Contacts: Gender */
$handler->display->display_options['fields']['gender']['id'] = 'gender';
$handler->display->display_options['fields']['gender']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['gender']['field'] = 'gender';
$handler->display->display_options['fields']['gender']['label'] = '';
$handler->display->display_options['fields']['gender']['exclude'] = TRUE;
$handler->display->display_options['fields']['gender']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['gender']['alter']['text'] = '<div class="chr_panel--my-details__personal__gender">[gender]</div>';
$handler->display->display_options['fields']['gender']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['gender']['hide_empty'] = TRUE;
/* Field: CiviCRM Custom: Extended Demographics: Marital Status */
$handler->display->display_options['fields']['marital_status_58']['id'] = 'marital_status_58';
$handler->display->display_options['fields']['marital_status_58']['table'] = 'civicrm_value_extended_demographics_8';
$handler->display->display_options['fields']['marital_status_58']['field'] = 'marital_status_58';
$handler->display->display_options['fields']['marital_status_58']['label'] = '';
$handler->display->display_options['fields']['marital_status_58']['exclude'] = TRUE;
$handler->display->display_options['fields']['marital_status_58']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['marital_status_58']['alter']['text'] = '<div class="chr_panel--my-details__personal__marital_status [marital_status_58]">[marital_status_58]</div>';
$handler->display->display_options['fields']['marital_status_58']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[id] [gender] [marital_status_58]';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: CiviCRM Contacts: Birth Date */
$handler->display->display_options['fields']['birth_date']['id'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['birth_date']['field'] = 'birth_date';
$handler->display->display_options['fields']['birth_date']['label'] = 'Date of Birth';
$handler->display->display_options['fields']['birth_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['birth_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['birth_date']['custom_date_format'] = 'd/m/Y';
$handler->display->display_options['fields']['birth_date']['second_date_format'] = 'long';
/* Field: CiviCRM Custom: Extended Demographics: Nationality */
$handler->display->display_options['fields']['nationality_44']['id'] = 'nationality_44';
$handler->display->display_options['fields']['nationality_44']['table'] = 'civicrm_value_extended_demographics_8';
$handler->display->display_options['fields']['nationality_44']['field'] = 'nationality_44';
$handler->display->display_options['fields']['nationality_44']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nationality_44']['hide_empty'] = TRUE;
/* Contextual filter: CiviCRM Contacts: Contact ID */
$handler->display->display_options['arguments']['id']['id'] = 'id';
$handler->display->display_options['arguments']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['arguments']['id']['field'] = 'id';
$handler->display->display_options['arguments']['id']['default_action'] = 'default';
$handler->display->display_options['arguments']['id']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['id']['default_argument_options']['code'] = 'return CRM_Core_Session::singleton()->getLoggedInContactID();';
$handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
/* Contextual filter: CiviCRM Drupal match table: Drupal User ID */
$handler->display->display_options['arguments']['uf_id']['id'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['table'] = 'civicrm_uf_match';
$handler->display->display_options['arguments']['uf_id']['field'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['uf_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uf_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uf_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uf_id']['summary_options']['items_per_page'] = '25';

/* Display: My Personal Details */
$handler = $view->new_display('block', 'My Personal Details', 'my_personal_details');
$translatables['mydetails_personal'] = array(
  t('Master'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('                <a href="/user/!2/edit" class="ctools-modal-civihr-custom-style  btn btn-primary">
                  <i class="fa fa-user" aria-hidden="true"></i> Edit account
                </a>
                <a href="/edit-my-personal-details/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
                  <i class="fa fa-pencil" aria-hidden="true"></i> Edit Personal Details
                </a>

'),
  t('no image'),
  t('<div class="chr_panel--my-details__personal__contact_id"><span>ID</span> [id]</div>'),
  t('.'),
  t(','),
  t('Name'),
  t('<div class="chr_panel--my-details__personal__gender">[gender]</div>'),
  t('<div class="chr_panel--my-details__personal__marital_status [marital_status_58]">[marital_status_58]</div>'),
  t('[id] [gender] [marital_status_58]'),
  t('Date of Birth'),
  t('Nationality'),
  t('All'),
  t('My Personal Details'),
);
