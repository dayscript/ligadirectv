<div class="teamCalendar large-12 columns">
  <div class="equipoInfoc3 linksAfS">
      <a class="titleTeamCalendar" href="#">TODOS CONTRA TODOS</a>
  </div>
  <div class="partidos">
    <?php
        $firts=true;
        foreach ($items['calendar'] as $key => $value) {
              if($value['competitors'][0]['teamId'] == $items['node']->field_external_id['und'][0]['value'] || $value['competitors'][1]['teamId'] == $items['node']->field_external_id['und'][0]['value']){
                $stadio = isset($value['venue'])?$value['venue']['venueName']:'';
                $date   = date( 'd-m-Y', strtotime( $value['matchTime'] ));
                $hora   = date( 'H:i', strtotime( $value['matchTime'] ));
                $teamloc=$value['competitors'][0];
                $teamVis=$value['competitors'][1];
                if($value['competitors'][1]['isHomeCompetitor']==1){
                    $teamloc=$value['competitors'][1];
                    $teamVis=$value['competitors'][0];
                }
                print '<div class="bParti p'.$value['poolNumber'].' r'.$value['roundNumber'].' ">
                        <div class="ico1"><img src="'.$teamloc['images']['logo']['T1']['url'].'"></div>
                        <div class="ico2"><img src="'.$teamVis['images']['logo']['T1']['url'].'"></div>
                        <h4>'.$stadio.' - '.$date.' - '.$hora.'</h4>
                        <h3>'.$value['competitors'][0]['clubName'].'  vs '.$value['competitors'][1]['clubName'].'</h3>
                        <h4><a href="http://www.sportingpulse.com/comp_info.cgi?c=11-9529-0-253096-0&a=FIXTURE&compID=271515" target="_blank">Ver estad&iacute;sticas del partido</a></h4>
                    </div>';
              }
        }
    ?>
  </div>
</div>
