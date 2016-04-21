<link href="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/pivot.css" rel="stylesheet" />
<link href="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/c3.min.css" rel="stylesheet" />
<script type="text/javascript" src="http://code.jquery.com/jquery-2.1.1.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivot.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/c3.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/d3.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/c3_renderers.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable/export_renderers.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/jquery-ui-1.9.2.custom.min.js"></script>
<script src="/sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecopivot.js"></script>
<?php /*<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecowebpivot.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecopivotdataapi.js"></script>
<script src="sites/all/modules/civihr-custom/civihr_employee_portal/js/pivottable-nreco/nrecopivotdataapi.jquery.nrecorelexbuilder-1.0"></script>
 */?>

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

<?php if (!empty($filters)): ?>
<a id="expose-filters-btn" class="btn btn-primary btn-default">Expose filters &raquo;</a>
<a id="collapse-filters-btn" class="btn btn-primary btn-default hidden">Collapse filters &laquo;</a>
<div id="report-filters" class="hidden">
    <?php print render($filters); ?>
</div>
<?php endif; ?>

<ul class="nav nav-tabs nav-justified report-tabs">
<?php if (!empty($tableUrl)): ?>
    <li role="presentation" class="active"><a class="btn btn-default" data-tab="data">Data</a></li>
<?php endif; ?>
<?php if (!empty($jsonUrl)): ?>
    <li role="presentation"><a class="btn btn-default" data-tab="pivot-table">Pivot Table</a></li>
<?php endif; ?>
<?php if (!empty($jsonUrl)): ?>
    <li role="presentation"><a class="btn btn-default" data-tab="orb-pivot-table">Orb Pivot Table</a></li>
<?php endif; ?>
</ul>

<div class="report-content">
    <div class="report-block data">
        <h4>Data</h4>
        <div id="reportTable"><?php print $table; ?></div>
<?php if (!empty($exportUrl)): ?>
        <a href="<?php print $exportUrl; ?>" id="export-report" class="btn btn-primary btn-default">Export</a>
<?php endif; ?>
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
<?php if (!empty($data)): ?>
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
            derivedAttributes: {}
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
                rows    : [],
                columns : [],
                data    : [],
                preFilters : {
                }
            };
        };
        var orbElem = document.getElementById('reportOrbPivotTable');
        var orbConvertedData = orbConvertData(data);
        var orbInstance = new orb.pgridwidget(orbConfig(orbConvertedData.fields, orbConvertedData.data));
        orbInstance.render(orbElem);
<?php endif; ?>
        ////////////////////////////////////////////////////////////////////////

<?php if (!empty($jsonUrl)): ?>
        function reportRefreshJson(filterValues) {
            console.info('reportRefreshJson()');
            CRM.$.ajax({
                url: '<?php print $jsonUrl; ?>' + filterValues,
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
<?php endif; ?>
<?php if (!empty($tableUrl)): ?>
        function reportRefreshTable(filterValues) {
            console.info('reportRefreshTable()');
            CRM.$.ajax({
                url: '<?php print $tableUrl; ?>' + filterValues,
                error: function () {
                    console.info('error');
                },
                success: function (data) {
                    CRM.$('#reportTable').html(data);
                    //CRM.$('#reportTable form').hide(); // temporary
                },
                type: 'GET'
            });
        }
        //CRM.$('#reportTable form').hide(); // temporary
<?php endif; ?>
<?php if (!empty($filters)): ?>
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
        CRM.$('#report-filters input[type="submit"]').bind('click', function(e) {
            e.preventDefault();
            console.info('submitting filters');
            var formSerialize = CRM.$('#report-filters form:first').formSerialize();
            console.info('formSerialize:');
            console.info(formSerialize);
<?php if (!empty($jsonUrl)): ?>
            reportRefreshJson('?' + formSerialize);
<?php endif; ?>
<?php if (!empty($tableUrl)): ?>
            reportRefreshTable('?' + formSerialize);
<?php endif; ?>
        });
<?php endif; ?>
        CRM.$('.report-tabs a').bind('click', function(e) {
            e.preventDefault();
            CRM.$('.report-tabs li').removeClass('active');
            CRM.$(this).parent().addClass('active');
            CRM.$('.report-block').addClass('hidden');
            CRM.$('.report-block.' + CRM.$(this).data('tab')).removeClass('hidden');
        });
        CRM.$('.report-tabs a:first').click();
    });
</script>
