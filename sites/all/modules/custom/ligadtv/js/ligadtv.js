(function ($) {
  Drupal.behaviors.ligadtv = {
    attach: function (context, settings) {
      $('#slidorion').slidorion({
            effect: 'slideRandom',
            hoverPause: true,
            interval: 20000,
            speed: 800,
            controlNav: false,
            controlNavClass: 'nav'
        });
    }
  };
})(jQuery);
