<?php
/**
 * @copyright 2012-2013 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
namespace Application\Controllers;
use Blossom\Classes\Controller;

class IndexController extends Controller
{
	public function index(array $params)
	{
        return new \Application\Views\IndexView();
	}
}
