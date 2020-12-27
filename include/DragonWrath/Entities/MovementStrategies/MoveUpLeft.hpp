#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class MoveUpLeft : public DragonWrath::Entities::MovementStrategies::Base
         {
         private:
            DragonWrath::Entities::Base *entity;
            float speed;

         public:
            MoveUpLeft(DragonWrath::Entities::Base *entity, float speed=5);
            ~MoveUpLeft();

            void update() override;
         };
      }
   }
}


