
#include <World/BasicScreens/TitleScreen.hpp>

#include <allegro5/allegro_color.h>
#include <iostream>


namespace World
{
namespace BasicScreens
{


TitleScreen::TitleScreen(AllegroFlare::Display *display)
   : AllegroFlare::Screen(display)
   , title_text("Title Screen!")
   , title_text_font(nullptr)
{
}


TitleScreen::~TitleScreen()
{
   if (title_text_font) al_destroy_font(title_text_font);
}


void TitleScreen::initialize()
{
   title_text_font = al_create_builtin_font();
}


void TitleScreen::start()
{
}


void TitleScreen::primary_timer_func()
{
   al_clear_to_color(al_color_name("gray"));

   if (title_text_font)
   {
      float text_width = al_get_text_width(title_text_font, title_text.c_str());
      float text_x = 1920 / 2 - text_width / 2;
      al_draw_text(title_text_font, al_color_name("white"), text_x, 1080 / 3, ALLEGRO_ALIGN_CENTER, title_text.c_str());
   }
}


}
}


