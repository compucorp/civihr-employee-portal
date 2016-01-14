<?php $enabled_y_axis_filters = variable_get(arg(0) . '_enabled_y_axis_filters', array()); ?>

<div data-graph>
    <section class="panel panel-primary">
        <header class="panel-heading">
            <div class="row">
                <div class="col-xs-1 text-left">
                    <a href="/<?php print $next_url;?>">
                        <i class="fa fa-chevron-left"></i>
                    </a>
                </div>
                <div class="col-xs-10">
                    <h2 class="panel-title">
                        <?php print $report_title; ?>
                    </h2>
                </div>
                <div class="col-xs-1 text-right">
                    <a href="/<?php print $next_url;?>">
                        <i class="fa fa-chevron-right"></i>
                    </a>
                </div>
            </div>
        </header>
        <div class="panel-body">
            <div class="row">
                <div class="col-md-2" data-graph-section="main-filters">
                    <button
                        data-graph-button-tpl
                        data-graph-button-inactive-class=""
                        data-graph-button-active-class="active"
                        class="btn btn-lg btn-secondary-outline btn-block text-uppercase">
                    </button>

                    <div data-graph-button-area>
                        <!-- Content generated in reports.js -->
                    </div>

                    <?php
                        foreach ($enabled_y_axis_filters as $key => $filter) {
                            if ($filter != '0') {
                                print "<span data-temporary-main-filters data-value=\"$key\" data-label=\"$filter\" class=\"hide\"></span>";
                            }
                        }
                    ?>
                </div>
                <div class="col-md-8">
                    <div class="clearfix visible-xs-block visible-sm-block">&nbsp;</div>

                    <?php if (arg(0) == 'civihr_reports') { ?>
                        <div class="form-inline text-right">
                            <div class="form-group">
                                <label for="date-filter" class="control-label">Select Date:</label>
                                <div data-graph-calendar class="input-group input-group-unstyled">
                                    <input type="text" id="date-filter" class="form-control">
                                    <span class="input-group-addon fa fa-calendar"></span>
                                </div>
                            </div>
                        </div>
                    <?php } ?>
                    <div data-graph-section="canvas">
                        <!-- Content generated in reports.js -->
                    </div>
                </div>
                <div class="col-md-2">
                    <div class="row">
                        <div class="col-md-12" data-graph-section="graph-filters">
                            <button
                                data-graph-button-tpl
                                data-graph-button-inactive-class="btn-secondary-outline"
                                data-graph-button-active-class="btn-primary"
                                class="btn btn-lg btn-block text-uppercase">
                            </button>
                            <div data-graph-button-area>
                                <!-- Content generated in reports.js -->
                            </div>
                        </div>
                        <div class="col-md-12" data-graph-section="legend">
                            <!-- Content generated in reports.js -->
                        </div>
                    </div>
                </div>
            </div>

            <?php if (arg(0) == 'civihr_reports_monthly' || arg(0) == 'civihr_reports_absence') { ?>
                <div class="row">
                    <div class="col-xs-12" data-graph-section="slider">
                        <div data-graph-slider>
                            <span class="col-xs-2 text-center ui-slider-range-values" data-graph-slider-min-date></span>
                            <div class="col-xs-8" data-graph-slider-control></div>
                            <span class="col-xs-2 text-center ui-slider-range-values" data-graph-slider-max-date></span>
                        </div>
                    </div>
                </div>
            <?php } ?>
        </div>
        <footer class="panel-footer text-center" data-graph-section="sub-filters">
            <button
                data-graph-button-tpl
                data-graph-button-inactive-class=""
                data-graph-button-active-class="active"
                class="btn btn-lg btn-secondary-outline text-uppercase">
            </button>
            <div class="btn-group" data-graph-button-area>
                <!-- Content generated in reports.js -->
            </div>
        </footer>
    </section>
    <div data-graph-section="data">
        <?php print $custom_data; ?>
    </div>
</div>
<section class="panel panel-default">
    <div class="panel-body">
        <?php print $settings_url; ?>
    </div>
</section>
