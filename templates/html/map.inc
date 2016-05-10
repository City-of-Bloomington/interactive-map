<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<?php $this->_include('partials/head.inc'); ?>
<body>
	<?php $this->_include('partials/header.inc'); ?>
	<main>
        <div class="panel1">
<?= $this->includeBlocks('panel1'); ?>
        </div>
        <?php if($this->includeBlocks('panel2')): ?>
            <div class="resultsPanel">
                <?= $this->includeBlocks('panel2'); ?>
            </div>
        <?php endif ?>
        <?php
            include BLOSSOM.'/errorMessages.php';

            echo $this->includeBlocks();
        ?>
	</main>
	<?php $this->_include('partials/footer.inc'); ?>
</body>
</html>
<?php $this->_include('partials/garbageCollection.inc'); ?>
