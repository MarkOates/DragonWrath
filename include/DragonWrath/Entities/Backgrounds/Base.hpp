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

            class BackgroundLayer
            {
            public:
               float offset_x;
               float offset_y;
               float offset_scale;
               ALLEGRO_BITMAP *bitmap;
            };
            std::vector<BackgroundLayer> background_layers;

            class ForegroundLayer
            {
            public:
               float offset_x;
               float offset_y;
               float offset_scale;
               ALLEGRO_BITMAP *bitmap;
            };
            std::vector<ForegroundLayer> foreground_layers;

         public:
            Base(AllegroFlare::ElementID *parent, AllegroFlare::BitmapBin &bitmap_bin);
            ~Base();

            void update() override;
            void draw() override;
            void draw_foregrounds();
         };
      }
   }
}


