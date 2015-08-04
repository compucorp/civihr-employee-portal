(function($) {
Drupal.behaviors.civihr_employee_portal_reports = {
    attach: function (context, settings) {


        // Round UP to the nearest five -> helper function
        function roundUp5(x) {
            return Math.ceil(x / 5) * 5;
        }

        var data; // Holds our loaded data

        var type = 'bar';

        console.log(Drupal.settings.basePath);

        d3.json(Drupal.settings.basePath + "all-roles", function(error, json) {
            if (error) return console.warn(error);

            console.log(json);

            // Prepare our data
            data = json.results;
            var settings = [];

            // Width and height for the SVG area
            settings.innerWidth = window.innerWidth / 3;
            settings.innerHeight = window.innerHeight / 3;
            settings.barPadding = 2;

            // Pie charts are round so we need a radius for them
            settings.radius = Math.min(settings.innerWidth, settings.innerHeight) / 2;

            // Set our defined range of coluor codes
            //settings.color = d3.scale.ordinal()
            //    .range(['#A60F2B', '#648C85', '#B3F2C9', '#528C18', '#C3F25C']);

            // Use 20 predefined colours
            settings.color = d3.scale.category20();

            // Set number of ticks
            settings.setTicks = 5;

            // Start x padding, when using axes
            settings.padding = 25;

            // Start y / height padding, when using axes
            settings.hpadding = 5;

            // Duration
            settings.duration = 250;

            // Draw the report
            if (type == 'line') {
                visualizeLineChart(settings);
            }
            if (type == 'bar') {
                visualizeBarChart(settings);
            }

        });

        function visualizeLineChart(settings) {

            $('#custom-report').empty();

            // Create SVG element
            var svg = d3.select("#custom-report")
                .append("svg")
                .attr("width", settings.innerWidth + settings.padding)
                .attr("height", settings.innerHeight);

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

                    console.log(d.data);

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

                            console.log(data);

                            var viewHtml = data;
                            console.log(viewHtml);
                            target.children().fadeOut(300, function() {
                                target.html(viewHtml);

                                var newHeightOfTarget = target.children().height();

                                target.children().hide();

                                target.animate({
                                    height: newHeightOfTarget
                                }, 150);

                                target.children().delay(150).fadeIn(300);

                                Drupal.attachBehaviors(target);
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

        }

        function visualizeBarChart(settings) {

            $('#custom-report').empty();

            var svg = d3.select('#custom-report')
                .append('svg')
                .attr('width', settings.innerWidth)
                .attr('height', settings.innerHeight)
                .append('g')
                .attr('transform', 'translate(' + (settings.innerWidth / 2) +  ',' + (settings.innerHeight / 2) + ')');

            var arc = d3.svg.arc()
                .outerRadius(settings.radius);

            var pie = d3.layout.pie()
                .value(function(d) { console.log(d); return d.data.count; })
                .sort(null);

            var path = svg.selectAll('path')
                .data(pie(data))
                .enter()
                .append('path')
                .attr('d', arc)
                .attr('fill', function(d, i) {
                    console.log(d);
                    return settings.color(d.data.data.department);
                });

        }
              
    }
}
})(jQuery);