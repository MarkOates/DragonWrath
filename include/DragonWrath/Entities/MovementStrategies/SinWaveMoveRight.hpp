#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class SinWaveMoveRight : public DragonWrath::Entities::MovementStrategies::Base
         {
         private:
            DragonWrath::Entities::Base *entity;
            float speed;

         public:
            SinWaveMoveRight(DragonWrath::Entities::Base *entity, float speed=5);
            ~SinWaveMoveRight();

            void update() override;
         };
      }
   }
}


