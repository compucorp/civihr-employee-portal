<?php

namespace Drupal\civihr_employee_portal\Mail;

use Drupal\civihr_employee_portal\Helpers\WebformHelper;

class OnboardingFormEditNotificationMail extends WebformSubmissionNotificationMail {

  /**
   * @param array $message
   *
   * @return array
   */
  public function getVariables($message) {
    $variables =  parent::getVariables($message);
    // Replace the title
    $variables['webformTitle'] = 'the onboarding form';

    return $variables;
  }

  /**
   * @inheritdoc
   */
  protected function formatSubmittedValues($node, $submission) {
    $submittedValues = WebformHelper::getSubmittedValues($node, $submission);

    $this->formatPersonalDetails($submittedValues);
    $this->formatPayroll($submittedValues);
    $this->formatEmergencyContacts($submittedValues);
    $this->formatDependants($submittedValues);

    // We don't want this info in the email
    unset($submittedValues['Profile Picture']);

    return $submittedValues;
  }

  /**
   * @param array $submittedValues
   */
  private function formatPersonalDetails(&$submittedValues) {
    $personalDetails = &$submittedValues['Personal Details'];
    unset($personalDetails[0]['Existing Contact']);

    // The options for this are not stored correctly and need manual replacement
    $ssnApplicationKey = 'I am currently applying for a NI/ SSN';
    $value = $personalDetails[0][$ssnApplicationKey];
    $replacement = $value ? 'Yes' : 'No';
    $personalDetails[0][$ssnApplicationKey] = $replacement;
  }

  /**
   * @param $submittedValues
   */
  protected function formatPayroll(&$submittedValues) {
    $payroll = &$submittedValues['Payroll'];
    $skipStepOption = 'Add Now (Payroll)';
    if ($this->skippedStep($payroll, $skipStepOption)) {
      $this->formatSkippedStep($payroll);
    }
    unset($payroll[0][$skipStepOption]);
  }

  /**
   * @param $submittedValues
   */
  private function formatEmergencyContacts(&$submittedValues) {
    $emergencyContacts = &$submittedValues['Emergency Contact'];
    $skipStepOption = 'Add Now (Emergency Contacts)';

    if ($this->skippedStep($emergencyContacts, $skipStepOption)) {
      $this->formatSkippedStep($emergencyContacts);
      return;
    }
    unset($emergencyContacts[0][$skipStepOption]);

    $addSecondOption = 'Add another emergency contact?';
    $firstContactKey = 'Emergency Contact';
    $secondContactKey = 'Second Emergency Contact';

    unset($emergencyContacts[$firstContactKey]['Is a dependant?']);
    unset($emergencyContacts[$secondContactKey]['Is a dependant?']);

    // Check if a second contact was added and remove the value for conditional
    $addedSecondContact = $emergencyContacts[0][$addSecondOption] === 'Yes';
    unset($emergencyContacts[0][$addSecondOption]);

    // Remove the second emergency contact if it wasn't added
    if (!$addedSecondContact) {
      unset($emergencyContacts[$secondContactKey]);
    }
  }

  /**
   * @param array $submittedValues
   */
  private function formatDependants(&$submittedValues) {
    $dependants = &$submittedValues['Dependants'];
    $skipStepOption = 'Add Now (Dependants)';
    if ($this->skippedStep($dependants, $skipStepOption)) {
      $this->formatSkippedStep($dependants);
      return;
    }
    // Unset unused data
    unset($dependants[0]);
    // Remove unused dependant entries
    $dependantsKeys = ['Fifth', 'Fourth', 'Third', 'Second', 'First'];
    foreach ($dependantsKeys as $index => $dependantKey) {
      if (!isset($dependantKey[$index + 1])) {
        continue;
      }

      // Get the answer to the question "Add a dependant" for previous element
      $key = $dependantKey . ' Dependant';
      $previousElementKey = $dependantsKeys[$index + 1] . ' Dependant';
      $previousElementValues = &$dependants[$previousElementKey];
      $addNextKey = 'Add a ' . strtolower($dependantKey) . ' dependant?';
      $nextDependentAdded = $previousElementValues[$addNextKey];

      // If no, then unset the current dependant
      if (empty($nextDependentAdded) || $nextDependentAdded === 'No') {
        unset($dependants[$key]);
      }

      // Remove conditional field
      unset($previousElementValues[$addNextKey]);
    }

    // Remove hidden field
    foreach ($dependants as &$dependant) {
      unset($dependant['Is a Dependant?']);
    }
  }

  /**
   * Formats a step values that has been skipped
   *
   * @param array $stepValues
   */
  private function formatSkippedStep(&$stepValues) {
    $stepValues = [0 => ['Skipped' => 'The user skipped this step']];
  }

  /**
   * Checks whether a step has been skipped by the user
   *
   * @param array $stepValues
   * @param string $skipStepOption
   *
   * @return bool
   */
  private function skippedStep($stepValues, $skipStepOption) {
    return $stepValues[0][$skipStepOption] !== 'Add Now';
  }

}
