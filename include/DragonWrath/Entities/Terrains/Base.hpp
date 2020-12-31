#pragma once


#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Terrains
      {
         class Base : public DragonWrath::Entities::Base
         {
         public:
            Base(AllegroFlare::ElementID *parent);
            virtual ~Base();

            virtual void draw() override;
            virtual void update() override;
         };
      }
   }
}



