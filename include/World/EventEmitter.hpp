#pragma once

#include <allegro5/allegro.h>
#include <string>

namespace World
{
   class EventEmitter
   {
   private:
      ALLEGRO_EVENT_SOURCE &screen_switcher_event_souce;

   protected:
      ALLEGRO_EVENT build_emit_play_sound_effect_by_identifier(std::string identifier);
      ALLEGRO_EVENT build_emit_play_music_track_by_identifier(std::string identifier);
      ALLEGRO_EVENT build_emit_start_screen_by_identifier(std::string identifier);
      void emit(ALLEGRO_EVENT event);

   public:
      EventEmitter(ALLEGRO_EVENT_SOURCE &screen_switcher_event_souce);
      ~EventEmitter();

      void emit_start_title_screen_event();
      void emit_start_gameplay_screen_event();
      void emit_start_game_over_screen_event();
      void emit_start_game_won_screen_event();
      void emit_game_over_event();
      void emit_game_won_event();
      void emit_stop_all_music_and_sound_effects_event();

      void emit_start_screen_by_identifier(std::string identifier);
      void emit_play_sound_effect_by_identifier(std::string identifier);
      void emit_play_music_track_by_identifier(std::string identifier);
   };
}


