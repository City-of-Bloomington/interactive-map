<?php
/**
 * @copyright 2015-2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @param Map $this->map
 */
use Michelf\Markdown;
$navigation = Markdown::defaultTransform($this->map->getNavigationMarkdown());
$related    = Markdown::defaultTransform($this->map->getRelatedMarkdown());

$this->template->addToAsset('scripts', BASE_URI."/js/maps/{$this->map->getInternalFilename()}.js");
?>
<div class="navigationMarkdown"><?= $navigation; ?></div>
<p><?= parent::escape($this->map->getDescription()); ?></p>
<div id="map"></div>
<script type="text/javascript">
    // Transfer some constants from PHP to JavaScript.
    // These should be set in the site config.
    var IVY = {
        mapbox_api_key:    '<?= MAPBOX_API_KEY; ?>',
        mapbox_style:      '<?= MAPBOX_STYLE; ?>',
        geoserver:         '<?= GEOSERVER; ?>',
        default_latitude:  '<?= DEFAULT_LATITUDE; ?>',
        default_longitude: '<?= DEFAULT_LONGITUDE; ?>'
    };
</script>
<div class="relatedMarkdown"><?= $related; ?></div>
