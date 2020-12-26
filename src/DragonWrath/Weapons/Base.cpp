


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
   // to be implemented by derived class, if necessary
}



void Base::deactivate()
{
   // to be implemented by derived class, if necessary
}



void Base::update()
{
   // to be implemented by derived class, if necessary
}



} // namespace Weapons
} // namespace DragonWrath



