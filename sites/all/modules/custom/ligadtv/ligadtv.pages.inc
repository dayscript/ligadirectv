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
  $vocabulary = taxonomy_vocabulary_machine_name_load('phase');
  $phase = taxonomy_get_tree($vocabulary->vid);
  foreach ($phase as $key => $value) {
    $matchs[$value->tid] = _consult_matchs($value->tid);
  }
  return theme('matchs', array('items'=>$matchs));
}
function _statistics(){
  $games = getRes();
  return theme('statistics', array('items'=>$games));
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
   *
   */
  function _video_home_form_submit($for, &$form_state){
    variable_set('video_home', $form_state['values']['video_home']);
  }
?>
