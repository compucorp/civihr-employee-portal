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
    $from = intval(strtotime($this->value['min'], $query_substitutions['***CURRENT_TIME***']));
    $to = intval(strtotime($this->value['max'], $query_substitutions['***CURRENT_TIME***']));

    $from = date('Y-m-d', $from);
    $to = date('Y-m-d', $to);

    $operator = strtoupper($this->operator);
    $this->query->add_where_expression($this->options['group'], "$field $operator '$from' AND '$to'");
  }
}
