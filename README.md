CiviHR employee portal custom Drupal modules
======================

DEMO site available here:
http://178.79.132.53:8001/welcome-page
======================

Installation instructions - CiviHR 1.5
======================

- Install the hr15 profile with civicrm_buildkit (https://github.com/civicrm/civicrm-buildkit)
- Example command to install CiviHR: civibuild create hr15 --civi-ver 4.5 --url http://localhost:8900

Optionally:
- search for civihr_staff -> set absence entitlement for holidays, maternity etc
- put the leave approver for the civihr_staff, for example put leave approver as civihr_manager, after requesting a leave as staff, the civihr_manager will need to approve that leave.
