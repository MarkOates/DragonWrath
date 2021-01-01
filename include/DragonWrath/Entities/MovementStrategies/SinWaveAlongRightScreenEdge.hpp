#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class SinWaveAlongRightScreenEdge : public DragonWrath::Entities::MovementStrategies::Base
         {
         private:
            DragonWrath::Entities::Base *entity;
            float speed;

         public:
            SinWaveAlongRightScreenEdge(DragonWrath::Entities::Base *entity, float speed=5);
            ~SinWaveAlongRightScreenEdge();

            void update() override;
         };
      }
   }
}


