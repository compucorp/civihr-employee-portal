(function($) {
Drupal.behaviors.civihr_employee_portal_reports = {
    attach: function (context, settings) {

        console.log(settings);

        var data; // Will hold our loaded json data later

        // Init the main filters
        var mainFilters = document.querySelectorAll(".mainFilter");

        // Loop the buttons and attach the onclick function
        for (i = 0; i < mainFilters.length; i++) {
            mainFilters[i].onclick = function (data) {

                if (data.target !== null) {

                    // Set the mainFilter
                    customReport.setMainFilter(data.target.id);

                    // Add default classes
                    _checkDefaultClasses(mainFilters, data);

                    _checkChartTypes(customReport);

                    // Re-draw graph
                    customReport.drawGraph(customReport.getJsonUrl(), customReport.getChartType());

                }

                return false;
            }
        }

        // Init the sub filters
        var subFilters = document.querySelectorAll(".subFilter");

        // Loop the buttons and attach the onclick function
        for (i = 0; i < subFilters.length; i++) {
            subFilters[i].onclick = function (data) {

                if (data.target !== null) {

                    // Set the subfilter
                    customReport.setSubFilter(data.target.id);

                    // Add default classes
                    _checkDefaultClasses(subFilters, data);

                    // Re-draw graph
                    customReport.drawGraph(customReport.getJsonUrl(), customReport.getChartType());

                }

                return false;
            }
        }

        /**
         * Checks default CSS classes
         * @param subFilters or mainFilters
         * @param data
         * @private
         */
        function _checkDefaultClasses(filters, data) {

            // Append active class for filters
            $("#" + data.target.id).addClass("active");

            for (check = 0; check < filters.length; check++) {

                // Add active class if filter clicked
                if (filters[check]['id'] == data.target.id) {
                    $("#" + data.target.id).addClass("active");
                }
                else {
                    // Remove all other active classes
                    $("#" + filters[check]['id']).removeClass("active");
                }

            }

        }

        /**
         * Set default classes on initial load
         * @param subFilters
         * @private
         */
        function _setDefaultClass(mainFilters, subFilters, customReport) {

            for (check = 0; check < mainFilters.length; check++) {

                // Add active class if the cookie is already set)
                if (mainFilters[check]['id'] == customReport.getMainFilter()) {
                    $("#" + mainFilters[check]['id']).addClass("active");
                }

            }

            for (check = 0; check < subFilters.length; check++) {

                // Add active class if the cookie is already set)
                if (subFilters[check]['id'] == customReport.getSubFilter()) {
                    $("#" + subFilters[check]['id']).addClass("active");
                }

            }

        }

        /**
         * If the reports mainFilter value is gender or age allow only the grouped_bar chart
         * @param customReport
         * @private
         */
        function _checkChartTypes(customReport) {

            if (customReport.getMainFilter() != 'headcount') {
                customReport.setChartType('grouped_bar');
            }
            else {

                // If the mainFilter value is 'headcount', and we have grouped_bar chart, reset it to default bar chart
                if (customReport.setChartType() == 'grouped_bar') {
                    customReport.setChartType('bar');
                }
            }

        }

        /**
         * DrawReport Object
         * @constructor
         */
        function DrawReport() {

            // Init default settings for the Report class
            this.settings = [];

            this.settings.outerWidth = window.innerWidth / 2;
            this.settings.outerHeight = window.innerHeight / 2;

            // Width and height for the SVG area (for charts)
            this.settings.innerWidth = window.innerWidth / 3;
            this.settings.innerHeight = window.innerHeight / 3;
            this.settings.barPadding = 2;

            // Pie charts are round so we need a radius for them
            this.settings.radius = Math.min(this.settings.innerWidth, this.settings.innerHeight) / 2;

            // Set our defined range of colour codes for now
            // this.settings.color = d3.scale.ordinal()
            //    .range(['#A60F2B', '#648C85', '#B3F2C9', '#528C18', '#C3F25C']);

            // Use 20 predefined colours
            this.settings.color = d3.scale.category20();

            // Set number of ticks
            this.settings.setTicks = 5;

            // Start x padding, when using axes
            this.settings.padding = 25;

            // Start y / height padding, when using axes
            this.settings.hpadding = 25;

            // Duration
            this.settings.duration = 250;

            console.log('init');

        };

        // Round UP to the nearest five -> helper function
        DrawReport.prototype.roundUp5 = function(x) {
            return Math.ceil(x / 5) * 5;
        };

        // Create the default chart types (links + adds to SVG, onclick redraws the graph)
        DrawReport.prototype.addChartTypes = function(svg) {

            console.log('parent');
            var _this = this;

        };

        // Set default main filter type
        DrawReport.prototype.setMainFilter = function(filter) {
            this.mainFilter = filter;

            // Sets the filter on the cookie as well (helps to set default values)
            $.cookie('mainFilter', filter, { path: '/' });
        };

        // Set default sub filter type
        DrawReport.prototype.setSubFilter = function(filter) {
            // Sets the filter to the object
            this.subFilter = filter;

            // Sets the filter on the cookie as well (helps to set default values)
            $.cookie('subFilter', filter, { path: '/' });

        };

        // Get default sub filter type
        DrawReport.prototype.getSubFilter = function() {

            // Gets the default filter from the object
            if (this.subFilter !== 'undefined' && this.subFilter) {
                return this.subFilter;
            }

            // If not set on the object, try to get from the COOKIE values
            if ($.cookie('subFilter') !== 'undefined' && $.cookie('subFilter')) {
                return $.cookie('subFilter');
            }
            else {

                // Provide default sub filter type
                return 'department';
            }

        };

        // Get default main filter type
        DrawReport.prototype.getMainFilter = function() {

            // Gets the default filter from the object
            if (this.mainFilter !== 'undefined' && this.mainFilter) {
                return this.mainFilter;
            }

            // If not set on the object, try to get from the COOKIE values
            if ($.cookie('mainFilter') !== 'undefined' && $.cookie('mainFilter')) {
                return $.cookie('mainFilter');
            }
            else {

                // Provide default main filter type
                return 'headcount';
            }

        };

        // This will draw report on specified json endpoint, with specified report type
        DrawReport.prototype.drawGraph = function(json_url, type) {

            console.log('draw');
            var _this = this;

            d3.json(Drupal.settings.basePath + json_url, function(error, json) {
                if (error) return console.warn(error);

                // Prepare our data
                data = json.results;

                // Draw Simple bar chart
                if (type == 'bar') {

                    // Set "bar" chart
                    _this.setChartType('bar');

                    // Visualise
                    visualizeBarChart(_this);
                }

                // Draw pie chart
                if (type == 'pie') {

                    // Set "pie" chart
                    _this.setChartType('pie');

                    visualizePieChart(_this);
                }

                // Draw Grouped bar chart
                if (type == 'grouped_bar') {

                    // Set "grouped_bar" chart
                    _this.setChartType('grouped_bar');

                    multipleBarChart(_this);
                }

            });

        };

        // Extend base class (overwrite any default settings if needed)
        function CustomReport(name) {
            DrawReport.call(this);
            this.name = name;
            this.settings.barPadding = 5;

        }

        CustomReport.prototype = new DrawReport();

        // Overwrite any function if needed -> Create the default chart types (links + adds to SVG, onclick redraws the graph)
        CustomReport.prototype.addChartTypes = function(svg) {

            console.log('child');

            var _this = this;

            // Only headcount reports can be bar/pie types
            // All other reports are currently grouped bar charts
            if (this.getMainFilter() != 'headcount') {

                svg.append("text")
                    .attr("class", "btn btn-primary btn-reports")
                    .attr("type", "button")
                    .attr("x", _this.settings.outerWidth - 50)
                    .attr("y", 30)
                    .on('click', function(d,i) {
                        _this.drawGraph(_this.getJsonUrl(), 'grouped_bar');
                    })
                    .text(function(d,i) {
                        return 'Bar chart';
                    });

            }
            else {

                svg.append("text")
                    .attr("class", "btn btn-primary btn-reports")
                    .attr("type", "button")
                    .attr("x", _this.settings.outerWidth - 50)
                    .attr("y", 30)
                    .on('click', function(d,i) {
                        _this.drawGraph(_this.getJsonUrl(), 'bar');
                    })
                    .text(function(d,i) {
                        return 'Bar chart';
                    });

                svg.append("text")
                    .attr("class", "btn btn-primary btn-reports")
                    .attr("type", "button")
                    .attr("x", _this.settings.outerWidth - 50)
                    .attr("y", 60)
                    .on('click', function(d,i) {
                        _this.drawGraph(_this.getJsonUrl(), 'pie');
                    })
                    .text(function(d,i) {
                        return 'Pie chart';
                    });

            }

        };

        // Sets default chart type
        CustomReport.prototype.setChartType = function(chart_type) {
            // Sets the chart type to the object
            this.chartType = chart_type;

            // Sets the chartType on the cookie as well (helps to set default values)
            $.cookie('chartType', chart_type, { path: '/' });

        };

        // Gets the default chart type
        CustomReport.prototype.getChartType = function() {

            // Gets the default chart type from the object
            if (this.chartType !== 'undefined' && this.chartType) {
                return this.chartType;
            }

            // If not set on the object, try to get from the COOKIE values
            if ($.cookie('chartType') !== 'undefined' && $.cookie('chartType')) {
                return $.cookie('chartType');
            }
            else {

                // Provide default chart type
                return 'bar';
            }

        };

        // Get reports basic json url for graph report
        CustomReport.prototype.getJsonUrl = function() {
            // Returns the report graph url from (mainFilter and subFilter values)
            return this.getMainFilter() + '-' + this.getSubFilter();
        };

        // Get reports basic view machine_name based on selected filter types
        CustomReport.prototype.getViewMachineName = function() {
            // Returns the view machine name from (mainFilter and subFilter values)
            return this.getMainFilter() + '_' + this.getSubFilter();
        };

        // Get view_display machine name what will be used when filtering the main view
        CustomReport.prototype.getViewDisplayName = function() {
            // Returns the view_display name from (mainFilter and subFilter values)
            return 'filter_' + this.getMainFilter() + '_' + this.getSubFilter();
        };

        var customReport = new CustomReport('param to pass');
        customReport.drawGraph(customReport.getJsonUrl(), customReport.getChartType());

        // Set default classes on initial load
        _setDefaultClass(mainFilters, subFilters, customReport);

        function visualizeBarChart(report) {

            $('#custom-report').empty();

            // Create SVG element
            var svg = d3.select("#custom-report")
                .append("svg")
                .attr("width", report.settings.outerWidth + report.settings.padding)
                .attr("height", report.settings.outerHeight);

            // Set up scales
            var scaleY = d3.scale.linear()
                .range([report.settings.outerHeight - report.settings.hpadding, report.settings.hpadding])
                .domain([0, d3.max(data, function(d) { return report.roundUp5(d.data.count); })]);

            var yAxis = d3.svg.axis()
                .scale(scaleY)
                .orient("left")
                .ticks(report.settings.setTicks);

            svg.selectAll("rect")
                .data(data)
                .enter()
                .append("rect")
                .attr("fill", function(d, i) {

                    if (d.data.department == 'HR') {
                        return 'green';
                    }
                    else {
                        return report.settings.color(d.data.department);
                    }

                })
                .on("mouseover", function() {
                    d3.select(this)
                        .attr("cursor", "pointer")
                        .attr("fill", "orange");
                })
                .on("mouseout", function(d) {
                    d3.select(this)
                        .transition()
                        .duration(report.settings.duration)
                        .attr("fill", report.settings.color(d.data.department));
                })
                .on("click", function(d, i) {

                    _displayFilterData(d, report);

                })
                .attr("x", function(d, i) {
                    return report.settings.padding + i * (report.settings.innerWidth / data.length);
                })
                .attr("y", function(d) {
                    return scaleY(d.data.count);
                })
                .attr("width", report.settings.innerWidth / data.length - report.settings.barPadding)
                .attr("height", function(d) {
                    return report.settings.outerHeight - report.settings.hpadding - scaleY(d.data.count);  // Just the data value
                });

            svg.selectAll("text")
                .data(data)
                .enter()
                .append("text")
                .attr("font-family", "sans-serif")
                .attr("font-size", "9px")
                .attr("fill", "black")
                .attr("text-anchor", "middle")
                .text(function(d) {
                    return d.data.department;
                })
                .attr("x", function(d, i) {
                    return i * (report.settings.innerWidth / data.length) + (report.settings.innerWidth / data.length - report.settings.barPadding) / 2;
                })
                .attr("y", function(d) {
                    return report.settings.outerHeight - 10;
                });

            // Append the axes
            svg.append("g")
                .attr("class", "y axis")
                .style({ 'stroke': 'Black', 'fill': 'none', 'stroke-width': '1px' })
                .attr("transform", "translate(" + report.settings.padding + ",0)")
                .call(yAxis);

            // Add chart types
            report.addChartTypes(svg);

        }

        function visualizePieChart(report) {

            $('#custom-report').empty();

            var svg = d3.select('#custom-report')
                .append('svg')
                .attr('width', report.settings.outerWidth + report.settings.padding)
                .attr('height', report.settings.outerHeight)
                .append('g');

            var arc = d3.svg.arc()
                .outerRadius(report.settings.radius);

            var pie = d3.layout.pie()
                .value(function(d) {
                    return d.data.count;
                })
                .sort(null);

            var path = svg.selectAll("path")
                .data(pie(data))
                .enter()
                .append("path")
                .attr('transform', 'translate(' + (report.settings.innerWidth / 2) +  ',' + (report.settings.innerHeight / 2) + ')')
                .attr('d', arc)
                .on("mouseover", function() {
                    d3.select(this)
                        .attr("cursor", "pointer")
                        .attr("fill", "orange");
                })
                .on("mouseout", function(d) {
                    d3.select(this)
                        .transition()
                        .duration(report.settings.duration)
                        .attr("fill", report.settings.color(d.data.data.department));
                })
                .on("click", function(d, i) {
                    _displayFilterData(d.data, report);

                })
                .attr('fill', function(d, i) {
                    return report.settings.color(d.data.data.department);
                });

            var label = svg.selectAll("label")
                .data(pie(data));

            // Add text label for each slice...
            label.enter()
                .append("text")
                .attr("font-family", "sans-serif")
                .attr("x", report.settings.innerWidth / 2)
                .attr("y", report.settings.innerHeight / 2)
                .attr("font-size", "9px")
                .attr("fill", "black")
                .attr("text-anchor", "middle")
                .attr("transform", function(d) {
                    // Sets the text outside from the circle
                    d.innerRadius = report.settings.radius + 30;
                    return "translate(" + arc.centroid(d) + ")";
                })
                .text(function(d, i) { return d.data.data.department; });

            var count = svg.selectAll("count")
                .data(pie(data));

            // Add count for each slice...
            count.enter()
                .append("text")
                .attr("font-family", "sans-serif")
                .attr("x", report.settings.innerWidth / 2)
                .attr("y", report.settings.innerHeight / 2)
                .attr("font-size", "11px")
                .attr("font-style", "bold")
                .attr("fill", "white")
                .attr("text-anchor", "middle")
                .attr("transform", function(d) {
                    // Sets the text inside the circle
                    d.innerRadius = report.settings.radius - 80;
                    return "translate(" + arc.centroid(d) + ")";
                })
                .text(function(d, i) { return d.data.data.count; });

            // Add chart types
            report.addChartTypes(svg);

        }

        function multipleBarChart(report) {

            $('#custom-report').empty();

            console.log(data);

            var nested_data = d3.nest()
                .key(function(d) {
                    return d.data.gender;
                }).sortKeys(d3.ascending)
                .key(function(d) {
                    return d.data.department;
                })
                .rollup(function(d) {
                    return d3.sum(d, function(g) {
                        return 1;
                    });
                })
                .entries(data);

            console.log(nested_data);

            var tracker = 0;
            var assigned_key = '';

            var tracking_array = [];

            // Groups data
            nested_data.forEach(function(s, main_key) {
                s.values.forEach(function(x, i) {

                    if (typeof tracking_array[x.key] == "undefined") {

                        // Add to the array with current key (if not exist)
                        tracking_array[x.key] = tracker;

                        // Number of grouped charts
                        tracking_array['grouped_charts_num'] = tracker + 1;
                        tracker++;
                    }

                });
            });

            var n = tracking_array['grouped_charts_num'], // Number of grouped charts
                m = nested_data.length; // Number of columns / chart

            console.log(tracking_array);

            // Sorts data
            nested_data.forEach(function(s, main_key) {

                var sorted_array = [];

                $.map(nested_data[main_key].values, function (n, key_i) {
                    sorted_array[tracking_array[n.key]] = n;
                });

                nested_data[main_key].values = sorted_array;

            });

            var margin = {top: 20, right: 30, bottom: 30, left: 40},
                width = report.settings.outerWidth + report.settings.padding,
                height = report.settings.outerHeight + report.settings.hpadding;

            var y = d3.scale.linear()
                .domain([0, d3.max(nested_data, function(d) {

                    // Get the highest column value
                    var highest = 0;

                    $.each(d.values, function(key, object_test) {
                        if (object_test) {
                            if (object_test.values > highest) {
                                highest = object_test.values;
                            }
                        }
                    });

                    return report.roundUp5(highest);
                })])
                .range([height - report.settings.padding, 0]);

            var x0 = d3.scale.ordinal()
                .domain(d3.range(n))
                .rangeBands([0, width - report.settings.padding], .3);

            var x1 = d3.scale.ordinal()
                .domain(d3.range(m))
                .rangeBands([0, x0.rangeBand()]);

            var z = d3.scale.category10();

            var xAxis = d3.svg.axis()
                .scale(x0)
                .tickFormat(function(d, i) {

                    for(var key in tracking_array) {
                        var value = tracking_array[key];

                        if (tracking_array[key] == d) {
                            return key;
                        }
                    }
                })
                .orient("bottom");

            var yAxis = d3.svg.axis()
                .scale(y)
                .orient("left")
                .ticks(report.settings.setTicks);

            var svg = d3.select("#custom-report").append("svg")
                .attr("width", width + margin.left + margin.right)
                .attr("height", height + margin.top + margin.bottom)
                .append("svg:g");

            svg.append("g")
                .attr("class", "y axis")
                .style({ 'stroke': 'Black', 'fill': 'none', 'stroke-width': '1px' })
                .attr("transform", "translate(" + 30 + "," + report.settings.padding + ")")
                .call(yAxis);

            svg.append("g")
                .attr("class", "x-axis")
                .style({ 'fill': 'none', 'stroke-width': '1px' })
                .attr("transform", "translate(" + -30 + "," + height + ")")
                .call(xAxis);

            svg.append("g").selectAll("g")
                .data(nested_data)
                .enter().append("g")
                .style("fill", function(d, i) {
                    return z(d.key);
                })
                .attr("transform", function(d, i) {
                    return "translate(" + x1(i) + ",0)";
                })
                .attr("data-legend",function(d) {
                    return d.key;
                })
                .selectAll("rect")
                .data(function(d) {
                    // d.key (holds male / female);
                    return d.values;
                })
                .enter().append("rect")
                .attr("width", x1.rangeBand())
                .attr("height", function(d) {

                    // If not set, just return 0
                    if (typeof d == "undefined") {
                        return height - report.settings.hpadding - y(0);
                    }

                    return height - report.settings.hpadding - y(d.values);

                })
                .on("mouseover", function() {
                    d3.select(this)
                        .attr("cursor", "pointer")
                        .attr("fill", "orange");
                })
                .on("mouseout", function(d, i) {
                    d3.select(this)
                        .transition()
                        .duration(report.settings.duration)
                        .attr("fill", function() {
                            return z(d3.select(this.parentNode).attr("data-legend"));
                        })
                })
                .on("click", function(d, i) {

                    d.data = [];

                    // Get x axis value (Location, Department..)
                    d.data.department = d['key'];

                    // Get the y axis filter value (Gender, Age)
                    d.data.gender = d3.select(this.parentNode).attr("data-legend");

                    _displayFilterData(d, report);

                })
                .attr("x", function(d, i) {
                    return x0(i);
                })
                .attr("y", function(d) {

                    // If not set, just return 0
                    if (typeof d == "undefined") {
                        return y(0) + report.settings.hpadding;
                    }

                    // d.key (holds headquarters / home office)
                    return y(d.values) + report.settings.hpadding;
                });

            // Add legend labels
            svg.append("g").selectAll("g")
                .data(nested_data)
                .enter().append("text")
                .attr("font-family", "sans-serif")
                .attr("font-size", "9px")
                .attr("fill", function(d, i) {
                    return z(d.key);
                })
                .attr("text-anchor", "middle")
                .text(function(d) {
                    return d.key;
                })
                .attr("x", function(d, i) {
                    return width - report.settings.barPadding;
                })
                .attr("y", function(d, i) {
                    return (i * report.settings.hpadding) + report.settings.outerHeight - 10;
                });

            // Add legend small image icons
            svg.append("g").selectAll("g")
                .data(nested_data)
                .enter().append("rect")
                .attr("width", 15)
                .attr("height", 15)
                .attr("fill", function(d, i) { return z(d.key); })
                .attr("x", function(d, i) {
                    return width - 50  - report.settings.barPadding;
                })
                .attr("y", function(d, i) {
                    return (i * report.settings.hpadding - 10) + report.settings.outerHeight - 10;
                });

            // Add chart types
            report.addChartTypes(svg);

        }

        /**
         *
         * @param d (passed from D3)
         * @param report (report object) -> contains all the prototype settings and functions
         * @private
         */
        function _displayFilterData(d, report) {

            $('#custom-report-details table').remove();
            $('#custom-report-details').append('<table></table>');

            // Build the custom table with details
            var target = $('#custom-report-details');
            var viewName = report.getViewMachineName();
            var viewDisplay = report.getViewDisplayName();

            console.log(d);

            // Wrapper around the settings js values
            var getCleanData = {
                gender: function (gender) {
                    return settings.civihr_employee_portal_reports.gender_options_data[gender];
                }
            }

            // If any value cleanup needs to be done it need to be done at this stage
            var x_axis = d.data.department;
            var y_axis = getCleanData['gender'](d.data.gender) || '';

            console.log(d.data.gender);
            console.log(getCleanData['gender'](d.data.gender));

            // Returns the URL for the ajax call
            function buildURL() {

                var base_path = Drupal.settings.basePath;
                var menu_route = 'civihr_reports';
                var separator = '/';
                var arguments = '?x_axis=' + x_axis + '&y_axis=' + y_axis + '&ajax=true';

                return base_path + menu_route + separator + viewName + separator + viewDisplay + arguments;
            }

            console.log(buildURL());

            $.ajax({
                type: 'GET',
                url: buildURL(),
                success: function(data) {

                    var viewHtml = data;
                    target.children().fadeOut(300, function() {
                        target.html(viewHtml);

                        var newHeightOfTarget = target.children().height();

                        target.children().hide();

                        target.animate({
                            height: newHeightOfTarget
                        }, 150);

                        target.children().delay(150).fadeIn(300);

                        // If we need to reload js behaviours call this function
                        // Drupal.attachBehaviors(target);
                    });
                },
                error: function(data) {
                    target.html('An error occured!');
                }
            });

        }
              
    }
}
})(jQuery);