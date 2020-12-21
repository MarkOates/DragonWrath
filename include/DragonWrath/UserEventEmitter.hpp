#pragma once

#include <allegro5/allegro.h>

namespace DragonWrath
{
   class UserEventEmitter
   {
   private:
      ALLEGRO_EVENT_SOURCE *screen_switcher_event_souce;

   public:
      UserEventEmitter(ALLEGRO_EVENT_SOURCE *screen_switcher_event_souce=nullptr);
      ~UserEventEmitter();

      void emit_start_title_screen_event();
      void emit_start_gameplay_screen_event();
   };
}

