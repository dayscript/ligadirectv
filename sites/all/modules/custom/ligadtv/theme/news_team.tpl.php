<ul class="example-orbit" data-orbit>
  <?php foreach ($items as $key => $value) {?>
    <li>
      <?php print $value['img'];?>
      <div class="orbit-caption">
        <h2>
          <?php print $value['title'];?>
        </h2>
        <span>
          <?php print $value['body'];?>
        </span>
      </div>
    </li>
  <?php }?>
</ul>
