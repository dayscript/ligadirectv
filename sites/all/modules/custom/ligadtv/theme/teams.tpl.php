<?php if($items['response']['meta']['code'] == 200):?>
  <?php foreach ($items['response']['data'] as $key => $value) { ?>
    <?php if(($key%3)==0):?>
      <div class="small-4 columns item left-item">
      <img src="<?php print $value['images']['logo']['T1']['url'];?>">
      <h3 class="title-team">
        <?php print $value['teamName'];?>
      </h3>
      <span class="detail-team">
        <?php $link = explode('/', $value['linkDetailClub']); ?>
        <a href="teams/<?php print $value['clubName'] . '/' . $link[4];?>">Ver equipo</a>
      </span>
    </div>
    <?php else:?>
      <div class="small-4 columns item">
        <img src="<?php print $value['images']['logo']['T1']['url'];?>">
        <h3 class="title-team">
          <?php print $value['teamName'];?>
        </h3>
        <span class="detail-team">
          <?php $link = explode('/', $value['linkDetailClub']); ?>
          <a href="teams/<?php print $value['clubName'] . '/' . $link[4];?>">Ver equipo</a>
        </span>
      </div>
    <?php endif ?>
  <?php }?>
<?php endif ?>
