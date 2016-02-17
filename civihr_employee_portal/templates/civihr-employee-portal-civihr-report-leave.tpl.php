<?php /*<link href="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/pivot.css" rel="stylesheet" />
<script type="text/javascript" src="http://code.jquery.com/jquery-2.1.1.min.js"></script>	
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/jquery-ui-1.9.2.custom.min.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/pivot.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/gchart_renderers.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecopivot.js"></script>		
*/ ?>

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
<?php /*<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecowebpivot.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecopivotdataapi.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecopivotdataapi.jquery.nrecorelexbuilder-1.0"></script>
 */?>

<?php /******** ORB includes **********/ ?>
<?php /*<link rel="stylesheet" type="text/css" href="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/css/bootstrap_superhero.css" />*/ ?>
<link rel="stylesheet" type="text/css" href="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/css/prism.css" />
<link rel="stylesheet" type="text/css" href="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/css/main.css" />
<script type="text/javascript" src="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/lib/respond.min.js"></script>
<link rel="stylesheet" type="text/css" href="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/css/orb.min.css" />
<script type="text/javascript" src="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/lib/react-0.12.2.min.js"></script>
<script type="text/javascript" src="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/orb.min.js"></script>
<script type="text/javascript" src="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/data.js"></script>
<script type="text/javascript" src="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/main.js"></script>
<script type="text/javascript" src="sites/all/modules/civihr-custom/civihr_employee_portal/js/orb/prism.js"></script>


<h2>CiviHR Report - Leave - proof of concept</h2>

<div><?php print drupal_render($date_filter); ?></div>

<h4>Pivot Table</h4>
<div id="reportPivotTable"></div>
<br/><br/>

<h4>Pivot Table using Orb.js library (with subtotals)</h4>
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
            rows: ["Gender"],
            cols: ["Type", "Months"],
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
                "Months": jQuery.pivotUtilities.derivers.dateFormat("Absence start date", "%y-%m")
            }
        }, false);
        
        
        
        ///// Orb.js:
        var orbData = [];
        for (var i in data) {
            var orbRow = [];
            for (var j in data[i]) {
                if (
                    j === 'Contact ID' || 
                    j === 'Age' || 
                    j === 'Duration' || 
                    j === 'Absolute duration' ||
                    j === 'Is credit' || 
                    j === 'Amount Taken' || 
                    j === 'Amount accrued'
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
console.info(orbData[0]);
        loadOrb(orbFields, orbData);
        




        ////////////////////////////////////////////////////////////////////////
        
        var startDateFilterValue = 'any',
            endDateFilterValue = 'any',
            perDateField = '';

        CRM.$('.btn-report-date-filter').bind('click', function(e) {
            e.preventDefault();
            console.info('Applying date filter.');
            startDateFilterValue = CRM.$('input[name="start_date_filter[date]"]').val();
            endDateFilterValue = CRM.$('input[name="end_date_filter[date]"]').val();
            if (startDateFilterValue === '') {
                startDateFilterValue = 'any';
            }
            if (endDateFilterValue === '') {
                endDateFilterValue = 'any';
            }
            console.info('dateFilterValue: ' + startDateFilterValue + ', ' + endDateFilterValue);

            reportRefreshPivotTable(startDateFilterValue, endDateFilterValue);
            reportRefreshTable(startDateFilterValue, endDateFilterValue);
        });
        
        function reportRefreshPivotTable(startDateFilterValue, endDateFilterValue) {
            console.info('reportRefreshPivotTable()');
            CRM.$.ajax({
                url: '/civihr-report---leave/' + startDateFilterValue + '/' + endDateFilterValue,
                error: function () {
                    console.info('error');
                },
                success: function (data) {
                    console.info('refreshing Pivot Table');
                    jQuery("#reportPivotTable").pivotUI(data, {
                        rendererName: "Table",
                        renderers: CRM.$.extend(
                            jQuery.pivotUtilities.renderers, 
                            jQuery.pivotUtilities.c3_renderers
                        ),
                        unusedAttrsVertical: false/*,
                        derivedAttributes: {
                            "Gender Imbalance": function(mp) {
                                return mp["Gender"] == "Male" ? 1 : -1;
                            }
                        }*/
                    }, false);
                },
                type: 'GET'
            });
        }

        function reportRefreshTable(startDateFilterValue, endDateFilterValue) {
            console.info('reportRefreshTable()');
            CRM.$.ajax({
                url: '/hrreport_people_test_printtable/' + startDateFilterValue + '/' + endDateFilterValue,
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
