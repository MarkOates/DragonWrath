

#include <DragonWrath/Entities/Enemies/BlueDragon.hpp>

#include <DragonWrath/MovementStrategyNames.hpp>
#include <sstream>
#include <math.h>


namespace DragonWrath
{
namespace Entities
{
namespace Enemies
{


BlueDragon::BlueDragon(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Enemies::Base(parent, "BlueDragon", x, y, 2, 200)
   , movement_strategy(SIN_WAVE_MOVE_LEFT)
{
}


BlueDragon::~BlueDragon()
{
}


void BlueDragon::update()
{
   if (movement_strategy == MOVE_LEFT)
   {
      velocity.position.y = 0;
      velocity.position.x = -8;
   }
   else if (movement_strategy == MOVE_RIGHT)
   {
      velocity.position.y = 0;
      velocity.position.x = 8;
   }
   else if (movement_strategy == STAY_STILL)
   {
      velocity.position.x = 0;
      velocity.position.y = 0;
   }
   else if (movement_strategy == SIN_WAVE_MOVE_LEFT)
   {
      velocity.position.x = -8;
      velocity.position.y = sin((al_get_time() - get_created_at()) * 4) * 10;
   }
   else
   {
      std::stringstream error_message;
      error_message << "BlueDragon::update(): error: undefined movement_strategy \""
         << movement_strategy
         << "\""
         << std::endl;
      throw std::runtime_error(error_message.str());
   }
}


void BlueDragon::set_movement_strategy(std::string movement_strategy)
{
   this->movement_strategy = movement_strategy;
}


} // namespace Enemies
} // namespace Entities
} // namespace DragonWrath


