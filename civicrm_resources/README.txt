
The module provides an api function to easily load civicrm resources from an extention into drupal. It invokes a custom drupal cache bin to store path information of extensions, so as not to bootstrap civicrm on every api call. 

This module is sponsored by www.compucorp.co.uk

Installation 
------------

Place the Civi civicrm_resources in the modules directory of your site and
enable it on the `admin/modules` page.


Usage
-----

The module invokes a custom drupal cache bin to store path information of extensions, so as not to call civicrm_initialize() on every api call. 
To load a js/css from "Job Contract (CiviHR)", call the api function as in following examples.

- civicrm_resources_load('Job Contract (CiviHR)', array('gulpfile.js', 'hrjc.css', 'contact.js'));
This will load all css/js files listed in array located anywhere in extension "Job Contract (CiviHR)".

- civicrm_resources_load('Job Contract (CiviHR)', array('gulpfile.js', 'contact.js', '*.css'));
This will load all css files and 2 js files listed in array located anywhere in extension "Job Contract (CiviHR)".

- civicrm_resources_load('Job Contract (CiviHR)');
This will load all css files and all js files located anywhere in extension "Job Contract (CiviHR)".
