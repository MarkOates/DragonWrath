#pragma once


#include <AllegroFlare/ElementID.hpp>


namespace DragonWrath
{
   namespace Levels
   {
      class Base : public AllegroFlare::ElementID
      {
      private:
         float floor_min_y, floor_max_y;

      public:
         Base();
         ~Base();

         void set_y_bounds(float min_y, float max_y);
         void get_y_bounds(float *min_y, float *max_y);

         void update_all();
         void cleanup_all();
         void draw_all();
      };
   }
}



