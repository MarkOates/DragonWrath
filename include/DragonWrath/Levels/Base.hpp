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
         float width;

      public:
         Base(int width);
         ~Base();

         void set_y_bounds(float min_y, float max_y);
         void get_y_bounds(float *min_y, float *max_y);
         float get_width();

         void update_all();
         void cleanup_all();
         void draw_all();
      };
   }
}



