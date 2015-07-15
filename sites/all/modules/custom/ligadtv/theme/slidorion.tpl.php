<div id="slidorion" class="slidorion large-12">
  <div class="slider">
    <?php foreach ($items[0] as $key => $value) { ?>
      <div class="slide">
        <a href="<?php print $value['nid']?>">
          <?php print $value['fid'];?>
          <div class="bgSlider">
            <div class="sltitle">
              <?php print $value['title'];?>
            </div>
            <div class="sldes">
              <p>
                <?php print $value['body'];?>
              </p>
            </div>
          </div>
        </a>
      </div>
    <?php } ?>
  </div>
  <div class="accordion">
      <?php foreach ($items[0] as $key => $value) { ?>
        <div class="header">
          <a href="<?php print $value['nid']?>"><?php print $value['title'];?></a>
        </div>
        <div class="content">
          <?php print $value['body'];?>
        </div>
      <?php }?>
  </div>
</div>
