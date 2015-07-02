<?php foreach ($items as $key => $value) {?>
  <?php if($value['matchStatus'] == 'COMPLETE'):?>
    <?php $cont++; ?>
    <?php if($cont < 6): ?>
      <?php
        $stadio = isset($value['venue']) ? $value['venue']['venueName'] : '';
        $date   = date( 'd-m-Y', strtotime( $value['matchTime'] ));
        $hora   = date( 'H:i', strtotime( $value['matchTime'] ));
        $teamloc=$teams[$value['competitors'][0]['clubId']];
        $teamVis=$teams[$value['competitors'][1]['clubId']];
        $teamlocD=$value['competitors'][0];
        $teamVisD=$value['competitors'][1];
        if($value['competitors'][1]['isHomeCompetitor']==1){
            $teamloc=$teams[$value['competitors'][1]['clubId']];
            $teamVis=$teams[$value['competitors'][0]['clubId']];
            $teamlocD=$value['competitors'][1];
            $teamVisD=$value['competitors'][0];
        }
      ?>
      <div class="c1GameHome">
        <div class="cGameHome">
            <img width="25px" src="<?php print $teamloc['images']['logo']['T1']['url']?>">
            <p><?php print $teamlocD['teamCode'] . ' ' . $teamlocD['scoreString'];?></p>
        </div>
        <div class="cGameHome">
            <img width="25px" src="<?php print $teamVis['images']['logo']['T1']['url'];?>">
            <p><?php print $teamVisD['teamCode'].' '.$teamVisD['scoreString'];?></p>
        </div>
        <div class="cdateVerHome">
            <?php print $date; ?>
        </div>
      </div>
    <?php endif ?>
  <?php endif ?>
<?php } ?>
