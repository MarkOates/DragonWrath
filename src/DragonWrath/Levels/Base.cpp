


#include <DragonWrath/Entities/Base.hpp>
//#include <dungeon/helpers/scene_collection_helper.hpp>
//#include <dungeon/helpers/scene_collision_helper.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/EntityAttributeNames.hpp>
#include <DragonWrath/SceneCollisionHelper.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>
#include <allegro5/allegro.h>
#include <algorithm>



namespace DragonWrath
{
namespace Levels
{


Base::Base(std::string type, DragonWrath::UserEventEmitter &user_event_emitter)
   : ElementID(nullptr)
   , user_event_emitter(user_event_emitter)
   , level_end_padding_timer(5)
{
   set("type", type);
}



Base::~Base()
{
}



void Base::update()
{
   if (is_completed()) level_end_padding_timer -= 1.0/60.0f; //ALLEGRO_BPS_TO_SECS(60);

   update_level_specific_behavior();
   update_collisions();
}



void Base::update_collisions()
{
   SceneCollisionHelper collision_helper(this, user_event_emitter);
   collision_helper.resolve_collisions();
}



void Base::draw()
{
   SceneCollectionHelper collection_helper(this);

   std::vector<Entities::Base *> y_sorted_entities = collection_helper.get_all_entities_y_sorted();

   for (auto &entity : y_sorted_entities) if (!entity->exists(ALWAYS_ON_TOP)) entity->draw();
   for (auto &entity : y_sorted_entities) if (entity->exists(ALWAYS_ON_TOP)) entity->draw();
}



void Base::cleanup()
{
   SceneCollectionHelper collection_helper(this);

   for (auto &descendant : collection_helper.get_all_flagged_for_deletion())
      delete descendant;
}



bool Base::is_type(std::string type)
{
   return exists("type", type);
}



bool Base::is_ready_to_destroy()
{
   return level_end_padding_timer <= 0.0f;
}



} // namespace Levels
} // namespace DragonWrath


