<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */

 /*
 * This view is for showing the roles of a contact in My Details page
 * the structure of this view is designed as a container for each row
 * that is why all markup is beign removed and inside the row the
 * structure is built emulating a view container per row (this is done
 * through the view UI)
 * Design: https://projects.invisionapp.com/d/main#/console/13248050/297230123/preview
 */

?>
<?php if ($rows): ?>
  <?php $classes = str_replace('view ','', $classes); ?>
  <div class="<?php print $classes ?>">
    <?php print $rows; ?>
  </div>
<?php endif; ?>
