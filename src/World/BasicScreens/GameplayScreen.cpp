
#include <World/BasicScreens/GameplayScreen.hpp>

#include <allegro5/allegro_color.h>


namespace World
{
namespace BasicScreens
{


GameplayScreen::GameplayScreen(AllegroFlare::Display *display)
   : AllegroFlare::Screen(display)
{
}


GameplayScreen::~GameplayScreen()
{
}


void GameplayScreen::primary_timer_func()
{
   al_clear_to_color(al_color_name("blue"));
}


}
}


