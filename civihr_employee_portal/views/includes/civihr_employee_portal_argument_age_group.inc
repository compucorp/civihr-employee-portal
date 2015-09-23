
<?php

/**
 * Class civihr_employee_portal_argument_age_group
 * Custom argument handler for the age group contextual filters
 */

class civihr_employee_portal_argument_age_group extends views_handler_argument {

    /**
     * Set up the query for this argument.
     *
     * The argument sent may be found at $this->argument.
     */
    function query($group_by = FALSE) {
        $this->ensure_my_table();

        // Get the age groups
        $age_groups = variable_get('age_group_vals');

        if (isset($age_groups) && !empty($age_groups)) {

            foreach (json_decode($age_groups, TRUE) as $age_group) {

                // Find which age group the argument belongs to
                if ($age_group['description'] == $this->argument) {
                    $oldest_birth_age = date('Y-m-d', strtotime("-" . $age_group['end_period'] . " year", time()));
                    $youngest_birth_age = date('Y-m-d', strtotime("-" . $age_group['start_period'] . " year", time()));
                }

            }

        }

        watchdog('highest new', $youngest_birth_age);
        watchdog('lowest new', $oldest_birth_age);

        $this->query->add_where(0, "$this->table_alias.$this->real_field", "$oldest_birth_age", ">=");
        $this->query->add_where(0, "$this->table_alias.$this->real_field", "$youngest_birth_age", "<=");

    }

}