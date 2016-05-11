<?php
/**
 * @copyright 2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
namespace Application\Views\Maps;

use Blossom\Classes\Block;
use Blossom\Classes\Template;

class DetailView extends Template
{
    public function __construct(array $vars)
    {
        $format = !empty($_REQUEST['format']) ? $_REQUEST['format'] : 'html';
        parent::__construct('map', $format, $vars);

        $this->blocks['panel1'][] = new Block('maps/searchForm.inc');
        $this->blocks['panel1'][] = new Block('maps/relatedLinks.inc', ['linksMarkdown' => $this->map->getRelatedMarkdown()]);
        $this->blocks[] = new Block('maps/view.inc', ['map'=>$this->map]);

    }
}