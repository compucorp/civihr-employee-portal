<?php
/**
 * Remove Vacancies feature from the slideshow after new contact onboarding
 */
function civihr_employee_portal_update_7043() {
  $vacanciesNodeTitle = 'Vacancies';
  $vacanciesNodeId = db_query("SELECT nid FROM node WHERE
    title = '{$vacanciesNodeTitle}' AND
    type = 'welcome_slideshow'")
    ->fetchField();

  if ($vacanciesNodeId) {
    node_delete($vacanciesNodeId);
  }
}
