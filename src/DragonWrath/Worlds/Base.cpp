

#include <DragonWrath/Worlds/Base.hpp>

#include <DragonWrath/LevelFactory.hpp>


namespace DragonWrath
{
namespace Worlds
{


Base::Base(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter, 
std::string title, std::vector<std::string> levels_to_load)
   : framework(framework)
   , user_event_emitter(user_event_emitter)
   , title(title)
   , levels_to_load(levels_to_load)
   , current_level_index_num(-1)
   , current_level(nullptr)
{
}


Base::~Base()
{
}


bool Base::level_exists_at_current_index()
{
   if (current_level_index_num < 0) return false;
   if (current_level_index_num >= levels_to_load.size()) return false;
   return true;
}


bool Base::next_level_exists()
{
   return (current_level_index_num + 1) < (int)levels_to_load.size();

}


std::string Base::get_title()
{
   return title;
}


DragonWrath::Levels::Base *Base::reload_current_level()
{
   if (current_level)
   {
      delete current_level;
      current_level = nullptr;
   }

   if (level_exists_at_current_index())
   {
      DragonWrath::LevelFactory level_factory(framework, user_event_emitter);

      std::string current_level_identifier = levels_to_load[current_level_index_num];
      current_level = level_factory.create_level_by_identifier(current_level_identifier);
   }

   return current_level;
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
      DragonWrath::LevelFactory level_factory(framework, user_event_emitter);

      std::string next_level_identifier = levels_to_load[current_level_index_num + 1];
      current_level = level_factory.create_level_by_identifier(next_level_identifier);

      current_level_index_num++;
   }

   return current_level;
}


} // namespace Worlds
} // namespace DragonWrath


