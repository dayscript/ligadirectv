<?php
  function _video_home_config(){
    $form = drupal_get_form('_video_home_form');
    return theme('home_form', array('form'=>$form));
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
