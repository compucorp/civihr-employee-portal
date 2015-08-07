(function($) {
Drupal.behaviors.civihr_employee_portal_reports = {
    attach: function (context, settings) {

        // main filter can be (headcount, gender, age)
        $.cookie('mainFilter', 'headcount');

        var data; // Will hold our loaded json data later

        // Init the sub filters
        var subFilters = document.querySelectorAll(".subFilter");

        // Loop the buttons and attach the onclick function
        for (i = 0; i < subFilters.length; i++) {
            subFilters[i].onclick = function (data) {

                if (data.target !== null) {

                    // Set the subfilter
                    customReport.setSubFilter(data.target.id);

                    // @TODO pass the chart type from cookie or default value
                    customReport.drawGraph(customReport.getJsonUrl(), 'line');

                }

                return false;
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
            this.settings.hpadding = 5;

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
        };

        // Set default sub filter type
        DrawReport.prototype.setSubFilter = function(filter) {
            // Sets the filter to the object
            this.subFilter = filter;

            // Sets the filter on the cookie as well (helps to set default values)
            $.cookie('subFilter', filter);

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

                // Draw line chart
                if (type == 'line') {
                    visualizeLineChart(_this);
                }

                // Draw bar chart
                if (type == 'bar') {
                    visualizeBarChart(_this);
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
                    _this.drawGraph(_this.getJsonUrl(), 'line');
                })
                .text(function(d,i) {
                    return 'Line chart';
                });


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
        customReport.drawGraph(customReport.getJsonUrl(), 'line');

        console.log($.cookie('mainFilter'));
        console.log($.cookie('subFilter'));

        function visualizeLineChart(report) {

            $('#custom-report').empty();

            // Create SVG element
            var svg = d3.select("#custom-report")
                .append("svg")
                .attr("width", report.settings.outerWidth + report.settings.padding)
                .attr("height", report.settings.outerHeight);

            // Set up scales
            var scaleY = d3.scale.linear()
                .range([report.settings.innerHeight - report.settings.hpadding, report.settings.hpadding])
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
                    return report.settings.innerHeight - report.settings.hpadding - scaleY(d.data.count);  // Just the data value
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
                    return report.settings.innerHeight - 10;
                });

            // Append the axes
            svg.append("g")
                .attr("class", "axis")
                .attr("transform", "translate(" + report.settings.padding + ",0)")
                .call(yAxis);

            // Add chart types
            report.addChartTypes(svg);

        }

        function visualizeBarChart(report) {

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

            var viewArgument = d.data.department;

            $.ajax({
                type: 'GET',
                url: Drupal.settings.basePath + 'civihr_reports/' + viewName + '/' + viewDisplay + '?value=' + viewArgument + '&ajax=true',
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