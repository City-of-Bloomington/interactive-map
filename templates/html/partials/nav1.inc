<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
use Application\Models\MapsTable;
use Blossom\Classes\View;
?>
<div class="fn1-nav1">
    <nav class="fn1-nav1-container">
    <?php
        $table = new MapsTable();
        $list = $table->find();
        foreach ($list as $map) {
            $name = View::escape($map->getName());
            $url  = self::generateUri('maps.view', ['id'=>$map->getAlias()]);
            echo "<a href=\"$url\">$name</a>";
        }
    ?>
    </nav>
</div>
