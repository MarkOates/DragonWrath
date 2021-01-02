

#include <World/ScreenFactory.hpp>


namespace World
{


ScreenFactory::ScreenFactory(std::map<std::string, void (World::ScreenFactory::*)()> screen_elements)
   : screen_elements(screen_elements)
{
}


ScreenFactory::~ScreenFactory()
{
}


AllegroFlare::Screen *ScreenFactory::create_title_screen()
{
   return nullptr;
}


AllegroFlare::Screen *ScreenFactory::create_gameplay_screen()
{
   return nullptr;
}


AllegroFlare::Screen *ScreenFactory::create_game_over_screen()
{
   return nullptr;
}


AllegroFlare::Screen *ScreenFactory::create_game_won_screen()
{
   return nullptr;
}


AllegroFlare::Screen *ScreenFactory::create_from_identifier(std::string identifier)
{
   return nullptr;
}


} // namespace World



