<?php
/**
 * @copyright 2015-2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @param array $this->maps
 */
use Application\Models\Person;
?>
<section>
    <header>
        <h1><?= $this->_(['map', 'maps', 2]); ?></h1>
        <?php
            $userCanEdit = Person::isAllowed('maps', 'update');
            $helper = $this->template->getHelper('buttonLink');
            if ($userCanEdit) {
                echo '<div class="tools">';
                echo $helper->buttonLink(
                    self::generateUri('maps.update'),
                    $this->_('map_add'),
                    'add'
                );
                echo '</div>';
            }
        ?>
    </header>
    <table>
    <?php
        foreach ($this->maps as $map) {
            $id    = $map->getId();
            $url   = self::generateUri('maps.view', ['id'=>$map->getAlias()]);
            $name  = parent::escape($map->getName());

            $editButton = $userCanEdit
                ? $helper->buttonLink(self::generateUri('maps.update', ['id'=>$id]), $this->_('map_edit'), 'edit')
                : '';
            $deleteButton = Person::isAllowed('maps', 'delete')
                ? $helper->buttonLink(self::generateUri('maps.delete', ['id'=>$id]), $this->_('map_delete'), 'delete')
                : '';

            echo "
            <tr><td>$editButton</td>
                <td><a href=\"$url\">$name</a></td>
                <td>$deleteButton</td>
            </tr>
            ";
        }
    ?>
    </table>
</section>
