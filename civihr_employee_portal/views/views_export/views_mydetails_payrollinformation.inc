<?php

$view = new view();
$view->name = 'mydetails_payrollinformation';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'MyDetails_PayrollInformation';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Payroll Information';
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
$handler->display->display_options['footer']['area']['content'] = '<a href="/edit-my-payroll/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
                        <i class="fa fa-pencil" aria-hidden="true"></i>
                        Edit payroll information
                      </a>
';
$handler->display->display_options['footer']['area']['format'] = 'html_without_filters';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '<p class="view-empty-message">No payroll information listed!</p>

<div class="chr_panel__footer">
    <div class="chr_actions-wrapper">

<a href="/edit-my-payroll/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
                        <i class="fa fa-plus" aria-hidden="true"></i>
                        Add payroll information
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
/* Field: CiviCRM Custom: Bank Details: Bank Name */
$handler->display->display_options['fields']['bank_name_51']['id'] = 'bank_name_51';
$handler->display->display_options['fields']['bank_name_51']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_name_51']['field'] = 'bank_name_51';
$handler->display->display_options['fields']['bank_name_51']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['bank_name_51']['label'] = '';
$handler->display->display_options['fields']['bank_name_51']['exclude'] = TRUE;
$handler->display->display_options['fields']['bank_name_51']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['bank_name_51']['alter']['text'] = '<div class="views-field views-field-bank-name-51">
   <span class="views-label">
   Bank name
   </span>
   <span class="field-content">
      [bank_name_51]
   </span>
</div>
';
$handler->display->display_options['fields']['bank_name_51']['element_label_colon'] = FALSE;
/* Field: CiviCRM Custom: Bank Details: Account Holder */
$handler->display->display_options['fields']['account_holder_48']['id'] = 'account_holder_48';
$handler->display->display_options['fields']['account_holder_48']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['account_holder_48']['field'] = 'account_holder_48';
$handler->display->display_options['fields']['account_holder_48']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['account_holder_48']['label'] = 'Account holder';
$handler->display->display_options['fields']['account_holder_48']['exclude'] = TRUE;
$handler->display->display_options['fields']['account_holder_48']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['account_holder_48']['alter']['text'] = '<div class="views-field views-field-account-holder-48">
   <span class="views-label views-label-account-holder-48">Account holder</span>
   <span class="field-content">
      [account_holder_48]
   </span>
</div>';
$handler->display->display_options['fields']['account_holder_48']['element_label_colon'] = FALSE;
/* Field: CiviCRM Custom: Bank Details: Sort-Code */
$handler->display->display_options['fields']['sort_code_49']['id'] = 'sort_code_49';
$handler->display->display_options['fields']['sort_code_49']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['sort_code_49']['field'] = 'sort_code_49';
$handler->display->display_options['fields']['sort_code_49']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['sort_code_49']['exclude'] = TRUE;
$handler->display->display_options['fields']['sort_code_49']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['sort_code_49']['alter']['text'] = '<div class="views-field views-field-sort-code-49">
   <span class="views-label views-label-sort-code-49">Sort-Code</span>
   <span class="field-content">
      [sort_code_49]
   </span>
</div>';
$handler->display->display_options['fields']['sort_code_49']['element_label_colon'] = FALSE;
/* Field: CiviCRM Custom: Bank Details: Account No */
$handler->display->display_options['fields']['account_no_50']['id'] = 'account_no_50';
$handler->display->display_options['fields']['account_no_50']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['account_no_50']['field'] = 'account_no_50';
$handler->display->display_options['fields']['account_no_50']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['account_no_50']['exclude'] = TRUE;
$handler->display->display_options['fields']['account_no_50']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['account_no_50']['alter']['text'] = '<div class="views-field views-field-account-no-50">
   <span class="views-label views-label-account-no-50">Account No</span>
   <span class="field-content">
      [account_no_50]
   </span>
</div>
';
$handler->display->display_options['fields']['account_no_50']['element_label_colon'] = FALSE;
/* Field: CiviCRM Custom: Bank Details: Bank Postcode */
$handler->display->display_options['fields']['bank_post_code_55']['id'] = 'bank_post_code_55';
$handler->display->display_options['fields']['bank_post_code_55']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_post_code_55']['field'] = 'bank_post_code_55';
$handler->display->display_options['fields']['bank_post_code_55']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['bank_post_code_55']['label'] = 'Postcode';
$handler->display->display_options['fields']['bank_post_code_55']['exclude'] = TRUE;
$handler->display->display_options['fields']['bank_post_code_55']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['bank_post_code_55']['alter']['text'] = '<div class="views-field views-field-bank-post-code-55">
   <span class="views-label views-label-bank-post-code-55">Postcode</span>
   <span class="field-content">
      [bank_post_code_55]
   </span>
