<?php
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
  $rounds = _get_rounds();
  return theme('matchs', array('matchs'=>$matchs, 'rounds'=> $rounds));
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
/**
 * Function return info in page teams
 * @return theme tpl
 */
function _teams(){
  $teams = _get_teams();
  return theme('teams', array('items'=>$teams));
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
                        '#attributes'=>array('placeholder'=> 'code video'),
                        //'replace_pattern' => '[^a-z0-9-]+',
                        //'replace' => '-',
                      );
    $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));

    return $form;
  }

  /**
   * Implements hook_submit
   */
  function _video_home_form_submit($for, &$form_state){
    variable_set('video_home', $form_state['values']['video_home']);
  }
?>
