#pragma once


#include <DragonWrath/Entities/Enemies/Base.hpp>
#include <DragonWrath/Entities/MovementStrategies/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Enemies
      {
         class PurpleDragon : public DragonWrath::Entities::Enemies::Base
         {
         private:
            DragonWrath::Entities::MovementStrategies::Base *movement_strategy;

         public:
            PurpleDragon(ElementID *parent, float x, float y);
            ~PurpleDragon();

            void update() override;
         };
      }
   }
}


