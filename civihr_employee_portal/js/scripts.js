(function($) {
Drupal.behaviors.civihr_employee_portal = {
    attach: function (context, settings) {

        // Hide if not needed
        $('.form-item-manager-notes').hide();

        // This is the reject all modal form submit button
        $('#edit-reject-all').hide();

        // Show manager notes form when any action button is clicked in the manager approval modal windows
        $('#manager-reject-all').click(function() {

            // Show the manager notes edit field
            $('.form-item-manager-notes').show();

            // Hide the reject jquery action button
            $('#manager-reject-all').hide();

            // Show the real Reject All form button
            $('#edit-reject-all').show();

        });
        
        $("#edit-absence-request-date-from-datepicker-popup-0", context).change(function() {
      
            // Change min to-date to from-date the same as from date
            if ($("#edit-absence-request-date-to-datepicker-popup-0" ).hasClass('hasDatepicker')) {
                console.log('if');
                
                $("#edit-absence-request-date-to-datepicker-popup-0" ).datepicker( "option", "minDate", addDays($(this).val(), 0) ); // This method if to datepicker already initialised
           
            } else {
                console.log('else');
        
                $("#edit-absence-request-date-to-datepicker-popup-0" ).datepicker({changeMonth: true, changeYear: true});
                $("#edit-absence-request-date-to-datepicker-popup-0" ).datepicker( "option", "dateFormat", "yy-mm-dd");
                $("#edit-absence-request-date-to-datepicker-popup-0" ).datepicker( "option", "minDate", addDays($(this).val(), 0) ); // This method if to datepicker already initialised
                
            }

            // Change to-date to from-date
            $('#edit-absence-request-date-to-datepicker-popup-0', context).val($(this).val());
           
            // Trigger onclick event
            $('.ui-datepicker-current-day').trigger('click');

        });

        // Takes date string in format dd/mm/yyyy and returns date plus 'days' in the same format
        function addDays(dateStr, days) {
            // Convert to date obejct
            var dateArray = dateStr.split('-');
            var date = new Date(dateArray[0], dateArray[1]-1, dateArray[2]);

            // Add days
            date.setDate(date.getDate() + days);

            // Convert back to correct string format and return
            return date.getFullYear() + '-' + addZero(date.getMonth()+1) + '-' + addZero(date.getDate());
        }

        // Add leading zero if number is 9 or less
        function addZero(number) {
            if (number <= 9) {
                return '0'+number;
            } else {
                return number;
            }
        }
    }
}
})(jQuery);