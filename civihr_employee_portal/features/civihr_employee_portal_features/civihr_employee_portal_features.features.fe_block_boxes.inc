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
#civihr-signup-tab {
    transition: right 1s;
    text-align: center;
    position: fixed; 
    z-index: 100; 
    right: -340px; 
    top: 130px; 
    width: 280px; 
    background: #fff; 
    font-family: Lato, sans-serif;
    font-size: 16px;
    box-sizing: initial;
    color: rgb(118, 123, 142);
    padding: 10px 30px;
}

#civihr-signup-tab h3 {
    font-size: 28px;
    line-height: normal;
    margin: 5px;
}

#civihr-signup-tab a {
    color: #18BCB9;
}

#civihr-signup-tab .signup-button {
    color: #fff;
    background-color: #18BCB9;
    font-family: Lato, sans-serif;
    font-size: 13px;
    float: none;
    border: none;
    padding: 10px;
    cursor: pointer;
    box-sizing: initial;
}

#civihr-signup-tab .vertical-text {
    transform: rotate(270deg);
    transform-origin: left top 0;
    position: absolute;
    padding: 15px;
    width: 100px;
    height: 20px;
    margin: 0;
    top: 130px;
    left: -50px;
}

#civihr-signup-tab .big-and-bold {
    font-weight: bold;
    font-size: 16px;
    text-transform: uppercase;
}

.slide-in-right {
    right: 0px !important;
}
</style>

<div id="civihr-signup-tab">
<h3 id="signup-hide-button" class="vertical-text signup-button big-and-bold">JOIN CIVIHR</h3>
<form target="_blank" action="https://civihr.org/signup">
  <h3>Become an early adopter</h3>
  <p>Sign up for the public beta phase before the end of September. We\'ll provide free hosting and support till the end of March 2018, and you\'ll get to help shape the future of CiviHR.</p>
  <button class="signup-button big-and-bold">SIGN ME UP!</button>
  <p>or <a href="https://civihr.org">return to civihr.org</a></p>
</form>
</div>

<script>
  CRM.$(\'#signup-hide-button\').click(function() {
     CRM.$(\'#civihr-signup-tab\').toggleClass(\'slide-in-right\');
  });
</script>';

  $export['signup'] = $fe_block_boxes;

  return $export;
}
