#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class StayStill : public DragonWrath::Entities::MovementStrategies::Base
         {
         public:
            StayStill();
            ~StayStill();

            void update() override;
         };
      }
   }
}


