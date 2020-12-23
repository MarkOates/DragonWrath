#pragma once


#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/MovementStrategies/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Enemies
      {
         class PurpleDragon : public DragonWrath::Entities::Base
         {
         private:
            //TODO DragonWrath::Entities::MovementStrategies::Base *movement_strategy;
            std::string movement_strategy;

         public:
            PurpleDragon(ElementID *parent, float x, float y);
            ~PurpleDragon();

            void update() override;

            void set_movement_strategy(std::string movement_strategy);
         };
      }
   }
}


