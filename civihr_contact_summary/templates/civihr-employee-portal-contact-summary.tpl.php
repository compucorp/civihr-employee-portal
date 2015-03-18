
<?php
    /**
     * Created by PhpStorm.
     * User: gergelymeszaros
     * Date: 17/03/15
     * Time: 15:04
     */

?>

<div id="contact-summary-id" ng-app="myApp" ng-controller="myAppController">
    <h3 ng-class="myClass()">{{settings.title}}</h3>
    <p>
        <a class="btn btn-default" ng-click="updateCount(1)">Click</a>
        to increment {{count}} (template drupal + angular)
    </p>
</div>

<?php print $custom_data; ?>