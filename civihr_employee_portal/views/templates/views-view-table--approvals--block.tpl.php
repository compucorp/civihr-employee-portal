<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */

$approval_table_class = 'manager-approval-main-table tablesaw tablesaw-swipe';

?>

<table <?php if ($classes) { print 'class="'. $classes . ' ' . $approval_table_class . '"'; } ?>data-mode="columntoggle" data-minimap<?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
         
        <?php $data_priority = 0; ?>
        <?php foreach ($header as $field => $label): ?>
          
          <?php //print $field; 
            $data_priority += 1; 
          ?>
          
          <?php if ($field == 'tooltip') { $sortable = ''; $persist = 'data-priority="persist"'; } else { $persist = ''; } ?>
          
          <th <?php if ($header_classes[$field]) { print $persist . ' data-priority=' . "'$data_priority'"; } ?>>
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      
      <?php 
        
        if (trim(strip_tags($row['absence_status']) == 'Awaiting approval')) {
            $row_data_class = strip_tags($row['absence_title']) . ' ' . strip_tags($row['absence_status']);
        }
        else {
            $row_data_class = strip_tags($row['absence_status']);
        }
        
      ?>
      <tr <?php if ($row_classes[$row_count]) { print 'data="approvals-table@' . $row_data_class . '" class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php print $content; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>