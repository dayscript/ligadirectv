<div class="infoTopHeader noPhone">
    <?php
        $cont = 0;
        foreach ($items[0] as $key => $value) {
            if ($value['matchStatus'] == 'COMPLETE') {
                $cont++;
                if ($cont < 6) {
                    $stadio = isset($value['venue']) ? $value['venue']['venueName'] : '';
                    $date   = date( 'd-m-Y', strtotime( $value['matchTime'] ));
                    $hora   = date( 'H:i', strtotime( $value['matchTime'] ));
                    $teamloc=$teams[$value['competitors'][0]['clubId']];
                    $teamVis=$teams[$value['competitors'][1]['clubId']];
                    $teamlocD=$value['competitors'][0];
                    $teamVisD=$value['competitors'][1];
                    if($value['competitors'][1]['isHomeCompetitor']==1){
                        $teamloc=$teams[$value['competitors'][1]['clubId']];
                        $teamVis=$teams[$value['competitors'][0]['clubId']];
                        $teamlocD=$value['competitors'][1];
                        $teamVisD=$value['competitors'][0];
                    }
                    // print_r($teamloc);
                    $date = date('d-m-Y', strtotime($value['matchTime']));
                    echo '<div class="c1GameHome">
                        <div class="cGameHome">
                            <img width="25px" src="'.$teamloc['images']['logo']['T1']['url'].'">
                            <p>'.$teamlocD['teamCode'].' '.$teamlocD['scoreString'].'</p>
                        </div>
                        <div class="cGameHome">
                            <img width="25px" src="'.$teamVis['images']['logo']['T1']['url'].'">
                            <p>'.$teamVisD['teamCode'].' '.$teamVisD['scoreString'].'</p>
                        </div>
                        <div class="cdateVerHome">
                            '.$date.'
                            <a href="#">Ver mas></a>
                        </div>
                    </div>';

                }
            }
        }
    ?>
    <img class="img01" src="img/logo_dpb.png">
    <img class="img02" src="img/logo_fiba.png">
</div>
<div class="ccEstadisticas">
  <div class="space20"></div>
    <div class="title">
        <h1>
            ESTADÍSTICAS
        </h1>
    </div>
    <div class="space20"></div>
    <div class="navEstadisticas noPhone">
    <a href="estadisticas.php">
        <div class="linkEstadisticas active">
            LÍDERES INDIVIDUALES
        </div>
    </a>
    <a href="estadisticas-posiciones.php">
        <div class="linkEstadisticas">
            TABLA DE POSICIONES
        </div>
    </a>
</div>
<div class="space20"></div>
<div class="hrNaranjaFull"></div>
<div class="cc21 ccTablePlayers">
    <div class="headc21">
        <h3>MEDIA DE PUNTOS</h3>
    </div>
    <?php
        $points=getLeaderPoints();
        print drawLeader($points,$players,$teams,'sPointsAverage','MP');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>MEDIA REBOTES</h3>
    </div>
    <?php
        $points=getLeaderPointsRebotes();
        print drawLeader($points,$players,$teams,'sReboundsTotalAverage','REBM');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>MEDIA ASISTENCIAS</h3>
    </div>
    <?php
        $points=getLeaderMediaAsistencias2();
        print drawLeader($points,$players,$teams,'sAssistsAverage','MAS');
    ?>
</div>
<div class="space20"></div>
<div class="cc21 ccTablePlayers">
    <div class="headc21">
        <h3>TL PORCENTAJE</h3>
    </div>
    <?php
        $points=getLeaderTlPorcentaje();
        print drawLeader($points,$players,$teams,'sFreeThrowsPercentage','TL');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>3 PORCENTAJE</h3>
    </div>
    <?php
        $points=getLeader3Porcentaje();
        print drawLeader($points,$players,$teams,'sFreeThrowsPercentage','T3');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>2 PORCENTAJE</h3>
    </div>
    <?php
        $points=getLeader2Porcentaje();
        print drawLeader($points,$players,$teams,'sTwoPointersPercentage','T2');
    ?>
