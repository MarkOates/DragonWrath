


#include <DragonWrath/Entities/Enemies/Base.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace Enemies
{


Base::Base(AllegroFlare::ElementID *parent, std::string type, float x, float y)
   : DragonWrath::Entities::Base(parent, type, x, y)
{
}


Base::~Base()
{
}



} // Enemies
} // Entities
} // DragonWrath
