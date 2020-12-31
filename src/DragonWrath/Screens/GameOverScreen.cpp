

#include <DragonWrath/Screens/GameOverScreen.hpp>

#include <allegro5/allegro_color.h>
#include <AllegroFlare/Color.hpp>


namespace DragonWrath
{
namespace Screens
{


GameOverScreen::GameOverScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter)
   : framework(framework)
   , user_event_emitter(user_event_emitter)
{
}


GameOverScreen::~GameOverScreen()
{
}


void GameOverScreen::draw_main_title()
{
   ALLEGRO_FONT *title_text_font = framework.font("ChronoTrigger.ttf 100");
   ALLEGRO_FONT *subtitle_text_font = framework.font("ChronoTrigger.ttf 60");

   std::string title_text = "GAME OVER";
   std::string subtitle_text = "Press ANY key to return to the TITLE SCREEN";

   ALLEGRO_COLOR title_text_color = al_color_name("white");
   ALLEGRO_COLOR subtitle_text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};

   float title_text_x = 1920 / 2;
   float title_text_y = 1080 / 2 - 150;

   float subtitle_text_x = 1920 / 2;
   float subtitle_text_y = 1080 / 2 + 100;

   al_draw_text(
      title_text_font,
      title_text_color,
      title_text_x,
      title_text_y,
      ALLEGRO_ALIGN_CENTER,
      title_text.c_str()
   );
   al_draw_text(
      subtitle_text_font,
      subtitle_text_color,
      subtitle_text_x,
      subtitle_text_y,
      ALLEGRO_ALIGN_CENTER,
      subtitle_text.c_str()
   );
}


void GameOverScreen::start()
{
   user_event_emitter.emit_play_game_over_music();
}


void GameOverScreen::primary_timer_func()
{
   al_clear_to_color(AllegroFlare::color::black);

   draw_main_title();
}


void GameOverScreen::key_down_func(ALLEGRO_EVENT *ev)
{
   user_event_emitter.emit_start_title_screen_event();
}


} // Screens
} // DragonWrath


