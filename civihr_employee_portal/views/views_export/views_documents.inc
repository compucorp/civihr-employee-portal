$view = new view();
$view->name = 'Documents';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'documents';
$view->human_name = 'Documents';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Documents';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view my details';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'activity_type_id' => 'activity_type_id',
  'case_id' => 'case_id',
  'subject' => 'subject',
  'activity_date_time' => 'activity_date_time',
  'expire_date' => 'expire_date',
  'details' => 'details',
  'file_count' => 'file_count',
  'status_id' => 'status_id',
  'target_contact_id' => 'target_contact_id',
  'assignee_contact_id' => 'assignee_contact_id',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'activity_type_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'case_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'subject' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'activity_date_time' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'expire_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'details' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'file_count' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'target_contact_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'assignee_contact_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['empty_table'] = TRUE;
/* No results behavior: Global: Unfiltered text */
$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
$handler->display->display_options['empty']['area_text_custom']['label'] = 'No Document Results';
$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
$handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no documents to display.';
/* Field: Document entity: Document entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'documents';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Document ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Document entity: Document type */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'documents';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Type';
$handler->display->display_options['fields']['activity_type_id']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Case_id */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'documents';
$handler->display->display_options['fields']['case_id']['field'] = 'case_id';
$handler->display->display_options['fields']['case_id']['label'] = 'Assignment';
$handler->display->display_options['fields']['case_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['case_id']['separator'] = '';
/* Field: Document entity: Subject */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'documents';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
$handler->display->display_options['fields']['subject']['exclude'] = TRUE;
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Document due date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'documents';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due Date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Document expire date */
$handler->display->display_options['fields']['expire_date']['id'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['table'] = 'documents';
$handler->display->display_options['fields']['expire_date']['field'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['label'] = 'Expire Date';
$handler->display->display_options['fields']['expire_date']['element_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['expire_date']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Details */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'documents';
$handler->display->display_options['fields']['details']['field'] = 'details';
$handler->display->display_options['fields']['details']['exclude'] = TRUE;
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: File_count */
$handler->display->display_options['fields']['file_count']['id'] = 'file_count';
$handler->display->display_options['fields']['file_count']['table'] = 'documents';
$handler->display->display_options['fields']['file_count']['field'] = 'file_count';
$handler->display->display_options['fields']['file_count']['label'] = 'File Count';
$handler->display->display_options['fields']['file_count']['exclude'] = TRUE;
$handler->display->display_options['fields']['file_count']['element_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_class'] = 'hidden';
$handler->display->display_options['fields']['file_count']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['file_count']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['file_count']['separator'] = '';
/* Field: Document entity: Document status */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'documents';
$handler->display->display_options['fields']['status_id']['field'] = 'status_id';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
$handler->display->display_options['fields']['status_id']['element_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['status_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Target contact */
$handler->display->display_options['fields']['target_contact_id']['id'] = 'target_contact_id';
$handler->display->display_options['fields']['target_contact_id']['table'] = 'documents';
$handler->display->display_options['fields']['target_contact_id']['field'] = 'target_contact_id';
/* Field: Document entity: Assignee contact */
$handler->display->display_options['fields']['assignee_contact_id']['id'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['table'] = 'documents';
$handler->display->display_options['fields']['assignee_contact_id']['field'] = 'assignee_contact_id';

/* Display: Documents Dashboard block */
$handler = $view->new_display('block', 'Documents Dashboard block', 'block');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Document entity: Document entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'documents';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Document ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Document entity: Document type */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'documents';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Type';
$handler->display->display_options['fields']['activity_type_id']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Case_id */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'documents';
$handler->display->display_options['fields']['case_id']['field'] = 'case_id';
$handler->display->display_options['fields']['case_id']['label'] = 'Assignment';
$handler->display->display_options['fields']['case_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['case_id']['separator'] = '';
/* Field: Document entity: Subject */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'documents';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
$handler->display->display_options['fields']['subject']['exclude'] = TRUE;
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Document due date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'documents';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due Date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Document expire date */
$handler->display->display_options['fields']['expire_date']['id'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['table'] = 'documents';
$handler->display->display_options['fields']['expire_date']['field'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['label'] = 'Expire Date';
$handler->display->display_options['fields']['expire_date']['element_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['expire_date']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Details */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'documents';
$handler->display->display_options['fields']['details']['field'] = 'details';
$handler->display->display_options['fields']['details']['exclude'] = TRUE;
$handler->display->display_options['fields']['details']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: File_count */
$handler->display->display_options['fields']['file_count']['id'] = 'file_count';
$handler->display->display_options['fields']['file_count']['table'] = 'documents';
$handler->display->display_options['fields']['file_count']['field'] = 'file_count';
$handler->display->display_options['fields']['file_count']['label'] = 'File Count';
$handler->display->display_options['fields']['file_count']['exclude'] = TRUE;
$handler->display->display_options['fields']['file_count']['element_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_class'] = 'hidden';
$handler->display->display_options['fields']['file_count']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['file_count']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['file_count']['separator'] = '';
/* Field: Document entity: Document status */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'documents';
$handler->display->display_options['fields']['status_id']['field'] = 'status_id';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
$handler->display->display_options['fields']['status_id']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['status_id']['element_type'] = '0';
$handler->display->display_options['fields']['status_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['status_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Target contact */
$handler->display->display_options['fields']['target_contact_id']['id'] = 'target_contact_id';
$handler->display->display_options['fields']['target_contact_id']['table'] = 'documents';
$handler->display->display_options['fields']['target_contact_id']['field'] = 'target_contact_id';
$handler->display->display_options['fields']['target_contact_id']['exclude'] = TRUE;
/* Field: Document entity: Assignee contact */
$handler->display->display_options['fields']['assignee_contact_id']['id'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['table'] = 'documents';
$handler->display->display_options['fields']['assignee_contact_id']['field'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['exclude'] = TRUE;
/* Field: Document entity: Target_contact_name */
$handler->display->display_options['fields']['target_contact_name']['id'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['table'] = 'documents';
$handler->display->display_options['fields']['target_contact_name']['field'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['label'] = '';
$handler->display->display_options['fields']['target_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['target_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['target_contact_name']['element_wrapper_class'] = 'hidden';
/* Field: Document entity: Assignee_contact_name */
$handler->display->display_options['fields']['assignee_contact_name']['id'] = 'assignee_contact_name';
$handler->display->display_options['fields']['assignee_contact_name']['table'] = 'documents';
$handler->display->display_options['fields']['assignee_contact_name']['field'] = 'assignee_contact_name';
$handler->display->display_options['fields']['assignee_contact_name']['label'] = '';
$handler->display->display_options['fields']['assignee_contact_name']['element_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_name']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['assignee_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['assignee_contact_name']['element_wrapper_class'] = 'hidden';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Document entity: Target contact */
$handler->display->display_options['arguments']['target_contact_id']['id'] = 'target_contact_id';
$handler->display->display_options['arguments']['target_contact_id']['table'] = 'documents';
$handler->display->display_options['arguments']['target_contact_id']['field'] = 'target_contact_id';
$handler->display->display_options['arguments']['target_contact_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['target_contact_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['target_contact_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['target_contact_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['target_contact_id']['summary_options']['items_per_page'] = '25';

/* Display: Documents Dashboard Manager block */
$handler = $view->new_display('block', 'Documents Dashboard Manager block', 'block_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Documents Manager';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Document entity: Document entity ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'documents';
$handler->display->display_options['fields']['id']['field'] = 'id';
$handler->display->display_options['fields']['id']['label'] = 'Document ID';
$handler->display->display_options['fields']['id']['element_class'] = 'hidden';
$handler->display->display_options['fields']['id']['element_label_class'] = 'hidden';
$handler->display->display_options['fields']['id']['separator'] = '';
/* Field: Document entity: Target_contact_name */
$handler->display->display_options['fields']['target_contact_name']['id'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['table'] = 'documents';
$handler->display->display_options['fields']['target_contact_name']['field'] = 'target_contact_name';
$handler->display->display_options['fields']['target_contact_name']['label'] = 'Target contact';
$handler->display->display_options['fields']['target_contact_name']['element_type'] = 'div';
$handler->display->display_options['fields']['target_contact_name']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['target_contact_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['target_contact_name']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['target_contact_name']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Document type */
$handler->display->display_options['fields']['activity_type_id']['id'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['table'] = 'documents';
$handler->display->display_options['fields']['activity_type_id']['field'] = 'activity_type_id';
$handler->display->display_options['fields']['activity_type_id']['label'] = 'Type';
$handler->display->display_options['fields']['activity_type_id']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_type_id']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Case_id */
$handler->display->display_options['fields']['case_id']['id'] = 'case_id';
$handler->display->display_options['fields']['case_id']['table'] = 'documents';
$handler->display->display_options['fields']['case_id']['field'] = 'case_id';
$handler->display->display_options['fields']['case_id']['label'] = 'Assignment';
$handler->display->display_options['fields']['case_id']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['case_id']['element_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['case_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['case_id']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['case_id']['empty'] = '-';
$handler->display->display_options['fields']['case_id']['separator'] = '';
/* Field: Document entity: Subject */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'documents';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
$handler->display->display_options['fields']['subject']['exclude'] = TRUE;
$handler->display->display_options['fields']['subject']['element_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['subject']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Document due date */
$handler->display->display_options['fields']['activity_date_time']['id'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['table'] = 'documents';
$handler->display->display_options['fields']['activity_date_time']['field'] = 'activity_date_time';
$handler->display->display_options['fields']['activity_date_time']['label'] = 'Due Date';
$handler->display->display_options['fields']['activity_date_time']['element_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['activity_date_time']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Document expire date */
$handler->display->display_options['fields']['expire_date']['id'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['table'] = 'documents';
$handler->display->display_options['fields']['expire_date']['field'] = 'expire_date';
$handler->display->display_options['fields']['expire_date']['label'] = 'Expire Date';
$handler->display->display_options['fields']['expire_date']['element_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['expire_date']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['expire_date']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Details */
$handler->display->display_options['fields']['details']['id'] = 'details';
$handler->display->display_options['fields']['details']['table'] = 'documents';
$handler->display->display_options['fields']['details']['field'] = 'details';
$handler->display->display_options['fields']['details']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['details']['element_type'] = 'div';
$handler->display->display_options['fields']['details']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['details']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['details']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: File_count */
$handler->display->display_options['fields']['file_count']['id'] = 'file_count';
$handler->display->display_options['fields']['file_count']['table'] = 'documents';
$handler->display->display_options['fields']['file_count']['field'] = 'file_count';
$handler->display->display_options['fields']['file_count']['label'] = 'File Count';
$handler->display->display_options['fields']['file_count']['element_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['file_count']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['file_count']['element_wrapper_class'] = 'document-wrapper';
$handler->display->display_options['fields']['file_count']['separator'] = '';
/* Field: Document entity: Document status */
$handler->display->display_options['fields']['status_id']['id'] = 'status_id';
$handler->display->display_options['fields']['status_id']['table'] = 'documents';
$handler->display->display_options['fields']['status_id']['field'] = 'status_id';
$handler->display->display_options['fields']['status_id']['label'] = 'Status';
$handler->display->display_options['fields']['status_id']['alter']['strip_tags'] = TRUE;
$handler->display->display_options['fields']['status_id']['element_type'] = '0';
$handler->display->display_options['fields']['status_id']['element_label_type'] = 'strong';
$handler->display->display_options['fields']['status_id']['element_wrapper_type'] = 'div';
$handler->display->display_options['fields']['status_id']['element_wrapper_class'] = 'document-wrapper';
/* Field: Document entity: Assignee contact */
$handler->display->display_options['fields']['assignee_contact_id']['id'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['table'] = 'documents';
$handler->display->display_options['fields']['assignee_contact_id']['field'] = 'assignee_contact_id';
$handler->display->display_options['fields']['assignee_contact_id']['exclude'] = TRUE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Document entity: Assignee contact */
$handler->display->display_options['arguments']['assignee_contact_id']['id'] = 'assignee_contact_id';
$handler->display->display_options['arguments']['assignee_contact_id']['table'] = 'documents';
$handler->display->display_options['arguments']['assignee_contact_id']['field'] = 'assignee_contact_id';
$handler->display->display_options['arguments']['assignee_contact_id']['default_action'] = 'default';
$handler->display->display_options['arguments']['assignee_contact_id']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['assignee_contact_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['assignee_contact_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['assignee_contact_id']['summary_options']['items_per_page'] = '25';
$translatables['Documents'] = array(
  t('Master'),
  t('Documents'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('No Document Results'),
  t('There are no documents to display.'),
  t('Document ID'),
  t('.'),
  t('Type'),
  t('Assignment'),
  t('Subject'),
  t('Due Date'),
  t('Expire Date'),
  t('Details'),
  t('File Count'),
  t('Status'),
  t('Target contact'),
  t('Assignee contact'),
  t('Documents Dashboard block'),
  t('All'),
  t('Documents Dashboard Manager block'),
  t('Documents Manager'),
  t('-'),
);
