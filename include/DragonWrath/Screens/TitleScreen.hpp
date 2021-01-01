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
         float started_at;
         float time_jump;

         std::vector<std::tuple<float, float, void (DragonWrath::Screens::TitleScreen::*)()>> slides;

         float time_since_start();

      public:
         TitleScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
         ~TitleScreen();

         void draw_powered_by_allegro();
         void draw_game_by_mark_oates();
         void draw_krampushack_2020();
         void draw_sunset_background();
         void draw_main_title();

         void start() override;

         void primary_timer_func() override;
         void key_down_func(ALLEGRO_EVENT *ev) override;
      };
   }
}


