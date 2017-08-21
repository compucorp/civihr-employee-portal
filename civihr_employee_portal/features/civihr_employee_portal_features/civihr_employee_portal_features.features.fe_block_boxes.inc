<?php
/**
 * @file
 * civihr_employee_portal_features.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function civihr_employee_portal_features_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Signup block for CiviHR';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'signup';
  $fe_block_boxes->body = '<style>
.block--join-civihr {
  transition: right 1s;
  text-align: center;
}

.block--join-civihr h4 {
  display: none;
}

.block--join-civihr .vertical-text {
  transform: rotate(90deg);
  transform-origin: left top 0;
  position: absolute;
  padding: 15px;
  margin: 0;
  top: 0;
  left: 0;
}

.block--join-civihr {
  position: fixed; 
  z-index: 1; 
  right: -240px; 
  top: 130px; 
  width: 240px; 
  background: #fff; 
}

.block--join-civihr .btn {
  float: none;
}

.slide-in-right {
  right: 0px !important;
}
</style>
<h3 id="signup-hide-button" class="vertical-text btn btn-primary">Join CiviHR</h3>
<form target="_blank" action="https://civihr.org/signup">
  <h3>Become an early adopter</h3>
  <p>Sign up for the public beta phase before the end of September. We\'ll provide free hosting and support till the end of March 2018, and you\'ll get to help shape the future of CiviHR.</p>
  <button class="btn btn-primary">Sign me up!</button>
  <p>or <a href="https://civihr.org">return to civihr.org</a></p>
</form>

<script>
  CRM.$(\'#signup-hide-button\').click(function() {
     CRM.$(\'.block--join-civihr\').toggleClass(\'slide-in-right\');
  });
</script>';

  $export['signup'] = $fe_block_boxes;

  return $export;
}
