<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>>
        <a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <div class="large-8 columns">
    <?php print render($content['field_image_team']);?>
  </div>
  <div class="large-4 columns">
    <div class="medium-12 columns">
      <?php print render($content['field_city']);?>
    </div>
    <div class="medium-12 columns">
      <?php print render($content['field_stadium']);?>
    </div>
    <div class="medium-12 columns rs">
      <span >
        <img src="/<?php print drupal_get_path('module', 'ligadtv');?>/img/btn_twitter.png" class="rollover" data-rollover="/<?php print drupal_get_path('module', 'ligadtv');?>/img/btn_twitter2.png">
        <?php print render($content['field_twitter']);?>
      </span>
      <span>
        <img src="/<?php print drupal_get_path('module', 'ligadtv');?>/img/btn_facebook.png" class="rollover" data-rollover="/<?php print drupal_get_path('module', 'ligadtv');?>/img/btn_facebook2.png">
        <?php print render($content['field_facebook']);?>
      </span>
    </div>
    <div class="medium-12 columns logo">
    <?php
      $games = getRes();
      $cont = 0;
      foreach ($games as $key => $value) {
                if ($value['matchStatus'] == 'COMPLETE' && ($value['competitors'][0]['competitorId']== $content['field_external_id']['#items'][0]['value'] || $value['competitors'][1]['competitorId']==$content['field_external_id']['#items'][0]['value'])) {
                    if($value['competitors'][0]['competitorId'] == $content['field_external_id']['#items'][0]['value']){
                      if($cont == 0){
                        print ('<img src="'. $value['competitors'][0]['images']['logo']['T1']['url'] . '" >');
                      }
                    }elseif ($value['competitors'][1]['competitorId'] == $content['field_external_id']['#items'][0]['value']) {
                      if($cont == 0){
                        print ('<img src="'. $value['competitors'][1]['images']['logo']['T1']['url'] . '" >');
                      }
                    }
                    $cont++;
                }
            }
    ?>
    </div>
  </div>
  <div class="large-12 columns second-title">
    <?php print $title; ?>
  </div>
  <ul class="tabs horizontal large-12 columns indicator-team" data-tab>
    <li class="tab-title active large-3 columns"><a href="#news"><?php print t('News'); ?></a></li>
    <li class="tab-title large-3 columns"><a href="#nomina"><?php print t('Payroll');?></a></li>
    <li class="tab-title large-3 columns"><a href="#history"><?php print t('History');?></a></li>
    <li class="tab-title large-3 columns"><a href="#calendar"><?php print t('Calendar');?></a></li>
  </ul>
  <div class="tabs-content">
    <div class="content active" id="news">
       <div class="slide large-6 columns">
        <?php
          $news = block_load('ligadtv', 'news_team');
          $block = _block_get_renderable_array(_block_render_blocks(array($news)));
          $output = drupal_render($block);
          print($output);
        ?>
       </div>
       <div class="large-3 columns next-macth">
          <div class="headrsc21">
              <h3>PRÓXIMOS PARTIDOS</h3>
          </div>
          <div class="cc21ListPartidos">
            <?php
              $data = getCalComplete();
              $cont = 0;
              if(!empty($data)){
                foreach ($data as $key => $value) {
                  if ($value['competitors'][0]['competitorId'] == $content['field_external_id']['#items'][0]['value'] || $value['competitors'][1]['competitorId'] == $content['field_external_id']['#items'][0]['value']) {
                        $cont++;
                        if ($cont < 6) {
                            $stadio = isset($value['venue']) ? $value['venue']['venueName'] : '';
                            $date = date('d-m-Y', strtotime($value['matchTime']));
                            if ($value['competitors'][0]['isHomeCompetitor'] == 1) {
                                echo '<div class="cc21Partido">
                                <h4>' . $value['competitors'][0]['clubName'] . ' vs ' . $value['competitors'][1]['clubName'] . '</h4>
                                <h5>' . $stadio . ' - ' . $date . '</h5>
                              </div>';
                            } else {
                                echo '<div class="cc21Partido">
                                <h4>' . $value['competitors'][1]['clubName'] . ' vs ' . $value['competitors'][0]['clubName'] . '</h4>
                                <h5>' . $stadio . ' - ' . $date . '</h5>
                              </div>';
                            }
                        }
                    }
                }
              }else{
                echo '<div class="message-no-match">No hay partidos programados aún</div>';
              }
            ?>
          </div>
       </div>
       <div class="large-3 columns latest-results">
          <div class="headrsc21">
            <h3>ÚLTIMOS RESULTADOS</h3>
        </div>
        <div class="cc21ListResultados">
            <div>
            <?php
            $games = getRes();
            $cont = 0;
            foreach ($games as $key => $value) {
                if ($value['matchStatus'] == 'COMPLETE' && ($value['competitors'][0]['competitorId']== $content['field_external_id']['#items'][0]['value'] || $value['competitors'][1]['competitorId']==$content['field_external_id']['#items'][0]['value'])) {
                    $cont++;
                    if ($cont < 6) {
                        $stadio = isset($value['venueName']) ? $value['venueName'] : '';
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
                        $date = date('d-m-Y', strtotime($value['matchTime']));
                         print '<div class="resultsListTeams">
                                <div class="teamResMn">
                                    <div class="ico1">'.$teamloc['clubName'].'</div>
                                    <div class="resulMini">
                                        <div class="resulNumber">'.$teamlocD['scoreString'].'</div>
                                        <div class="resulRy">vs</div>
                                        <div class="resulNumber">'.$teamVisD['scoreString'].'</div>
                                    </div>
                                    <div class="ico1">'.$teamVis['clubName'].'</div>
                                </div>
                                <div class="rsDateTeam">
                                '.$date.' '.$hora.'
                                </div>
                            </div>';

                    }
                }
            }
            ?>
            </div>
       </div>
     </div>
    </div>
    <div class="content payroll" id="nomina">
      <?php
        $payroll = block_load('ligadtv', 'payroll');
        $block = _block_get_renderable_array(_block_render_blocks(array($payroll)));
        $output = drupal_render($block);
        print($output);
      ?>
    </div>
    <div class="content history" id="history">
      <?php print render($content['body']);?>
    </div>
    <div class="content calendar" id="calendar">
      <?php
        $calendar = block_load('ligadtv', 'calendar_team');
        $block = _block_get_renderable_array(_block_render_blocks(array($calendar)));
        $output = drupal_render($block);
        print($output);
      ?>
    </div>
  </div>
</article>
