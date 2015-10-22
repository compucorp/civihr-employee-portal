<?php

namespace Drupal\civihr_employee_portal\Forms;

class AbsenceRequestForm {

    protected $absence_type;
    protected $form;
    protected $form_state;

    /**
     * Constructor
     *
     * @param array $form
     *   The form structure
     * @param array $form_state
     *   The current form values
     */
    public function __construct($form, &$form_state) {
        $this->form = $form;
        $this->form_state =& $form_state;
    }

    /**
     * The callback called via the '#ajax.callback' properties of the form fields
     *
     * @return array
     *   The structure of the 'dates selected' form area
     */
    public function ajax_callback() {
        $from = $this->form_state['values']['absence_request_date_from'];
        $i = 0;

        while ($from <= $this->form_state['values']['absence_request_date_to']) {
            $i++;
            $this->add_day_to($from);
        }

        $this->form['absence_request_dates_selected']['dates_counter']['#value'] = $i;
        $this->form['absence_request_dates_selected']['#title'] = t('Dates selected:') . '<span class="civihr_form--request-leave__period">' . $this->form_state['values']['absence_request_date_from'] . " - " . $this->form_state['values']['absence_request_date_to'] . " (" . $this->request_duration() . " " . t("days") . ')</span>';

        $this->show_hide_selected_dates_section($i);

        return $this->form['absence_request_dates_selected'];
    }

    /**
     * Build the form structure
     *
     * @return array
     *   The new form structure
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
     * Submits the form
     */
    public function submit() {
        global $user;

        $attachment = $this->process_attachment();

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

        // Send the form submitted values
        $form_object = (object) $this->form_state['values'];

        // Get the leave_date
        if (isset($this->form_state['values']) && $this->form_state['values']['dates_counter'] != '1') {
            $absence_date = $this->form_state['values']['absence_request_date_from'] . ' - ' . $this->form_state['values']['absence_request_date_to'];
            $day = t('days');
        } else {
            $absence_date = $this->form_state['values']['absence_request_date_from'];
            $day = t('day');
        }

        // Build the leave date string
        $leave_date = $absence_date . ' = ' . $this->request_duration() . ' ' . $day;

        // Fire rules events
        rules_invoke_event('absence_request_add', $user, $absence_main_type, $absence_details, $form_object, $this->leave_data()['type'], $leave_date, $attachment);
    }

    /**
     * Validates the form
     *
     * @return boolean
     */
    public function validate() {
        $this->validate_attachment();

        if (isset($this->form_state['values']['absence_request_date_from']) && isset($this->form_state['values']['absence_request_date_to'])) {
            if ($this->form_state['values']['absence_request_date_to'] < $this->form_state['values']['absence_request_date_from']) {
                form_set_error('absence_request_date_to', t('End date must be bigger than the start date!'));
            }

            if (!isset($this->form_state['values']['absence_request_date_from']['date'])) {
                // Explode the date, convert to timestamp
                $mk_time_start = explode("-", $this->form_state['values']['absence_request_date_from']);
                $mk_time_end = explode("-", $this->form_state['values']['absence_request_date_to']);
                $mk_time_start_timestamp = mktime(0, 0, 0, $mk_time_start[1], $mk_time_start[2], $mk_time_start[0]);
                $mk_time_end_timestamp = mktime(0, 0, 0, $mk_time_end[1], $mk_time_end[2], $mk_time_end[0]);

                $period_id = $this->period_id($mk_time_start);

                // Not allow the request to overflow to next/different year (how we calculate the available entitlement if we allow this?)
                if ($mk_time_end[0] != $mk_time_start[0]) {
                    form_set_error('absence_request_date_to', t('Absence request start and end date must be in the same year!'));
                }

                // Check if we have the period ID (based on the passed absence start date year) - if no period ID return error
                if ($period_id == null) {
                    form_set_error('absence_request_date_from', t('This date period is not yet defined, please contact your Administrator!'));
                    return false;
                }

                // If we requested leave with start date in the past
                if ($mk_time_start_timestamp < strtotime('today') && $this->form_state['values']['absence_type'] != "sick") {
                    form_set_error('absence_request_date_from', t('Only Sickness can be requested with start date in the past!'));
                }

                // If we requested leave with start date in the future (applies only if leave type is "sick")
                if ($mk_time_start_timestamp > strtotime('today') && $this->form_state['values']['absence_type'] == "sick") {
                    form_set_error('absence_request_date_from', t('You are not allowed to report Sickness in advance!'));
                }
                
                // If we requested leave with dates that have already been requested before (duplicate dates)
                if($this->duplicate_dates_exist($mk_time_start_timestamp, $mk_time_end_timestamp)){
                    form_set_error('form', t('You have already requested leave for this date.'));
                }
                
                // Check if we have enough leave left to request this leave (only if leave type is DEBIT or CREDIT_USE) -> deducting days
                if (isset($this->form_state['values']['absence_type']) && ($this->form_state['values']['absence_type'] == 'debit' || $this->form_state['values']['absence_type'] == 'credit_use')) {
                    $leave = $this->leave_data();
                    $entitlement = $this->entitlement_data($leave['id'], $period_id);

                    if ($entitlement === null) {
                        return false;
                    }

                    $whole_duration = $this->request_duration();
                    $sum_approved_duration = $this->approved_duration($mk_time_start[0]);
                    $sum_added_credit = $this->credit_for_absence_type($leave['type'], $mk_time_start[0]);
                    $available_days = $this->available_days($sum_added_credit, $entitlement['amount'], $sum_approved_duration);

                    if ($whole_duration > $available_days) {
                        form_set_error('absence_request_date_from', t("You don't have enough days available to request this leave! (@days_left days left)", array('@days_left' => $available_days)));
                    }

                    watchdog('total duration requested', print_r($whole_duration, true));
                    watchdog('entitlement data', print_r($entitlement['amount'], true));
                    watchdog('sum total added credit', print_r($sum_added_credit, true));
                    watchdog('already approved duration', print_r($sum_approved_duration, true));
                }

                // @todo If we requeting credit type -> currently no rule
            }
        }

        return true;
    }

