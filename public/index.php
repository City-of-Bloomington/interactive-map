<?php include('../configuration.inc'); ?>
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
    <link rel="stylesheet" href="<?= LEAFLET; ?>/leaflet.css" />
    <link rel="stylesheet" href="<?= ASSETS_URI; ?>/css/screen.css" />
    <link rel="stylesheet" href="<?= BASE_URI; ?>/css/menu.css" />
    <title></title>
    <script src="<?= LEAFLET; ?>/leaflet.js"></script>
    <style type="text/css">
        #map { width:100%; height:800px; }
    </style>
</head>
<body>
    <header class="cob-siteHeader">
        <div class="cob-siteHeader-container">
            <?php
                include(ASSETS_HOME.'/html/cob-siteHeader-menu.html');
                include(ASSETS_HOME.'/html/cob-siteHeader-logo.html');
            ?>
        </div>
    </header>

    <div id="map"></div>
</body>

<script type="text/javascript" src="<?= BASE_URI; ?>/js/map.js"></script>
<script type="text/javascript" src="<?= BASE_URI; ?>/js/menuLauncher.js"></script>
</html>
