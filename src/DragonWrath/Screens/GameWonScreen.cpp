

#include <DragonWrath/Screens/GameWonScreen.hpp>

#include <allegro5/allegro_color.h>
#include <AllegroFlare/Color.hpp>


namespace DragonWrath
{
namespace Screens
{


GameWonScreen::GameWonScreen(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter)
   : framework(framework)
   , user_event_emitter(user_event_emitter)
{
}


GameWonScreen::~GameWonScreen()
{
}


void GameWonScreen::draw_you_have_won_banner()
{
   ALLEGRO_FONT *title_text_font = framework.font("ChronoTrigger.ttf 100");
   ALLEGRO_FONT *subtitle_text_font = framework.font("ChronoTrigger.ttf 60");

   std::string title_text = "--  CONGRATULATIONS  --";
   std::string subtitle_text = "You have won the game";

   ALLEGRO_COLOR text_color = ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0};

   float title_text_x = 1920 / 2;
   float title_text_y = 1080 / 2 - 150;

   float subtitle_text_x = 1920 / 2;
   float subtitle_text_y = 1080 / 2 + 100;

   al_draw_text(
      title_text_font,
      text_color,
      title_text_x,
      title_text_y,
      ALLEGRO_ALIGN_CENTER,
      title_text.c_str()
   );
   al_draw_text(
      subtitle_text_font,
      text_color,
      subtitle_text_x,
      subtitle_text_y,
      ALLEGRO_ALIGN_CENTER,
      subtitle_text.c_str()
   );
}


void GameWonScreen::start()
{
   user_event_emitter.emit_play_level_1_music_event();
}


void GameWonScreen::primary_timer_func()
{
   al_clear_to_color(AllegroFlare::color::black);

   draw_you_have_won_banner();
}


void GameWonScreen::key_down_func(ALLEGRO_EVENT *ev)
{
   //user_event_emitter.emit_start_title_screen_event();
}


} // Screens
} // DragonWrath


