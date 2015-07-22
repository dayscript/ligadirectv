/* Implement custom javascript here */
(function ($) {
  Drupal.behaviors.ligadtvTheme = {
    attach: function (context, settings) {
      $('.linkBack').click(function(){
        window.history.back();
      });
    }
  };
})(jQuery);
