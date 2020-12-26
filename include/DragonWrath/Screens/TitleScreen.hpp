#pragma once

#include <DragonWrath/Screens/Base.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/UserEventEmitter.hpp>

namespace DragonWrath
{
   namespace Screens
   {
      class TitleScreen : public DragonWrath::Screens::Base
      {
      private:
         AllegroFlare::Framework &framework;
         DragonWrath::UserEventEmitter &user_event_emitter;

      public:
         TitleScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
         ~TitleScreen();

         void draw_main_title();

         void start() override;

         void primary_timer_func() override;
         void key_down_func(ALLEGRO_EVENT *ev) override;
      };
   }
}


