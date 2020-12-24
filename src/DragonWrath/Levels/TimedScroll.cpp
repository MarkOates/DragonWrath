
#include <DragonWrath/Levels/TimedScroll.hpp>
#include <DragonWrath/LevelTypeNames.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
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


TimedScroll::TimedScroll(
      AllegroFlare::Framework &framework,
      DragonWrath::UserEventEmitter &user_event_emitter,
      float duration_to_end,
      std::vector<EnemyToSpawn> enemies_to_spawn
   )
   : DragonWrath::Levels::Base(TIMED_SCROLL, user_event_emitter)
   , framework(framework)
   , timer(0)
   , duration_to_end(duration_to_end)
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
         if (enemy_to_spawn.enemy_type == YELLOW_DRAGON)
         {
            entity_factory.create_yellow_dragon(
               enemy_to_spawn.spawn_x,
               enemy_to_spawn.spawn_y,
               enemy_to_spawn.movement_strategy
            );
         }
         else if (enemy_to_spawn.enemy_type == BLUE_DRAGON)
         {
            entity_factory.create_blue_dragon(
               enemy_to_spawn.spawn_x,
               enemy_to_spawn.spawn_y,
               enemy_to_spawn.movement_strategy
            );
         }
         else if (enemy_to_spawn.enemy_type == GREEN_DRAGON)
         {
            entity_factory.create_green_dragon(
               enemy_to_spawn.spawn_x,
               enemy_to_spawn.spawn_y,
               enemy_to_spawn.movement_strategy
            );
         }
         else if (enemy_to_spawn.enemy_type == RED_DRAGON)
         {
            entity_factory.create_red_dragon(
               enemy_to_spawn.spawn_x,
               enemy_to_spawn.spawn_y,
               enemy_to_spawn.movement_strategy
            );
         }
         else if (enemy_to_spawn.enemy_type == PURPLE_DRAGON)
         {
            entity_factory.create_purple_dragon(
               enemy_to_spawn.spawn_x,
               enemy_to_spawn.spawn_y
            );
         }
         else
         {
            std::stringstream error_message;
            error_message << "TimedScroll::update_level_specific_behavior()"
               << "error: undefined enemy_type for enemy_to_spawn \""
               << enemy_to_spawn.enemy_type
               << "\""
               << std::endl;
            throw std::runtime_error(error_message.str());
         }

         enemy_to_spawn.spawned = true;
      }
   }
}


float TimedScroll::get_timer()
{
   return timer;
}


bool TimedScroll::is_completed()
{
   return timer >= duration_to_end;
}



} // namespace Levels
} // namespace DragonWrath