    /**
     * The current absence_type (cached)
     *
     * @return string
     */
    protected function absence_type() {
        if ($this->absence_type) {
            return $this->absence_type;
        }

        $this->absence_type = 'debit';

        if (isset($this->form_state['absence_type']) && $this->form_state['absence_type'] != '') {
            $this->absence_type = $this->form_state['absence_type'];
        } else {
            $this->absence_type = arg(2); // Javascript probably disabled - use the value from arg()
        }

        return $this->absence_type;
    }

    /**
     * The list of possible absence types based on the current absent type
     *
     * @return array
     */
    protected function absence_types() {
        $options = array();

        foreach (get_civihr_absence_types() as $absence_type) {
            if (isset($absence_type['id']) && $absence_type['is_active'] == 1) {
                // If credit type is allowed show credit types (only if the employee clicked -> Request TOIL)
                if ($absence_type['allow_credits'] == '1' && $this->absence_type() == 'credit') {
                    // Default credit types
                    $options[$absence_type['credit_activity_type_id']] = $absence_type['title'];
                }

                // If debit type is allowed show debit types (only if the employee clicked -> Request Leave)
                if ($absence_type['allow_debits'] == '1' && $this->absence_type() == 'debit' && $absence_type['allow_credits'] !== '1' && $absence_type['title'] != 'Sick') {
                  // Default debit types
                    $options[$absence_type['debit_activity_type_id']] = $absence_type['title'];
                }

                // If Use TOIL is clicked show only debit types, which has credit type allowed too
                if ($absence_type['allow_debits'] == '1' && $absence_type['allow_credits'] == '1' && $this->absence_type() == 'credit_use' && $absence_type['title'] != 'Sick') {
                    // Default debit types which has credit type too
                    $options[$absence_type['debit_activity_type_id']] = $absence_type['title'];
                }

                // If Report New Sickness is clicked, show the debit types which are selected as the Sickness Absence Type @TODO -> currently hardcoded based on absence title
                if ($absence_type['allow_debits'] == '1' && $this->absence_type() == 'sick' && $absence_type['title'] == 'Sick') {
                    // Default debit types which has credit type too
                    $options[$absence_type['debit_activity_type_id']] = $absence_type['title'];
                }
            }
        }

        return $options;
    }

    /**
     * Adds a day to a given date
     *
     * @param string
     *   The date to add a day to
     */
    protected function add_day_to(&$date) {
        $date = date('Y-m-d', strtotime($date) + (60 * 60 * 24));
    }

