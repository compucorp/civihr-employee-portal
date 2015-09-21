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
            $birthDate = date('Y-m-d', $value);

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
                        $age = '0-1';
                    }
                }

            }

        }

        // Get the defined age groups and check what age group the contact belongs to
        return $age;
    }

}