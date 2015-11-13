<head>
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <?php if(defined('THEME')): ?>
        <link rel="stylesheet" href="<?= FN1_URL; ?>/css/default.css" />
    <?php else: ?>
        <link rel="stylesheet" href="<?= FN1_URL; ?>/css/default.css" />
        <link rel="stylesheet" href="<?= FN1_URL; ?>/css/<?= THEME ?>.css" />
    <?php endif ?>
    <link rel="stylesheet" href="<?= LEAFLET; ?>/leaflet.css" />
    <script src="<?= LEAFLET; ?>/leaflet.js"></script>
    <link rel="stylesheet" href="<?= BASE_URI ?>/css/screen.css" />
    <title><?php echo isset($this->title) ? self::escape($this->title) : APPLICATION_NAME; ?></title>
</head>
