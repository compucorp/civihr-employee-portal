(function($) {
Drupal.behaviors.civihr_employee_portal_filters = {
    attach: function (context, settings) {
        
        // Load only when the context is front page (we don't want to load this script in modal windows or when requesting leave)
        if (context == document) {
        
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
        
        // Set the the cookie for the actual available browser width size
        $.cookie('browser_width', $(window).width());
        console.log('size');
        $(window).resize(function() {
            // Set the the cookie for the actual available browser width size
            $.cookie('browser_width', $(window).width());
            console.log('re-size');
        });
        
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
        
        if ($('div').hasClass('approval-filters') && $('div').hasClass('ctools-modal-dialog') == false) {
            
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
                    }
                    else {
                        temp[inputArray[i]] = 1;
                    }
                    
                }
                
                return temp;
            }
            
             // Map the classes for each item into a new array
             classes = $(".manager-approval-main-table > tbody tr").map(function() {
                return $(this).attr("class").split(' ');
            });

            // Create list of distinct items only
            var classList = distinctList(classes);
            
            // Generate the list of filter links
            var tagList = '<ul id="tag-list" class="list-group"></ul>';
            
            // All filter
            tagItem = '<button class="btn btn-custom" type="button" class="active">all&nbsp;<span class="badge">' + classList['approvals-table'] + '</span></button>';

            // Check for the enabled absence types only
            var allowed_values = ["Vacation", "Maternity", "TOIL", "Approved", "Rejected", "Cancelled", "Awaiting approval"];
            
            // Loop through the list of classes & add link
            $.each(classList, function(index, value) {
                
                var index = index.replace("-", " ");
                if(jQuery.inArray(index, allowed_values)!==-1) {
                    tagItem += '<button class="btn btn-custom" type="button">' + index + '&nbsp;<span class="badge">' + value + '</span></button>';
                }
            });

            // Add the filter links before the list of items
            $( "div.approval-filters" ).html($(tagList).append(tagItem));

            $('#tag-list button').click(function(e) {

                // allows filter categories using multiple words
                var getText = $(this).text().replace(" ", "-");
                
                // Get the value name from the string (it includes the count value, so this removes it) -> similar to php explode function
                var string = getText.match(/\S+/g);
                
                if(string[0] == 'all'){
                    $(".manager-approval-main-table > tbody tr").fadeIn(10);
                } else {
                    $(".manager-approval-main-table > tbody tr").fadeOut(10);
                    $(".manager-approval-main-table > tbody tr." + string[0]).fadeIn(10);
                }

                // Add class "active" to current filter item
                $('#tag-list button').removeClass('active');
                $(this).addClass('active');

                // Prevent the page scrolling to the top of the screen
                e.preventDefault();
            });

        }
        
    }
}
})(jQuery);