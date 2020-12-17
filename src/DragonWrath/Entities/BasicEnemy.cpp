

#include <DragonWrath/Entities/BasicEnemy.hpp>

#include <sstream>
#include <math.h>


namespace DragonWrath
{
namespace Entities
{


BasicEnemy::BasicEnemy(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Base(parent, "basic_enemy", x, y)
   , movement_strategy("sin_wave_move_left")
{
}


BasicEnemy::~BasicEnemy()
{
}


void BasicEnemy::update()
{
   if (movement_strategy == "move_left")
   {
      velocity.position.y = 0;
      velocity.position.x = -8;
   }
   else if (movement_strategy == "move_right")
   {
      velocity.position.y = 0;
      velocity.position.x = 8;
   }
   else if (movement_strategy == "stay_still")
   {
      velocity.position.x = 0;
      velocity.position.y = 0;
   }
   else if (movement_strategy == "sin_wave_move_left")
   {
      velocity.position.x = -8;
      velocity.position.y = sin(al_get_time() * 4) * 10;
   }
   else
   {
      std::stringstream error_message;
      error_message << "BasicEnemy::update(): error: undefined movement_strategy \""
         << movement_strategy
         << "\""
         << std::endl;
      throw std::runtime_error(error_message.str());
   }
}


void BasicEnemy::set_movement_strategy(std::string movement_strategy)
{
   this->movement_strategy = movement_strategy;
}


} // namespace Entities
} // namespace DragonWrath


