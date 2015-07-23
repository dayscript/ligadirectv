<div class="teamInfo">
  <div class="equipoInfoc1">
    <?php foreach ($items as $key => $value) {?>
      <div class="indCC listPlayers">
      <a href="/player/<?php print $value['personId'];?>">
        <?php if(isset($value['images']['photo']['S1']['url'])):?>
          <img src="<?php print $value['images']['photo']['S1']['url'];?>">
        <?php else: ?>
          <img src="/<?php print drupal_get_path('module', 'ligadtv') . '/img/player.jpg';?>">
        <?php endif?>
        <div class="name-player"><?php print ($value['firstName'] . ' ' . $value['familyName']);?></div>
      </a>
    </div>
    <?php } ?>
  </div>
</div>
