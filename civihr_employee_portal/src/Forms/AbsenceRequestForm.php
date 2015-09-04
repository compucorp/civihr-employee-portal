<?php

namespace Drupal\civihr_employee_portal\Forms;

class AbsenceRequestForm {

    protected $form;
    protected $absence_type;
    protected $form_state;

    /**
     *
     *
     */
    public function __construct($form, &$form_state) {
        $this->form = $form;
        $this->form_state =& $form_state;
    }

    /**
     *
     *
     */
    public function ajax_callback() {
        // Init leave whole duration
        $whole_duration = 0;

        // Calculate the leave whole duration
        foreach ($this->form_state['values'] as $s_key => $form_s_val) {
            if (strpos($s_key, '_requested_day_') !== false) {
                $whole_duration += $form_s_val;
            }
        }

        // Get the days
        $whole_duration = $whole_duration / (6 * 80);

        $this->form['absence_request_dates_selected']['#title'] = t('Dates selected:') . '<span class="civihr_form--request-leave__period">' . $this->form_state['values']['absence_request_date_from'] . " - " . $this->form_state['values']['absence_request_date_to'] . " (" . $whole_duration . " " . t("days") . ')</span>';

        $from = $this->form_state['values']['absence_request_date_from'];
        $to = $this->form_state['values']['absence_request_date_to'];
        $i = 0;

        while ($from <= $to) {
            $from = strtotime($from);
            $from = $from + (60 * 60 * 24);
            $from = date('Y-m-d', $from);

            $i++;
        }

        $this->form['absence_request_dates_selected']['dates_counter']['#value'] = $i;

        $this->show_hide_selected_dates_section($i);

        return $this->form['absence_request_dates_selected'];
    }

    /**
     *
     *
     */
    public function build() {
        $this->add_properties();
        $this->add_fields();

        if (isset($this->form_state['values']['absence_request_date_from'])) {
            $this->add_requested_date_fields();
        }

        return $this->form;
    }

    /**
     *
     *
     */
    public function submit() {
        global $user;

        $submitted_attachment = new \stdClass();

        if (isset($this->form_state['values']['absence_file']) && $this->form_state['values']['absence_file'] != "") {

            // Unset the file from the form
            $file = $this->form_state['values']['absence_file'];
            unset($this->form_state['values']['absence_file']);

            // Change the file to permanent
            $file->status = FILE_STATUS_PERMANENT;
            $file->display = 1;
            $file->description = '';

            $saved_file = file_save($file);

            // Add the attached file
            $submitted_attachment = (object) $saved_file;
        }

        // Set absence type
        $absence_main_type = 'debit';

        if (isset($this->form_state['values']['absence_type']) && $this->form_state['values']['absence_type'] != '') {
            $absence_main_type = $this->form_state['values']['absence_type'];
        }

        // Set absence details
        $absence_details = '';

        if (isset($this->form_state['values']['details']) && $this->form_state['values']['details'] != '') {
            $absence_details = drupal_html_to_text(nl2br($this->form_state['values']['details']));
        }

        // Get the absence types
        $absenceTypes = get_civihr_absence_types();

        // Get leave Type
        foreach ($absenceTypes as $absenceType) {

            if (isset($absenceType['credit_activity_type_id']) && $absenceType['credit_activity_type_id'] == $this->form_state['values']['absence_request_type']) {
                $leave_type = $absenceType['title'];
            }

            if (isset($absenceType['debit_activity_type_id']) && $absenceType['debit_activity_type_id'] == $this->form_state['values']['absence_request_type']) {
                $leave_type = $absenceType['title'];
            }
        }

        // Send the form submitted values
        $form_object = (object) $this->form_state['values'];

        $whole_duration = 0;

        // Calculate the leave whole duration
        foreach ($this->form_state['values'] as $s_key => $form_s_val) {
            if (strpos($s_key, '_requested_day_') !== false) {
                $whole_duration += $form_s_val;
            }
        }

        // Get the leave_date
        if (isset($this->form_state['values']) && $this->form_state['values']['dates_counter'] != '1') {
            $absence_date = $this->form_state['values']['absence_request_date_from'] . ' - ' . $this->form_state['values']['absence_request_date_to'];
            $day = t('days');
        } else {
            $absence_date = $this->form_state['values']['absence_request_date_from'];
            $day = t('day');
        }

        // Build the leave date string
        $leave_date = $absence_date . ' = ' . $whole_duration / (6 * 80) . ' ' . $day;

        // Fire rules events
        rules_invoke_event('absence_request_add', $user, $absence_main_type, $absence_details, $form_object, $leave_type, $leave_date, $submitted_attachment);
    }

