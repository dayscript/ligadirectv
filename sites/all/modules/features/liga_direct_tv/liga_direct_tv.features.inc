<?php
/**
 * @file
 * liga_direct_tv.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function liga_direct_tv_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function liga_direct_tv_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function liga_direct_tv_node_info() {
  $items = array(
    'matchs' => array(
      'name' => t('Matchs'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Partido'),
      'help' => '',
    ),
    'players' => array(
      'name' => t('Players'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nombre'),
      'help' => '',
    ),
    'team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
