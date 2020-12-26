


#include <DragonWrath/Weapons/Base.hpp>



namespace DragonWrath
{
namespace Weapons
{


Base::Base(DragonWrath::UserEventEmitter &user_event_emitter)
   : user_event_emitter(user_event_emitter)
{
}



Base::~Base()
{
}


void Base::activate()
{
}


void Base::deactivate()
{
}


void Base::update()
{
}


} // namespace Weapons
} // namespace DragonWrath



