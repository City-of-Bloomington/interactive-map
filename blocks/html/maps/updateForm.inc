<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Map $this->map
 */
use Blossom\Classes\View;

$title = $this->map->getId() ? $this->_('map_edit') : $this->_('map_add');
$name = View::escape($this->map->getName());
?>
<section>
    <header>
        <h1><?= $title; ?></h1>
    </header>
    <form method="post" action="<?= BASE_URI; ?>/maps/update" enctype="multipart/form-data">
        <fieldset>
            <input name="map_id" type="hidden" value="<?= $this->map->getId(); ?>" />
            <dl><dt><label  for="name"><?= $this->_('name'); ?></label></dt>
                <dd><input name="name" id="name" value="<?= $name; ?>" /></dd>
            </dl>
            <dl><dt><label  for="script"><?= $this->_('script'); ?></label></dt>
                <dd><input name="script" id="script" type="file" /></dd>
            </dl>
            <?php
                $h = $this->template->getHelper('saveAndCancelButtons');
                echo $h->saveAndCancelButtons(BASE_URI.'/maps');
            ?>
        </fieldset>
    </form>
</section>