<?php $enabled_y_axis_filters = variable_get('enabled_y_axis_filters', array()); ?>

<section class="panel panel-primary" data-graph>
    <header class="panel-heading">
        <h2 class="panel-title">
            My People
        </h2>
    </header>
    <div class="panel-body">
        <div class="row">
            <div class="col-md-2" data-graph-section="y-filters">
                <?php
                    foreach ($enabled_y_axis_filters as $key => $filter) {
                        if ($filter != '0') {
                            print '<button id="' . $key . '" class="mainFilter btn btn-lg btn-secondary-outline btn-block">' . strtoupper($filter) . '</button>';
                        }
                    }
                ?>
            </div>
            <div class="col-md-8">
                <input type="text" id="reportToDate">
                <div id="custom-report" data-graph-section="canvas">
                    <!-- Content generated in reports.js -->
                </div>
            </div>
            <div class="col-md-2" data-graph-section="graph-filters">
                <button
                    data-graph-button-tpl
                    data-graph-button-inactive-class="btn-secondary-outline"
                    data-graph-button-active-class="btn-primary"
                    class="btn btn-lg btn-block text-uppercase">
                </button>
                <!-- Content generated in reports.js -->
            </div>
        </div>
    </div>
    <footer class="panel-footer text-center hide">
        <div class="report-x-filters btn-group" data-graph-section="x-filters">
            <button
                data-graph-button-tpl
                data-graph-button-inactive-class=""
                data-graph-button-active-class="active"
                class="subFilter btn btn-lg btn-secondary-outline text-uppercase">
            </button>
            <!-- Content generated in reports.js -->
        </div>
    </footer>
</section>

<div id="custom-report-details">
    <?php print $custom_data; ?>
</div>

<section class="panel panel-default">
    <div class="panel-body">
        <?php print $settings_url; ?>
    </div>
</section>
