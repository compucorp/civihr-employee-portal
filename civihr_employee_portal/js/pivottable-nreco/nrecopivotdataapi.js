// 
// NReco WebPivot Data javascript API
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

	var findClassById = function (classId) {
		var classInfo = findByProperty(this.classes, 'id', classId);
		return classInfo;
	};
	var findPropertyById = function (propId) {
		return findByProperty(this.properties, 'id', propId);
	};

	var getPossibleRelexFields = function (schema, classId) {
		var fields = [];
		var classInfo = schema.findClassById(classId);
		for (var pIdx = 0; pIdx < classInfo.properties.length; pIdx++) {
			var p = classInfo.properties[pIdx];
			fields.push({
				field : p.id,
				caption: p.name,
				property_id : p.id,
				datatype : p.datatype,
				class_id : classId
			});
		}
		return fields;
	};

	window.NRecoPivotDataApi = function (options) {
		this.options = options = $.extend(window.NRecoPivotDataApi.defaults, options);
		var schema = options.dataschema;
		schema.findClassById = findClassById;
		schema.getPossibleRelexFields = function (classId, maxLevel) {
			return getPossibleRelexFields(this, classId);
		};
		for (var i = 0; i < schema.classes.length; i++) {
			schema.classes[i].findPropertyById = findPropertyById;
		}
	}
	window.NRecoPivotDataApi.defaults = {
		loadValuesUrl: null,
		ajaxOptions : null,
		downloadProgressHandler: null,
		dataschema: {}
	};

	window.NRecoPivotDataApi.prototype.loadDataSchema = function (callback) {
		var o = this.options;
		callback(o.dataschema);
	};

	var apiCall = function (httpMethod, apiMethodName, data, callback) {
		var ajaxOpts = $.extend( {
			type: httpMethod,
			data: data,
			contentType: "application/json"
		}, this.options.ajaxOptions);
		if (typeof this.options.downloadProgressHandler == "function") {
			var downloadHandler = this.options.downloadProgressHandler;
			ajaxOpts.xhr = function () {
				var xhr = new window.XMLHttpRequest();
				xhr.addEventListener("progress", function (evt) {
					var progressLen = xhr.getResponseHeader("Progress-Content-Length");
					if (evt.lengthComputable) {
						var percentComplete = evt.loaded / evt.total;
						downloadHandler(percentComplete * 100);
					} else if (progressLen) {
						var percentComplete = evt.loaded / parseInt(progressLen);
						downloadHandler(percentComplete * 100);
					}
				}, false);
				
				return xhr;
			};
		}
		$.ajax(apiMethodName, ajaxOpts).success(callback);
	};

	window.NRecoPivotDataApi.prototype.loadDataValues = function (relex, totalcount, callback) {
		apiCall.call(this, "GET", this.options.loadValuesUrl,
			{
				q: relex,
				totalcount: totalcount ? true : false
			},
			function (res) {
				for (var rIdx = 0; rIdx < res.data.length; rIdx++)
					normalizeValues(res.data[rIdx]);
				callback(res);
			}
		);
	};

	window.NRecoPivotDataApi.prototype.loadDataValuesAsRows = function (relex, totalcount, callback) {
		this.loadDataValues(relex, totalcount, function (res) {
			var rows = [];
			for (var rIdx = 0; rIdx < res.data.length; rIdx++) {
				var v = res.data[rIdx];
				var r = {};
				for (var cIdx = 0; cIdx < res.columns.length; cIdx++)
					r[res.columns[cIdx]] = v.length > cIdx ? v[cIdx] : null;
				rows.push(r);
			}
			callback({
				totalcount: res.totalcount,
				data : rows
			});
		});
	}

	function normalizeValues(values) {
		for (var vIdx=0; vIdx<values.length; vIdx++) {
			var v = values[vIdx];
			if (v && v.length > 0 && v.charAt(0) == '\/') {
				values[vIdx] = new Date(parseInt(v.substr(6)));
			}
		}
	}

	function findByProperty(arr, prop, val) {
		var idx;
		for (idx = 0; idx < arr.length; idx++)
			if (arr[idx][prop] == val)
				return arr[idx];
		return null;
	}


}).call(this);