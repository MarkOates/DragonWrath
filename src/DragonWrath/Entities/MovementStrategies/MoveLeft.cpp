

#include <DragonWrath/Entities/MovementStrategies/MoveLeft.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategy
{


MoveLeft::MoveLeft(DragonWrath::Entities::Base *entity, float speed)
   : DragonWrath::Entities::MovementStrategy::Base()
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


} // namespace MovementStrategy
} // namespace Entities
} // namespace DragonWrath


