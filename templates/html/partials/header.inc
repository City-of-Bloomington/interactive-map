<?php
use Blossom\Classes\View;
?>
<header class="fn1-siteHeader">
    <div class="fn1-siteHeader-container">
        <div class="fn1-site-title">
            <h1><a href="<?php echo BASE_URI; ?>"><?php echo View::escape(APPLICATION_NAME); ?></a></h1>
            <div class="fn1-site-location" id="location_name">
                <a href="<?php echo BASE_URI; ?>">City of Bloomington, Mark Kruzan, Mayor</a>
            </div>
        </div>
        <div class="fn1-site-utilityBar">
        <?php
            $this->addToAsset('scripts', BASE_URI.'/js/menus.js');

            $this->_include('/partials/panel-widgets/User_menu.inc');
            $this->_include('/partials/panel-widgets/Administrator_menu.inc');
        ?>
        </div>
    </div>
</header>
