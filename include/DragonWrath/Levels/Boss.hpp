#pragma once

#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/Entities/Base.hpp>


namespace DragonWrath
{
   namespace Levels
   {
      class Boss : public DragonWrath::Levels::Base
      {
      public:
         class SuperBoss : public DragonWrath::Entities::Base
         {
         public:
            bool spawned;
            float spawn_time;
            std::string enemy_type;
            float spawn_x;
            float spawn_y;
            std::string movement_strategy;

            SuperBoss(
                  AllegroFlare::ElementID *parent,
                  float spawn_time,
                  std::string enemy_type,
                  float spawn_x,
                  float spawn_y,
                  std::string movement_strategy
                  );
           ~SuperBoss();
         };

         bool completed;

      private:
         AllegroFlare::Framework &framework;

      public:
         Boss(
               AllegroFlare::Framework &framework,
               DragonWrath::UserEventEmitter &user_event_emitter
            );
         ~Boss();

         void spawn_super_boss();

         void update_level_specific_behavior() override;

         bool is_completed() override;
         void activate_completed();
         void deactivate_completed();
      };
   }
}
