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


<?php /*	
	<h1>PivotTable.js NReco Extensions Example</h1>
	<div id="samplePivotTable"></div>
	
<script type="text/javascript">
	$(function () {
		var sampleData = [{ "Year": 2011, "Total": "8800", "Country": "United States", "ID": 1, "Customer": "Orlando Rivas" }, { "Year": 2011, "Total": "6331", "Country": "Germany", "ID": 2, "Customer": "Jeremy Morton" }, { "Year": 2012, "Total": "7981", "Country": "United States", "ID": 3, "Customer": "Keane Powers" }, { "Year": 2011, "Total": "8324", "Country": "United States", "ID": 4, "Customer": "Nigel Hood" }, { "Year": 2010, "Total": "8875", "Country": "Spain", "ID": 5, "Customer": "Blaze Pearson" }, { "Year": 2014, "Total": "9602", "Country": "Spain", "ID": 6, "Customer": "Emmanuel Goff" }, { "Year": 2013, "Total": "6942", "Country": "Spain", "ID": 7, "Customer": "Kane Mcpherson" }, { "Year": 2014, "Total": "8384", "Country": "France", "ID": 8, "Customer": "Jermaine Page" }, { "Year": 2014, "Total": "5807", "Country": "Italy", "ID": 9, "Customer": "Merritt Boyle" }, { "Year": 2011, "Total": "6969", "Country": "United Kingdom", "ID": 10, "Customer": "Scott Briggs" }, { "Year": 2013, "Total": "7636", "Country": "United Kingdom", "ID": 11, "Customer": "Herman Sawyer" }, { "Year": 2012, "Total": "7687", "Country": "United States", "ID": 12, "Customer": "Keane Austin" }, { "Year": 2013, "Total": "5284", "Country": "France", "ID": 13, "Customer": "Rogan Hodge" }, { "Year": 2014, "Total": "7716", "Country": "Austria", "ID": 14, "Customer": "Marvin Fuentes" }, { "Year": 2014, "Total": "5107", "Country": "United Kingdom", "ID": 15, "Customer": "Grady Walker" }, { "Year": 2013, "Total": "9816", "Country": "France", "ID": 16, "Customer": "Austin Noble" }, { "Year": 2011, "Total": "9233", "Country": "France", "ID": 17, "Customer": "August Rollins" }, { "Year": 2012, "Total": "6583", "Country": "Germany", "ID": 18, "Customer": "Zachary Beard" }, { "Year": 2013, "Total": "5922", "Country": "Spain", "ID": 19, "Customer": "Hiram Daniel" }, { "Year": 2010, "Total": "7885", "Country": "France", "ID": 20, "Customer": "Marsden Acosta" }, { "Year": 2013, "Total": "5084", "Country": "Spain", "ID": 21, "Customer": "Len Head" }, { "Year": 2013, "Total": "8857", "Country": "United States", "ID": 22, "Customer": "Octavius Clemons" }, { "Year": 2012, "Total": "7540", "Country": "Italy", "ID": 23, "Customer": "Lane Burch" }, { "Year": 2012, "Total": "8787", "Country": "Italy", "ID": 24, "Customer": "Nehru Dickerson" }, { "Year": 2012, "Total": "6710", "Country": "Italy", "ID": 25, "Customer": "Price Powell" }, { "Year": 2010, "Total": "5340", "Country": "Austria", "ID": 26, "Customer": "Richard Page" }, { "Year": 2011, "Total": "5527", "Country": "United States", "ID": 27, "Customer": "Evan Walker" }, { "Year": 2014, "Total": "9211", "Country": "United States", "ID": 28, "Customer": "Guy Duncan" }, { "Year": 2014, "Total": "7633", "Country": "United Kingdom", "ID": 29, "Customer": "Barclay Bender" }, { "Year": 2012, "Total": "8180", "Country": "United States", "ID": 30, "Customer": "Hammett Petersen" }, { "Year": 2011, "Total": "6894", "Country": "United States", "ID": 31, "Customer": "Wing Buckley" }, { "Year": 2014, "Total": "5818", "Country": "Austria", "ID": 32, "Customer": "Marvin Cross" }, { "Year": 2011, "Total": "9088", "Country": "United States", "ID": 33, "Customer": "Rajah Graham" }, { "Year": 2014, "Total": "5464", "Country": "United Kingdom", "ID": 34, "Customer": "Amery Craig" }, { "Year": 2011, "Total": "7960", "Country": "Spain", "ID": 35, "Customer": "Jerry Leblanc" }, { "Year": 2010, "Total": "9129", "Country": "Italy", "ID": 36, "Customer": "Todd Grant" }, { "Year": 2010, "Total": "9821", "Country": "United States", "ID": 37, "Customer": "Lawrence Delgado" }, { "Year": 2010, "Total": "7594", "Country": "United States", "ID": 38, "Customer": "Kevin Jacobs" }, { "Year": 2014, "Total": "6654", "Country": "Spain", "ID": 39, "Customer": "Timothy Bartlett" }, { "Year": 2012, "Total": "6909", "Country": "United Kingdom", "ID": 40, "Customer": "Nash Harvey" }, { "Year": 2011, "Total": "8997", "Country": "Austria", "ID": 41, "Customer": "Noble Hawkins" }, { "Year": 2014, "Total": "8612", "Country": "United States", "ID": 42, "Customer": "Jameson Ingram" }, { "Year": 2013, "Total": "8412", "Country": "Germany", "ID": 43, "Customer": "Garrison Leon" }, { "Year": 2012, "Total": "6981", "Country": "Germany", "ID": 44, "Customer": "Hammett Conner" }, { "Year": 2010, "Total": "7603", "Country": "France", "ID": 45, "Customer": "Amery Warner" }, { "Year": 2012, "Total": "9921", "Country": "United States", "ID": 46, "Customer": "Zane Leonard" }, { "Year": 2011, "Total": "6044", "Country": "United States", "ID": 47, "Customer": "Gareth Mercer" }, { "Year": 2013, "Total": "9570", "Country": "United Kingdom", "ID": 48, "Customer": "Jackson Olsen" }, { "Year": 2013, "Total": "8161", "Country": "Italy", "ID": 49, "Customer": "Dustin Meyer" }, { "Year": 2013, "Total": "5495", "Country": "United States", "ID": 50, "Customer": "Logan Kelly" }, { "Year": 2011, "Total": "7844", "Country": "France", "ID": 51, "Customer": "Colt Gamble" }, { "Year": 2010, "Total": "7538", "Country": "France", "ID": 52, "Customer": "Fletcher Flores" }, { "Year": 2014, "Total": "6111", "Country": "Italy", "ID": 53, "Customer": "Noah Mays" }, { "Year": 2010, "Total": "9640", "Country": "Austria", "ID": 54, "Customer": "Fitzgerald Summers" }, { "Year": 2010, "Total": "7588", "Country": "Spain", "ID": 55, "Customer": "Fulton Molina" }, { "Year": 2010, "Total": "9738", "Country": "Spain", "ID": 56, "Customer": "Orson Clements" }, { "Year": 2011, "Total": "7548", "Country": "United Kingdom", "ID": 57, "Customer": "Abdul Davis" }, { "Year": 2010, "Total": "9138", "Country": "Austria", "ID": 58, "Customer": "Shad Baldwin" }, { "Year": 2011, "Total": "5931", "Country": "Spain", "ID": 59, "Customer": "Nash Lynn" }, { "Year": 2013, "Total": "6524", "Country": "United Kingdom", "ID": 60, "Customer": "Jack Warner" }, { "Year": 2014, "Total": "8655", "Country": "France", "ID": 61, "Customer": "Mark Giles" }, { "Year": 2010, "Total": "9216", "Country": "Austria", "ID": 62, "Customer": "Hayes Thornton" }, { "Year": 2010, "Total": "6063", "Country": "Spain", "ID": 63, "Customer": "Abel Glover" }, { "Year": 2012, "Total": "7479", "Country": "France", "ID": 64, "Customer": "Abdul Griffin" }, { "Year": 2014, "Total": "6197", "Country": "Spain", "ID": 65, "Customer": "Conan Oneal" }, { "Year": 2013, "Total": "9909", "Country": "United States", "ID": 66, "Customer": "Tarik Larsen" }, { "Year": 2014, "Total": "7177", "Country": "United States", "ID": 67, "Customer": "Ashton Parrish" }, { "Year": 2010, "Total": "8789", "Country": "United States", "ID": 68, "Customer": "Sean Beach" }, { "Year": 2012, "Total": "8344", "Country": "Spain", "ID": 69, "Customer": "Tanek Franks" }, { "Year": 2014, "Total": "8303", "Country": "United States", "ID": 70, "Customer": "Jakeem Lloyd" }, { "Year": 2012, "Total": "8144", "Country": "Italy", "ID": 71, "Customer": "Adrian Hood" }, { "Year": 2010, "Total": "9646", "Country": "Austria", "ID": 72, "Customer": "Valentine Chandler" }, { "Year": 2014, "Total": "5919", "Country": "United States", "ID": 73, "Customer": "Burton Finch" }, { "Year": 2011, "Total": "5506", "Country": "Germany", "ID": 74, "Customer": "Connor Atkinson" }, { "Year": 2013, "Total": "9906", "Country": "Germany", "ID": 75, "Customer": "Jermaine Sanchez" }, { "Year": 2010, "Total": "7587", "Country": "Italy", "ID": 76, "Customer": "Colby Frederick" }, { "Year": 2010, "Total": "5608", "Country": "Spain", "ID": 77, "Customer": "Jack Cash" }, { "Year": 2010, "Total": "5128", "Country": "United States", "ID": 78, "Customer": "Reece Hodge" }, { "Year": 2012, "Total": "7317", "Country": "France", "ID": 79, "Customer": "Gil Ayers" }, { "Year": 2011, "Total": "6559", "Country": "Germany", "ID": 80, "Customer": "Christopher Boone" }, { "Year": 2013, "Total": "8401", "Country": "Austria", "ID": 81, "Customer": "Garth Gould" }, { "Year": 2012, "Total": "8862", "Country": "Italy", "ID": 82, "Customer": "Hall Carey" }, { "Year": 2013, "Total": "8632", "Country": "France", "ID": 83, "Customer": "Mason Porter" }, { "Year": 2010, "Total": "7764", "Country": "Spain", "ID": 84, "Customer": "Scott Lowe" }, { "Year": 2012, "Total": "5806", "Country": "Germany", "ID": 85, "Customer": "Plato Stein" }, { "Year": 2011, "Total": "7394", "Country": "Spain", "ID": 86, "Customer": "Dane Keith" }, { "Year": 2010, "Total": "9800", "Country": "Italy", "ID": 87, "Customer": "Akeem Maxwell" }, { "Year": 2012, "Total": "5310", "Country": "Austria", "ID": 88, "Customer": "Connor Phillips" }, { "Year": 2010, "Total": "9983", "Country": "Italy", "ID": 89, "Customer": "Perry Riggs" }, { "Year": 2013, "Total": "8318", "Country": "Italy", "ID": 90, "Customer": "Davis Hensley" }, { "Year": 2012, "Total": "7270", "Country": "Germany", "ID": 91, "Customer": "Troy Estes" }, { "Year": 2011, "Total": "6461", "Country": "United States", "ID": 92, "Customer": "Keith Bradshaw" }, { "Year": 2013, "Total": "9665", "Country": "United Kingdom", "ID": 93, "Customer": "Dante Hansen" }, { "Year": 2013, "Total": "8974", "Country": "United Kingdom", "ID": 94, "Customer": "Lionel Chandler" }, { "Year": 2011, "Total": "8180", "Country": "Germany", "ID": 95, "Customer": "Noah Andrews" }, { "Year": 2013, "Total": "7339", "Country": "United States", "ID": 96, "Customer": "Otto Carson" }, { "Year": 2012, "Total": "9384", "Country": "Spain", "ID": 97, "Customer": "Wallace Blackburn" }, { "Year": 2013, "Total": "7395", "Country": "United Kingdom", "ID": 98, "Customer": "Forrest Stokes" }, { "Year": 2011, "Total": "8223", "Country": "Italy", "ID": 99, "Customer": "Otto Glenn" }, { "Year": 2013, "Total": "6892", "Country": "Austria", "ID": 100, "Customer": "Vladimir Bell" }];
		
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
		var wrappedRenderers = $.extend( {}, $.pivotUtilities.renderers);
		$.each(stdRendererNames, function() {
			var rName = this;
			wrappedRenderers[rName] = nrecoPivotExt.wrapTableRenderer(wrappedRenderers[rName]);
		});
		
		var pvtOpts = {
			renderers: wrappedRenderers,
			rendererOptions: { sort: { direction : "desc", column_key : [ 2014 ]} },
			vals: ["Total"],
			rows: ["Country"],
			cols: ["Year"],
			aggregatorName : "Sum"
		}


		$('#samplePivotTable').pivotUI(sampleData, pvtOpts);
	});


</script>


*/ ?>






