#pragma once


#include <DragonWrath/Entities/Enemies/Base.hpp>
#include <DragonWrath/Entities/MovementStrategies/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Enemies
      {
         class BlueDragon : public DragonWrath::Entities::Enemies::Base
         {
         private:
            //TODO DragonWrath::Entities::MovementStrategies::Base *movement_strategy;
            std::string movement_strategy;

         public:
            BlueDragon(ElementID *parent, float x, float y);
            ~BlueDragon();

            void update() override;

            void set_movement_strategy(std::string movement_strategy);
         };
      }
   }
}


