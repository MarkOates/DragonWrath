

#include <DragonWrath/Entities/MovementStrategies/MoveAlongPath.hpp>

#include <allegro_flare/path2d.h>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategies
{


MoveAlongPath::MoveAlongPath(DragonWrath::Entities::Base *entity, float speed)
   : DragonWrath::Entities::MovementStrategies::Base()
   , entity(entity)
   , speed(speed)
   , position_along_path(0.0)
{
}


MoveAlongPath::~MoveAlongPath()
{
}


void MoveAlongPath::update()
{
   if (entity)
   {
      position_along_path += speed;


      allegro_flare::path2d path;

      float screen_width = 1920;
      float screen_height = 1080;

      path.add_point(screen_width - 10, screen_height * 0.25); // top right
      path.add_point(screen_width / 2, screen_height * 0.25); // top left
      path.add_point(screen_width / 2, screen_height * 0.75); // bottom left
      path.add_point(screen_width - 10, screen_height * 0.75); // bottom right


      if (position_along_path <= 0.0) position_along_path = 0.0;
      if (position_along_path >= path.length()) position_along_path = path.length();


      AllegroFlare::vec2d coordinate_at_position_along_path = path.coordinate_at(position_along_path);
      entity->place.position.x = coordinate_at_position_along_path.x;
      entity->place.position.y = coordinate_at_position_along_path.y;
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


