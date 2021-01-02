
#include <World/BasicScreens/GameWonScreen.hpp>

#include <allegro5/allegro_color.h>


namespace World
{
namespace BasicScreens
{


GameWonScreen::GameWonScreen(AllegroFlare::Display *display)
   : AllegroFlare::Screen(display)
{
}


GameWonScreen::~GameWonScreen()
{
}


void GameWonScreen::primary_timer_func()
{
   al_clear_to_color(al_color_name("green"));
}


}
}


