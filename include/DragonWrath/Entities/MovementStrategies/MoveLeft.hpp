#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategy
      {
         class MoveLeft : public DragonWrath::Entities::MovementStrategy::Base
         {
         private:
            DragonWrath::Entities::Base *entity;
            float speed;

         public:
            MoveLeft(DragonWrath::Entities::Base *entity, float speed=5);
            ~MoveLeft();

            void update() override;
         };
      }
   }
}


