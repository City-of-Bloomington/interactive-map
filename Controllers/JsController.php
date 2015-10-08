<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
namespace Application\Controllers;

use Blossom\Classes\Controller;

class JsController extends Controller
{
    public function index()
    {
    }

    public function map()
    {
        header('Content-type: application/javascript; charset=utf-8');

        $map = !empty($_REQUEST['map']) ? $_REQUEST['map'] : 'default';

        if (file_exists(SITE_HOME."/maps/$map.js")) {
               readfile(SITE_HOME."/maps/$map.js");
        }
        else {
            header('HTTP/1.1 404 Not Found', true, 404);
        }
        exit();
    }
}