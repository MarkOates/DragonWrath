#pragma once


#include <AllegroFlare/ElementID.hpp>


namespace DragonWrath
{
   namespace Levels
   {
      class Base : public AllegroFlare::ElementID
      {
      private:
         virtual void update_level_specific_behavior() = 0;
         void update_collisions();

      public:
         Base(std::string type);
         ~Base();

         void update();
         void draw();
         void cleanup();

         bool is_type(std::string type);
      };
   }
}



