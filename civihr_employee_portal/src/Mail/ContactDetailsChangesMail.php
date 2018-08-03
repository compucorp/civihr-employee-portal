<?php

namespace Drupal\civihr_employee_portal\Mail;

/**
 * To send emails with the differences when a user changes his details
 */
class ContactDetailsChangesMail extends AbstractDrupalSystemMail {
  /**
   * Returns the name of the template for this mail
   *
   * @return string
   *     the name of the template
   */
  protected function getTemplateName() {
    return 'notifications/html.tpl';
  }

  /**
   * To get HTML of Submissions Details for a notification
   *
   * @param array $contactData
   *    Structured data for the contact
   *
   * @return array
   *    Structured data for the section containing HTML and its title
   */
  private function buildSubmissionDetailsSection($contactData) {
    $email = trim($contactData->hrjc_contact_details_civicrm_contact_work_email);
    $displayName =  $contactData->civicrm_contact_display_name;
    $profilePath = 'civicrm/contact/view';
    $query = ['reset' => 1, 'cid' => $contactData->id];
    $attributes = ['style' => 'text-decoration: none; color: #42afcb'];
    $profileLinkArgs = ['absolute' => TRUE, 'query' => $query, 'attributes' => $attributes];
    $linkedEmail = l($email, 'mailto:' . $email, ['attributes' => $attributes]);
    $linkedProfile = l($displayName, $profilePath, $profileLinkArgs);
    $now = format_date(time(), 'custom', 'd/m/Y (h:ia)');

    $rows = [
      ['label' => 'Staff Member:', 'value' => $linkedProfile . ' | ' . $linkedEmail],
      ['label' => 'Submitted On:', 'value' => $now],
    ];

    $section = [];
    $section['title'] = 'Submission Details';
    $section['content'] = self::$smarty->fetchWith('notifications/section_content.tpl', ['rows' => $rows]);

    return $section;
  }

  /**
   * Build structured array with title and HTML content for a generic section of data
   *
   * @param array $change
   *    array of changed detected in a section
   *
   * @return array
   *    title and HTML content of the section
   */
  private function buildDataSection($change) {
    foreach ($change['diff'] as $field) {
      $rows = [];
      foreach ($field as $label => $value) {
        $rows[]= ['label' => $label, 'value' => $value];
      }
    }
    $sectionContent = self::$smarty->fetchWith('notifications/section_content.tpl', ['rows' => $rows]);
    $section = [
      'title' => $change['title'],
      'content' => $sectionContent,
    ];
    return  $section;
  }

  /**
   * To build the necessary variables that will be used to generate HTML from templates
   *
   * @return ContactDetailsChangesMail
   *     this, the same instance
   */
  private function buildVariables() {
    $variables = [];
    $variables['title'] = $this->params['subject'];
    $variables['page_title'] = $this->params['subject'];
    $variables['sections'] = [$this->buildSubmissionDetailsSection($this->params['contactData'])];

    foreach ($this->params['changes'] as $change) {
      $variables['sections'][] = $this->buildDataSection($change);
    }

    $this->variables = $variables;
    return $this;
  }
}
