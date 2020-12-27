#pragma once


#include <DragonWrath/Entities/MovementStrategies/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace MovementStrategies
      {
         class TrackPlayerDragon : public DragonWrath::Entities::MovementStrategies::Base
         {
         private:
            DragonWrath::Entities::Base *entity;
            float speed;

         public:
            TrackPlayerDragon(DragonWrath::Entities::Base *entity, float speed=5);
            ~TrackPlayerDragon();

            void initialize() override;
            void update() override;
         };
      }
   }
}


