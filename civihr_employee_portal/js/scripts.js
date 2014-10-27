(function($) {
Drupal.behaviors.civihr_employee_portal = {
    attach: function (context, settings) {

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