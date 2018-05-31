<?php
/**
 * @file
 * A filter that allows the between operator to compare dates in 'Y-m-d' format
 * rather than the default timestamp comparison since absence dates are stored
 * in 'Y-m-d' format in the db.
 */

class views_between_operation_dates_filter_handler extends views_handler_filter_date {
  function op_between($field) {
    // Use the substitutions to ensure a consistent timestamp.
    $query_substitutions = views_views_query_substitutions($this->view);
    $a = intval(strtotime($this->value['min'], $query_substitutions['***CURRENT_TIME***']));
    $b = intval(strtotime($this->value['max'], $query_substitutions['***CURRENT_TIME***']));

    $a = date('Y-m-d', $a);
    $b = date('Y-m-d', $b);

    // This is safe because we are manually scrubbing the values.
    // It is necessary to do it this way because $a and $b are formulas when using an offset.
    $operator = strtoupper($this->operator);
    $this->query->add_where_expression($this->options['group'], "$field $operator '$a' AND '$b'");
  }
}