    /**
     *
     *
     */
    public function validate() {
        global $user;

        // Validate only after final submit
        // This check is required because the validate function is called with each ajax refresh eg. start/end date change during absence request
        if (isset($this->form_state['values']['op']) && isset($this->form_state['values']['absence_file']) && $this->form_state['values']['op'] == 'Submit') {
            $file = file_save_upload('absence_file', array(
                'file_validate_is_image' => array(),
                'file_validate_extensions' => array('png gif jpg jpeg'),
            ));

            if ($file) {
                if ($file = file_move($file, 'private://')) {
                    $this->form_state['values']['absence_file'] = $file;
                } else {
                    form_set_error('absence_file', t('Failed to write the uploaded file the site\'s file folder.'));
                }
            }
        }

        if (isset($this->form_state['values']['absence_request_date_from']) && isset($this->form_state['values']['absence_request_date_to'])) {
            if ($this->form_state['values']['absence_request_date_to'] < $this->form_state['values']['absence_request_date_from'])
                form_set_error('absence_request_date_to', t('End date must be bigger than the start date!'));

            if (!isset($this->form_state['values']['absence_request_date_from']['date'])) {
                // Explode the date, convert to timestamp and compare to the current day timestamp
                $mk_time_start = explode("-", $this->form_state['values']['absence_request_date_from']);
                $mk_time_end = explode("-", $this->form_state['values']['absence_request_date_to']);

                // Not allow the request to overflow to next/different year (how we calculate the available entitlement if we allow this?)
                if ($mk_time_end[0] != $mk_time_start[0]) {
                    form_set_error('absence_request_date_to', t('Absence request start and end date must be in the same year!'));
                }

                // Load the date periods
                $date_periods = get_civihr_date_periods();

                foreach ($date_periods as $date_period) {
                    // Check the date periods and compare to the requested absence start date
                    if (strpos($date_period['start_date'], $mk_time_start[0]) !== false) {
                        $period_id = $date_period['id'];
                    }
                }

                // Check if we have the period ID (based on the passed absence start date year) - if no period ID return error
                if (!isset($period_id)) {
                    form_set_error('absence_request_date_from', t("This date period is not yet defined, please contact your Administrator!"));
                    return false;
                }

                // Requested leave - start timestamp
                $request_timestamp = mktime(0, 0, 0, $mk_time_start[1], $mk_time_start[2], $mk_time_start[0]);

                // If we requested leave with start date in the past
                if ($request_timestamp < strtotime('today') && $this->form_state['values']['absence_type'] != "sick")
                    form_set_error('absence_request_date_from', t('Only Sickness can be requested with start date in the past!'));

                // If we requested leave with start date in the future (applies only if leave type is "sick")
                if ($request_timestamp > strtotime('today') && $this->form_state['values']['absence_type'] == "sick")
                    form_set_error('absence_request_date_from', t('You are not allowed to report Sickness in advance!'));

                // Check if we have enough leave left to request this leave (only if leave type is DEBIT or CREDIT_USE) -> deducting days
                if (isset($this->form_state['values']['absence_type']) && ($this->form_state['values']['absence_type'] == 'debit' || $this->form_state['values']['absence_type'] == 'credit_use')) {
                    // Get the absence types
                    $absenceTypes = get_civihr_absence_types();

                    // Get leave Type
                    foreach ($absenceTypes as $absenceType) {
                        if (isset($absenceType['credit_activity_type_id']) && $absenceType['credit_activity_type_id'] == $this->form_state['values']['absence_request_type']) {
                            $leave_type = $absenceType['title'];
                            $leave_id = $absenceType['id'];
                        }

                        if (isset($absenceType['debit_activity_type_id']) && $absenceType['debit_activity_type_id'] == $this->form_state['values']['absence_request_type']) {
                            $leave_type = $absenceType['title'];
                            $leave_id = $absenceType['id'];
                        }
                    }

                    // Init leave whole duration
                    $whole_duration = 0;

                    // Calculate the leave whole duration
                    foreach ($this->form_state['values'] as $s_key => $form_s_val) {
                        if (strpos($s_key, '_requested_day_') !== false) {
                            $whole_duration += $form_s_val;
                        }
                    }

                    try {
                        $entitlement_data = civicrm_api3('HRAbsenceEntitlement', 'getsingle', array(
                            'sequential' => 1,
                            'type_id' => $leave_id,
                            'contact_id' => $_SESSION['CiviCRM']['userID'],
                            'period_id' => $period_id,
                            'options' => array('limit' => 1) // Make sure to return with limit 1 as if credit and debit is defined the API returns 2 results as default
                        ));
                    } catch (\Exception $e) {
                        // No entitlement returned or server error
                        watchdog('exception - entitlement data', print_r($e, true));
                        form_set_error('absence_request_date_from', t("No entitlement defined for absence type, or server error!"));

                        return false;
                    }

                    // Duration of days what we requested
                    $whole_duration = $whole_duration / (6 * 80);

                    // Calculate how many days you already requested which is not (rejected or cancelled) -> those doesn't decrease your available days
                    $q = db_select('absence_list', 'al')
                        ->condition('contact_id', $_SESSION['CiviCRM']['userID'])
                        ->condition('absence_status', 3, '<>')
                        ->condition('absence_status', 9, '<>')
                        ->condition('absence_start_date', '%' . db_like($mk_time_start[0]) . '%', 'LIKE')
                        ->condition('activity_type_id', $this->form_state['values']['absence_request_type']);
                    $q->addExpression('sum(duration) / (6 * 80)');

                    $sum_approved_duration = $q->execute()->fetchField();

                    // Check if we have credit added for that absence type
                    $q = db_select('absence_list', 'al')
                        ->condition('contact_id', $_SESSION['CiviCRM']['userID'])
                        ->condition('absence_status', 3, '<>')
                        ->condition('absence_status', 9, '<>')
                        ->condition('is_credit', 1)
                        ->condition('absence_start_date', '%' . db_like($mk_time_start[0]) . '%', 'LIKE')
                        ->condition('absence_title', $leave_type);
                    $q->addExpression('sum(duration) / (6 * 80)');

                    $sum_added_credit = $q->execute()->fetchField();

                    // Available days = (credit absences added + total_entitlement) - debit_absences
                    $available_days = ($sum_added_credit + $entitlement_data['amount']) - $sum_approved_duration;

                    if ($whole_duration > $available_days) {
                        form_set_error('absence_request_date_from', t("You don't have enough days available to request this leave! (@days_left days left)", array('@days_left' => $available_days)));
                    }

                    watchdog('total duration requested', print_r($whole_duration, true));
                    watchdog('entitlement data', print_r($entitlement_data['amount'], true));
                    watchdog('sum total added credit', print_r($sum_added_credit, true));
                    watchdog('already approved duration', print_r($sum_approved_duration, true));
                }

                // @todo If we requeting credit type -> currently no rule
            }
        }

        return true;
    }

