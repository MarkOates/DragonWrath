#pragma once


#include <DragonWrath/Entities/PowerUps/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace PowerUps
      {
         class SpeedBoost : public DragonWrath::Entities::PowerUps::Base
         {
         public:
            SpeedBoost(ElementID *parent, float x, float y);
            ~SpeedBoost();
         };
      }
   }
}


