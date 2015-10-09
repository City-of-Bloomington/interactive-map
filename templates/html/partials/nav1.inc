<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
use Application\Models\MapsTable;
?>
<div class="nav1">
    <nav class="container">
    <?php
        $a = '<a href="%s">%s</a>';

        $table = new MapsTable();
        $list = $table->find();
        foreach ($list as $map) {
            echo sprintf($a, BASE_URI."?map={$map->getId()}", $map->getName());
        }
    ?>
    </nav>
</div>
