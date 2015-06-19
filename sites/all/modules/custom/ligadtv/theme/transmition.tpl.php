<?php
    global $base_url;
    $team1 = !empty($items['transmition'][0]['t1']) ? node_load($items['transmition'][0]['t1']) : '';
    $team2 = !empty($items['transmition'][0]['t1']) ? node_load($items['transmition'][0]['t2']) : '';
    $channel = !empty($items['transmition'][0]['channel']) ? node_load($items['transmition'][0]['channel']) : '';
?>
<?php if(!empty($items)):?>
<div class="transmition">
    <div class="headc21">
            <h3>TRANSMISIÓN POR TELEVISIÓN</h3>
    </div>
    <div class="ccResultField">
        <div class="transccTeams">
            <div class="team">
                <img src="<?php print image_style_url('team',$team1->field_image['und'][0]['uri']);?>">
            </div>
            <div class="vs">
                vs
            </div>
            <div class="team">
                <img src="<?php print image_style_url('team',$team2->field_image['und'][0]['uri']);?>">

            </div>
        </div>
        <p class="ccTrnas">Transmite:</p>
        <img src="<?php print image_style_url('channel',$channel->field_image['und'][0]['uri']);?>">
        <p class="infoTrans"><?php print $items['transmition'][0]['date'];?></p>
        <p class="infoTrans"><?php print taxonomy_term_load($items['transmition'][0]['site'])->name;?></p>
    </div>
</div>
<?php endif ?>
