#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class MoveRight : public DragonWrath::Entities::MovementStrategies::Base
         {
         private:
            DragonWrath::Entities::Base *entity;
            float speed;

         public:
            MoveRight(DragonWrath::Entities::Base *entity, float speed=5);
            ~MoveRight();

            void update() override;
         };
      }
   }
}


