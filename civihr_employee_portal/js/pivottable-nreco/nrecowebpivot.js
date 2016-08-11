// 
// NReco Web Pivot Widget
// Author: Vitaliy Fedorchenko
// 
// Copyright (c) nrecosite.com - All Rights Reserved
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY 
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
(function () {
	var $;

	$ = jQuery;

	window.NRecoWebPivotEditor = function (storageApi, options) {
		this.storageApi = storageApi;
		this.options = $.extend(NRecoWebPivotEditor.defaults, options);
		var nrecoWebPivot = this;

		storageApi.loadDataSchema(function (schema) {
			nrecoWebPivot.dataSchema = schema;
			$(nrecoWebPivot.options.relexBuilderSelector).nrecoRelexBuilder($.extend({
				dataSchema: schema
			}, nrecoWebPivot.options.relexBuilderOptions));

			if (typeof nrecoWebPivot.options.onLoad == "function")
				nrecoWebPivot.options.onLoad();
		});

		initPivot(nrecoWebPivot, { data: [],columns:[] }, []);
	};

	window.NRecoWebPivotEditor.defaults = {
		relexBuilderSelector: null,
		pivotSelector: null,
		pivotOptions: {
		},
		relexBuilderOptions : {

		},
		onLoad : null
	};

	window.NRecoWebPivotEditor.prototype.load = function (loadedCallback) {
		var nrecoWebPivot = this;
		var state = this.getState();
		nrecoWebPivot.loadedState = state;

		this.storageApi.loadDataValues(state.relex, false, function (res) {
			setTimeout(function () { // get browser a chance to update UI
				initPivot(nrecoWebPivot, res, state.selected_columns);
			}, 10);
			if (typeof loadedCallback == "function")
				loadedCallback(res);
		});

	};

	window.NRecoWebPivotEditor.prototype.getState = function () {
		var state = {};
		state.relex_builder = $(this.options.relexBuilderSelector).nrecoRelexBuilder('getState');
		state.relex = $(this.options.relexBuilderSelector).nrecoRelexBuilder('buildRelex');
		state.selected_columns = $(this.options.relexBuilderSelector).nrecoRelexBuilder('getSelectedFields');

		var allPivotUIOpts = $(this.options.pivotSelector).data("pivotUIOptions");
		state.pivot_options = getPivotState(allPivotUIOpts);
		return state;
	};

	window.NRecoWebPivotEditor.prototype.setState = function (state) {
		var relexBuilder = $(this.options.relexBuilderSelector);
		if (state.relex_builder) {
			relexBuilder.nrecoRelexBuilder("setState", state.relex_builder);
			if (state.pivot_options) {
				this.options.pivotOptions = $.extend(true, this.options.pivotOptions, state.pivot_options);
			}
		} else {
			relexBuilder.nrecoRelexBuilder("setState", {class_id:""});
		}
	};

	var getPivotState = function (pivotOpts) {
		var props = ["aggregatorName","cols","vals","rendererName","rows"];
		var opts = {};
		for (var pIdx = 0; pIdx < props.length; pIdx++) {
			var p = props[pIdx];
			opts[p] = pivotOpts[p];
		}
		if (pivotOpts.rendererOptions && pivotOpts.rendererOptions.sort) {
			opts.rendererOptions = {
				sort: pivotOpts.rendererOptions.sort
			};
		}
		return opts;
	};

	var pivotDataLoader = function (res, selectedColumns) {
		var selectedColumnsByRelexResult = {};
		$.each(selectedColumns, function () {
			selectedColumnsByRelexResult[this.relex_result_name] = this;
		});
		
		this.loadHandler = function (callback) {
			var rIdx;
			for (var i = 0; i < res.data.length; i++) {
				var origR = res.data[i];
				var r = {};
				for (rIdx = 0; rIdx < res.columns.length; rIdx++) {
					var c = selectedColumnsByRelexResult[res.columns[rIdx]];
					var v = origR[rIdx];
					var caption = c.datatype == "date" || c.datatype == "datetime" ? "_" + c.caption : c.caption;
					r[caption] = v;
				}
				callback(r);
			}
		};
		var mthNames = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"];
		var quarterNames = ["Q1", "Q1", "Q1", "Q2", "Q2", "Q2", "Q3", "Q3", "Q3", "Q4", "Q4", "Q4"];		
		this.getDerivedAttributes = function () {
			var derivedAttrs = {};
			$.each(selectedColumns, function () {
				var c = this;
				if (c.datatype == "date" || c.datatype == "datetime") {
					var colCaption = "_" + c.caption;
					derivedAttrs[c.caption] = function (record) {
						var dt = record[colCaption];
						if (dt != null && typeof dt.getFullYear == "function") {
							var dayStr = dt.getDate().toString();
							return dt.getFullYear() + " " + mthNames[dt.getMonth()] + " " + (dayStr.length>1 ? dayStr : "0"+dayStr);
						}
						return "";
					};
					derivedAttrs[c.caption + " (Year)"] = function (record) {
						var dt = record[colCaption];
						if (dt != null && typeof dt.getFullYear == "function") {
							return dt.getFullYear();
						}
						return "";
					};
					derivedAttrs[c.caption + " (Month)"] = function (record) {
						var dt = record[colCaption];
						if (dt != null && typeof dt.getMonth == "function") {
							return mthNames[dt.getMonth()];
						}
						return "";
					};
					derivedAttrs[c.caption + " (Quarter)"] = function (record) {
						var dt = record[colCaption];
						if (dt != null && typeof dt.getMonth == "function") {
							return quarterNames[dt.getMonth()];
						}
						return "";
					};
				}
			});
			return derivedAttrs;
		};
		this.getSorters = function () {
			var monthAttrs = [];
			$.each(selectedColumns, function () {
				var c = this;
				if (c.datatype == "date" || c.datatype == "datetime") {
					monthAttrs.push(c.caption + " (Month)");
				}
			});
			return function (attr) {
				if (monthAttrs.indexOf(attr)>=0)
					return $.pivotUtilities.sortAs(mthNames);
			};
		};		
		this.getHiddenAttributes = function () {
			var hiddenAttrs = [];
			$.each(selectedColumns, function () {
				var c = this;
				if (c.datatype == "date" || c.datatype == "datetime") {
					hiddenAttrs.push("_" + c.caption);
				}
			});
			return hiddenAttrs;
		};
	};

	var initPivot = function (nrecoWebPivot, res, selectedColumns) {

		var loadPivotData = new pivotDataLoader(res, selectedColumns);
		var pvtOpts = $.extend({}, nrecoWebPivot.options.pivotOptions, {
			derivedAttributes: loadPivotData.getDerivedAttributes(),
			hiddenAttributes: loadPivotData.getHiddenAttributes(),
			sorters: loadPivotData.getSorters()
		});
		var origRefresh = pvtOpts.onRefresh;
		pvtOpts.onRefresh = function (pivotUIOptions) {
			if (res.data.length > 0) {
				var savedOpts = nrecoWebPivot.options.pivotOptions;
				savedOpts.aggregatorName = pivotUIOptions.aggregatorName;
				savedOpts.cols = pivotUIOptions.cols;
				savedOpts.vals = pivotUIOptions.vals;
				savedOpts.rendererName = pivotUIOptions.rendererName;
				savedOpts.rows = pivotUIOptions.rows;
				savedOpts.rendererOptions = pivotUIOptions.rendererOptions;
			}
			if (origRefresh)
				origRefresh(pivotUIOptions);
		};
		if (res.data.length == 0) {
			// workaround for strange derived props rendering
			pvtOpts.derivedAttributes = {};
		}
		$(nrecoWebPivot.options.pivotSelector).pivotUI(loadPivotData.loadHandler, pvtOpts, true);
	};

	window.NRecoWebPivotViewer = function (storageApi, options) {
		this.storageApi = storageApi;
		this.options = $.extend(NRecoWebPivotViewer.defaults, options);
		var nrecoWebPivot = this;

		if (typeof nrecoWebPivot.options.onLoad == "function")
			nrecoWebPivot.options.onLoad();
	};
	window.NRecoWebPivotViewer.defaults = {
		pivotSelector: "#pivotViewer",
		pivotOptions: {
		},
		onLoad: null
	};
	window.NRecoWebPivotViewer.prototype.load = function (pivotState, loadedCallback) {
		var nrecoWebPivot = this;

		this.storageApi.loadDataValues(pivotState.relex, false, function (res) {
			var loadPivotData = new pivotDataLoader(res, pivotState.selected_columns);
			var pvtOpts = $.extend(nrecoWebPivot.options.pivotOptions, {
				derivedAttributes: loadPivotData.getDerivedAttributes(),
				hiddenAttributes: loadPivotData.getHiddenAttributes(),
				sorters: loadPivotData.getSorters()
			}, pivotState.pivot_options);

			var renderers = pvtOpts.renderers ? $.pivotUtilities.renderers : pvtOpts.renderers;
			var renderer = renderers[pivotState.pivot_options.rendererName];
			if (renderer)
				pvtOpts.renderer = renderer;
			if (!pvtOpts.rendererOptions)
				pvtOpts.rendererOptions = {};

			$(nrecoWebPivot.options.pivotSelector).pivot(loadPivotData.loadHandler, pvtOpts);

			if (typeof loadedCallback == "function")
				loadedCallback(res);
		});

	};

}).call(this);