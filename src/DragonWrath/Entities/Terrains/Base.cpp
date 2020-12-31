

#include <DragonWrath/Entities/Terrains/Base.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace Terrains
{


Base::Base(ElementID *parent)
   : DragonWrath::Entities::Base(parent, "terrain", 0, 0)
{
}


Base::~Base()
{
}


void Base::draw()
{
}


void Base::update()
{
}


} // namespace Terrains
} // namespace Entities
} // namespace DragonWrath



