
#include <DragonWrath/Levels/Boss.hpp>
#include <DragonWrath/LevelTypeNames.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <allegro5/allegro.h>


namespace DragonWrath
{
namespace Levels
{


Boss::SuperBoss::SuperBoss(AllegroFlare::ElementID *parent, float spawn_time, std::string enemy_type, float spawn_x, float spawn_y, std::string movement_strategy)
   : DragonWrath::Entities::Base(parent, "SuperBoss", spawn_x, spawn_y)
   , spawned(false)
   , spawn_time(spawn_time)
   , enemy_type(enemy_type)
   , spawn_x(spawn_x)
   , spawn_y(spawn_y)
   , movement_strategy(movement_strategy)
{}


Boss::SuperBoss::~SuperBoss()
{}



Boss::Boss(
      AllegroFlare::Framework &framework,
      DragonWrath::UserEventEmitter &user_event_emitter
   )
   : DragonWrath::Levels::Base(TIMED_SCROLL, user_event_emitter)
   , framework(framework)
{}


Boss::~Boss()
{}


void Boss::spawn_super_boss()
{
}


void Boss::update_level_specific_behavior()
{
   DragonWrath::EntityFactory entity_factory(framework, this);
}


bool Boss::is_completed()
{
   return completed;
}


void Boss::activate_completed()
{
   completed = true;
}


void Boss::deactivate_completed()
{
   completed = false;
}


} // namespace Levels
} // namespace DragonWrath



