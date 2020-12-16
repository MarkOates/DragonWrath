

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
   health -= amount;
   if (health <= 0)
   {
      health = 0;
      // state = DEAD
   }
   else
   {
      std::cout << "Dragon takes damage of " << amount << "!!" << std::endl;
   }
}


bool PlayerDragon::is_dead()
{
   return state == DEAD;
}


} // namespace Entities
} // namespace DragonWrath


