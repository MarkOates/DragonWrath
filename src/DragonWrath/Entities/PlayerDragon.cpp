

#include <DragonWrath/Entities/PlayerDragon.hpp>

#include <DragonWrath/EntityTypeNames.hpp>
#include <sstream>


namespace DragonWrath
{
namespace Entities
{


PlayerDragon::PlayerDragon(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Base(parent, PLAYER_DRAGON, x, y)
   , state(ALIVE)
   , max_health(3)
   , health(3)
   , speed_level(1)
{
}


PlayerDragon::~PlayerDragon()
{
}


void PlayerDragon::take_damage(int amount)
{
   if (is_dead())
   {
      std::cout << "Dragon cannot take damage because he is dead." << std::endl;
      return;
   }

   health -= amount;
   if (health <= 0)
   {
      health = 0;
      state = DEAD;
      std::cout << "Dragon has died of death." << std::endl;
   }
   else
   {
      std::cout << "Dragon takes damage of " << amount << "!!" << std::endl;
      std::cout << "Dragon now has health " << health << " / " << max_health << std::endl;
   }
}


bool PlayerDragon::is_dead()
{
   return state == DEAD;
}


int PlayerDragon::get_health()
{
   return health;
}


int PlayerDragon::get_max_health()
{
   return max_health;
}


int PlayerDragon::get_speed_level()
{
   return speed_level;
}


void PlayerDragon::increment_speed_level()
{
   speed_level += 1;
   if (speed_level >= 3) speed_level = 3;
}


float PlayerDragon::calculate_max_velocity()
{
   switch(speed_level)
   {
   case 1:
      return 5.0f;
      break;
   case 2:
      return 8.0f;
      break;
   case 3:
      return 11.0f;
      break;
   default:
      {
         std::stringstream error_message;
         error_message << "PlayerDragon::calculate_max_velocity(): error, unrecognized speed_level of \""
            << speed_level
            << "\""
            << std::endl;
         throw std::runtime_error(error_message.str());
      }
      break;
   }
}


} // namespace Entities
} // namespace DragonWrath


