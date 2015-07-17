<div class="tableNomina statisticsTable">
  <table class="bigTable">
    <thead>
      <tr>
        <td>JUGADOR</td>
        <td>EQUIPO</td>
        <td class="noBorder"><?php print $unit;?></td>
      </tr>
    </thead>
    <tbody>
      <?php foreach ($items as $key => $value) {?>
        <tr>
            <td><?php print $value['personName']; ?></td>
            <td><?php print $value['primaryClubName']; ?></td>
            <td><?php print $value[$query];?></td>
        </tr>
      <?php } ?>
    </tbody>
  </table>
</div>
