#pragma once

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

  EnemyToSpawn(float spawn_time, std::string enemy_type, float spawn_x, float spawn_y, std::string movement_strategy);
  ~EnemyToSpawn();
};


namespace DragonWrath
{
   namespace Levels
   {
      class TimedScroll : public DragonWrath::Levels::Base
      {
      private:
         float timer;
         const float timer_step;
         std::vector<EnemyToSpawn> enemies_to_spawn;

      public:
         TimedScroll(std::vector<EnemyToSpawn> enemies_to_spawn={});
         ~TimedScroll();

         void update() override;
         float get_timer();
      };
   }
}