</div>
<div class="space20"></div>
<div class="cc21 ccTablePlayers">
    <div class="headc21">
        <h3>PUNTOS</h3>
    </div>
    <?php
        $points=getLeaderPuntos();
        print drawLeader($points,$players,$teams,'sPoints','PT');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>REBOTES TOTALES</h3>
    </div>
    <?php
        $points=getLeaderPointsSecondChance();
        print drawLeader($points,$players,$teams,'sReboundsTotal','RT');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>ASISTENCIAS</h3>
    </div>
    <?php
        $points=getLeaderAssists();
        print drawLeader($points,$players,$teams,'sAssists','AS');
    ?>
</div>
<div class="space20"></div>
<div class="cc21 ccTablePlayers">
    <div class="headc21">
        <h3>REBOTES OFENSIVOS</h3>
    </div>
    <?php
        $points=getLeaderReboundsOffensive();
        drawLeader($points,$players,$teams,'sReboundsOffensive','RO');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>REBOTES DEFENSIVOS</h3>
    </div>
    <?php
        $points=getLeaderReboundsDevensive();
        print drawLeader($points,$players,$teams,'sReboundsDefensive','RD');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>TAPONES</h3>
    </div>
    <?php
        $points=getLeaderTapones();
        print drawLeader($points,$players,$teams,'sBlocks','TAP');
    ?>
</div>
<div class="space20"></div>
<div class="cc21 ccTablePlayers">
    <div class="headc21">
        <h3>TL CONVERTIDOS</h3>
    </div>
    <?php
        $points=getLeaderTlConvert();
        print drawLeader($points,$players,$teams,'sTrueShootingAttempts','TLC');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>RECUPERÓ</h3>
    </div>
    <?php
        $points=getLeaderSteals();
        print drawLeader($points,$players,$teams,'sSteals','REC');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>CANASTA DE 2</h3>
    </div>
    <?php
        $points=getLeaderCasnasta2();
        print drawLeader($points,$players,$teams,'sTwoPointersMade','T2C');
    ?>
</div>
<div class="space20"></div>
<div class="cc21 ccTablePlayers">
    <div class="headc21">
        <h3>CANASTA DE 3</h3>
    </div>
    <?php
        $points=getLeaderCasnasta3();
        print drawLeader($points,$players,$teams,'sThreePointersMade','T3C');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>Faltas personales</h3>
    </div>
    <?php
        $points=getLeaderFoulPer();
        print drawLeader($points,$players,$teams,'sFoulsPersonal','FP');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>Media de robos</h3>
    </div>
    <?php
        $points=getLeaderPointsSec();
        print drawLeader($points,$players,$teams,'sPointsSecondChance','MR');
    ?>
</div>

<div class="space20"></div>

<div class="cc21 ccTablePlayers">
    <div class="headc21">
        <h3>Eficiencia</h3>
    </div>
    <?php
        $points=getLeaderWins();
        print drawLeader($points,$players,$teams,'sEfficiency','EF');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>Media de tapones</h3>
    </div>
    <?php
        $points=getLeaderBlocksReceived();
        print drawLeader($points,$players,$teams,'sBlocksAverage','MT');
    ?>
</div>
<div class="cc21 mc21 ccTablePlayers">
    <div class="headc21">
        <h3>Balones perdidos</h3>
    </div>
    <?php
        $points=getLeaderBallFouls();
        print drawLeader($points,$players,$teams,'sTurnovers','BP');
    ?>
</div>

<div class="space20"></div>
<div class="space20"></div>
<div class="hrNaranjaFull"></div>
<div class="cc22 desk">
    <div class="space20"></div>
    <div class="hrNaranjaFull"></div>
    <div class="space20"></div>
    <div class="desk">
        <img class="directv" src="img/sponsor_directv.png">
        <img class="borderImgTop molten" src="img/sponsor_molten.png">
        <img class="borderImgTop lan" src="img/sponsor_lan.png">
        <img class="borderImgTop win" src="img/sponsor_win.png">
        <img class="borderImgTop tuboleta" src="img/sponsor_tuboleta.png">
        <img class="borderImgBot fiba" src="img/sponsor_fiba.png">
        <img class="borderImgBot abasu" src="img/sponsor_abasu.png">
        <img class="borderImgBot fcb" src="img/sponsor_fcb.png">
        <img class="borderImgBot go" src="img/sponsor_go.png">
    </div>
</div>
