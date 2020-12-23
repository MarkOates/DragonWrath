

#include <DragonWrath/Entities/MovementStrategies/MoveRight.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategies
{


MoveRight::MoveRight(DragonWrath::Entities::Base *entity, float speed)
   : DragonWrath::Entities::MovementStrategies::Base()
   , entity(entity)
   , speed(speed)
{
}


MoveRight::~MoveRight()
{
}


void MoveRight::update()
{
   if (entity)
   {
      entity->velocity.position.y = 0;
      entity->velocity.position.x = speed;
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


