(function($) {
Drupal.behaviors.civihr_employee_portal_reports = {
    attach: function (context, settings) {


        // Round UP to the nearest five -> helper function
        function roundUp5(x) {
            return Math.ceil(x / 5) * 5;
        }

        var data; // Holds our loaded data

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

            // Set number of ticks
            settings.setTicks = 5;

            // Start x padding, when using axes
            settings.padding = 25;

            // Start y / height padding, when using axes
            settings.hpadding = 5;

            // Duration
            settings.duration = 250;

            // Draw the report
            visualize(settings);
        });

        function visualize(settings) {

            console.log(data);

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
     
        // Relationship visualisation
        var links = [
            {source: "Gergely Meszaros", target: "Civi Manager", source_type: "civihr_staff", target_type: "civihr_manager"},
            {source: "Civi Manager", target: "Admin", source_type: "civihr_manager", target_type: "civihr_admin"},
            {source: "Robin", target: "Civi Manager", source_type: "civihr_staff", target_type: "civihr_manager"},
            {source: "Rob", target: "Not set", source_type: "civihr_staff", target_type: "not_set"},
            {source: "John", target: "Civi Manager Admin", source_type: "civihr_staff", target_type: "civihr_admin"},
            {source: "Civi Manager Admin", target: "Admin", source_type: "civihr_admin", target_type: "civihr_admin"}
        ];

        var nodes = {};

        // Compute the distinct nodes from the links.
        links.forEach(function(link) {
            link.source = nodes[link.source] || (nodes[link.source] = {name: link.source, type: link.source_type});
            link.target = nodes[link.target] || (nodes[link.target] = {name: link.target, type: link.target_type});
        });

        var width = 960,
            height = 500;

        var force = d3.layout.force()
            .nodes(d3.values(nodes))
            .links(links)
            .size([width, height])
            .linkDistance(60)
            .charge(-300)
            .on("tick", tick)
            .start();

        var svg = d3.select("#relationship-report").append("svg")
            .attr("width", width)
            .attr("height", height);

        // Per-type markers, as they don't inherit styles.
        svg.append("defs").selectAll("marker")
            .data(["civihr_staff", "civihr_manager", "civihr_admin"])
            .enter().append("marker")
            .attr("id", function(d) { return d; })
            .attr("viewBox", "0 -5 10 10")
            .attr("refX", 15)
            .attr("refY", -1.5)
            .attr("markerWidth", 6)
            .attr("markerHeight", 6)
            .attr("orient", "auto")
            .append("path")
            .attr("d", "M0,-5L10,0L0,5");

        var path = svg.append("g").selectAll("path")
            .data(force.links())
            .enter().append("path")
            .attr("class", function(d) { return "link " + d.source_type; })
            .attr("marker-end", function(d) { return "url(#" + d.source_type + ")"; });

        var circle = svg.append("g").selectAll("circle")
            .data(force.nodes())
            .enter().append("circle")
            .attr("r", 6)
            .style("fill", function(d, i) {
                if (d.type != '') {
                    
                    if (d.type == 'civihr_admin') {
                        return 'red';
                    }
                    else if (d.type == 'civihr_staff') {
                        return 'green';
                    }
                    else if (d.type == 'civihr_manager') {
                        return 'grey';
                    }
                }
                
                // Default colour
                return 'yellow';
            })
            .on("click", clickEvent)
            .call(force.drag);

        var text = svg.append("g").selectAll("text")
            .data(force.nodes())
            .enter().append("text")
            .attr("x", 8)
            .attr("y", ".31em")
            .text(function(d) { return d.name; });

        // Use elliptical arc path segments to doubly-encode directionality.
        function tick() {
            path.attr("d", linkArc);
            circle.attr("transform", transform);
            text.attr("transform", transform);
        }
        
        function clickEvent(d) {
            console.log(d);
            console.log(d3.select(this));
        }

        function linkArc(d) {
            var dx = d.target.x - d.source.x,
                dy = d.target.y - d.source.y,
                dr = Math.sqrt(dx * dx + dy * dy);
            return "M" + d.source.x + "," + d.source.y + "A" + dr + "," + dr + " 0 0,1 " + d.target.x + "," + d.target.y;
        }

        function transform(d) {
            return "translate(" + d.x + "," + d.y + ")";
        }
              
    }
}
})(jQuery);