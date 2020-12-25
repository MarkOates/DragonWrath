

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


bool Base::is_type(std::string type_to_check)
{
   return exists("type", type_to_check);
}


} // namespace PowerUps
} // namespace Entities
} // namespace DragonWrath



