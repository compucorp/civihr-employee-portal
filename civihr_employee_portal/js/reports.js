/* global angular, Drupal, jQuery, moment, Ps, swal */

(function ($) {
  'use strict';
  var compileAngularElement;

  /**
   * Define HRReport object.
   */
  function HRReport () {}

  /**
   * Initialization function.
   *
   * @param {JSON} options - Settings for the object.
   */
  HRReport.prototype.init = function (options) {
    $.extend(this, options);
    this.initAngular();
    this.processData(this.data);
    this.originalFilterElement = $('#report-filters').detach();
  };

  /**
   * Appends drag and drop instructions for the field rows and columns.
   */
  HRReport.prototype.appendFieldsDraggingInstructions = function () {
    var columnsMessage = 'Drag and drop a field here from the list on the left to add as a column heading / horizontal axis in the report.';
    var rowsMessage = 'Drag and drop a field here from the list on the left to add as a row heading / vertical axis in the report.';

    $('.report-field-columns .pvtAxisContainer').append('<p class="instructions">' + columnsMessage + '</p>');
    $('.report-field-rows .pvtAxisContainer').append('<p class="instructions">' + rowsMessage + '</p>');
  };

  /**
   * Compiles the filters element into an angular component. This is done for
   * elements created outside of the Angular cycle (ie: created using jQuery, etc.)
   */
  HRReport.prototype.appendFilters = function () {
    var element = this.originalFilterElement.clone();
    var filtersContainer = this.pivotTableContainer.find('.report-filters');

    compileAngularElement(element);
    filtersContainer.empty();
    element.appendTo(filtersContainer);
  };

  /**
   * Creates a new layout for the report elements.
   */
  HRReport.prototype.createReportSectionElement = function () {
    var html = '<div class="report-section">' +
      '<div class="row report-header-section">' +
        '<div class="report-filters col-md-3"></div>' +
        '<div class="report-function col-md-2 form-group">' +
          '<label>Chart Functions:</label>' +
          '<div class="report-function-select"></div>' +
          '<div class="report-function-group"></div>' +
        '</div>' +
        '<div class="report-field-columns col-md-7"><table><tr></tr></table></div>' +
      '</div>' +
      '<div class="row report-content-section">' +
        '<div class="report-fields-selection col-md-3"><table><tr></tr></table></div>' +
        '<div class="report-field-rows col-md-2"><table><tr></tr></table></div>' +
        '<div class="report-area col-md-7"></div>' +
      '</div>' +
    '</div>';

    this.pivotTableContainer.append(html);
  };

  /**
   * Hides the report rows and columns instructions if there are fields inside
   * of their container, otherwise displays the instructions.
   */
  HRReport.prototype.displayInstructionsIfDroppableHasNoFields = function () {
    $('.pvtAxisContainer .instructions').each(function () {
      var hasFields = $(this).siblings().length;

      hasFields ? $(this).slideUp() : $(this).slideDown();
    });
  };

  /**
   * Init PivotTable.js library
   */
  HRReport.prototype.initPivotTable = function () {
    this.pivotTableContainer.pivotUI(this.data, {
      rendererName: 'Table',
      renderers: $.extend(
        jQuery.pivotUtilities.renderers,
        jQuery.pivotUtilities.c3_renderers,
        jQuery.pivotUtilities.export_renderers
      ),
      vals: ['Count'],
      rows: [],
      cols: [],
      aggregatorName: 'Count',
      unusedAttrsVertical: false,
      aggregators: this.getAggregators(),
      derivedAttributes: this.derivedAttributes,

      // It's necessary to make all the DOM changes here
      // because the library doesn't have support to custom template
      // https://github.com/nicolaskruchten/pivottable/issues/484
      onRefresh: function (config) {
        return this.pivotTableOnRefresh(config);
      }.bind(this)
    }, false);
  };

  /**
   * Update Pivot Table config data on refresh.
   *
   * @param {JSON} config
   */
  HRReport.prototype.pivotTableOnRefresh = function (config) {
    Drupal.behaviors.civihr_employee_portal_reports.instance.updateCustomTemplate();
    var configCopy = JSON.parse(JSON.stringify(config));
    // delete some values which are functions
    delete configCopy['aggregators'];
    delete configCopy['renderers'];
    // delete some bulky default values
    delete configCopy['rendererOptions'];
    delete configCopy['localeStrings'];
    this.pivotConfig = configCopy;
  };

  /**
   * Return an object containing set of Pivot Table aggregators extended with
   * our custom ones.
   *
   * @returns {jQuery.pivotUtilities.aggregators|_$.pivotUtilities.aggregators|aggregators}
   */
  HRReport.prototype.getAggregators = function () {
    var aggregators = $.pivotUtilities.aggregators;
    var ordered = {};

    // Create custom Aggregator behaving like 'Count Unique Values' but
    // not counting NULL, 0 or empty strings.
    aggregators['Count Unique Values excluding null, 0 or empty'] = function (attributeArray) {
      var attribute = attributeArray[0];
      return function (data, rowKey, colKey) {
        return {
          uniq: [],
          push: function (record) {
            var _ref = record[attribute];
            if (!!+_ref && this.uniq.indexOf(_ref) < 0) {
              this.uniq.push(record[attribute]);
            }
          },
          value: function () { return this.uniq.length; },
          format: function (x) { return x; },
          numInputs: 1
        };
      };
    };
    aggregators['Sum field 1 by unique values of field 2'] = function (attributeArray) {
      var attribute1 = attributeArray[0];
      var attribute2 = attributeArray[1];
      return function (data, rowKey, colKey) {
        return {
          sum: 0,
          byFieldValues: [],
          push: function (record) {
            if (!isNaN(parseFloat(record[attribute1]))) {
              if (record[attribute2] in this.byFieldValues) {
                return this.sum;
              }
              this.byFieldValues[record[attribute2]] = 1;
              this.sum += parseFloat(record[attribute1]);

              return this.sum;
            }
          },
          value: function () {
            return this.sum;
          },
          format: function (x) { return x.toFixed(2); },
          numInputs: attribute1 != null ? 0 : 2
        };
      };
    };

    // Sort aggregators by keys.
    Object.keys(aggregators).sort().forEach(function (key) {
      ordered[key] = aggregators[key];
    });
    return ordered;
  };

  /**
   * Moves elements inside the report into a new element.
   *
   * @param {String} fromSelector - the path for the source element to move.
   * @param {String} toSelector - the path for the container element.
   */
  HRReport.prototype.moveReportElementFromTo = function (fromSelector, toSelector) {
    var fromElement = this.pivotTableContainer.find(fromSelector);
    var toElement = $(toSelector);

    if (!fromElement.length) {
      return;
    }

    toElement.empty();
    fromElement.detach().appendTo(toElement);
  };

  /**
   * Move the report original elements into new layout elements.
   */
  HRReport.prototype.moveReportElements = function () {
    this.moveReportElementFromTo('.pvtCols', '.report-field-columns table tr');
    this.moveReportElementFromTo('.pvtRows', '.report-field-rows table tr');
    this.moveReportElementFromTo('.pvtUnused', '.report-fields-selection table tr');
    this.moveReportElementFromTo('.pvtRenderer', '.chart-type-select');
    this.moveReportElementFromTo('.pvtAggregator', '.report-function-select');
    this.moveReportElementFromTo('.pvtVals', '.report-function-group');
    this.moveReportElementFromTo('.pvtRendererArea', '.report-area');
  };

  /**
   * Do additional required operations on data returned from backend.
   *
   * @param array data
   * @returns array
   */
  HRReport.prototype.processData = function (data) {
    // Set 'null' for all empty values.
    for (var i in data) {
      for (var j in data[i]) {
        if (data[i][j] === '') {
          data[i][j] = 'null';
        }
      }
    }
    return data;
  };

  /**
   * Updates the layout of the pivot table and form element styles.
   */
  HRReport.prototype.updateCustomTemplate = function () {
    var hasReportSectionElement = this.pivotTableContainer.find('.report-section').length;

    if (!hasReportSectionElement) {
      this.createReportSectionElement();
      this.moveReportElements();
      this.appendFilters();
      this.bindFilters();
      this.appendFieldsDraggingInstructions();
      this.displayInstructionsIfDroppableHasNoFields();
      this.bindDragAndDropEventListeners();
    }

    this.updateDropdown();
    this.updateFilterbox();
    this.adaptSvgProportionsToContainer();
  };

  /**
   * Update the pivot table dropdown to look like CiviHR style
   *
   */
  HRReport.prototype.updateDropdown = function () {
    $('.report-content select').each(function () {
      var selectClass = 'crm_custom-select crm_custom-select--full';

      if (!$(this).parent().hasClass('crm_custom-select')) {
        if ($(this).hasClass('pvtAggregator')) {
          selectClass += ' crm_custom-select--transparent';
        }

        $(this).wrap('<div class="' + selectClass + '"></div>');
        $(this).parent().append('<span class="crm_custom-select__arrow"></span>');
      }
    });

    $('.pvtVals .crm_custom-select').each(function () {
      if ($(this).find('select').length === 0) {
        $(this).remove();
      }
    });
  };

  /**
   * Update the filter box adding some classes to styling
   * the checkboxes and add a new checkbox to check all options
   *
   */
  HRReport.prototype.updateFilterbox = function () {
    var that = this;
    $('.pvtFilterBox').each(function () {
      $(this).find('.pvtSearch').removeClass('pvtSearch').addClass('form-text');
      $(this).find('button').addClass('btn btn-primary btn-block');

      if ($(this).find('.pvtFilterSelectAllWrap').length === 0) {
        var filters = $(this).find('.pvtFilter');

        $(this).find('.pvtFilterSelectAllWrap').remove();
        $(this).find('.pvtCheckContainer').prepend(`<p class="pvtFilterSelectAllWrap"><label><input type="checkbox" class="pvtFilterSelectAll" checked="checked"><span>Select All</span></label></p>`);

        $(this).find('.pvtFilterSelectAll').on('click', function () {
          filters.prop('checked', $(this).is(':checked'));
        });

        $(this).find('.pvtCheckContainer p').addClass('chr_custom-checkbox');
      }

      // Altering Employee length of service data to show number of days into
      // String format of Year, Months and Days of length of service.
      if (that.lengthOfServiceFilter(this)) {
        // Iterating through all the filter values.
        $(this).find('p.chr_custom-checkbox').each(function (i) {
          // Skip the Select All checkbox from filters.
          if (!$(this).hasClass('pvtFilterSelectAllWrap')) {
            that.lengthOfServiceValue(this);
          }
        });
      }
    });
  };

  /**
   * Updates the SVG element proportions so it adapts them to its
   * parent container. This helps the SVG charts to display their information
   * without breaking.
   */
  HRReport.prototype.adaptSvgProportionsToContainer = function () {
    this.pivotTableContainer.find('svg')
      .removeAttr('width')
      .removeAttr('height')
      .each(function () {
        // The viewBox attribute is done ins this way because jQuery doesn't
        // set it properly.
        // The value of 800 800 was chosen because it gives the best ratio
        // for displaying the charts.
        $(this)[0].setAttribute('viewBox', '0 0 800 800');
      });
  };

  /*
   * Finding the filter box for field Employee length of service.
   *
   *  @param {String} filterData
   *
   *  @return {bool}
   */
  HRReport.prototype.lengthOfServiceFilter = function (filterData) {
    return $(filterData).find('h4').text().indexOf('Employee length of service (') >= 0;
  };

  /*
   * Finding and replacing the value of Employee length of service.
   *
   *  @param {String} filterSelector - DOM element that has value.
   */
  HRReport.prototype.lengthOfServiceValue = function (filterSelector) {
    var that = this;
    // Fetching the Employee length of service from filter values.
    var employeeLengthService = $(filterSelector).find('span:first').text();
    if ($.isNumeric(employeeLengthService)) {
      $(filterSelector).find('span:first').text(that.formatLengthOfService(employeeLengthService));
    }
  };

  /**
   * Processes results in people report view to format length of service for each
   * contact in a human readable form using moment lib.
   *
   * @param {String} employeeLengthService - Employee length of service field value.
   *
   * @returns {String} Date format string for provide length of service.
   */
  HRReport.prototype.formatLengthOfService = function (employeeLengthService) {
    var dateEnd = moment();
    var dateStart = moment().subtract(employeeLengthService, 'days');

    if (!dateStart || !dateEnd) {
      return null;
    }

    var days, months, m, years;

    m = moment(dateEnd);
    years = m.diff(dateStart, 'years');

    m.add(-years, 'years');
    months = m.diff(dateStart, 'months');

    m.add(-months, 'months');
    days = m.diff(dateStart, 'days');

    years = years > 0 ? (years > 1 ? years + ' years ' : years + ' year ') : '';
    months = months > 0 ? (months > 1 ? months + ' months ' : months + ' month ') : '';
    days = days > 0 ? (days > 1 ? days + ' days' : days + ' day') : '';
    return (years + months + days) || '0 days';
  };

  /**
   * Shows the Report
   */
  HRReport.prototype.show = function () {
    this.initPivotTable();
    this.applyFilters();
  };

  /**
   * Gets the default query parameters for fetching results for the
   * Leave and absence report. It basically defaults to parameters
   * for fetching results for the current year
   *
   * @return {String}
   */
  HRReport.prototype.getDefaultFilterQueryForLeaveReport = function () {
    var fromDate = moment().startOf('month').format('YYYY-MM-DD');
    var toDate = moment().endOf('month').format('YYYY-MM-DD');
    var defaultFilterValues = [
      { name: 'absence_date_filter[min]', value: fromDate },
      { name: 'absence_date_filter[max]', value: toDate }
    ];

    return '?' + $.param(defaultFilterValues);
  }

  /**
   * Gets the default query parameters for fetching results for the
   * People report. It basically defaults the date parameter to the
   * current date.
   *
   * @return {String}
   */
  HRReport.prototype.getDefaultFilterQueryForPeopleReport = function () {
    var currentDate = moment().format('YYYY-MM-DD');
    var defaultFilterValues = [
      { name: 'between_date_filter[value]', value: currentDate }
    ];

    return '?' + $.param(defaultFilterValues);
  }

  /**
   * Processes the filter values and replaces with default values
   * for the people and leave reports when the filter values does
   * not have a query parameter appended.
   * On load of page the form values are not appended to query string
   * hence filterValues has a value of '?'
   *
   * @param  {String} filterValues
   * @return {String}
   */
  HRReport.prototype.processFilterValues = function (filterValues) {
    if (filterValues === '?' && this.reportName === 'leave_and_absence') {
      return this.getDefaultFilterQueryForLeaveReport()
    }

    if (filterValues === '?' && this.reportName === 'people') {
      return this.getDefaultFilterQueryForPeopleReport()
    }

    return filterValues;
  }

  /**
   * Refresh JSON data and Pivot Tables using provided filter values
   *
   * @param string filterValues
   */
  HRReport.prototype.refreshJson = function (filterValues) {
    var that = this;
    if (!this.jsonUrl) {
      return;
    }

    filterValues = that.processFilterValues(filterValues);

    $.ajax({
      url: this.jsonUrl + filterValues,
      error: function () {
        console.log('Error refreshing Report JSON data.');
      },
      success: function (data) {
        // Refreshing Pivot Table:
        data = that.processData(data);
        that.data = data;
        that.pivotTableContainer.pivotUI(data, {
          rendererName: 'Table',
          renderers: $.extend(
            jQuery.pivotUtilities.renderers,
            jQuery.pivotUtilities.c3_renderers
          ),
          unusedAttrsVertical: false,
          // It's necessary to make all the DOM changes here
          // because the library doesn't have support to custom template
          // https://github.com/nicolaskruchten/pivottable/issues/484
          onRefresh: function (config) {
            return that.pivotTableOnRefresh(config);
          }
        }, false);
      },
      type: 'GET'
    });
  };

  /**
   * Refresh data table using provided filter values
   *
   * @param string filterValues
   */
  HRReport.prototype.refreshTable = function (filterValues) {
    var that = this;
    if (!this.tableUrl) {
      return;
    }

    filterValues = that.processFilterValues(filterValues);

    var tableDomId = this.getReportTableDomID();
    $.ajax({
      url: that.tableUrl + filterValues,
      error: function () {
        console.log('Error refreshing Report data table.');
      },
      success: function (data) {
        that.tableContainer.html(data);
        that.refreshReportTableViewInstance(tableDomId);
      },
      type: 'GET'
    });
  };

  /**
   * Return unique Drupal View's DOM ID of data table
   */
  HRReport.prototype.getReportTableDomID = function () {
    var reportTableDiv = $('#reportTable > div.view:first');
    var reportTableClasses = reportTableDiv.attr('class').split(' ');
    for (var i in reportTableClasses) {
      if (reportTableClasses[i].substring(0, 12) === 'view-dom-id-') {
        return reportTableClasses[i].substr(12);
      }
    }
    return null;
  };

  /**
   * Reinitialize View instance of data table for given View's DOM ID
   *
   * @param string viewReportDataTableId
   */
  HRReport.prototype.refreshReportTableViewInstance = function (viewReportDataTableId) {
    var AjaxViews = Drupal.views.ajaxView;
    var viewReportDataTableSettings = Drupal.settings.views.ajaxViews['views_dom_id:' + viewReportDataTableId];
    var viewReportDataTableNewId = this.getReportTableDomID();

    delete Drupal.settings.views.ajaxViews['views_dom_id:' + viewReportDataTableId];
    delete Drupal.views.instances['views_dom_id:' + viewReportDataTableId];

    viewReportDataTableSettings.view_dom_id = viewReportDataTableNewId;
    Drupal.settings.views.ajaxViews['views_dom_id:' + viewReportDataTableNewId] = viewReportDataTableSettings;
    Drupal.views.instances['views_dom_id:' + viewReportDataTableNewId] = new AjaxViews(Drupal.settings.views.ajaxViews['views_dom_id:' + viewReportDataTableNewId]);
  };

  /**
   * Binds drag and drop event listeners for the field containers. These are
   * used for highlighting the droppable containers and removing instructions
   * once a field is dropped in a column or row container.
   */
  HRReport.prototype.bindDragAndDropEventListeners = function () {
    var draggableItems = this.pivotTableContainer.find('.report-fields-selection .pvtAxisContainer, .report-field-columns .pvtAxisContainer, .report-field-rows .pvtAxisContainer');
    var droppableContainers = this.pivotTableContainer.find('.report-field-columns .pvtAxisContainer, .report-field-rows .pvtAxisContainer');
    var highlightClass = 'highlight';

    draggableItems.on('sortstart', function () {
      droppableContainers.addClass(highlightClass);
    });

    draggableItems.on('sortstop', function (event) {
      droppableContainers.removeClass(highlightClass);
      this.displayInstructionsIfDroppableHasNoFields();
    }.bind(this));
  };

  /**
   * Bind filters UI events
   */
  HRReport.prototype.bindFilters = function () {
    // Filters bindings
    var that = this;
    if (!this.filters) {
      return;
    }

    $('.report-filters input[type="submit"]').bind('click', function (e) {
      e.preventDefault();
      that.applyFilters();
    });
  };

  HRReport.prototype.applyFilters = function () {
    var that = this;
    var formSerialize = $('.report-filters form:first').serializeArray();

    formSerialize.map(function (input) {
      input.value = that.formatDate(input.value, 'DD/MM/YYYY', 'YYYY-MM-DD');
    });

    formSerialize = $.param(formSerialize);

    if (that.jsonUrl) {
      that.refreshJson('?' + formSerialize);
    }
    if (that.tableUrl) {
      that.refreshTable('?' + formSerialize);
    }
  };

  /**
   * Format a date passing the old format and
   * the new date format
   *
   * @param  {String} date
   * @param  {String} oldFormat
   * @param  {String} newFormat
   * @return {String} formated date
   */
  HRReport.prototype.formatDate = function (date, oldFormat, newFormat) {
    var mDate = moment(date, oldFormat);

    if (mDate.isValid()) {
      date = mDate.format(newFormat);
    }

    return date;
  };

  /**
   * Gets Report configuration by currently selected configId
   * and apply it to the Pivot Table instance.
   */
  HRReport.prototype.configGet = function () {
    var that = this;
    var configId = this.getReportConfigurationId();
    if (!configId) {
      return false;
    }

    $.ajax({
      url: '/reports/' + that.reportName + '/configuration/' + configId,
      error: function () {
        swal('Failed', 'Error loading Report configuration!', 'error');
      },
      success: function (data) {
        if (data.status === 'success') {
          that.configApply(data.config);
        } else {
          swal('Failed', 'Error loading Report configuration!', 'error');
        }
      },
      type: 'GET'
    });
  };

  /**
   * Save Report configuration with currently selected configId.
   */
  HRReport.prototype.configSave = function (message) {
    var that = this;
    var configId = this.getReportConfigurationId();
    if (!configId) {
      swal('No configuration selected', 'Please choose configuration to update.', 'error');
      return false;
    }
    if (typeof message === 'undefined') {
      message = 'Are you sure you want to save this configuration changes?';
    }

    swal({
      title: 'Save Report configuration?',
      text: message,
      type: 'info',
      showCancelButton: true,
      confirmButtonColor: '#DD6B55',
      confirmButtonText: 'Yes',
      closeOnConfirm: false
    }, function () {
      that.configSaveProcess(configId);
    });
  };

  /**
   * Save new Report configuration basing on currently set configuration.
   */
  HRReport.prototype.configSaveNew = function (callback) {
    var that = this;

    swal({
      title: 'New Report configuration',
      text: 'Configuration name:',
      type: 'input',
      showCancelButton: true,
      closeOnConfirm: false,
      inputPlaceholder: ''
    }, function (inputValue) {
      if (inputValue === false) return false;
      if (inputValue === '') {
        swal.showInputError('Configuration name cannot be empty.');
        return false;
      }
      that.configSaveProcess(0, inputValue, callback);
    });
  };

  /**
   * Handle both Save and SaveNew actions server requests.
   *
   * @param {Integer} configId
   * @param {String} configName
   */
  HRReport.prototype.configSaveProcess = function (configId, configName, callback) {
    var that = this;
    var reportName = this.reportName;

    $.ajax({
      url: '/reports/' + reportName + '/configuration/' + configId + '/save',
      data: {
        label: configName,
        json_config: that.pivotConfig
      },
      error: function () {
        swal('Failed', 'Error saving Report configuration!', 'error');
      },
      success: function (data) {
        if (data.status === 'success') {
          // Update select with new option if we saved a new configuration:
          if (data['id']) {
            $('.report-config-select').append('<option value="' + data['id'] + '">' + data['label'] + '</option>');
            // Sort options by their labels alphabetically.
            $('.report-config-select').append($('.report-config-select option').remove().sort(function (a, b) {
              var aText = $(a).text();
              var bText = $(b).text();

              return (aText > bText) ? 1 : ((aText < bText) ? -1 : 0);
            }));
            $('.report-config-select').val(data['id']);
            callback && callback();
          }
          swal('Success', 'Report configuration has been saved', 'success');
        } else if (data.status === 'already_exists') {
          // If there is already a configuration with this label then we ask for overwriting it.
          $('.report-config-select').val(data['id']);
          that.configSave('Configuration with this name already exists. Do you want to modify it?');
        } else {
          swal('Failed', 'Error saving Report configuration!', 'error');
        }
      },
      method: 'POST'
    });
  };

  /**
   * Delete currently active configuration.
   */
  HRReport.prototype.configDelete = function (callback) {
    var configId = this.getReportConfigurationId();
    if (!configId) {
      swal('No configuration selected', 'Please choose configuration to delete.', 'error');
      return false;
    }
    var reportName = this.reportName;

    swal({
      title: 'Delete Report configuration?',
      text: 'Are you sure you want to delete this configuration?',
      type: 'info',
      showCancelButton: true,
      confirmButtonColor: '#DD6B55',
      confirmButtonText: 'Yes',
      closeOnConfirm: false
    }, function () {
      $.ajax({
        url: '/reports/' + reportName + '/configuration/' + configId + '/delete',
        error: function () {
          swal('Failed', 'Error deleting Report configuration!', 'error');
        },
        success: function (data) {
          if (data.status === 'success') {
            $('.report-config-select option[value=' + configId + ']').remove();
            swal('Success', 'Report configuration has been deleted', 'success');
            callback && callback();
          } else {
            swal('Failed', 'Error deleting Report configuration!', 'error');
          }
        },
        method: 'POST'
      });
    });
  };

  /**
   * Return an ID of currently active Report configuration.
   *
   * @returns {Integer}
   */
  HRReport.prototype.getReportConfigurationId = function () {
    return $('.report-config-select').val();
  };

  /**
   * Apply given Pivot Table configuration.
   *
   * @param {Object} config
   * @param {JSON} config
   */
  HRReport.prototype.configApply = function (config) {
    var that = this;
    config['onRefresh'] = function (config) {
      return that.pivotTableOnRefresh(config);
    };
    this.pivotTableContainer.pivotUI(this.data, config, true);
  };

  /**
   * Init angular in reports custom page,
   * and add the calendar icon
   *
   */
  HRReport.prototype.initAngular = function () {
    var hrReportInstance = this;

    require([
      'common/angular',
      'common/services/angular-date/date-format',
      'common/directives/angular-date/date-input',
      'common/moment',
      'common/filters/angular-date/format-date'
    ], function () {
      angular.module('civihrReports', [
        'ngAnimate',
        'ui.bootstrap',
        'common.angularDate'
      ])
      .run(['$compile', '$rootScope', function ($compile, $rootScope) {
        compileAngularElement = function (html) {
          var element = angular.element(html);
          var scope = $rootScope.$new();

          $compile(element)(scope);
          return element;
        };
      }])
      .directive('uibDatepickerPopupWrap', function sectionDirective () {
        return ({
          link: function (scope, element, attributes) {
            return $(element[0]).wrap('<span id="bootstrap-theme" />');
          }
        });
      })
      .constant('REPORT_NAME', hrReportInstance.reportName)
      .value('formFiltersStore', {
        initialized: false,
        values: {}
      })
      .controller('FiltersController', ['$q', 'REPORT_NAME', 'AbsencePeriod',
        'formFiltersStore', function ($q, REPORT_NAME, AbsencePeriod,
          formFiltersStore) {
          var vm = this;

          vm.dateFormat = 'dd/MM/yyyy';
          vm.filters = formFiltersStore.values;
          vm.loading = { dates: false };

          (function init () {
            vm.loading.dates = true;

            initFormFilterValues()
              .finally(function () {
                vm.loading.dates = false;
              });
          })();

          /**
           * If form filters have not been initialized, they'll get their default
           * values depending on the current report.
           *
           * @return {Promise} - Resolves to an empty promise after the form
           * filter values have been initialized.
           */
          function initFormFilterValues () {
            return $q(function (resolve, reject) {
              if (formFiltersStore.initialized) {
                return resolve();
              }

              if (REPORT_NAME === 'leave_and_absence') {
                formFiltersStore.values.fromDate = moment().startOf('month').toDate();
                formFiltersStore.values.toDate = moment().endOf('month').toDate();
                resolve();
              } else {
                formFiltersStore.values.date = new Date();
                resolve();
              }
            })
            .then(function () {
              formFiltersStore.initialized = true;
            });
          }
        }
      ])
      .service('AbsencePeriod', ['$q', function ($q) {
        return {
          /**
           * Returns the current absence period or null if there is none.
           *
           * @return {Promise} - resolves to the current absence period or NULL
           * in case there is none.
           */
          getCurrent: function () {
            var today = moment().format('YYYY-MM-DD');

            return $q(function (resolve, reject) {
              CRM.api3('AbsencePeriod', 'get', {
                'start_date': { '<=': today },
                'end_date': { '>=': today },
                'sequential': 1
              }).then(function (result) {
                resolve(result.values[0] || null);
              }, reject);
            });
          }
        };
      }]);

      angular.bootstrap($('#civihrReports')[0], ['civihrReports']);
    });
  };

  /**
   * Main Reports object instance
   */
  Drupal.behaviors.civihr_employee_portal_reports = {
    instance: null,
    /**
     * This method runs when the page is ready. The method is executed by Drupal.
     * More information:
     * https://www.drupal.org/docs/7/api/javascript-api/managing-javascript-in-drupal-7
     *
     * @param {Element} context - A reference to the document where the script is
     *   being executed.
     * @param {Object} settings - A map of configuration options shared between
     *   all behaviours.
     */
    attach: function (context, settings) {
      this.instance = new HRReport();
      this.bindReportConfigurationEvents();
      this.bindTabsEvents();
      this.switchToTabSpecifiedOnTheUrl();
      this.displayConfigurationOptionsIfConfigurationsHaveBeenSaved();
    },
    /**
     * Binds report configuration events for changing, saving, updating and
     * deleting them.
     */
    bindReportConfigurationEvents: function () {
      $('.report-config-select').bind('change', function (e) {
        this.instance.configGet();
      }.bind(this));
      $('.report-config-save-btn').bind('click', function (e) {
        this.instance.configSave();
      }.bind(this));
      $('.report-config-save-new-btn').bind('click', function (e) {
        this.instance.configSaveNew(function () {
          this.displayConfigurationOptionsIfConfigurationsHaveBeenSaved();
        }.bind(this));
      }.bind(this));
      $('.report-config-delete-btn').bind('click', function (e) {
        this.instance.configDelete(function () {
          this.displayConfigurationOptionsIfConfigurationsHaveBeenSaved();
        }.bind(this));
      }.bind(this));
    },
    /**
     * Bind tab switching events for the report tabs.
     */
    bindTabsEvents: function () {
      $('.report-tabs a').on('click', function (e) {
        $('.report-tabs li').removeClass('active');
        $(e.target).parent().addClass('active');
        $('.report-block').addClass('hidden');
        $('.report-block.' + $(e.target).data('tab')).removeClass('hidden');
        this.initScrollbarFallbackOnTabChange();
      }.bind(this));
    },
    /**
     * Displays the Report Configuration's save/update/delete options depending
     * on the availability of configurations. If no configurations are available
     * only the save option is available and the others are hidden.
     */
    displayConfigurationOptionsIfConfigurationsHaveBeenSaved: function () {
      var deleteOption = $('.report-config-delete-btn');
      var updateOption = $('.report-config-save-btn');
      var hasSavedConfigurations = $('.report-config-select option').length >= 2;

      if (hasSavedConfigurations) {
        deleteOption.fadeIn('fast');
        updateOption.fadeIn('fast');
      } else {
        deleteOption.fadeOut('fast');
        updateOption.fadeOut('fast');
      }
    },
    /**
     * initializes the scrollbar fallback
     *
     */
    initScrollbarFallbackOnTabChange: function () {
      var el = document.querySelector('.chr_custom-scrollbar');

      Ps.initialize(el);
    },
    /**
     * Automatically switches the current selected tab depending on the tab class
     * provided in the URL.
     */
    switchToTabSpecifiedOnTheUrl: function () {
      var tabSelector = '.report-tabs a';
      var hash = window.location.hash;

      tabSelector += hash ? '[data-tab="' + hash.substr(1) + '"]' : ':first';

      $(tabSelector).click();
    }
  };
})(jQuery);
