#include <DragonWrath/GameplayScreenHud.hpp>


namespace DragonWrath
{


GameplayScreenHud::GameplayScreenHud(AllegroFlare::Framework &framework)
   : bitmap_bin(framework.get_bitmap_bin_ref())
   , font_bin(framework.get_font_bin_ref())
{
}


GameplayScreenHud::~GameplayScreenHud()
{
}


void GameplayScreenHud::draw()
{
   ALLEGRO_FONT *font = font_bin.auto_get("ChronoTrigger.ttf 32");
   std::string health_text = "8 / 10";
   al_draw_text(font, ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0}, 10, 10, 0, health_text.c_str());
}


}


