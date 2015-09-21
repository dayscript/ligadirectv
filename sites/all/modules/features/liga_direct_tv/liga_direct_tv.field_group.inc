<?php
/**
 * @file
 * liga_direct_tv.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function liga_direct_tv_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|matchs|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'matchs';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contenido',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_competition_id',
      2 => 'field_match_id',
      3 => 'field_match_number',
      4 => 'field_match_time',
      5 => 'field_venue_name',
      6 => 'title',
      7 => 'path',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_content|node|matchs|form'] = $field_group;

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
      4 => 'field_team',
      5 => 'title',
      6 => 'path',
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
  $field_group->identifier = 'group_match_information|node|matchs|form';
  $field_group->group_name = 'group_match_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'matchs';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Información Partido',
    'weight' => '1',
    'children' => array(
      0 => 'field_round',
      1 => 'group_team_1',
      2 => 'group_team_2',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-match-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_match_information|node|matchs|form'] = $field_group;

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
  $field_group->identifier = 'group_team_1|node|matchs|form';
  $field_group->group_name = 'group_team_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'matchs';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_match_information';
  $field_group->data = array(
    'label' => 'Equipo 1',
    'weight' => '13',
    'children' => array(
      0 => 'field_team_1',
      1 => 'field_points_team_1',
      2 => 'field_team_id_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-team-1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_1|node|matchs|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_team_2|node|matchs|form';
  $field_group->group_name = 'group_team_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'matchs';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_match_information';
  $field_group->data = array(
    'label' => 'Equipo 2',
    'weight' => '14',
    'children' => array(
      0 => 'field_team_2',
      1 => 'field_points_team_2',
      2 => 'field_team_id_2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-team-2 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_team_2|node|matchs|form'] = $field_group;

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
