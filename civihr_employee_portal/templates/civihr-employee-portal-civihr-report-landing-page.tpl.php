<ul>
<?php
foreach ($menu as $item):
?>
    <li>
        <a href="<?php print $item['link_path']; ?>">
            <h2><?php print $item['link_title']; ?></h2>
            <?php print $item['options']['attributes']['title']; ?>
        </a>
    </li>
<?php
endforeach;
?>
</ul>
