#pragma once


#include <AllegroFlare/ElementID.hpp>


namespace DragonWrath
{
   namespace Levels
   {
      class Base : public AllegroFlare::ElementID
      {
      public:
         Base();
         ~Base();

         void update_all();
         void cleanup_all();
         void draw_all();
      };
   }
}



