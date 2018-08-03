<?php

$view = new view();
$view->name = 'mydetails_notifications__my_payroll';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'mydetails_notifications__my_payroll';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Payroll Information';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '1';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: CiviCRM Custom: Bank Details: Account Holder */
$handler->display->display_options['fields']['account_holder_48']['id'] = 'account_holder_48';
$handler->display->display_options['fields']['account_holder_48']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['account_holder_48']['field'] = 'account_holder_48';
$handler->display->display_options['fields']['account_holder_48']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Bank Details: Account No */
$handler->display->display_options['fields']['account_no_50']['id'] = 'account_no_50';
$handler->display->display_options['fields']['account_no_50']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['account_no_50']['field'] = 'account_no_50';
$handler->display->display_options['fields']['account_no_50']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['account_no_50']['text_format'] = 'html_without_filters';
/* Field: CiviCRM Custom: Bank Details: Bank Address Line 1 */
$handler->display->display_options['fields']['bank_address_line_1_52']['id'] = 'bank_address_line_1_52';
$handler->display->display_options['fields']['bank_address_line_1_52']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_address_line_1_52']['field'] = 'bank_address_line_1_52';
$handler->display->display_options['fields']['bank_address_line_1_52']['exclude'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_1_52']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_1_52']['alter']['text'] = '[bank_address_line_1_52]';
$handler->display->display_options['fields']['bank_address_line_1_52']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_1_52']['element_type'] = 'div';
/* Field: CiviCRM Custom: Bank Details: Bank Address Line 2 */
$handler->display->display_options['fields']['bank_address_line_2_53']['id'] = 'bank_address_line_2_53';
$handler->display->display_options['fields']['bank_address_line_2_53']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_address_line_2_53']['field'] = 'bank_address_line_2_53';
$handler->display->display_options['fields']['bank_address_line_2_53']['exclude'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_2_53']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Bank Details: Bank Address Line 3 */
$handler->display->display_options['fields']['bank_address_line_3_54']['id'] = 'bank_address_line_3_54';
$handler->display->display_options['fields']['bank_address_line_3_54']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_address_line_3_54']['field'] = 'bank_address_line_3_54';
$handler->display->display_options['fields']['bank_address_line_3_54']['label'] = 'Bank Address';
$handler->display->display_options['fields']['bank_address_line_3_54']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_3_54']['alter']['text'] = '[bank_address_line_1_52] [bank_address_line_2_53] [bank_address_line_3_54]';
$handler->display->display_options['fields']['bank_address_line_3_54']['alter']['nl2br'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_3_54']['element_type'] = 'div';
$handler->display->display_options['fields']['bank_address_line_3_54']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['bank_address_line_3_54']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['bank_address_line_3_54']['text_format'] = 'html_without_filters';
/* Field: CiviCRM Custom: Bank Details: Bank Name */
$handler->display->display_options['fields']['bank_name_51']['id'] = 'bank_name_51';
$handler->display->display_options['fields']['bank_name_51']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_name_51']['field'] = 'bank_name_51';
$handler->display->display_options['fields']['bank_name_51']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Bank Details: Bank Postcode */
$handler->display->display_options['fields']['bank_post_code_55']['id'] = 'bank_post_code_55';
$handler->display->display_options['fields']['bank_post_code_55']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['bank_post_code_55']['field'] = 'bank_post_code_55';
$handler->display->display_options['fields']['bank_post_code_55']['alter']['strip_tags'] = TRUE;
/* Field: CiviCRM Custom: Bank Details: Sort-Code */
$handler->display->display_options['fields']['sort_code_49']['id'] = 'sort_code_49';
$handler->display->display_options['fields']['sort_code_49']['table'] = 'civicrm_value_bank_details_9';
$handler->display->display_options['fields']['sort_code_49']['field'] = 'sort_code_49';
$handler->display->display_options['fields']['sort_code_49']['alter']['strip_tags'] = TRUE;
/* Contextual filter: CiviCRM Drupal match table: Drupal User ID */
$handler->display->display_options['arguments']['uf_id']['id'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['table'] = 'civicrm_uf_match';
$handler->display->display_options['arguments']['uf_id']['field'] = 'uf_id';
$handler->display->display_options['arguments']['uf_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['uf_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uf_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uf_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uf_id']['summary_options']['items_per_page'] = '25';
$translatables['mydetails_notifications__my_payroll'] = array(
  t('Master'),
  t('Payroll Information'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Account Holder'),
  t('Account No'),
  t('Bank Address Line 1'),
  t('[bank_address_line_1_52]'),
  t('Bank Address Line 2'),
  t('Bank Address'),
  t('[bank_address_line_1_52] [bank_address_line_2_53] [bank_address_line_3_54]'),
  t('Bank Name'),
  t('Bank Postcode'),
  t('Sort-Code'),
  t('All'),
);
