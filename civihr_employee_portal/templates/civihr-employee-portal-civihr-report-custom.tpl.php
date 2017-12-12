<div id="civihrReports">
  <?php if (!empty($filters)): ?>
    <div
      ng-controller="FiltersController as filters"
      id="report-filters"
      class="panel panel-pane pane-block chr_panel chr_panel--no-padding panel--sliding-body"
      ng-class="{ 'panel--sliding-body': filters.filtersCollapsed }">
      <div class="pane-content">
        <div class="chr_search-result__header" ng-click="filters.filtersCollapsed = !filters.filtersCollapsed">
          <div class="chr_search-result__total">
            <i
              class="chr_search-result__icon glyphicon glyphicon-chevron-right"
              ng-class="{ 'glyphicon-chevron-right': filters.filtersCollapsed, 'glyphicon-chevron-down': !filters.filtersCollapsed }">
            </i>
            <span ng-class="{ 'hide': !filters.filtersCollapsed }">Show Filters</span>
            <span class="hide" ng-class="{ 'hide': filters.filtersCollapsed }">Hide Filters</span>
          </div>
        </div>

        <div
          class="panel-body-wrap panel-body-wrap--collapse"
          ng-class="{ 'panel-body-wrap--collapse': filters.filtersCollapsed }">
            <?php print render($filters); ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <ul class="nav nav-tabs nav-justified nav-tabs-header report-tabs">
    <?php if (!empty($jsonUrl)): ?>
      <li role="presentation" class="active">
        <a data-tab="report-builder" href="#report-builder">
          <i class="fa fa-bar-chart"></i>
          Report Builder
        </a>
      </li>
    <?php endif; ?>
    <?php if (!empty($tableUrl)): ?>
      <li role="presentation">
        <a data-tab="view-data" href="#view-data">
          <i class="fa fa-table"></i>
          View Data
        </a>
      </li>
    <?php endif; ?>
  </ul>

  <div class="report-content panel-pane pane-block chr_panel chr_panel--no-padding">
    <?php if (!empty($jsonUrl)): ?>
      <div class="report-block report-builder tab-pane">
        <div class="chr_search-result__header">
          <div class="chr_search-result__total">
            Report Builder
          </div>
        </div>
        <div id="reportPivotTableConfiguration">
          <form>
            <div class="form-item">
              Configuration:
            </div>
            <div class="form-item">
              <div class="crm_custom-select">
                <select name="id" class="report-config-select skip-js-custom-select">
                  <option value=""><?php print t('-- select configuration --'); ?></option>
                  <?php if (!empty($configurationList)): ?>
                    <?php foreach ($configurationList as $key => $value): ?>
                      <option value="<?php print $key; ?>"><?php print $value; ?></option>
                    <?php endforeach; ?>
                  <?php endif; ?>
                </select>
                <span class="crm_custom-select__arrow"></span>
              </div>
            </div>
            <?php if (user_access('manage hrreports configuration')): ?>
              <div class="form-item">
                <input type="button" class="report-config-save-btn btn btn-primary" value="<?php print t('Save Report'); ?>">
              </div>
              <div class="form-item">
                <input type="button" class="report-config-save-new-btn btn btn-primary" value="<?php print t('Save As New'); ?>">
              </div>
              <div class="form-item">
                <input type="button" class="report-config-delete-btn btn btn-danger" value="<?php print t('Delete'); ?>">
              </div>
            <?php endif; ?>
          </form>
        </div>
        <div id="reportPivotTable" class="pvtTable-civi"></div>
      </div>
    <?php endif; ?>
    <?php if (!empty($tableUrl)): ?>
      <div class="report-block view-data pane-content hidden">
        <div id="reportTable"><?php print $table; ?></div>
        <?php if (!empty($exportUrl)): ?>
          <div class="chr_panel__footer">
            <div class="chr_actions-wrapper">
              <a href="<?php print $exportUrl; ?>" id="export-report" class="btn btn-primary">Export</a>
            </div>
          </div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </div>

  <script type="text/javascript">
    CRM.$(function () {
      var data = [];
      var initialDerivedAttributes = {};
      <?php if ($reportName === 'people'): ?>
      initialDerivedAttributes = {
        "Employee length of service group": function (row) {
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
      };
      <?php endif; ?>
      Drupal.behaviors.civihr_employee_portal_reports.instance.init({
        reportName: '<?php print $reportName; ?>',
        configurationList: <?php print json_encode($configurationList); ?>,
        data: data,
        tableContainer: jQuery('#reportTable'),
        pivotTableContainer: jQuery('#reportPivotTable'),
        derivedAttributes: initialDerivedAttributes,
        tableUrl: '<?php print $tableUrl; ?>',
        jsonUrl: '<?php print $jsonUrl; ?>',
        filters: <?php print !empty($filters) ? 1 : 0; ?>
      });
      Drupal.behaviors.civihr_employee_portal_reports.instance.show();
    });
  </script>
</div>
