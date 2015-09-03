<?php
/**
 * @file
 * features_ligadtv.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_ligadtv_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_information|node|players|form';
  $field_group->group_name = 'group_general_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'players';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Información General',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_image',
      2 => 'field_team_id',
      3 => 'field_personal_id',
      4 => 'title',
      5 => 'path',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_general_information|node|players|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_information|node|team|form';
  $field_group->group_name = 'group_general_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Información General',
    'weight' => '0',
    'children' => array(
      0 => 'field_image',
      1 => 'field_image_team',
      2 => 'field_city',
      3 => 'field_stadium',
      4 => 'field_twitter',
      5 => 'field_facebook',
      6 => 'body',
      7 => 'title',
      8 => 'path',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_general_information|node|team|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stadistics|node|players|form';
  $field_group->group_name = 'group_stadistics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'players';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Estadisticas',
    'weight' => '2',
    'children' => array(
      0 => 'field_points_average',
      1 => 'field_rebounds_total_average',
      2 => 'field_assists_average',
      3 => 'field_points',
      4 => 'field_rebounds_total',
      5 => 'field_assists',
      6 => 'field_rebounds_offensive',
      7 => 'field_rebounds_defensive',
      8 => 'field_blocks',
      9 => 'field_two_pointer_made',
      10 => 'field_three_pointer_made',
      11 => 'field_fouls_personal',
      12 => 'field_steals_average',
      13 => 'field_efficiency',
      14 => 'field_blocks_average',
      15 => 'field_turnovers',
      16 => 'field_free_throws_made',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-stadistics field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_stadistics|node|players|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tournamet_information|node|team|form';
  $field_group->group_name = 'group_tournamet_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'team';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Información Campeonato',
    'weight' => '1',
    'children' => array(
      0 => 'field_team_id',
      1 => 'field_played',
      2 => 'field_won',
      3 => 'field_lost',
      4 => 'field_scored_for',
      5 => 'field_scored_against',
      6 => 'field_point_diff',
      7 => 'field_last_5',
      8 => 'field_points',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Información Campeonato',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-tournamet-information field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_tournamet_information|node|team|form'] = $field_group;

  return $export;
}
