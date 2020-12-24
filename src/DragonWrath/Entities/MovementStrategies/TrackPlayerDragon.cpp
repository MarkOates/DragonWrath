

#include <DragonWrath/Entities/MovementStrategies/TrackPlayerDragon.hpp>

#include <allegro_flare/path2d.h>


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


void TrackPlayerDragon::update()
{
   if (entity)
   {
      // logic TODO here
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


