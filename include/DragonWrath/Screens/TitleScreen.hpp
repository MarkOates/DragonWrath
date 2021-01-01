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
         std::vector<std::tuple<std::string, void (DragonWrath::Screens::TitleScreen::*)()>> menu_items;

         int menu_cursor_pos;
         void move_cursor_up();
         void move_cursor_down();
         void activate_current_menu_selection();

         int num_menu_items();
         bool is_menu_active();

         float time_since_start();

      public:
         TitleScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter);
         ~TitleScreen();

         void draw_powered_by_allegro();
         void draw_game_by_mark_oates();
         void draw_krampushack_2020();
         void draw_sunset_background();
         void draw_main_title();
         void draw_menu_items();

         void start() override;
         void start_new_game();
         void exit();

         void primary_timer_func() override;
         void key_down_func(ALLEGRO_EVENT *ev) override;
         void key_char_func(ALLEGRO_EVENT *ev) override;
      };
   }
}


