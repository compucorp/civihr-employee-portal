<?php
if (_is_hrreports_data_table_view($view->name)) {
  include('views-view-table-hrreports.tpl.php');
} else if (_is_scrollable_table_view_with_results($view->name)) {
  include('views-view-table-scrollable-with-results.tpl.php');
} else {
  include('views-view-table-default.tpl.php');
}
