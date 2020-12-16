

#include <DragonWrath/Entities/PlayerDragon.hpp>
#include <DragonWrath/EntityTypeNames.hpp>


namespace DragonWrath
{
namespace Entities
{


PlayerDragon::PlayerDragon(ElementID *parent, float x, float y)
   : DragonWrath::Entities::Base(parent, PLAYER_DRAGON, x, y)
   , max_health(10)
   , health(max_health)
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


} // namespace Entities
} // namespace DragonWrath


