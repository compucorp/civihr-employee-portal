<?php

use Drupal\civihr_employee_portal\View\AbstractView;

class HelperFunctionsTest extends PHPUnit_Framework_TestCase {
  protected $sampleWherePart = [
    [
      'conditions' => [
        [
          'field' => 'foo1',
          'value' => 'bar1'
        ],
        [
          'field' => 'foo2',
          'value' => 'bar2'
        ],
      ]
    ],
    [
      'conditions' => [
        [
          'field' => 'foo3',
          'value' => 'bar3'
        ],
        [
          'field' => 'foo4',
          'value' => 'bar4'
        ],
      ]
    ]
  ];

  public function testGetWhereFields() {
    $parts = [];
    $view = $this->getMockForAbstractClass(AbstractView::class);
    $view->getWhereFields($this->sampleWherePart, $parts);
    $expectedCount = 4;
    $this->assertCount($expectedCount, $parts);
    for ($i = 1; $i < $expectedCount + 1; $i++) {
      $this->assertEquals('bar' . $i, $parts['foo' . $i]);
    }
  }

}
