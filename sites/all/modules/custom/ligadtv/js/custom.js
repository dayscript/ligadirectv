Drupal.behaviors.custom = {
  attach: function (context, settings) {
    var leader   = loadJson('sPointsAverage.json','mediaPointHtml', 'MP', 'sPointsAverage');
    var pointsReb= loadJson('sReboundsTotalAverage.json','mediaRebotes', 'REBM', 'sReboundsTotalAverage');
    var pointsAsisten = loadJson('sAssistsAverage.json','mediaAsistence','MAS', 'sAssistsAverage');
    //var pointsTL = loadJson('sFreeThrowsPercentage.json' ,'tlporcentaje', 'TL', 'sFreeThrowsPercentage');
    //var points3  = loadJson('sFreeThrowsPercentage.json','3porcentaje', 'T3', 'sFreeThrowsPercentage');
    //var points2  = loadJson('sTwoPointersPercentage.json', '2porcentaje' ,'T2', 'sTwoPointersPercentage');
    var points   = loadJson('sPoints.json', 'puntos', 'PT', 'sPoints');
    var pointsT  = loadJson('sReboundsTotal.json','rebot-total', 'RT', 'sReboundsTotal');
    var pointsAs = loadJson('sAssists.json', 'asistencias', 'AS', 'sAssists');
    var pointsRO = loadJson('sReboundsOffensive.json', 'rebotes-ofensivos', 'RO', 'sReboundsOffensive');
    var pointsRD = loadJson('sReboundsDefensive.json', 'rebotes-defensivos', 'RD', 'sReboundsDefensive');
    var pointsTA = loadJson('sBlocks.json', 'tapones', 'TAP', 'sBlocks');
    var pointsTC = loadJson('sTrueShootingAttempts.json', 'tl-convertidos', 'TLC', 'sTrueShootingAttempts');
    var recupero = loadJson('sSteals.json', 'recupero', 'REC', 'sSteals');
    var canasta2 = loadJson('sTwoPointersMade.json', 'canasta2', 'T2C', 'sTwoPointersMade');
    var canasta3 = loadJson('sThreePointersMade.json', 'canasta3', 'T3C', 'sThreePointersMade');
    var faltasPer= loadJson('sFoulsPersonal.json', 'faltas-personales', 'FP', 'sFoulsPersonal');
    var mediaRob = loadJson('sStealsAverage.json', 'media-robos', 'MR', 'sStealsAverage');
    var eficienc = loadJson('sEfficiency.json', 'eficiencia', 'EF', 'sEfficiency');
    var mediaTap = loadJson('sBlocksAverage.json', 'media-tapones', 'MT', 'sBlocksAverage');
    var balPerdi = loadJson('sTurnovers.json', 'balones-perdidos', 'BP', 'sTurnovers');
    
  }
};

