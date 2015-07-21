Drupal.behaviors.custom = {
  attach: function (context, settings) {
    var leader   = loadJson('sPointsAverage.json','mediaPointHtml', 'MP');
    var pointsReb= loadJson('sReboundsTotalAverage.json','mediaRebotes', 'REBM');
    var pointsAsisten = loadJson('sAssistsAverage.json','mediaAsistence','MAS');
    var pointsTL = loadJson('sFreeThrowsPercentage.json' ,'tlporcentaje', 'TL');
    var points3  = loadJson('sFreeThrowsPercentage.json','3porcentaje', 'T3');
    var points2  = loadJson('sTwoPointersPercentage.json', '2porcentaje' ,'T2');
    var points   = loadJson('sPoints.json', 'puntos', 'PT');
    var pointsT  = loadJson('sReboundsTotal.json','rebot-total', 'RT');
    var pointsAs = loadJson('sAssists.json', 'asistencias', 'AS');
    var pointsRO = loadJson('sReboundsOffensive.json', 'rebotes-ofensivos', 'RO');
    var pointsRD = loadJson('sReboundsDefensive.json', 'rebotes-defensivos', 'RD');
    var pointsTA = loadJson('sBlocks.json', 'tapones', 'TAP');
    var pointsTC = loadJson('sTrueShootingAttempts.json', 'tl-convertidos', 'TLC');
    var recupero = loadJson('sSteals.json', 'recupero', 'REC');
    var canasta2 = loadJson('sTwoPointersMade.json', 'canasta2', 'T2C');
    var canasta3 = loadJson('sThreePointersMade.json', 'canasta3', 'T3C');
    var faltasPer= loadJson('sFoulsPersonal.json', 'faltas-personales', 'FP');
    var mediaRob = loadJson('sStealsAverage.json', 'media-robos', 'MR');
    var eficienc = loadJson('sEfficiency.json', 'eficiencia', 'EF');
    var mediaTap = loadJson('sBlocksAverage.json', 'media-tapones', 'MT');
    var balPerdi = loadJson('sTurnovers.json', 'balones-perdidos', 'BP');
  }
};

function loadJson (name, id, point) {
  var data_file = '/ligadirectv/sites/all/modules/custom/ligadtv/data/' + name; //Descomentar en caso de ser local
  //var data_file = '/sites/all/modules/custom/ligadtv/data/' + name;
  var http_request = new XMLHttpRequest();
  try{
    // Opera 8.0+, Firefox, Chrome, Safari
    http_request = new XMLHttpRequest();
  }catch (e){
    // Internet Explorer Browsers
    try{
      http_request = new ActiveXObject("Msxml2.XMLHTTP");
    }catch (e) {
      try{
        http_request = new ActiveXObject("Microsoft.XMLHTTP");
      }catch (e){
        // Something went wrong
        alert("Your browser broke!");
        return false;
      }
    }
  }
  http_request.onreadystatechange  = function(){
      if (http_request.readyState == 4  ){
        // Javascript function JSON.parse to parse JSON data
        var jsonObj = JSON.parse(http_request.responseText);
        var leader  = Array.prototype.slice.call(jsonObj.response.data, 0);
        var data = drawLeader(leader,point);
        document.getElementById(id).innerHTML = data;
      }
   }
   http_request.open("GET", data_file, true);
   http_request.send();
}
/**
 * [drawLeader description]
 * @param  {string} leader [description]
 * @param  {string} point  [description]
 * @return {[type]}        [description]
 */
function drawLeader(leader, point) {
  console.log(leader);
  console.log(point);
  for (var i = 0; i <= 5 ; i++) {
    if(i == 0){
      if(typeof(leader[i].images) != 'undefined'){
        var data = '<div class="dataPlayer"><div class="leaderImg"><img src="' + leader[i].images.photo.T1.url + '"><div class="titleLidder">Leader</div></div><div class="info"><div class="inInfo"><h4>' + leader[i].firstName + ' ' + leader[i].familyName + '</h4><h5>' + leader[i].teamName + '</h5></div><div class="cc1Info"><div class="cc2Info">' +
                            leader[i].sPoints + ' ' +point + '</div><img src="' + getLogo(leader[i].linkDetailTeam) + '"></div></div></div><div class="tableLeader"><table><thead><tr><td width="20px">#</td><td width="50px">EQU</td><td width="185px" style="text-align: left;">NOMBRE</td><td width="45px">'+ point + '</td></tr></thead><tbody>';
      }else{
        var data = '<div class="dataPlayer"><div class="leaderImg"><img src=""><div class="titleLidder">Leader</div></div><div class="info"><div class="inInfo"><h4>' + leader[i].firstName + ' ' + leader[i].familyName + '</h4><h5>' + leader[i].teamName + '</h5></div><div class="cc1Info"><div class="cc2Info">' +
                            leader[i].sPoints + point + '</div><img src="' + getLogo(leader[i].linkDetailTeam) + '"></div></div></div><div class="tableLeader"><table><thead><tr><td width="20px">#</td><td width="50px">EQU</td><td width="185px" style="text-align: left;">NOMBRE</td><td width="45px">'+ point + '</td></tr></thead><tbody>';
      }
    }else{
      data +='<tr><td>' + i + '</td><td>' + leader[i].teamCode + '</td><td>'+
            leader[i].firstName  + leader[i].familyName +'</td><td>' +
            leader[i].sPoints + '</td></tr>';
    }
  }
  data += '</tbody></table><a href="/statistics/sPoints/'+ point + '" class="verTodos">VER LISTA COMPLETA >> </a></div>';
  return data;
}

function getLogo(link){
  var ak = '73fee4973791892d5cd9fa0f8411da51';
  var data_file = 'http://api.wh.sportingpulseinternational.com' + link + '?format=json&ak=' + ak ;
  var http_request = new XMLHttpRequest();
  var jqxhr = jQuery.getJSON(data_file, function() {
    console.log(jqxhr);
  }).done(function() {
      console.log( "second success" );
    }).fail(function() {
      console.log( "error" );
    }).always(function() {
      console.log( "complete" );
    });
}
