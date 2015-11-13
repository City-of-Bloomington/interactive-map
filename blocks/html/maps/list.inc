<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param array $this->maps
 */
use Application\Models\Person;
use Blossom\Classes\View;
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
    <table class="fn1-table">
    <?php
        foreach ($this->maps as $map) {
            $id    = $map->getId();
            $url   = self::generateUri('maps.view', ['id'=>$map->getAlias()]);
            $name  = View::escape($map->getName());

            $editButton = $userCanEdit
                ? $helper->buttonLink(self::generateUri('maps.update', ['id'=>$id]), $this->_('map_edit'), 'edit')
                : '';
            $deleteButton = Person::isAllowed('maps', 'delete')
                ? $helper->buttonLink(self::generateUri('maps.delete', ['id'=>$id]), $this->_('map_delete'), 'delete')
                : '';

            $mediaUrl = $map->getMediaUrl();
            $media = $mediaUrl ? "<img src=\"$mediaUrl\" />" : '';

            echo "
            <tr>
                <th scope=\"row\">$name</th>
                <td><a href=\"$url\">View Map</a></td>
                <td>$editButton</td>
                <td>$media</td>
                <td>$deleteButton</td>
            </tr>
            ";
        }
    ?>
    </table>
</section>
