<?php

namespace Drupal\civihr_employee_portal\View;

/**
 * Contains methods common to views. Extend to encapsulate functionality
 * specific to certain views, such as what code should be executed for certain
 * view hooks.
 */
abstract class AbstractView {

  /**
   * This should be defined in child classes.
   *
   * @var string|NULL
   */
  protected static $name = NULL;

  /**
   * @param \view $view
   * @param \views_plugin_query_default $query
   */
  public function alter($view, $query) {
    // do nothing
  }

  /**
   * @return string
   */
  public static function getName() {
    if (NULL === static::$name) {
      throw new \Exception(sprintf('Please define $name in %s', static::class));
    }

    return static::$name;
  }

  /**
   * Takes the where part of a query and returns an array of fields => values
   *
   * @param mixed $part
   *  The $query->where part
   * @param array $fields
   *  An array to store the fields
   */
  public function getWhereFields($part, &$fields) {
    if (isset($part['conditions'])) {
      $part = $part['conditions'];
    }
    if (isset($part['field']) && $part['field'] instanceof \DatabaseCondition) {
      $part = $part['field']->conditions();
    }

    if (isset($part['field'])) {
      $fields[$part['field']] = $part['value'];
    }
    elseif (is_array($part)) {
      foreach ($part as $item) {
        $this->getWhereFields($item, $fields);
      }
    }
  }
}
