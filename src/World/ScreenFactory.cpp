

#include <World/ScreenFactory.hpp>


namespace World
{


ScreenFactory::ScreenFactory()
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


} // namespace World



