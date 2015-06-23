<?php
  print render($fields['field_image']->content);
  print render($fields['title']->content);
  print render($fields['body']->content);
?>
<div class="dateCNoti">
  <?php
    print render($fields['created']->content);
    print render($fields['sharethis']->content);
    print render($fields['nid']->content);
  ?>
</div>
