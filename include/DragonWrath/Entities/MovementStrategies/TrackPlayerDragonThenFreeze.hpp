#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class TrackPlayerDragonThenFreeze : public DragonWrath::Entities::MovementStrategies::Base
         {
         private:
            DragonWrath::Entities::Base *entity;
            float speed;
            float timer;

         public:
            TrackPlayerDragonThenFreeze(DragonWrath::Entities::Base *entity, float speed=15);
            ~TrackPlayerDragonThenFreeze();

            void initialize() override;
            void update() override;
         };
      }
   }
}


