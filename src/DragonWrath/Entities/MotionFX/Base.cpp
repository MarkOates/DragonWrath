

#include <DragonWrath/Entities/MotionFX/Base.hpp>


namespace DragonWrath
{
namespace Entities
{
namespace MotionFX
{


Base::Base(ElementID *parent, std::string motion_fx_type, float x, float y, float duration)
   : Entities::Base(parent, "motion_fx", x, y)
   , duration(duration)
   , counter(duration)
{
   set("motion_fx_type", motion_fx_type);
}


Base::~Base() {}


void Base::update()
{
   counter -= 1.0 / 60.0;
   if (counter <= 0) flag_for_deletion();
}


} // namespace MotionFX
} // namespace Entities
} // namespace DragonWrath



