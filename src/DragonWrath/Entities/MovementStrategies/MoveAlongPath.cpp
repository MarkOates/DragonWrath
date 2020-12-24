

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
{
}


MoveAlongPath::~MoveAlongPath()
{
}


void MoveAlongPath::update()
{
   if (entity)
   {
      allegro_flare::path2d horseshoe_path;

      float screen_width = 1920;
      float screen_height = 1080;

      horseshoe_path.add_point(screen_width - 10, screen_height * 0.25); // top right
      horseshoe_path.add_point(screen_width / 2, screen_height * 0.25); // top left
      horseshoe_path.add_point(screen_width / 2, screen_height * 0.75); // bottom left
      horseshoe_path.add_point(screen_width - 10, screen_height * 0.75); // bottom right

      horseshoe_path.draw_outline(al_color_name("red"), 3.0f);
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


