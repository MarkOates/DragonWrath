

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


void Base::update()
{
   float baseline = 1.4f;
   float amplitude = 0.15f;
   float frequency_per_sec = 3.0f;
   float scale = sin((al_get_time() - this->get_created_at()) * frequency_per_sec)*amplitude + baseline;
   bitmap.scale(scale);
}


} // namespace PowerUps
} // namespace Entities
} // namespace DragonWrath



