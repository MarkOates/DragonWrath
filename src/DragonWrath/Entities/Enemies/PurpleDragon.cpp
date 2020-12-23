

#include <DragonWrath/Entities/Enemies/PurpleDragon.hpp>

#include <DragonWrath/MovementStrategyNames.hpp>
#include <sstream>
#include <math.h>


namespace DragonWrath
{
namespace Entities
{
namespace Enemies
{


PurpleDragon::PurpleDragon(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Base(parent, "basic_enemy", x, y)
   , movement_strategy(SIN_WAVE_MOVE_LEFT)
{
}


PurpleDragon::~PurpleDragon()
{
}


void PurpleDragon::update()
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
      velocity.position.y = sin(al_get_time() * 4) * 10;
   }
   else
   {
      std::stringstream error_message;
      error_message << "PurpleDragon::update(): error: undefined movement_strategy \""
         << movement_strategy
         << "\""
         << std::endl;
      throw std::runtime_error(error_message.str());
   }
}


void PurpleDragon::set_movement_strategy(std::string movement_strategy)
{
   this->movement_strategy = movement_strategy;
}


} // namespace Enemies
} // namespace Entities
} // namespace DragonWrath


