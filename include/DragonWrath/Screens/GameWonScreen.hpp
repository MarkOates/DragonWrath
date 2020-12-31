#pragma once

#include <DragonWrath/Screens/Base.hpp>
#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/UserEventEmitter.hpp>

namespace DragonWrath
{
   namespace Screens
   {
      class GameWonScreen : public DragonWrath::Screens::Base
      {
      private:
         AllegroFlare::Framework &framework;
         DragonWrath::UserEventEmitter &user_event_emitter;

      public:
         GameWonScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
         ~GameWonScreen();

         void draw_you_have_won_banner();

         void start() override;

         void primary_timer_func() override;
         void key_down_func(ALLEGRO_EVENT *ev) override;
      };
   }
}


