#pragma once


#include <DragonWrath/Entities/PowerUps/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace PowerUps
      {
         class OneUp : public DragonWrath::Entities::PowerUps::Base
         {
         public:
            OneUp(ElementID *parent, float x, float y);
            ~OneUp();
         };
      }
   }
}


