<?php $count = 0;?>
<?php foreach ($player as $key => $value) { ?>
  <?php if($value['personId'] == $idPlayer):?>
    <?php if($count == 0):?>
      <div class="playerInfoBig">
        <div class="pipPic">
          <img src="<?=$value['images']['photo']['S1']['url']?>">
        </div>
        <div class="sspib">
          <img src="/<?php print drupal_get_path('module', 'ligadtv');?>/img/escudo.png">
          <img src="/<?php print drupal_get_path('module', 'ligadtv');?>/img/logo_directv_calendario.png">
        </div>
        <?php drupal_set_title('NOMINA');?>
        <div class="cinpib">
          <h3><?=$value['firstName']?> <?=$value['familyName']?></h3>
          <h2><?=$tes['title']?></h2>
          <h3>ESTADÍSTICAS DE LA TEMPORADA</h2>
          <div class="ccInfoPib ccipibFirts">
            PPP: <?= $value['sPoints'] ?>
          </div>
          <div class="ccInfoPib">
            RPG: <?= $value['sReboundsTotalAverage']?>
          </div>
          <div class="ccInfoPib">
            APP: <?= $value['sAssistsPercentage']?>
          </div>
          <div class="ccInfoPib">
            %TC: <?= $value['sThreePointersPercentage']?>
          </div>
          <div class="linepip"></div>
        </div>
      </div>
      <div class="ccsponsor34">
        <img src="/<?php print drupal_get_path('module', 'ligadtv');?>/img/pauta1.png">
        <img src="/<?php print drupal_get_path('module', 'ligadtv');?>/img/pauta2.png">
      </div>
      <div class="space20"></div>
      <?php $count = $count + 1;?>
    <?php endif?>
  <?php endif?>
<?php } ?>
