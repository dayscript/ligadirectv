<?php
/**
 * @file
 * liga_direct_tv.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function liga_direct_tv_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'estadisticas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Estadisticas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media de puntos */
  $handler->display->display_options['fields']['field_points_average']['id'] = 'field_points_average';
  $handler->display->display_options['fields']['field_points_average']['table'] = 'field_data_field_points_average';
  $handler->display->display_options['fields']['field_points_average']['field'] = 'field_points_average';
  $handler->display->display_options['fields']['field_points_average']['label'] = 'MP';
  $handler->display->display_options['fields']['field_points_average']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_points_average']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Media de puntos (field_points_average) */
  $handler->display->display_options['sorts']['field_points_average_value']['id'] = 'field_points_average_value';
  $handler->display->display_options['sorts']['field_points_average_value']['table'] = 'field_data_field_points_average';
  $handler->display->display_options['sorts']['field_points_average_value']['field'] = 'field_points_average_value';
  $handler->display->display_options['sorts']['field_points_average_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'players' => 'players',
  );

  /* Display: Media de puntos */
  $handler = $view->new_display('block', 'Media de puntos', 'block_1');

  /* Display: Primero media de puntos */
  $handler = $view->new_display('attachment', 'Primero media de puntos', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media de puntos */
  $handler->display->display_options['fields']['field_points_average']['id'] = 'field_points_average';
  $handler->display->display_options['fields']['field_points_average']['table'] = 'field_data_field_points_average';
  $handler->display->display_options['fields']['field_points_average']['field'] = 'field_points_average';
  $handler->display->display_options['fields']['field_points_average']['label'] = '';
  $handler->display->display_options['fields']['field_points_average']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_points_average']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
  );

  /* Display: Media de rebotes */
  $handler = $view->new_display('block', 'Media de rebotes', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media de rebotes */
  $handler->display->display_options['fields']['field_rebounds_total_average']['id'] = 'field_rebounds_total_average';
  $handler->display->display_options['fields']['field_rebounds_total_average']['table'] = 'field_data_field_rebounds_total_average';
  $handler->display->display_options['fields']['field_rebounds_total_average']['field'] = 'field_rebounds_total_average';
  $handler->display->display_options['fields']['field_rebounds_total_average']['label'] = 'REBM';
  $handler->display->display_options['fields']['field_rebounds_total_average']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Media de rebotes (field_rebounds_total_average) */
  $handler->display->display_options['sorts']['field_rebounds_total_average_value']['id'] = 'field_rebounds_total_average_value';
  $handler->display->display_options['sorts']['field_rebounds_total_average_value']['table'] = 'field_data_field_rebounds_total_average';
  $handler->display->display_options['sorts']['field_rebounds_total_average_value']['field'] = 'field_rebounds_total_average_value';
  $handler->display->display_options['sorts']['field_rebounds_total_average_value']['order'] = 'DESC';

  /* Display: Primero media de rebotes */
  $handler = $view->new_display('attachment', 'Primero media de rebotes', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media de rebotes */
  $handler->display->display_options['fields']['field_rebounds_total_average']['id'] = 'field_rebounds_total_average';
  $handler->display->display_options['fields']['field_rebounds_total_average']['table'] = 'field_data_field_rebounds_total_average';
  $handler->display->display_options['fields']['field_rebounds_total_average']['field'] = 'field_rebounds_total_average';
  $handler->display->display_options['fields']['field_rebounds_total_average']['label'] = '';
  $handler->display->display_options['fields']['field_rebounds_total_average']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rebounds_total_average']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Media de rebotes (field_rebounds_total_average) */
  $handler->display->display_options['sorts']['field_rebounds_total_average_value']['id'] = 'field_rebounds_total_average_value';
  $handler->display->display_options['sorts']['field_rebounds_total_average_value']['table'] = 'field_data_field_rebounds_total_average';
  $handler->display->display_options['sorts']['field_rebounds_total_average_value']['field'] = 'field_rebounds_total_average_value';
  $handler->display->display_options['sorts']['field_rebounds_total_average_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
    'block_1' => 0,
  );

  /* Display: Media de Asistentes */
  $handler = $view->new_display('block', 'Media de Asistentes', 'block_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media de asistentes */
  $handler->display->display_options['fields']['field_assists_average']['id'] = 'field_assists_average';
  $handler->display->display_options['fields']['field_assists_average']['table'] = 'field_data_field_assists_average';
  $handler->display->display_options['fields']['field_assists_average']['field'] = 'field_assists_average';
  $handler->display->display_options['fields']['field_assists_average']['label'] = 'MAS';
  $handler->display->display_options['fields']['field_assists_average']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Media de asistentes (field_assists_average) */
  $handler->display->display_options['sorts']['field_assists_average_value']['id'] = 'field_assists_average_value';
  $handler->display->display_options['sorts']['field_assists_average_value']['table'] = 'field_data_field_assists_average';
  $handler->display->display_options['sorts']['field_assists_average_value']['field'] = 'field_assists_average_value';
  $handler->display->display_options['sorts']['field_assists_average_value']['order'] = 'DESC';

  /* Display: Primero media de asistentes */
  $handler = $view->new_display('attachment', 'Primero media de asistentes', 'attachment_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media de asistentes */
  $handler->display->display_options['fields']['field_assists_average']['id'] = 'field_assists_average';
  $handler->display->display_options['fields']['field_assists_average']['table'] = 'field_data_field_assists_average';
  $handler->display->display_options['fields']['field_assists_average']['field'] = 'field_assists_average';
  $handler->display->display_options['fields']['field_assists_average']['label'] = '';
  $handler->display->display_options['fields']['field_assists_average']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_assists_average']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Media de asistentes (field_assists_average) */
  $handler->display->display_options['sorts']['field_assists_average_value']['id'] = 'field_assists_average_value';
  $handler->display->display_options['sorts']['field_assists_average_value']['table'] = 'field_data_field_assists_average';
  $handler->display->display_options['sorts']['field_assists_average_value']['field'] = 'field_assists_average_value';
  $handler->display->display_options['sorts']['field_assists_average_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_3' => 'block_3',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
  );

  /* Display: Puntos */
  $handler = $view->new_display('block', 'Puntos', 'block_4');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Puntos */
  $handler->display->display_options['fields']['field_points']['id'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['table'] = 'field_data_field_points';
  $handler->display->display_options['fields']['field_points']['field'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['label'] = 'PT';
  $handler->display->display_options['fields']['field_points']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Puntos (field_points) */
  $handler->display->display_options['sorts']['field_points_value']['id'] = 'field_points_value';
  $handler->display->display_options['sorts']['field_points_value']['table'] = 'field_data_field_points';
  $handler->display->display_options['sorts']['field_points_value']['field'] = 'field_points_value';
  $handler->display->display_options['sorts']['field_points_value']['order'] = 'DESC';

  /* Display: Primero puntos */
  $handler = $view->new_display('attachment', 'Primero puntos', 'attachment_4');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Puntos */
  $handler->display->display_options['fields']['field_points']['id'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['table'] = 'field_data_field_points';
  $handler->display->display_options['fields']['field_points']['field'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['label'] = '';
  $handler->display->display_options['fields']['field_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_points']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Puntos (field_points) */
  $handler->display->display_options['sorts']['field_points_value']['id'] = 'field_points_value';
  $handler->display->display_options['sorts']['field_points_value']['table'] = 'field_data_field_points';
  $handler->display->display_options['sorts']['field_points_value']['field'] = 'field_points_value';
  $handler->display->display_options['sorts']['field_points_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_4' => 'block_4',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
  );

  /* Display: Rebotes totales */
  $handler = $view->new_display('block', 'Rebotes totales', 'block_5');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Total de rebotes */
  $handler->display->display_options['fields']['field_rebounds_total']['id'] = 'field_rebounds_total';
  $handler->display->display_options['fields']['field_rebounds_total']['table'] = 'field_data_field_rebounds_total';
  $handler->display->display_options['fields']['field_rebounds_total']['field'] = 'field_rebounds_total';
  $handler->display->display_options['fields']['field_rebounds_total']['label'] = 'RT';
  $handler->display->display_options['fields']['field_rebounds_total']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Total de rebotes (field_rebounds_total) */
  $handler->display->display_options['sorts']['field_rebounds_total_value']['id'] = 'field_rebounds_total_value';
  $handler->display->display_options['sorts']['field_rebounds_total_value']['table'] = 'field_data_field_rebounds_total';
  $handler->display->display_options['sorts']['field_rebounds_total_value']['field'] = 'field_rebounds_total_value';
  $handler->display->display_options['sorts']['field_rebounds_total_value']['order'] = 'DESC';

  /* Display: Primero rebotes totales */
  $handler = $view->new_display('attachment', 'Primero rebotes totales', 'attachment_5');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Total de rebotes */
  $handler->display->display_options['fields']['field_rebounds_total']['id'] = 'field_rebounds_total';
  $handler->display->display_options['fields']['field_rebounds_total']['table'] = 'field_data_field_rebounds_total';
  $handler->display->display_options['fields']['field_rebounds_total']['field'] = 'field_rebounds_total';
  $handler->display->display_options['fields']['field_rebounds_total']['label'] = '';
  $handler->display->display_options['fields']['field_rebounds_total']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rebounds_total']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Total de rebotes (field_rebounds_total) */
  $handler->display->display_options['sorts']['field_rebounds_total_value']['id'] = 'field_rebounds_total_value';
  $handler->display->display_options['sorts']['field_rebounds_total_value']['table'] = 'field_data_field_rebounds_total';
  $handler->display->display_options['sorts']['field_rebounds_total_value']['field'] = 'field_rebounds_total_value';
  $handler->display->display_options['sorts']['field_rebounds_total_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_5' => 'block_5',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
  );

  /* Display: Asistencias */
  $handler = $view->new_display('block', 'Asistencias', 'block_6');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Asistencias */
  $handler->display->display_options['fields']['field_assists']['id'] = 'field_assists';
  $handler->display->display_options['fields']['field_assists']['table'] = 'field_data_field_assists';
  $handler->display->display_options['fields']['field_assists']['field'] = 'field_assists';
  $handler->display->display_options['fields']['field_assists']['label'] = '';
  $handler->display->display_options['fields']['field_assists']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_assists']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Asistencias (field_assists) */
  $handler->display->display_options['sorts']['field_assists_value']['id'] = 'field_assists_value';
  $handler->display->display_options['sorts']['field_assists_value']['table'] = 'field_data_field_assists';
  $handler->display->display_options['sorts']['field_assists_value']['field'] = 'field_assists_value';
  $handler->display->display_options['sorts']['field_assists_value']['order'] = 'DESC';

  /* Display: Primero Asistencias */
  $handler = $view->new_display('attachment', 'Primero Asistencias', 'attachment_6');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Asistencias */
  $handler->display->display_options['fields']['field_assists']['id'] = 'field_assists';
  $handler->display->display_options['fields']['field_assists']['table'] = 'field_data_field_assists';
  $handler->display->display_options['fields']['field_assists']['field'] = 'field_assists';
  $handler->display->display_options['fields']['field_assists']['label'] = '';
  $handler->display->display_options['fields']['field_assists']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_assists']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Asistencias (field_assists) */
  $handler->display->display_options['sorts']['field_assists_value']['id'] = 'field_assists_value';
  $handler->display->display_options['sorts']['field_assists_value']['table'] = 'field_data_field_assists';
  $handler->display->display_options['sorts']['field_assists_value']['field'] = 'field_assists_value';
  $handler->display->display_options['sorts']['field_assists_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_6' => 'block_6',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
  );

  /* Display: Rebotes ofensivos */
  $handler = $view->new_display('block', 'Rebotes ofensivos', 'block_7');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Rebotes ofensivos */
  $handler->display->display_options['fields']['field_rebounds_offensive']['id'] = 'field_rebounds_offensive';
  $handler->display->display_options['fields']['field_rebounds_offensive']['table'] = 'field_data_field_rebounds_offensive';
  $handler->display->display_options['fields']['field_rebounds_offensive']['field'] = 'field_rebounds_offensive';
  $handler->display->display_options['fields']['field_rebounds_offensive']['label'] = 'RO';
  $handler->display->display_options['fields']['field_rebounds_offensive']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Rebotes ofensivos (field_rebounds_offensive) */
  $handler->display->display_options['sorts']['field_rebounds_offensive_value']['id'] = 'field_rebounds_offensive_value';
  $handler->display->display_options['sorts']['field_rebounds_offensive_value']['table'] = 'field_data_field_rebounds_offensive';
  $handler->display->display_options['sorts']['field_rebounds_offensive_value']['field'] = 'field_rebounds_offensive_value';
  $handler->display->display_options['sorts']['field_rebounds_offensive_value']['order'] = 'DESC';

  /* Display: Primero rebotes ofensivos */
  $handler = $view->new_display('attachment', 'Primero rebotes ofensivos', 'attachment_7');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Rebotes ofensivos */
  $handler->display->display_options['fields']['field_rebounds_offensive']['id'] = 'field_rebounds_offensive';
  $handler->display->display_options['fields']['field_rebounds_offensive']['table'] = 'field_data_field_rebounds_offensive';
  $handler->display->display_options['fields']['field_rebounds_offensive']['field'] = 'field_rebounds_offensive';
  $handler->display->display_options['fields']['field_rebounds_offensive']['label'] = '';
  $handler->display->display_options['fields']['field_rebounds_offensive']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rebounds_offensive']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Rebotes ofensivos (field_rebounds_offensive) */
  $handler->display->display_options['sorts']['field_rebounds_offensive_value']['id'] = 'field_rebounds_offensive_value';
  $handler->display->display_options['sorts']['field_rebounds_offensive_value']['table'] = 'field_data_field_rebounds_offensive';
  $handler->display->display_options['sorts']['field_rebounds_offensive_value']['field'] = 'field_rebounds_offensive_value';
  $handler->display->display_options['sorts']['field_rebounds_offensive_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_7' => 'block_7',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
  );

  /* Display: Rebotes defensivos */
  $handler = $view->new_display('block', 'Rebotes defensivos', 'block_8');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Rebotes defensivos */
  $handler->display->display_options['fields']['field_rebounds_defensive']['id'] = 'field_rebounds_defensive';
  $handler->display->display_options['fields']['field_rebounds_defensive']['table'] = 'field_data_field_rebounds_defensive';
  $handler->display->display_options['fields']['field_rebounds_defensive']['field'] = 'field_rebounds_defensive';
  $handler->display->display_options['fields']['field_rebounds_defensive']['label'] = 'RD';
  $handler->display->display_options['fields']['field_rebounds_defensive']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Rebotes defensivos (field_rebounds_defensive) */
  $handler->display->display_options['sorts']['field_rebounds_defensive_value']['id'] = 'field_rebounds_defensive_value';
  $handler->display->display_options['sorts']['field_rebounds_defensive_value']['table'] = 'field_data_field_rebounds_defensive';
  $handler->display->display_options['sorts']['field_rebounds_defensive_value']['field'] = 'field_rebounds_defensive_value';
  $handler->display->display_options['sorts']['field_rebounds_defensive_value']['order'] = 'DESC';

  /* Display: Primero rebotes defensivos */
  $handler = $view->new_display('attachment', 'Primero rebotes defensivos', 'attachment_8');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Rebotes defensivos */
  $handler->display->display_options['fields']['field_rebounds_defensive']['id'] = 'field_rebounds_defensive';
  $handler->display->display_options['fields']['field_rebounds_defensive']['table'] = 'field_data_field_rebounds_defensive';
  $handler->display->display_options['fields']['field_rebounds_defensive']['field'] = 'field_rebounds_defensive';
  $handler->display->display_options['fields']['field_rebounds_defensive']['label'] = '';
  $handler->display->display_options['fields']['field_rebounds_defensive']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rebounds_defensive']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Rebotes defensivos (field_rebounds_defensive) */
  $handler->display->display_options['sorts']['field_rebounds_defensive_value']['id'] = 'field_rebounds_defensive_value';
  $handler->display->display_options['sorts']['field_rebounds_defensive_value']['table'] = 'field_data_field_rebounds_defensive';
  $handler->display->display_options['sorts']['field_rebounds_defensive_value']['field'] = 'field_rebounds_defensive_value';
  $handler->display->display_options['sorts']['field_rebounds_defensive_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_8' => 'block_8',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
  );

  /* Display: Tapones */
  $handler = $view->new_display('block', 'Tapones', 'block_9');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Tapones */
  $handler->display->display_options['fields']['field_blocks']['id'] = 'field_blocks';
  $handler->display->display_options['fields']['field_blocks']['table'] = 'field_data_field_blocks';
  $handler->display->display_options['fields']['field_blocks']['field'] = 'field_blocks';
  $handler->display->display_options['fields']['field_blocks']['label'] = 'TAP';
  $handler->display->display_options['fields']['field_blocks']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Tapones (field_blocks) */
  $handler->display->display_options['sorts']['field_blocks_value']['id'] = 'field_blocks_value';
  $handler->display->display_options['sorts']['field_blocks_value']['table'] = 'field_data_field_blocks';
  $handler->display->display_options['sorts']['field_blocks_value']['field'] = 'field_blocks_value';
  $handler->display->display_options['sorts']['field_blocks_value']['order'] = 'DESC';

  /* Display: Primero tapones */
  $handler = $view->new_display('attachment', 'Primero tapones', 'attachment_9');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Tapones */
  $handler->display->display_options['fields']['field_blocks']['id'] = 'field_blocks';
  $handler->display->display_options['fields']['field_blocks']['table'] = 'field_data_field_blocks';
  $handler->display->display_options['fields']['field_blocks']['field'] = 'field_blocks';
  $handler->display->display_options['fields']['field_blocks']['label'] = '';
  $handler->display->display_options['fields']['field_blocks']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blocks']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Tapones (field_blocks) */
  $handler->display->display_options['sorts']['field_blocks_value']['id'] = 'field_blocks_value';
  $handler->display->display_options['sorts']['field_blocks_value']['table'] = 'field_data_field_blocks';
  $handler->display->display_options['sorts']['field_blocks_value']['field'] = 'field_blocks_value';
  $handler->display->display_options['sorts']['field_blocks_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_9' => 'block_9',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_8' => 0,
  );

  /* Display: Recupero */
  $handler = $view->new_display('block', 'Recupero', 'block_10');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Recuperó */
  $handler->display->display_options['fields']['field_free_throws_made']['id'] = 'field_free_throws_made';
  $handler->display->display_options['fields']['field_free_throws_made']['table'] = 'field_data_field_free_throws_made';
  $handler->display->display_options['fields']['field_free_throws_made']['field'] = 'field_free_throws_made';
  $handler->display->display_options['fields']['field_free_throws_made']['label'] = 'REC';
  $handler->display->display_options['fields']['field_free_throws_made']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Recuperó (field_free_throws_made) */
  $handler->display->display_options['sorts']['field_free_throws_made_value']['id'] = 'field_free_throws_made_value';
  $handler->display->display_options['sorts']['field_free_throws_made_value']['table'] = 'field_data_field_free_throws_made';
  $handler->display->display_options['sorts']['field_free_throws_made_value']['field'] = 'field_free_throws_made_value';
  $handler->display->display_options['sorts']['field_free_throws_made_value']['order'] = 'DESC';

  /* Display: Primero Recuperó */
  $handler = $view->new_display('attachment', 'Primero Recuperó', 'attachment_10');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Recuperó */
  $handler->display->display_options['fields']['field_free_throws_made']['id'] = 'field_free_throws_made';
  $handler->display->display_options['fields']['field_free_throws_made']['table'] = 'field_data_field_free_throws_made';
  $handler->display->display_options['fields']['field_free_throws_made']['field'] = 'field_free_throws_made';
  $handler->display->display_options['fields']['field_free_throws_made']['label'] = '';
  $handler->display->display_options['fields']['field_free_throws_made']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_free_throws_made']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Recuperó (field_free_throws_made) */
  $handler->display->display_options['sorts']['field_free_throws_made_value']['id'] = 'field_free_throws_made_value';
  $handler->display->display_options['sorts']['field_free_throws_made_value']['table'] = 'field_data_field_free_throws_made';
  $handler->display->display_options['sorts']['field_free_throws_made_value']['field'] = 'field_free_throws_made_value';
  $handler->display->display_options['sorts']['field_free_throws_made_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_10' => 'block_10',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_8' => 0,
    'block_9' => 0,
  );

  /* Display: Canasta de 2 */
  $handler = $view->new_display('block', 'Canasta de 2', 'block_11');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Canastas 2 */
  $handler->display->display_options['fields']['field_two_pointer_made']['id'] = 'field_two_pointer_made';
  $handler->display->display_options['fields']['field_two_pointer_made']['table'] = 'field_data_field_two_pointer_made';
  $handler->display->display_options['fields']['field_two_pointer_made']['field'] = 'field_two_pointer_made';
  $handler->display->display_options['fields']['field_two_pointer_made']['label'] = 'T2C';
  $handler->display->display_options['fields']['field_two_pointer_made']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Canastas 2 (field_two_pointer_made) */
  $handler->display->display_options['sorts']['field_two_pointer_made_value']['id'] = 'field_two_pointer_made_value';
  $handler->display->display_options['sorts']['field_two_pointer_made_value']['table'] = 'field_data_field_two_pointer_made';
  $handler->display->display_options['sorts']['field_two_pointer_made_value']['field'] = 'field_two_pointer_made_value';
  $handler->display->display_options['sorts']['field_two_pointer_made_value']['order'] = 'DESC';

  /* Display: Primero Canasta 2 */
  $handler = $view->new_display('attachment', 'Primero Canasta 2', 'attachment_11');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Canastas 2 */
  $handler->display->display_options['fields']['field_two_pointer_made']['id'] = 'field_two_pointer_made';
  $handler->display->display_options['fields']['field_two_pointer_made']['table'] = 'field_data_field_two_pointer_made';
  $handler->display->display_options['fields']['field_two_pointer_made']['field'] = 'field_two_pointer_made';
  $handler->display->display_options['fields']['field_two_pointer_made']['label'] = '';
  $handler->display->display_options['fields']['field_two_pointer_made']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_two_pointer_made']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Canastas 2 (field_two_pointer_made) */
  $handler->display->display_options['sorts']['field_two_pointer_made_value']['id'] = 'field_two_pointer_made_value';
  $handler->display->display_options['sorts']['field_two_pointer_made_value']['table'] = 'field_data_field_two_pointer_made';
  $handler->display->display_options['sorts']['field_two_pointer_made_value']['field'] = 'field_two_pointer_made_value';
  $handler->display->display_options['sorts']['field_two_pointer_made_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_11' => 'block_11',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_8' => 0,
    'block_9' => 0,
    'block_10' => 0,
  );

  /* Display: Canasta de 3 */
  $handler = $view->new_display('block', 'Canasta de 3', 'block_12');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Canasta 3 */
  $handler->display->display_options['fields']['field_three_pointer_made']['id'] = 'field_three_pointer_made';
  $handler->display->display_options['fields']['field_three_pointer_made']['table'] = 'field_data_field_three_pointer_made';
  $handler->display->display_options['fields']['field_three_pointer_made']['field'] = 'field_three_pointer_made';
  $handler->display->display_options['fields']['field_three_pointer_made']['label'] = 'T3C';
  $handler->display->display_options['fields']['field_three_pointer_made']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Canasta 3 (field_three_pointer_made) */
  $handler->display->display_options['sorts']['field_three_pointer_made_value']['id'] = 'field_three_pointer_made_value';
  $handler->display->display_options['sorts']['field_three_pointer_made_value']['table'] = 'field_data_field_three_pointer_made';
  $handler->display->display_options['sorts']['field_three_pointer_made_value']['field'] = 'field_three_pointer_made_value';
  $handler->display->display_options['sorts']['field_three_pointer_made_value']['order'] = 'DESC';

  /* Display: Primero Canasta 3 */
  $handler = $view->new_display('attachment', 'Primero Canasta 3', 'attachment_12');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Canasta 3 */
  $handler->display->display_options['fields']['field_three_pointer_made']['id'] = 'field_three_pointer_made';
  $handler->display->display_options['fields']['field_three_pointer_made']['table'] = 'field_data_field_three_pointer_made';
  $handler->display->display_options['fields']['field_three_pointer_made']['field'] = 'field_three_pointer_made';
  $handler->display->display_options['fields']['field_three_pointer_made']['label'] = 'T3C';
  $handler->display->display_options['fields']['field_three_pointer_made']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Canasta 3 (field_three_pointer_made) */
  $handler->display->display_options['sorts']['field_three_pointer_made_value']['id'] = 'field_three_pointer_made_value';
  $handler->display->display_options['sorts']['field_three_pointer_made_value']['table'] = 'field_data_field_three_pointer_made';
  $handler->display->display_options['sorts']['field_three_pointer_made_value']['field'] = 'field_three_pointer_made_value';
  $handler->display->display_options['sorts']['field_three_pointer_made_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_12' => 'block_12',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_8' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
  );

  /* Display: Faltas personales */
  $handler = $view->new_display('block', 'Faltas personales', 'block_13');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Faltas personales */
  $handler->display->display_options['fields']['field_fouls_personal']['id'] = 'field_fouls_personal';
  $handler->display->display_options['fields']['field_fouls_personal']['table'] = 'field_data_field_fouls_personal';
  $handler->display->display_options['fields']['field_fouls_personal']['field'] = 'field_fouls_personal';
  $handler->display->display_options['fields']['field_fouls_personal']['label'] = 'PF';
  $handler->display->display_options['fields']['field_fouls_personal']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Faltas personales (field_fouls_personal) */
  $handler->display->display_options['sorts']['field_fouls_personal_value']['id'] = 'field_fouls_personal_value';
  $handler->display->display_options['sorts']['field_fouls_personal_value']['table'] = 'field_data_field_fouls_personal';
  $handler->display->display_options['sorts']['field_fouls_personal_value']['field'] = 'field_fouls_personal_value';
  $handler->display->display_options['sorts']['field_fouls_personal_value']['order'] = 'DESC';

  /* Display: Primero faltas personales */
  $handler = $view->new_display('attachment', 'Primero faltas personales', 'attachment_13');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Faltas personales */
  $handler->display->display_options['fields']['field_fouls_personal']['id'] = 'field_fouls_personal';
  $handler->display->display_options['fields']['field_fouls_personal']['table'] = 'field_data_field_fouls_personal';
  $handler->display->display_options['fields']['field_fouls_personal']['field'] = 'field_fouls_personal';
  $handler->display->display_options['fields']['field_fouls_personal']['label'] = '';
  $handler->display->display_options['fields']['field_fouls_personal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fouls_personal']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Faltas personales (field_fouls_personal) */
  $handler->display->display_options['sorts']['field_fouls_personal_value']['id'] = 'field_fouls_personal_value';
  $handler->display->display_options['sorts']['field_fouls_personal_value']['table'] = 'field_data_field_fouls_personal';
  $handler->display->display_options['sorts']['field_fouls_personal_value']['field'] = 'field_fouls_personal_value';
  $handler->display->display_options['sorts']['field_fouls_personal_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_13' => 'block_13',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_8' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
  );

  /* Display: Robos */
  $handler = $view->new_display('block', 'Robos', 'block_14');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Robos */
  $handler->display->display_options['fields']['field_steals_average']['id'] = 'field_steals_average';
  $handler->display->display_options['fields']['field_steals_average']['table'] = 'field_data_field_steals_average';
  $handler->display->display_options['fields']['field_steals_average']['field'] = 'field_steals_average';
  $handler->display->display_options['fields']['field_steals_average']['label'] = 'MR';
  $handler->display->display_options['fields']['field_steals_average']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Robos (field_steals_average) */
  $handler->display->display_options['sorts']['field_steals_average_value']['id'] = 'field_steals_average_value';
  $handler->display->display_options['sorts']['field_steals_average_value']['table'] = 'field_data_field_steals_average';
  $handler->display->display_options['sorts']['field_steals_average_value']['field'] = 'field_steals_average_value';
  $handler->display->display_options['sorts']['field_steals_average_value']['order'] = 'DESC';

  /* Display: Primero robos */
  $handler = $view->new_display('attachment', 'Primero robos', 'attachment_14');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Robos */
  $handler->display->display_options['fields']['field_steals_average']['id'] = 'field_steals_average';
  $handler->display->display_options['fields']['field_steals_average']['table'] = 'field_data_field_steals_average';
  $handler->display->display_options['fields']['field_steals_average']['field'] = 'field_steals_average';
  $handler->display->display_options['fields']['field_steals_average']['label'] = '';
  $handler->display->display_options['fields']['field_steals_average']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_steals_average']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Robos (field_steals_average) */
  $handler->display->display_options['sorts']['field_steals_average_value']['id'] = 'field_steals_average_value';
  $handler->display->display_options['sorts']['field_steals_average_value']['table'] = 'field_data_field_steals_average';
  $handler->display->display_options['sorts']['field_steals_average_value']['field'] = 'field_steals_average_value';
  $handler->display->display_options['sorts']['field_steals_average_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_14' => 'block_14',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_8' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
    'block_13' => 0,
    'block_15' => 0,
  );

  /* Display: Eficiencia */
  $handler = $view->new_display('block', 'Eficiencia', 'block_15');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Eficiencia */
  $handler->display->display_options['fields']['field_efficiency']['id'] = 'field_efficiency';
  $handler->display->display_options['fields']['field_efficiency']['table'] = 'field_data_field_efficiency';
  $handler->display->display_options['fields']['field_efficiency']['field'] = 'field_efficiency';
  $handler->display->display_options['fields']['field_efficiency']['label'] = 'EF';
  $handler->display->display_options['fields']['field_efficiency']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Eficiencia (field_efficiency) */
  $handler->display->display_options['sorts']['field_efficiency_value']['id'] = 'field_efficiency_value';
  $handler->display->display_options['sorts']['field_efficiency_value']['table'] = 'field_data_field_efficiency';
  $handler->display->display_options['sorts']['field_efficiency_value']['field'] = 'field_efficiency_value';
  $handler->display->display_options['sorts']['field_efficiency_value']['order'] = 'DESC';

  /* Display: Primero eficiencia */
  $handler = $view->new_display('attachment', 'Primero eficiencia', 'attachment_15');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Eficiencia */
  $handler->display->display_options['fields']['field_efficiency']['id'] = 'field_efficiency';
  $handler->display->display_options['fields']['field_efficiency']['table'] = 'field_data_field_efficiency';
  $handler->display->display_options['fields']['field_efficiency']['field'] = 'field_efficiency';
  $handler->display->display_options['fields']['field_efficiency']['label'] = '';
  $handler->display->display_options['fields']['field_efficiency']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_efficiency']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Eficiencia (field_efficiency) */
  $handler->display->display_options['sorts']['field_efficiency_value']['id'] = 'field_efficiency_value';
  $handler->display->display_options['sorts']['field_efficiency_value']['table'] = 'field_data_field_efficiency';
  $handler->display->display_options['sorts']['field_efficiency_value']['field'] = 'field_efficiency_value';
  $handler->display->display_options['sorts']['field_efficiency_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_15' => 'block_15',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_8' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
    'block_13' => 0,
    'block_14' => 0,
  );

  /* Display: Balones perdidos */
  $handler = $view->new_display('block', 'Balones perdidos', 'block_16');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Balones perdidos */
  $handler->display->display_options['fields']['field_turnovers']['id'] = 'field_turnovers';
  $handler->display->display_options['fields']['field_turnovers']['table'] = 'field_data_field_turnovers';
  $handler->display->display_options['fields']['field_turnovers']['field'] = 'field_turnovers';
  $handler->display->display_options['fields']['field_turnovers']['label'] = 'BP';
  $handler->display->display_options['fields']['field_turnovers']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Balones perdidos (field_turnovers) */
  $handler->display->display_options['sorts']['field_turnovers_value']['id'] = 'field_turnovers_value';
  $handler->display->display_options['sorts']['field_turnovers_value']['table'] = 'field_data_field_turnovers';
  $handler->display->display_options['sorts']['field_turnovers_value']['field'] = 'field_turnovers_value';
  $handler->display->display_options['sorts']['field_turnovers_value']['order'] = 'DESC';

  /* Display: Primero balones perdidos */
  $handler = $view->new_display('attachment', 'Primero balones perdidos', 'attachment_16');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Balones perdidos */
  $handler->display->display_options['fields']['field_turnovers']['id'] = 'field_turnovers';
  $handler->display->display_options['fields']['field_turnovers']['table'] = 'field_data_field_turnovers';
  $handler->display->display_options['fields']['field_turnovers']['field'] = 'field_turnovers';
  $handler->display->display_options['fields']['field_turnovers']['label'] = '';
  $handler->display->display_options['fields']['field_turnovers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_turnovers']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Balones perdidos (field_turnovers) */
  $handler->display->display_options['sorts']['field_turnovers_value']['id'] = 'field_turnovers_value';
  $handler->display->display_options['sorts']['field_turnovers_value']['table'] = 'field_data_field_turnovers';
  $handler->display->display_options['sorts']['field_turnovers_value']['field'] = 'field_turnovers_value';
  $handler->display->display_options['sorts']['field_turnovers_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_16' => 'block_16',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_8' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
    'block_13' => 0,
    'block_14' => 0,
    'block_15' => 0,
  );

  /* Display: Media de tapones */
  $handler = $view->new_display('block', 'Media de tapones', 'block_17');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '2';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Nombre';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media de Tapones */
  $handler->display->display_options['fields']['field_blocks_average']['id'] = 'field_blocks_average';
  $handler->display->display_options['fields']['field_blocks_average']['table'] = 'field_data_field_blocks_average';
  $handler->display->display_options['fields']['field_blocks_average']['field'] = 'field_blocks_average';
  $handler->display->display_options['fields']['field_blocks_average']['label'] = 'MT';
  $handler->display->display_options['fields']['field_blocks_average']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Media de Tapones (field_blocks_average) */
  $handler->display->display_options['sorts']['field_blocks_average_value']['id'] = 'field_blocks_average_value';
  $handler->display->display_options['sorts']['field_blocks_average_value']['table'] = 'field_data_field_blocks_average';
  $handler->display->display_options['sorts']['field_blocks_average_value']['field'] = 'field_blocks_average_value';
  $handler->display->display_options['sorts']['field_blocks_average_value']['order'] = 'DESC';

  /* Display: Primero media tapones */
  $handler = $view->new_display('attachment', 'Primero media tapones', 'attachment_17');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_team_target_id']['id'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['table'] = 'field_data_field_team';
  $handler->display->display_options['relationships']['field_team_target_id']['field'] = 'field_team_target_id';
  $handler->display->display_options['relationships']['field_team_target_id']['label'] = 'Contenido entity referenced from field_team';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media de Tapones */
  $handler->display->display_options['fields']['field_blocks_average']['id'] = 'field_blocks_average';
  $handler->display->display_options['fields']['field_blocks_average']['table'] = 'field_data_field_blocks_average';
  $handler->display->display_options['fields']['field_blocks_average']['field'] = 'field_blocks_average';
  $handler->display->display_options['fields']['field_blocks_average']['label'] = '';
  $handler->display->display_options['fields']['field_blocks_average']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blocks_average']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Equipo */
  $handler->display->display_options['fields']['field_team']['id'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['table'] = 'field_data_field_team';
  $handler->display->display_options['fields']['field_team']['field'] = 'field_team';
  $handler->display->display_options['fields']['field_team']['label'] = '';
  $handler->display->display_options['fields']['field_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_team_target_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Media de Tapones (field_blocks_average) */
  $handler->display->display_options['sorts']['field_blocks_average_value']['id'] = 'field_blocks_average_value';
  $handler->display->display_options['sorts']['field_blocks_average_value']['table'] = 'field_data_field_blocks_average';
  $handler->display->display_options['sorts']['field_blocks_average_value']['field'] = 'field_blocks_average_value';
  $handler->display->display_options['sorts']['field_blocks_average_value']['order'] = 'DESC';
  $handler->display->display_options['displays'] = array(
    'block_17' => 'block_17',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
    'block_6' => 0,
    'block_7' => 0,
    'block_8' => 0,
    'block_9' => 0,
    'block_10' => 0,
    'block_11' => 0,
    'block_12' => 0,
    'block_13' => 0,
    'block_14' => 0,
    'block_15' => 0,
    'block_16' => 0,
  );
  $translatables['estadisticas'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('#'),
    t('Nombre'),
    t('MP'),
    t('Media de puntos'),
    t('Primero media de puntos'),
    t('Contenido entity referenced from field_team'),
    t('Media de rebotes'),
    t('REBM'),
    t('Primero media de rebotes'),
    t('Media de Asistentes'),
    t('MAS'),
    t('Primero media de asistentes'),
    t('Puntos'),
    t('PT'),
    t('Primero puntos'),
    t('Rebotes totales'),
    t('RT'),
    t('Primero rebotes totales'),
    t('Asistencias'),
    t('Primero Asistencias'),
    t('Rebotes ofensivos'),
    t('RO'),
    t('Primero rebotes ofensivos'),
    t('Rebotes defensivos'),
    t('RD'),
    t('Primero rebotes defensivos'),
    t('Tapones'),
    t('TAP'),
    t('Primero tapones'),
    t('Recupero'),
    t('REC'),
    t('Primero Recuperó'),
    t('Canasta de 2'),
    t('T2C'),
    t('Primero Canasta 2'),
    t('Canasta de 3'),
    t('T3C'),
    t('Primero Canasta 3'),
    t('Faltas personales'),
    t('PF'),
    t('Primero faltas personales'),
    t('Robos'),
    t('MR'),
    t('Primero robos'),
    t('Eficiencia'),
    t('EF'),
    t('Primero eficiencia'),
    t('Balones perdidos'),
    t('BP'),
    t('Primero balones perdidos'),
    t('Media de tapones'),
    t('MT'),
    t('Primero media tapones'),
  );
  $export['estadisticas'] = $view;

  $view = new view();
  $view->name = 'positions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Positions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Posiciones';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'field_played' => 'field_played',
    'field_won' => 'field_won',
    'field_lost' => 'field_lost',
    'field_scored_for' => 'field_scored_for',
    'field_scored_against' => 'field_scored_against',
    'field_point_diff' => 'field_point_diff',
    'field_last_5' => 'field_last_5',
    'field_points' => 'field_points',
  );
  $handler->display->display_options['style_options']['default'] = 'field_points';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_played' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_won' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lost' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_scored_for' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_scored_against' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_point_diff' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_5' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_points' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Pos';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Equipo';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Jugados */
  $handler->display->display_options['fields']['field_played']['id'] = 'field_played';
  $handler->display->display_options['fields']['field_played']['table'] = 'field_data_field_played';
  $handler->display->display_options['fields']['field_played']['field'] = 'field_played';
  $handler->display->display_options['fields']['field_played']['label'] = 'J';
  $handler->display->display_options['fields']['field_played']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_played']['settings'] = array(
    'thousand_separator' => '.',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Ganados */
  $handler->display->display_options['fields']['field_won']['id'] = 'field_won';
  $handler->display->display_options['fields']['field_won']['table'] = 'field_data_field_won';
  $handler->display->display_options['fields']['field_won']['field'] = 'field_won';
  $handler->display->display_options['fields']['field_won']['label'] = 'G';
  $handler->display->display_options['fields']['field_won']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_won']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Perdidos */
  $handler->display->display_options['fields']['field_lost']['id'] = 'field_lost';
  $handler->display->display_options['fields']['field_lost']['table'] = 'field_data_field_lost';
  $handler->display->display_options['fields']['field_lost']['field'] = 'field_lost';
  $handler->display->display_options['fields']['field_lost']['label'] = 'P';
  $handler->display->display_options['fields']['field_lost']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lost']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: A FAV */
  $handler->display->display_options['fields']['field_scored_for']['id'] = 'field_scored_for';
  $handler->display->display_options['fields']['field_scored_for']['table'] = 'field_data_field_scored_for';
  $handler->display->display_options['fields']['field_scored_for']['field'] = 'field_scored_for';
  $handler->display->display_options['fields']['field_scored_for']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scored_for']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: E CON */
  $handler->display->display_options['fields']['field_scored_against']['id'] = 'field_scored_against';
  $handler->display->display_options['fields']['field_scored_against']['table'] = 'field_data_field_scored_against';
  $handler->display->display_options['fields']['field_scored_against']['field'] = 'field_scored_against';
  $handler->display->display_options['fields']['field_scored_against']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scored_against']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: DG */
  $handler->display->display_options['fields']['field_point_diff']['id'] = 'field_point_diff';
  $handler->display->display_options['fields']['field_point_diff']['table'] = 'field_data_field_point_diff';
  $handler->display->display_options['fields']['field_point_diff']['field'] = 'field_point_diff';
  $handler->display->display_options['fields']['field_point_diff']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_point_diff']['settings'] = array(
    'thousand_separator' => '.',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: ULTIMOS */
  $handler->display->display_options['fields']['field_last_5']['id'] = 'field_last_5';
  $handler->display->display_options['fields']['field_last_5']['table'] = 'field_data_field_last_5';
  $handler->display->display_options['fields']['field_last_5']['field'] = 'field_last_5';
  $handler->display->display_options['fields']['field_last_5']['element_label_colon'] = FALSE;
  /* Field: Content: Puntos */
  $handler->display->display_options['fields']['field_points']['id'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['table'] = 'field_data_field_points';
  $handler->display->display_options['fields']['field_points']['field'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['label'] = 'PTS';
  $handler->display->display_options['fields']['field_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_points']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team' => 'team',
  );
  /* Filter criterion: Content: Puntos (field_points) */
  $handler->display->display_options['filters']['field_points_value']['id'] = 'field_points_value';
  $handler->display->display_options['filters']['field_points_value']['table'] = 'field_data_field_points';
  $handler->display->display_options['filters']['field_points_value']['field'] = 'field_points_value';
  $handler->display->display_options['filters']['field_points_value']['operator'] = 'not empty';

  /* Display: Page Positions */
  $handler = $view->new_display('page', 'Page Positions', 'page');
  $handler->display->display_options['path'] = 'positions-new';

  /* Display: Block positions */
  $handler = $view->new_display('block', 'Block positions', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Equipo';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Jugados */
  $handler->display->display_options['fields']['field_played']['id'] = 'field_played';
  $handler->display->display_options['fields']['field_played']['table'] = 'field_data_field_played';
  $handler->display->display_options['fields']['field_played']['field'] = 'field_played';
  $handler->display->display_options['fields']['field_played']['label'] = 'J';
  $handler->display->display_options['fields']['field_played']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_played']['settings'] = array(
    'thousand_separator' => '.',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Ganados */
  $handler->display->display_options['fields']['field_won']['id'] = 'field_won';
  $handler->display->display_options['fields']['field_won']['table'] = 'field_data_field_won';
  $handler->display->display_options['fields']['field_won']['field'] = 'field_won';
  $handler->display->display_options['fields']['field_won']['label'] = 'G';
  $handler->display->display_options['fields']['field_won']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_won']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Perdidos */
  $handler->display->display_options['fields']['field_lost']['id'] = 'field_lost';
  $handler->display->display_options['fields']['field_lost']['table'] = 'field_data_field_lost';
  $handler->display->display_options['fields']['field_lost']['field'] = 'field_lost';
  $handler->display->display_options['fields']['field_lost']['label'] = 'P';
  $handler->display->display_options['fields']['field_lost']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lost']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Puntos */
  $handler->display->display_options['fields']['field_points']['id'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['table'] = 'field_data_field_points';
  $handler->display->display_options['fields']['field_points']['field'] = 'field_points';
  $handler->display->display_options['fields']['field_points']['label'] = 'PTS';
  $handler->display->display_options['fields']['field_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_points']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => ',',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $translatables['positions'] = array(
    t('Master'),
    t('Posiciones'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Pos'),
    t('Equipo'),
    t('J'),
    t('G'),
    t('P'),
    t('A FAV'),
    t('E CON'),
    t('DG'),
    t('ULTIMOS'),
    t('PTS'),
    t('Page Positions'),
    t('Block positions'),
  );
  $export['positions'] = $view;

  $view = new view();
  $view->name = 'teams';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Teams';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Equipos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'small-4 columns';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'team-page',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="node/[nid]">Ver equipo</a>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team' => 'team',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'teams';
  $translatables['teams'] = array(
    t('Master'),
    t('Equipos'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="node/[nid]">Ver equipo</a>'),
    t('Page'),
  );
  $export['teams'] = $view;

  return $export;
}
