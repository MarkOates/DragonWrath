
#include <World/BasicScreens/GameOverScreen.hpp>

#include <allegro5/allegro_color.h>


namespace World
{
namespace BasicScreens
{


GameOverScreen::GameOverScreen(AllegroFlare::Display *display)
   : AllegroFlare::Screen(display)
{
}


GameOverScreen::~GameOverScreen()
{
}


void GameOverScreen::primary_timer_func()
{
   al_clear_to_color(al_color_name("red"));
}


}
}


