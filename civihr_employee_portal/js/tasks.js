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
                    json: '{"sort_name":"' + params + '", "relationship_name": "Line Manager is", "related_contact_id": ' + Drupal.settings.currentCiviCRMUserId + ', "include_related_contact": true}',
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
                allowClear: true,
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
                allowClear: true,
                placeholder: "Search for target",
                minimumInputLength: 1,
                multiple: false,
                ajax: Drupal.behaviors.civihr_employee_portal_tasks.contactAjax,
                escapeMarkup: function (markup) {
                    return markup;
                }
            }).on("change", function(e) {
                var assignmentSelectOptions = [];
                CRM.api3('Task', 'getcontact', {
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
                allowClear: true,
                placeholder: "Search for workflow",
                data: assignmentsSelectOptions
            });
            CRM.$('#edit-assignment').select2("data", defaultValue);
            CRM.$('.btn.assignment-remove').click( function() {
                CRM.$('#edit-assignment').select2('data', null);
            });
        },
        initTasksFilters: function () {
          var $navTaskFilter = $('#nav-tasks-filter'),
            $dropdownFilter = $('#select-tasks-filter'),
            $tableTaskStaff = $('#tasks-dashboard-table-staff'),
            $tableTaskStaffRows = $tableTaskStaff.find('.task-row');

          var $selectedRowFilter =  $tableTaskStaff.find('.task-row'),
            $selectedRowType = $tableTaskStaff.find('.task-row'),
            selectedRowFilterSelector = null;

          var chk = CRM.$('.checkbox-task-completed');

          $navTaskFilter.find('a').bind('click', function (e) {
            e.preventDefault();

            var $this = $(this),
              taskFilter = $this.data('taskFilter');

            $navTaskFilter.find('> li').removeClass('active');
            $this.parent().addClass('active');

            if (taskFilter === 'all') {
              $selectedRowFilter = $tableTaskStaff.find('.task-row');
              selectedRowFilterSelector = '.task-row';
            } else {
              $selectedRowFilter = $tableTaskStaff.find('.task-filter-id-' + taskFilter);
              selectedRowFilterSelector = '.task-filter-id-' + taskFilter;
            }

            showFilteredTaskRows();
          });

          $dropdownFilter.on('change', function (e) {
            var taskFilter = $(this).val();

            if (taskFilter === 'all') {
              $selectedRowFilter = $tableTaskStaff.find('.task-row');
              selectedRowFilterSelector = '.task-row';
            } else {
              $selectedRowFilter = $tableTaskStaff.find('.task-filter-id-' + taskFilter);
              selectedRowFilterSelector = '.task-filter-id-' + taskFilter;
            }

            showFilteredTaskRows();
          });

          chk.unbind('change').bind('change', function(e) {
            var checkedTaskId = $(this).val();

            $.ajax({
              url: '/civi_tasks/ajax/complete/' + checkedTaskId,
              success: function (result) {
                if (!result.success) {
                  CRM.alert(result.message, 'Error', 'error');
                  return;
                }

                $('#row-task-id-' + checkedTaskId).fadeOut(500, function () {
                  $(this).remove();
                  refreshTasksCounter();
                });
              }
            });
          });

          buildTaskContactFilter();

          function showFilteredTaskRows() {
            $tableTaskStaffRows
              .hide()
              .removeClass('selected-by-type')
              .removeClass('selected-by-filter');

            $selectedRowType.addClass('selected-by-type');
            $selectedRowFilter.addClass('selected-by-filter');

            $('.selected-by-type.selected-by-filter.selected-by-contact', $tableTaskStaff).show();
          }

          function refreshTasksCounter() {
            var sum = 0;

            $navTaskFilter
              .find('[data-task-filter]')
              .not('[data-task-filter="all"]')
              .each(function (i, filter) {
                var $filter = $(filter),
                  type = $filter.data('taskFilter'),
                  count = $('.task-filter-id-' + type, $tableTaskStaff).length;

                sum += count;

                $filter.find('.task-counter-filter').text(count);
              });

            $navTaskFilter
              .find('[data-task-filter="all"]')
              .find('.task-counter-filter').text(sum);

            document.dispatchEvent(new Event('TasksBadge:: Update Count'));
          }

          function buildTaskContactFilter() {
            $tableTaskStaffRows.addClass('selected-by-contact');

            $('#task-filter-contact').on("keyup", function () {
              var value = $(this).val().toLowerCase();

              $tableTaskStaffRows.removeClass('selected-by-contact');

              $("#tasks-dashboard-table-staff > tbody > tr.task-row").each(function (index) {
                var $row = $(this);
                var text = $row.data('rowContacts') || '';
                var matchedIndex = text.toLowerCase().indexOf(value);

                if (value.length === 0 || matchedIndex !== -1) {
                  $row.addClass('selected-by-contact');
                } else {
                  $row.removeClass('selected-by-contact');
                }
              });

              showFilteredTaskRows();
            });
          }
        }
    }
})(jQuery);
