// 
// NReco Relex Builder jQuery Plugin
// Author: Vitaliy Fedorchenko
// 
// Copyright (c) Vitaliy Fedorchenko (nrecosite.com) - All Rights Reserved
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY 
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
(function () {
	var $;

	$ = jQuery;

	function NRecoRelexBuilder(element,options) {
		this.element = element;
		this.options = options;
		var builder = this;

		this.init();
	}

	NRecoRelexBuilder.prototype.init = function () {
		var builder = this;
		initClassSelector(builder);
	};

	var digits = "0123456789";
	var datatypeToRelexType = {
		'string': 'string',
		'decimal': 'decimal',
		'datetime': 'datetime',
		'date': 'datetime',
		'boolean': 'boolean',
		'integer' : 'int64'
	};

	function buildRelexCondition(classInfo, conditionFields, conditionExpr, allFields) {
		var expr = conditionExpr.expression;
		var exprWithConditons = "";
		var currentConditionLexem = "";

		var getCurrentConditionStr = function () {
			var conditionIndex = parseInt(currentConditionLexem) - 1;
			if (conditionIndex < 0 || conditionIndex >= conditionFields.length)
				throw "Invalid condition index: " + conditionIndex;
			var f = conditionFields[conditionIndex];

			var fieldDescriptor = findByProperty(allFields, "name", f.field);
			var relexVal = f.value.replace(/["]/g, "\"\"");
			if (f.condition == "like" || f.condition == "!like")
				relexVal = "%" + relexVal + "%";
			var relexType = datatypeToRelexType[fieldDescriptor.__datatype];

			if ((f.value == null || $.trim(f.value) == "") && relexType != "string" && (f.condition=="=" || f.condition=="!=") ) {
				relexVal = "null"
			} else {
				relexVal = "\"" + relexVal + "\":" + relexType;
			}
			return f.field + f.condition +  relexVal;
		};

		for (var cIdx = 0; cIdx < expr.length; cIdx++) {
			var ch = expr.charAt(cIdx);
			if (digits.indexOf(ch) >= 0) {
				currentConditionLexem += ch;
			} else {
				if (currentConditionLexem != "") {
					exprWithConditons += getCurrentConditionStr();
					currentConditionLexem = "";
				}
				exprWithConditons += ch;
			}
		}
		if (currentConditionLexem != "") {
			exprWithConditons += getCurrentConditionStr();
		}
		return exprWithConditons;
	}

	NRecoRelexBuilder.prototype.getSelectedFields = function () {
		var selectedColumns = [];
		var selectedData = $(this.element).find(this.options.fieldBuilderHolder).find('input.columnSelector').select2('data');

		var currentClassId = $(this.element).find(this.options.classSelect).val();
		var allFields = this.getQueryBuilderFields(currentClassId);

		if (selectedData.length == 0) {
			var classInfo = this.options.dataSchema.findClassById(currentClassId);
			if (classInfo) {
				for (var pIdx = 0; pIdx < classInfo.properties.length; pIdx++) {
					var p = classInfo.properties[pIdx];
					selectedData.push({ id: p.id });
				}
			}
		}

		$.each(selectedData, function () {
			var fldDescriptor = findByProperty(allFields, "name", this.id);
			var f = {
				relex_field_name : this.id,
				relex_result_name: this.id.replace(/[.]/g,'_'),
				caption : fldDescriptor.caption,
				datatype : fldDescriptor.__datatype
			};
			selectedColumns.push(f);
		});

		return selectedColumns;
	};

	NRecoRelexBuilder.prototype.getState = function () {
		var state = {
			class_id: $(this.element).find(this.options.classSelect).val()
		};
		if (state.class_id) {
			var $conditionBuilder = $(this.element).find(this.options.conditionBuilderHolder).find('.nrecoConditionBuilderContainer');
			state.filter = {
				conditions: $conditionBuilder.data('getConditions')(),
				expression: $conditionBuilder.data('getExpression')()
			};
			state.fields = $.map(this.getSelectedFields(), function (v) { return v.relex_field_name });
		}
		return state;
	};

	NRecoRelexBuilder.prototype.setState = function (state) {
		if (state.class_id) {
			$(this.element).find(this.options.classSelect).val(state.class_id).change();
			if (state.filter) {
				var $conditionBuilder = $(this.element).find(this.options.conditionBuilderHolder).find('.nrecoConditionBuilderContainer');
				if ($conditionBuilder.length > 0) {
					if (state.filter.conditions) {
						$conditionBuilder.data('addConditions')(state.filter.conditions);
					}
					if (state.filter.expression) {
						$conditionBuilder.data('setExpression')(state.filter.expression.type, state.filter.expression.expression);
					}
				}
			}
			if (state.fields) {
				var $selectFields = $(this.element).find(this.options.fieldBuilderHolder).find('input.columnSelector');
				$selectFields.select2('val', state.fields, true);
			}
		} else {
			$(this.element).find(this.options.classSelect).val("").change();
		}
	};

	NRecoRelexBuilder.prototype.buildRelex = function (extraOptions) {
		var state = this.getState();
		var classId = state.class_id;
		var classInfo = this.options.dataSchema.findClassById(classId);
		if (!classInfo)
			return null;
		
		var conditionFields = state.filter.conditions;
		var conditionExpr = state.filter.expression;

		var selectedColumns = state.fields;
		if (extraOptions && extraOptions.fields) {
			for (var cIdx = 0; cIdx < extraOptions.fields.length; cIdx++)
				if ($.inArray(extraOptions.fields[cIdx], selectedColumns) < 0)
					selectedColumns.push(extraOptions.fields[cIdx]);
		}

		var allFieldDescriptors = this.getQueryBuilderFields(classId);
		var conditionStr = buildRelexCondition(classInfo, conditionFields, conditionExpr, allFieldDescriptors);

		var relex = classId;
		if (conditionStr && conditionStr != "")
			relex += "(" + conditionStr + ")";
		relex += "[";
		if (selectedColumns.length > 0) {
			relex += selectedColumns.join(',');
		} else {
			relex += "*";
		}
		if (extraOptions && extraOptions.sort) {
			relex += ";" + extraOptions.sort;
		}
		relex += "]";
		return relex;
	};

	var initClassSelector = function (builder) {
		var $tableSelect = $(builder.element).find(builder.options.classSelect);
		$tableSelect.html('');
		$tableSelect.append($('<option/>').val('').text('-- select table --'));

		$.each(builder.options.dataSchema.classes, function () {
			var classInfo = this;
			$tableSelect.append($('<option/>').val(classInfo.id).text(classInfo.name));
		});

		$tableSelect.change(function () {
			var classId = $(this).val();
			addConditionBuilder(builder, classId);
			addFieldBuilder(builder, classId);
		});
	};

	var addConditionBuilder = function (builder, classId) {
		var $conditionBuilderHolder = $(builder.element).find(builder.options.conditionBuilderHolder);
		var $conditionBuilderElem = $('<div/>');
		$conditionBuilderHolder.html('');

		if (classId && classId != '') {
			$conditionBuilderHolder.append($conditionBuilderElem);

			$conditionBuilderElem.nrecoConditionBuilder({
				fields: builder.getQueryBuilderFields(classId)
			});
			
			var applyBootstrap = function () {
				$conditionBuilderElem.find('.nrecoConditionBuilderFieldSelector select:not(.form-control)').select2({width:"off"});

				$conditionBuilderElem.find('input:not(.form-control),select:not(.form-control)').addClass('form-control input-sm');
				$conditionBuilderElem.find('.nrecoConditionBuilderConditionRow .rowContainer:not(.form-inline)').addClass('form-inline');
			};
			$conditionBuilderElem.on("change blur", 'input,select', function () {
				applyBootstrap();
			});
			applyBootstrap();
		}
	};

	var addFieldBuilder = function (builder, classId) {
		var $columnBuilderHolder = $(builder.element).find(builder.options.fieldBuilderHolder);
		$columnBuilderHolder.html('');

		if (classId && classId != '') {
			var $columnSelectorInput = $('<input class="columnSelector form-control" type="hidden"/>');
			$columnBuilderHolder.append($columnSelectorInput);

			var availableFields = builder.getQueryBuilderFields(classId);
			var selectData = [];
			for (var fIdx = 0; fIdx < availableFields.length; fIdx++) {
				var f = availableFields[fIdx];
				selectData.push({id:f.name, text:f.caption});
			}

			$columnSelectorInput.select2({
				minimumInputLength: 0,
				multiple: true,
				data: selectData,
				placeholder : "all class datatype properties"
			});

			$columnSelectorInput.select2("container").find("ul.select2-choices").sortable({
				containment: 'parent',
				start: function () { $columnSelectorInput.select2("onSortStart"); },
				update: function () { $columnSelectorInput.select2("onSortEnd"); }
			});
		}
	};

	function findByProperty(arr, prop, val) {
		var idx;
		for (idx = 0; idx < arr.length; idx++)
			if (arr[idx][prop] == val)
				return arr[idx];
		return null;
	}

	NRecoRelexBuilder.prototype.getQueryBuilderFields = function (classId, namePrefix, captionPrefix) {
		var fields = [];
		var classInfo = this.options.dataSchema.findClassById(classId);

		var composeFieldDescriptor = function (name, caption, datatype) {
			var field = {
				name: name,
				caption: caption,
				renderer: {
					name: 'textbox'
				},
				__datatype : datatype
			};
			if (datatype == 'integer' || datatype == 'decimal' || datatype == 'datetime' || datatype == 'date') {
				field.conditions = [
					{ text: '=', value: '=' },
					{ text: '<>', value: '!=' },
					{ text: '>', value: '>' },
					{ text: '>=', value: '>=' },
					{ text: '<', value: '<' },
					{ text: '<=', value: '<=' }
				];
				if (datatype == 'date' || datatype == 'datetime') {
					field.renderer.name = 'datepicker';
				}
			} else if (datatype == 'string') {
				field.conditions = [
					{ text: '=', value: '=' },
					{ text: '<>', value: '!=' },
					{ text: 'like', value: 'like' },
					{ text: 'not like', value: '!like' },
				];
			} else if (datatype == 'boolean') {
				field.conditions = [
					{ text: '=', value: '=' },
					{ text: '<>', value: '!=' }
				];
				field.renderer.name = 'dropdownlist';
				field.renderer.values = [
					{ text: 'Yes', value: 'true' },
					{ text: 'No', value: 'false' }
				];
			}
			return field;
		};

		var relexFields = this.options.dataSchema.getPossibleRelexFields(classId, 10);
		$.each(relexFields, function () {
			fields.push(
				composeFieldDescriptor(this.field, this.caption, this.datatype)
			);
		});

		return fields;
	};

	$.fn.nrecoRelexBuilder = function (options) {
		if (typeof options == "string") {
			var builderInstance = this.data('_nrecoRelexBuilder');
			if (builderInstance && (typeof builderInstance[options]) == "function") {
				return builderInstance[options].apply(builderInstance, Array.prototype.slice.call(arguments, 1));
			} else {
				$.error('Method ' + options + ' does not exist on jQuery.nrecoRelexBuilder');
			}
		}
		return this.each(function () {
			var opts = $.extend({}, $.fn.nrecoRelexBuilder.defaults, options);
			var $holder = $(this);

			if (!$.data(this, '_nrecoRelexBuilder')) {
				$.data(this, '_nrecoRelexBuilder', new NRecoRelexBuilder(this, opts));
			}

		});

	};

	$.fn.nrecoRelexBuilder.defaults = {
		dataSchema: null,
		state : null,
		conditionBuilderHolder: '.dataConditionBuilder',
		classSelect: '.dataSelect',
		fieldBuilderHolder : '.dataColumnBuilder'
	};


}).call(this);