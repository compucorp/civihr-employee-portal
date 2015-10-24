(function($) {
    'use strict';

    /**
     * D3Wrapper Object
     */
    var D3Wrapper = (function () {

        // Init default settings
        var _settings = (function (settings) {
            // The DOM container of the chart
            settings.container = '';

            settings.outerWidth = window.innerWidth / 2;
            settings.outerHeight = window.innerHeight / 2;

            // Width and height for the SVG area (for charts)
            settings.innerWidth = window.innerWidth / 3;
            settings.innerHeight = window.innerHeight / 3;
            settings.barPadding = 5;

            // Pie charts are round so we need a radius for them
            settings.radius = Math.min(settings.innerWidth, settings.innerHeight) / 2;

            // Set our defined range of colour codes for now
            // settings.color = d3.scale.ordinal()
            //    .range(['#A60F2B', '#648C85', '#B3F2C9', '#528C18', '#C3F25C']);

            // Use 20 predefined colours
            settings.color = d3.scale.category20();

            // Set number of ticks
            settings.setTicks = 5;

            // Start x padding, when using axes
            settings.padding = 25;

            // Start y / height padding, when using axes
            settings.hpadding = 25;

            // Set globally used margins
            settings.margin = {top: 20, right: 30, bottom: 30, left: 40},

            // Globally accessible svg_width and svg_height -> (mind the final svg width and height equals to svg_width + margins)
            settings.svg_width = settings.outerWidth + settings.padding;
            settings.svg_height = settings.outerHeight + settings.hpadding;

            // Duration
            settings.duration = 250;

            // Empty default click handler
            settings.clickHandler = function () {}

            return settings;
        })({});

        /**
         * Round UP to the nearest five -> helper function
         *
         */
        function roundUp5 (x) {
            return Math.ceil(x / 5) * 5;
        }

        return {

            /**
             * Draws a bar chart
             *
             * @param {JSON} chartData - The data to visualize
             */
            barChart: function (chartData) {
                document.querySelector(_settings.container).innerHTML = '';

                // Create SVG element
                var svg = d3.select(_settings.container)
                    .append("svg")
                    .attr("width", _settings.svg_width + _settings.margin.left + _settings.margin.right)
                    .attr("height", _settings.svg_height + _settings.margin.top + _settings.margin.bottom);

                // Set up scales
                var scaleX = d3.scale.ordinal()
                    .domain(d3.range(chartData.length))
                    .rangeBands([0, _settings.svg_width - _settings.padding], .3);

                var scaleY = d3.scale.linear()
                    .range([_settings.svg_height - _settings.padding, 0])
                    .domain([0, d3.max(chartData, function(d) { return roundUp5(d.data.count); })]);

                var xAxis = d3.svg.axis()
                    .scale(scaleX)
                    .tickFormat(function(d, i) {
                        return chartData[i]['data']['department'];
                    })
                    .orient("bottom");

                var yAxis = d3.svg.axis()
                    .scale(scaleY)
                    .orient("left")
                    .ticks(_settings.setTicks);

                svg.selectAll("rect")
                    .data(chartData)
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
                        return scaleX(i);
                    })
                    .attr("y", function (d) {
                        return scaleY(d.data.count) + _settings.hpadding;
                    })
                    .attr("width", _settings.innerWidth / chartData.length - _settings.barPadding)
                    .attr("height", function (d) {
                        return _settings.svg_height - _settings.hpadding - scaleY(d.data.count);
                    });

                // Append the axes
                svg.append("g")
                    .attr("class", "x-axis")
                    .style({ 'fill': 'none', 'stroke-width': '1px' })
                    .attr("transform", "translate(" + -30 + "," + _settings.svg_height + ")")
                    .call(xAxis);

                svg.append("g")
                    .attr("class", "y-axis")
                    .style({ 'stroke': 'Black', 'fill': 'none', 'stroke-width': '1px' })
                    .attr("transform", "translate(" + 30 + "," + _settings.padding + ")")
                    .call(yAxis);
            },

            /**
             * Draws a multiple bar chart
             *
             * @param {JSON} chartData - The data to visualize
             */
            multipleBarChart: function (chartData) {
                document.querySelector(_settings.container).innerHTML = '';

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
                    .entries(chartData);

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

                        return roundUp5(highest);
                    })])
                    .range([_settings.svg_height - _settings.padding, 0]);

                var x0 = d3.scale.ordinal()
                    .domain(d3.range(n))
                    .rangeBands([0, _settings.svg_width - _settings.padding], .3);

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

                var svg = d3.select(_settings.container).append("svg")
                    .attr("width", _settings.svg_width + _settings.margin.left + _settings.margin.right)
                    .attr("height", _settings.svg_height + _settings.margin.top + _settings.margin.bottom)
                    .append("svg:g");

                svg.append("g")
                    .attr("class", "y-axis")
                    .style({ 'stroke': 'Black', 'fill': 'none', 'stroke-width': '1px' })
                    .attr("transform", "translate(" + 30 + "," + _settings.padding + ")")
                    .call(yAxis);

                svg.append("g")
                    .attr("class", "x-axis")
                    .style({ 'fill': 'none', 'stroke-width': '1px' })
                    .attr("transform", "translate(" + -30 + "," + _settings.svg_height + ")")
                    .call(xAxis);

                svg.append("g").selectAll("g")
                    .data(nested_data)
                    .enter().append("g")
                    .style("fill", function (d, i) {
                        return z(d.key);
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
                    .attr("width", x1.rangeBand())
                    .attr("height", function (d) {
                        // If not set, just return 0
                        if (typeof d == "undefined") {
                            return _settings.svg_height - _settings.hpadding - y(0);
                        }

                        return _settings.svg_height - _settings.hpadding - y(d.values);
                    })
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

                        _settings.clickHandler(d);
                    })
                    .attr("x", function (d, i) {
                        return x0(i);
                    })
                    .attr("y", function (d) {
                        // If not set, just return 0
                        if (typeof d == "undefined") {
                            return y(0) + _settings.hpadding;
                        }

                        // d.key (holds headquarters / home office)
                        return y(d.values) + _settings.hpadding;
                    });

                // Add legend labels
                svg.append("g").selectAll("g")
                    .data(nested_data)
                    .enter().append("text")
                    .attr("font-family", "sans-serif")
                    .attr("font-size", "9px")
                    .attr("fill", function (d, i) {
                        return z(d.key);
                    })
                    .attr("text-anchor", "middle")
                    .text(function(d) {
                        return d.key;
                    })
                    .attr("x", function (d, i) {
                        return _settings.svg_width - _settings.barPadding;
                    })
                    .attr("y", function (d, i) {
                        return (i * _settings.hpadding) + _settings.outerHeight - 10;
                    });

                // Add legend small image icons
                svg.append("g").selectAll("g")
                    .data(nested_data)
                    .enter().append("rect")
                    .attr("width", 15)
                    .attr("height", 15)
                    .attr("fill", function (d, i) {
                        return z(d.key);
                    })
                    .attr("x", function(d, i) {
                        return _settings.svg_width - 50 - _settings.barPadding;
                    })
                    .attr("y", function(d, i) {
                        return (i * _settings.hpadding - 10) + _settings.outerHeight - 10;
                    });
            },

            /**
             * Draws a pie chart
             *
             * @param {JSON} chartData - The data to visualize
             */
            pieChart: function (chartData) {
                document.querySelector(_settings.container).innerHTML = '';

                var svg = d3.select(_settings.container)
                    .append('svg')
                    .attr("width", _settings.svg_width + _settings.margin.left + _settings.margin.right)
                    .attr("height", _settings.svg_height + _settings.margin.top + _settings.margin.bottom)
                    .append('g');

                var arc = d3.svg.arc()
                    .outerRadius(_settings.radius - 10)
                    .innerRadius(_settings.radius - 50);

                var pie = d3.layout.pie()
                    .value(function (d) {
                        return d.data.count;
                    })
                    .sort(null);

                var path = svg.selectAll("path")
                    .data(pie(chartData))
                    .enter()
                    .append("path")
                    .attr('transform', 'translate(' + (_settings.innerWidth / 2) +  ',' + (_settings.innerHeight / 2) + ')')
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
                    });

                // Add legend labels
                svg.append("g").selectAll("g")
                    .data(pie(chartData))
                    .enter().append("text")
                    .attr("font-family", "sans-serif")
                    .attr("font-size", "9px")
                    .attr("fill", function (d, i) {
                        return _settings.color(d.data.data.department);
                    })
                    .attr("text-anchor", "middle")
                    .text(function(d) {
                        return d.data.data.department;
                    })
                    .attr("x", function (d, i) {
                        return _settings.outerWidth + _settings.padding - _settings.barPadding;
                    })
                    .attr("y", function (d, i) {
                        return (i * _settings.hpadding) + _settings.outerHeight - 100;
                    });

                // Add legend small image icons
                svg.append("g").selectAll("g")
                    .data(pie(chartData))
                    .enter().append("rect")
                    .attr("width", 15)
                    .attr("height", 15)
                    .attr("fill", function (d, i) {
                        return _settings.color(d.data.data.department);
                    })
                    .attr("x", function (d, i) {
                        return _settings.outerWidth - 80 + _settings.padding - _settings.barPadding;
                    })
                    .attr("y", function (d, i) {
                        return (i * _settings.hpadding - 10) + _settings.outerHeight - 100;
                    });

                var count = svg.selectAll("count")
                    .data(pie(chartData));

                // Add count for each slice...
                count.enter()
                    .append("text")
                    .attr("font-family", "sans-serif")
                    .attr("x", _settings.innerWidth / 2)
                    .attr("y", _settings.innerHeight / 2)
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
            },

            /**
             * Override default settings
             *
             * @param {JSON} overrides - Overrides for default settings
             */
            settings: function (overrides) {
                for (var setting in overrides) {
                    _settings[setting] = overrides[setting];
                }
            }
        };
    })();



    /**
     * Displays a chart on the page, handling its filters and data table
     *
     * @param {Object} ChartLibrary - A library for drawing charts
     * @param {JSON} cleanData - ?
     * @param {Object} context [temporary]
     */
    function CustomReport(ChartLibrary, cleanData, context) {
        this.chartLibrary = ChartLibrary;
        this.chartLibrary.settings({
            container: '[data-graph-section="canvas"]',
            clickHandler: this.displayFilterData.bind(this)
        });

        this.context = context;
        this.cleanData = cleanData;

        this.getDOMElements();
        this.hideButtonTpls();
        this.setDataWrapperVisibility();
    }

    /**
     * Activate the given button and deactivate all the others in its section
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
        var $graphFilters = this.$DOM.section.graphFilters;

        this.clearButtons($graphFilters);

        // Only headcount reports can be bar/pie types
        // All other reports are currently grouped bar charts
        if (this.getMainFilter() != 'headcount' && this.getMainFilter() != 'fte') {
            this.addButton({
                active: this.getChartType() === 'grouped_bar',
                label: 'bar chart',
                click: function () {
                    this.drawGraph(this.getJsonUrl(), 'grouped_bar');
                }.bind(this)
            }, $graphFilters);
        } else {
            this.addButton({
                active: this.getChartType() === 'bar',
                label: 'bar chart',
                click: function () {
                    this.drawGraph(this.getJsonUrl(), 'bar');
                }.bind(this)
            }, $graphFilters);

            this.addButton({
                active: this.getChartType() === 'pie',
                label: 'pie chart',
                click: function () {
                    this.drawGraph(this.getJsonUrl(), 'pie');
                }.bind(this)
            }, $graphFilters);
        }
    };

    /**
     * Removes all the buttons contained in a given section
     *
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
        var button = $section.find('[data-graph-button-tpl]').clone();

        button
            .attr('data-graph-button', '')
            .removeAttr('data-graph-button-tpl')
            .addClass(button.data('graph-button-' + ( !!attributes.active ? 'active' : 'inactive' ) + '-class'))
            .show();

        button.on('click', function (event) {
            _this.activateButton($(this));

            if (attributes.click) {
                attributes.click(event);
            }
        });

        if (attributes.value) {
            button.data('value', attributes.value);
        }

        if (attributes.label) {
            button.text(attributes.label);
        }

        return button;
    };

    /**
     *
     * @param d (passed from D3)
     * @param report (report object) -> contains all the prototype settings and functions
     * @private
     */
    CustomReport.prototype.displayFilterData = function (d) {
        // Build the custom table with details
        var viewName = this.getViewMachineName();
        var viewDisplay = this.getViewDisplayName();

        // If any value cleanup needs to be done it need to be done at this stage
        var x_axis = d.data.department;
        var y_axis = this.cleanData['gender'](d.data.gender) || d.data.gender;

        if (this.$DOM.section.dataWrapper.is(':visible')) {
            this.$DOM.section.dataWrapper.find('table').animate({ opacity: 0.3 }, 500);
        }

        $.ajax({
            type: 'GET',
            url: buildURL(),
            success: function (data) {
                this.$DOM.section.dataWrapper
                    .html(data)
                    .ready(function () {
                        if (Drupal.vbo) {
                            // Reload js behaviours for views bulk operations
                            $('.vbo-views-form', this.context).each(function () {
                                Drupal.vbo.initTableBehaviors(this);
                                Drupal.vbo.initGenericBehaviors(this);
                            });
                        }

                        if (Drupal.civihr_theme) {
                            // Apply theme related js
                            Drupal.civihr_theme.applyCustomSelect();
                        }

                        this.$DOM.section.dataWrapper.fadeIn();
                    }.bind(this));
            }.bind(this),
            error: function (data) {
                this.$DOM.section.dataWrapper.html('An error occured!');
            }.bind(this)
        });

        // Returns the URL for the ajax call
        function buildURL() {
            var base_path = Drupal.settings.basePath;
            var menu_route = 'civihr_reports';
            var separator = '/';
            var args = '?x_axis=' + x_axis + '&y_axis=' + y_axis + '&ajax=true';

            return base_path + menu_route + separator + viewName + separator + viewDisplay + args;
        }
    };

    /**
     * This will draw report on specified json endpoint, with specified report type
     *
     * @param {string} json_url - The full url of the endpoint returning the graph data
     * @param {string} type - The graph type
     */
    CustomReport.prototype.drawGraph = function (json_url, type) {
        d3.json(json_url, function (error, json) {
            if (error) {
                return console.warn(error);
            }

            switch (type) {
                case 'grouped_bar':
                    this.setChartType('grouped_bar');
                    this.chartLibrary.multipleBarChart(json.results);
                    break;
                case 'pie':
                    this.setChartType('pie');
                    this.chartLibrary.pieChart(json.results);
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
        this.$DOM.section = {
            dataWrapper: this.$DOM.wrapper.find('[data-graph-section="data"]'),
            canvas: this.$DOM.wrapper.find('[data-graph-section="canvas"]'),
            graphFilters: this.$DOM.wrapper.find('[data-graph-section="graph-filters"]'),
            xFilters: this.$DOM.wrapper.find('[data-graph-section="x-filters"]'),
            yFilters: this.$DOM.wrapper.find('[data-graph-section="y-filters"]')
        };
    };

    /**
     * Get reports basic json url for graph report
     *
     * @return {string}
     */
    CustomReport.prototype.getJsonUrl = function () {
        // Returns the report graph url from (mainFilter and subFilter values)
        return Drupal.settings.basePath + this.getMainFilter() + '-' + this.getSubFilter();
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
     * Get view_display machine name what will be used when filtering the main view
     *
     * @return {string}
     */
    CustomReport.prototype.getViewDisplayName = function () {
        // Returns the view_display name from (mainFilter and subFilter values)
        return 'filter_' + this.getMainFilter() + '_' + this.getSubFilter();
    };

    /**
     * Get reports basic view machine_name based on selected filter types
     *
     * @return {string}
     */
    CustomReport.prototype.getViewMachineName = function () {
        // Returns the view machine name from (mainFilter and subFilter values)
        return this.getMainFilter() + '_' + this.getSubFilter();
    };

    /**
     * Hides all the template buttons
     *
     */
    CustomReport.prototype.hideButtonTpls = function () {
        $.each(this.$DOM.section, function (_, section) {
            section.find('[data-graph-button-tpl]').hide();
        });
    };

    /**
     * If the Data section has already a results table, show it
     *
     */
    CustomReport.prototype.setDataWrapperVisibility = function () {
        if (this.$DOM.section.dataWrapper.find('table').length > 0 ) {
            this.$DOM.section.dataWrapper.show();
        } else {
            this.$DOM.section.dataWrapper.hide();
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



    Drupal.behaviors.civihr_employee_portal_reports = {
        attach: function (context, settings) {
             // Wrapper around the settings js values
            var cleanData = {
                // Gender values
                gender: function (gender) {
                    return settings.civihr_employee_portal_reports.gender_options_data[gender];
                },

                // Enabled X Axis Group By settings (need to pass Y Group By machine name/type)
                enabled_x_axis_defaults: function (type) {
                    return settings.civihr_employee_portal_reports.enabled_x_axis_defaults['enabled_x_axis_filters_' + type];
                }
            };
            var customReport = new CustomReport(D3Wrapper, cleanData, context);
            // Init the main filters
            var mainFilters = document.querySelectorAll(".mainFilter");
            // Init the subFilters as global and leave empty for now
            var subFilters = '';

            customReport.$DOM.section.xFilters.hide();

            // Report to date selector
            $( "#reportToDate > input" )
                .datepicker({ dateFormat: "yy-mm-dd" })
                .change(function() { // When the date range changes update the graph
                    // If not set it will return All values
                    var toDate = this.value || 'All';

                    // Filter the graph by specifing To Date
                    customReport.drawGraph(customReport.getJsonUrl() + '/' + toDate, customReport.getChartType());
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

            // Loop the buttons and attach the onclick function
            for (var i = 0; i < mainFilters.length; i++) {
                mainFilters[i].onclick = function (data) {
                    if (data.target !== null) {
                        // Set the mainFilter
                        customReport.setMainFilter(data.target.id);

                        // Force change to location filter (when filters are updated)
                        customReport.setSubFilter('location');

                        // Add default classes
                        _checkDefaultClasses(mainFilters, data);
                        _checkChartTypes(customReport);

                        // Re-draw graph
                        customReport.drawGraph(customReport.getJsonUrl(), customReport.getChartType());

                        // Generate X Axis Group By buttons, when Y Axis Group By is clicked
                        _generateSubFilters(data, subFilters);
                    }

                    return false;
                }
            }

            customReport.drawGraph(customReport.getJsonUrl(), customReport.getChartType());

            // Set default classes on initial load
            _setDefaultClass(mainFilters, subFilters, customReport);

            /**
             * This function will generate the X Axis buttons, based on available X Axis Grouping options
             * @param data
             * @private
             */
            function _generateSubFilters(data, subFilters) {
                // Make array from object keys
                var dataGroups = Object.keys(cleanData.enabled_x_axis_defaults(data.target.id));
                var $xFilters = customReport.$DOM.section.xFilters;

                customReport.clearButtons($xFilters);

                dataGroups.forEach(function (value, key) {
                    customReport.addButton({
                        active: customReport.getSubFilter() === value,
                        label: value,
                        value: value,
                        click: function (data) {
                            if (data.target !== null) {
                                // Set the subfilter
                                customReport.setSubFilter($(data.target).data('value'));
                                // Re-draw graph
                                customReport.drawGraph(customReport.getJsonUrl(), customReport.getChartType());
                            }

                            return false;
                        }
                    }, $xFilters);
                });

                $xFilters.show();

                // Set default classes on initial load
                _setDefaultClass(mainFilters, subFilters, customReport);
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

                for (var check = 0; check < filters.length; check++) {
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
                for (var check = 0; check < mainFilters.length; check++) {
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
                if (customReport.getMainFilter() != 'headcount' && customReport.getMainFilter() != 'fte') {
                    customReport.setChartType('grouped_bar');
                } else {
                    // If the mainFilter value is 'headcount', and we have
                    // grouped_bar chart, reset it to default bar chart
                    if (customReport.setChartType() == 'grouped_bar') {
                        customReport.setChartType('bar');
                    }
                }
            }
        }
    }
})(jQuery);
