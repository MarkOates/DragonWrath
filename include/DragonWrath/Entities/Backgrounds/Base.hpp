#pragma once


#include <DragonWrath/Entities/Base.hpp>

#include <AllegroFlare/BitmapBin.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Backgrounds
      {
         class Base : public DragonWrath::Entities::Base
         {
         private:
            AllegroFlare::BitmapBin &bitmap_bin;
            float offset_x;
            float offset_y;

         public:
            Base(AllegroFlare::ElementID *parent, AllegroFlare::BitmapBin &bitmap_bin);
            ~Base();

            void draw() override;
            void draw_foregrounds();
         };
      }
   }
}


