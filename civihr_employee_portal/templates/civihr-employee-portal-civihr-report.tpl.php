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


<h2>CiviHR Report - People - proof of concept</h2>

<div><?php print drupal_render($date_filter); ?></div>

<h4>Flat Table</h4>
<div id="reportTable"><?php print $table; ?></div>
<a href="/civihr-report---people-csv" id="export-csv" class="btn btn-primary btn-default">Export to CSV</a>

<?php /*<h4>Pivot Table</h4>
<div id="reportPivotTable"></div>*/ ?>
<h4>Pivot Table</h4>
<div id="reportPivotTable"></div>

<br/><br/>

<h4>Pivot Table using Orb.js library (with subtotals)</h4>
<div id="reportOrbPivotTable"></div>

<?php /*<h4>Month-by-month Report</h4>
<div><?php //print drupal_render($per_date_filter); ?>
    <select id="per-date-filter">
        <option value=""></option>
        <option value="headcount">headcount</option>
        <option value="location">location</option>
        <option value="contract_type">contract type</option>
    </select>
</div>
<div id="reportPerDate"></div>*/ ?>



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
                "Age Group": function(row) {
                    if (row['Age'] === 'not set') {
                        return 'Unspecified';
                    }
                    var age = parseInt(row['Age'], 10);
                    if (age < 20) {
                        return "Under 20";
                    }
                    if (age < 30) {
                        return "20 - 29";
                    }
                    if (age < 40) {
                        return "30 - 39";
                    }
                    if (age < 50) {
                        return "40 - 49";
                    }
                    if (age < 60) {
                        return "50 - 59";
                    }
                    return "Over 60";
                },
                "Length of Service Group": function(row) {
                    var los = parseInt(row['Length of Service'] / 365, 10);
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
                },
                "End reason label":  function(row) {
                    var er = row["End reason"];//parseInt(row["End reason"], 10);
                    if (er === '1') {
                        return "Voluntary";
                    }
                    if (er === '2') {
                        return "Involuntary";
                    }
                    if (er === '3') {
                        return "Planned";
                    }
                    return "Unspecified";
                },

                "Contract Start Months": jQuery.pivotUtilities.derivers.dateFormat("Period start date", "%y-%m"),
                "Contract End Months": jQuery.pivotUtilities.derivers.dateFormat("Period end date", "%y-%m"),

                // Derived Attributes for Absence:
                /*"Absence Amount Taken": function(row) {
                    if (parseInt(row['Is credit'], 10) === 0) {
                        return row['Duration'];
                    }
                    return 0;
                },
                "Absence Amount Accrued": function(row) {
                    if (parseInt(row['Is credit'], 10) === 1) {
                        return row['Duration'];
                    }
                    return 0;
                },
                "Absence Absolute Duration": function(row) {
                    if (parseInt(row['Is credit'], 10) === 1) {
                        return -row['Duration'];
                    }
                    return row['Duration'];
                },*/
                "Absence Start Months": jQuery.pivotUtilities.derivers.dateFormat("Absence start date", "%y-%m"),
                "Absence Start Day of Week": jQuery.pivotUtilities.derivers.dateFormat("Absence start date", "%w"),

                "Absence type": function(row) {
                    if (!checkAbsenceInContract(row)) {
                        return '';
                    }
                    return row["Absence type"];
                },
                "Absence start date": function(row) {
                    if (!checkAbsenceInContract(row)) {
                        return '';
                    }
                    return row["Absence start date"];
                },
                "Absence end date": function(row) {
                    if (!checkAbsenceInContract(row)) {
                        return '';
                    }
                    return row["Absence end date"];
                },
                "Absence status": function(row) {
                    if (!checkAbsenceInContract(row)) {
                        return '';
                    }
                    return row["Absence status"];
                },
                "Duration": function(row) {
                    if (checkAbsenceInContract(row)) {
                        return row["Duration"];
                    }
                    return '';
                },
                "Is credit": function(row) {
                    if (!checkAbsenceInContract(row)) {
                        return '';
                    }
                    return row["Is credit"];
                },
                "Absence Amount Taken": function(row) {
                    if (!checkAbsenceInContract(row)) {
                        return '';
                    }
                    if (parseInt(row['Is credit'], 10) === 0) {
                        return row['Duration'];
                    }
                    return 0;
                },
                "Absence Amount Accrued": function(row) {
                    if (!checkAbsenceInContract(row)) {
                        return '';
                    }
                    if (parseInt(row['Is credit'], 10) === 1) {
                        return row['Duration'];
                    }
                    return 0;
                },
                "Absence Absolute Duration": function(row) {
                    if (!checkAbsenceInContract(row)) {
                        return '';
                    }
                    if (parseInt(row['Is credit'], 10) === 1) {
                        return -row['Duration'];
                    }
                    return row['Duration'];
                },
            }
        }, false);
        
        function checkAbsenceInContract(row) {
            var contractStart = row["Period start date"].substring(0, 10);
            var contractEnd = row["Period end date"].substring(0, 10);
            var absenceStart = row["Absence start date"].substring(0, 10);
            var absenceEnd = row["Absence end date"].substring(0, 10);
            if (!contractStart || !absenceStart || absenceEnd < contractStart || absenceStart > contractEnd) {
                return false;
            }
            return true;
        }
        
        ///// Orb.js:
        function orbConvertData(data) {
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
            reportPerDateRefrestTable(perDateField, dateFilterValue);
        });
        
        function reportRefreshPivotTable(dateFilterValue) {
            console.info('reportRefreshPivotTable()');
            CRM.$.ajax({
                url: '/civihr-report---people/' + dateFilterValue + '/' + dateFilterValue,
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
                        unusedAttrsVertical: false/*,
                        derivedAttributes: {
                            "Gender Imbalance": function(mp) {
                                return mp["Gender"] == "Male" ? 1 : -1;
                            }
                        }*/
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
        
        CRM.$('#per-date-filter').bind('change', function(e) {
            perDateField = CRM.$(this).val();
            reportPerDateRefrestTable(perDateField, dateFilterValue);
        });
        
        function reportPerDateRefrestTable(perDateField, dateFilterValue) {
            console.info('reportPerDateRefreshTable()');
            if (perDateField === '') {
                return false;
            }
            CRM.$.ajax({
                url: '/hrreport_people_test_getdatereport/' + perDateField + '/' + dateFilterValue,
                error: function () {
                    console.info('error');
                },
                success: function (data) {
                    CRM.$('#reportPerDate').html(data);
                },
                type: 'GET'
            });
        }
    });
</script>
