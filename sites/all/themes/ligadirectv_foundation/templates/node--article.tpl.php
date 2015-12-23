<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>>
        <a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php print render($content['field_image']);?>
  <?php if ($display_submitted): ?>
    <div class="posted">
      <?php if ($user_picture): ?>
        <?php print $user_picture; ?>
      <?php endif; ?>
      <?php $user = user_load($uid);?>
      <span>Por: <a href="/users/<?= $user->name ?>" title="Ver perfil del usuario." class="username" xml:lang="" about="/users/liga-directv" typeof="sioc:UserAccount" property="foaf:name" datatype=""><?= $user->name ?></a></span>
      <?php //print $submitted; ?>
      <?php if(isset($user->field_twitter_user_name)): ?>
        <div class="twitter-username">
          <a href="https://twitter.com/@<?php print render($user->field_twitter_user_name['und'][0]['twitter_username']);?>">
            @<?php print render($user->field_twitter_user_name['und'][0]['twitter_username']);?>
          </a>
        </div>
        <div style="display:none"><?php var_dump($submitted) ?></div>
      <?php endif ?>
       - <span><?php
        echo ucfirst(t(date("l", $node->changed))) . " " . date("d/m/Y h:i a", $node->changed) ?></span>
    </div>
  <?php endif; ?>
  <div class="rs">
    <span class='st_fblike_hcount' displayText='Facebook Like'></span>
    <span class='st_facebook_hcount' displayText='Facebook'></span>
    <span class='st_twitter_hcount' displayText='Tweet'></span>
  </div>
  <?php print render($content['body']);?>
</article>
