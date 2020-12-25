

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
   , shield_level(0)
   , bullet_level(0)
   , speed_level(0)
   , options_level(0)
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

   shield_level -= amount;
   if (shield_level <= 0)
   {
      shield_level = 0;
      state = DEAD;
      std::cout << "Dragon has died of death." << std::endl;
   }
   else
   {
      std::cout << "Dragon takes damage of " << amount << "!!" << std::endl;
      std::cout << "Dragon now has shield_level " << shield_level << std::endl;
   }
}


bool PlayerDragon::is_dead()
{
   return state == DEAD;
}


int PlayerDragon::get_shield_level()
{
   return shield_level;
}


int PlayerDragon::get_bullet_level()
{
   return bullet_level;
}


int PlayerDragon::get_speed_level()
{
   return speed_level;
}


int PlayerDragon::get_options_level()
{
   return options_level;
}


void PlayerDragon::increment_shield_level()
{
   shield_level += 1;
   if (shield_level >= 3) shield_level = 3;
}


void PlayerDragon::increment_bullet_level()
{
   bullet_level += 1;
   if (bullet_level >= 3) bullet_level = 3;
}


void PlayerDragon::increment_speed_level()
{
   speed_level += 1;
   if (speed_level >= 3) speed_level = 3;
}


void PlayerDragon::increment_options_level()
{
   options_level += 1;
   if (options_level >= 3) options_level = 3;
}


float PlayerDragon::calculate_max_velocity()
{
   switch(speed_level)
   {
   case 0:
      return 5.0f;
      break;
   case 1:
      return 7.0f;
      break;
   case 2:
      return 9.0f;
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


