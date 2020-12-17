#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class MoveLeft : public DragonWrath::Entities::MovementStrategies::Base
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


