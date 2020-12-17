

#include <DragonWrath/Entities/MovementStrategies/MoveLeft.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategies
{


MoveLeft::MoveLeft(DragonWrath::Entities::Base *entity, float speed)
   : DragonWrath::Entities::MovementStrategies::Base()
   , entity(entity)
   , speed(speed)
{
}


MoveLeft::~MoveLeft()
{
}


void MoveLeft::update()
{
   if (entity) entity->velocity.position.x = -speed;
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


