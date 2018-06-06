<?php

namespace Drupal\civihr_employee_portal\Helpers;

use stdClass;

class TaxonomyHelper {

  /**
   * Create HR Resource Type Vocabulary
   */
  public static function createHRRecourceTypeVocabulary() {
    $new_vocab = (object)array(
      'name' => 'HR Resource type',
      'machine_name' => 'hr_resource_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0
    );

    return taxonomy_vocabulary_save($new_vocab);
  }

  /**
   * Create default terms
   */
  public static function createDefaultTerms() {
    self::createTaxonomyTerm('hr_resource_type', 'Policy');
    self::createTaxonomyTerm('hr_resource_type', 'Handbook');
    self::createTaxonomyTerm('hr_resource_type', 'Forms');
    self::createTaxonomyTerm('hr_resource_type', 'Training Manual');
  }

  /**
   * Add Taxonomy Term for a given Vocabulary
   *
   * @param string
   *    Name of Vocabulary
   * @param string
   *    Name of Term
   *
   * @return int/boolean
   *    Created Term ID.
   */
  private static function createTaxonomyTerm($vocabulary_name, $term_name) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
    if ($vocabulary !== FALSE && is_string($term_name) && !taxonomy_get_term_by_name($term_name, $vocabulary_name)) {
      $term = new stdClass();
      $term->name = $term_name;
      $term->vid = $vocabulary->vid;
      taxonomy_term_save($term);

      return $term->tid;
    }

    return FALSE;
  }
}
