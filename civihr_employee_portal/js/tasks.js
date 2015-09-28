(function ($) {
    Drupal.behaviors.civihr_employee_portal_tasks = {
        attach: function (context, settings) {
            //$(function() {
            //});
        },
        contactAjax: {
            url: '/index.php?q=civicrm/ajax/rest&entity=task&action=getcontactlist&format=json',
            dataType: 'json',
            type: 'POST',
            delay: 250,
            data: function (params) {
                return {
                    json: '{"sort_name":"' + params + '"}',
                    page: 1
                };
            },
            processResults: function (data, page) {
                return {
                    results: data.items
                };
            },
            results: function (data, page) {
                var mapped = CRM.$.map(data.values, function (item) {
                    return {id: item.id, text: item.sort_name};
                });
                return {
                    results: mapped,
                    more: false
                };
            }
        },
        buildAssigneeSelect: function (defaultValue) {
            CRM.$('#edit-assignee').select2({
                placeholder: "Search for assignee",
                minimumInputLength: 1,
                multiple: false,
                ajax: Drupal.behaviors.civihr_employee_portal_tasks.contactAjax,
                escapeMarkup: function (markup) {
                    return markup;
                }
            });
            CRM.$('#edit-assignee').select2("data", defaultValue);
            CRM.$('.btn.assignee-remove').click( function() {
                CRM.$('#edit-assignee').select2('data', null);
            });
        },
        buildTargetSelect: function (defaultValue) {
            CRM.$('#edit-target').select2({
                placeholder: "Search for target",
                minimumInputLength: 1,
                multiple: false,
                ajax: Drupal.behaviors.civihr_employee_portal_tasks.contactAjax,
                escapeMarkup: function (markup) {
                    return markup;
                }
            }).on("change", function(e) {
                var assignmentSelectOptions = [];
                CRM.api3('Contact', 'get', {
                    "sequential": 1,
                    "id": e.val
                }).done(function(result) {
                    var sort_name = result.values[0].sort_name;
                    CRM.api3('Assignment', 'get', {
                        "sequential": 1,
                        "contact_id": e.val
                    }).done(function(result) {
                        for (var i in result.values) {
                            assignmentSelectOptions.push({
                                'id': result.values[i].id,
                                'text': sort_name + ' - ' + result.values[i].subject
                            });
                        }
                        Drupal.behaviors.civihr_employee_portal_tasks.buildAssignmentsSelect(assignmentSelectOptions);
                    });
                });
            });
            CRM.$('#edit-target').select2("data", defaultValue);
            CRM.$('.btn.target-remove').click( function() {
                CRM.$('#edit-target').select2('data', null);
            });
        },
        buildAssignmentsSelect: function (assignmentsSelectOptions, defaultValue) {
            CRM.$('#edit-assignment').select2({
                placeholder: "Search for assignment",
                data: assignmentsSelectOptions
            });
            CRM.$('#edit-assignment').select2("data", defaultValue);
            CRM.$('.btn.assignment-remove').click( function() {
                CRM.$('#edit-assignment').select2('data', null);
            });
        }
    }
})(jQuery);