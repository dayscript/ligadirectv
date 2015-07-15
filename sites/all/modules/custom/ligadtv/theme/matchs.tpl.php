<?php print_r($rounds);?>
<?php dpm($matchs);?>
<ul class="tabs" data-tab role="tablist">
  <?php foreach ($rounds['response']['data'] as $key => $value) {?>
    <?php if($key == 0 ):?>
      <li class="tab-title active" role="presentational"><a href="#panel2-<?php print $key;?>" role="tab" tabindex="0" aria-selected="true" controls="panel2-<?php print $key;?>"><?php print $value['roundNumber'];?></a></li>
    <?php else:?>
      <li class="tab-title" role="presentational"><a href="#panel2-<?php print $key;?>" role="tab" tabindex="0" aria-selected="true" controls="panel2-<?php print $key;?>"><?php print $value['roundNumber'];?></a></li>
    <?php endif ?>
  <?php }?>
</ul>
<!--<div class="tabs-content">
  <?php foreach ($matchs as $key => $value) {?>
    <?php if($key == 2): ?>
      <section role="tabpanel" aria-hidden="false" class="content active matchs" id="panel2-<?php print $key;?>">
        <?php foreach ($value as $key2 => $values) {?>
          <?php
            $team1 = !empty($values['t1']) ? node_load($values['t1']) : '';
            $team2 = !empty($values['t1']) ? node_load($values['t1']) : '';
          ?>
            <div class="ccResBox p1 r5 large-6 columns" style="display: block;">
              <div class="crbheader">ESTADÍSTICAS DEL PARTIDO &gt;</div>
              <a class="vermas" href="<?php print drupal_get_path_alias('node/' . $values['nid']);?>">
              VER MAS &gt;
              </a>
              <div class="crbTeam">
                  <div class="ico1"><img src="<?php print image_style_url('team',$team1->field_image['und'][0]['uri']);?>"></div>
                  <div class="crbname"><?php print $team1->title;?></div>
              </div>
              <div class="crbVs">
                  <div class="crLine"></div>
              Vs
              </div>
              <div class="crbTeam">
                  <div class="ico1"><img src="<?php print image_style_url('team',$team2->field_image['und'][0]['uri']);?>"></div>
                  <div class="crbname"><?php print $team2->title;?></div>
              </div>
              <div class="crBlueC">
                  <p><?php print $values['date']?></p>
                  <p><?php print $team2->title;?></p>
              </div>
            </div>
        <?php }?>
      </section>
    <?php else :?>
      <section role="tabpanel" aria-hidden="false" class="content matchs" id="panel2-<?php print $key;?>">
      <?php foreach ($value as $key2 => $values) {?>
        <?php
          $team1 = !empty($values['t1']) ? node_load($values['t1']) : '';
          $team2 = !empty($values['t1']) ? node_load($values['t1']) : '';
        ?>
          <div class="ccResBox p1 r5 large-6 columns" style="display: block;">
            <div class="crbheader">ESTADÍSTICAS DEL PARTIDO &gt;</div>
            <a class="vermas" href="<?php print drupal_get_path_alias('node/' . $values['nid']);?>">
            VER MAS &gt;
            </a>
            <div class="crbTeam">
                <div class="ico1"><img src="<?php print image_style_url('team',$team1->field_image['und'][0]['uri']);?>"></div>
                <div class="crbname"><?php print $team1->title;?></div>
            </div>
            <div class="crbVs">
                <div class="crLine"></div>
            Vs
            </div>
            <div class="crbTeam">
                <div class="ico1"><img src="<?php print image_style_url('team',$team2->field_image['und'][0]['uri']);?>"></div>
                <div class="crbname"><?php print $team2->title;?></div>
            </div>
            <div class="crBlueC">
                <p><?php print $values['date']?></p>
                <p><?php print $team2->title;?></p>
            </div>
          </div>
      <?php }?>
    </section>
    <?php endif?>
    <section role="tabpanel" aria-hidden="false" class="content pastidos" id="panel2-<?php print $key;?>">
      <?php foreach ($value as $key2 => $values) {?>
        <?php
          $team1 = !empty($values['t1']) ? node_load($values['t1']) : '';
          $team2 = !empty($values['t1']) ? node_load($values['t1']) : '';
        ?>
          <div class="ccResBox p1 r5" style="display: block;">
            <div class="crbheader">ESTADÍSTICAS DEL PARTIDO &gt;</div>
            <a class="vermas" href="<?php print drupal_get_path_alias('node/' . $values['nid']);?>">
            VER MAS &gt;
            </a>
            <div class="crbTeam">
                <div class="ico1"><img src="<?php print image_style_url('team',$team1->field_image['und'][0]['uri']);?>"></div>
                <div class="crbname"><?php print $team1->title;?></div>
            </div>
            <div class="crbVs">
                <div class="crLine"></div>
            Vs
            </div>
            <div class="crbTeam">
                <div class="ico1"><img src="<?php print image_style_url('team',$team2->field_image['und'][0]['uri']);?>"></div>
                <div class="crbname"><?php print $team2->title;?></div>
            </div>
            <div class="crBlueC">
                <p><?php print $values['date']?></p>
                <p><?php print $team2->title;?></p>
            </div>
          </div>
      <?php }?>
    </section>
  <?php }?>
</div>
-->
