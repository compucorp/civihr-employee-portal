<link href="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/pivot.css" rel="stylesheet" />
<link href="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/c3.min.css" rel="stylesheet" />

<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/jquery-2.1.1.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivot.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/c3.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/d3.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/c3_renderers.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/export_renderers.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/jquery-ui-1.9.2.custom.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecopivot.js"></script>

<?php /******** ORB includes **********/ ?>
<?php /*<link rel="stylesheet" type="text/css" href="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/css/bootstrap_superhero.css" />*/ ?>
<link rel="stylesheet" type="text/css" href="/sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/css/prism.css" />
<link rel="stylesheet" type="text/css" href="/sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/css/main.css" />
<script type="text/javascript" src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/lib/respond.min.js"></script>
<link rel="stylesheet" type="text/css" href="/sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/css/orb.min.css" />
<script type="text/javascript" src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/lib/react-0.12.2.min.js"></script>
<script type="text/javascript" src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/orb.min.js"></script>
<script type="text/javascript" src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/data.js"></script>
<script type="text/javascript" src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/main.js"></script>
<script type="text/javascript" src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/prism.js"></script>


<a id="expose-filters-btn" class="btn btn-primary btn-default">Expose filters &raquo;</a>
<a id="collapse-filters-btn" class="btn btn-primary btn-default hidden">Collapse filters &laquo;</a>
<div id="report-filters" class="hidden">
    <?php print drupal_render($date_filter); ?>
</div>

<ul class="nav nav-tabs nav-justified report-tabs">
    <li role="presentation" class="active"><a class="btn btn-default" data-tab="data">Data</a></li>
    <li role="presentation"><a class="btn btn-default" data-tab="pivot-table">Pivot Table</a></li>
    <li role="presentation"><a class="btn btn-default" data-tab="orb-pivot-table">Orb Pivot Table</a></li>
</ul>

<div class="report-content">
    <div class="report-block data">
        <h4>Data</h4>
        <div id="reportTable"><?php print $table; ?></div>
        <a href="/civihr-report---people-csv" id="export-csv" class="btn btn-primary btn-default">Export to CSV</a>
    </div>
    <div class="report-block pivot-table hidden">
        <h4>Pivot Table</h4>
        <div id="reportPivotTable"></div>
    </div>
    <div class="report-block orb-pivot-table hidden">
        <h4>Orb Pivot Table (with subtotals)</h4>
        <div id="reportOrbPivotTable"></div>
    </div>
</div>

