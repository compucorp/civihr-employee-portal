CiviHR employee portal custom Drupal modules
======================

Installation instructions - CiviHR 1.5
======================

- Install the hrdemo with civicrm_buildkit
- Turn on the Radix theme (/appearance) and set it to default theme
- Set the CiviCRM Administration theme and CiviCRM Public theme to Seven theme (/appearance)
- Disable the Emergency contacts (v1.4) module
- Disable the Absence (CiviHR v1.4) module
- Uninstall the Absence (CiviHR v1.4) module
- Install Absence (CiviHR v1.5)
- Disable the Job (CiviHR v1.4) module (no uninstall needed here)
- Install the Job Contract (CiviHR v1.5) module

Optionally:
- search for civihr_staff -> set absence entitlement for holidays, maternity etc
- put the leave approver for the civihr_staff, for example put leave approver as civihr_manager, after requesting a leave as staff, the civihr_manager will need to approve that leave.
