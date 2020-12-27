

#include <DragonWrath/Entities/MovementStrategies/MoveDownLeft.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategies
{


MoveDownLeft::MoveDownLeft(DragonWrath::Entities::Base *entity, float speed)
   : DragonWrath::Entities::MovementStrategies::Base()
   , entity(entity)
   , speed(speed)
{
}


MoveDownLeft::~MoveDownLeft()
{
}


void MoveDownLeft::update()
{
   if (entity)
   {
      entity->velocity.position.x = -speed;
      entity->velocity.position.y = speed * 0.2;
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


