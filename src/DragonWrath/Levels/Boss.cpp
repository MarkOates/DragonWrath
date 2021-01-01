
#include <DragonWrath/Levels/Boss.hpp>
#include <DragonWrath/LevelTypeNames.hpp>
#include <DragonWrath/EntityTypeNames.hpp>
#include <DragonWrath/EntityFactory.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>
#include <allegro5/allegro.h>


namespace DragonWrath
{
namespace Levels
{


Boss::Boss(
      AllegroFlare::Framework &framework,
      DragonWrath::UserEventEmitter &user_event_emitter
   )
   : DragonWrath::Levels::Base(BOSS, user_event_emitter)
   , completed(false)
   , started_at(0)
   , framework(framework)
{}


Boss::~Boss()
{
}



void Boss::start()
{
   user_event_emitter.emit_play_final_boss_music();
   spawn_super_boss();
}


void Boss::spawn_super_boss()
{
   DragonWrath::Entities::Enemies::SuperBoss *super_boss = new DragonWrath::Entities::Enemies::SuperBoss(this);
   super_boss->bitmap.bitmap(framework.bitmap("enemies/bosses/attack_loop_2.png"));
   super_boss->bitmap.align(0.5, 0.5);
   super_boss->bitmap.scale(6, 6);
   super_boss->bitmap.flip(true, false);
   super_boss->place.size = AllegroFlare::vec2d(100, 100);
}


void Boss::update_level_specific_behavior()
{
   SceneCollectionHelper collection_helper(this);
   DragonWrath::Entities::Enemies::SuperBoss *super_boss = collection_helper.get_super_boss();

   if (!super_boss) activate_completed();
   if (super_boss && super_boss->is_dead()) activate_completed();
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



