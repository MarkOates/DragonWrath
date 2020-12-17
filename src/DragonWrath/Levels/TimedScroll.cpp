
#include <DragonWrath/Levels/TimedScroll.hpp>
#include <DragonWrath/LevelTypeNames.hpp>
#include <allegro5/allegro.h>


EnemyToSpawn::EnemyToSpawn(float spawn_time, std::string enemy_type, float spawn_x, float spawn_y, std::string movement_strategy)
   : spawn_time(spawn_time)
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


TimedScroll::TimedScroll(std::vector<EnemyToSpawn> enemies_to_spawn)
   : DragonWrath::Levels::Base(TIMED_SCROLL)
   , timer(0)
   , timer_step(ALLEGRO_BPS_TO_SECS(60))
   , enemies_to_spawn(enemies_to_spawn)
{}


TimedScroll::~TimedScroll()
{}


void TimedScroll::update()
{
   timer += timer_step;
}


float TimedScroll::get_timer()
{
   return timer;
}


} // namespace Levels
} // namespace DragonWrath