    /**
     *
     *
     */
    protected function add_fields() {
        $this->form['absence_request_type'] = array(
            '#title' => t('Type:'),
            '#type' => 'select',
            '#options' => $this->get_absence_types(),
            '#prefix' => '<div class="modal-civihr-custom__section--strip">',
            '#suffix'=> '</div>'
        );

        $this->form['absence_file'] = array(
            '#type' => 'file',
            '#title' => t('Document'),
            '#attributes' => array('size' => ''),
            '#description' => t('Upload supporting documentation if needed, allowed extensions: jpg, jpeg, png, gif'),
            '#prefix' => '<div class="modal-civihr-custom__section">',
            '#suffix'=> '</div>'
         );

        $this->form['absence_request_date_from'] = array(
            '#title' => t('From:'),
            '#type' => 'date_popup',
            '#required' => 'TRUE',
            '#date_format' => 'Y-m-d',
            '#date_year_range' => '-2:+2',
            '#prefix' => '<div class="modal-civihr-custom__section">'
        );

        $this->form['absence_request_date_to'] = array(
            '#title' => t('Until:'),
            '#type' => 'date_popup',
            '#required' => 'TRUE',
            '#ajax' => array(
                'callback'  => 'jms_industry_lens_form_ajax',
                'wrapper'   => 'absence-request-dates-selected',
                'event'   => 'change',
            ),
            '#date_format' => 'Y-m-d',
            '#date_year_range' => '-10:+10',
            '#suffix' => '</div>'
        );

        $this->form['absence_request_dates_selected'] = array(
            '#type' => 'fieldset',
            '#title' => t('Selected dates'),
            '#markup' => '',
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#attributes' => array('class' => array('civihr_form__fieldset--transparent')),
            '#prefix' => '<div id="absence-request-dates-selected" class="hide modal-civihr-custom__section">',
            '#suffix' => '</div>'
        );

        $this->form['absence_request_dates_selected']['dates_counter'] = array(
            '#type'     => 'hidden',
            '#title' => 'Counter',
            '#default_value' => 'null',
        );

        $this->form['absence_type'] = array(
            '#type' => 'hidden',
            '#value' => $this->absence_type,
        );

        $this->form['details'] = array(
            '#type' => 'textarea',
            '#title' => t('Notes:'),
            '#rows' => 10,
            '#cols' => null,
            '#prefix' => '<div class="modal-civihr-custom__section">',
            '#suffix'=> '</div>'
        );

        $this->form['submit'] = array(
            '#type' => 'submit',
            '#value' => t('Submit'),
            '#prefix' => '<div class="modal-civihr-custom__footer">',
            '#suffix'=> '</div>'
        );
    }

