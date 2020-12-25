#pragma once


#include <DragonWrath/Entities/PowerUps/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace PowerUps
      {
         class ShieldBoost : public DragonWrath::Entities::PowerUps::Base
         {
         public:
            ShieldBoost(ElementID *parent, float x, float y);
            ~ShieldBoost();
         };
      }
   }
}


