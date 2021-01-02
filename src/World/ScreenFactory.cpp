

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


AllegroFlare::Screen *ScreenFactory::create_from_identifier(std::string identifier)
{
   return nullptr;
}


} // namespace World



