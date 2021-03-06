#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class StayStill : public DragonWrath::Entities::MovementStrategies::Base
         {
         private:
            DragonWrath::Entities::Base *entity;

         public:
            StayStill(DragonWrath::Entities::Base *entity);
            ~StayStill();

            void update() override;
         };
      }
   }
}


