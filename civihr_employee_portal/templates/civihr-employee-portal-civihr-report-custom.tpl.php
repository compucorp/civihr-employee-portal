<div id="hrr">
  <?php if (!empty($filters)): ?>
  <div id="js-filters-wrapper" class="panel panel-pane pane-block chr_panel chr_panel--no-padding panel--sliding-body">
      <div ng-controller="FiltersController as filters" class="pane-content">
          <div id="js-filters-btn" class="chr_search-result__header">
              <div class="chr_search-result__total">
                  <i class="chr_search-result__icon glyphicon glyphicon-chevron-down"></i>
                  <span id="js-filters-title-show">Show Filters</span>
                  <span id="js-filters-title-hide" class="hide">Hide Filters</span>
              </div>
          </div>

          <div id="report-filters" class="panel-body-wrap">
              <?php print render($filters); ?>
          </div>
      </div>
  </div>
</div>
  <?php endif; ?>

  <ul class="nav nav-tabs nav-justified nav-tabs-header report-tabs">
  <?php if (!empty($tableUrl)): ?>
      <li role="presentation" class="active"><a class="btn btn-default" data-tab="data">Data</a></li>
  <?php endif; ?>
  <?php if (!empty($jsonUrl)): ?>
      <li role="presentation"><a class="btn btn-default" data-tab="pivot-table">Pivot Table</a></li>
  <?php endif; ?>
  <?php if (!empty($jsonUrl)): ?>
      <li role="presentation"><a class="btn btn-default" data-tab="orb-pivot-table">Orb Pivot Table</a></li>
  <?php endif; ?>
  </ul>

  <div class="report-content panel-pane pane-block chr_panel chr_panel--no-padding">
  <?php if (!empty($tableUrl)): ?>
      <div class="report-block data pane-content">
          <div id="reportTable"><?php print $table; ?></div>
  <?php if (!empty($exportUrl)): ?>
          <div class="chr_panel__footer">
              <div class="chr_actions-wrapper">
                  <a href="<?php print $exportUrl; ?>" id="export-report" class="btn btn-primary btn-default">Export</a>
              </div>
          </div>
  <?php endif; ?>
      </div>
  <?php endif; ?>
  <?php if (!empty($jsonUrl)): ?>
      <div class="report-block pivot-table pane-content hidden">
          <div class="chr_search-result__header">
              <div class="chr_search-result__total">
                  Pivot Table
              </div>
          </div>
          <div id="reportPivotTable" class="pvtTable-civi"></div>
      </div>
      <div class="report-block orb-pivot-table pane-content hidden">
          <div class="chr_search-result__header">
              <div class="chr_search-result__total">
                  Orb Pivot Table (with subtotals)
              </div>
          </div>
          <div id="reportOrbPivotTable"></div>
      </div>
  <?php endif; ?>
  </div>

  <script type="text/javascript">
      CRM.$(function () {
  <?php if (!empty($data)): ?>
          var data = <?php print $data; ?>;
          var initialDerivedAttributes = {};
  <?php if ($report_name === 'people'): ?>
          initialDerivedAttributes = {
              "Employee length of service group": function(row) {
                  var los = parseInt(row['Employee length of service'] / 365, 10);
                  if (los < 1) {
                      return "Under 1 year";
                  }
                  if (los < 2) {
                      return "1 - 2 years";
                  }
                  if (los < 5) {
                      return "2 - 5 years";
                  }
                  if (los < 10) {
                      return "5 - 10 years";
                  }
                  if (los < 15) {
                      return "10 - 15 years";
                  }
                  if (los < 20) {
                      return "15 - 20 years";
                  }
                  return "Over 20 years";
              }
          }
  <?php endif; ?>
          Drupal.behaviors.civihr_employee_portal_reports.instance.init({
              data: data,
              tableContainer: jQuery('#reportTable'),
              pivotTableContainer: jQuery('#reportPivotTable'),
              orbContainer: document.getElementById('reportOrbPivotTable'),
              derivedAttributes: initialDerivedAttributes,
              tableUrl: '<?php print $tableUrl; ?>',
              jsonUrl: '<?php print $jsonUrl; ?>',
              filters: <?php print !empty($filters) ? 1 : 0; ?>
          });
          Drupal.behaviors.civihr_employee_portal_reports.instance.show();
  <?php endif; ?>
      });
  </script>
</div>
