<?php

/**
 * Custom views handler field to display age group for the contact based on the birth date
 */
class civihr_employee_portal_handler_age_group extends views_handler_field {

    function render($values) {

        // Init civi so we can use the same function for calculating the age
        civicrm_initialize();

        // Get the birth_date value (timestamp)
        $value = $this->get_value($values);

        // As default we assume the age is not set
        $age = 'not set';

        if (isset($value)) {

            // Birth date based on the timestamp
            //$birthDate = date('Y-m-d', $value);
            $birthDate = $value;

            if ($birthDate < date('Ymd')) {
                $age_array = CRM_Utils_Date::calculateAge($birthDate);
                $age_years = CRM_Utils_Array::value('years', $age_array);
                $age_months = CRM_Utils_Array::value('months', $age_array);

                if (isset($age_years)) {
                    $age = $age_years;
                }
                else {

                    // No age set means contact is less than 1 year old or the birth date is not set at all
                    if (isset($age_months)) {
                        $age = intval(0);
                    }
                }

            }

            // Get the age groups
            $age_groups = variable_get('age_group_vals');

            if (isset($age_groups) && !empty($age_groups)) {

                foreach (json_decode($age_groups, TRUE) as $age_group) {

                    // Find which age group the contact age belongs to
                    if ((int)$age >= (int)$age_group['start_period'] && (int)$age <= (int)$age_group['end_period']) {
                        return $age_group['description'];
                    }

                }

            }

        }

        // Fallback to default
        return $age;
    }

}