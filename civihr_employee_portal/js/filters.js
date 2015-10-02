(function($) {
Drupal.behaviors.civihr_employee_portal_filters = {
    attach: function (context, settings) {

        // Load only when the context is front page (we don't want to load this script in modal windows or when requesting leave)
        if (context == document) {

            /**
             *
             * @param {type} clicked_object
             * @param {type} type
             * Function for Quick approve / Quick reject the leave from the manager approval block
             */
            function civiUpdateActivity(clicked_object, type) {

                if (type == 'approve') {
                    var status_value = 2;
                    var status_type = 'Approved';
                    var status_message = 'The whole leave request has been Approved.';

                }
                if (type == 'reject') {
                    var status_value = 9;
                    var status_type = 'Rejected';
                    var status_message = 'The whole leave request has been Rejected.';
                }

                CRM.api3('Activity', 'get', {
                    "sequential": 1,
                    "source_record_id": clicked_object,
                }).done(function(result) {

                    for (index = 0; index < result.count; ++index) {

                        CRM.api3('Activity', 'setvalue', {
                            "sequential": 1,
                            "id": result.values[index].id,
                            "field": "status_id",
                            "value": status_value
                        }).done(function(result) {

                        });
                    }

                });

                CRM.api3('Activity', 'setvalue', {
                    "sequential": 1,
                    "id": clicked_object,
                    "field": "status_id",
                    "value": status_value
                }).done(function(result) {

                    if (result.is_error == 1) {
                        swal("Failed!", result.error_message, "error");
                    }
                    else {

                        // Update absence status on the screen
                        $("#act-id-" + clicked_object).html(status_type);

                        // Remove the row (so it will not be loaded when rebuilding the filters)
                        $("#act-id-" + clicked_object).closest('tr').remove();

                        // Rebuild filters
                        loadFilters();

                        console.log(Drupal.settings.basePath + 'ajax/quick_email_notify/' + clicked_object + '/' + type);

                        // Notify by email
                        $.ajax({
                            type: 'GET',
                            url: Drupal.settings.basePath + 'ajax/quick_email_notify/' + clicked_object + '/' + type,
                            success: function(data) {
                                console.log('Email sent');
                            },
                            error: function(data) {
                                console.log(data);
                                console.log('Email not sent!');
                            }
                        });

                        // Notify with popup
                        swal(status_type + "!", status_message, "success");
                    }
                });
            }

            /**
             * Load filters function
             */
            function loadFilters() {

                // Function to create a distinct list from array
                function distinctList(inputArray) {
                    var i;
                    var length = inputArray.length;
                    var outputArray = [];
                    var temp = {};

                    for (i = 0; i < length; i++) {
                        // Count the values based on their key
                        if (typeof temp[inputArray[i]] !== 'undefined') {
                            temp[inputArray[i]] = temp[inputArray[i]] + 1;
                        } else {
                            temp[inputArray[i]] = 1;
                        }
                    }

                    return temp;
                }

                //
                function filterTable(filter) {
                    var string = filter.match(/\S+/g);

                    if (string[0] === 'all') {
                        $(".manager-approval-main-table > tbody tr").fadeIn(10);
                    } else {
                        $(".manager-approval-main-table > tbody tr").fadeOut(10);
                        $(".manager-approval-main-table > tbody tr").each(function () {
                            var data_array = $(this).attr('data').split("@");
                            var index = string[0].replace(/-/g, " ");

                            // Filter
                            if ($.inArray(index, data_array) !== -1) {
                                $(this).fadeIn(10);
                            }
                        });
                    }
                }

                var $filtersNav = $("div.approval-filters").find('.chr_table-w-filters__filters__nav');
                var $filtersSelect = $("div.approval-filters").find('.chr_table-w-filters__filters__dropdown');

                // Reset the filters
                $filtersNav.html('').addClass('hide');
                $filtersSelect.html('').addClass('hide');

                // Create list of distinct items only
                var classList = distinctList($(".manager-approval-main-table > tbody tr").map(function () {
                    if ($(this).attr("data") !== undefined) {
                        return $(this).attr("data").split('@');
                    }
                }));

                if (Object.keys(classList).length !== 0) {
                    var excluded_values = ["approvals table", "Approved", "Rejected"]; // Check for the enabled absence types only
                    var included_values = ["Approved", "Rejected"]; // Check for the enabled approved / rejected only

                    var tagItems = '<li class="active"><a href >all&nbsp;<span class="badge badge-primary pull-right">' + classList['approvals-table'] + '</span></a></li>';
                    var tagOptions = '<option value="all">all (' + classList['approvals-table'] + ')</option>';

                    $.each(classList, function (index, value) {
                        var index = index.replace("-", " ");

                        if ($.inArray(index, excluded_values) == -1) {
                            tagItems += '<li><a href="#">' + index + '&nbsp;<span class="badge badge-primary pull-right">' + value + '</span></a></li>';
                            tagOptions += '<option value="' + index + '">' + index + ' (' + value + ')</option>';
                        }
                    });

                    $.each(classList, function (index, value) {
                        var index = index.replace("-", " ");

                        if ($.inArray(index, included_values) !== -1) {
                            tagItems += '<li><a href="#">' + index + '&nbsp;<span class="badge badge-primary pull-right">' + value + '</span></a></li>';
                            tagOptions += '<option value="' + index + '">' + index + ' (' + value + ')</option>';
                        }
                    });

                    // Add the filter links before the list of items
                    $filtersNav.append(tagItems).removeClass('hide');
                    $filtersSelect.append(tagOptions).removeClass('hide');
                }

                $filtersNav.on('click', 'a', function (e) {
                    // allows filter categories using multiple words
                    filterTable($(this).text().replace(/ /g, "-"));

                    // Add class "active" to current filter item
                    $('#tag-list li').removeClass('active');
                    $(this).parent().addClass('active');

                    // Prevent the page scrolling to the top of the screen
                    e.preventDefault();
                });

                $filtersSelect.on('change', function () {
                    filterTable($(this).val().replace(/ /g, "-"));
                })
            }

            $( ".manager-approval-main-table__actions__action--approve" ).click(function() {
                var action = $(this).attr('id');

                swal({
                    title: "Approve all leave",
                    text: "Are you sure you want to approve this leave?",
                    type: "info",
                    showCancelButton: true,
                    confirmButtonColor: "#DD6B55",
                    confirmButtonText: "Yes, approve all!",
                    closeOnConfirm: false,
                }, function() {
                    civiUpdateActivity(action, 'approve');
                });
            });

            $( ".manager-approval-main-table__actions__action--deny" ).click(function() {
                var action = $(this).attr('id');

                swal({
                    title: "Reject all leave",
                    text: "Are you sure you want to reject this leave?",
                    type: "info",
                    showCancelButton: true,
                    confirmButtonColor: "#DD6B55",
                    confirmButtonText: "Yes, reject all!",
                    closeOnConfirm: false
                }, function(){
                    civiUpdateActivity(action, 'reject');
                });
            });

            if ($('table').hasClass('manager-approval-main-table') && $('div').hasClass('ctools-modal-dialog') == false) {
                // Header table sorter
                $(".manager-approval-main-table").tablesorter();
            }
        }

        var ApprovalFilter = function () {

            var $table = $("table.manager-approval-main-table");

        };

        ApprovalFilter.prototype.removeHighlighting = function(highlightedElements) {
            highlightedElements.each(function(){
                var element = $(this);

                element.replaceWith(element.html());
            })
        };

        ApprovalFilter.prototype.addHighlighting = function(element, textToHighlight) {
            var text = element.text();
            var highlightedText = '<em>' + textToHighlight + '</em>';
            var newText = text.replace(textToHighlight, highlightedText);

            element.html(newText);
        };

        // Init the approval highlight search
        var approvalsearch = new ApprovalFilter();

        if (context == document) {

            if ($('table').hasClass('manager-approval-main-table') && $('div').hasClass('ctools-modal-dialog') == false) {
                // Set the the cookie for the actual available browser width size
                $.cookie('browser_width', $(window).width());
                console.log('size');
                $(window).resize(function() {
                    // Set the the cookie for the actual available browser width size
                    $.cookie('browser_width', $(window).width());
                    console.log('re-size');
                });
            }
        }

        $("#manager-approval-search").on("keyup", function() {
            var value = $(this).val();

            approvalsearch.removeHighlighting($(".manager-approval-main-table > tbody tr em"));

            $(".manager-approval-main-table > tbody tr").each(function(index) {
                $row = $(this);

                // Find the Contact name element
                var $tdElement = $row.find(".views-field-civi-target-contact-name");

                var id = $tdElement.text().trim();
                var matchedIndex = id.indexOf(value);

                if (matchedIndex != 0) {
                    $row.hide();
                }
                else {
                    approvalsearch.addHighlighting($tdElement, value);
                    $row.show();
                }
            });
        });

        if ($('div').hasClass('approval-filters') && $('div').hasClass('ctools-modal-dialog') == false && context == document) {

            // Init the filters
            loadFilters();

        }

    }
}
})(jQuery);
