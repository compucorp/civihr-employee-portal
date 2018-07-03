<?php

  // This is the view for printing contact details in My Details page
  // It contains 2 other views in its $footer section
  // However these views which contains information about phones and
  // emails ( view-mydetails-myphones / view-mydetails-emails ) are not
  // appropiate to be in the footer section of the contact details, that
  // is why $rows variable is being appended with the $footer content,
  // and after that footer content is set new markup, which is the
  // "Edit contact details button"

  // In the end _views-view--generic-display-output.tpl.php is called to
  // integrate seamlessly in the panel page of "My Deatils" page

  $rows .= $footer;
  $footer = '
    <a href="/edit-my-contact-details/js/view" class="ctools-use-modal ctools-modal-civihr-custom-style  btn btn-primary">
      <i class="fa fa-pencil" aria-hidden="true"></i> Edit Contact Details
    </a>';
  include('_views-view--generic-display-output.tpl.php');
