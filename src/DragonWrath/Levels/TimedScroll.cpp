
#include <DragonWrath/Levels/TimedScroll.hpp>
#include <DragonWrath/LevelTypeNames.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <allegro5/allegro.h>


EnemyToSpawn::EnemyToSpawn(float spawn_time, std::string enemy_type, float spawn_x, float spawn_y, std::string movement_strategy)
   : spawned(false)
   , spawn_time(spawn_time)
   , enemy_type(enemy_type)
   , spawn_x(spawn_x)
   , spawn_y(spawn_y)
   , movement_strategy(movement_strategy)
{}


EnemyToSpawn::~EnemyToSpawn()
{}


namespace DragonWrath
{
namespace Levels
{


TimedScroll::TimedScroll(AllegroFlare::Framework &framework, std::vector<EnemyToSpawn> enemies_to_spawn)
   : DragonWrath::Levels::Base(TIMED_SCROLL)
   , framework(framework)
   , timer(0)
   , timer_step(ALLEGRO_BPS_TO_SECS(60))
   , enemies_to_spawn(enemies_to_spawn)
{}


TimedScroll::~TimedScroll()
{}


void TimedScroll::update_level_specific_behavior()
{
   timer += timer_step;

   DragonWrath::EntityFactory entity_factory(framework, this);

   for (auto &enemy_to_spawn : enemies_to_spawn)
   {
      if (enemy_to_spawn.spawned) continue;
      if (timer > enemy_to_spawn.spawn_time)
      {
         entity_factory.create_enemy(enemy_to_spawn.spawn_x, enemy_to_spawn.spawn_y);
         enemy_to_spawn.spawned = true;
      }
   }
}


float TimedScroll::get_timer()
{
   return timer;
}


} // namespace Levels
} // namespace DragonWrath


