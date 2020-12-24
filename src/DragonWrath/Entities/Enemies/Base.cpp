


#include <DragonWrath/Entities/Enemies/Base.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace Enemies
{


Base::Base(AllegroFlare::ElementID *parent, std::string type, float x, float y, int initial_health)
   : DragonWrath::Entities::Base(parent, type, x, y)
   , health(initial_health)
   , dead(false)
{
}


Base::~Base()
{
}


int Base::get_health()
{
   return this->health;
}


void Base::take_damage(int damage)
{
   health -= damage;
   if (health <= 0)
   {
      health = 0;
      dead = true;
   }
}


bool Base::is_dead()
{
   return this->dead;
}


} // Enemies
} // Entities
} // DragonWrath
