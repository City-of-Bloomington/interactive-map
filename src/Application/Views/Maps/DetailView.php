<?php
/**
 * @copyright 2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
namespace Application\Views\Maps;

use Blossom\Classes\Block;
use Blossom\Classes\Template;

class DetailView extends Template
{
    public function __construct(array $vars)
    {
        $format = !empty($_REQUEST['format']) ? $_REQUEST['format'] : 'html';
        parent::__construct('default', $format, $vars);

        $this->blocks[] = new Block('maps/view.inc', ['map'=>$this->map]);
    }
}