    /**
     * Adds the fields that make up the form
     */
    protected function add_fields() {
        $this->form['absence_request_type'] = array(
            '#attributes' => array('class' => array('skip-js-custom-select')),
            '#title' => t('Type:'),
            '#type' => 'select',
            '#options' => $this->absence_types(),
            '#field_prefix' => '<div class="chr_custom-select chr_custom-select--full chr_custom-select--transparent">',
            '#field_suffix' => '</div>',
            '#prefix' => '<div class="modal-civihr-custom__section--strip">',
            '#suffix'=> '</div>',
        );

        $this->form['absence_file'] = array(
            '#type' => 'file',
            '#title' => t('Document:'),
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
            '#value' => $this->absence_type(),
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
     * Adds the properties to the form
     */
    protected function add_properties() {
        $this->form['#attributes']['class'][] = 'civihr_form--modal civihr_form--request-leave';
        $this->form['#validate'][] = 'civihr_employee_portal_absence_request_form_validate';
        $this->form['#submit'][] = "civihr_employee_portal_absence_request_form_submit";
    }

    /**
     * Adds the _requested_day_ field to the form, based on the selected absence period
     */
    protected function add_requested_date_fields() {
        $from = $this->form_state['values']['absence_request_date_from'];

        try {
            $public_holidays = $this->public_holidays();
        } catch (Exception $e) {
            watchdog('exception - public holidays', print_r($e, TRUE));
            form_set_error('absence_request_date_from', t("Public holidays not defined, or server error!"));

            return;
        }

        while ($from <= $this->form_state['values']['absence_request_date_to']) {
            $check_day = _checkRequestedDay($public_holidays, $from); // Check if the day is public holiday or not working day

            $this->form['absence_request_dates_selected']['_requested_day_' . str_replace('-', '', $from)] = array(
                '#type' => 'select',
                '#title' => $from . $check_day['exclude_type'],
                '#options' => array('480' => t('All day'), '240' => t('Half day'), '0' => t('Excluded @exclude_type', array('@exclude_type' => $check_day['exclude_type']))),
                '#default_value' => $check_day['default_value'],
                '#ajax' => array(
                    'callback' => 'jms_industry_lens_form_ajax',
                    'wrapper' => 'absence-request-dates-selected',
                    'event' => 'change'
                )
            );

            $this->add_day_to($from);
        }

        $this->reset_form_state_requested_days();
    }

    /**
     * Calculate how many days you already requested which is not (rejected or cancelled) -> those doesn't decrease your available days
     *
     * @param string $year
     *   The year of the current request
     * @return dataset
     */
    protected function approved_duration($year) {
        $q = db_select('absence_list', 'al')
            ->condition('contact_id', $_SESSION['CiviCRM']['userID'])
            ->condition('absence_status', 3, '<>')
            ->condition('absence_status', 9, '<>')
            ->condition('absence_start_date', '%' . db_like($year) . '%', 'LIKE')
            ->condition('activity_type_id', $this->form_state['values']['absence_request_type']);
        $q->addExpression('sum(duration) / (6 * 80)');

        return $q->execute()->fetchField();
    }
    
    /**
     * Check if the dates requested for leaves are already requested for other leaves before
     *
     * @param timestamp $requestedStartTimestamp
     *   Timestamp for start date requested by the user
     * @param timestamp $requestedEndTimestamp
     *   Timestamp for start date requested by the user
     * @return bool
     */
    protected function duplicate_dates_exist($requestedStartTimestamp, $requestedEndTimestamp) {
        // fetch all leaves that has End time greater than today
        $absencesDataQuery = db_select('absence_list', 'al')
            ->condition('contact_id', $_SESSION['CiviCRM']['userID'])
            //->condition('absence_end_date_timestamp', strtotime('today'), '>')
            ->fields('al', array('absence_start_date_timestamp', 'absence_end_date_timestamp'));

        $absencesData = $absencesDataQuery->execute()->fetchAll();

        $dateExists = false;
        foreach($absencesData as $absence) {
            $startTimestamp = $absence->absence_start_date_timestamp;
            $endTimestamp = $absence->absence_end_date_timestamp;

            $dateExists = false;
            if($requestedStartTimestamp <= $endTimestamp && $requestedStartTimestamp >= $startTimestamp) {
                    $dateExists = true;
            }else if($requestedEndTimestamp >= $startTimestamp && $requestedEndTimestamp <= $endTimestamp) {
                    $dateExists = true;
            }else if($startTimestamp >= $requestedStartTimestamp && $endTimestamp <= $requestedEndTimestamp) {
                $dateExists = true;
            }
            
            if($dateExists == true) {
                break;
            }
        }
        
        return $dateExists;
    }

    /**
     * Available days = (credit absences added + total_entitlement) - debit_absences
     *
     * @param int $credit
     * @param int $entitled
     * @param int $approved
     * @return int
     */
    protected function available_days($credit, $entitled, $approved) {
        return ($credit + $entitled) - $approved;
    }

    /**
     * Check if we have credit added for that absence type
     *
     * @param string $type
     * @param string $year
     *   The year of the current request
     * @return dataset
     */
    protected function credit_for_absence_type($type, $year) {
        $q = db_select('absence_list', 'al')
            ->condition('contact_id', $_SESSION['CiviCRM']['userID'])
            ->condition('absence_status', 3, '<>')
            ->condition('absence_status', 9, '<>')
            ->condition('is_credit', 1)
            ->condition('absence_start_date', '%' . db_like($year) . '%', 'LIKE')
            ->condition('absence_title', $type);
        $q->addExpression('sum(duration) / (6 * 80)');

        return $q->execute()->fetchField();
    }

    /**
     * The entitlement data of the current user
     *
     * @param int $leave_id
     * @param int $period_id
     * @return array|null
     */
    protected function entitlement_data($leave_id, $period_id) {
        try {
            // Make sure to return with limit 1 as if credit and debit is defined the API returns 2 results as default
            return civicrm_api3('HRAbsenceEntitlement', 'getsingle', array(
                'sequential' => 1,
                'type_id' => $leave_id,
                'contact_id' => $_SESSION['CiviCRM']['userID'],
                'period_id' => $period_id,
                'options' => array('limit' => 1)
            ));
        } catch (\Exception $e) {
            watchdog('exception - entitlement data', print_r($e, true));
            form_set_error('absence_request_date_from', t("No entitlement defined for absence type, or server error!"));

            return null;
        }
    }

    /**
     * Leave data
     *
     * @param array
     */
    protected function leave_data() {
        $data = [];

        foreach (get_civihr_absence_types() as $absence_type) {
            if (isset($absence_type['credit_activity_type_id']) && $absence_type['credit_activity_type_id'] == $this->form_state['values']['absence_request_type']) {
                $data['type'] = $absence_type['title'];
                $data['id'] = $absence_type['id'];
            }

            if (isset($absence_type['debit_activity_type_id']) && $absence_type['debit_activity_type_id'] == $this->form_state['values']['absence_request_type']) {
                $data['type'] = $absence_type['title'];
                $data['id'] = $absence_type['id'];
            }
        }

        return $data;
    }

    /**
     * The period id
     * Checks the date periods and compares to the requested absence start date
     *
     * @param array $start_date
     * @return int
     */
    protected function period_id($start_date) {
        $period_id = null;

        foreach (get_civihr_date_periods() as $date_period) {
            if (strpos($date_period['start_date'], $start_date[0]) !== false) {
                $period_id = $date_period['id'];
            }
        }

        return $period_id;
    }

    /**
     * Processes the attached file, if present
     *
     * @return stdClass
     */
    protected function process_attachment() {
        $attachment = new \stdClass();

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
            $attachment = (object) $saved_file;
        }

        return $attachment;
    }

    /**
     * The list of public holidays defined in the system
     *
     * @return array
     */
    protected function public_holidays() {
        // Get the activity ID for the public holiday activity type
        $holiday_activity_type_id = civicrm_api3('OptionValue', 'getvalue', array(
            'sequential' => 1,
            'name' => 'Public Holiday',
            'return' => 'value'
        ));

        return civicrm_api3('Activity', 'get', array(
            'sequential' => 1,
            'activity_type_id' => $holiday_activity_type_id,
        ));
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
     * The leave whole duration
     *
     * @return float
     *   The duration in days (2 days, 4.5 days, etc)
     */
    protected function request_duration() {
        $duration = 0;

        foreach ($this->form_state['values'] as $s_key => $form_s_val) {
            if (strpos($s_key, '_requested_day_') !== false) {
                $duration += $form_s_val;
            }
        }

        return $duration / (6 * 80);
    }

    /**
     * Shows/hides the 'dates selected' area based on their number
     *
     * @param int $dates_no
     */
    protected function show_hide_selected_dates_section($dates_no) {
        $containing_div = $this->form['absence_request_dates_selected']['#prefix'];
        $hidden = strpos($containing_div, 'hide');

        if ($dates_no > 0 && $hidden) {
            $containing_div = str_replace('hide', '', $containing_div);
        } elseif ($dates_no == 0 && !$hidden) {
            $containing_div = str_replace('class="', 'class="hide"', $containing_div);
        }

        $this->form['absence_request_dates_selected']['#prefix'] = $containing_div;
    }

    /**
     * Validates the attached file, if present (only after final submit)
     */
    protected function validate_attachment() {
        // This check is required because the validate function is called with each ajax refresh
        // eg. start/end date change during absence request
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
    }
}
?>
