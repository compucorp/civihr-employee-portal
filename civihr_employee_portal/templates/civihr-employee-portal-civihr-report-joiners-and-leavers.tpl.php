<link href="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/pivot.css" rel="stylesheet" />
<link href="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/c3.min.css" rel="stylesheet" />
<script type="text/javascript" src="http://code.jquery.com/jquery-2.1.1.min.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivot.min.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/c3.min.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/d3.min.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/c3_renderers.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/export_renderers.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/jquery-ui-1.9.2.custom.min.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecopivot.js"></script>

<h2>CiviHR Report - Joiners and Leavers - proof of concept</h2>

<div><?php print drupal_render($date_filter); ?></div>

<h4>Pivot Table</h4>
<table width="100%">
    <tr>
        <td><button id="reportJoinersAndLeaversExample1">Example output 1</button> If I want to know how many people joined the whole company, split by gender by month</td>
    </tr>
    <tr>
        <td><button id="reportJoinersAndLeaversExample2">Example output 2</button> If I want to know how many people joined a department by month</td>
    </tr>
    <tr>
        <td><button id="reportJoinersAndLeaversExample3">Example output 3</button> If I want to know how many people left by month</td>
    </tr>
</table>
<div id="reportPivotTable"></div>

<div id="demo-pgrid" class="demo-pgrid"></div>

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
            rows: [],
            cols: [],
            aggregatorName: "Count",
            unusedAttrsVertical: false,
            derivedAttributes: {
                "Amount Taken": function(row) {
                    if (parseInt(row['Is credit'], 10) === 0) {
                        return row['Duration'];
                    }
                    return 0;
                },
                "Amount accrued": function(row) {
                    if (parseInt(row['Is credit'], 10) === 1) {
                        return row['Duration'];
                    }
                    return 0;
                },
                "Absolute duration": function(row) {
                    if (parseInt(row['Is credit'], 10) === 1) {
                        return -row['Duration'];
                    }
                    return row['Duration'];
                },
                "Start Date Months": jQuery.pivotUtilities.derivers.dateFormat("Period start date", "%y-%m"),
                "End Date Months": jQuery.pivotUtilities.derivers.dateFormat("Period end date", "%y-%m")
            }
        }, false);
        




        ////////////////////////////////////////////////////////////////////////
        
        var dateFilterValue = 'any',
            perDateField = '';

        CRM.$('.btn-report-date-filter').bind('click', function(e) {
            e.preventDefault();
            console.info('Applying date filter.');
            dateFilterValue = CRM.$('input[name="date_filter[date]"]').val();
            if (dateFilterValue === '') {
                dateFilterValue = 'any';
            }
            console.info('dateFilterValue: ' + dateFilterValue);

            reportRefreshPivotTable(dateFilterValue);
            reportRefreshTable(dateFilterValue);
        });
        
        CRM.$('#reportJoinersAndLeaversExample1').bind('click', function() {
            reportRefreshPivotTable(dateFilterValue, true, ["Gender"], ["Start Date Months"], "Count");
        });
        CRM.$('#reportJoinersAndLeaversExample2').bind('click', function() {
            reportRefreshPivotTable(dateFilterValue, true, ["Department"], ["Start Date Months"], "Count");
        });
        CRM.$('#reportJoinersAndLeaversExample3').bind('click', function() {
            reportRefreshPivotTable(dateFilterValue, true, ["Department"], ["End Date Months"], "Count");
        });
        
        function reportRefreshPivotTable(dateFilterValue, reload, r, c, a) {
            console.info('reportRefreshPivotTable()');
            var cfg = {
                rendererName: "Table",
                renderers: CRM.$.extend(
                    jQuery.pivotUtilities.renderers, 
                    jQuery.pivotUtilities.c3_renderers
                ),
                unusedAttrsVertical: false,
                derivedAttributes: {
                    "Start Date Months": jQuery.pivotUtilities.derivers.dateFormat("Period start date", "%y-%m"),
                    "End Date Months": jQuery.pivotUtilities.derivers.dateFormat("Period end date", "%y-%m")
                }
            };
            if (typeof reload === 'undefined') {
                reload = false;
            }
            if (typeof r !== 'undefined') {
                cfg.rows = r;
            }
            if (typeof c !== 'undefined') {
                cfg.cols = c;
            }
            if (typeof a !== 'undefined') {
                cfg.aggregatorName = a;
            }
            console.info(cfg);
            CRM.$.ajax({
                url: '/civihr-report---people/' + dateFilterValue + '/' + dateFilterValue,
                error: function () {
                    console.info('error');
                },
                success: function (data) {
                    console.info('refreshing Pivot Table');
                    jQuery("#reportPivotTable").pivotUI(data, cfg, reload);
                },
                type: 'GET'
            });
        }

        function reportRefreshTable(dateFilterValue) {
            console.info('reportRefreshTable()');
            CRM.$.ajax({
                url: '/hrreport_people_test_printtable/' + dateFilterValue,
                error: function () {
                    console.info('error');
                },
                success: function (data) {
                    CRM.$('#reportTable').html(data);
                },
                type: 'GET'
            });
        }

    });
</script>
