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
            </div>
            <?php if ($rows): ?>
                <div class="view-content panel-panel">
                    <div class="well-small">
                        <div class="form-group">
                            <div class="input-group">
                                <div class="btn input-group-addon"><span class="glyphicon glyphicon-search" aria-hidden="true"></span></div>
                                <input class="form-control" id="manager-approval-search" placeholder="Enter name">
                            </div>
                        </div>
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
        <div class="chr_table-w-filters row">
            <div class="chr_table-w-filters__filters approval-filters col-md-3">
                <div class="chr_table-w-filters__filters__dropdown-wrapper form-item">
                    <select class="chr_table-w-filters__filters__dropdown">
                        <!-- content injected via JS -->
                    </select>
                </div>
                <ul id="tag-list" class="chr_table-w-filters__filters__nav nav nav-pills nav-stacked">
                    <!-- content injected via JS -->
                </ul>
            </div>
            <div class="chr_table-w-filters__table-wrapper col-md-9">
                <div class="chr_table-w-filters__table">
                    <?php print $rows; ?>
                </div>
            </div>
        </div>
    <?php elseif ($empty): ?>
        <div class="view-empty">
            <?php print $empty; ?>
        </div>
    <?php endif; ?>

    <?php if ($pager) { print $pager; } ?>

    <?php if ($attachment_after): ?>
        <div class="attachment attachment-after">
            <?php print $attachment_after; ?>
        </div>
    <?php endif; ?>

    <?php if ($more){ print $more; } ?>

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