<h2>CiviHR Report - People - proof of concept</h2>

<div><?php print drupal_render($date_filter); ?></div>

<?php /*<h4>Pivot Table</h4>
<div id="reportPivotTable"></div>*/ ?>
<h4>PivotTable library with NReco extensions</h4>
<div id="reportPivotTable"></div>
<div id="reportPivotTable2"></div>
<div id="pivotRelexBuilder">wtf?</div>
<button id="export">export</button>

<h4>Month-by-month Report</h4>
<div><?php //print drupal_render($per_date_filter); ?>
    <select id="per-date-filter">
        <option value=""></option>
        <option value="headcount">headcount</option>
        <option value="location">location</option>
        <option value="contract_type">contract type</option>
    </select>
</div>
<div id="reportPerDate"></div>



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
            unusedAttrsVertical: false
        }, false);
        



        /*** PivotTable library with NReco extensions initialization: ***/
        var nrecoPivotExt = new NRecoPivotTableExtensions({
            drillDownHandler: function (dataFilter) {
                console.log(dataFilter);

                var filterParts = [];
                for (var k in dataFilter) {
                    filterParts.push(k + "=" + dataFilter[k]);
                }
                alert(filterParts.join(", "));
            }
        });

        var stdRendererNames = ["Table", "Table Barchart", "Heatmap", "Row Heatmap", "Col Heatmap"];
        var wrappedRenderers = CRM.$.extend({}, jQuery.pivotUtilities.renderers, jQuery.pivotUtilities.export_renderers);
        CRM.$.each(stdRendererNames, function () {
            var rName = this;
            wrappedRenderers[rName] = nrecoPivotExt.wrapTableRenderer(wrappedRenderers[rName]);
        });
        // wrap pivottable renderers with nreco extensions
        var pivotStdRenderers = CRM.$.extend({}, jQuery.pivotUtilities.renderers);
        var nrecoPivotExt = new NRecoPivotTableExtensions({
            wrapWith: '<div class="pvtTableRendererHolder"></div>',
            drillDownHandler: function (attrFilter) {
                alert('Drill-down for: '+JSON.stringify( attrFilter ) );
            }
        });
        for (var rendererName in pivotStdRenderers) {
            // add sort handling to table renderer
            var renderer = nrecoPivotExt.wrapTableRenderer(pivotStdRenderers[rendererName]);
            pivotStdRenderers[rendererName] = renderer;
        }

        var allPivotRenderers = $.extend(pivotStdRenderers, 
            $.pivotUtilities.c3_renderers // alternative: $.pivotUtilities.gchart_renderers
        );
        for (var rendererName in allPivotRenderers) {
            // add data export api for renderer
            var renderer = allPivotRenderers[rendererName];
            allPivotRenderers[rendererName] = nrecoPivotExt.wrapPivotExportRenderer(renderer);
        }


        var sum = $.pivotUtilities.aggregatorTemplates.sum;
        var numberFormat = $.pivotUtilities.numberFormat;
        var intFormat = numberFormat({digitsAfterDecimal: 0});
        var tpl = $.pivotUtilities.aggregatorTemplates;

        var pvtOpts = {
            renderers: wrappedRenderers,
            vals: ["Total"],
            rows: ["Gender"/*, "Location"*/],
            cols: ["Month by month"],
            //aggregatorName: "Count", //"Count Unique Values",
            rendererName: "Row Heatmap",
            unusedAttrsVertical: false,
            derivedAttributes: {
//                "2015-01": function(row) {
//                    return row["Gender"] == "Male" ? 1 : -1;
//                }
            },
            /*aggregators: {
                "Sum1": function() { return tpl.sum()(["Gender"])}
            },
            aggregatorName: "Sum1"*/
            //aggregator: sum(intFormat)(["2015-01"])
            
        }
        
        var monthsFilter = [];
        var monthsCount = {};
        var yearFilter = '2015';
        var pad = '00';
        for (var monthI = 1; monthI < 1; monthI++) {
            var dateKey = yearFilter + '-' + (pad+monthI).slice(-pad.length);
            monthsFilter.push(dateKey);
            monthsCount[dateKey] = 0;
        }
        
        for (var i in monthsFilter) {
            /*pvtOpts.derivedAttributes[monthsFilter[i]] = (function(row) {
                return function() {
                    return row;
                }
            })(monthsFilter[i]);*/
            pvtOpts.rows.push(monthsFilter[i]);
            
            
            pvtOpts.derivedAttributes[monthsFilter[i]] = function(i) {
               return function(row) {
                                var result = row["Period start date"].substring(0,7) < monthsFilter[i] ? monthsFilter[i] : 0;
                                return result;
                                return monthsCount[monthsFilter[i]] += result;
                            }
                        
             }(i);
         }
         
         
         
        pvtOpts.derivedAttributes["Month by month"] = function(row) {
            return row["Period start date"].substring(0,7);
        }
         
