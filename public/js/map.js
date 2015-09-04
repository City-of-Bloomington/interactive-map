"use strict";
var mapbox = L.tileLayer('https://api.mapbox.com/v4/' + IVY.mapbox_style + '/{z}/{x}/{y}.png?access_token=' + IVY.mapbox_api_key, {
        maxZoom: 18
    }),
    osm = L.tileLayer('http://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        attribution: 'Map data © <a href="http://openstreetmap.org">OpenStreetMap</a> contributors'
    }),
    parks = L.tileLayer.wms('https://bloomington.in.gov/geoserver/wms', {
        layers: 'publicgis:Parks',
        format: 'image/png',
            transparent: true,
            version: '1.1.1',
            opacity: 0.5
    }),
    trails = L.tileLayer.wms('https://bloomington.in.gov/geoserver/wms', {
        layers: 'publicgis:TrailsAndPaths',
        format: 'image/png',
            transparent: true,
            version: '1.1.1',
            opacity: 1
    }),
    schools = L.tileLayer.wms('https://bloomington.in.gov/geoserver/wms', {
        layers: 'publicgis:Schools',
        format: 'image/png',
            transparent: true,
            version: '1.1.1',
            opacity: 1
    }),
    map = L.map('map', {
        center: [39.169927, -86.536806],
        zoom: 14,
        layers: [mapbox, parks, trails, schools]
    }),
    base    = { 'Mapbox': mapbox, 'OpenStreetMap': osm},
    overlay = { 'Parks': parks, 'Trails': trails, 'Schools': schools};

L.control.layers(base, overlay).addTo(map);
