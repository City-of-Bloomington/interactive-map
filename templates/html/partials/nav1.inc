<?php
/**
 * @copyright 2015-2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
use Application\Models\MapsTable;
?>
<nav id="nav1">
    <div class="container">
    <?php
        $table = new MapsTable();
        $list = $table->find();
        foreach ($list as $map) {
            $name = parent::escape($map->getName());
            $url  = self::generateUri('maps.view', ['id'=>$map->getAlias()]);
            echo "<a href=\"$url\">$name</a>";
        }
    ?>
    </div>
</nav>
