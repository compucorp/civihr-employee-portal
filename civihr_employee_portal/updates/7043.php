<?php
/**
 * Remove Vacancies feature from the slideshow after new contact onboarding
 */
function civihr_employee_portal_update_7043() {
  $vacanciesNodeTitle = 'Vacancies';
  $vacanciesNodeId = db_query("SELECT nid FROM node WHERE title = '{$vacanciesNodeTitle}'")
    ->fetchField();

  $vacanciesNodeId && node_delete($vacanciesNodeId);
}
