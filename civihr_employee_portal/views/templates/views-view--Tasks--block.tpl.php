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
?>
<div class="<?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title) { print $title; } ?>
    <?php print render($title_suffix); ?>

    <?php if ($header): ?>
        <div class="absence-approval-actions">
            <div class="view-header">
                <?php print $header; ?>

                <a href="/civi_tasks/nojs/view_completed" class="ctools-use-modal ctools-modal-civihr-default-style ctools-use-modal-processed chr_action--transparent chr_action--icon--list chr_action--icon--responsive show-complete-tasks">
                    <span>Show completed tasks</span>
                </a>
            </div>
            <?php if ($rows): ?>
                <div class="view-content">
                    <div class="input-group">
                        <input type="text" name="task-filter-contact" id="task-filter-contact" value="" placeholder="Enter name" />
                    </div>
                </div>
            <?php endif; ?>
        </div>
  <?php endif; ?>

    <?php if ($exposed): ?>
        <div class="view-filters">
            <?php print $exposed; ?>
        </div>
    <?php endif; ?>

    <?php if ($attachment_before): ?>
        <div class="attachment attachment-before">
            <?php print $attachment_before; ?>
        </div>
    <?php endif; ?>

    <?php if ($rows): ?>
        <div class="view-content">
            <?php print $rows; ?>
        </div>
    <?php elseif ($empty): ?>
            <div class="view-empty">
                <?php print $empty; ?>
            </div>
    <?php endif; ?>

    <?php if ($pager): ?>
        <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($attachment_after): ?>
        <div class="attachment attachment-after">
            <?php print $attachment_after; ?>
        </div>
    <?php endif; ?>

    <?php if ($more): ?>
        <?php print $more; ?>
    <?php endif; ?>

    <?php if ($footer): ?>
        <div class="view-footer">
            <?php print $footer; ?>
        </div>
    <?php endif; ?>

    <?php if ($feed_icon): ?>
        <div class="feed-icon">
            <?php print $feed_icon; ?>
        </div>
    <?php endif; ?>

</div><?php /* class view */ ?>
