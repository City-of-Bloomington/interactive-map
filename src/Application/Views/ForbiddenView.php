<?php
/**
 * @copyright 2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE
 */
namespace Application\Views;

use Blossom\Classes\Template;

class ForbiddenView extends Template
{
    public function __construct(array $vars=null)
    {
        header('HTTP/1.1 403 Forbidden', true, 403);

        parent::__construct('default', 'html', $vars);
    }
}
