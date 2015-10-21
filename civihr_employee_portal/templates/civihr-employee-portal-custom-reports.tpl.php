<?php $enabled_y_axis_filters = variable_get('enabled_y_axis_filters', array()); ?>

<section class="chr_section">
    <header class="chr_section__header">
        <h2 class="chr_section__title">
            My People
        </h2>
    </header>
    <div class="chr_section__body">
        <div class="row">
            <div class="col-md-2 column1 panel-panel">
                <?php
                    foreach ($enabled_y_axis_filters as $key => $filter) {
                        if ($filter != '0') {
                            print '<button id="' . $key . '" class="mainFilter btn btn-lg btn-secondary-outline btn-block">' . strtoupper($filter) . '</button>';
                        }
                    }
                ?>
            </div>

            <div class="col-md-8 column2 panel-panel">
                <input type="text" id="reportToDate">
                <div id="custom-report"></div>
            </div>
        </div>
    </div>
    <div class="chr_section__footer text-center">
        <div class="report-x-filters btn-group">
            <!-- Content generated in reports.js -->
        </div>
    </div>
</section>

<div class="panel-pane custom-data-block">
    <div>
        <div id="custom-report-details"> <?php print $custom_data; ?> </div>
    </div>
</div>

<section class="chr_section">
    <div class="chr_section__body">
        <?php print $settings_url; ?>
    </div>
</section>
