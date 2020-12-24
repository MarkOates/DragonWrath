#pragma once

#include <AllegroFlare/Framework.hpp>
#include <DragonWrath/Levels/Base.hpp>


class EnemyToSpawn
{
public:
  bool spawned;
  float spawn_time;
  std::string enemy_type;
  float spawn_x;
  float spawn_y;
  std::string movement_strategy;

  EnemyToSpawn(
        float spawn_time,
        std::string enemy_type,
        float spawn_x,
        float spawn_y,
        std::string movement_strategy
     );
  ~EnemyToSpawn();
};


namespace DragonWrath
{
   namespace Levels
   {
      class TimedScroll : public DragonWrath::Levels::Base
      {
      private:
         AllegroFlare::Framework &framework;
         float timer;
         float duration_to_end;
         const float timer_step;
         std::vector<EnemyToSpawn> enemies_to_spawn;

      public:
         TimedScroll(
               AllegroFlare::Framework &framework,
               DragonWrath::UserEventEmitter &user_event_emitter,
               float duration,
               std::vector<EnemyToSpawn> enemies_to_spawn={}
            );
         ~TimedScroll();

         void update_level_specific_behavior() override;

         float get_timer();

         bool is_completed() override;
      };
   }
}
