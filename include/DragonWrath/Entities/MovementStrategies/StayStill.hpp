#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategy
      {
         class StayStill : public DragonWrath::Entities::MovementStrategy::Base
         {
         public:
            StayStill();
            ~StayStill();

            void update() override;
         };
      }
   }
}