    /**
     *
     *
     */
    protected function add_properties() {
        $this->form['#attributes']['class'][] = 'civihr_form--modal civihr_form--request-leave';
        $this->form['#validate'][] = 'civihr_employee_portal_absence_request_form_validate';
        $this->form['#submit'][] = "civihr_employee_portal_absence_request_form_submit";
    }

    /**
     *
     *
     */
    protected function add_requested_date_fields() {
        $from = $this->form_state['values']['absence_request_date_from'];
        $to = $this->form_state['values']['absence_request_date_to'];
        $i = 0;

        try {
            // Get the activity ID for the public holiday activity type
            $holiday_activity_type_id = civicrm_api3('OptionValue', 'getvalue', array(
                'sequential' => 1,
                'name' => "Public Holiday",
                'return' => "value"
            ));

            // Get the public holidays
            $public_holidays = civicrm_api3('Activity', 'get', array(
                'sequential' => 1,
                'activity_type_id' => $holiday_activity_type_id,
            ));

        } catch (Exception $e) {
            // No public holidays returned or server error
            watchdog('exception - public holidays', print_r($e, TRUE));
            form_set_error('absence_request_date_from', t("Public holidays not defined, or server error!"));

            return $this->form;
        }

        while ($from <= $to) {
            $check_day = _checkRequestedDay($public_holidays, $from); // Check if the day is public holiday or not working day

            $this->form['absence_request_dates_selected']['_requested_day_' . str_replace('-', '', $from)] = array(
                '#type'     => 'select',
                '#title' => $from . $check_day['exclude_type'],
                '#options' => array('480' => t('All day'), '240' => t('Half day'), '0' => t('Excluded @exclude_type', array('@exclude_type' => $check_day['exclude_type']))),
                '#default_value' => $check_day['default_value'],
                '#ajax' => array(
                    'callback'  => 'jms_industry_lens_form_ajax',
                    'wrapper'   => 'absence-request-dates-selected',
                    'event'   => 'change',
                )
            );

            $from = strtotime($from);
            $from = $from + (60 * 60 * 24);
            $from = date('Y-m-d', $from);
        }

        $this->reset_form_state_requested_days();
    }

