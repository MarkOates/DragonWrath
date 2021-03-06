

#include <DragonWrath/Entities/MovementStrategies/StayStill.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MovementStrategies
{


StayStill::StayStill(DragonWrath::Entities::Base *entity)
   : DragonWrath::Entities::MovementStrategies::Base()
   , entity(entity)
{
}


StayStill::~StayStill()
{
}


void StayStill::update()
{
   if (entity)
   {
      entity->velocity.position.y = 0;
      entity->velocity.position.x = 0;
   }
}


} // namespace MovementStrategies
} // namespace Entities
} // namespace DragonWrath


