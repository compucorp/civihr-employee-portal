<h2>CiviHR Report - People - proof of concept</h2>

<h4>Flat Table - sample with first 10 rows</h4>
<div id="reportTable"><?php print $table; ?></div>

<h4>PivotTable library</h4>
<div id="reportPivotTable"></div>

<h4>PivotTable library with NReco extensions</h4>
<div id="reportPivotTableNReco"></div>

<h4>React-Pivot library</h4>
<div id="reportReactPivot"></div>

<!--<h4>Orb library</h4>
<div id="reportOrb"></div>-->

<script type="text/javascript">
    CRM.$(function () {
        var data = <?php print $data; ?>;
        
        /*** PivotTable library initialization: ***/
        //var derivers = jQuery.pivotUtilities.derivers;
        var renderers = jQuery.extend(jQuery.pivotUtilities.renderers, 
            jQuery.pivotUtilities.c3_renderers);
        
        jQuery("#reportPivotTable").pivotUI(data, {
            cols: ["Age"],
            rows: ["Gender"],
            //aggregatorName: "Count",
            //vals: ["Contact ID"],
            rendererName: "Area Chart",
            renderers: renderers
        });
        
        /*** PivotTable library with NReco extensions initialization: ***/
        var nrecoPivotExt = new NRecoPivotTableExtensions({
            drillDownHandler: function (dataFilter) {
                console.log(dataFilter);

                var filterParts = [];
                for (var k in dataFilter) {
                    filterParts.push(k+"="+dataFilter[k]);
                }
                alert( filterParts.join(", "));	
            }
        });

        var stdRendererNames = ["Table","Table Barchart","Heatmap","Row Heatmap","Col Heatmap"];
        var wrappedRenderers = CRM.$.extend( {}, jQuery.pivotUtilities.renderers);
        CRM.$.each(stdRendererNames, function() {
            var rName = this;
            wrappedRenderers[rName] = nrecoPivotExt.wrapTableRenderer(wrappedRenderers[rName]);
        });

        var pvtOpts = {
            renderers: wrappedRenderers,
            rendererOptions: { sort: { direction : "desc", column_key : [ 2014 ]} },
            vals: ["Total"],
            rows: ["First name", "Contract type"],
            //cols: ["Age"],
            aggregatorName : "Count",
            rendererName: "Row Heatmap",
        }

        jQuery('#reportPivotTableNReco').pivotUI(data, pvtOpts);
        
        
        /*** React-Table library initialization: ***/
        var dimensions = [];
        for (i in data[0]) {
            dimensions.push({
                'value': i, 'title': i
            });
        }
        var reduce = function(row, memo) {
            //memo.Gender = (memo.Gender || 0) + parseFloat(row.transaction.amount)
            return memo;
        }
        var calculations = [
            {
                title: 'Total', value: 'amountTotal',
                template: function(val, row) {
                    return val;
                }
            }
        ];
        ReactPivot(document.getElementById('reportReactPivot'), {
            rows: data,
            dimensions: dimensions,
            calculations: calculations,
            reduce: reduce
        });
        
        
        /*** Orb library ***/
        /*var orbFields = [];
        var j = 0;
        for (var i in data[0]) {
            orbFields.push({
                name: j++,
                caption: i
            });
        }
        var config = {
            dataSource: data,
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
            fields: orbFields,
            rows    : [ 'Gender' ],
            columns : [ 'Age' ],
            data    : [  ],
            preFilters : {
                //'Manufacturer': { 'Matches': /n/ },
                //'Amount'      : { '>':  40 }
            },
            width: 1110,
            height: 645
        };

        new orb.pgridwidget(config).render(document.getElementById('reportOrb'));*/
    });
</script>
