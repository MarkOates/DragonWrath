


#include <DragonWrath/Entities/Base.hpp>
//#include <dungeon/helpers/scene_collection_helper.hpp>
//#include <dungeon/helpers/scene_collision_helper.hpp>
#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/EntityAttributeNames.hpp>
#include <algorithm>



namespace DragonWrath
{
namespace Levels
{


Base::Base(int width)
   : ElementID(nullptr)
   , floor_min_y(465)
   , floor_max_y(600)
   , width(width)
{}



Base::~Base()
{
}



void Base::set_y_bounds(float min_y, float max_y)
{
   floor_min_y = min_y;
   floor_max_y = max_y;
}



void Base::get_y_bounds(float *min_y, float *max_y)
{
   *min_y = floor_min_y;
   *max_y = floor_max_y;
}



float Base::get_width()
{
   return width;
}



void Base::update_all()
{
   //SceneCollisionHelper collision_helper(this);
   //collision_helper.resolve_collisions();
}



void Base::cleanup_all()
{
   //SceneCollectionHelper collection_helper(this);

   //for (auto &descendant : collection_helper.get_all_flagged_for_deletion())
      //delete descendant;
}



void Base::draw_all()
{
   //SceneCollectionHelper collection_helper(this);

   //std::vector<Entity::Base *> y_sorted_entities = collection_helper.get_all_entities_y_sorted();

   //for (auto &entity : y_sorted_entities) if (!entity->exists(ALWAYS_ON_TOP)) entity->draw();
   //for (auto &entity : y_sorted_entities) if (entity->exists(ALWAYS_ON_TOP)) entity->draw();
}



} // namespace Levels
} // namespace DragonWrath


