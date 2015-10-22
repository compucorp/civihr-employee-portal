<?php $enabled_y_axis_filters = variable_get('enabled_y_axis_filters', array()); ?>

<div class="panel-pane pane-block">

    <div class="col-md-2 column1 panel-panel">
        <?php
            foreach ($enabled_y_axis_filters as $key => $filter) {
                if ($filter != '0') {
                    print '<button id="' . $key . '" class="mainFilter btn btn-primary btn-reports">' . $filter . '</button>';
                }
            }
        ?>
    </div>

    <div class="col-md-8 column2 panel-panel">

        <input type="text" id="reportToDate">

        <div id="custom-report"></div>
    </div>

    <!-- Content generated in reports.js -->
    <div class="col-md-8 column1 panel-panel report-x-filters"></div>

</div>

<div class="panel-pane custom-data-block">

    <div>
        <div id="custom-report-details"> <?php print $custom_data; ?> </div>
    </div>

</div>

<div class="panel-pane pane-block custom-settings-block">

    <div class="col-md-8 column2 panel-panel">
        <?php print $settings_url; ?>
    </div>

</div>
