(function ($) {
  Drupal.behaviors.ligadtv = {
    attach: function (context, settings) {

      $(document).ready(function(){
        
        $('#slidorion .slider').cycle();
        
        $('.linkBack').click(function(){
          window.history.back();
        });
        
      });
    }
  };
})(jQuery);
