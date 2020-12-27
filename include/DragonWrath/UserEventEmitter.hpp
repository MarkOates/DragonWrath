#pragma once

#include <allegro5/allegro.h>
#include <string>

namespace DragonWrath
{
   class UserEventEmitter
   {
   private:
      ALLEGRO_EVENT_SOURCE &screen_switcher_event_souce;

   public:
      UserEventEmitter(ALLEGRO_EVENT_SOURCE &screen_switcher_event_souce);
      ~UserEventEmitter();

      // screen change events

      void emit_start_title_screen_event();
      void emit_start_gameplay_screen_event();

      // spawn entity events

      void emit_spawn_player_bullet_event(float x, float y);
      void emit_spawn_extra_life_power_up_event(float x, float y);
      void emit_spawn_shield_boost_power_up_event(float x, float y);
      void emit_spawn_bullet_boost_power_up_event(float x, float y);
      void emit_spawn_speed_boost_power_up_event(float x, float y);
      void emit_spawn_option_boost_power_up_event(float x, float y);

      // stats, equipment, and powerup events

      void emit_increase_player_score(int points_to_add);
      void emit_player_dragon_gets_extra_life();
      void emit_player_dragon_gets_shield_boost();
      void emit_player_dragon_gets_bullet_boost();
      void emit_player_dragon_gets_speed_boost();
      void emit_player_dragon_gets_option_boost();

      // music events

      void emit_play_title_screen_music_event();
      void emit_play_level_1_music_event();

      // sound effect events

      void emit_play_player_shooting_bullet_sound_effect_event();
      void emit_play_enemy_takes_hit_sound_effect_event();
      void emit_play_enemy_explosion_sound_effect_event();
   };
}

