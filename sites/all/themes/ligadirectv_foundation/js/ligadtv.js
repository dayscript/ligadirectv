(function ($) {
  Drupal.behaviors.ligadtv = {
    attach: function (context, settings) {

      $(document).ready(function(){

        $('#slidorion .slider').cycle();

        $('.linkBack').click(function(){
          window.history.back();
        });

        if($(".view-estadisticas-jugador-equipo").length > 0) {
          var total = [];
          total[0] = "";
          $(".view-estadisticas-jugador-equipo table tbody tr").each(function(index) {
            $(this).children("td").each(function(index2) {
              if(index2 > 0) {
                var celdaValor = $(this).text();//alert(celdaValor);
                celdaValor = eval(celdaValor);
                //console.log("test: " + /^-?\d+$/.test(celdaValor));
                if (/^-?\d+$/.test(celdaValor)) {
                  parseInt(celdaValor);
                  //console.log("parseo entero: " + celdaValor);
                }
                else {
                  celdaValor = parseFloat(celdaValor);
                  //console.log("parseo float: " + celdaValor);
                }
                if(celdaValor == "undefinded" || isNaN(celdaValor)) {
                  celdaValor = "";
                  //console.log("celdaValor undefined: " + celdaValor);
                }
                if(total[index2] == "undefinded" || isNaN(total[index2])) {
                  total[index2] = celdaValor;
                  //console.log("total[index2] undefinded: " + celdaValor);
                }
                else total[index2] = eval("celdaValor + total[index2]");
              }
            });
          });
          var text = '<tfoot><tr>';
          jQuery.each(total, function(i, val) {
            if(i > 0) {
              if (!/^-?\d+$/.test(val)) {
                val = parseFloat(val).toFixed(2);
                //console.log("toFixed: " + val);
              }
              text += '<td>' + val + '</td>';
            }
            else if(i == 0) {
              text += '<td>TOTAL</td>';
            }
          });
          text += '</tr></tfoot>';
          //console.log(text);
          //alert(text);
          jQuery(".view-estadisticas-jugador-equipo table").append(text);
        }

        if($(".view-estadisticas-partido").length > 0) {
          var celdas = [1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18];
          var per = [2, 3, 6, 15, 16];
          var sum = [13, 19];
          $(".view-estadisticas-partido table").each(function(x) {
            var total = [];
            total[0] = "";
            var tcel = 0;
            var min = [0, 0];
            $(this).children("tbody").children("tr").each(function(index) {
              tcel++;
            //$(".view-estadisticas-partido table tbody tr").each(function(index) {
              $(this).children("td").each(function(index2) {
                console.log("inArray: " + index2 + " - " + jQuery.inArray( index2, celdas ));
                if( index2 > 0 && jQuery.inArray( index2, celdas ) >= 0 ) {
                  var celdaValor = $(this).text();//alert(celdaValor);
                  celdaValor = eval(celdaValor);
                  //console.log("test: " + /^-?\d+$/.test(celdaValor));
                  if (/^-?\d+$/.test(celdaValor)) {
                    parseInt(celdaValor);
                    //console.log("parseo entero: " + celdaValor);
                  }
                  else {
                    celdaValor = parseFloat(celdaValor);
                    //console.log("parseo float: " + celdaValor);
                  }
                  if(celdaValor == "undefinded" || isNaN(celdaValor)) {
                    celdaValor = "";
                    //console.log("celdaValor undefined: " + celdaValor);
                  }
                  if(total[index2] == "undefinded" || isNaN(total[index2])) {
                    total[index2] = celdaValor;
                    //console.log("total[index2] undefinded: " + celdaValor);
                  }
                  else total[index2] = eval("celdaValor + total[index2]");
                }
                else {
                  var celdaValor = $(this).text();//alert(celdaValor);
                  celdaValor = $.trim(celdaValor);
                  console.log("indexof: " + celdaValor.indexOf("%"));
                  if(celdaValor.indexOf("%") > 0) {
                    /*var l = celdaValor.length;
                    var celdaValor = celdaValor.substring(0, (l - 2));*/
                    celdaValor = eval(celdaValor);
                    parseInt(celdaValor);
                    if(total[index2] == "undefinded" || isNaN(total[index2])) {
                      total[index2] = celdaValor;
                      //console.log("total[index2] undefinded: " + celdaValor);
                    }
                    else total[index2] = eval("celdaValor + total[index2]");
                  }
                  else if(celdaValor.indexOf(":") > 0) {
                    celdaValor = celdaValor.split(":");
                    celdaValor[0] = eval(celdaValor[0]);
                    celdaValor[1] = eval(celdaValor[1]);
                    parseInt(celdaValor[0]);
                    parseInt(celdaValor[1]);
                    min[0] = eval("celdaValor[0] + min[0]");
                    min[1] = eval("celdaValor[1] + min[1]");
                    console.log("total[index2] undefinded: " + min[0] + ":" + min[1]);
                    if(min[1] >= 60) {
                      var tmp = min[1] / 60;
                      tmp = Math.floor(tmp);
                      console.log("tmp: " + tmp);
                      min[0] = eval("min[0] + tmp");
                      min[1] = eval("min[1] - (tmp * 60)");
                    }
                    total[index2] = min[0]+ ":" + min[1];
                    console.log("total[index2] undefinded: " + min[0] + ":" + min[1]);
                  }
                  else {
                    total[index2] = "";
                  }
                }
              });
            });
            var text = '<tfoot><tr>';
            jQuery.each(total, function(i, val) {
              if( i > 0 && jQuery.inArray( i, sum ) >= 0 ) {
                var num1 = eval("i - 1");
                var num2 = eval("i - 2");
                var dec = eval("total[num1] / total[num2]");
                dec = eval("dec * 100");
                dec = parseFloat(dec).toFixed(2);
                text += '<td>' + dec + ' %</td>';
              }
              else if( i > 0 && jQuery.inArray( i, per ) >= 0 ) {
                var t = eval("val / tcel");
                text += '<td>' + t + ' %</td>';
              }
              else if( i > 0  && jQuery.inArray( i, celdas ) >= 0 ) {
                if (!/^-?\d+$/.test(val)) {
                  val = parseFloat(val).toFixed(2);
                  //console.log("toFixed: " + val);
                }
                text += '<td>' + val + '</td>';
              }
              else if(i == 0) {
                text += '<td>TOTAL</td>';
              }
              else if(i != 0 && i != 1 && jQuery.inArray( i, per ) < 0 && jQuery.inArray( i, celdas ) < 0 ) {
                text += '<td>' + val + '</td>';
              }
              else {
                text += '<td></td>';
              }
            });
            text += '</tr></tfoot>';
            //console.log(text);
            //alert(text);
            jQuery(this).append(text);
            total = "";
          });
        }
      });
    }
  };
})(jQuery);
