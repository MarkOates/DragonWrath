

#include <World/BasicScreens/Factory.hpp>

#include <World/BasicScreens/TitleScreen.hpp>
#include <World/BasicScreens/GameplayScreen.hpp>
#include <World/BasicScreens/GameOverScreen.hpp>
#include <World/BasicScreens/GameWonScreen.hpp>

#include <sstream>


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


AllegroFlare::Screen *Factory::create_from_identifier(std::string identifier)
{
   if (identifier == "TITLE_SCREEN") return create_title_screen();
   if (identifier == "GAMEPLAY_SCREEN") return create_gameplay_screen();
   if (identifier == "GAME_OVER_SCREEN") return create_game_over_screen();
   if (identifier == "GAME_WON_SCREEN") return create_game_won_screen();

   std::stringstream error_message;
   error_message
      << "ScreenFactory::create_from_identifier(): error: "
      << "unrecognized identifier \""
      << identifier
      << "\"";
   throw std::runtime_error(error_message.str());
}


} // BasicScreens
} // World


