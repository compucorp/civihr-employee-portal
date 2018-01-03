/* global angular, Drupal, jQuery, moment, Ps, swal */

(function ($) {
  'use strict';
  var compileAngularElement;

  /**
   * Define HRReport object.
   */
  function HRReport () {
    this.initScrollbarFallback();
  }

  /**
   * Initialization function.
   *
   * @param {JSON} options - Settings for the object.
   */
  HRReport.prototype.init = function (options) {
    $.extend(this, options);
    this.processData(this.data);
    this.originalFilterElement = $('#report-filters').detach();
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
        '<div class="report-filters col-sm-3"></div>' +
        '<div class="report-function col-sm-2">' +
          '<div class="report-function-select"></div>' +
          '<div class="report-function-group"></div>' +
        '</div>' +
        '<div class="report-field-columns col-sm-7"><table><tr></tr></table></div>' +
      '</div>' +
      '<div class="row report-content-section">' +
        '<div class="report-fields-selection col-sm-3"><table><tr></tr></table></div>' +
        '<div class="report-field-rows col-sm-2"><table><tr></tr></table></div>' +
        '<div class="report-area col-sm-7"></div>' +
      '</div>' +
    '</div>';

    this.pivotTableContainer.append(html);
  };

  /**
   * Init PivotTable.js library
   */
  HRReport.prototype.initPivotTable = function () {
    var that = this;
    this.pivotTableContainer.pivotUI(this.data, {
      rendererName: 'Table',
      renderers: CRM.$.extend(
        jQuery.pivotUtilities.renderers,
        jQuery.pivotUtilities.c3_renderers,
        jQuery.pivotUtilities.export_renderers
      ),
      vals: ['Count'],
      rows: [],
      cols: [],
      aggregatorName: 'Count',
      unusedAttrsVertical: false,
      aggregators: that.getAggregators(),
      derivedAttributes: this.derivedAttributes,

      // It's necessary to make all the DOM changes here
      // because the library doesn't have support to custom template
      // https://github.com/nicolaskruchten/pivottable/issues/484
      onRefresh: function (config) {
        return that.pivotTableOnRefresh(config);
      }
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
   * Highlights droppable containers when report fields are dragged
   */
  HRReport.prototype.highlightDroppableContainersOnFieldsDrag = function () {
    var draggableItems = this.pivotTableContainer.find('.report-fields-selection .pvtAxisContainer');
    var droppableContainers = this.pivotTableContainer.find('.report-field-columns .pvtAxisContainer, .report-field-rows .pvtAxisContainer');
    var highlightClass = 'highlight';

    draggableItems.on('sortstart', function () {
      droppableContainers.addClass(highlightClass);
    });

    draggableItems.on('sortstop', function () {
      droppableContainers.removeClass(highlightClass);
    });
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
      this.highlightDroppableContainersOnFieldsDrag();
    }

    this.updateDropdown();
    this.updateFilterbox();
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
   * Init the scrollbar fallback
   *
   */
  HRReport.prototype.initScrollbarFallback = function () {
    var el = document.querySelector('.chr_custom-scrollbar');

    if (el) {
      Ps.initialize(el);
    }
  };

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
    CRM.$.ajax({
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
          renderers: CRM.$.extend(
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
    var tableDomId = this.getReportTableDomID();
    CRM.$.ajax({
      url: that.tableUrl + filterValues,
      error: function () {
        console.log('Error refreshing Report data table.');
      },
      success: function (data) {
        that.tableContainer.html(data);
        that.refreshReportTableViewInstance(tableDomId);
        that.initScrollbarFallback();
      },
      type: 'GET'
    });
  };

  /**
   * Return unique Drupal View's DOM ID of data table
   */
  HRReport.prototype.getReportTableDomID = function () {
    var reportTableDiv = CRM.$('#reportTable > div.view:first');
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
   * Bind filters UI events
   */
  HRReport.prototype.bindFilters = function () {
    // Filters bindings
    var that = this;
    if (!this.filters) {
      return;
    }

    CRM.$('.report-filters input[type="submit"]').bind('click', function (e) {
      e.preventDefault();
      that.applyFilters();
    });
  };

  HRReport.prototype.applyFilters = function () {
    var that = this;
    var formSerialize = CRM.$('.report-filters form:first').serializeArray();

    formSerialize.map(function (input) {
      input.value = that.formatDate(input.value, 'DD/MM/YYYY', 'YYYY-MM-DD');
    });

    formSerialize = CRM.$.param(formSerialize);

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

    CRM.$.ajax({
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
  HRReport.prototype.configSaveNew = function () {
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
      that.configSaveProcess(0, inputValue);
    });
  };

  /**
   * Handle both Save and SaveNew actions server requests.
   *
   * @param {Integer} configId
   * @param {String} configName
   */
  HRReport.prototype.configSaveProcess = function (configId, configName) {
    var that = this;
    var reportName = this.reportName;

    CRM.$.ajax({
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
            CRM.$('.report-config-select').append('<option value="' + data['id'] + '">' + data['label'] + '</option>');
            // Sort options by their labels alphabetically.
            CRM.$('.report-config-select').append(CRM.$('.report-config-select option').remove().sort(function (a, b) {
              var aText = $(a).text();
              var bText = $(b).text();

              return (aText > bText) ? 1 : ((aText < bText) ? -1 : 0);
            }));
            CRM.$('.report-config-select').val(data['id']);
          }
          swal('Success', 'Report configuration has been saved', 'success');
        } else if (data.status === 'already_exists') {
          // If there is already a configuration with this label then we ask for overwriting it.
          CRM.$('.report-config-select').val(data['id']);
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
  HRReport.prototype.configDelete = function () {
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
      CRM.$.ajax({
        url: '/reports/' + reportName + '/configuration/' + configId + '/delete',
        error: function () {
          swal('Failed', 'Error deleting Report configuration!', 'error');
        },
        success: function (data) {
          if (data.status === 'success') {
            CRM.$('.report-config-select option[value=' + configId + ']').remove();
            swal('Success', 'Report configuration has been deleted', 'success');
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
    return CRM.$('.report-config-select').val();
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
      .controller('FiltersController', function () {
        this.format = 'dd/MM/yyyy';
        this.placeholderFormat = 'dd/MM/yyyy';
        this.date = new Date();
        this.filtersCollapsed = true;
      })
      .controller('SettingsController', function () {
        this.isCollapsed = true;
      });

      angular.bootstrap($('#civihrReports')[0], ['civihrReports']);
    });
  };

  /**
   * Main Reports object instance
   */
  Drupal.behaviors.civihr_employee_portal_reports = {
    instance: null,
    attach: function (context, settings) {
      var that = this;
      this.instance = new HRReport();
      this.instance.initAngular();

      // Tabs bindings
      CRM.$('.report-tabs a').bind('click', function (e) {
        CRM.$('.report-tabs li').removeClass('active');
        CRM.$(this).parent().addClass('active');
        CRM.$('.report-block').addClass('hidden');
        CRM.$('.report-block.' + CRM.$(this).data('tab')).removeClass('hidden');
      });

      switchTabsOnLoad();

      // Reports configuration bindings
      CRM.$('.report-config-select').bind('change', function (e) {
        that.instance.configGet();
      });
      CRM.$('.report-config-save-btn').bind('click', function (e) {
        that.instance.configSave();
      });
      CRM.$('.report-config-save-new-btn').bind('click', function (e) {
        that.instance.configSaveNew();
      });
      CRM.$('.report-config-delete-btn').bind('click', function (e) {
        that.instance.configDelete();
      });

      /**
       * Switch to correct tab, on page load
       */
      function switchTabsOnLoad () {
        var tabSelector = '.report-tabs a';
        var hash = window.location.hash;

        hash ? tabSelector += '[data-tab="' + hash.substr(1) + '"]' : tabSelector += ':first';

        CRM.$(tabSelector).click();
      }
    }
  };
})(jQuery);
