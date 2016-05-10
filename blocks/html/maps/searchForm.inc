<?php
/**
 * @copyright 2009-2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
use Blossom\Classes\View;
?>
<form action="<?= self::generateUri('maps.search');  ?>" class="searchForm">
    <label>

        <!-- TODO: Replace ITEMS below with the plural form of the result type returned by the search -->
        <span><?= sprintf($this->_('searchForItems', 'labels'), 'ITEMS'); ?></span>
        <input type="text" />
    </label>
</form>
