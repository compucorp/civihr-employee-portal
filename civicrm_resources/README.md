
The module provides an api function to easily load civicrm resources from an extention into drupal. It invokes a custom drupal cache bin to store path information of extensions, so as not to bootstrap civicrm on every api call.

This module is sponsored by www.compucorp.co.uk

Installation
------------

Place the Civi civicrm_resources in the modules directory of your site and
enable it on the `admin/modules` page.


Usage
-----

The module invokes a custom drupal cache bin to store path information of extensions, so as not to call civicrm_initialize() on every api call.
To load JS/CSS resources from "Job Contract (CiviHR)", call the API function as follows:

```js
civicrm_resources_load('org.civicrm.hrjobcontract', [
  'css/dist/hrjc.css',
  'js/dist/contact.js',
  'js/gulpfile.js'
]);
```

This will load one CSS and two JS resources located in the extension "Job Contract (CiviHR)".
