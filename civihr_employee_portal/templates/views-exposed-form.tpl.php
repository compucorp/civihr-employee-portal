<?php
if (_is_hrreports_exposed_filters_form($form)) {
    include('views-exposed-form-hrreports.tpl.php');
} else {
    include('views-exposed-form-default.tpl.php');
}
