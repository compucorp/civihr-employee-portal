<div class="panel-pane pane-block chr_panel chr_panel--no-padding">
  <div class="pane-content">
    <div class="chr_search-result__header">
      <div class="chr_search-result__total">
        Results
        <span class="chr_search-result__total__count"><?php echo count($rows); ?></span>
      </div>
    </div>

    <table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
      <?php if (!empty($title) || !empty($caption)) : ?>
        <caption><?php print $caption . $title; ?></caption>
      <?php endif; ?>
      <?php if (!empty($header)) : ?>
        <thead>
          <tr>
            <?php
            foreach ($header as $field => $label):
              if (false) {
                continue;
              }
            ?>
              <th>
                <?php print $label; ?>
              </th>
            <?php endforeach; ?>
            <th><?php print t('Edit'); ?></th>
            <th><?php print t('Delete'); ?></th>
          </tr>
        </thead>
      <?php endif; ?>
      <tbody>
        <?php foreach ($rows as $row_count => $row): ?>
          <tr class="<?php echo ($row_count % 2 === 0) ? 'odd' : 'even'; ?>">
            <?php
              foreach ($row as $field => $content):
                if ($field === 'id'):
                  continue;
                endif;
            ?>
              <td>
                <?php print strip_tags(html_entity_decode($content)); ?>
              </td>
            <?php endforeach; ?>
            <td>
              <?php if ($canEdit): ?>
                <a href="/reports/settings/age_group/nojs/edit/<?php print strip_tags($row['id']); ?>"
                  class="ctools-use-modal ctools-modal-civihr-custom-style ctools-use-modal-processed">
              <?php endif; ?>
              Edit
              <?php if ($canEdit): ?>
                </a>
              <?php endif; ?>
            </td>
            <td>
              <?php if ($canDelete): ?>
                <a href="/reports/settings/age_group/nojs/delete/<?php print strip_tags($row['id']); ?>"
                  class="ctools-use-modal ctools-modal-civihr-custom-style ctools-use-modal-processed">
              <?php endif; ?>
              Delete
              <?php if ($canDelete): ?>
                </a>
              <?php endif; ?>
            </td>
          </tr>
        <?php endforeach; ?>
      </tbody>
    </table>

    <?php if ($canEdit): ?>
      <div class="chr_panel__footer">
        <div class="chr_actions-wrapper">
          <a href="/reports/settings/age_group/nojs/create" class="chr_action ctools-use-modal ctools-modal-civihr-custom-style ctools-use-modal-processed">Create new Age Group</a>
        </div>
      </div>
    <?php endif; ?>
  </div>
</div>
