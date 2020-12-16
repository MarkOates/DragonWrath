

#include <DragonWrath/Entities/PlayerDragon.hpp>
#include <DragonWrath/EntityTypeNames.hpp>


namespace DragonWrath
{
namespace Entities
{


PlayerDragon::PlayerDragon(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Base(parent, PLAYER_DRAGON, x, y)
   , state(ALIVE)
   , max_health(2)
   , health(2)
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


} // namespace Entities
} // namespace DragonWrath


