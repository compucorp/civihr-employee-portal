(function($) {
  'use strict';

  /**
   * Define HRReport object.
   */
  function HRReport() {
    var data = [];
    var pivotTableContainer = jQuery("#reportPivotTable");
    var derivedAttributes = {};

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
  };

  /**
   * Init PivotTable.js library
   */
  HRReport.prototype.initPivotTable = function() {
    var that = this;
    this.pivotTableContainer.pivotUI(this.data, {
      rendererName: "Table",
      renderers: CRM.$.extend(
        jQuery.pivotUtilities.renderers,
        jQuery.pivotUtilities.c3_renderers,
        jQuery.pivotUtilities.export_renderers
      ),
      vals: ["Total"],
      rows: ["Employee gender"],
      cols: ["Contract Normal Place of Work"],
      aggregatorName: "Count",
      unusedAttrsVertical: false,
      aggregators: that.getAggregators(),
      derivedAttributes: this.derivedAttributes,

      // It's necessary to make all the DOM changes here
      // because the library doesn't have support to custom template
      // https://github.com/nicolaskruchten/pivottable/issues/484
      onRefresh: function () {
        Drupal.behaviors.civihr_employee_portal_reports.instance.updateCustomTemplate();
      }
    }, false);
  }

  /**
   * Return an object containing set of Pivot Table aggregators extended with
   * our custom ones.
   *
   * @returns {jQuery.pivotUtilities.aggregators|_$.pivotUtilities.aggregators|aggregators}
   */
  HRReport.prototype.getAggregators = function() {
    var aggregators = $.pivotUtilities.aggregators;
    var ordered = {};

    // Create custom Aggregator behaving like 'Count Unique Values' but
    // not counting NULL, 0 or empty strings.
    aggregators["Count Unique Values excluding null, 0 or empty"] = function(attributeArray) {
      var attribute = attributeArray[0];
      return function(data, rowKey, colKey) {
        return {
          uniq: [],
          push: function(record) {
            var _ref = record[attribute];
            if (!!+_ref && this.uniq.indexOf(_ref) < 0) {
              this.uniq.push(record[attribute]);
            }
          },
          value: function() { return this.uniq.length; },
          format: function(x) { return x; },
          numInputs: 1
        };
      };
    };
    aggregators["Sum field 1 by unique values of field 2"] = function(attributeArray) {
      var attribute1 = attributeArray[0];
      var attribute2 = attributeArray[1];
      return function(data, rowKey, colKey) {
        return {
          sum: 0,
          byFieldValues: [],
          push: function(record) {
            if (!isNaN(parseFloat(record[attribute1]))) {
              if (record[attribute2] in this.byFieldValues) {
                return this.sum;
              }
              this.byFieldValues[record[attribute2]] = 1;
              return this.sum += parseFloat(record[attribute1]);
            }
          },
          value: function() {
            return this.sum;
          },
          format: function(x) { return x.toFixed(2); },
          numInputs: attribute1 != null ? 0 : 2
        };
      };
    };

    // Sort aggregators by keys.
    Object.keys(aggregators).sort().forEach(function(key) {
      ordered[key] = aggregators[key];
    });
    return ordered;
  }

  /**
   * Do additional required operations on data returned from backend.
   *
   * @param array data
   * @returns array
   */
  HRReport.prototype.processData = function(data) {
    // Set 'null' for all empty values.
    for (var i in data) {
      for (var j in data[i]) {
        if (data[i][j] === "") {
          data[i][j] = "null";
        }
      }
    }
    return data;
  }

  /**
   * Update the pivot table dropdown and filter box
   *
   */
  HRReport.prototype.updateCustomTemplate = function() {
    this.updateDropdown();
    this.updateFilterbox();
  };

  /**
   * Update the pivot table dropdown to look like CiviHR style
   *
   */
  HRReport.prototype.updateDropdown = function() {
    $('.pvtUi select').each(function () {
      var selectClass = 'chr_custom-select chr_custom-select--full';

      if (!$(this).parent().hasClass('chr_custom-select')) {
        if ($(this).hasClass('pvtAggregator')) {
          selectClass += ' chr_custom-select--transparent';
        }

        $(this).wrap('<div class="' + selectClass + '"></div>');
      }
    });

    $('.pvtVals .chr_custom-select').each(function () {
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
  HRReport.prototype.updateFilterbox = function() {
    $('.pvtFilterBox').each(function () {
      $(this).find('.pvtSearch').removeClass('pvtSearch').addClass('form-text');
      $(this).find('button').addClass('btn btn-primary btn-default btn-block');

      if ($(this).find('.pvtFilterSelectAllWrap').length === 0) {
        var filters = $(this).find(".pvtFilter");

        $(this).find('.pvtFilterSelectAllWrap').remove();
        $(this).find('.pvtCheckContainer').prepend(`<p class="pvtFilterSelectAllWrap"><label><input type="checkbox" class="pvtFilterSelectAll" checked="checked"><span>Select All</span></label></p>`);

        $(this).find('.pvtFilterSelectAll').on('click', function () {
          filters.prop("checked", $(this).is(':checked'));
        });

        $(this).find('.pvtCheckContainer p').addClass('chr_custom-checkbox');
      }
    });
  };

  /**
   * Shows the Report
   */
  HRReport.prototype.show = function () {
    this.initPivotTable();
    this.bindFilters();
  };

  /**
   * Init the scrollbar fallback
   *
   */
  HRReport.prototype.initScrollbarFallback = function() {
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
  HRReport.prototype.refreshJson = function(filterValues) {
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
        that.pivotTableContainer.pivotUI(data, {
          rendererName: "Table",
          renderers: CRM.$.extend(
            jQuery.pivotUtilities.renderers,
            jQuery.pivotUtilities.c3_renderers
          ),
          unusedAttrsVertical: false
        }, false);
      },
      type: 'GET'
    });
  }

  /**
   * Refresh data table using provided filter values
   *
   * @param string filterValues
   */
  HRReport.prototype.refreshTable = function(filterValues) {
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
  }

  /**
   * Return unique Drupal View's DOM ID of data table
   */
  HRReport.prototype.getReportTableDomID = function() {
    var reportTableDiv = CRM.$('#reportTable > div.view:first');
    var reportTableClasses = reportTableDiv.attr('class').split(' ');
    for (var i in reportTableClasses) {
      if (reportTableClasses[i].substring(0, 12) === 'view-dom-id-') {
        return reportTableClasses[i].substr(12);
      }
    }
    return null;
  }

  /**
   * Reinitialize View instance of data table for given View's DOM ID
   *
   * @param string viewReportDataTableId
   */
  HRReport.prototype.refreshReportTableViewInstance = function(viewReportDataTableId) {
    var viewReportDataTableSettings = Drupal.settings.views.ajaxViews['views_dom_id:' + viewReportDataTableId];
    var viewReportDataTableNewId = this.getReportTableDomID();

    delete Drupal.settings.views.ajaxViews['views_dom_id:' + viewReportDataTableId];
    delete Drupal.views.instances['views_dom_id:' + viewReportDataTableId];

    viewReportDataTableSettings.view_dom_id = viewReportDataTableNewId;
    Drupal.settings.views.ajaxViews['views_dom_id:' + viewReportDataTableNewId] = viewReportDataTableSettings;
    Drupal.views.instances['views_dom_id:' + viewReportDataTableNewId] = new Drupal.views.ajaxView(Drupal.settings.views.ajaxViews['views_dom_id:' + viewReportDataTableNewId]);
  }

  /**
   * Bind filters UI events
   */
  HRReport.prototype.bindFilters = function() {
    // Filters bindings
    var that = this;
    if (!this.filters) {
      return;
    }

    CRM.$('#report-filters input[type="submit"]').bind('click', function(e) {
      e.preventDefault();
      var formSerialize = CRM.$('#report-filters form:first').serializeArray();

      formSerialize.map(function(input) {
        input.value = that.formatDate(input.value, 'DD/MM/YYYY', 'YYYY-MM-DD');
      });

      formSerialize = CRM.$.param(formSerialize);

      if (that.jsonUrl) {
        that.refreshJson('?' + formSerialize);
      }
      if (that.tableUrl) {
        that.refreshTable('?' + formSerialize);
      }
    });
  }

  /**
   * Format a date passing the old format and
   * the new date format
   *
   * @param  {String} date
   * @param  {String} oldFormat
   * @param  {String} newFormat
   * @return {String} formated date
   */
  HRReport.prototype.formatDate = function(date, oldFormat, newFormat) {
    var mDate = moment(date, oldFormat);

    if (mDate.isValid()) {
      date = mDate.format(newFormat);
    }

    return date;
  };

  /**
   * Init angular in reports custom page,
   * and add the calendar icon
   *
   */
  HRReport.prototype.initAngular = function() {
    require([
      'common/angular',
      'common/services/angular-date/date-format',
      'common/directives/angular-date/date-input',
      'common/moment',
      'common/filters/angular-date/format-date'
    ], function() {
      angular.module('civihrReports', [
        'ngAnimate',
        'ui.bootstrap',
        'common.angularDate'
      ])
      .directive('uibDatepickerPopupWrap', function sectionDirective() {
        return({
          link: function(scope, element, attributes) {
            return $(element[0]).wrap('<span id="bootstrap-theme" />');
          }
        });
      })
      .controller('FiltersController', function() {
        this.format = 'dd/MM/yyyy';
        this.placeholderFormat = 'dd/MM/yyyy';
        this.filtersCollapsed = true;
      })
      .controller('SettingsController', function() {
        this.isCollapsed = true;
      });

      angular.bootstrap(document.getElementById('civihrReports'), ['civihrReports']);
    });
  };

  /**
   * Main Reports object instance
   */
  Drupal.behaviors.civihr_employee_portal_reports = {
    instance: null,
    attach: function (context, settings) {
      this.instance = new HRReport();

      this.instance.initAngular();

      // Tabs bindings
      CRM.$('.report-tabs a').bind('click', function(e) {
        e.preventDefault();
        CRM.$('.report-tabs li').removeClass('active');
        CRM.$(this).parent().addClass('active');
        CRM.$('.report-block').addClass('hidden');
        CRM.$('.report-block.' + CRM.$(this).data('tab')).removeClass('hidden');
      });
      CRM.$('.report-tabs a:first').click();
    }
  }
})(jQuery);
