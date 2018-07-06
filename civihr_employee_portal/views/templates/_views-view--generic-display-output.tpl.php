<?php

/**
 * @file
 * This a common template which its name does not come from a template
 * suggestion. The `_` was deliberate to point that this template is different,
 * something like a helper for other templates.
 * This template is called from the default views template only for certain
 * views, and was built to mimic a panel block template, to integrate views
 * transparently on panel pages, to re-use current styles for pages like the
 * ones used on dashboard.
 *
 * Variables available:
 * - @var array $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - @var string $classes: A string version of $classes_array for use in the class attribute
 * - @var string $css_name: A css-safe version of the view name.
 * - @var string $css_class: The user-specified classes names, if any
 * - @var string $header: The view header
 * - @var string $footer: The view footer
 * - @var string $rows: The results of the view query, if any
 * - @var string $empty: The empty text to display if the view is empty
 * - @var string $pager: The pager next/prev links to display, if any
 * - @var string $exposed: Exposed widget form/info to display
 * - @var string $feed_icon: Feed icon to display, if any
 * - @var string $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
  $display_options = $view->display['default']->display_options;
  $view_class_comply_with_bem = isset($display_options['css_class']) ? ' ' . check_plain($display_options['css_class']) : '';
  // removes view class to avoid generic view style to interfere with styling
  // also add view class that complies with BEM
  $classes = str_replace('view ', '', $classes) . $view_class_comply_with_bem;
  $title = $view->get_title();
?>
<div class="panel-panel <?php print $classes; ?>">
  <div class="panel-panel-inner">
    <div class="panel-pane pane-block">
      <?php if ($title): ?>
        <h2 class="pane-title">
          <?php print $title; ?>
        </h2>
      <?php endif; ?>
      <div class="pane-content">
        <?php if ($rows): ?>
          <div class="view-content">
            <?php print $rows; ?>
          </div>
        <?php elseif ($empty): ?>
          <div class="view-empty">
            <?php print $empty; ?>
          </div>
        <?php endif; ?>
        <?php if ($footer): ?>
          <div class="chr_panel__footer">
            <div class="chr_actions-wrapper">
              <?php print $footer; ?>
            </div>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
