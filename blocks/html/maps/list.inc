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
                    BASE_URI.'/maps/update',
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
            $id = $map->getId();
            $url = BASE_URI."/maps/view?map=$id";
            $name = View::escape($map->getName());

            $editButton = $userCanEdit
                ? $helper->buttonLink(BASE_URI."/maps/update?map_id=$id", $this->_('map_edit'), 'edit')
                : '';
            $deleteButton = Person::isAllowed('maps', 'delete')
                ? $helper->buttonLink(BASE_URI."/maps/delete?map_id=$id", $this->_('map_delete'), 'delete')
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