(function($) {
Drupal.behaviors.civihr_employee_portal_reports = {
    attach: function (context, settings) {
        
        var gender_dataset = [
                    ['male', 78], ['female', 27], ['not specified', 97]
                
        ];
        
        // Round UP to the nearest five -> helper function
        function roundUp5(x) {
            return Math.ceil(x / 5) * 5;
        }
        
        // Width and height for the SVG area
        var w = window.innerWidth / 3;
        var h = window.innerHeight / 3;
        var barPadding = 2;
        
        // Set number of ticks
        var setTicks = 20;
        
        // Start x padding, when using axes
        var padding = 25;
        
        // Start y / height padding, when using axes
        var hpadding = 5;
        
        // Create SVG element
        var svg = d3.select("#custom-report")
            .append("svg")
            .attr("width", w + padding)
            .attr("height", h);
    
        // Set up scales
        var scaleY = d3.scale.linear()
            .range([h - hpadding, hpadding])
            .domain([0, d3.max(gender_dataset, function(d) { return roundUp5(d[1]); })]);
        
        var yAxis = d3.svg.axis()
            .scale(scaleY)
            .orient("left")
            .ticks(setTicks);
    
        svg.selectAll("rect")
            .data(gender_dataset)
            .enter()
            .append("rect")
            .attr("fill", function(d, i) {
                
                if (d[0] == 'male') {
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
                    .duration(250)
                    .attr("fill", "teal");
            })
            .on("click", function(d, i) {
                
                // console.log(d[0]);
        
                $('#custom-report-details table').remove();
                $('#custom-report-details').append('<table></table>');
                
                // Build the custom table with details
                var table = $('#custom-report-details').children();
                for(i=0; i < d[1]; i++){
                    var val = i+1;
                    table.append( '<tr><td>' + d[0] + ' ' +  val + '</td></tr>' );
                }
            })
            .attr("x", function(d, i) {
                return padding + i * (w / gender_dataset.length);
            })
            .attr("y", function(d) {
                return scaleY(d[1]);
            })
            .attr("width", w / gender_dataset.length - barPadding)
            .attr("height", function(d) {
                return h - hpadding - scaleY(d[1]);  // Just the data value
            }); 
            
        svg.selectAll("text")
            .data(gender_dataset)
            .enter()
            .append("text")
            .attr("font-family", "sans-serif")
            .attr("font-size", "9px")
            .attr("fill", "black")
            .attr("text-anchor", "middle")
            .text(function(d) {
                return d[0];
            })
            .attr("x", function(d, i) {
                return i * (w / gender_dataset.length) + (w / gender_dataset.length - barPadding) / 2;
            })
            .attr("y", function(d) {
                return h - 10;
            });
            
        // Append the axes
        svg.append("g")
            .attr("class", "axis")
            .attr("transform", "translate(" + padding + ",0)")
            .call(yAxis);
     
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