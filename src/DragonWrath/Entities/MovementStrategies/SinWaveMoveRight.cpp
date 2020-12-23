

#include <DragonWrath/Entities/MovementStrategies/SinWaveMoveRight.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategies
{


SinWaveMoveRight::SinWaveMoveRight(DragonWrath::Entities::Base *entity, float speed)
   : DragonWrath::Entities::MovementStrategies::Base()
   , entity(entity)
   , speed(speed)
{
}


SinWaveMoveRight::~SinWaveMoveRight()
{
}


void SinWaveMoveRight::update()
{
   if (entity)
   {
      entity->velocity.position.x = -speed;
      entity->velocity.position.y = sin(al_get_time() * 4) * 10;
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


