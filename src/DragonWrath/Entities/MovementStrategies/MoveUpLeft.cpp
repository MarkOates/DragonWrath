

#include <DragonWrath/Entities/MovementStrategies/MoveUpLeft.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategies
{


MoveUpLeft::MoveUpLeft(DragonWrath::Entities::Base *entity, float speed)
   : DragonWrath::Entities::MovementStrategies::Base()
   , entity(entity)
   , speed(speed)
{
}


MoveUpLeft::~MoveUpLeft()
{
}


void MoveUpLeft::update()
{
   if (entity)
   {
      entity->velocity.position.x = -speed;
      entity->velocity.position.y = -speed * 0.2;
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


