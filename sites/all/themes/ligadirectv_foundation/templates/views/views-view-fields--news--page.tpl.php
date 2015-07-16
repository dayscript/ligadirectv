<div class="content">
  <?php print render($fields['field_image']->content);?>
  <div class="content-title">
    <?php print render($fields['title']->content);?>
  </div>
  <?php print render($fields['body']->content);?>
  <div class="dateCNoti">
    <?php
      print render($fields['created']->content);
      print render($fields['sharethis']->content);
      print render($fields['nid']->content);
    ?>
  </div>
</div>
