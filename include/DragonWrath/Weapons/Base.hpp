#pragma once


#include <DragonWrath/UserEventEmitter.hpp>


namespace DragonWrath
{
   namespace Weapons
   {
      class Base
      {
      protected:
         DragonWrath::UserEventEmitter &user_event_emitter;

      public:
         Base(DragonWrath::UserEventEmitter &user_event_emitter);
         virtual ~Base();

         virtual void activate();
         virtual void deactivate();
         virtual void update();
      };
   }
}




