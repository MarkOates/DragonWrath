#pragma once


#include <DragonWrath/Entities/PowerUps/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace PowerUps
      {
         class BulletBoost : public DragonWrath::Entities::PowerUps::Base
         {
         public:
            BulletBoost(ElementID *parent, float x, float y);
            ~BulletBoost();
         };
      }
   }
}