<script type="text/javascript">
    CRM.$(function () {
        var data = <?php print $data; ?>;
        
        /*** PivotTable library initialization: ***/
        jQuery("#reportPivotTable").pivotUI(data, {
            rendererName: "Table",
            renderers: CRM.$.extend(
                jQuery.pivotUtilities.renderers, 
                jQuery.pivotUtilities.c3_renderers,
                jQuery.pivotUtilities.export_renderers
            ),
            vals: ["Total"],
            rows: [],
            cols: [],
            aggregatorName: "Count",
            unusedAttrsVertical: false,
            derivedAttributes: {
                "Employee length of service group": function(row) {
                    var los = parseInt(row['Employee length of service'] / 365, 10);
                    if (los < 1) {
                        return "Under 1 year";
                    }
                    if (los < 2) {
                        return "1 - 2 years";
                    }
                    if (los < 5) {
                        return "2 - 5 years";
                    }
                    if (los < 10) {
                        return "5 - 10 years";
                    }
                    if (los < 15) {
                        return "10 - 15 years";
                    }
                    if (los < 20) {
                        return "15 - 20 years";
                    }
                    return "Over 20 years";
                }
            }
        }, false);
        
        ///// Orb.js:
        function orbConvertData(data) {
            var orbData = [];
            for (var i in data) {
                var orbRow = [];
                for (var j in data[i]) {
                    if (
                        j === 'Contact ID' || 
                        j === 'Employee age'
                    ) {
                        data[i][j] = parseFloat(data[i][j]);
                    }
                    orbRow.push(data[i][j]);
                }
                orbData.push(orbRow);
            }
            var orbFields = [];
            var j = 0;
            for (var i in data[0]) {
                orbFields.push({
                    name: j++,
                    caption: i
                });
            }
            orbFields.push(
                {
                    name: j++,
                    caption: 'Duration',
                    dataSettings: {
                        aggregateFunc: 'avg',
                        formatFunc: function(value) {
                            return Number(value).toFixed(0);
                        }
                    }
                }
            );
    
            return {
                'data': orbData,
                'fields': orbFields
            }
        }
        
        var orbConfig = function(f, d) {
            return {
                width: 1110,
                height: 645,
                dataSource: d,
                dataHeadersLocation: 'columns',
                theme: 'blue',
                toolbar: {
                    visible: true
                },
                grandTotal: {
                        rowsvisible: true,
                        columnsvisible: true
                },
                subTotal: {
                        visible: true,
                    collapsed: true
                },
                fields: f,
                rows    : []/*[ 'Manufacturer', 'Category' ]*/,
                columns : []/*[ 'Class' ]*/,
                data    : []/*[ 'Quantity', 'Amount' ]*/,
                preFilters : {
                    //'Manufacturer': { 'Matches': /n/ },
                    //'Amount'      : { '>':  40 }
                }
            };
        };
        var orbElem = document.getElementById('reportOrbPivotTable');
        var orbConvertedData = orbConvertData(data);
        var orbInstance = new orb.pgridwidget(orbConfig(orbConvertedData.fields, orbConvertedData.data));
        orbInstance.render(orbElem);



        ////////////////////////////////////////////////////////////////////////
        
        var dateFilterValue = 'all',
            perDateField = '';

        CRM.$('.btn-report-date-filter').bind('click', function(e) {
            e.preventDefault();
            console.info('Applying date filter.');
            dateFilterValue = CRM.$('input[name="date_filter[date]"]').val();
            if (dateFilterValue === '') {
                dateFilterValue = 'all';
            }
            console.info('dateFilterValue: ' + dateFilterValue);

            reportRefreshJson(dateFilterValue);
            reportRefreshTable(dateFilterValue);
        });
        
        function reportRefreshJson(dateFilterValue) {
            console.info('reportRefreshJson()');
            CRM.$.ajax({
                url: '/civihr-report-json-people/' + dateFilterValue + '/' + dateFilterValue,
                error: function () {
                    console.info('error');
                },
                success: function (data) {
                    // Refreshing Pivot Table:
                    console.info('refreshing Pivot Table');
                    jQuery("#reportPivotTable").pivotUI(data, {
                        rendererName: "Table",
                        renderers: CRM.$.extend(
                            jQuery.pivotUtilities.renderers, 
                            jQuery.pivotUtilities.c3_renderers
                        ),
                        unusedAttrsVertical: false
                    }, false);
                    // Refreshing Orb Pivot Table:
                    var orbConvertedData = orbConvertData(data);
                    orbInstance.refreshData(orbConvertedData.data);
                },
                type: 'GET'
            });
        }

        function reportRefreshTable(dateFilterValue) {
            console.info('reportRefreshTable()');
            CRM.$.ajax({
                url: '/reports/people/table/' + dateFilterValue + '/' + dateFilterValue,
                error: function () {
                    console.info('error');
                },
                success: function (data) {
                    CRM.$('#reportTable').html(data);
                },
                type: 'GET'
            });
        }
        CRM.$('#expose-filters-btn').bind('click', function(e) {
            e.preventDefault();
            CRM.$(this).addClass('hidden');
            CRM.$('#collapse-filters-btn').removeClass('hidden');
            CRM.$('#report-filters').removeClass('hidden');
        });
        CRM.$('#collapse-filters-btn').bind('click', function(e) {
            e.preventDefault();
            CRM.$(this).addClass('hidden');
            CRM.$('#expose-filters-btn').removeClass('hidden');
            CRM.$('#report-filters').addClass('hidden');
        });
        CRM.$('.report-tabs a').bind('click', function(e) {
            e.preventDefault();
            CRM.$('.report-tabs li').removeClass('active');
            CRM.$(this).parent().addClass('active');
            CRM.$('.report-block').addClass('hidden');
            CRM.$('.report-block.' + CRM.$(this).data('tab')).removeClass('hidden');
        });
    });
</script>
