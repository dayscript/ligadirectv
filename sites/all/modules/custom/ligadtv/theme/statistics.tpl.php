<?php
    $points         = getLeaderPoints();
    $mediaPointHtml = drawLeader($points,$players,$teams,'sReboundsTotalAverage','REBM');
    $pointsReb      = getLeaderPointsRebotes();
    $pointsRebHtml  = drawLeader($pointsReb,$players,$teams,'sReboundsTotalAverage','REBM');
    $pointsAsisten  = getLeaderMediaAsistencias2();
    $pointsAsistenH = drawLeader($pointsAsisten,$players,$teams,'sReboundsTotalAverage','REBM');
    $pointsTL       = getLeaderTlPorcentaje();
    $pointsTLHTML   = drawLeader($pointsTL,$players,$teams,'sFreeThrowsPercentage','TL');
    $points3        = getLeader3Porcentaje();
    $points3HTML    = drawLeader($points3,$players,$teams,'sFreeThrowsPercentage','TL');
    $points2        = getLeader2Porcentaje();
    $points2HTML    = drawLeader($points2,$players,$teams,'sFreeThrowsPercentage','TL');
    $pointsSUM      = getLeaderPuntos();
    $pointsSUMHTML  = drawLeader($pointsSUM,$players,$teams,'sReboundsTotal','RT');
    $pointsREBTOTAL = getLeaderPointsSecondChance();
    $pointsREBTOTALH= drawLeader($pointsREBTOTAL,$players,$teams,'sReboundsTotal','RT');
    $pointsAsistenc = getLeaderAssists();
    $pointsAsistencH= drawLeader($pointsAsistenc,$players,$teams,'sAssists','AS');
    $pointsREBOFE   = getLeaderReboundsOffensive();
    $pointsREBOFEHT = drawLeader($pointsREBOFE,$players,$teams,'sReboundsOffensive','RO');
    $pointsREDEF    = getLeaderReboundsDevensive();
    $pointsREDEFHTM = drawLeader($pointsREDEF,$players,$teams,'sReboundsDefensive','RD');
    $pointsTAPON    = getLeaderTapones();
    $pointsTAPONHTM = drawLeader($points,$players,$teams,'sBlocks','TAP');
    $pointsTL       = getLeaderTlConvert();
    $pointsTLHTML   = drawLeader($pointsTL,$players,$teams,'sTrueShootingAttempts','TLC');
    $pointsREC      = getLeaderSteals();
    $pointsRECHTML  = drawLeader($pointsREC,$players,$teams,'sSteals','REC');
    $pointsCANAST2  = getLeaderCasnasta2();
    $pointsCANAST2HT= drawLeader($pointsCANAST2,$players,$teams,'sTwoPointersMade','T2C');
    $pointsCANAST3  = getLeaderCasnasta3();
    $pointsCANAST3HT= drawLeader($pointsCANAST3,$players,$teams,'sThreePointersMade','T3C');
    $pointsFALT     = getLeaderFoulPer();
    $pointsFALTHTML = drawLeader($pointsFALT,$players,$teams,'sFoulsPersonal','FP');
    $pointsFALP     = getLeaderFoulPer();
    $pointsFALPHTM  = drawLeader($pointsFALP,$players,$teams,'sFoulsPersonal','FP');
    $pointsEFIC     = getLeaderWins();
    $pointsEFICHTM  = drawLeader($pointsEFIC,$players,$teams,'sEfficiency','EF');
    $pointsMETAPO   = getLeaderBlocksReceived();
    $pointsMETAPOHT = drawLeader($pointsMETAPO,$players,$teams,'sBlocksAverage','MT');
    $pointsBP       = getLeaderBallFouls();
    $pointsBPHTML   = drawLeader($pointsBP,$players,$teams,'sTurnovers','BP');
    variable_set('nextExecute', date('Y-m-d', strtotime('+1 week')));
