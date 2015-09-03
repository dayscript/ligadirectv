<div class="header-pos-es large-12 columns">
    <a href="/estadisticas" class="tab-falso">LÍDERES INDIVIDUALES</a>
    <a href="/posiciones" class="active tab-falso">TABLA DE POSICIONES</a>
</div>

<div class="tableNomina">
    <table class="bigTable">
        <thead>
            <tr>
                <td>POS</td>
                <td>EQUIPO</td>
                <td>J</td>
                <td>G</td>
                <td>P</td>
                <td>A FAV</td>
                <td>E CON</td>
                <td>DG</td>
                <td>ULTIMOS</td>
                <td class="noBorder">PTS</td>
            </tr>
        </thead>
        <tbody>
        <?php foreach ($items as $key => $value) {
            print $value;
        }?>
        </tbody>
    </table>
</div>