function loadJson (name, id, point, opt) {
  //var data_file = '/ligadirectv/sites/all/modules/custom/ligadtv/data/' + name; //Descomentar en caso de ser local
  var data_file = '/sites/all/modules/custom/ligadtv/data/' + name;
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
        var data = drawLeader(leader,point, opt);
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
function drawLeader(leader, point, opt) {
  var logo,
      points = 0;
  
  for (var i = 0; i <= 5 ; i++) {
    
    switch( opt ){
      case "sPointsAverage":
        points = leader[i].sPointsAverage;
      break;
      case "sReboundsTotalAverage":
        points = leader[i].sReboundsTotalAverage;
      break;
      case "sAssistsAverage":
        points = leader[i].sAssistsAverage;
      break;
      case "sFreeThrowsPercentage":
        points = leader[i].sFreeThrowsPercentage;
      break;
      case "sTwoPointersPercentage":
        points = leader[i].sTwoPointersPercentage;
      break;
      case "sPoints":
        points = leader[i].sPoints;
      break;
      case "sReboundsTotal":
        points = leader[i].sReboundsTotal;
      break;
      case "sAssists":
        points = leader[i].sAssists;
      break;
      case "sReboundsOffensive":
        points = leader[i].sReboundsOffensive;
      break;
      case "sReboundsDefensive":
        points = leader[i].sReboundsDefensive;
      break;
      case "sBlocks":
        points = leader[i].sBlocks;
      break;
      case "sTrueShootingAttempts":
        points = leader[i].sTrueShootingAttempts;
      break;
      case "sSteals":
        points = leader[i].sSteals;
      break;
      case "sTwoPointersMade":
        points = leader[i].sTwoPointersMade;
      break;
      case "sThreePointersMade":
        points = leader[i].sThreePointersMade;
      break;
      case "sFoulsPersonal":
        points = leader[i].sFoulsPersonal;
      break;
      case "sStealsAverage":
        points = leader[i].sSteals;
      break;
      case "sEfficiency":
        points = parseInt(leader[i].sEfficiency);
      break;
      case "sBlocksAverage":
        points = leader[i].sBlocksAverage;
      break;
      case "sTurnovers":
        points = leader[i].sTurnovers;
      break;
    }
    
    if(i == 0){
      if(typeof(leader[i].images) != 'undefined'){
        var data = '<div class="dataPlayer"><div class="leaderImg"><img src="' + leader[i].images.photo.T1.url + '"><div class="titleLidder">Leader</div></div><div class="info"><div class="inInfo"><h4>' + leader[i].firstName + '  ' + leader[i].familyName + '</h4><h5>' + leader[i].teamName + '</h5></div><div class="cc1Info"><div class="cc2Info">' +
                            points + '  ' + point + '</div><div id ="'+ leader[i].teamId +'"></div></div></div></div><div class="tableLeader"><table><thead><tr><td width="20px">#</td><td width="50px">EQU</td><td width="185px" style="text-align: left;">NOMBRE</td><td width="45px">'+ point + '</td></tr></thead><tbody>';
       getLogo(leader[i].teamId);
      }else{
        var data = '<div class="dataPlayer"><div class="leaderImg"><img src=""><div class="titleLidder">Leader</div></div><div class="info"><div class="inInfo"><h4>' + leader[i].firstName + '  ' + leader[i].familyName + '</h4><h5>' + leader[i].teamName + '</h5></div><div class="cc1Info"><div class="cc2Info">' +
                            points + '  ' + point + '</div><div id = "'+ leader[i].teamId + '"></div></div></div></div><div class="tableLeader"><table><thead><tr><td width="20px">#</td><td width="50px">EQU</td><td width="185px" style="text-align: left;">NOMBRE</td><td width="45px">'+ point + '</td></tr></thead><tbody>';
        getLogo(leader[i].teamId);
      }
    }else{
      
      
      
      data +='<tr><td>' + i + '</td><td>' + leader[i].teamCode + '</td><td>'+
            leader[i].firstName  + ' ' + leader[i].familyName +'</td><td>' +
            points + '</td></tr>';
    }
  }
  data += '</tbody></table><a href="/statistics/sPoints/'+ point + '" class="verTodos">VER LISTA COMPLETA >> </a></div>';
  return data;
}

function getLogo(idTeam){
  var idTeam = idTeam ;
  var data;
  var data_file = '/sites/all/modules/custom/ligadtv/data/teams.json';
  jQuery.ajax({
      url:data_file,
      dataType: "text",
      success: function(data) {
      var json = jQuery.parseJSON(data);
      jQuery.each(json.response.data,function(){
          if(this.teamId == idTeam){
            if( typeof(this.images) != 'undefined'){
                data = this.images.logo.T1.url;
                console.log(idTeam);
                //document.getElementById(idTeam).innerHTML = idTeam + '<img src="' + data + '">';
                jQuery(".dataPlayer").find("#"+idTeam).empty().append('<img src="'+ data +'">');
            }else{
                document.getElementById(idTeam).innerHTML = idTeam;
            }
          }
      });
      }
  });
}
