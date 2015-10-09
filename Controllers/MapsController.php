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

        $this->template->blocks[] = new Block('maps/list.inc', ['maps'=>$list]);
    }

    public function view()
    {
        if (!empty($_GET['map'])) {
            try { $map = new Map($_GET['map']); }
            catch (\Exception $e) { }
        }
        if (!isset($map)) {
            header('HTTP/1.1 404 Not Found', true, 404);
            $this->template->blocks[] = new Block('404.inc');
            return;
        }

        $this->template->blocks[] = new Block('maps/view.inc', ['map'=>$map]);
    }

    public function update()
    {
        if (!empty($_REQUEST['map_id'])) {
            try { $map = new Map($_REQUEST['map_id']); }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
        }
        else { $map = new Map(); }

        if (!isset($map)) {
            header('HTTP/1.1 404 Not Found', true, 404);
            $this->template->blocks[] = new Block('404.inc');
            return;
        }

        if (isset($_POST['map_id'])) {
            try {
                $map->handleUpdate($_POST, $_FILES);
                $map->save();
                header('Location: '.BASE_URL.'/maps/view?map='.$map->getId());
                exit();
            }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
        }

        $this->template->blocks[] = new Block('maps/updateForm.inc', ['map'=>$map]);
    }

    public function delete()
    {
        if (!empty($_REQUEST['map_id'])) {
            try {
                $map = new Map($_REQUEST['map_id']);
                $map->delete();
            }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
        }
        header('Location: '.BASE_URL.'/maps');
        exit();
    }
}