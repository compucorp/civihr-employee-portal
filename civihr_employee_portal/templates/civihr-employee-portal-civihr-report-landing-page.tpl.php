<ul>
<?php

/**
 * Split the title on ':' to separate the subtitle
 * and add the class .chr_panel__header__subtitle to it.
 *
 * @param string $originalTitle
 * @return string
 */
function setTitleMarkup($originalTitle) {
  $position = strpos($originalTitle, ':') + 1;
  $title = substr($originalTitle, 0, $position);
  $subtitle = '<span class="chr_panel__header-subtitle">' . substr($originalTitle, $position) . '</span>';

  return $title . $subtitle;
}

foreach ($menu as $item):
?>
    <li class="panel-pane pane-block chr_panel chr_panel--small-text">
        <a href="<?php print $item['link_path']; ?>">
            <h2 class="chr_panel__header chr_panel__header--with-border panel-title u-font-size-big"><?php print setTitleMarkup($item['link_title']); ?></h2>
        </a>
        <div class="u-font-size-small">
            <?php print $item['options']['attributes']['title']; ?>
        </div>
    </li>
<?php
endforeach;
?>
</ul>
