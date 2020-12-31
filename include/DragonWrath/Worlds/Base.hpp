#pragma once


#include <DragonWrath/Levels/Base.hpp>
#include <AllegroFlare/Framework.hpp>


namespace DragonWrath
{
   namespace Worlds
   {
      class Base
      {
      private:
         AllegroFlare::Framework &framework;
         DragonWrath::UserEventEmitter &user_event_emitter;
         std::string title;
         std::vector<std::string> levels_to_load;
         int current_level_index_num;
         DragonWrath::Levels::Base *current_level;

         bool level_exists_at_current_index();
         bool next_level_exists();

      public:
         Base(AllegroFlare::Framework &framework, DragonWrath::UserEventEmitter &user_event_emitter, std::string title, std::vector<std::string> levels_to_load);
         ~Base();

         std::string get_title();

         DragonWrath::Levels::Base *reload_current_level();
         DragonWrath::Levels::Base *create_next_level_and_destroy_current();
      };
   }
}



