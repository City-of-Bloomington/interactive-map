<?php
/**
 * @copyright 2015-2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @param Map $this->map
 */
$title = $this->map->getId() ? $this->_('map_edit') : $this->_('map_add');

$fields = ['name', 'alias', 'navigationMarkdown', 'relatedMarkdown'];
foreach ($fields as $f) {
    $get = 'get'.ucfirst($f);
    $$f = parent::escape($this->map->$get());
}
?>
<section>
    <header>
        <h1><?= $title; ?></h1>
    </header>
    <form method="post" action="<?= self::generateUri('maps.update'); ?>" enctype="multipart/form-data">
        <fieldset>
            <input name="id" type="hidden" value="<?= $this->map->getId(); ?>" />
            <?php
                $helper = $this->template->getHelper('field');
                echo $helper->field(['name'=>'name',  'id'=>'name',  'label'=>$this->_('name' ), 'value'=>$name,  'required'=>true]);
                echo $helper->field(['name'=>'alias', 'id'=>'alias', 'label'=>$this->_('alias'), 'value'=>$alias, 'required'=>true]);

                $h = $this->template->getHelper('ButtonLink');
                $downloadButton = $h->buttonLink(
                    self::generateUri('maps.download', ['id'=>$this->map->getId()]),
                    $this->_('download'),
                    'download'
                );
                echo $helper->field([
                    'name'  => 'script',
                    'id'    => 'script',
                    'label' => $this->_('script'),
                    'type'  => 'file',
                    'help'  => $downloadButton
                ]);

                foreach(['navigationMarkdown', 'relatedMarkdown'] as $f) {
                    echo $helper->field(['name'=>$f, 'id'=>$f, 'label'=>$this->_($f), 'type'=>'textarea', 'value'=>$$f]);
                }

                $h = $this->template->getHelper('saveAndCancelButtons');
                echo $h->saveAndCancelButtons(self::generateUri('maps.index'));
            ?>
        </fieldset>
    </form>
</section>
