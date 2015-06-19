<div class="hrNaranjaFull"></div>
<div class="cc21 mc21 next_macth">
    <div class="headc21">
        <h3>PRÓXIMOS PARTIDOS</h3>
        <a href="partidos">Calendario ></a>
    </div>
    <div class="cc21ListPartidos">
        <?php
            $cont = 0;
            foreach ($items[0] as $key => $value) { ?>
                <?php if($value['matchStatus'] == 'SCHEDULED'):?>
                   <?php $cont++;?>
                    <?php if($cont < 7):?>
                        <?php
                            $stadio = isset($value['venue']) ? $value['venue']['venueName'] : '';
                            $date   = date('d-m-Y', strtotime($value['matchTime']));
                        ?>
                        <?php if ($value['competitors'][0]['isHomeCompetitor'] == 1): ?>
                            <div class="cc21Partido">
                                <h4>
                                    <?php print $value['competitors'][0]['clubName']; ?>
                                    vs
                                    <?php print $value['competitors'][1]['clubName'];?>
                                </h4>
                                <h5><?php print $stadio ?> - <?php print $date ?></h5>
                            </div>
                        <?php else: ?>
                            <div class="cc21Partido">
                                <h4>
                                    <?php print $value['competitors'][1]['clubName']; ?>
                                    vs
                                    <?php print $value['competitors'][0]['clubName']; ?>
                                </h4>
                                <h5><?php print $stadio ?> - <?php print $date ?></h5>
                            </div>
                       <?php endif ?>
                    <?php endif ?>
                <?php endif ?>
        <?php }?>
    </div>
    <div class="c21Imglogo">
        <img src="<?php print drupal_get_path('module', 'ligadtv') . '/'?>img/logo_directv_calendario.png">
    </div>
</div>
