


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
{
}


Base::~Base()
{
}


float Base::get_health()
{
   return this->health;
}


} // Enemies
} // Entities
} // DragonWrath
