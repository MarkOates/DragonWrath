#pragma once


#include <DragonWrath/Entities/Terrains/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Terrains
      {
         class Pillar : public DragonWrath::Entities::Terrains::Base
         {
         private:
            ALLEGRO_BITMAP *texture;

         public:
            Pillar(AllegroFlare::ElementID *parent, float x, float y, float w, float h, ALLEGRO_BITMAP *texture);
            virtual ~Pillar();

            void draw() override;
         };
      }
   }
}



