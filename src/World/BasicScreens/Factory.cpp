

#include <World/BasicScreens/Factory.hpp>

#include <World/BasicScreens/TitleScreen.hpp>
#include <World/BasicScreens/GameplayScreen.hpp>
#include <World/BasicScreens/GameOverScreen.hpp>
#include <World/BasicScreens/GameWonScreen.hpp>


namespace World
{
namespace BasicScreens
{


Factory::Factory(AllegroFlare::Display *display)
   : World::ScreenFactory()
   , display(display)
{}


Factory::~Factory()
{}


AllegroFlare::Screen *Factory::create_title_screen()
{
   return new World::BasicScreens::TitleScreen(display);
}


AllegroFlare::Screen *Factory::create_gameplay_screen()
{
   return new World::BasicScreens::GameplayScreen(display);
}


AllegroFlare::Screen *Factory::create_game_over_screen()
{
   return new World::BasicScreens::GameOverScreen(display);
}


AllegroFlare::Screen *Factory::create_game_won_screen()
{
   return new World::BasicScreens::GameWonScreen(display);
}


} // BasicScreens
} // World


