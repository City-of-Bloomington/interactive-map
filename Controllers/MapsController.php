<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
namespace Application\Controllers;

use Application\Models\Map;
use Application\Models\MapsTable;
use Blossom\Classes\Block;
use Blossom\Classes\Controller;

class MapsController extends Controller
{
    public function index()
    {
        $table = new MapsTable();
        $list = $table->find();
        $relatedLinks = $table->find('relatedMarkdown');

        $this->template->blocks[] = new Block('maps/list.inc', ['maps'=>$list]);
    }

    public function view()
    {
        if (!empty($_GET['id'])) {
            try { $map = new Map($_GET['id']); }
            catch (\Exception $e) { }
        }
        if (!isset($map)) {
            header('HTTP/1.1 404 Not Found', true, 404);
            $this->template->blocks[] = new Block('404.inc');
            return;
        }

        $this->template->blocks['panel1'][] = new Block('maps/searchForm.inc');
#        if (!empty($map->getLegendMarkdown())) {
            $this->template->blocks['panel1'][] = new Block('maps/viewLegend.inc', ['mapId' => $map->getId()]);
#        }
        $this->template->blocks['panel1'][] = new Block('maps/relatedLinks.inc', ['linksMarkdown' => $map->getRelatedMarkdown()]);
        $this->template->blocks[] = new Block('maps/view.inc', ['map'=>$map]);
    }

    public function update()
    {
        if (!empty($_REQUEST['id'])) {
            try { $map = new Map($_REQUEST['id']); }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
        }
        else { $map = new Map(); }

        if (!isset($map)) {
            header('HTTP/1.1 404 Not Found', true, 404);
            $this->template->blocks[] = new Block('404.inc');
            return;
        }

        if (isset($_POST['id'])) {
            try {
                $map->handleUpdate($_POST, $_FILES);
                $map->save();
                header('Location: '.self::generateUrl('maps.view', ['id'=>$map->getId()]));
                exit();
            }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
        }

        $this->template->blocks[] = new Block('maps/updateForm.inc', ['map'=>$map]);
    }

    public function delete()
    {
        if (!empty($_REQUEST['id'])) {
            try {
                $map = new Map($_REQUEST['id']);
                $map->delete();
            }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
        }
        header('Location: '.self::generateUrl('maps.index'));
        exit();
    }

    /**
     * URL to download the javascript file for a map
     */
    public function download()
    {
        header('Content-type: application/javascript; charset=utf-8');
        if (!empty($_GET['id'])) {
            try {
                $map = new Map($_GET['id']);
                header("Content-Disposition: attachment; filename={$map->getAlias()}.js");
                readfile(APPLICATION_HOME."/public/js/maps/{$map->getInternalFilename()}.js");
                exit();
            }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
        }
        header('HTTP/1.1 404 Not Found', true, 404);
    }

    public function search()
    {
        return;
    }
}
