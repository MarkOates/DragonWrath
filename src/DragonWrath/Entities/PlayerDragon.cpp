

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
   , shooting(false)
   , shield_level(0)
   , bullet_level(0)
   , speed_level(0)
   , option_level(0)
   , weapon(nullptr)
{
}


PlayerDragon::~PlayerDragon()
{
}


void PlayerDragon::equip_weapon(DragonWrath::Weapons::Base *weapon)
{
   this->weapon = weapon;
}


void PlayerDragon::dequip_weapon()
{
   this->weapon = nullptr;
}


void PlayerDragon::take_damage(int amount)
{
   if (is_dead())
   {
      return;
   }

   shield_level -= amount;
   if (shield_level < 0) kill();
}


void PlayerDragon::kill()
{
   shield_level = 0;
   state = DEAD;
}



bool PlayerDragon::is_dead()
{
   return state == DEAD;
}


void PlayerDragon::activate_shooting()
{
   std::cout << "activating shooting" << std::endl;
   this->shooting = true;
}


void PlayerDragon::deactivate_shooting()
{
   std::cout << "deactivating shooting" << std::endl;
   this->shooting = false;
}


bool PlayerDragon::is_shooting()
{
   return shooting;
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


int PlayerDragon::get_option_level()
{
   return option_level;
}


DragonWrath::Weapons::Base *PlayerDragon::get_weapon()
{
   return weapon;
}


bool PlayerDragon::has_weapon()
{
   return weapon != nullptr;
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


void PlayerDragon::increment_option_level()
{
   option_level += 1;
   if (option_level >= 3) option_level = 3;
}


bool PlayerDragon::is_shield_level_at_max()
{
   return shield_level == 3;
}


bool PlayerDragon::is_bullet_level_at_max()
{
   return bullet_level == 3;
}


bool PlayerDragon::is_speed_level_at_max()
{
   return speed_level == 3;
}


bool PlayerDragon::is_option_level_at_max()
{
   return option_level == 3;
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