var monthByMonth = function() {
  return function(data, rowKey, colKey) {
    /*console.info('successRate aggregator');
    console.info('data:');
    console.info(data);
    console.info('rowKey:');
    console.info(rowKey);
    console.info('colKey:');
    console.info(colKey);*/
        if (typeof colKey !== 'undefined' && colKey[0] === '1980-06') {
            console.info('cell:');
            console.info(data.rowAttrs);
            console.info(rowKey);
            console.info(colKey);
        }

    return {
      count: 0,
      push: function(record) {
          //console.info('record:');
          //console.info(record);
        //if (!isNaN(parseFloat(record.successes))) {
//parseInt(record["2015-01"]);
        //}
        return this.count++;
      },
      value: function() {
        var countResult = 0;
        if (typeof data !== 'undefined') {
            countResult = getCountsMonthByMonth(data.rowAttrs, rowKey, colKey);
        }
        if (countResult === 0) {
            ///countResult = this.count;
        }
        //this.sumSuccesses = countResult;
        return countResult;//this.sumSuccesses / 1;
      },
      format: function(x) { return x; },
      numInputs: 0
    };
  };
};

function getCountsMonthByMonth(fields, values, date) {
    //console.info('searching for:');
    //console.info(fields);
    //console.info(values);
    //console.info(date);
    var i = 0;
    var result = 0;
    if (fields.length === 0 || values.length === 0 ||  date.length === 0) {
        return result;
    }
    for (i in data) {
        if (typeof data[i]["Period start date"] === 'undefined') {
            //console.info('deb1');
            continue;
        }
        if (data[i]["Period start date"].substring(0,7) > date[0]) {
            //console.info('deb2');
            continue;
        }
        var valuesMatch = 0;
        for (var j in fields) {
            if (values[j] === '') {
                valuesMatch++;
                continue;
            }
            if (data[i][fields[j]] === values[j]) {
                valuesMatch++;
            }
        }
        //console.info('valuesMatch: '  + valuesMatch);
        //console.info('fields.length: ' + fields.length);
        if (valuesMatch === fields.length) {
            result++;
            //console.info('found:');
            //console.info(data[i]);
        }
    }
    return result;
}

         pvtOpts.aggregators = { "Month by month": monthByMonth };
         pvtOpts.aggregatorName = "Month by month";
    
pvtOpts.derivedAttributes.monthAndDayDeriver = $.pivotUtilities.derivers.dateFormat("Period start date", "%y-%m");
pvtOpts.derivedAttributes.ageBinDeriver = $.pivotUtilities.derivers.bin("Age", 10);

        jQuery('#reportPivotTable').pivotUI(data, pvtOpts);



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
        
        CRM.$('button#export').bind('click', function(e) {
            console.info('exporting');
            var reportData = $('#reportPivotTableNReco .pivotExportData').data('getPivotExportData')();
            console.log(reportData);
        });

    });
</script>
