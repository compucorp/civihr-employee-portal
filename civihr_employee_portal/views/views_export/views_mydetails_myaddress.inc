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
/* Relationship: CiviCRM Contacts: HRJobContract Revision entity */
$handler->display->display_options['relationships']['hrjc_revision']['id'] = 'hrjc_revision';
$handler->display->display_options['relationships']['hrjc_revision']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_revision']['field'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Details_revision_id */
$handler->display->display_options['relationships']['details_revision_id']['id'] = 'details_revision_id';
$handler->display->display_options['relationships']['details_revision_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['details_revision_id']['field'] = 'details_revision_id';
$handler->display->display_options['relationships']['details_revision_id']['relationship'] = 'hrjc_revision';
/* Field: CiviCRM Address: Supplemental Street Address */
$handler->display->display_options['fields']['supplemental_address_1']['id'] = 'supplemental_address_1';
$handler->display->display_options['fields']['supplemental_address_1']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['supplemental_address_1']['field'] = 'supplemental_address_1';
$handler->display->display_options['fields']['supplemental_address_1']['relationship'] = 'id';
$handler->display->display_options['fields']['supplemental_address_1']['label'] = '';
$handler->display->display_options['fields']['supplemental_address_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['supplemental_address_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['supplemental_address_1']['location_type'] = '0';
$handler->display->display_options['fields']['supplemental_address_1']['location_op'] = '0';
$handler->display->display_options['fields']['supplemental_address_1']['is_primary'] = 0;
/* Field: CiviCRM Address: 2nd Supplemental Street Address */
$handler->display->display_options['fields']['supplemental_address_2']['id'] = 'supplemental_address_2';
$handler->display->display_options['fields']['supplemental_address_2']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['supplemental_address_2']['field'] = 'supplemental_address_2';
$handler->display->display_options['fields']['supplemental_address_2']['relationship'] = 'id';
$handler->display->display_options['fields']['supplemental_address_2']['label'] = '';
$handler->display->display_options['fields']['supplemental_address_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['supplemental_address_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['supplemental_address_2']['location_type'] = '0';
$handler->display->display_options['fields']['supplemental_address_2']['location_op'] = '0';
$handler->display->display_options['fields']['supplemental_address_2']['is_primary'] = 0;
/* Field: CiviCRM Address: State/Province */
$handler->display->display_options['fields']['state_province']['id'] = 'state_province';
$handler->display->display_options['fields']['state_province']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['state_province']['field'] = 'state_province';
$handler->display->display_options['fields']['state_province']['relationship'] = 'id';
$handler->display->display_options['fields']['state_province']['label'] = '';
$handler->display->display_options['fields']['state_province']['exclude'] = TRUE;
$handler->display->display_options['fields']['state_province']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['state_province']['location_type'] = '0';
$handler->display->display_options['fields']['state_province']['location_op'] = '0';
$handler->display->display_options['fields']['state_province']['is_primary'] = 0;
/* Field: CiviCRM Address: Full Street Address */
$handler->display->display_options['fields']['street_address']['id'] = 'street_address';
$handler->display->display_options['fields']['street_address']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['street_address']['field'] = 'street_address';
$handler->display->display_options['fields']['street_address']['relationship'] = 'id';
$handler->display->display_options['fields']['street_address']['label'] = 'Home Address';
$handler->display->display_options['fields']['street_address']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['street_address']['alter']['text'] = '[street_address]
[supplemental_address_1]
[supplemental_address_2]
[state_province]';
$handler->display->display_options['fields']['street_address']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['street_address']['location_type'] = '0';
$handler->display->display_options['fields']['street_address']['location_op'] = '0';
$handler->display->display_options['fields']['street_address']['is_primary'] = 0;
/* Field: CiviCRM Address: Country */
$handler->display->display_options['fields']['country_1']['id'] = 'country_1';
$handler->display->display_options['fields']['country_1']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['country_1']['field'] = 'country';
$handler->display->display_options['fields']['country_1']['relationship'] = 'id';
$handler->display->display_options['fields']['country_1']['label'] = '';
$handler->display->display_options['fields']['country_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['country_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['country_1']['location_type'] = '0';
$handler->display->display_options['fields']['country_1']['location_op'] = '0';
$handler->display->display_options['fields']['country_1']['is_primary'] = 0;
$handler->display->display_options['fields']['country_1']['country_display'] = '2';
/* Field: CiviCRM Address: Postal Code */
$handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['relationship'] = 'id';
$handler->display->display_options['fields']['postal_code']['label'] = 'Postcode';
$handler->display->display_options['fields']['postal_code']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['postal_code']['alter']['text'] = '[postal_code]
[country_1]';
$handler->display->display_options['fields']['postal_code']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['postal_code']['location_type'] = '0';
$handler->display->display_options['fields']['postal_code']['location_op'] = '0';
$handler->display->display_options['fields']['postal_code']['is_primary'] = 0;
/* Field: CiviCRM Address: Country */
$handler->display->display_options['fields']['country']['id'] = 'country';
$handler->display->display_options['fields']['country']['table'] = 'civicrm_address';
$handler->display->display_options['fields']['country']['field'] = 'country';
$handler->display->display_options['fields']['country']['relationship'] = 'id';
$handler->display->display_options['fields']['country']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['country']['location_type'] = '0';
$handler->display->display_options['fields']['country']['location_op'] = '0';
$handler->display->display_options['fields']['country']['is_primary'] = 0;

/* Display: Home Address */
$handler = $view->new_display('block', 'Home Address', 'my_address');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['required'] = TRUE;
/* Relationship: CiviCRM Address: Address */
$handler->display->display_options['relationships']['id']['id'] = 'id';
$handler->display->display_options['relationships']['id']['table'] = 'civicrm_address';
$handler->display->display_options['relationships']['id']['field'] = 'id';
$handler->display->display_options['relationships']['id']['relationship'] = 'drupal_id';
$handler->display->display_options['relationships']['id']['label'] = 'Address';
$handler->display->display_options['relationships']['id']['required'] = TRUE;
$handler->display->display_options['relationships']['id']['location_type'] = '6';
$handler->display->display_options['relationships']['id']['location_op'] = '0';
$handler->display->display_options['relationships']['id']['is_primary'] = 1;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: User: Uid */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'users';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['relationship'] = 'drupal_id';
$handler->display->display_options['arguments']['uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
  t('HRJobContract Revision entity'),
  t('HRJobContract Details entity'),
  t('[street_address]
[supplemental_address_1]
[supplemental_address_2]
[state_province]'),
  t('Postcode'),
  t('[postal_code]
[country_1]'),
  t('Country'),
  t('Address'),
  t('All'),
);
