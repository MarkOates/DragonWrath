

#include <DragonWrath/Entities/MovementStrategies/SinWaveAlongRightScreenEdge.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategies
{


SinWaveAlongRightScreenEdge::SinWaveAlongRightScreenEdge(DragonWrath::Entities::Base *entity, float speed)
   : DragonWrath::Entities::MovementStrategies::Base()
   , entity(entity)
   , speed(speed)
{
}


SinWaveAlongRightScreenEdge::~SinWaveAlongRightScreenEdge()
{
}


void SinWaveAlongRightScreenEdge::update()
{
   if (entity)
   {
      entity->place.position.x = 1920 / 6 * 5;
      entity->place.position.y = 1080 / 2 + sin(al_get_time() * 2.4) * 300; // * 1080 / 6 * 4;
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


