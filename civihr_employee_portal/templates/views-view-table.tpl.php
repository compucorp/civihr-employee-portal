<?php
if (_is_hrreports_data_table_view($view->name)) {
    include('views-view-table-hrreports.tpl.php');
} else {
    include('views-view-table-default.tpl.php');
}
