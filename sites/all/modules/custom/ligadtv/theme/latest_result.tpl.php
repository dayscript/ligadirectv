<div class="hrNaranjaFull"></div>
<div class="latest-result">
    <div class="headc21">
        <h3>ÚLTIMOS RESULTADOS</h3>
    </div>
    <div class="infocc21">
                <?php foreach ($items[0] as $key => $value) { ?>
            <?php if ($value['matchStatus'] == 'COMPLETE'):?>
                <?php $cont++;?>
                <?php if ($cont < 6): ?>
                    <?php
                        $stadio = isset($value['venue']) ? $value['venue']['venueName'] : '';
                        $date   = date( 'd-m-Y', strtotime( $value['matchTime'] ));
                        $hora   = date( 'H:i', strtotime( $value['matchTime'] ));
                        $teamloc=$teams[$value['competitors'][0]['clubId']];
                        $teamVis=$teams[$value['competitors'][1]['clubId']];
                        $teamlocD=$value['competitors'][0];
                        $teamVisD=$value['competitors'][1];
                    ?>
                    <?php if($value['competitors'][1]['isHomeCompetitor']==1): ?>
                        <?php
                            $teamloc=$teams[$value['competitors'][1]['clubId']];
                            $teamVis=$teams[$value['competitors'][0]['clubId']];
                            $teamlocD=$value['competitors'][1];
                            $teamVisD=$value['competitors'][0];
                        ?>
                    <?php endif;
                        $date = date('d-m-Y', strtotime($value['matchTime']));
                    ?>
                        <div class="headline-<?php print $key; ?>">
                            <div class="ccrsInfo">
                                <div class="ico1"><img width="50px" src="<?php print $teamlocD['images']['logo']['T1']['url'];?>"></div>
                                    <div class="resulMini">
                                        <div class="resulNumber"><?php print $teamlocD['scoreString'];?></div>
                                        <div class="resulRy">-</div>
                                        <div class="resulNumber"><?php print $teamVisD['scoreString'];?></div>
                                    </div>
                                    <div class="ico2"><img width="50px" src="<?php print $teamVisD['images']['logo']['T1']['url']; ?>"></div>
                                    <div class="rsDate">
                                        <?php print $date . ' ' .$hora; ?>
                                    </div>
                            </div>
                        </div>
                    <?php endif; ?>
            <?php endif; ?>
        <?php }?>
        </div>
    <div class="ccLinkResults">
        <a href="/matchs">Ver Todos ></a>
    </div>
</div>
