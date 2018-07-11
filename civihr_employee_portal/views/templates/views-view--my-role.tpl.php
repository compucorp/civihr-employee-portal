<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - @var array $classes_array
 *        An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - @var string $classes
 *        A string version of $classes_array for use in the class attribute
 * - @var string $css_name
 *        A css-safe version of the view name.
 * - @var string $css_class
 *        The user-specified classes names, if any
 * - @var string $header
 *        The view header
 * - @var string $footer
 *        The view footer
 * - @var string $rows
 *        The results of the view query, if any
 * - @var string $empty
 *        The empty text to display if the view is empty
 * - @var string $pager
 *        The pager next/prev links to display, if any
 * - @var string $exposed
 *        Exposed widget form/info to display
 * - @var string $feed_icon
 *        Feed icon to display, if any
 * - @var string $more
 *        A link to view more, if any
 *
 * @ingroup views_templates
 */

 /*
 * This view is for showing the roles of a contact in My Details page
 * the structure of this view is designed as a container for each row
 * that is why all markup is beign removed and inside the row the
 * structure is built emulating a view container per row (this is done
 * through the view UI)
 */
?>
<?php if ($rows): ?>
  <?php $classes = str_replace('view ','', $classes); ?>
  <div class="<?php print $classes ?>">
    <?php print $rows; ?>
  </div>
<?php endif; ?>
