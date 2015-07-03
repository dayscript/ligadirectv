<?php
  dpm($items)
?>
<?php drupal_set_title($items['response']['data']['clubName']); ?>
<div class="equipoInfoc12">
  <div class="equipoInfoc121">
    <img src="admin//upload/team//1391111044foto_equipo_academia.png">
  </div>
  <div class="equipoInfoc122">
    <h2><?php print $items['response']['data']['clubName'];?></h2>
    <p>Ciudad:<?php print $items['response']['data']['state'];?></p>
    <p>Estadio:Coliseo U. de Medellín</p>
    <!-- <p>WebSite:</p> -->
    <br>
    <p><a href="https://twitter.com/BasketAcademia"><img src="img/btn_twitter.png" class="rollover" data-rollover="img/btn_twitter2.png">@BasketAcademia</a></p>
    <p><a href="https://www.facebook.com/AcademiaBasketClub"><img src="img/btn_facebook.png" class="rollover" data-rollover="img/btn_facebook2.png">/AcademiaBasketClub</a></p>
  </div>
  <div class="equipoInfoc122 linkTeam">
    <a href="equipo-historia.php?id=2">
      <li>HISTORIA</li>
    </a>
    <a class="last" href="equipo-nomina.php?id=2">
      <li>NÓMINA</li>
    </a>
    <a class="last" href="equipo.php?id=2">
      <li class="activeTeam">NOTICIAS</li>
    </a>
    <a class="last" href="equipo-calendario.php?id=2">
      <li>CALENDARIO</li>
    </a>
  </div>
</div>
