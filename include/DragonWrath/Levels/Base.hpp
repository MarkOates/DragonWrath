#pragma once


#include <AllegroFlare/ElementID.hpp>


namespace DragonWrath
{
   namespace Levels
   {
      class Base : public AllegroFlare::ElementID
      {
      public:
         Base(std::string type);
         ~Base();

         virtual void update();

         void update_all();
         void cleanup_all();
         void draw_all();

         bool is_type(std::string type);
      };
   }
}



