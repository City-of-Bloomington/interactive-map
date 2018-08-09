<?php
/**
 * @copyright 2009-2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param $this->mapId ID of the map
 */
use Blossom\Classes\View;

function legendItems($mapId) {
#    foreach ($legendItems as $l) {
        echo '<ul class="legend">';
        echo "<li>TODO: Legend item</li>";
        echo '</ul>';
#    }
}

?>
<section>
    <header>
        <h1>Legend</h1>
    </header>
    <div class="content">
        <?= legendItems($this->mapId) ?>
    </div>
</section>
