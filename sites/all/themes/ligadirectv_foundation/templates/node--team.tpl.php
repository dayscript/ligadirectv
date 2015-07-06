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
      <span>
        <?php print render($content['field_twitter']);?>
      </span>
      <span>
        <?php print render($content['field_facebook']);?>
      </span>
    </div>
  </div>
  <div class="large-12 columns">
    <?php print $title; ?>
  </div>
  <ul class="tabs horizontal" data-tab>
    <li class="tab-title active"><a href="#news"><?php print t('News'); ?></a></li>
    <li class="tab-title"><a href="#nomina"><?php print t('Payroll');?></a></li>
    <li class="tab-title"><a href="#panel31">Tab 3</a></li>
    <li class="tab-title"><a href="#panel41">Tab 4</a></li>
  </ul>
  <div class="tabs-content">
    <div class="content active" id="news">
      <p>This is the first panel of the basic tab example. You can place all sorts of content here including a grid.</p>
    </div>
    <div class="content" id="nomina">
      <?php
        $payroll = block_load('ligadtv', 'payroll');
        $block = _block_get_renderable_array(_block_render_blocks(array($payroll)));
        $output = drupal_render($block);
        print($output);
      ?>
    </div>
    <div class="content" id="panel31">
      <p>This is the third panel of the basic tab example. This is the third panel of the basic tab example.</p>
    </div>
    <div class="content" id="panel41">
      <p>This is the fourth panel of the basic tab example. This is the fourth panel of the basic tab example.</p>
    </div>
  </div>
  <?php print render($content['body']);?>
</article>
