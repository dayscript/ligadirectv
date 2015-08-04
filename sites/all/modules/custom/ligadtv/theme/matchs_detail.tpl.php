<div class="gameEstadisticas">
<?php foreach ($matchs as $key => $value) { ?>
  <?php if($value['matchId']==$idMatchs):?>
    <?php dpm($value);?>
    <div class="gmStaTeam">
        <div class="ico1"><img src="<?php print $value['competitors'][0]['images']['logo']['T1']['url'];?>"></div>
        <div class="gmStaname"><?php print $value['competitors'][0]['teamName'];?></div>
        <div class="gmStaScore"><?print $value['competitors'][0]['scoreString'];?></div>
    </div>
    <div class="vs">
    Vs
    </div>
    <div class="gmStaTeam">
        <div class="gmStaScore"><?php print $value['competitors'][1]['scoreString'];?></div>
        <div class="gmStaname"><?php print $value['competitors'][1]['teamName'];?></div>
        <div class="ico1"><img src="<?php print $value['competitors'][1]['images']['logo']['T1']['url'];?>"></div>
    </div>
    <div class="ccStaInfoC large-12 columns">
        <p><?php print $prGame['venue'] . date( 'H:i', strtotime( $value['matchTime'] )) . date( 'd-m-Y', strtotime( $value['matchTime'] ))?> </p>
    </div>
    <div class="large-12 columns titleEsGm">
        <?php print $value['competitors'][0]['teamName'];?>
    </div>
    <div class="large-12 columns titleEsGm final">
        <?php print $value['competitors'][1]['teamName'];?>
    </div>
  <?php endif?>
<?php } ?>
</div>