</div>';
$handler->display->display_options['fields']['bank_post_code_55']['element_label_colon'] = FALSE;
/* Field: CiviCRM Custom: Bank Details: Bank Address Line 2 */
$handler->display->display_options['fields']['bank_address_line_2_53']['id'] = 'bank_address_line_2_53';
$handler->display->display_options['fields']['bank_address_line_2_53']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_address_line_2_53']['field'] = 'bank_address_line_2_53';
$handler->display->display_options['fields']['bank_address_line_2_53']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['bank_address_line_2_53']['label'] = '';
$handler->display->display_options['fields']['bank_address_line_2_53']['exclude'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_2_53']['element_label_colon'] = FALSE;
/* Field: CiviCRM Custom: Bank Details: Bank Address Line 3 */
$handler->display->display_options['fields']['bank_address_line_3_54']['id'] = 'bank_address_line_3_54';
$handler->display->display_options['fields']['bank_address_line_3_54']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_address_line_3_54']['field'] = 'bank_address_line_3_54';
$handler->display->display_options['fields']['bank_address_line_3_54']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['bank_address_line_3_54']['label'] = '';
$handler->display->display_options['fields']['bank_address_line_3_54']['exclude'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_3_54']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '[bank_name_51][account_holder_48][sort_code_49][account_no_50][bank_post_code_55]';
$handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
/* Field: CiviCRM Custom: Bank Details: Bank Address Line 1 */
$handler->display->display_options['fields']['bank_address_line_1_52']['id'] = 'bank_address_line_1_52';
$handler->display->display_options['fields']['bank_address_line_1_52']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_address_line_1_52']['field'] = 'bank_address_line_1_52';
$handler->display->display_options['fields']['bank_address_line_1_52']['relationship'] = 'drupal_id';
$handler->display->display_options['fields']['bank_address_line_1_52']['label'] = 'Bank address';
$handler->display->display_options['fields']['bank_address_line_1_52']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_1_52']['alter']['text'] = '[bank_address_line_2_53]
[bank_address_line_3_54]
[bank_address_line_1_52]';
$handler->display->display_options['fields']['bank_address_line_1_52']['element_label_colon'] = FALSE;
/* Filter criterion: CiviCRM Custom: Bank Details: Bank Name */
$handler->display->display_options['filters']['bank_name_51']['id'] = 'bank_name_51';
$handler->display->display_options['filters']['bank_name_51']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['filters']['bank_name_51']['field'] = 'bank_name_51';
$handler->display->display_options['filters']['bank_name_51']['relationship'] = 'drupal_id';
$handler->display->display_options['filters']['bank_name_51']['operator'] = 'not empty';

/* Display: Payroll Information */
$handler = $view->new_display('block', 'Payroll Information', 'my_payroll_information');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: CiviCRM Contacts: Drupal ID */
$handler->display->display_options['relationships']['drupal_id']['id'] = 'drupal_id';
$handler->display->display_options['relationships']['drupal_id']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['drupal_id']['field'] = 'drupal_id';
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
$translatables['mydetails_payrollinformation'] = array(
  t('Master'),
  t('Payroll Information'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('<a href="/edit-my-payroll/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
                        <i class="fa fa-pencil" aria-hidden="true"></i>
                        Edit payroll information
                      </a>
'),
  t('<p class="view-empty-message">No payroll information listed!</p>

<div class="chr_panel__footer">
    <div class="chr_actions-wrapper">

<a href="/edit-my-payroll/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
                        <i class="fa fa-plus" aria-hidden="true"></i>
                        Add payroll information
                      </a>

  </div>
</div>

'),
  t('Drupal User'),
  t('HRJobContract Revision entity'),
  t('HRJobContract Details entity'),
  t('<div class="views-field views-field-bank-name-51">
   <span class="views-label">
   Bank name
   </span>
   <span class="field-content">
      [bank_name_51]
   </span>
</div>
'),
  t('Account holder'),
  t('<div class="views-field views-field-account-holder-48">
   <span class="views-label views-label-account-holder-48">Account holder</span>
   <span class="field-content">
      [account_holder_48]
   </span>
</div>'),
  t('Sort-Code'),
  t('<div class="views-field views-field-sort-code-49">
   <span class="views-label views-label-sort-code-49">Sort-Code</span>
   <span class="field-content">
      [sort_code_49]
   </span>
</div>'),
  t('Account No'),
  t('<div class="views-field views-field-account-no-50">
   <span class="views-label views-label-account-no-50">Account No</span>
   <span class="field-content">
      [account_no_50]
   </span>
</div>
'),
  t('Postcode'),
  t('<div class="views-field views-field-bank-post-code-55">
   <span class="views-label views-label-bank-post-code-55">Postcode</span>
   <span class="field-content">
      [bank_post_code_55]
   </span>
</div>'),
  t('[bank_name_51][account_holder_48][sort_code_49][account_no_50][bank_post_code_55]'),
  t('Bank address'),
  t('[bank_address_line_2_53]
[bank_address_line_3_54]
[bank_address_line_1_52]'),
  t('All'),
);
