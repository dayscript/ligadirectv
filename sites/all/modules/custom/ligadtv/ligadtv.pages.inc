<?php
function _ligadtv_config(){
  $form = drupal_get_form('_ligadtv_config_form');
  return theme('ligadtv_config', array('form'=>$form));
}

/**
 * [_video_home_config description]
 * @return [type] [description]
 */
  function _video_home_config(){
    $form = drupal_get_form('_video_home_form');
    return theme('home_form', array('form'=>$form));
  }
/**
 * [_matchs description]
 * @return [type] [description]
 */
function _matchs(){
  $matchs = _list_matchs();
  dpm($matchs);
  $rounds = _get_rounds();
  return theme('matchs', array('matchs'=>$matchs, 'rounds'=> $rounds));
}
function _matchs_detail($idMatch){
  $games = getRes();
  $cont = 0;
  return(theme('matchs_detail', array('matchs'=>$games, 'idMatchs'=>$idMatch)));
}
/**
 * [_statistics description]
 * @return [type] [description]
 */
function _statistics(){
  $games = getRes();
  return theme('statistics', array('items'=>$games));
}

function _statistics_table($query, $unit){
  $data = getLeaderPoints();
  $data = $data['response']['data'];
  $data = array_sort($data,$query,SORT_DESC);

  return theme('statisticsTable', array('items'=>$data, 'unit'=>$unit, 'query'=>$query));
}

function _positions(){
  $data = getStanding($sql);
  $cont = 1;
  $maxRound = 0;
  foreach ($data as $key => $value) {
      if ($value['roundNumber'] > $maxRound) {
          $maxRound = $value['roundNumber'];
      }
  }
  foreach ($data as $key => $value) {
      if ($value['poolNumber'] == '1' && $value['roundNumber'] == $maxRound) {
          $items[]= "<tr>
                  <td>" . $cont . "</td>
                  <td>" . $value['clubName'] . "</td>
                  <td>" . $value['played'] . "</td>
                  <td>" . $value['won'] . "</td>
                  <td>" . $value['lost'] . "</td>
                  <td>" . $value['scoredFor'] . "</td>
                  <td>" . $value['scoredAgainst'] . "</td>
                  <td>" . $value['pointDiff'] . "</td>
                  <td>" . $value['last5'] . "</td>
                  <td>" . (($value['won'] * 2) + $value['lost']) . "</td>
              </tr>";
      }
      if ($value['poolNumber'] == '2' && $value['roundNumber'] == $maxRound) {
              $groupB[]= "<tr>
                <td>" .  $cont . "</td>
                <td>" . $value['clubName'] . "</td>
                <td>" . $value['played'] . "</td>
                <td>" . $value['won'] . "</td>
                <td>" . $value['lost'] . "</td>
                <td>" . $value['scoredFor'] . "</td>
                <td>" . $value['scoredAgainst'] . "</td>
                <td>" . $value['pointDiff'] . "</td>
                <td>" . $value['last5'] . "</td>
                <td>" . (($value['won'] * 2) + $value['lost']) . "</td>
          </tr>";
      }
      $cont++;
  }
  return theme('positions', array('items'=>$items, 'groupB'=>$groupB));
}
/**
 * function return info team especific
 * @return [type] [description]
 */
function _detail_teams($name, $id){
  $teams = _get_detail_teams($name, $id);
  return theme('detail_teams', array('items'=>$teams));
}

  /**
  * Implements hook_form
  **/
  function _video_home_form(){
    $form['video_home'] = array(
                        '#type' => 'textfield',
                        '#title' => t('Video'),
                        '#default_value' => variable_get('video_home'),
                        '#maxlength' => 180,
                        '#attributes'=>array('placeholder'=> t('code video')),
                      );
    $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));

    return $form;
  }
  function _ligadtv_config_form(){
    $form['ak'] = array(
                    '#type' => 'textfield',
                    '#title' => t('AK'),
                    '#default_value' => variable_get('ak'),
                    '#maxlength' => 180,
                    '#attributes'=>array('placeholder'=> t('Ak value')),
                  );
    $form['actual'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Actual'),
                    '#default_value' => variable_get('actual'),
                    '#maxlength' => 180,
                    '#attributes'=>array('placeholder'=> t('actual value')),
                  );
    $form['liga'] = array(
                    '#type' => 'textfield',
                    '#title' => t('Liga'),
                    '#default_value' => variable_get('liga'),
                    '#maxlength' => 180,
                    '#attributes'=>array('placeholder'=> t('liga value')),
                  );
    $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));

    return $form;
  }
  /**
   * Implements hook_submit
   */

  function _video_home_form_submit($form, &$form_state){
    variable_set('video_home', $form_state['values']['video_home']);
  }

  function _ligadtv_config_form_submit($form, &$form_state){
   variable_set('ak', $form_state['values']['ak']);
   variable_set('actual', $form_state['values']['actual']);
   variable_set('liga', $form_state['values']['liga']);
  }
?>
