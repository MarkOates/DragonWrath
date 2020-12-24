

#include <DragonWrath/Entities/PowerUps/Base.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace PowerUps
{


Base::Base(ElementID *parent, std::string type, float x, float y)
   : DragonWrath::Entities::Base(parent, type, x, y)
{
   set("power_up");
}


Base::~Base()
{
}


} // namespace PowerUps
} // namespace Entities
} // namespace DragonWrath



