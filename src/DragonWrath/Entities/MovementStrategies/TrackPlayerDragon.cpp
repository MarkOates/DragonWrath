

#include <DragonWrath/Entities/MovementStrategies/TrackPlayerDragon.hpp>

#include <DragonWrath/Levels/Base.hpp>
#include <DragonWrath/SceneCollectionHelper.hpp>
#include <allegro_flare/path2d.h>
#include <sstream>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategies
{


TrackPlayerDragon::TrackPlayerDragon(DragonWrath::Entities::Base *entity, float speed)
   : DragonWrath::Entities::MovementStrategies::Base()
   , entity(entity)
   , speed(speed)
{
}


TrackPlayerDragon::~TrackPlayerDragon()
{
}


void TrackPlayerDragon::initialize()
{
   if (entity)
   {
      DragonWrath::Levels::Base *root = static_cast<DragonWrath::Levels::Base *>(entity->get_root());
      DragonWrath::SceneCollectionHelper scene_collection_helper(root);
      DragonWrath::Entities::PlayerDragon *player_dragon = scene_collection_helper.get_player_dragon();
      float speed = 8;

      if (player_dragon)
      {
         AllegroFlare::vec2d direction_vector =
            (player_dragon->place.position - entity->place.position).normalized();
         entity->velocity.position = direction_vector * speed;
      }
      else
      {
         entity->velocity.x = -speed;
         entity->velocity.y = 0;
      }
   }
}


void TrackPlayerDragon::update()
{
   if (entity)
   {
      AllegroFlare::ElementID *root = entity->get_root();
      if (root)
      {
         // this is making the assumption that the root will always be the DragonWrath::Levels::Base*
         DragonWrath::Levels::Base *level = static_cast<DragonWrath::Levels::Base *>(root);
         DragonWrath::SceneCollectionHelper scene_collection_helper(level);
         DragonWrath::Entities::PlayerDragon *player_dragon = scene_collection_helper.get_player_dragon();

         if (player_dragon)
         {
            AllegroFlare::vec2d direction_vector =
               (player_dragon->place.position - entity->place.position).normalized();
            entity->velocity.position = direction_vector * speed;
         }
         else
         {
            // expected behavior:
            // player_dragon has been removed from the scene, and is no longer able to be tracked.
         }
      }
      else
      {
         std::stringstream error_message;
         error_message << "TrackPlayerDragon::update(): error: root is unexpectedly nullptr" << std::endl;
         throw std::runtime_error(error_message.str());
      }
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


