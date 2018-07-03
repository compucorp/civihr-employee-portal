<?php
  /**
  * This file is a template which holds the roles in MyDetails_MyRole view
  * No markup is printed on purpose because it must emulate a view HTML structure
  * at a row level, as if every row would be a view container.
  * Through the views UI this row is set with the appropiate markup to emulate
  * a view per row, as proposed in the design.
  * https://projects.invisionapp.com/d/main#/console/13248050/297230123/preview
  */
  foreach ($rows as $id => $row) {
    print $row;
  }
