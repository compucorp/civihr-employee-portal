(function($) {

    var app = angular.module("myApp", []);
    app.controller("myAppController", function($scope) {
        $scope.settings = Drupal.settings.myapp;
        $scope.count = 1;

        $scope.updateCount = function(value) {
            $scope.count = $scope.count + value;
        }

        $scope.myClass = function() {
            return "myclass-" + $scope.count;
        }
    })

    var myVar = setInterval(foo, 5);

    function foo() {
        $('#contact-summary-id').each(function() {
            console.log('loading');

            if($(this).is(':visible')) {

                angular.bootstrap(document, ['myApp']);
                console.log(myVar);
                clearInterval(myVar);
            }
        });
    }



})(jQuery);

(function($) {
    Drupal.behaviors.civihr_contact_summary = {
        attach: function (context, settings) {


            $( "#tab_hrcontactsummary" ).click(function(event) {
                event.preventDefault();


                console.log('click');

            });
        }
    }

})(jQuery);