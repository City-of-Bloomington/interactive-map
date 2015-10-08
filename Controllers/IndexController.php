<?php
/**
 * @copyright 2012-2013 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
namespace Application\Controllers;

use Blossom\Classes\Block;
use Blossom\Classes\Controller;

class IndexController extends Controller
{
	public function index()
	{
        $map = !empty($_REQUEST['map']) ? $_REQUEST['map'] : 'default';
        $this->template->blocks[] = new Block('map.inc', ['map'=>$map]);
	}
}
