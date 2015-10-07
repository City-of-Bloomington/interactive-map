<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
$this->template->addToAsset('scripts', BASE_URI.'/js/map.js');
?>
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
