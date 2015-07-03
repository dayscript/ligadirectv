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
      <?php print $submitted; ?>
      <?php $user = user_load($uid);?>
      <?php if(isset($user->field_twitter_user_name)): ?>
        <div class="twitter-username">
          <a href="https://twitter.com/@<?php print render($user->field_twitter_user_name['und'][0]['twitter_username']);?>">
            <?php print render($user->field_twitter_user_name['und'][0]['twitter_username']);?>
          </a>
        </div>
      <?php endif ?>
    </div>
  <?php endif; ?>
  <div class="rs">
    <span class='st_fblike_hcount' displayText='Facebook Like'></span>
    <span class='st_facebook_hcount' displayText='Facebook'></span>
    <span class='st_twitter_hcount' displayText='Tweet'></span>
  </div>
  <?php print render($content['body']);?>
</article>
