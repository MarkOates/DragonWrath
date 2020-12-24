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

      void emit_start_title_screen_event();
      void emit_start_gameplay_screen_event();
      void emit_increase_player_score(int points_to_add);
   };
}