    /**
     *
     *
     */
    protected function get_absence_types() {
        $this->absence_type = 'debit';

        if (isset($this->form_state['absence_type']) && $this->form_state['absence_type'] != '') {
            $this->absence_type = $this->form_state['absence_type'];
        } else {
            $this->absence_type = arg(2); // Javascript probably disabled - use the value from arg()
        }

        $absenceTypes = get_civihr_absence_types();

        // Absence types select list
        $options = array();

        foreach ($absenceTypes as $absenceType) {

            if (isset($absenceType['id']) && $absenceType['is_active'] == 1) {

                // If credit type is allowed show credit types (only if the employee clicked -> Request TOIL)
                if ($absenceType['allow_credits'] == '1' && $this->absence_type == 'credit') {
                    // Default credit types
                    $options[$absenceType['credit_activity_type_id']] = $absenceType['title'];
                }

                // If debit type is allowed show debit types (only if the employee clicked -> Request Leave)
                if ($absenceType['allow_debits'] == '1' && $this->absence_type == 'debit' && $absenceType['allow_credits'] !== '1' && $absenceType['title'] != 'Sick') {
                  // Default debit types
                    $options[$absenceType['debit_activity_type_id']] = $absenceType['title'];
                }

                // If Use TOIL is clicked show only debit types, which has credit type allowed too
                if ($absenceType['allow_debits'] == '1' && $absenceType['allow_credits'] == '1' && $this->absence_type == 'credit_use' && $absenceType['title'] != 'Sick') {
                    // Default debit types which has credit type too
                    $options[$absenceType['debit_activity_type_id']] = $absenceType['title'];
                }

                // If Report New Sickness is clicked, show the debit types which are selected as the Sickness Absence Type @TODO -> currently hardcoded based on absence title
                if ($absenceType['allow_debits'] == '1' && $this->absence_type == 'sick' && $absenceType['title'] == 'Sick') {
                    // Default debit types which has credit type too
                    $options[$absenceType['debit_activity_type_id']] = $absenceType['title'];
                }
            }
        }

        return $options;
    }

    /**
     * Reset the previously build _requested_day_ fields in the
     * $form_state values to avoid them being carried over
     */
    protected function reset_form_state_requested_days() {
        foreach ($this->form_state['values'] as $s_key => $form_s_val) {
            if (strpos($s_key, '_requested_day_') !== false) {
                unset($this->form_state['values'][$s_key]);
           }
        }
    }

    /**
     * Showing and hiding the selected dates based on their number
     */
    protected function show_hide_selected_dates_section($dates_number) {
        $containing_div = $this->form['absence_request_dates_selected']['#prefix'];
        $hidden = strpos($containing_div, 'hide');

        if ($dates_number > 0 && $hidden) {
            $containing_div = str_replace('hide', '', $containing_div);
        } elseif ($dates_number == 0 && !$hidden) {
            $containing_div = str_replace('class="', 'class="hide"', $containing_div);
        }

        $this->form['absence_request_dates_selected']['#prefix'] = $containing_div;
    }
}
?>