?>
<div class="navEstadisticas noPhone">
    <a href="/estadisticas">
        <div class="linkEstadisticas active">
            LÍDERES INDIVIDUALES
        </div>
    </a>
    <a href="/positions">
        <div class="linkEstadisticas">
            TABLA DE POSICIONES
        </div>
    </a>
</div>
<div class="large-12 columns">
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>MEDIA DE PUNTOS</h3>
        </div>
        <?php print $mediaPointHtml['header']; print $mediaPointHtml['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers t-center">
        <div class="headc21">
            <h3>MEDIA REBOTES</h3>
        </div>
        <?php print $pointsRebHtml['header']; print $pointsRebHtml['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>MEDIA ASISTENCIAS</h3>
        </div>
        <?php print $pointsAsistenH['header']; print $pointsAsistenH['table'];?>
    </div>
</div>
<div class="large-12 columns">
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>TL PORCENTAJE</h3>
        </div>
        <?php print $pointsTLHTML['header']; print $pointsTLHTML['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers t-center">
        <div class="headc21">
            <h3>3 PORCENTAJE</h3>
        </div>
        <?php print $points3HTML['header']; print $points3HTML['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>2 PORCENTAJE</h3>
        </div>
        <?php print $points2HTML['header']; print $points2HTML['table'];?>
    </div>
</div>
<div class="large-12 columns">
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>PUNTOS</h3>
        </div>
        <?php print $pointsSUMHTML['header']; print $pointsSUMHTML['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers t-center">
        <div class="headc21">
            <h3>REBOTES TOTALES</h3>
        </div>
        <?php print $pointsREBTOTALH['header']; print $pointsREBTOTALH['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>ASISTENCIAS</h3>
        </div>
        <?php print $pointsAsistencH['header']; print $pointsAsistencH['table'];?>
    </div>
</div>
<div class="large-12 columns">
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>REBOTES DEFENSIVOS</h3>
        </div>
        <?php print $pointsREBOFEHT['header']; print $pointsREBOFEHT['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers t-center">
        <div class="headc21">
            <h3>REBOTES DEFENSIVOS</h3>
        </div>
        <?php print $pointsREDEFHTM['header']; print $pointsREDEFHTM['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>TAPONES</h3>
        </div>
        <?php print $pointsTAPONHTM['header']; print $pointsTAPONHTM['table'];?>
    </div>
</div>
<div class="large-12 columns">
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>TL CONVERTIDOS</h3>
        </div>
        <?php print $pointsTLHTML['header']; print $pointsTLHTML['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers t-center">
        <div class="headc21">
            <h3>RECUPERÓ</h3>
        </div>
        <?php print $pointsRECHTML['header']; print $pointsRECHTML['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>CANASTA DE 2</h3>
        </div>
        <?php print $pointsCANAST2HT['header']; print $pointsCANAST2HT['table'];?>
    </div>
</div>
<div class="large-12 columns">
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>CANASTA DE 3</h3>
        </div>
        <?php print $pointsCANAST3HT['header']; print $pointsCANAST3HT['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers t-center">
        <div class="headc21">
            <h3>Faltas personales</h3>
        </div>
        <?php print $pointsFALTHTML['header']; print $pointsFALTHTML['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>Media de robos</h3>
        </div>
        <?php print $pointsFALPHTM['header']; print $pointsFALPHTM['table'];?>
    </div>
</div>
<div class="large-12 columns">
   <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>Eficiencia</h3>
        </div>
        <?php print $pointsEFICHTM['header']; print $pointsEFICHTM['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers t-center">
        <div class="headc21">
            <h3>Media de tapones</h3>
        </div>
        <?php print $pointsMETAPOHT['header']; print $pointsMETAPOHT['table'];?>
    </div>
    <div class="large-4 columns ccTablePlayers">
        <div class="headc21">
            <h3>Balones perdidos</h3>
        </div>
        <?php print $pointsBPHTML['header']; print $pointsBPHTML['table'];?>
    </div>
</div>
