CiviCRM Views Integration
=============
Making civicrm work with Drupal Views module [is pain](https://wiki.civicrm.org/confluence/display/CRMDOC/Views3+Integration),
you also need to keep updating the drupal settings.php file each time a new table by and extension or
new custom group get added .

This Extension simplifies this operation by creating/updating json file that holds the views integration database array which should be used in settings.php file with all CiviCRM tables prefixes; after installing the module the code that should be added by site admin is visible from admin/reports/status page and should be manually added to settings.php and keeping an eye on any custom group get added via hook_civicrm_post and re-create json file to hold updated custom group within array to the settings.php file automatically without any user interaction.

Author
======

- Omar Abu Hussein, [Compucorp LTD](http://compucorp.co.uk)
