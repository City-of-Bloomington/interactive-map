<?php
/**
 * @copyright 2015-2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @param array $this->maps
 */
$maps = [];
foreach ($this->maps as $map) {
    $maps[] = [
        'id'          => $map->getId(),
        'name'        => $map->getName(),
        'description' => $map->getDescription(),
        'url'         => self::generateUrl('maps.view', ['id'=>$map->getAlias()])
    ];
}
echo json_encode($maps, JSON_PRETTY_PRINT);
