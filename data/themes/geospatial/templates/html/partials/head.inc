<head>
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="<?= FN1_URL;  ?>/css/default.css" />
    <link rel="stylesheet" href="<?= FN1_URL;  ?>/css/<?= THEME ?>.css" />
    <link rel="stylesheet" href="<?= LEAFLET;  ?>/leaflet.css" />
    <script src="<?= LEAFLET; ?>/leaflet.js"></script>
    <title><?php echo isset($this->title) ? self::escape($this->title) : APPLICATION_NAME; ?></title>
</head>
