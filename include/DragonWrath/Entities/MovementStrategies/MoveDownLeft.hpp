#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class MoveDownLeft : public DragonWrath::Entities::MovementStrategies::Base
         {
         private:
            DragonWrath::Entities::Base *entity;
            float speed;

         public:
            MoveDownLeft(DragonWrath::Entities::Base *entity, float speed=5);
            ~MoveDownLeft();

            void update() override;
         };
      }
   }
}


