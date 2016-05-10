<?php
/**
 * @copyright 2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param string $this->linksMarkdown
 */
//use Blossom\Classes\View;
use Michelf\Markdown;
?>
<section class="additionalInfoBlock">
<?= Markdown::defaultTransform($this->linksMarkdown); ?>
</section>
