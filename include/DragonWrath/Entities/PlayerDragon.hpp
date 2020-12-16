#pragma once


#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      class PlayerDragon : public DragonWrath::Entities::Base
      {
      public:
         PlayerDragon(ElementID *parent, float x, float y);
         ~PlayerDragon();
      };
   }
}


