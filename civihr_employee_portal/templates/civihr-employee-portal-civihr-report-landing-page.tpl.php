<ul>
<?php
foreach ($menu as $item):
?>
    <li class="panel-pane pane-block chr_panel chr_panel--small-text">
        <a href="<?php print $item['link_path']; ?>">
            <h2 class="chr_panel__header chr_panel__header--with-border panel-title u-font-size-big">
              <span class="chr_panel__header-subtitle">
                <?php print $item['link_title']; ?>
              </span>
            </h2>
        </a>
        <div class="u-font-size-small">
            <?php print $item['options']['attributes']['title']; ?>
        </div>
    </li>
<?php
endforeach;
?>
</ul>
