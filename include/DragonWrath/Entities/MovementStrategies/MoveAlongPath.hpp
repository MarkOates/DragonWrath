#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class MoveAlongPath : public DragonWrath::Entities::MovementStrategies::Base
         {
         private:
            DragonWrath::Entities::Base *entity;
            float speed;

         public:
            MoveAlongPath(DragonWrath::Entities::Base *entity, float speed=5);
            ~MoveAlongPath();

            void update() override;
         };
      }
   }
}


