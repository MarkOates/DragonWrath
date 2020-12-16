#include <DragonWrath/GameplayScreenHud.hpp>

#include <sstream>


namespace DragonWrath
{


GameplayScreenHud::GameplayScreenHud(AllegroFlare::Framework &framework)
   : bitmap_bin(framework.get_bitmap_bin_ref())
   , font_bin(framework.get_font_bin_ref())
   , player_health(0)
   , player_max_health(10)
{
}


GameplayScreenHud::~GameplayScreenHud()
{
}


void GameplayScreenHud::draw()
{
   ALLEGRO_FONT *font = font_bin.auto_get("ChronoTrigger.ttf 32");
   std::stringstream health_text;
   health_text << player_health << "/" << player_max_health;

   al_draw_text(font, ALLEGRO_COLOR{1.0, 1.0, 1.0, 1.0}, 10, 10, 0, health_text.str().c_str());
}


void GameplayScreenHud::set_player_health(int player_health)
{
   this->player_health = player_health;
}


void GameplayScreenHud::set_player_max_health(int player_max_health)
{
   this->player_max_health = player_max_health;
}


}


