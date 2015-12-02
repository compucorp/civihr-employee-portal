(function($) {
    'use strict';

    /**
     * Wraps the D3 JS library
     *
     * Must be given the css selectors for the chart and legend containers
     *
     * Example usage:
     *
     *   D3Wrapper.init({
     *       selectors: {
     *           chart: '.example-chart',
     *           legend: '#example-legend'
     *       },
     *       settings: {
     *           setTicks: 3,
     *           clickHandler: function (d) {
     *               // Handle the clicl event on chart elements
     *           }
     *       }
     *   });
     *
     *   D3Wrapper.barChart(chartData);
     */
    var D3Wrapper = (function () {

        // The chart object
        var _chart = {
            data: null,
            margin: { bottom: 30, left: 40, right: 30, top: 20 },
            selector: null,
            size: {},
            type: null,
            calculateSize: function () {
                this.size.width = document.querySelector(this.selector).clientWidth;
                this.size.height = this.size.width / 2;

                this.size.innerWidth = this.size.width - this.margin.left - this.margin.right;
                this.size.innerHeight = this.size.height - this.margin.top - this.margin.bottom;

                // Pie charts are round so we need a radius for them
                _settings.radius = Math.min(_chart.size.innerWidth, _chart.size.innerHeight) / 2;
            }
        };

        // The legend object
        var _legend = {
            constants: {
                ENTRY_FONT_SIZE: 13,
                ENTRY_ROW_HEIGHT: 15,
                ENTRY_ROW_MARGIN: 10,
                ICON_MARGIN: 5,
                ICON_SIZE: 15
            },
            margin: { bottom: 15, left: 15, right: 15, top: 15 },
            selector: null,
            size: {},
            calculateSize: function (data) {
                var padding = {
                    left: parseInt(window.getComputedStyle(document.querySelector(this.selector), null).getPropertyValue('padding-left')),
                    right: parseInt(window.getComputedStyle(document.querySelector(this.selector), null).getPropertyValue('padding-left'))
                };

                this.size.height = data.length * (this.constants.ENTRY_ROW_HEIGHT + this.constants.ENTRY_ROW_MARGIN) - this.constants.ENTRY_ROW_MARGIN + this.margin.left + this.margin.right;
                this.size.width = document.querySelector(this.selector).clientWidth - padding.left - padding.right;
            }
        };

        // Default settings
        var _settings = {
            color: d3.scale.category20(),
            duration: 250,
            setTicks: 5,
            clickHandler: function () { /* Empty default click handler */ }
        };

        /**
         * Draws the chart axis
         *
         * @param {Object} svg
         * @param {Object} xAxis
         * @param {Object} yAxis
         */
        function _drawAxis(svg, xAxis, yAxis) {
            svg.append("g")
                .attr("class", "chart-axis chart-axis-x")
                .style({ 'fill': 'none', 'stroke-width': '1px' })
                .attr("transform", "translate(0," + _chart.size.innerHeight + ")")
                .call(xAxis);

            svg.append("g")
                .attr("class", "chart-axis chart-axis-y")
                .style({ 'stroke': 'Black', 'fill': 'none', 'stroke-width': '1px' })
                .call(yAxis);
        }

        /**
         * Draws the chart legend
         *
         * @param {Object} svg
         * @param {Object} data - The data object from which to extract the labels
         * @param {Object} callbacks - .color() and .text() fns, to extract colors and labels
         */
        function _drawLegend(svg, data, callbacks) {
            _legend.calculateSize(data);

            var svg = _drawSvg(_legend);

            // Outer frame
            svg.append("rect")
                .attr("fill", "#ffffff")
                .attr("stroke", "#e6ecef")
                .attr("height", function () {
                    return _legend.size.height;
                })
                .attr("width", _legend.size.width)
                .attr("x", function (d, i) {
                    return -_legend.margin.left;
                })
                .attr("y", function (d, i) {
                    return -_legend.margin.top;
                });

            // Icons
            svg.selectAll("g")
                .data(data)
                .enter().append("rect")
                .attr("width", _legend.constants.ICON_SIZE)
                .attr("height", _legend.constants.ICON_SIZE)
                .attr("fill", callbacks.color)
                .attr('class', function (d, i) {
                    return 'chart-color-' + i;
                })
                .attr("x", function(d, i) {
                    return 0;
                })
                .attr("y", function(d, i) {
                    return (i * (_legend.constants.ICON_SIZE + _legend.constants.ENTRY_ROW_MARGIN));
                });

            // Labels
            svg.selectAll("g")
                .data(data)
                .enter()
                .append("text")
                    .attr("font-family", "sans-serif")
                    .attr("font-size", _legend.constants.ENTRY_FONT_SIZE + "px")
                    .attr("fill", '#535A67')
                    .attr("text-anchor", "left")
                    .text(callbacks.text)
                    .attr("x", function (d, i) {
                        return _legend.constants.ICON_SIZE + _legend.constants.ICON_MARGIN;
                    })
                    .attr("y", function (d, i) {
                        return (_legend.constants.ENTRY_ROW_HEIGHT / 1.3) + (i * (_legend.constants.ENTRY_ROW_HEIGHT + _legend.constants.ENTRY_ROW_MARGIN));
                    });
        };

        /**
         * Creates the SVG element
         *
         * @return {Object} element - Either the _chart or the _label object
         * @return {Array}
         */
        function _drawSvg(element) {
            document.querySelector(element.selector).innerHTML = '';

            return d3.select(element.selector)
                .append("svg")
                    .attr("width", element.size.width)
                    .attr("height", element.size.height)
                .append("g")
                    .attr("transform", "translate(" + element.margin.left + "," + element.margin.top + ")");
        }

        /**
         * The handler of the resize event
         *
         */
        function _resizeHandler () {
            _chart.calculateSize();
            this[_chart.type]();
        }

        /**
         * Round UP to the nearest five -> helper function
         *
         * @param {int} x
         * @return {float}
         */
        function _roundUp5 (x) {
            return Math.ceil(x / 5) * 5;
        }

        /**
         * Creates Date object required for slider ranges
         * @param dateValue
         * @returns {Date}
         */
        function createDateRange(dateValue) {
            if (dateValue != '') {
                console.log(dateValue);
                // Always for use the first day of the month so the range is set correctly
                return new Date(parseInt(dateValue.substring(0, 4)), parseInt(dateValue.substring(5, 7) - 1));
            }
        }


        return {

            /**
             * Initializes the object
             *
             * 1) Sets the selectors for the chart and legend container elements,
             * 2) Calculates the size of the chart based on the size of its container
             * 3) Overrides the default settings with the ones given
             * 4) Initializes the resize handler
             *
             * @param {JSON} options - Object containing the selectors and settings
             */
            init: function (options) {
                _chart.selector = options.selectors.chart;
                _legend.selector = options.selectors.legend;

                _chart.calculateSize();

                // Override default settings
                for (var setting in options.settings) {
                    _settings[setting] = options.settings[setting];
                }

                window.onresize = _resizeHandler.bind(this);
            },

            /**
             * Draws a bar chart
             *
             * @param {JSON} (optional) chartData - The data to visualize
             */
            barChart: function (chartData) {
                _chart.type = 'barChart';

                if (typeof chartData !== 'undefined') {
                    _chart.data =  chartData;
                }

                var svg = _drawSvg(_chart);

                var x = d3.scale.ordinal()
                    .domain(d3.range(_chart.data.length))
                    .rangeBands([0, _chart.size.innerWidth], .2);
                var y = d3.scale.linear()
                    .range([_chart.size.innerHeight, 0])
                    .domain([0, d3.max(_chart.data, function(d) { return _roundUp5(d.data.count); })]);

                var xAxis = d3.svg.axis()
                    .scale(x)
                    .tickFormat(function(d, i) {
                        return _chart.data[i]['data']['department'];
                    })
                    .orient("bottom");
                var yAxis = d3.svg.axis()
                    .scale(y)
                    .orient("left")
                    .ticks(_settings.setTicks);

                document.querySelector(_legend.selector).innerHTML = '';

                svg.selectAll("rect")
                    .data(_chart.data)
                    .enter()
                    .append("rect")
                    .attr("fill", function (d, i) {
                        if (d.data.department === 'HR') {
                            return 'green';
                        } else {
                            return _settings.color(d.data.department);
                        }
                    })
                    .attr('class', function (d, i) {
                        return d.data.department === 'HR' ? 'green' : 'chart-color-' + i;
                    })
                    .on("mouseover", function () {
                        d3.select(this)
                            .attr("cursor", "pointer")
                            .attr("fill", "orange");
                    })
                    .on("mouseout", function (d) {
                        d3.select(this)
                            .transition()
                            .duration(_settings.duration)
                            .attr("fill", _settings.color(d.data.department));
                    })
                    .on("click", function (d, i) {
                        _settings.clickHandler(d);
                    })
                    .attr("x", function (d, i) {
                        return x(i);
                    })
                    .attr("y", function (d) {
                        return y(d.data.count);
                    })
                    .attr("width", x.rangeBand())
                    .attr("height", function (d) {
                        return _chart.size.innerHeight - y(d.data.count);
                    });

                _drawAxis(svg, xAxis, yAxis);
            },

            /**
             * Draws a bar chart
             *
             * @param {JSON} (optional) chartData - The data to visualize
             */
            monthlyChart: function (chartData, dateRange) {
                console.log(dateRange);
                _chart.type = 'monthlyChart';

                if (typeof chartData !== 'undefined') {
                    _chart.data =  chartData;
                }

                var svg = _drawSvg(_chart);

                if (typeof dateRange === 'undefined'){
                    // our range is not yet selected
                    // fallback to some default date range
                    var date_ranges = []
                    date_ranges.push(new Date(2012, 0));
                    date_ranges.push(new Date(2012, 11));
                }
                else {
                    var date_ranges = dateRange.split("/");
                    date_ranges = date_ranges.map(createDateRange);

                    // Remove empty elements
                    date_ranges = date_ranges.filter(function(e) { return e; });
                    console.log(date_ranges);

                }
                // Monthly grouping (max and min date range value from the passed data)
                var x = d3.time.scale()
                    .domain(d3.extent(date_ranges, function(d) {
                        //console.log(d);
                        return d;
                    }))
                    .range([0, _chart.size.innerWidth]);

                var xAxis = d3.svg.axis()
                    .scale(x)
                    .orient("bottom")
                    .ticks(d3.time.months)
                    .tickSize(16, 0)
                    .tickFormat(d3.time.format("%B"));

                var y = d3.scale.linear()
                    .range([_chart.size.innerHeight, 0])
                    .domain([0, d3.max(_chart.data, function(d) { return _roundUp5(d.data.count); })]);

                var yAxis = d3.svg.axis()
                    .scale(y)
                    .orient("left")
                    .ticks(_settings.setTicks);

                document.querySelector(_legend.selector).innerHTML = '';

                var makeDate = d3.time.format("%Y-%m-%d %X").parse;

                // Define the line
                var valueline = d3.svg.line()
                    .x(function(d, i) {
                        // console.log(d.data.start_date);

                        // console.log(makeDate(d.data.start_date));
                        return x(makeDate(d.data.start_date));
                    })
                    .y(function(d) {
                        // console.log(d.data);
                        return y(Math.floor((Math.random() * 5)));
                    });

                svg.append("path")
                    .attr("class", "line")
                    .attr("style", "stroke: steelblue; stroke-width: 2; fill: none;")
                    .attr("d", valueline(_chart.data));

                /**
                var valueline2 = d3.svg.line()
                    .x(function(d, i) {
                        console.log(date_period[i]);
                        console.log(i);
                        return x(date_period[i]);
                    })
                    .y(function(d, i) {
                        console.log(d.data.count);
                        return y(d.data.count);
                    });

                */

                //svg.append("path")
                //    .datum(_chart.data)
                //    .attr("class", "line")
                //    .attr("d", valueline2);

                //svg.selectAll("rect")
                // .data(_chart.data)
                //    .append("path")      // Add the valueline2 path.
                //    .attr("class", "line")
                //    .style("stroke", "red")
                //    .attr("d", valueline2(_chart.data));

                /**
                svg.selectAll("rect")
                    .data(_chart.data)
                    .enter()
                    .append("rect")
                    .attr("fill", function (d, i) {
                        if (d.data.department === 'HR') {
                            return 'green';
                        } else {
                            return _settings.color(d.data.department);
                        }
                    })
                    .on("mouseover", function () {
                        d3.select(this)
                            .attr("cursor", "pointer")
                            .attr("fill", "orange");
                    })
                    .on("mouseout", function (d) {
                        d3.select(this)
                            .transition()
                            .duration(_settings.duration)
                            .attr("fill", _settings.color(d.data.department));
                    })
                    .on("click", function (d, i) {
                        _settings.clickHandler(d);
                    })
                    .attr("x", function (d, i) {
                        return x(i);
                    })
                    .attr("y", function (d) {
                        return y(d.data.count);
                    })
                    .attr("width", x.range())
                    .attr("height", function (d) {
                        return _chart.size.innerHeight - y(d.data.count);
                    });
                 */

                _drawAxis(svg, xAxis, yAxis);
            },

            /**
             * Draws a multiple bar chart
             *
             * @param {JSON} chartData - The data to visualize
             */
            multipleBarChart: function (chartData) {
                _chart.type = 'multipleBarChart';

                if (typeof chartData !== 'undefined') {
                    _chart.data = chartData;
                }

                var nested_data = d3.nest()
                    .key(function (d) {
                        return d.data.gender;
                    }).sortKeys(d3.ascending)
                    .key(function (d) {
                        return d.data.department;
                    })
                    .rollup(function (d) {
                        return d3.sum(d, function(g) {
                            return 1;
                        });
                    })
                    .entries(_chart.data);

                var tracker = 0;
                var assigned_key = '';
                var tracking_array = [];

                // Groups data
                nested_data.forEach(function (s, main_key) {
                    s.values.forEach(function (x, i) {
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

                // Sorts data
                nested_data.forEach(function (s, main_key) {
                    var sorted_array = [];

                    $.map(nested_data[main_key].values, function (n, key_i) {
                        sorted_array[tracking_array[n.key]] = n;
                    });

                    nested_data[main_key].values = sorted_array;
                });

                var y = d3.scale.linear()
                    .domain([0, d3.max(nested_data, function (d) {
                        // Get the highest column value
                        var highest = 0;

                        $.each(d.values, function(key, object_test) {
                            if (object_test) {
                                if (object_test.values > highest) {
                                    highest = object_test.values;
                                }
                            }
                        });

                        return _roundUp5(highest);
                    })])
                    .range([_chart.size.innerHeight, 0]);

                var x0 = d3.scale.ordinal()
                    .domain(d3.range(n))
                    .rangeBands([0, _chart.size.innerWidth], .2);

                var x1 = d3.scale.ordinal()
                    .domain(d3.range(m))
                    .rangeBands([0, x0.rangeBand()]);

                var z = d3.scale.category10();

                var xAxis = d3.svg.axis()
                    .scale(x0)
                    .tickFormat(function (d, i) {
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
                    .ticks(_settings.setTicks);

                var svg = _drawSvg(_chart);

                svg.append("g").selectAll("g")
                    .data(nested_data)
                    .enter().append("g")
                    .style("fill", function (d, i) {
                        return z(d.key);
                    })
                    .attr('class', function (d, i) {
                        return 'chart-color-' + i;
                    })
                    .attr("transform", function (d, i) {
                        return "translate(" + x1(i) + ",0)";
                    })
                    .attr("data-legend",function (d) {
                        return d.key;
                    })
                    .selectAll("rect")
                    .data(function (d) {
                        // d.key (holds male / female);
                        return d.values;
                    })
                    .enter().append("rect")
                    .on("mouseover", function () {
                        d3.select(this)
                            .attr("cursor", "pointer")
                            .attr("fill", "orange");
                    })
                    .on("mouseout", function (d, i) {
                        d3.select(this)
                            .transition()
                            .duration(_settings.duration)
                            .attr("fill", function() {
                                return z(d3.select(this.parentNode).attr("data-legend"));
                            })
                    })
                    .on("click", function (d, i) {
                        d.data = [];

                        // Get x axis value (Location, Department..)
                        d.data.department = d['key'];

                        // Get the y-axis filter value (Gender, Age)
                        d.data.gender = d3.select(this.parentNode).attr("data-legend");

                        console.log('click');
                        _settings.clickHandler(d);
                    })
                    .attr("x", function (d, i) {
                        return x0(i);
                    })
                    .attr("y", function (d) {
                        // If not set, just return 0
                        if (typeof d == "undefined") {
                            return y(0);
                        }

                        // d.key (holds headquarters / home office)
                        return y(d.values) ;
                    })
                    .attr("width", x1.rangeBand())
                    .attr("height", function (d) {
                        // If not set, just return 0
                        if (typeof d == "undefined") {
                            return _chart.size.innerHeight - y(0);
                        }

                        return _chart.size.innerHeight - y(d.values);
                    });

                _drawAxis(svg, xAxis, yAxis);
                _drawLegend(svg, nested_data, {
                    color: function (d, i) { return z(d.key); },
                    text: function(d) { return d.key; }
                });
            },

            /**
             * Draws a pie chart
             *
             * @param {JSON} chartData - The data to visualize
             */
            pieChart: function (chartData) {
                _chart.type = 'pieChart';

                if (typeof chartData !== 'undefined') {
                    _chart.data =  chartData;
                }

                var svg = _drawSvg(_chart);

                var arc = d3.svg.arc()
                    .outerRadius(_settings.radius - 10)
                    .innerRadius(_settings.radius - 50);

                var pie = d3.layout.pie()
                    .value(function (d) {
                        return d.data.count;
                    })
                    .sort(null);

                var count = svg.selectAll("count").data(pie(_chart.data));

                svg.selectAll("path")
                    .data(pie(_chart.data))
                    .enter()
                    .append("path")
                    .attr('transform', 'translate(' + (_chart.size.innerWidth / 2) +  ',' + (_chart.size.innerHeight / 2) + ')')
                    .attr('d', arc)
                    .on("mouseover", function () {
                        d3.select(this)
                            .attr("cursor", "pointer")
                            .attr("fill", "orange");
                    })
                    .on("mouseout", function (d) {
                        d3.select(this)
                            .transition()
                            .duration(_settings.duration)
                            .attr("fill", _settings.color(d.data.data.department));
                    })
                    .on("click", function (d, i) {
                        _settings.clickHandler(d.data);
                    })
                    .attr('fill', function (d, i) {
                        return _settings.color(d.data.data.department);
                    })
                    .attr('class', function (d, i) {
                        return 'chart-color-' + i;
                    });

                // Add count for each slice...
                count.enter()
                    .append("text")
                    .attr("font-family", "sans-serif")
                    .attr("x", _chart.size.innerWidth / 2)
                    .attr("y", _chart.size.innerHeight / 2)
                    .attr("font-size", "11px")
                    .attr("font-style", "bold")
                    .attr("fill", "white")
                    .attr("text-anchor", "middle")
                    .attr("transform", function(d) {
                        // Sets the text inside the circle
                        d.innerRadius = _settings.radius - 80;
                        return "translate(" + arc.centroid(d) + ")";
                    })
                    .text(function (d, i) {
                        return d.data.data.count;
                    });

                _drawLegend(svg, pie(_chart.data), {
                    color: function (d) { return _settings.color(d.data.data.department); },
                    text: function(d) { return d.data.data.department;}
                });
            },
        };
    })();



    /**
     * Displays a chart on the page, handling its filters and data table
     *
     * @param {JSON} options - Settings for the object
     */
    function CustomReport(options) {
        $.extend(this, options);

        this.init();
        this.drawGraph();
    }

    /**
     * Activates the given button and deactivate all the others in its section
     *
     * @param {Object} $button - The jQuery object to activate
     */
    CustomReport.prototype.activateButton = function ($button) {
        var $section = $button.parents('[data-graph-section]');

        $section.find('[data-graph-button]').each(function (_, button) {
            var $button = $(button);

            $button
                .addClass($button.data('graph-button-inactive-class'))
                .removeClass($button.data('graph-button-active-class'));
        });

        $button.addClass($button.data('graph-button-active-class'));
    };

    /**
     * Add a button to the given section
     *
     * If the section has an element marked with [data-graph-button-area], then
     * the button will be put there, otherwise it will be appended to the section
     *
     * @param {JSON} attributes - The attributes to apply to the cloned button
     * @param {Object} $section - jQuery object of the section
     */
    CustomReport.prototype.addButton = function (attributes, $section) {
        var $buttonArea = $section.find('[data-graph-button-area]');

        ($buttonArea.length ? $buttonArea : $section)
            .append(this.cloneButtonTpl(attributes, $section));
    };

    /**
     * Create the default chart types (links + adds to SVG, onclick redraws the graph)
     * Overwrite any function if needed
     *
     */
    CustomReport.prototype.addChartTypes = function () {
        var $graphFilters = this.$DOM.sections.filters.graph;

        this.clearButtons($graphFilters);

        // Only headcount reports can be bar/pie types
        // All other reports are currently grouped bar charts
        if (this.getMainFilter() !== 'headcount' && this.getMainFilter() !== 'fte') {
            this.addButton({
                active: this.getChartType() === 'grouped_bar',
                label: 'bar chart',
                click: function () {
                    this.setChartType('grouped_bar');
                    this.drawGraph();
                }.bind(this)
            }, $graphFilters);
        } else {
            this.addButton({
                active: this.getChartType() === 'bar',
                label: 'bar chart',
                click: function () {
                    this.setChartType('bar');
                    this.drawGraph();
                }.bind(this)
            }, $graphFilters);

            this.addButton({
                active: this.getChartType() === 'pie',
                label: 'pie chart',
                click: function () {
                    this.setChartType('pie');
                    this.drawGraph();
                }.bind(this)
            }, $graphFilters);

            this.addButton({
                active: this.getChartType() === 'monthly_chart',
                label: 'monthly chart',
                click: function () {
                    this.setChartType('monthly_chart');
                    this.drawGraph();
                }.bind(this)
            }, $graphFilters);
        }
    };

    /**
     * Removes all the buttons contained in a given section
     *
     * @param {Object} $section - jQuery object of the section
     */
    CustomReport.prototype.clearButtons = function ($section) {
        $section.find('[data-graph-button]').remove();
    };

    /**
     * Clones the button marked as a template inside the given section
     *
     * @param {JSON} attributes - The attributes to apply to the cloned button
     * @param {Object} $section - jQuery object of the section
     * @return jQuery object of the cloned button
     */
    CustomReport.prototype.cloneButtonTpl = function (attributes, $section) {
        var _this = this;
        var $button = $section.find('[data-graph-button-tpl]').clone();

        $button
            .attr('data-graph-button', '')
            .removeAttr('data-graph-button-tpl')
            .addClass($button.data('graph-button-' + ( !!attributes.active ? 'active' : 'inactive' ) + '-class'))
            .show();

        $button.on('click', function (event) {
            var $button = $(this);

            _this.activateButton($button);

            if (typeof attributes.click === 'function') {
                attributes.click($button);
            }

            event.preventDefault();
        });

        if (attributes.label) {
            $button.text(attributes.label);
        }

        if (attributes.value) {
            $button.data('value', attributes.value);
        }

        return $button;
    };

    /**
     *
     * @param d (passed from D3)
     * @private
     */
    CustomReport.prototype.displayFilterData = function (d) {
        // If any value cleanup needs to be done it need to be done at this stage
        var x_axis = d.data.department;
        var y_axis = this.cleanData['gender'](d.data.gender) || d.data.gender;

        if (this.$DOM.sections.dataWrapper.is(':visible')) {
            this.$DOM.sections.dataWrapper.find('table').animate({ opacity: 0.3 }, 500);
        }

        $.ajax({
            type: 'GET',
            url: buildURL.call(this),
            success: function (data) {
                this.$DOM.sections.dataWrapper
                    .html(data)
                    .ready(function () {
                        if (typeof this.on !== 'undefined' && typeof this.on.tableLoad === 'function') {
                            this.on.tableLoad();
                        }

                        this.$DOM.sections.dataWrapper.fadeIn();
                    }.bind(this));
            }.bind(this),
            error: function (data) {
                this.$DOM.sections.dataWrapper.html('An error occured!');
            }.bind(this)
        });

        // Returns the URL for the ajax call
        function buildURL() {
            var base_path = Drupal.settings.basePath;
            var menu_route = 'civihr_reports';
            var separator = '/';
            var args = '?x_axis=' + x_axis + '&y_axis=' + y_axis + '&ajax=true';

            return base_path + menu_route + separator + this.viewMachineName() + separator + this.viewDisplayName() + args;
        }
    };

    /**
     * This will draw report on specified json endpoint
     *
     * @param {string} path - Path to append to the default json URL
     */
    CustomReport.prototype.drawGraph = function (path) {
        var url = this.getJsonUrl() + ( typeof path !== 'undefined' ? path : '' );
        console.log(url);
        d3.json(url, function (error, json) {
            if (error) {
                return console.warn(error);
            }

            switch (this.getChartType()) {
                case 'grouped_bar':
                    this.setChartType('grouped_bar');
                    this.chartLibrary.multipleBarChart(json.results);
                    break;
                case 'pie':
                    this.setChartType('pie');
                    this.chartLibrary.pieChart(json.results);
                    break;
                case 'monthly_chart':
                    this.setChartType('monthly_chart');
                    this.chartLibrary.monthlyChart(json.results, path);
                    break;
                case 'bar':
                default:
                    this.setChartType('bar');
                    this.chartLibrary.barChart(json.results);
            }

            this.addChartTypes();
        }.bind(this));
    };

    /**
     * Generates the buttons for the main filters
     *
     */
    CustomReport.prototype.generateMainFilters = function() {
        var $mainFilters = this.$DOM.sections.filters.main;

        this.clearButtons($mainFilters);

        for (var value in this.filters.main) {
            this.addButton({
                active: value === this.getMainFilter(),
                label: this.filters.main[value],
                value: value,
                click: this.mainFilterClickHandler.bind(this)
            }, $mainFilters);
        }
    };

    /**
     * This function will generate the X Axis buttons, based on available X Axis Grouping options
     *
     * @param data
     * @private
     */
    CustomReport.prototype.generateSubFilters = function (mainFilter) {
        var subFilters = this.filters.sub(mainFilter);
        var $subFilters = this.$DOM.sections.filters.sub;

        this.clearButtons($subFilters);

        for (var value in subFilters) {
            this.addButton({
                active: this.getSubFilter() === value,
                label: subFilters[value],
                value: value,
                click: function ($button) {
                    this.setSubFilter($button.data('value'));
                    this.drawGraph();
                }.bind(this)
            }, $subFilters);
        };

        $subFilters.show();
    };

    /**
     * Gets the default chart type
     *
     * @return {string}
     */
    CustomReport.prototype.getChartType = function () {
        // Gets the default chart type from the object
        if (this.chartType !== 'undefined' && this.chartType) {
            return this.chartType;
        }

        // If not set on the object, try to get from the COOKIE values
        if ($.cookie('chartType') !== 'undefined' && $.cookie('chartType')) {
            return $.cookie('chartType');
        } else {
            // Provide default chart type
            return 'bar';
        }
    };

    /**
     * Collects the DOM elements marked by the [data-graph-*] data attribute
     *
     */
    CustomReport.prototype.getDOMElements = function () {
        this.$DOM = {};
        this.$DOM.wrapper = $('[data-graph]');
        this.$DOM.sections = {
            dataWrapper: this.$DOM.wrapper.find('[data-graph-section="data"]'),
            canvas: this.$DOM.wrapper.find('[data-graph-section="canvas"]'),
            filters: {
                graph: this.$DOM.wrapper.find('[data-graph-section="graph-filters"]'),
                main: this.$DOM.wrapper.find('[data-graph-section="main-filters"]'),
                sub: this.$DOM.wrapper.find('[data-graph-section="sub-filters"]')
            }
        };
    };

    /**
     * Get reports basic json url for graph report
     *
     * @return {string}
     */
    CustomReport.prototype.getJsonUrl = function () {
        // Returns the report graph url from (mainFilter and subFilter values)
        console.log(Drupal.settings.civihr_employee_portal_reports);
        return Drupal.settings.basePath + Drupal.settings.civihr_employee_portal_reports.prefix + '_' + this.getMainFilter() + '-' + this.getSubFilter();
    };

    /**
     * Get default main filter type
     *
     * @return {sring}
     */
    CustomReport.prototype.getMainFilter = function () {
        // Gets the default filter from the object
        if (this.mainFilter !== 'undefined' && this.mainFilter) {
            return this.mainFilter;
        }

        // If not set on the object, try to get from the COOKIE values
        if ($.cookie('mainFilter') !== 'undefined' && $.cookie('mainFilter')) {
            return $.cookie('mainFilter');
        } else {
            // Provide default main filter type
            return 'headcount';
        }
    };

    /**
     * Get default sub filter type
     *
     * @return {string}
     */
    CustomReport.prototype.getSubFilter = function () {
        // Gets the default filter from the object
        if (this.subFilter !== 'undefined' && this.subFilter) {
            return this.subFilter;
        }

        // If not set on the object, try to get from the COOKIE values
        if ($.cookie('subFilter') !== 'undefined' && $.cookie('subFilter')) {
            return $.cookie('subFilter');
        } else {
            // Provide default sub filter type
            return 'location';
        }
    };

    /**
     * Hides all the template buttons
     *
     */
    CustomReport.prototype.hideButtonTpls = function () {
        this.$DOM.wrapper.find('[data-graph-button-tpl]').hide();
    };

    /**
     * Hides sub filters section
     *
     */
    CustomReport.prototype.hideSubFilters = function () {
        this.$DOM.sections.filters.sub.hide()
    };

    /**
     * Initializes the object
     *
     */
    CustomReport.prototype.init = function () {
        this.chartLibrary.init({
            selectors: {
                chart: '[data-graph-section="canvas"]',
                legend: '[data-graph-section="legend"]'
            },
            settings: {
                clickHandler: this.displayFilterData.bind(this)
            }
        });

        this.getDOMElements();

        // Init date single filter
        this.initCalendar();

        // Init date slider
        this.initSlider();

        this.generateMainFilters();

        this.hideButtonTpls();
        this.hideSubFilters();
        this.setDataWrapperVisibility();
    };

    /**
     * Initializes the calendar element
     *
     */
    CustomReport.prototype.initCalendar = function () {
        var _this = this;

        // Report to date selector
        $('[data-graph-calendar] > input')
            .datepicker({ dateFormat: 'yy-mm-dd' })
            .change(function() { // When the date range changes update the graph
                // If not set it will return All values
                var toDate = this.value || 'All';

                // Filter the graph by specifing To Date (pass the same date for Start and End date in the views)
                _this.drawGraph('/' + toDate + '/' + toDate);
            });
    };

    /**
     * Initializes the slider element
     */
    CustomReport.prototype.initSlider = function() {
        var _this = this;

        $("#slider-range").slider({
            range: true,
            min: new Date('2010/01/01').getTime() / 1000, // min date
            max: new Date('2014/01/01').getTime() / 1000, // max date
            step: 86400,
            values: [new Date('2012/01/01').getTime() / 1000, new Date('2012/12/31').getTime() / 1000], // default range
            change: function(event, ui) {
                console.log(new Date(ui.values[0] * 1000));

                var start_date = new Date(ui.values[0] * 1000);
                var end_date = new Date(ui.values[1] * 1000);

                start_date = start_date.getFullYear() + "-" + ("0" + (start_date.getMonth() + 1)).slice(-2) + "-" + ("0" + (start_date.getDate())).slice(-2);
                end_date = end_date.getFullYear() + "-" + ("0" + (end_date.getMonth() + 1)).slice(-2) + "-" + ("0" + (end_date.getDate())).slice(-2);

                // Filter the graph by specifing Start and End date range
                _this.drawGraph('/' + start_date + '/' + end_date);

                $("#amount").val((new Date(ui.values[0] * 1000).toDateString()) + " - " + (new Date(ui.values[1] * 1000)).toDateString());
            }
        });

        $("#amount").val((new Date($( "#slider-range" ).slider("values", 0) * 1000).toDateString()) +
            " - " + (new Date($( "#slider-range" ).slider("values", 1) * 1000)).toDateString());

    };

    /**
     * Handler of the click event on main filters
     *
     * @param {Object} $button - jQuery object of the filter button
     */
    CustomReport.prototype.mainFilterClickHandler = function ($button) {

        /**
         * If the reports mainFilter value is gender or age allow only the grouped_bar chart
         * @param customReport
         * @private
         */
        function _checkChartTypes() {
            if (this.getMainFilter() !== 'headcount' && this.getMainFilter() !== 'fte') {
                this.setChartType('grouped_bar');
            } else {
                // If the mainFilter value is 'headcount', and we have
                // grouped_bar chart, reset it to default bar chart
                if (this.setChartType() === 'grouped_bar') {
                    this.setChartType('bar');
                }
            }
        }

        // Set the mainFilter
        this.setMainFilter($button.data('value'));

        // Force change to location filter (when filters are updated)
        this.setSubFilter('location');

        _checkChartTypes.call(this);

        // Re-draw graph
        this.drawGraph();

        // Generate X Axis Group By buttons, when Y Axis Group By is clicked
        this.generateSubFilters($button.data('value'));
    };

    /**
     * If the Data section has already a results table, show it
     *
     */
    CustomReport.prototype.setDataWrapperVisibility = function () {
        if (this.$DOM.sections.dataWrapper.find('table').length > 0) {
            this.$DOM.sections.dataWrapper.show();
        } else {
            this.$DOM.sections.dataWrapper.hide();
        }
    };

    /**
     * Sets default chart type
     *
     */
    CustomReport.prototype.setChartType = function (chart_type) {
        // Sets the chart type to the object
        this.chartType = chart_type;

        // Sets the chartType on the cookie as well (helps to set default values)
        $.cookie('chartType', chart_type, { path: '/' });
    };

    /**
     * Set default main filter type
     *
     */
    CustomReport.prototype.setMainFilter = function (filter) {
        this.mainFilter = filter;

        // Sets the filter on the cookie as well (helps to set default values)
        $.cookie('mainFilter', filter, { path: '/' });
    };

    /**
     * Set default sub filter type
     *
     */
    CustomReport.prototype.setSubFilter = function (filter) {
        // Sets the filter to the object
        this.subFilter = filter;

        // Sets the filter on the cookie as well (helps to set default values)
        $.cookie('subFilter', filter, { path: '/' });
    };

    /**
     * Get view_display machine name what will be used when filtering the main view
     * Returns the view_display name from (mainFilter and subFilter values)
     *
     * @return {string}
     */
    CustomReport.prototype.viewDisplayName = function () {
        return 'filter_' + this.viewMachineName();
    };

    /**
     * Get reports basic view machine_name based on selected filter types
     * Returns the view machine name from (mainFilter and subFilter values)
     *
     * @return {string}
     */
    CustomReport.prototype.viewMachineName = function () {
        return this.getMainFilter() + '_' + this.getSubFilter();
    };



    Drupal.behaviors.civihr_employee_portal_reports = {
        attach: function (context, settings) {
            var customReport = new CustomReport({
                chartLibrary: D3Wrapper,
                cleanData: {
                    gender: function (gender) {
                        return settings.civihr_employee_portal_reports.gender_options_data[gender];
                    }
                },
                filters: {
                    main: (function () {
                        return jQuery.makeArray($('[data-temporary-main-filters]')).reduce(function (obj, filter) {
                            obj['' + $(filter).data('value') + ''] = $(filter).data('label');

                            return obj;
                        }, {});
                    })(),
                    sub: function (type) {
                        // console.log(settings.civihr_employee_portal_reports);
                        var prefix = settings.civihr_employee_portal_reports.prefix;
                        return settings.civihr_employee_portal_reports.enabled_x_axis_defaults[prefix + '_enabled_x_axis_filters_' + type];
                    }
                },
                on: {
                    tableLoad: function () {
                        // Reload js behaviours for views bulk operations
                        if (Drupal.vbo) {
                            $('.vbo-views-form', context).each(function () {
                                Drupal.vbo.initTableBehaviors(this);
                                Drupal.vbo.initGenericBehaviors(this);
                            });
                        }
                    }
                }
            });

            $('.table-add', context).once('editableBehaviour', function () {
                // Apply the myCustomBehaviour effect to the elements only once.
                var $TABLE = $('#table');
                var $BTN = $('#export-btn');
                var $EXPORT = $("input[name='age_group_vals']");

                function _exportAgeGroups() {
                    var $rows = $TABLE.find('tr:not(:hidden)');
                    var headers = [];
                    var data = [];

                    // Get the headers (add special header logic here)
                    $($rows.shift()).find('th:not(:empty)').each(function () {
                        headers.push($(this).attr('id'));
                    });

                    // Turn all existing rows into a loopable array
                    $rows.each(function () {
                        var $td = $(this).find('td');
                        var h = {};

                        // Use the headers from earlier to name our hash keys
                        headers.forEach(function (header, i) {
                            h[header] = $td.eq(i).text();
                        });

                        data.push(h);
                    });

                    // Output the result
                    $EXPORT.val(JSON.stringify(data));
                }

                $('.table-add').click(function () {
                    var $clone = $TABLE.find('tr.hide').clone(true).removeClass('hide table-line');
                    $TABLE.find('table').append($clone);

                    // Update the hidden string
                    _exportAgeGroups();
                });

                $('.table-remove').click(function () {
                    $(this).parents('tr').detach();

                    // Update the hidden string
                    _exportAgeGroups();
                });

                $('.table-up').click(function () {
                    var $row = $(this).parents('tr');
                    if ($row.index() === 1) return; // Don't go above the header
                    $row.prev().before($row.get(0));

                    // Update the hidden string
                    _exportAgeGroups();
                });

                $('.table-down').click(function () {
                    var $row = $(this).parents('tr');
                    $row.next().after($row.get(0));

                    // Update the hidden string
                    _exportAgeGroups();
                });

                // A few jQuery helpers for exporting only
                jQuery.fn.pop = [].pop;
                jQuery.fn.shift = [].shift;

                var contents = $('.changeable').html();
                $('.changeable').blur(function () {
                    if (contents != $(this).html()) {

                        // Update the hidden string
                        _exportAgeGroups();

                        contents = $(this).html();
                    }
                });
            });
        }
    }
})(jQuery);
