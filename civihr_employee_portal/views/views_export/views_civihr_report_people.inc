<?php

$view = new view();
$view->name = 'civihr_report_people';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'civicrm_contact';
$view->human_name = 'CiviHR Report - People';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'CiviHR Report - People';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
/* Relationship: CiviCRM Contacts: HRJobContract Revision entity */
$handler->display->display_options['relationships']['hrjc_revision']['id'] = 'hrjc_revision';
$handler->display->display_options['relationships']['hrjc_revision']['table'] = 'civicrm_contact';
$handler->display->display_options['relationships']['hrjc_revision']['field'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Details_revision_id */
$handler->display->display_options['relationships']['details_revision_id']['id'] = 'details_revision_id';
$handler->display->display_options['relationships']['details_revision_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['details_revision_id']['field'] = 'details_revision_id';
$handler->display->display_options['relationships']['details_revision_id']['relationship'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Health_revision_id */
$handler->display->display_options['relationships']['health_revision_id']['id'] = 'health_revision_id';
$handler->display->display_options['relationships']['health_revision_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['health_revision_id']['field'] = 'health_revision_id';
$handler->display->display_options['relationships']['health_revision_id']['relationship'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Hour_revision_id */
$handler->display->display_options['relationships']['hour_revision_id']['id'] = 'hour_revision_id';
$handler->display->display_options['relationships']['hour_revision_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['hour_revision_id']['field'] = 'hour_revision_id';
$handler->display->display_options['relationships']['hour_revision_id']['relationship'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Pay_revision_id */
$handler->display->display_options['relationships']['pay_revision_id']['id'] = 'pay_revision_id';
$handler->display->display_options['relationships']['pay_revision_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['pay_revision_id']['field'] = 'pay_revision_id';
$handler->display->display_options['relationships']['pay_revision_id']['relationship'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Pension_revision_id */
$handler->display->display_options['relationships']['pension_revision_id']['id'] = 'pension_revision_id';
$handler->display->display_options['relationships']['pension_revision_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['pension_revision_id']['field'] = 'pension_revision_id';
$handler->display->display_options['relationships']['pension_revision_id']['relationship'] = 'hrjc_revision';
/* Relationship: HRJobContract Revision entity: Role_jobcontract_id */
$handler->display->display_options['relationships']['role_jobcontract_id']['id'] = 'role_jobcontract_id';
$handler->display->display_options['relationships']['role_jobcontract_id']['table'] = 'hrjc_revision';
$handler->display->display_options['relationships']['role_jobcontract_id']['field'] = 'role_jobcontract_id';
$handler->display->display_options['relationships']['role_jobcontract_id']['relationship'] = 'hrjc_revision';
/* Field: CiviCRM Contacts: Contact ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Employee ID';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: CiviCRM Contacts: Display Name */
$handler->display->display_options['fields']['display_name']['id'] = 'display_name';
$handler->display->display_options['fields']['display_name']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['display_name']['field'] = 'display_name';
$handler->display->display_options['fields']['display_name']['label'] = 'Employee display name';
$handler->display->display_options['fields']['display_name']['link_to_civicrm_contact'] = 0;
/* Field: CiviCRM Contacts: Age */
$handler->display->display_options['fields']['age']['id'] = 'age';
$handler->display->display_options['fields']['age']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['age']['field'] = 'age';
$handler->display->display_options['fields']['age']['label'] = 'Employee age';
/* Field: CiviCRM Contacts: Age Group */
$handler->display->display_options['fields']['age_group']['id'] = 'age_group';
$handler->display->display_options['fields']['age_group']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['age_group']['field'] = 'age_group';
$handler->display->display_options['fields']['age_group']['label'] = 'Employee age group';
/* Field: CiviCRM Contacts: Gender */
$handler->display->display_options['fields']['gender']['id'] = 'gender';
$handler->display->display_options['fields']['gender']['table'] = 'civicrm_contact';
$handler->display->display_options['fields']['gender']['field'] = 'gender';
$handler->display->display_options['fields']['gender']['label'] = 'Employee gender';
/* Field: CiviCRM Custom: Contact Length of Service: Length of Service */
$handler->display->display_options['fields']['length_of_service']['id'] = 'length_of_service';
$handler->display->display_options['fields']['length_of_service']['table'] = 'civicrm_value_length_of_service_11';
$handler->display->display_options['fields']['length_of_service']['field'] = 'length_of_service';
$handler->display->display_options['fields']['length_of_service']['label'] = 'Employee length of service';
$handler->display->display_options['fields']['length_of_service']['separator'] = '';
/* Field: HRJobContract Revision entity: Jobcontract_id */
$handler->display->display_options['fields']['jobcontract_id']['id'] = 'jobcontract_id';
$handler->display->display_options['fields']['jobcontract_id']['table'] = 'hrjc_revision';
$handler->display->display_options['fields']['jobcontract_id']['field'] = 'jobcontract_id';
$handler->display->display_options['fields']['jobcontract_id']['relationship'] = 'hrjc_revision';
$handler->display->display_options['fields']['jobcontract_id']['label'] = 'Contract ID';
$handler->display->display_options['fields']['jobcontract_id']['separator'] = '';
/* Field: HRJobContract Details entity: Contract_type */
$handler->display->display_options['fields']['contract_type']['id'] = 'contract_type';
$handler->display->display_options['fields']['contract_type']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['contract_type']['field'] = 'contract_type';
$handler->display->display_options['fields']['contract_type']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['contract_type']['label'] = 'Contract type';
/* Field: HRJobContract Details entity: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['title']['label'] = 'Contract title';
/* Field: HRJobContract Details entity: Position */
$handler->display->display_options['fields']['position']['id'] = 'position';
$handler->display->display_options['fields']['position']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['position']['field'] = 'position';
$handler->display->display_options['fields']['position']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['position']['label'] = 'Contract position';
/* Field: HRJobContract Details entity: Period start date */
$handler->display->display_options['fields']['period_start_date']['id'] = 'period_start_date';
$handler->display->display_options['fields']['period_start_date']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['period_start_date']['field'] = 'period_start_date';
$handler->display->display_options['fields']['period_start_date']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['period_start_date']['label'] = 'Contract start date';
/* Field: HRJobContract Details entity: Period end date */
$handler->display->display_options['fields']['period_end_date']['id'] = 'period_end_date';
$handler->display->display_options['fields']['period_end_date']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['period_end_date']['field'] = 'period_end_date';
$handler->display->display_options['fields']['period_end_date']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['period_end_date']['label'] = 'Contract end date';
/* Field: HRJobContract Details entity: Period_start_month */
$handler->display->display_options['fields']['period_start_month']['id'] = 'period_start_month';
$handler->display->display_options['fields']['period_start_month']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['period_start_month']['field'] = 'period_start_month';
$handler->display->display_options['fields']['period_start_month']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['period_start_month']['label'] = 'Contract start date (grouped by month)';
/* Field: HRJobContract Details entity: Period_end_month */
$handler->display->display_options['fields']['period_end_month']['id'] = 'period_end_month';
$handler->display->display_options['fields']['period_end_month']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['period_end_month']['field'] = 'period_end_month';
$handler->display->display_options['fields']['period_end_month']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['period_end_month']['label'] = 'Contract end date (grouped by month)';
/* Field: HRJobContract Details entity: Contract end reason */
$handler->display->display_options['fields']['end_reason']['id'] = 'end_reason';
$handler->display->display_options['fields']['end_reason']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['end_reason']['field'] = 'end_reason';
$handler->display->display_options['fields']['end_reason']['relationship'] = 'details_revision_id';
/* Field: HRJobContract Details entity: Location */
$handler->display->display_options['fields']['location']['id'] = 'location';
$handler->display->display_options['fields']['location']['table'] = 'hrjc_details';
$handler->display->display_options['fields']['location']['field'] = 'location';
$handler->display->display_options['fields']['location']['relationship'] = 'details_revision_id';
$handler->display->display_options['fields']['location']['label'] = 'Contract Normal Place of Work';
/* Field: HRJobContract Hour entity: Contract location standard hours */
$handler->display->display_options['fields']['location_standard_hours']['id'] = 'location_standard_hours';
$handler->display->display_options['fields']['location_standard_hours']['table'] = 'hrjc_hour';
$handler->display->display_options['fields']['location_standard_hours']['field'] = 'location_standard_hours';
$handler->display->display_options['fields']['location_standard_hours']['relationship'] = 'hour_revision_id';
/* Field: HRJobContract Hour entity: Hours_type */
$handler->display->display_options['fields']['hours_type']['id'] = 'hours_type';
$handler->display->display_options['fields']['hours_type']['table'] = 'hrjc_hour';
$handler->display->display_options['fields']['hours_type']['field'] = 'hours_type';
$handler->display->display_options['fields']['hours_type']['relationship'] = 'hour_revision_id';
$handler->display->display_options['fields']['hours_type']['label'] = 'Contract hours type';
/* Field: HRJobContract Pay entity: Is_paid */
$handler->display->display_options['fields']['is_paid']['id'] = 'is_paid';
$handler->display->display_options['fields']['is_paid']['table'] = 'hrjc_pay';
$handler->display->display_options['fields']['is_paid']['field'] = 'is_paid';
$handler->display->display_options['fields']['is_paid']['relationship'] = 'pay_revision_id';
$handler->display->display_options['fields']['is_paid']['label'] = 'Contract is paid';
/* Field: HRJobContract Pay entity: Contract pay scale */
$handler->display->display_options['fields']['pay_scale']['id'] = 'pay_scale';
$handler->display->display_options['fields']['pay_scale']['table'] = 'hrjc_pay';
$handler->display->display_options['fields']['pay_scale']['field'] = 'pay_scale';
$handler->display->display_options['fields']['pay_scale']['relationship'] = 'pay_revision_id';
/* Field: HRJobContract Pay entity: Pay_amount */
$handler->display->display_options['fields']['pay_amount']['id'] = 'pay_amount';
$handler->display->display_options['fields']['pay_amount']['table'] = 'hrjc_pay';
$handler->display->display_options['fields']['pay_amount']['field'] = 'pay_amount';
$handler->display->display_options['fields']['pay_amount']['relationship'] = 'pay_revision_id';
$handler->display->display_options['fields']['pay_amount']['label'] = 'Contract pay amount';
/* Field: HRJobContract Pay entity: Pay_currency */
$handler->display->display_options['fields']['pay_currency']['id'] = 'pay_currency';
$handler->display->display_options['fields']['pay_currency']['table'] = 'hrjc_pay';
$handler->display->display_options['fields']['pay_currency']['field'] = 'pay_currency';
$handler->display->display_options['fields']['pay_currency']['relationship'] = 'pay_revision_id';
$handler->display->display_options['fields']['pay_currency']['label'] = 'Contract pay currency';
/* Field: HRJobContract Pay entity: Pay_unit */
$handler->display->display_options['fields']['pay_unit']['id'] = 'pay_unit';
$handler->display->display_options['fields']['pay_unit']['table'] = 'hrjc_pay';
$handler->display->display_options['fields']['pay_unit']['field'] = 'pay_unit';
$handler->display->display_options['fields']['pay_unit']['relationship'] = 'pay_revision_id';
$handler->display->display_options['fields']['pay_unit']['label'] = 'Contract pay unit';
/* Field: HRJobContract Pension entity: Contract pension is enrolled */
$handler->display->display_options['fields']['is_enrolled']['id'] = 'is_enrolled';
$handler->display->display_options['fields']['is_enrolled']['table'] = 'hrjc_pension';
$handler->display->display_options['fields']['is_enrolled']['field'] = 'is_enrolled';
$handler->display->display_options['fields']['is_enrolled']['relationship'] = 'pension_revision_id';
/* Field: HRJobContract Hour entity: Hours_fte */
$handler->display->display_options['fields']['hours_fte']['id'] = 'hours_fte';
$handler->display->display_options['fields']['hours_fte']['table'] = 'hrjc_hour';
$handler->display->display_options['fields']['hours_fte']['field'] = 'hours_fte';
$handler->display->display_options['fields']['hours_fte']['relationship'] = 'hour_revision_id';
$handler->display->display_options['fields']['hours_fte']['label'] = 'Contract hours FTE';
/* Field: HRJobContract Role entity: Role_id */
$handler->display->display_options['fields']['role_id']['id'] = 'role_id';
$handler->display->display_options['fields']['role_id']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_id']['field'] = 'role_id';
$handler->display->display_options['fields']['role_id']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_id']['label'] = 'Role ID';
$handler->display->display_options['fields']['role_id']['separator'] = '';
/* Field: HRJobContract Role entity: Role start date */
$handler->display->display_options['fields']['role_start_date']['id'] = 'role_start_date';
$handler->display->display_options['fields']['role_start_date']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_start_date']['field'] = 'role_start_date';
$handler->display->display_options['fields']['role_start_date']['relationship'] = 'role_jobcontract_id';
/* Field: HRJobContract Role entity: Role end date */
$handler->display->display_options['fields']['role_end_date']['id'] = 'role_end_date';
$handler->display->display_options['fields']['role_end_date']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_end_date']['field'] = 'role_end_date';
$handler->display->display_options['fields']['role_end_date']['relationship'] = 'role_jobcontract_id';
/* Field: HRJobContract Role entity: Role_start_month */
$handler->display->display_options['fields']['role_start_month']['id'] = 'role_start_month';
$handler->display->display_options['fields']['role_start_month']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_start_month']['field'] = 'role_start_month';
$handler->display->display_options['fields']['role_start_month']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_start_month']['label'] = 'Role start date (grouped by month)';
/* Field: HRJobContract Role entity: Role_end_month */
$handler->display->display_options['fields']['role_end_month']['id'] = 'role_end_month';
$handler->display->display_options['fields']['role_end_month']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_end_month']['field'] = 'role_end_month';
$handler->display->display_options['fields']['role_end_month']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_end_month']['label'] = 'Role end date (grouped by month)';
/* Field: HRJobContract Role entity: Role_title */
$handler->display->display_options['fields']['role_title']['id'] = 'role_title';
$handler->display->display_options['fields']['role_title']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_title']['field'] = 'role_title';
$handler->display->display_options['fields']['role_title']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_title']['label'] = 'Role title';
/* Field: HRJobContract Role entity: Role_description */
$handler->display->display_options['fields']['role_description']['id'] = 'role_description';
$handler->display->display_options['fields']['role_description']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_description']['field'] = 'role_description';
$handler->display->display_options['fields']['role_description']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_description']['label'] = 'Role description';
/* Field: HRJobContract Role entity: Role_location */
$handler->display->display_options['fields']['role_location']['id'] = 'role_location';
$handler->display->display_options['fields']['role_location']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_location']['field'] = 'role_location';
$handler->display->display_options['fields']['role_location']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_location']['label'] = 'Role location';
/* Field: HRJobContract Role entity: Role funder */
$handler->display->display_options['fields']['role_funder']['id'] = 'role_funder';
$handler->display->display_options['fields']['role_funder']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_funder']['field'] = 'role_funder';
$handler->display->display_options['fields']['role_funder']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_funder']['exclude'] = TRUE;
/* Field: HRJobContract Role entity: Role percent pay funder */
$handler->display->display_options['fields']['role_percent_pay_funder']['id'] = 'role_percent_pay_funder';
$handler->display->display_options['fields']['role_percent_pay_funder']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_percent_pay_funder']['field'] = 'role_percent_pay_funder';
$handler->display->display_options['fields']['role_percent_pay_funder']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_percent_pay_funder']['exclude'] = TRUE;
/* Field: HRJobContract Role entity: Role cost center */
$handler->display->display_options['fields']['role_cost_center']['id'] = 'role_cost_center';
$handler->display->display_options['fields']['role_cost_center']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_cost_center']['field'] = 'role_cost_center';
$handler->display->display_options['fields']['role_cost_center']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_cost_center']['exclude'] = TRUE;
/* Field: HRJobContract Role entity: Role percent pay cost center */
$handler->display->display_options['fields']['role_percent_pay_cost_center']['id'] = 'role_percent_pay_cost_center';
$handler->display->display_options['fields']['role_percent_pay_cost_center']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_percent_pay_cost_center']['field'] = 'role_percent_pay_cost_center';
$handler->display->display_options['fields']['role_percent_pay_cost_center']['relationship'] = 'role_jobcontract_id';
/* Field: HRJobContract Role entity: Role_department */
$handler->display->display_options['fields']['role_department']['id'] = 'role_department';
$handler->display->display_options['fields']['role_department']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_department']['field'] = 'role_department';
$handler->display->display_options['fields']['role_department']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_department']['label'] = 'Role department';
/* Field: HRJobContract Role entity: Role_functional_area */
$handler->display->display_options['fields']['role_functional_area']['id'] = 'role_functional_area';
$handler->display->display_options['fields']['role_functional_area']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_functional_area']['field'] = 'role_functional_area';
$handler->display->display_options['fields']['role_functional_area']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_functional_area']['label'] = 'Role functional area';
/* Field: HRJobContract Role entity: Role_hours */
$handler->display->display_options['fields']['role_hours']['id'] = 'role_hours';
$handler->display->display_options['fields']['role_hours']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_hours']['field'] = 'role_hours';
$handler->display->display_options['fields']['role_hours']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_hours']['label'] = 'Role hours';
/* Field: HRJobContract Role entity: Role_hours_unit */
$handler->display->display_options['fields']['role_hours_unit']['id'] = 'role_hours_unit';
$handler->display->display_options['fields']['role_hours_unit']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_hours_unit']['field'] = 'role_hours_unit';
$handler->display->display_options['fields']['role_hours_unit']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_hours_unit']['label'] = 'Role hours unit';
/* Field: HRJobContract Role entity: Role_level_type */
$handler->display->display_options['fields']['role_level_type']['id'] = 'role_level_type';
$handler->display->display_options['fields']['role_level_type']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_level_type']['field'] = 'role_level_type';
$handler->display->display_options['fields']['role_level_type']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_level_type']['label'] = 'Role level type';
/* Field: HRJobContract Role entity: Role_organization */
$handler->display->display_options['fields']['role_organization']['id'] = 'role_organization';
$handler->display->display_options['fields']['role_organization']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_organization']['field'] = 'role_organization';
$handler->display->display_options['fields']['role_organization']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_organization']['label'] = 'Role organization';
/* Field: HRJobContract Role entity: Role_region */
$handler->display->display_options['fields']['role_region']['id'] = 'role_region';
$handler->display->display_options['fields']['role_region']['table'] = 'hrjc_role';
$handler->display->display_options['fields']['role_region']['field'] = 'role_region';
$handler->display->display_options['fields']['role_region']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['fields']['role_region']['label'] = 'Role region';
/* Sort criterion: CiviCRM Contacts: Last Name */
$handler->display->display_options['sorts']['last_name']['id'] = 'last_name';
$handler->display->display_options['sorts']['last_name']['table'] = 'civicrm_contact';
$handler->display->display_options['sorts']['last_name']['field'] = 'last_name';
/* Sort criterion: CiviCRM Contacts: Contact ID */
$handler->display->display_options['sorts']['id']['id'] = 'id';
$handler->display->display_options['sorts']['id']['table'] = 'civicrm_contact';
$handler->display->display_options['sorts']['id']['field'] = 'id';
/* Sort criterion: HRJobContract Revision entity: Jobcontract_id */
$handler->display->display_options['sorts']['jobcontract_id']['id'] = 'jobcontract_id';
$handler->display->display_options['sorts']['jobcontract_id']['table'] = 'hrjc_revision';
$handler->display->display_options['sorts']['jobcontract_id']['field'] = 'jobcontract_id';
$handler->display->display_options['sorts']['jobcontract_id']['relationship'] = 'hrjc_revision';
/* Contextual filter: HRJobContract Revision entity: Effective_date */
$handler->display->display_options['arguments']['effective_date']['id'] = 'effective_date';
$handler->display->display_options['arguments']['effective_date']['table'] = 'hrjc_revision';
$handler->display->display_options['arguments']['effective_date']['field'] = 'effective_date';
$handler->display->display_options['arguments']['effective_date']['relationship'] = 'hrjc_revision';
$handler->display->display_options['arguments']['effective_date']['default_action'] = 'default';
$handler->display->display_options['arguments']['effective_date']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['effective_date']['default_argument_options']['code'] = '$date_filter = $_REQUEST[\'between_date_filter\'];
if (!empty($date_filter[\'value\'])) {
    $expl = explode(\'/\', $date_filter[\'value\']);
if (count($expl) === 1) { return $date_filter[\'value\']; }
    return $expl[2] . \'-\' . $expl[1] . \'-\' . $expl[0];
}
return date(\'Y-m-d\');';
$handler->display->display_options['arguments']['effective_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['effective_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['effective_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['effective_date']['civihr_range'] = '<=';
$handler->display->display_options['arguments']['effective_date']['civihr_range_empty'] = '0';
/* Contextual filter: HRJobContract Revision entity: Effective_end_date */
$handler->display->display_options['arguments']['effective_end_date']['id'] = 'effective_end_date';
$handler->display->display_options['arguments']['effective_end_date']['table'] = 'hrjc_revision';
$handler->display->display_options['arguments']['effective_end_date']['field'] = 'effective_end_date';
$handler->display->display_options['arguments']['effective_end_date']['relationship'] = 'hrjc_revision';
$handler->display->display_options['arguments']['effective_end_date']['default_action'] = 'default';
$handler->display->display_options['arguments']['effective_end_date']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['effective_end_date']['default_argument_options']['code'] = '$date_filter = $_REQUEST[\'between_date_filter\'];
if (!empty($date_filter[\'value\'])) {
    $expl = explode(\'/\', $date_filter[\'value\']);
if (count($expl) === 1) { return $date_filter[\'value\']; }
    return $expl[2] . \'-\' . $expl[1] . \'-\' . $expl[0];
}
return date(\'Y-m-d\');';
$handler->display->display_options['arguments']['effective_end_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['effective_end_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['effective_end_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['effective_end_date']['civihr_range'] = '>=';
$handler->display->display_options['arguments']['effective_end_date']['civihr_range_empty'] = '1';
/* Contextual filter: HRJobContract Details entity: Period start date */
$handler->display->display_options['arguments']['period_start_date']['id'] = 'period_start_date';
$handler->display->display_options['arguments']['period_start_date']['table'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_start_date']['field'] = 'period_start_date';
$handler->display->display_options['arguments']['period_start_date']['relationship'] = 'details_revision_id';
$handler->display->display_options['arguments']['period_start_date']['default_action'] = 'default';
$handler->display->display_options['arguments']['period_start_date']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['period_start_date']['default_argument_options']['code'] = '$date_filter = $_REQUEST[\'between_date_filter\'];
if (!empty($date_filter[\'value\'])) {
    $expl = explode(\'/\', $date_filter[\'value\']);
if (count($expl) === 1) { return $date_filter[\'value\']; }
    return $expl[2] . \'-\' . $expl[1] . \'-\' . $expl[0];
}
return date(\'Y-m-d\');';
$handler->display->display_options['arguments']['period_start_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['period_start_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['period_start_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['period_start_date']['civihr_range'] = '<=';
$handler->display->display_options['arguments']['period_start_date']['civihr_range_empty'] = '0';
/* Contextual filter: HRJobContract Details entity: Period end date */
$handler->display->display_options['arguments']['period_end_date']['id'] = 'period_end_date';
$handler->display->display_options['arguments']['period_end_date']['table'] = 'hrjc_details';
$handler->display->display_options['arguments']['period_end_date']['field'] = 'period_end_date';
$handler->display->display_options['arguments']['period_end_date']['relationship'] = 'details_revision_id';
$handler->display->display_options['arguments']['period_end_date']['default_action'] = 'default';
$handler->display->display_options['arguments']['period_end_date']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['period_end_date']['default_argument_options']['code'] = '$date_filter = $_REQUEST[\'between_date_filter\'];
if (!empty($date_filter[\'value\'])) {
    $expl = explode(\'/\', $date_filter[\'value\']);
if (count($expl) === 1) { return $date_filter[\'value\']; }
    return $expl[2] . \'-\' . $expl[1] . \'-\' . $expl[0];
}
return date(\'Y-m-d\');';
$handler->display->display_options['arguments']['period_end_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['period_end_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['period_end_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['period_end_date']['civihr_range'] = '>=';
$handler->display->display_options['arguments']['period_end_date']['civihr_range_empty'] = '1';
/* Contextual filter: HRJobContract Role entity: Role start date */
$handler->display->display_options['arguments']['role_start_date']['id'] = 'role_start_date';
$handler->display->display_options['arguments']['role_start_date']['table'] = 'hrjc_role';
$handler->display->display_options['arguments']['role_start_date']['field'] = 'role_start_date';
$handler->display->display_options['arguments']['role_start_date']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['arguments']['role_start_date']['default_action'] = 'default';
$handler->display->display_options['arguments']['role_start_date']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['role_start_date']['default_argument_options']['code'] = '$date_filter = $_REQUEST[\'between_date_filter\'];
if (!empty($date_filter[\'value\'])) {
    $expl = explode(\'/\', $date_filter[\'value\']);
if (count($expl) === 1) { return $date_filter[\'value\']; }
    return $expl[2] . \'-\' . $expl[1] . \'-\' . $expl[0];
}
return date(\'Y-m-d\');';
$handler->display->display_options['arguments']['role_start_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['role_start_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['role_start_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['role_start_date']['civihr_range'] = '<=';
$handler->display->display_options['arguments']['role_start_date']['civihr_range_empty'] = '0';
/* Contextual filter: HRJobContract Role entity: Role end date */
$handler->display->display_options['arguments']['role_end_date']['id'] = 'role_end_date';
$handler->display->display_options['arguments']['role_end_date']['table'] = 'hrjc_role';
$handler->display->display_options['arguments']['role_end_date']['field'] = 'role_end_date';
$handler->display->display_options['arguments']['role_end_date']['relationship'] = 'role_jobcontract_id';
$handler->display->display_options['arguments']['role_end_date']['default_action'] = 'default';
$handler->display->display_options['arguments']['role_end_date']['default_argument_type'] = 'php';
$handler->display->display_options['arguments']['role_end_date']['default_argument_options']['code'] = '$date_filter = $_REQUEST[\'between_date_filter\'];
if (!empty($date_filter[\'value\'])) {
    $expl = explode(\'/\', $date_filter[\'value\']);
if (count($expl) === 1) { return $date_filter[\'value\']; }
    return $expl[2] . \'-\' . $expl[1] . \'-\' . $expl[0];
}
return date(\'Y-m-d\');';
$handler->display->display_options['arguments']['role_end_date']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['role_end_date']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['role_end_date']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['role_end_date']['civihr_range'] = '>=';
$handler->display->display_options['arguments']['role_end_date']['civihr_range_empty'] = '1';
/* Filter criterion: CiviCRM Contacts: Is Deleted */
$handler->display->display_options['filters']['is_deleted']['id'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['table'] = 'civicrm_contact';
$handler->display->display_options['filters']['is_deleted']['field'] = 'is_deleted';
$handler->display->display_options['filters']['is_deleted']['value'] = '0';
$handler->display->display_options['filters']['is_deleted']['group'] = 1;
/* Filter criterion: CiviCRM Contacts: Contact Type */
$handler->display->display_options['filters']['contact_type']['id'] = 'contact_type';
$handler->display->display_options['filters']['contact_type']['table'] = 'civicrm_contact';
$handler->display->display_options['filters']['contact_type']['field'] = 'contact_type';
$handler->display->display_options['filters']['contact_type']['value'] = array(
  'Individual' => 'Individual',
);
$handler->display->display_options['filters']['contact_type']['group'] = 1;
/* Filter criterion: HRJobContract Revision entity: Deleted */
$handler->display->display_options['filters']['deleted']['id'] = 'deleted';
$handler->display->display_options['filters']['deleted']['table'] = 'hrjc_revision';
$handler->display->display_options['filters']['deleted']['field'] = 'deleted';
$handler->display->display_options['filters']['deleted']['relationship'] = 'hrjc_revision';
$handler->display->display_options['filters']['deleted']['value']['value'] = '0';
$handler->display->display_options['filters']['deleted']['group'] = 1;
/* Filter criterion: HRJobContract Revision entity: Overrided */
$handler->display->display_options['filters']['overrided']['id'] = 'overrided';
$handler->display->display_options['filters']['overrided']['table'] = 'hrjc_revision';
$handler->display->display_options['filters']['overrided']['field'] = 'overrided';
$handler->display->display_options['filters']['overrided']['relationship'] = 'hrjc_revision';
$handler->display->display_options['filters']['overrided']['value']['value'] = '0';
$handler->display->display_options['filters']['overrided']['group'] = 1;
/* Filter criterion: Date: Between Dates (hrjc_details) */
$handler->display->display_options['filters']['between_date_filter']['id'] = 'between_date_filter';
$handler->display->display_options['filters']['between_date_filter']['table'] = 'hrjc_details';
$handler->display->display_options['filters']['between_date_filter']['field'] = 'between_date_filter';
$handler->display->display_options['filters']['between_date_filter']['relationship'] = 'details_revision_id';
$handler->display->display_options['filters']['between_date_filter']['exposed'] = TRUE;
$handler->display->display_options['filters']['between_date_filter']['expose']['operator_id'] = 'between_date_filter_op';
$handler->display->display_options['filters']['between_date_filter']['expose']['label'] = 'Date';
$handler->display->display_options['filters']['between_date_filter']['expose']['operator'] = 'between_date_filter_op';
$handler->display->display_options['filters']['between_date_filter']['expose']['identifier'] = 'between_date_filter';
$handler->display->display_options['filters']['between_date_filter']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  55120974 => 0,
  17087012 => 0,
  57573969 => 0,
);
$handler->display->display_options['filters']['between_date_filter']['default_date'] = 'now';
$handler->display->display_options['filters']['between_date_filter']['year_range'] = '-10:+10';
$handler->display->display_options['filters']['between_date_filter']['start_date_field'] = 'hrjc_details.period_start_date';
$handler->display->display_options['filters']['between_date_filter']['end_date_field'] = 'hrjc_details.period_end_date';
$handler->display->display_options['filters']['between_date_filter']['include_null_dates'] = '2';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'views_json';
$handler->display->display_options['style_options']['root_object'] = '';
$handler->display->display_options['style_options']['top_child_object'] = '';
$handler->display->display_options['style_options']['plaintext_output'] = 1;
$handler->display->display_options['style_options']['remove_newlines'] = 0;
$handler->display->display_options['style_options']['jsonp_prefix'] = '';
$handler->display->display_options['style_options']['using_views_api_mode'] = 0;
$handler->display->display_options['style_options']['object_arrays'] = 0;
$handler->display->display_options['style_options']['numeric_strings'] = 0;
$handler->display->display_options['style_options']['bigint_string'] = 0;
$handler->display->display_options['style_options']['pretty_print'] = 0;
$handler->display->display_options['style_options']['unescaped_slashes'] = 0;
$handler->display->display_options['style_options']['unescaped_unicode'] = 0;
$handler->display->display_options['style_options']['char_encoding'] = array();
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['field_config'] = array(
  'id' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'display_name' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'age_group' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'end_reason' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'gender' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'length_of_service' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'absence_title' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'absence_start_date' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'absence_end_date' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'absence_status' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'duration' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'is_credit' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'jobcontract_id' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'contract_type' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'title' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'position' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'period_start_date' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'period_end_date' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'location' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'location_standard_hours' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'hours_type' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'is_paid' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'pay_scale' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'pay_amount' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'pay_currency' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'pay_unit' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'is_enrolled' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'hours_fte' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'effective_date' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'effective_end_date' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
  'details_revision_id' => array(
    'merge_option' => 'merge_unique',
    'separator' => ', ',
  ),
);
$handler->display->display_options['path'] = 'civihr_report_json_people';
$handler->display->display_options['menu']['title'] = 'Report 1: CiviHR People Report';
$handler->display->display_options['menu']['description'] = 'CiviHR People Report containing Contact, JobContract and Absence Activity data.';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'menu-reports';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'civihr_report_table_people');
$handler->display->display_options['defaults']['use_ajax'] = FALSE;
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'first_name' => 'first_name',
  'last_name' => 'last_name',
  'age_group' => 'age_group',
  'gender' => 'gender',
  'contract_type' => 'contract_type',
  'location' => 'location',
  'location_standard_hours' => 'location_standard_hours',
  'hours_type' => 'hours_type',
  'is_paid' => 'is_paid',
  'pay_scale' => 'pay_scale',
  'pay_amount' => 'pay_amount',
  'pay_currency' => 'pay_currency',
  'pay_unit' => 'pay_unit',
  'is_enrolled' => 'is_enrolled',
  'period_start_date' => 'period_start_date',
  'period_end_date' => 'period_end_date',
  'region' => 'region',
  'department' => 'department',
  'level_type' => 'level_type',
  'cost_center' => 'cost_center',
  'location_1' => 'location_1',
  'start_date' => 'start_date',
  'end_date' => 'end_date',
  'headcount' => 'headcount',
  'hours_fte' => 'hours_fte',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'first_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'last_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'age_group' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'gender' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'contract_type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'location' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'location_standard_hours' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'hours_type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'is_paid' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'pay_scale' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'pay_amount' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'pay_currency' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'pay_unit' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'is_enrolled' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'period_start_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'period_end_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'region' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'department' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'level_type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'cost_center' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'location_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'start_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'end_date' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'headcount' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'hours_fte' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;

/* Display: Data export */
$handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['path'] = 'civihr_report_export_people';
$translatables['civihr_report_people'] = array(
  t('Master'),
  t('CiviHR Report - People'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('HRJobContract Revision entity'),
  t('HRJobContract Details entity'),
  t('HRJobContract Health entity'),
  t('HRJobContract Hour entity'),
  t('HRJobContract Pay entity'),
  t('HRJobContract Pension entity'),
  t('HRJobContract Role entity'),
  t('Employee ID'),
  t('.'),
  t('Employee display name'),
  t('Employee age'),
  t('Employee age group'),
  t('Employee gender'),
  t('Employee length of service'),
  t('Contract ID'),
  t('Contract type'),
  t('Contract title'),
  t('Contract position'),
  t('Contract start date'),
  t('Contract end date'),
  t('Contract start date (grouped by month)'),
  t('Contract end date (grouped by month)'),
  t('Contract end reason'),
  t('Contract Normal Place of Work'),
  t('Contract location standard hours'),
  t('Contract hours type'),
  t('Contract is paid'),
  t('Contract pay scale'),
  t('Contract pay amount'),
  t('Contract pay currency'),
  t('Contract pay unit'),
  t('Contract pension is enrolled'),
  t('Contract hours FTE'),
  t('Role ID'),
  t('Role start date'),
  t('Role end date'),
  t('Role start date (grouped by month)'),
  t('Role end date (grouped by month)'),
  t('Role title'),
  t('Role description'),
  t('Role location'),
  t('Role funder'),
  t('Role percent pay funder'),
  t('Role cost center'),
  t('Role percent pay cost center'),
  t('Role department'),
  t('Role functional area'),
  t('Role hours'),
  t('Role hours unit'),
  t('Role level type'),
  t('Role organization'),
  t('Role region'),
  t('All'),
  t('Date'),
  t('Page'),
  t('Block'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Data export'),
);
