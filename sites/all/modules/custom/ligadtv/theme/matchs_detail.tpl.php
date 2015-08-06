<div class="gameEstadisticas">
<?php foreach ($matchs as $key => $value) { ?>
  <?php if($value['matchId']==$idMatchs):?>
    <div class="gmStaTeam">
        <div class="ico1"><img src="<?php print $value['competitors'][0]['images']['logo']['T1']['url'];?>"></div>
        <div class="gmStaname"><?php print $value['competitors'][0]['teamName'];?></div>
        <div class="gmStaScore"><?php print $value['competitors'][0]['scoreString'];?></div>
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
    <div class="team-information">
    <div class="title">Eventos del partido</div>
    <?php $competitors = _matchs_competition($idMatchs); ?>
        <?php foreach ($competitors['response']['data'] as $key => $value) {?>
            <div class="action">
                <div class="time"><?php print $value['clock'];?></div>
                <div class="actionType"><?php print t($value['actionType']);?></div>
                <div class="type"><?php print $value['subType'];?></div>
                <div class="team-name"><?php print $value['teamName'];?></div>
                <div class="name"><?php print $value['firstName'];?> <?php print $value['familyName'];?></div>
            </div>
        <?php }?>
    </div>
</div>
