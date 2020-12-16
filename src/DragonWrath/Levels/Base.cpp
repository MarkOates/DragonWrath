


#include <DragonWrath/Entities/Base.hpp>
//#include <dungeon/helpers/scene_collection_helper.hpp>
//#include <dungeon/helpers/scene_collision_helper.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/EntityAttributeNames.hpp>
#include <DragonWrath/SceneCollisionHelper.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>
#include <algorithm>



namespace DragonWrath
{
namespace Levels
{


Base::Base()
   : ElementID(nullptr)
{}



Base::~Base()
{
}



void Base::update()
{
}



void Base::update_all()
{
   SceneCollisionHelper collision_helper(this);
   collision_helper.resolve_collisions();
}



void Base::cleanup_all()
{
   SceneCollectionHelper collection_helper(this);

   for (auto &descendant : collection_helper.get_all_flagged_for_deletion())
      delete descendant;
}



void Base::draw_all()
{
   SceneCollectionHelper collection_helper(this);

   std::vector<Entities::Base *> y_sorted_entities = collection_helper.get_all_entities_y_sorted();

   for (auto &entity : y_sorted_entities) if (!entity->exists(ALWAYS_ON_TOP)) entity->draw();
   for (auto &entity : y_sorted_entities) if (entity->exists(ALWAYS_ON_TOP)) entity->draw();
}



} // namespace Levels
} // namespace DragonWrath


