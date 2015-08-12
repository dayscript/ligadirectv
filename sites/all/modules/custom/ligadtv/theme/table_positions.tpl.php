<div class="hrNaranjaFull"></div>
<div class="cc2Home">
    <div class="cc21">
        <div class="headc21">
            <h3>TABLA DE POSICIONES</h3>
            <a href="/posiciones" targer="_blank">Posiciones ></a>
        </div>
        <div class="infocc21">
            <table>
                <tr class="title">
                    <td>EQUIPO</td>
                    <td>J</td>
                    <td>G</td>
                    <td>P</td>
                    <td>PTS</td>
                </tr>
                <?php
                $cond = false;
                foreach ($items[0] as $key => $value) { ?>
                    <?php if($value['roundNumber'] == $items[1]):?>
                       <?php /*if($cond): ?>
                            <tr class='tdIn'>
                                <td><?php print $value['clubName']; ?></td>
                                <td><?php print $value['played'];?></td>
                                <td><?php print $value['won'];?></td>
                                <td><?php print $value['lost'];?></td>
                                <td><?php print (($value['won'] * 2) + $value['lost']); ?></td>
                            </tr>
                        <?php else:?>
                            <tr class="tdIn naranja">
                                <td><?php print $value['clubName']; ?></td>
                                <td><?php print $value['played']; ?></td>
                                <td><?php print $value['won']; ?></td>
                                <td><?php print $value['lost']; ?></td>
                                <td><?php print (($value['won'] * 2) + $value['lost']); ?></td>
                            </tr>
                        <?php endif */?>
                        <?php if($cond): ?>
                            
                            <tr class='tdIn'>
                                <td><?php print $value['clubName']; ?></td>
                                <td><?php print $value['played'];?></td>
                                <td><?php print $value['won'];?></td>
                                <td><?php print $value['lost'];?></td>
                                <td><?php print (int)$value['standingPoints']; ?></td>
                            </tr>
                        <?php else:?>
                            <tr class="tdIn naranja">
                                <td><?php print $value['clubName']; ?></td>
                                <td><?php print $value['played'];?></td>
                                <td><?php print $value['won'];?></td>
                                <td><?php print $value['lost'];?></td>
                                <td><?php print (int)$value['standingPoints']; ?></td>
                            </tr>
                        <?php endif ?>
                       
                        <?php $cond = $cond ? false : true; ?>
                    <?php endif ?>
                <?php } ?>
            </table>
        </div>
    </div>
</div>
