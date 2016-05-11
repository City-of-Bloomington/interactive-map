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
    public function index(array $params)
    {
        $table = new MapsTable();
        $list = $table->find();

        return new \Application\Views\Maps\IndexView(['maps' => $list]);

    }

    public function view(array $params)
    {
        if (!empty($params['id'])) {
            try { $map = new Map($params['id']); }
            catch (\Exception $e) { }
        }
        if (!isset($map)) {
            header('HTTP/1.1 404 Not Found', true, 404);
            $this->template->blocks[] = new Block('404.inc');
            return;
        }

        return new \Application\Views\Maps\DetailView(['map' => $map]);

    }

    public function update(array $params)
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

        return new \Application\Views\Maps\UpdateView(['map' => $map]);

    }

    public function delete($id)
    {
        if (!empty($id)) {
            try {
                $map = new Map($id);
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
    public function download(array $params)
    {
        header('Content-type: application/javascript; charset=utf-8');
        if (!empty($params['id'])) {
            try {
                $map = new Map($params['id']);
                header("Content-Disposition: attachment; filename={$map->getAlias()}.js");
                readfile(APPLICATION_HOME."/public/js/maps/{$map->getInternalFilename()}.js");
                exit();
            }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
        }
        header('HTTP/1.1 404 Not Found', true, 404);
    }
}
