<?php drupal_set_title('RESULTADOS');?>
<ul class="tabs" data-tab role="tablist">
  <?php foreach ($rounds['response']['data'] as $key => $value) {?>
    <?php $rounds2[$key] = $value['roundNumber'];?>
  <?php }?>
  <?php
  sort($rounds2);
  $rounds2 = array_unique($rounds2);
  foreach ($rounds2 as $key => $value) { ?>
    <?php if($key == 0 ):?>
      <li class="tab-title active" role="presentational"><a href="#panel2-<?php print $value;?>" role="tab" tabindex="0" aria-selected="true" controls="panel2-<?php print $value;?>"><?php print $value;?></a></li>
    <?php else:?>
      <li class="tab-title" role="presentational"><a href="#panel2-<?php print $value;?>" role="tab" tabindex="0" aria-selected="true" controls="panel2-<?php print $value;?>"><?php print $value;?></a></li>
    <?php endif ?>
  <?php }?>
</ul>
<div class="tabs-content">
  <?php foreach ($rounds2 as $key => $value) {?>
    <?php if($value == 1):?>
      <section role="tabpanel" aria-hidden="false" class="content active matchs" id="panel2-<?php print $value;?>">
        <?php foreach ($matchs['response']['data'] as $keyM => $valueM) {?>
            <?php if($value == $valueM['roundNumber']):?>
              <div class="ccResBox p1 r5 large-6 columns" style="display: block;">
                <div class="crbheader">ESTADÍSTICAS DEL PARTIDO &gt;</div>
                <a class="vermas" href="/matchs/<?php print $valueM['matchId'];?>">VER MAS &gt;</a>
                <div class="crbTeam">
                      <div class="ico1"><img src="<?php print $valueM['competitors'][0]['images']['logo']['T1']['url'];?>"></div>
                      <div class="crbname"><?php print $valueM['competitors'][0]['teamName'];?></div>
                  </div>
                  <div class="crbVs">
                      <div class="crLine"></div>
                  Vs
                  </div>
                  <div class="crbTeam">
                      <div class="ico1"><img src="<?php print $valueM['competitors'][1]['images']['logo']['T1']['url'];?>"></div>
                      <div class="crbname"><?php print $valueM['competitors'][1]['teamName'];?></div>
                  </div>
                  <div class="crBlueC">
                      <p><?php print $valueM['matchTime']?></p>
                      <p><?php print $valueM['venue']['venueName'];?></p>
                  </div>
              </div>
            <?php endif?>
        <?php } ?>
      </section>
    <?php else: ?>
      <section role="tabpanel" aria-hidden="false" class="content matchs" id="panel2-<?php print $value;?>">
        <?php foreach ($matchs['response']['data'] as $keyM => $valueM) {?>
            <?php if($value == $valueM['roundNumber']):?>
              <div class="ccResBox p1 r5 large-6 columns" style="display: block;">
                <div class="crbheader">ESTADÍSTICAS DEL PARTIDO &gt;</div>
                <a class="vermas" href="/matchs/<?php print $valueM['matchId'];?>">VER MAS &gt;</a>
                <div class="crbTeam">
                      <div class="ico1"><img src="<?php print $valueM['competitors'][0]['images']['logo']['T1']['url'];?>"></div>
                      <div class="crbname"><?php print $valueM['competitors'][0]['teamName'];?></div>
                  </div>
                  <div class="crbVs">
                      <div class="crLine"></div>
                  Vs
                  </div>
                  <div class="crbTeam">
                      <div class="ico1"><img src="<?php print $valueM['competitors'][1]['images']['logo']['T1']['url'];?>"></div>
                      <div class="crbname"><?php print $valueM['competitors'][1]['teamName'];?></div>
                  </div>
                  <div class="crBlueC">
                      <p><?php print $valueM['matchTime']?></p>
                      <p><?php print $valueM['venue']['venueName'];?></p>
                  </div>
              </div>
            <?php endif?>
        <?php } ?>
      </section>
    <?php endif ?>
  <?php }?>
</div>
