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
         std::string title;
         std::vector<std::string> levels_to_load;
         int current_level_index_num;
         DragonWrath::Levels::Base *current_level;

      public:
         Base(AllegroFlare::Framework &framework, std::string title, std::vector<std::string> levels_to_load);
         ~Base();

         std::string get_title();

         DragonWrath::Levels::Base *create_next_level_and_destroy_current();

         bool next_level_exists();
      };
   }
}



