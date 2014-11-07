(function($) {
Drupal.behaviors.civihr_employee_portal_filters = {
    attach: function (context, settings) {
        
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
            var allowed_values = ["Vacation", "Maternity", "TOIL"];
            
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