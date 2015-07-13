<div class="teamInfo">
  <div class="equipoInfoc1">
    <?php foreach ($items as $key => $value) {?>
      <div class="indCC listPlayers">
      <a href="/player/<?php print $value['personId'];?>">
        <img src="<?php print $value['images']['photo']['S1']['url'];?>">
        <div class="name-player"><?php print ($value['firstName'] . ' ' . $value['familyName']);?></div>
      </a>
    </div>
    <?php } ?>
  </div>
</div>
