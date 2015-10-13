<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Map $this->map
 */
use Blossom\Classes\View;

$title = $this->map->getId() ? $this->_('map_edit') : $this->_('map_add');

$fields = ['name', 'alias', 'navigationMarkdown', 'relatedMarkdown'];
foreach ($fields as $f) {
    $get = 'get'.ucfirst($f);
    $$f = View::escape($this->map->$get());
}
?>
<section>
    <header>
        <h1><?= $title; ?></h1>
    </header>
    <form method="post" action="<?= self::generateUri('maps.update'); ?>" enctype="multipart/form-data">
        <fieldset>
            <input name="id" type="hidden" value="<?= $this->map->getId(); ?>" />
            <dl><dt><label  for="name"><?= $this->_('name'); ?></label></dt>
                <dd><input name="name" id="name" value="<?= $name; ?>" /></dd>
            </dl>
            <dl><dt><label  for="alias"><?= $this->_('alias'); ?></label></dt>
                <dd><input name="alias" id="alias" value="<?= $alias; ?>" /></dd>
            </dl>
            <dl><dt><label  for="script"><?= $this->_('script'); ?></label></dt>
                <dd><input name="script" id="script" type="file" />
                    <a href="<?= self::generateUri('maps.download', ['id'=>$this->map->getId()]); ?>"
                        class="download button">
                        <?= $this->_('download'); ?>
                    </a>
                </dd>
            </dl>
        </fieldset>

        <fieldset><legend><?= $this->_('navigationMarkdown'); ?></legend>
            <textarea name="navigationMarkdown"><?= $navigationMarkdown; ?></textarea>
        </fieldset>

        <fieldset><legend><?= $this->_('relatedMarkdown'); ?></legend>
            <textarea name="relatedMarkdown"><?= $relatedMarkdown; ?></textarea>
        </fieldset>

        <fieldset>
            <?php
                $h = $this->template->getHelper('saveAndCancelButtons');
                echo $h->saveAndCancelButtons(self::generateUri('maps.index'));
            ?>
        </fieldset>
    </form>
</section>