#pragma once

#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>
#include <DragonWrath/Entities/Enemies/Base.hpp>
#include <DragonWrath/Entities/MovementStrategies/Base.hpp>


namespace DragonWrath
{
   namespace Entities
   {
      namespace Enemies
      {
         class SuperBoss : public DragonWrath::Entities::Enemies::Base
         {
         private:
            DragonWrath::Entities::MovementStrategies::Base *current_movement_strategy;
            float started_at;
            bool initialized;
            float timer;

                       // start // duration
            std::vector<std::tuple<float, float, DragonWrath::Entities::MovementStrategies::Base*>>
               movement_strategy_playlist_items;

            float time_since_start();

         public:
            SuperBoss(AllegroFlare::ElementID *parent);
           ~SuperBoss();

            void initialize();

            void update() override;
         };
      }
   }
}

