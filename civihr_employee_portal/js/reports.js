(function($) {
Drupal.behaviors.civihr_employee_portal_reports = {
    attach: function (context, settings) {

        // Round UP to the nearest five -> helper function
        function roundUp5(x) {
            return Math.ceil(x / 5) * 5;
        }

        var data; // Will hold our loaded json data later

        /**
         * DrawReport Object
         * @constructor
         */
        var DrawReport = function () {

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

        // This will draw report on specified json endpoint, with specified report type
        DrawReport.prototype.drawGraph = function(json_url, type) {

            console.log('draw');

            d3.json(Drupal.settings.basePath + json_url, function(error, json) {
                if (error) return console.warn(error);

                // Prepare our data
                data = json.results;

                // Draw line chart
                if (type == 'line') {
                    visualizeLineChart(report.settings);
                }

                // Draw bar chart
                if (type == 'bar') {
                    visualizeBarChart(report.settings);
                }

            });

        };

        // Init the basic Report Object
        var report = new DrawReport();

        report.drawGraph('all-roles', 'line');


        function visualizeLineChart(settings) {

            $('#custom-report').empty();

            // Create SVG element
            var svg = d3.select("#custom-report")
                .append("svg")
                .attr("width", settings.outerWidth + settings.padding)
                .attr("height", settings.outerHeight);

            // Set up scales
            var scaleY = d3.scale.linear()
                .range([settings.innerHeight - settings.hpadding, settings.hpadding])
                .domain([0, d3.max(data, function(d) { return roundUp5(d.data.count); })]);

            var yAxis = d3.svg.axis()
                .scale(scaleY)
                .orient("left")
                .ticks(settings.setTicks);

            svg.selectAll("rect")
                .data(data)
                .enter()
                .append("rect")
                .attr("fill", function(d, i) {

                    if (d.data.department == 'HR') {
                        return 'green';
                    }
                    else {
                        return 'teal';
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
                        .duration(settings.duration)
                        .attr("fill", "teal");
                })
                .on("click", function(d, i) {

                    $('#custom-report-details table').remove();
                    $('#custom-report-details').append('<table></table>');

                    // Build the custom table with details
                    var target = $('#custom-report-details');
                    var viewName = 'all_roles';
                    var viewDisplay = 'role_contacts';

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

                })
                .attr("x", function(d, i) {
                    return settings.padding + i * (settings.innerWidth / data.length);
                })
                .attr("y", function(d) {
                    return scaleY(d.data.count);
                })
                .attr("width", settings.innerWidth / data.length - settings.barPadding)
                .attr("height", function(d) {
                    return settings.innerHeight - settings.hpadding - scaleY(d.data.count);  // Just the data value
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
                    return i * (settings.innerWidth / data.length) + (settings.innerWidth / data.length - settings.barPadding) / 2;
                })
                .attr("y", function(d) {
                    return settings.innerHeight - 10;
                });

            // Append the axes
            svg.append("g")
                .attr("class", "axis")
                .attr("transform", "translate(" + settings.padding + ",0)")
                .call(yAxis);

            svg.append("text")
                .attr("class", "btn btn-primary btn-reports")
                .attr("type", "button")
                .attr("x", settings.outerWidth - 50)
                .attr("y", 50)
                .on('click', function(d,i) {
                    report.drawGraph('all-roles', 'bar');
                })
                .text(function(d,i) {
                    return 'Bar chart';
                })

            svg.append("text")
                .attr("class", "btn btn-primary btn-reports")
                .attr("type", "button")
                .attr("x", settings.outerWidth - 50)
                .attr("y", 100)
                .on('click', function(d,i) {
                    report.drawGraph('all-roles', 'line');
                })
                .text(function(d,i) {
                    return 'Line chart';
                })

        }

        function visualizeBarChart(settings) {

            $('#custom-report').empty();

            var svg = d3.select('#custom-report')
                .append('svg')
                .attr('width', settings.outerWidth)
                .attr('height', settings.outerHeight)
                .append('g')
                .attr('transform', 'translate(' + (settings.innerWidth / 2) +  ',' + (settings.innerHeight / 2) + ')');

            var arc = d3.svg.arc()
                .outerRadius(settings.radius);

            var pie = d3.layout.pie()
                .value(function(d) {
                    return d.data.count;
                })
                .sort(null);

            var path = svg.selectAll('path')
                .data(pie(data))
                .enter()
                .append('path')
                .attr('d', arc)
                .attr('fill', function(d, i) {
                    return settings.color(d.data.data.department);
                });

            svg.append("text")
                .attr("class", "btn btn-primary btn-reports")
                .attr("type", "button")
                .attr("x", 150)
                .attr("y", -100)
                .on('click', function(d,i) {
                    report.drawGraph('all-roles', 'bar');
                })
                .text(function(d,i) {
                    return 'Bar chart';
                })

            svg.append("text")
                .attr("class", "btn btn-primary btn-reports")
                .attr("type", "button")
                .attr("x", 150)
                .attr("y", -50)
                .on('click', function(d,i) {
                    report.drawGraph('all-roles', 'line');
                })
                .text(function(d,i) {
                    return 'Line chart';
                })

        }
              
    }
}
})(jQuery);