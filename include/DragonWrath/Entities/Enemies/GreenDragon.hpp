#pragma once


#include <DragonWrath/Entities/Enemies/Base.hpp>
#include <DragonWrath/Entities/MovementStrategies/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Enemies
      {
         class GreenDragon : public DragonWrath::Entities::Enemies::Base
         {
         private:
            //TODO DragonWrath::Entities::MovementStrategies::Base *movement_strategy;
            std::string movement_strategy;

         public:
            GreenDragon(ElementID *parent, float x, float y);
            ~GreenDragon();

            void update() override;

            void set_movement_strategy(std::string movement_strategy);
         };
      }
   }
}


