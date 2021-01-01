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
         float duration_to_allow_exit;
         float timer_to_allow_exit;
         bool exitable;

         bool is_exitable();
         void activate_exitable();
         void deactivate_exitable();

         void update_timer_to_allow_exit();
         void draw_you_have_won_banner();
         void draw_press_any_key_to_return_to_the_title_screen();
         void draw_sunset_background();

      public:
         GameWonScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
         ~GameWonScreen();

         void start() override;

         void primary_timer_func() override;
         void key_down_func(ALLEGRO_EVENT *ev) override;
      };
   }
}


