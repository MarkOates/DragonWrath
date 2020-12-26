#pragma once


#include <DragonWrath/Weapons/Base.hpp>
#include <DragonWrath/UserEventEmitter.hpp>


namespace DragonWrath
{
   namespace Weapons
   {
      class BasicRefire : public DragonWrath::Weapons::Base
      {
      public:
         BasicRefire(DragonWrath::UserEventEmitter &user_event_emitter);
         ~BasicRefire();
      };
   }
}





