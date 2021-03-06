#pragma once

#include <allegro5/allegro.h>
#include <string>

namespace DragonWrath
{
   class UserEventEmitter
   {
   private:
      ALLEGRO_EVENT_SOURCE &screen_switcher_event_souce;

      ALLEGRO_EVENT build_emit_play_sound_effect_by_identifier(std::string identifier);
      ALLEGRO_EVENT build_emit_play_music_track_identifier(std::string identifier);

   public:
      UserEventEmitter(ALLEGRO_EVENT_SOURCE &screen_switcher_event_souce);
      ~UserEventEmitter();

      // system level screen change events

      void emit_start_title_screen_event();
      void emit_start_gameplay_screen_event();
      void emit_start_game_over_screen_event();
      void emit_start_game_won_screen_event();
      void emit_game_over_event();
      void emit_game_won_event();
      void emit_stop_all_music_and_sound_effects_event();
      void emit_play_title_screen_music_event();
      void emit_play_game_over_music();
      void emit_play_game_won_music();


      // gameplay level events


      // spawn entity events

      void emit_spawn_player_bullet_event(float x, float y);
      void emit_spawn_extra_life_power_up_event(float x, float y);
      void emit_spawn_shield_boost_power_up_event(float x, float y);
      void emit_spawn_bullet_boost_power_up_event(float x, float y);
      void emit_spawn_speed_boost_power_up_event(float x, float y);
      void emit_spawn_option_boost_power_up_event(float x, float y);
      void emit_spawn_slash_poof_event(float x, float y);

      // stats, equipment, and powerup events

      void emit_increase_player_score(int points_to_add);
      void emit_player_dragon_gets_extra_life();
      void emit_player_dragon_gets_shield_boost();
      void emit_player_dragon_gets_bullet_boost();
      void emit_player_dragon_gets_speed_boost();
      void emit_player_dragon_gets_option_boost();

      // gameplay events

      void emit_player_dragon_dies_event();
      void emit_restart_current_level_event();
      void emit_load_next_level_event();

      // music events

      void emit_play_level_1_music_event();
      void emit_play_final_boss_music();

      // sound effect events

      void emit_play_player_shooting_bullet_sound_effect_event();
      void emit_play_enemy_takes_hit_sound_effect_event();
      void emit_play_bullet_deflected_sound_event();
      void emit_play_enemy_explosion_sound_effect_event();
   };
}

