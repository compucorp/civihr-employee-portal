<?php

namespace Drupal\civihr_employee_portal\Blocks;

class ManagerCalendar {

    /**
     * Manager calendar output block
     * @return string
     */
    public function generateBlock() {

        global $user;
        $current_year = date('Y');

        $calendar_tables = array();

        $months_data = array();

        $uid = $user->uid;

        $managerData = get_civihr_uf_match_data($uid);
        $managerId = $managerData['contact_id'];

        $absencesQuery = '
          SELECT
            aal.employee_id,
            aal.id,
            aal.activity_type_id,
            aal.absence_title,
            aal.duration,
            aal.absence_start_date_timestamp,
            aal.absence_end_date_timestamp,
            absence_status,
            manager_id
          FROM {absence_approval_list} aal
          WHERE absence_status != :cancelled AND
            absence_status != :rejected AND
            YEAR(absence_end_date) = YEAR(CURDATE())';

        $result = db_query($absencesQuery, array('cancelled' => 3, 'rejected' => 9));

        // Result is returned as a iterable object that returns a stdClass object on each iteration
        foreach ($result as $record) {
            $managers = _getManagerContacts($record->employee_id);
            if(!in_array($managerId, $managers)){
              continue;
            }
            $check_start_month = intval(date('n', $record->absence_start_date_timestamp + 3600)); // 1-12
            $check_end_month = intval(date('n', $record->absence_end_date_timestamp + 3600)); // 1-12
            $check_start_day = intval(date('d', $record->absence_start_date_timestamp + 3600));
            $check_end_day = intval(date('d', $record->absence_end_date_timestamp + 3600));

            if ($check_start_month == $check_end_month) {
                $months_data[$check_start_month][$check_start_day][$record->employee_id][$record->id] =
                    array(
                        'name' => get_civihr_contact_data($record->employee_id)['display_name'],
                        'title' => $record->absence_title,
                        'type' => $record->activity_type_id,
                        'start_month' => $check_start_month,
                        'end_month' => $check_end_month,
                        'start_day' => $check_start_day,
                        'end_day' => $check_end_day,
                        'duration' => $record->duration <= 480 ? $record->duration / (6 * 80) . ' day' : $record->duration / (6 * 80) . ' days'
                    );
            }
            else {

                $months_difference = abs($check_end_month - $check_start_month);

                for ($num_of_iterations = 0; $num_of_iterations <= $months_difference; $num_of_iterations++) {

                    $new_end_month = $check_start_month + $num_of_iterations;
                    $new_end_day = cal_days_in_month(CAL_GREGORIAN, $new_end_month, $current_year);

                    if ($num_of_iterations == $months_difference) {
                        $new_end_day = $check_end_day;
                    }

                    if ($num_of_iterations == 0) {
                        $new_start_day = $check_start_day;

                    }
                    else {
                        $new_start_day = 1;

                    }

                    $months_data[$check_start_month+$num_of_iterations][$new_start_day][$record->employee_id][$record->id] =
                        array(
                            'name' => get_civihr_contact_data($record->employee_id)['display_name'],
                            'title' => $record->absence_title,
                            'type' => $record->activity_type_id,
                            'start_month' => $check_start_month + $num_of_iterations,
                            'end_month' => $new_end_month,
                            'start_day' => $new_start_day,
                            'end_day' => $new_end_day,
                            'duration' => $record->duration <= 480 ? $record->duration / (6 * 80) . ' day' : $record->duration / (6 * 80) . ' days'
                        );

                }

            }


        }

        // Get the colour codes from calendar legend
        $view = views_get_view('calendar_absence_list');
        $view->set_display('page_1');
        $row_options = $view->display_handler->get_option('row_options');

        // Save the colour codes (array of absence type ID + colour code)
        $colour_codes = $row_options['colors']['calendar_colors_absence_type'];

        // Loop from current month backwards to January (optionally to set some more specific filters)
        for ($month = 12; $month > 0; $month--) {
            $num_days_month = cal_days_in_month(CAL_GREGORIAN, $month, $current_year);

            // Header
            $header = array(array('class' => 'chr_calendar--manager__header__employee-name', 'data' => t("Employee name")));

            // If the month exist in the months_data array display the values
            if (isset($months_data[$month])) {
                $rows = array();

                for ($i = 0; $i < $num_days_month; $i++) {
                    $s = $i+1;
                    $header[] = array('class' => 'chr_calendar--manager__header__day-of-month', 'data' => $s);

                    foreach ($months_data[$month] as $employee) {
                        
                        foreach ($employee as $empId => $activities) {
                            $employeeId = $empId;
                            foreach ($activities as $key_ac => $activity) {

                                $rows[$employeeId][0] = array(
                                    'class' => 'chr_calendar--manager__employee_name',
                                    'data' => '<div class="' . $activity['name'] . '">' . $activity['name'] . '</div>'
                                );
                                
                                // prevent key overwriting for requested dates
                                if(isset($rows[$employeeId][$s]['style'])){
                                    continue;
                                }
                                
                                if ($activity['start_month'] == $activity['end_month']) {
                                    if ($s >= $activity['start_day'] && $s <= $activity['end_day']) {
                                        $colour_code = !empty($colour_codes[$activity['type']]) ? $colour_codes[$activity['type']] : '#999999';
                                        $rows[$employeeId][$s]['class'] = 'chr_calendar--manager__date chr_calendar--manager__date--filled';
                                        $rows[$employeeId][$s]['style'] = 'background-color: ' . $colour_code . ';';
                                        $rows[$employeeId][$s]['data'] = '<div style="color: #ffffff;" class="views-tooltip stripe" tooltip-content="' . $activity['title'] . ': ' . $activity['duration'] . '">'  . date('D', strtotime($current_year . '/' . $activity['start_month'] . '/' . $s)) . '</div></div>';
                                    }
                                    else {
                                        $rows[$employeeId][$s]['class'] = 'chr_calendar--manager__date';
                                        $rows[$employeeId][$s]['data'] = '';
                                    }
                                }

                            }
                        }

                    }
                }

                $month_name = date('F', mktime(0, 0, 0, $month, 10)); // March

                $calendar_tables[]['title'] = $month_name . ' ' . $current_year;
                $calendar_tables[]['data'] = theme('table', array(
                    'header' => $header,
                    'rows' => $rows,
                    'attributes' => array('class' => 'chr_calendar--manager')
                ));
            }
        }

        $block = module_invoke('calendar', 'block_view', 'calendar_legend');

        // Output the themed calendar
        return theme('civihr_employee_portal_manager_calendar_block',
            array(
                'calendar_output' => $calendar_tables,
                'calendar_legend' => render($block['content'])
            )
        );
    }
}
