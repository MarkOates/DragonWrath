

#include <DragonWrath/Worlds/Base.hpp>

#include <DragonWrath/LevelFactory.hpp>


namespace DragonWrath
{
namespace Worlds
{


Base::Base(AllegroFlare::Framework &framework, std::string title, std::vector<std::string> levels_to_load)
   : framework(framework)
   , title(title)
   , levels_to_load({ "level_1", "level_2" })
   , current_level_index_num(-1)
   , current_level(nullptr)
{
}


Base::~Base()
{
}


std::string Base::get_title()
{
   return title;
}


DragonWrath::Levels::Base *Base::create_next_level_and_destroy_current()
{
   if (current_level)
   {
      delete current_level;
      current_level = nullptr;
   }

   if (next_level_exists())
   {
      DragonWrath::LevelFactory level_factory(framework);

      std::string next_level_identifier = levels_to_load[current_level_index_num + 1];
      std::cout << "loading next level \"" << next_level_identifier << "\"...";
      current_level = level_factory.create_level_by_identifier(next_level_identifier);
      std::cout << "done." << std::endl;

      current_level_index_num++;
   }

   return current_level;
}


bool Base::next_level_exists()
{
   std::cout << "current_level_index_num " << current_level_index_num << std::endl;
   std::cout << "levels_to_load.size() " << levels_to_load.size() << std::endl;

   return (current_level_index_num + 1) < (int)levels_to_load.size();
}



} // namespace Worlds
} // namespace DragonWrath


