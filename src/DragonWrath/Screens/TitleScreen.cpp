

#include <DragonWrath/Screens/TitleScreen.hpp>

#include <allegro5/allegro_color.h>


namespace DragonWrath
{
namespace Screens
{


TitleScreen::TitleScreen(AllegroFlare::Framework &framework)
   : framework(framework)
{
}


TitleScreen::~TitleScreen()
{
}


void TitleScreen::primary_timer_func()
{
   ALLEGRO_FONT *title_text_font = framework.font("ChronoTrigger.ttf 300");
   ALLEGRO_FONT *subtitle_text_font = framework.font("ChronoTrigger.ttf 60");

   std::string title_text = "DRAGONWRATH";
   std::string subtitle_text = "Press ANY key to START";

   ALLEGRO_COLOR title_text_color = al_color_name("yellow");
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


void TitleScreen::key_down_func(ALLEGRO_EVENT *ev)
{
   framework.shutdown_program = true;
}


} // Screens
} // DragonWrath


